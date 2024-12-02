#include "clibpdfi.h"   /* PDF Internal (private) prototypes */
#include "clibmz.h"

extern unsigned char *ebc2asc;
extern unsigned char *asc2ebc;

static char *pdfetoa(char *buf, int len);
static char *pdfatoe(char *buf, int len);

/* trying some new printf code */
#define vsnprintf   vsnprintf_
#define vsprint     vsprintf_

__asm__("\n&FUNC    SETC 'dstr_data'");
static char *dstr_data(DSTR *str)
{
    return str->data ? str->data : str->static_data;
}

__asm__("\n&FUNC    SETC 'dstr_len'");
static int dstr_len(DSTR *str)
{
    return str->used_len;
}

__asm__("\n&FUNC    SETC 'dstr_ensure'");
static int dstr_ensure(DSTR *str, int len)
{
    if (len <= str->alloc_len) return 0;

    if (!str->data && len <= sizeof(str->static_data)) {
        str->alloc_len = len;
    }
    else if (str->alloc_len < len) {
        int     new_len     = len + 64;     /* original bump was 4096 */
        char    *new_data   = realloc(str->data, new_len);

        if (!new_data) return -ENOMEM;

        /* If we move beyond the on-stack buffer, copy the old data out */
        if (!str->data && str->used_len > 0)
            memcpy(new_data, str->static_data, str->used_len + 1);

        str->data       = new_data;
        str->alloc_len  = new_len;
    }
    return 0;
}

__asm__("\n&FUNC    SETC 'dstr_printf'");
static int dstr_printf(DSTR *str, const char *fmt, ...)
{
    va_list ap;
    int len;

    va_start(ap, fmt);
    len = vsnprintf(NULL, 0, fmt, ap);
    if (dstr_ensure(str, str->used_len + len + 1) < 0) {
        va_end(ap);
        return -ENOMEM;
    }
    va_end(ap);

    va_start(ap, fmt);
    vsprintf(dstr_data(str) + str->used_len, fmt, ap);
    pdfetoa(dstr_data(str) + str->used_len, len);
    str->used_len += len;
    va_end(ap);

    return len;
}

__asm__("\n&FUNC    SETC 'dstr_append_data'");
static int dstr_append_data(DSTR *str, const void *extend, int len)
{
    if (dstr_ensure(str, str->used_len + len) < 0)
        return -ENOMEM;

    memcpy(dstr_data(str) + str->used_len, extend, len);
    str->used_len += len;
    return len;
}

__asm__("\n&FUNC    SETC 'dstr_append'");
static int dstr_append(DSTR *str, const char *extend, int len)
{
    if (len <= 0) len = strlen(extend);

    if (dstr_ensure(str, str->used_len + len + 1) < 0)
        return -ENOMEM;

    memcpy(dstr_data(str) + str->used_len, extend, len + 1);
    pdfetoa(dstr_data(str) + str->used_len, len);
    str->used_len += len;
    return len;
}

__asm__("\n&FUNC    SETC 'dstr_free'");
static void dstr_free(DSTR *str)
{
    if (str->data)
        free(str->data);

    str->alloc_len      = 0;
    str->used_len       = 0;
    str->data           = 0;
    str->static_data[0] = 0;
}

__asm__("\n&FUNC    SETC 'pdf_set_err'");
static int pdf_set_err(PDF *doc, int errval, const char *fmt, ...)
{
    va_list ap;
    int len;

    va_start(ap, fmt);
    len = vsnprintf(doc->errstr, sizeof(doc->errstr) - 1, fmt, ap);
    va_end(ap);

    /* Make sure we're properly terminated */
    doc->errstr[sizeof(doc->errstr)-1] = '\0';
    doc->errval      = errval;

    return errval;
}

__asm__("\n&FUNC    SETC 'pdf_get_object'");
static PDFO *pdf_get_object(PDF *pdf, int index)
{
    return (PDFO*) arrayget(&pdf->objects, index);
}

__asm__("\n&FUNC    SETC 'pdf_append_object'");
static int pdf_append_object(PDF *pdf, PDFO *obj)
{
    int index;

    if (arrayadd(&pdf->objects, obj))
        return -ENOMEM;

    index = ++pdf->current_index;   /* arraycount(&pdf->objects); */
    obj->index = index;

    if (pdf->last_objects[obj->type]) {
        obj->prev = pdf->last_objects[obj->type]->index;
        pdf->last_objects[obj->type]->next = obj->index;
    }

    pdf->last_objects[obj->type] = obj;

    if (!pdf->first_objects[obj->type])
        pdf->first_objects[obj->type] = obj;

    return 0;
}

__asm__("\n&FUNC    SETC 'pdf_add_object'");
static PDFO *pdf_add_object(PDF *pdf, int type)
{
    PDFO *obj;

    obj = calloc(1, sizeof(*obj));
    if (!obj) {
        pdf_set_err(pdf, -errno, "Unable to allocate object %d: %s",
                    pdf->current_index+1, strerror(errno));
        return NULL;
    }

    strcpy(obj->eye, PDF_OBJECT_EYE);
    obj->type = type;

    if (obj->type==OBJ_text) {
        obj->text = calloc(1, sizeof(TEXT));
        if (!obj->text) {
            pdf_set_err(pdf, -errno, "Unable to allocate object %d: %s",
                    pdf->current_index+1, strerror(errno));
            free(obj);
            return NULL;
        }
    }

    if (pdf_append_object(pdf, obj) < 0) {
        free(obj);
        return NULL;
    }

    return obj;
}

__asm__("\n&FUNC    SETC 'pdf_object_destroy'");
static void pdf_object_destroy(PDFO *object)
{
    switch (object->type) {
    case OBJ_stream:
    case OBJ_image:
        dstr_free(&object->stream);
        break;
    case OBJ_page:
        arrayfree(&object->page.children);
        break;
    case OBJ_info:
        free(object->info);
        break;
    case OBJ_bookmark:
        arrayfree(&object->bookmark.children);
        break;
    case OBJ_text:
        dstr_free(&object->text->stream);
        free(object->text);
    }
    free(object);
}

__asm__("\n&FUNC    SETC 'pdf_find_first_object'");
static PDFO *pdf_find_first_object(PDF *pdf, int type)
{
    return pdf->first_objects[type];
}

__asm__("\n&FUNC    SETC 'pdf_find_last_object'");
static PDFO *pdf_find_last_object(PDF *pdf, int type)
{
    return pdf->last_objects[type];
}


__asm__("\n&FUNC    SETC 'pdfetoa'");
static char *pdfetoa(char *buf, int len)
{
    int i;

    if (!len) len = strlen(buf);
    if (len<=0) goto quit;

    for(i=0; i < len; i++) {
        /* we translate special control characters ourselves */
        switch(buf[i]) {
        case '\r':          /* EBCDIC CR */
            buf[i]=0x0D;    /* ASCII CR */
            break;
        case '\n':          /* EBCDIC NL */
            buf[i]=0x0A;    /* ASCII LF */
            break;
        case 0xAD:          /* EBCDIC Left Square Bracket */
            buf[i]=0x5B;    /* ASCII Left Square Bracket */
            break;
        case 0xBD:          /* EBCDIC Right Square Bracket */
            buf[i]=0x5D;    /* ASCII Right Square Bracket */
            break;
        default:
            buf[i] = ebc2asc[buf[i]];
        }
    }

quit:
    return buf;
}

__asm__("\n&FUNC    SETC 'pdf_fprintf'");
static int pdf_fprintf(FILE *stream, const char *format, ...)
{
    va_list arg;
    int ret;
    char    buf[4096];

    va_start(arg, format);
    ret = vsprintf(buf, format, arg);
    va_end(arg);

    if (ret > 0) {
        pdfetoa(buf,ret);
        ret = fwrite(buf, 1, ret, stream);
    }

quit:
    return (ret);
}

__asm__("\n&FUNC    SETC 'pdf_add_stream'");
static int pdf_add_stream(PDF *pdf, PDFO *page, const char *buffer)
{
    PDFO *obj;
    int len;

    if (!page)
        page = pdf_find_last_object(pdf, OBJ_page);

    if (!page)
        return pdf_set_err(pdf, -EINVAL, "Invalid pdf page");

    len = strlen(buffer);
    /* We don't want any trailing whitespace in the stream */
    while (len >= 1 && (buffer[len - 1] == '\r' || buffer[len - 1] == '\n'))
        len--;

    obj = pdf_add_object(pdf, OBJ_stream);
    if (!obj)
        return pdf->errval;

    dstr_printf(&obj->stream, "<< /Length %d >>stream\r\n", len);
    dstr_append_data(&obj->stream, buffer, len);    /* buffer is already ASCII data */
    dstr_append(&obj->stream, "\r\nendstream\r\n", 0);

    len = arrayadd(&page->page.children, (void*)obj->index);

    return len;
}

#if 0
__asm__("\n&FUNC    SETC 'utf8_to_utf32'");
static int utf8_to_utf32(const char *utf8, int len, unsigned *utf32)
{
    unsigned ch = *utf8;
    uint8_t mask;

    if ((ch & 0x80) == 0) {
        len = 1;
        mask = 0x7f;
    } else if ((ch & 0xe0) == 0xc0 && len >= 2) {
        len = 2;
        mask = 0x1f;
    } else if ((ch & 0xf0) == 0xe0 && len >= 3) {
        len = 3;
        mask = 0xf;
    } else if ((ch & 0xf8) == 0xf0 && len >= 4) {
        len = 4;
        mask = 0x7;
    } else
        return -EINVAL;

    ch = 0;
    for (int i = 0; i < len; i++) {
        int shift = (len - i - 1) * 6;
        if (i == 0)
            ch |= ((unsigned)(*utf8++) & mask) << shift;
        else
            ch |= ((unsigned)(*utf8++) & 0x3f) << shift;
    }

    *utf32 = ch;

    return len;
}
#endif

__asm__("\n&FUNC    SETC 'pdf_add_text_spacing'");
static int pdf_add_text_spacing(PDF *pdf, PDFO *page,
                                const char *text, int size, int xoff,
                                int yoff, unsigned colour, double spacing)
{
    int ret;
    int len = text ? strlen(text) : 0;
    DSTR str = INIT_DSTR;
    int i;
    PDFO *font = pdf_get_object(pdf, pdf->current_font);

    /* Don't bother adding empty/null strings */
    if (!len)
        return 0;

    dstr_append(&str, "BT ", 3);
    dstr_printf(&str, "%d %d TD ", xoff, yoff);
    dstr_printf(&str, "/F%d %d Tf ", font->font.index, size);
    dstr_printf(&str, "%g %g %g rg ", PDF_RGB_R(colour), PDF_RGB_G(colour),
                PDF_RGB_B(colour));
    dstr_printf(&str, "%g Tc ", spacing);
    dstr_append(&str, "(", 1);

    /* Escape magic characters properly */
    for (i = 0; i < len;) {
#if 0
        unsigned code;
        int code_len;
        code_len = utf8_to_utf32(&text[i], len - i, &code);
        if (code_len < 0) {
            dstr_free(&str);
            return pdf_set_err(pdf, -EINVAL, "Invalid UTF-8 encoding");
        }
#else
        /* since we're running in an EBCDIC environment we know our
           characters are not UFT8 or any other ASCII subset/superset */
        unsigned code = text[i];
        int code_len  = 1;
        char buf[5]   = {0};
#endif
        if (code > 255) {
            /* We support *some* minimal UTF-8 characters */
            switch (code) {
            case 0x160:
                buf[0] = (char)0x8a;
                break;
            case 0x161:
                buf[0] = (char)0x9a;
                break;
            case 0x17d:
                buf[0] = (char)0x8e;
                break;
            case 0x17e:
                buf[0] = (char)0x9e;
                break;
            case 0x20ac:
                strcpy(buf, "\\200");
                break;
            default:
                dstr_free(&str);
                return pdf_set_err(pdf, -EINVAL,
                                   "Unsupported UTF-8 character: 0x%x 0o%o",
                                   code, code);
            }
            dstr_append(&str, buf, 0);
        }
        else if (strchr("()\\", code)) {
            /* Escape some characters */
            buf[0] = '\\';
            buf[1] = code;
            dstr_append(&str, buf, 2);
        }
        else if (strrchr("\n\r\t\b\f", code)) {
            /* Skip over these characters */
            ;
        }
#if 1
        else if (!isprint(code)) {
            buf[0] = '.';
            dstr_append(&str, buf, 1);
        }
#endif
        else {
            buf[0] = code;
            dstr_append(&str, buf, 1);
        }

        i += code_len;
    }
    dstr_append(&str, ") Tj ", 5);
    dstr_append(&str, "ET", 2);

    ret = pdf_add_stream(pdf, page, dstr_data(&str));
    dstr_free(&str);
    return ret;
}

/* How wide is each character, in points, at size 14 */
static const unsigned short helvetica_widths[256] = {
    280, 280, 280, 280,  280, 280, 280, 280,  280,  280, 280,  280, 280,
    280, 280, 280, 280,  280, 280, 280, 280,  280,  280, 280,  280, 280,
    280, 280, 280, 280,  280, 280, 280, 280,  357,  560, 560,  896, 672,
    192, 335, 335, 392,  588, 280, 335, 280,  280,  560, 560,  560, 560,
    560, 560, 560, 560,  560, 560, 280, 280,  588,  588, 588,  560, 1023,
    672, 672, 727, 727,  672, 615, 784, 727,  280,  504, 672,  560, 839,
    727, 784, 672, 784,  727, 672, 615, 727,  672,  951, 672,  672, 615,
    280, 280, 280, 472,  560, 335, 560, 560,  504,  560, 560,  280, 560,
    560, 223, 223, 504,  223, 839, 560, 560,  560,  560, 335,  504, 280,
    560, 504, 727, 504,  504, 504, 336, 262,  336,  588, 352,  560, 352,
    223, 560, 335, 1008, 560, 560, 335, 1008, 672,  335, 1008, 352, 615,
    352, 352, 223, 223,  335, 335, 352, 560,  1008, 335, 1008, 504, 335,
    951, 352, 504, 672,  280, 335, 560, 560,  560,  560, 262,  560, 335,
    742, 372, 560, 588,  335, 742, 335, 403,  588,  335, 335,  335, 560,
    541, 280, 335, 335,  367, 560, 840, 840,  840,  615, 672,  672, 672,
    672, 672, 672, 1008, 727, 672, 672, 672,  672,  280, 280,  280, 280,
    727, 727, 784, 784,  784, 784, 784, 588,  784,  727, 727,  727, 727,
    672, 672, 615, 560,  560, 560, 560, 560,  560,  896, 504,  560, 560,
    560, 560, 280, 280,  280, 280, 560, 560,  560,  560, 560,  560, 560,
    588, 615, 560, 560,  560, 560, 504, 560,  504,
};

static const unsigned short helvetica_bold_widths[256] = {
    280,  280, 280,  280, 280, 280, 280, 280,  280, 280, 280, 280,  280, 280,
    280,  280, 280,  280, 280, 280, 280, 280,  280, 280, 280, 280,  280, 280,
    280,  280, 280,  280, 280, 335, 477, 560,  560, 896, 727, 239,  335, 335,
    392,  588, 280,  335, 280, 280, 560, 560,  560, 560, 560, 560,  560, 560,
    560,  560, 335,  335, 588, 588, 588, 615,  982, 727, 727, 727,  727, 672,
    615,  784, 727,  280, 560, 727, 615, 839,  727, 784, 672, 784,  727, 672,
    615,  727, 672,  951, 672, 672, 615, 335,  280, 335, 588, 560,  335, 560,
    615,  560, 615,  560, 335, 615, 615, 280,  280, 560, 280, 896,  615, 615,
    615,  615, 392,  560, 335, 615, 560, 784,  560, 560, 504, 392,  282, 392,
    588,  352, 560,  352, 280, 560, 504, 1008, 560, 560, 335, 1008, 672, 335,
    1008, 352, 615,  352, 352, 280, 280, 504,  504, 352, 560, 1008, 335, 1008,
    560,  335, 951,  352, 504, 672, 280, 335,  560, 560, 560, 560,  282, 560,
    335,  742, 372,  560, 588, 335, 742, 335,  403, 588, 335, 335,  335, 615,
    560,  280, 335,  335, 367, 560, 840, 840,  840, 615, 727, 727,  727, 727,
    727,  727, 1008, 727, 672, 672, 672, 672,  280, 280, 280, 280,  727, 727,
    784,  784, 784,  784, 784, 588, 784, 727,  727, 727, 727, 672,  672, 615,
    560,  560, 560,  560, 560, 560, 896, 560,  560, 560, 560, 560,  280, 280,
    280,  280, 615,  615, 615, 615, 615, 615,  615, 588, 615, 615,  615, 615,
    615,  560, 615,  560,
};

static const unsigned short helvetica_bold_oblique_widths[256] = {
    280,  280, 280,  280, 280, 280, 280, 280,  280, 280, 280, 280,  280, 280,
    280,  280, 280,  280, 280, 280, 280, 280,  280, 280, 280, 280,  280, 280,
    280,  280, 280,  280, 280, 335, 477, 560,  560, 896, 727, 239,  335, 335,
    392,  588, 280,  335, 280, 280, 560, 560,  560, 560, 560, 560,  560, 560,
    560,  560, 335,  335, 588, 588, 588, 615,  982, 727, 727, 727,  727, 672,
    615,  784, 727,  280, 560, 727, 615, 839,  727, 784, 672, 784,  727, 672,
    615,  727, 672,  951, 672, 672, 615, 335,  280, 335, 588, 560,  335, 560,
    615,  560, 615,  560, 335, 615, 615, 280,  280, 560, 280, 896,  615, 615,
    615,  615, 392,  560, 335, 615, 560, 784,  560, 560, 504, 392,  282, 392,
    588,  352, 560,  352, 280, 560, 504, 1008, 560, 560, 335, 1008, 672, 335,
    1008, 352, 615,  352, 352, 280, 280, 504,  504, 352, 560, 1008, 335, 1008,
    560,  335, 951,  352, 504, 672, 280, 335,  560, 560, 560, 560,  282, 560,
    335,  742, 372,  560, 588, 335, 742, 335,  403, 588, 335, 335,  335, 615,
    560,  280, 335,  335, 367, 560, 840, 840,  840, 615, 727, 727,  727, 727,
    727,  727, 1008, 727, 672, 672, 672, 672,  280, 280, 280, 280,  727, 727,
    784,  784, 784,  784, 784, 588, 784, 727,  727, 727, 727, 672,  672, 615,
    560,  560, 560,  560, 560, 560, 896, 560,  560, 560, 560, 560,  280, 280,
    280,  280, 615,  615, 615, 615, 615, 615,  615, 588, 615, 615,  615, 615,
    615,  560, 615,  560,
};

static const unsigned short helvetica_oblique_widths[256] = {
    280, 280, 280, 280,  280, 280, 280, 280,  280,  280, 280,  280, 280,
    280, 280, 280, 280,  280, 280, 280, 280,  280,  280, 280,  280, 280,
    280, 280, 280, 280,  280, 280, 280, 280,  357,  560, 560,  896, 672,
    192, 335, 335, 392,  588, 280, 335, 280,  280,  560, 560,  560, 560,
    560, 560, 560, 560,  560, 560, 280, 280,  588,  588, 588,  560, 1023,
    672, 672, 727, 727,  672, 615, 784, 727,  280,  504, 672,  560, 839,
    727, 784, 672, 784,  727, 672, 615, 727,  672,  951, 672,  672, 615,
    280, 280, 280, 472,  560, 335, 560, 560,  504,  560, 560,  280, 560,
    560, 223, 223, 504,  223, 839, 560, 560,  560,  560, 335,  504, 280,
    560, 504, 727, 504,  504, 504, 336, 262,  336,  588, 352,  560, 352,
    223, 560, 335, 1008, 560, 560, 335, 1008, 672,  335, 1008, 352, 615,
    352, 352, 223, 223,  335, 335, 352, 560,  1008, 335, 1008, 504, 335,
    951, 352, 504, 672,  280, 335, 560, 560,  560,  560, 262,  560, 335,
    742, 372, 560, 588,  335, 742, 335, 403,  588,  335, 335,  335, 560,
    541, 280, 335, 335,  367, 560, 840, 840,  840,  615, 672,  672, 672,
    672, 672, 672, 1008, 727, 672, 672, 672,  672,  280, 280,  280, 280,
    727, 727, 784, 784,  784, 784, 784, 588,  784,  727, 727,  727, 727,
    672, 672, 615, 560,  560, 560, 560, 560,  560,  896, 504,  560, 560,
    560, 560, 280, 280,  280, 280, 560, 560,  560,  560, 560,  560, 560,
    588, 615, 560, 560,  560, 560, 504, 560,  504,
};

static const unsigned short symbol_widths[256] = {
    252, 252, 252, 252,  252, 252, 252,  252, 252,  252,  252, 252, 252, 252,
    252, 252, 252, 252,  252, 252, 252,  252, 252,  252,  252, 252, 252, 252,
    252, 252, 252, 252,  252, 335, 718,  504, 553,  839,  784, 442, 335, 335,
    504, 553, 252, 553,  252, 280, 504,  504, 504,  504,  504, 504, 504, 504,
    504, 504, 280, 280,  553, 553, 553,  447, 553,  727,  672, 727, 616, 615,
    769, 607, 727, 335,  636, 727, 691,  896, 727,  727,  774, 746, 560, 596,
    615, 695, 442, 774,  650, 801, 615,  335, 869,  335,  663, 504, 504, 636,
    553, 553, 497, 442,  525, 414, 607,  331, 607,  553,  553, 580, 525, 553,
    553, 525, 553, 607,  442, 580, 718,  691, 496,  691,  497, 483, 201, 483,
    553, 0,   0,   0,    0,   0,   0,    0,   0,    0,    0,   0,   0,   0,
    0,   0,   0,   0,    0,   0,   0,    0,   0,    0,    0,   0,   0,   0,
    0,   0,   0,   0,    0,   0,   756,  624, 248,  553,  168, 718, 504, 759,
    759, 759, 759, 1050, 994, 607, 994,  607, 403,  553,  414, 553, 553, 718,
    497, 463, 553, 553,  553, 553, 1008, 607, 1008, 663,  829, 691, 801, 994,
    774, 774, 829, 774,  774, 718, 718,  718, 718,  718,  718, 718, 774, 718,
    796, 796, 897, 829,  553, 252, 718,  607, 607,  1050, 994, 607, 994, 607,
    497, 331, 796, 796,  792, 718, 387,  387, 387,  387,  387, 387, 497, 497,
    497, 497, 0,   331,  276, 691, 691,  691, 387,  387,  387, 387, 387, 387,
    497, 497, 497, 0,
};

static const unsigned short times_widths[256] = {
    252, 252, 252, 252, 252, 252, 252, 252,  252, 252, 252, 252,  252, 252,
    252, 252, 252, 252, 252, 252, 252, 252,  252, 252, 252, 252,  252, 252,
    252, 252, 252, 252, 252, 335, 411, 504,  504, 839, 784, 181,  335, 335,
    504, 568, 252, 335, 252, 280, 504, 504,  504, 504, 504, 504,  504, 504,
    504, 504, 280, 280, 568, 568, 568, 447,  928, 727, 672, 672,  727, 615,
    560, 727, 727, 335, 392, 727, 615, 896,  727, 727, 560, 727,  672, 560,
    615, 727, 727, 951, 727, 727, 615, 335,  280, 335, 472, 504,  335, 447,
    504, 447, 504, 447, 335, 504, 504, 280,  280, 504, 280, 784,  504, 504,
    504, 504, 335, 392, 280, 504, 504, 727,  504, 504, 447, 483,  201, 483,
    545, 352, 504, 352, 335, 504, 447, 1008, 504, 504, 335, 1008, 560, 335,
    896, 352, 615, 352, 352, 335, 335, 447,  447, 352, 504, 1008, 335, 987,
    392, 335, 727, 352, 447, 727, 252, 335,  504, 504, 504, 504,  201, 504,
    335, 766, 278, 504, 568, 335, 766, 335,  403, 568, 302, 302,  335, 504,
    456, 252, 335, 302, 312, 504, 756, 756,  756, 447, 727, 727,  727, 727,
    727, 727, 896, 672, 615, 615, 615, 615,  335, 335, 335, 335,  727, 727,
    727, 727, 727, 727, 727, 568, 727, 727,  727, 727, 727, 727,  560, 504,
    447, 447, 447, 447, 447, 447, 672, 447,  447, 447, 447, 447,  280, 280,
    280, 280, 504, 504, 504, 504, 504, 504,  504, 568, 504, 504,  504, 504,
    504, 504, 504, 504,
};

static const unsigned short times_bold_widths[256] = {
    252, 252, 252, 252,  252, 252, 252, 252,  252,  252,  252,  252,  252,
    252, 252, 252, 252,  252, 252, 252, 252,  252,  252,  252,  252,  252,
    252, 252, 252, 252,  252, 252, 252, 335,  559,  504,  504,  1008, 839,
    280, 335, 335, 504,  574, 252, 335, 252,  280,  504,  504,  504,  504,
    504, 504, 504, 504,  504, 504, 335, 335,  574,  574,  574,  504,  937,
    727, 672, 727, 727,  672, 615, 784, 784,  392,  504,  784,  672,  951,
    727, 784, 615, 784,  727, 560, 672, 727,  727,  1008, 727,  727,  672,
    335, 280, 335, 585,  504, 335, 504, 560,  447,  560,  447,  335,  504,
    560, 280, 335, 560,  280, 839, 560, 504,  560,  560,  447,  392,  335,
    560, 504, 727, 504,  504, 447, 397, 221,  397,  524,  352,  504,  352,
    335, 504, 504, 1008, 504, 504, 335, 1008, 560,  335,  1008, 352,  672,
    352, 352, 335, 335,  504, 504, 352, 504,  1008, 335,  1008, 392,  335,
    727, 352, 447, 727,  252, 335, 504, 504,  504,  504,  221,  504,  335,
    752, 302, 504, 574,  335, 752, 335, 403,  574,  302,  302,  335,  560,
    544, 252, 335, 302,  332, 504, 756, 756,  756,  504,  727,  727,  727,
    727, 727, 727, 1008, 727, 672, 672, 672,  672,  392,  392,  392,  392,
    727, 727, 784, 784,  784, 784, 784, 574,  784,  727,  727,  727,  727,
    727, 615, 560, 504,  504, 504, 504, 504,  504,  727,  447,  447,  447,
    447, 447, 280, 280,  280, 280, 504, 560,  504,  504,  504,  504,  504,
    574, 504, 560, 560,  560, 560, 504, 560,  504,
};

static const unsigned short times_bold_italic_widths[256] = {
    252, 252, 252, 252, 252, 252, 252, 252,  252, 252, 252, 252,  252, 252,
    252, 252, 252, 252, 252, 252, 252, 252,  252, 252, 252, 252,  252, 252,
    252, 252, 252, 252, 252, 392, 559, 504,  504, 839, 784, 280,  335, 335,
    504, 574, 252, 335, 252, 280, 504, 504,  504, 504, 504, 504,  504, 504,
    504, 504, 335, 335, 574, 574, 574, 504,  838, 672, 672, 672,  727, 672,
    672, 727, 784, 392, 504, 672, 615, 896,  727, 727, 615, 727,  672, 560,
    615, 727, 672, 896, 672, 615, 615, 335,  280, 335, 574, 504,  335, 504,
    504, 447, 504, 447, 335, 504, 560, 280,  280, 504, 280, 784,  560, 504,
    504, 504, 392, 392, 280, 560, 447, 672,  504, 447, 392, 350,  221, 350,
    574, 352, 504, 352, 335, 504, 504, 1008, 504, 504, 335, 1008, 560, 335,
    951, 352, 615, 352, 352, 335, 335, 504,  504, 352, 504, 1008, 335, 1008,
    392, 335, 727, 352, 392, 615, 252, 392,  504, 504, 504, 504,  221, 504,
    335, 752, 268, 504, 610, 335, 752, 335,  403, 574, 302, 302,  335, 580,
    504, 252, 335, 302, 302, 504, 756, 756,  756, 504, 672, 672,  672, 672,
    672, 672, 951, 672, 672, 672, 672, 672,  392, 392, 392, 392,  727, 727,
    727, 727, 727, 727, 727, 574, 727, 727,  727, 727, 727, 615,  615, 504,
    504, 504, 504, 504, 504, 504, 727, 447,  447, 447, 447, 447,  280, 280,
    280, 280, 504, 560, 504, 504, 504, 504,  504, 574, 504, 560,  560, 560,
    560, 447, 504, 447,
};

static const unsigned short times_italic_widths[256] = {
    252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252,  252, 252,
    252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252,  252, 252,
    252, 252, 252, 252, 252, 335, 423, 504, 504, 839, 784, 215,  335, 335,
    504, 680, 252, 335, 252, 280, 504, 504, 504, 504, 504, 504,  504, 504,
    504, 504, 335, 335, 680, 680, 680, 504, 927, 615, 615, 672,  727, 615,
    615, 727, 727, 335, 447, 672, 560, 839, 672, 727, 615, 727,  615, 504,
    560, 727, 615, 839, 615, 560, 560, 392, 280, 392, 425, 504,  335, 504,
    504, 447, 504, 447, 280, 504, 504, 280, 280, 447, 280, 727,  504, 504,
    504, 504, 392, 392, 280, 504, 447, 672, 447, 447, 392, 403,  277, 403,
    545, 352, 504, 352, 335, 504, 560, 896, 504, 504, 335, 1008, 504, 335,
    951, 352, 560, 352, 352, 335, 335, 560, 560, 352, 504, 896,  335, 987,
    392, 335, 672, 352, 392, 560, 252, 392, 504, 504, 504, 504,  277, 504,
    335, 766, 278, 504, 680, 335, 766, 335, 403, 680, 302, 302,  335, 504,
    527, 252, 335, 302, 312, 504, 756, 756, 756, 504, 615, 615,  615, 615,
    615, 615, 896, 672, 615, 615, 615, 615, 335, 335, 335, 335,  727, 672,
    727, 727, 727, 727, 727, 680, 727, 727, 727, 727, 727, 560,  615, 504,
    504, 504, 504, 504, 504, 504, 672, 447, 447, 447, 447, 447,  280, 280,
    280, 280, 504, 504, 504, 504, 504, 504, 504, 680, 504, 504,  504, 504,
    504, 447, 504, 447,
};

static const unsigned short zapfdingbats_widths[256] = {
    0,   0,   0,   0,   0,    0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,    0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   280,  981, 968, 981, 987, 724, 795, 796, 797, 695,
    967, 946, 553, 861, 918,  940, 918, 952, 981, 761, 852, 768, 767, 575,
    682, 769, 766, 765, 760,  497, 556, 541, 581, 697, 792, 794, 794, 796,
    799, 800, 822, 829, 795,  847, 829, 839, 822, 837, 930, 749, 728, 754,
    796, 798, 700, 782, 774,  798, 765, 712, 713, 687, 706, 832, 821, 795,
    795, 712, 692, 701, 694,  792, 793, 718, 797, 791, 797, 879, 767, 768,
    768, 765, 765, 899, 899,  794, 790, 441, 139, 279, 418, 395, 395, 673,
    673, 0,   393, 393, 319,  319, 278, 278, 513, 513, 413, 413, 235, 235,
    336, 336, 0,   0,   0,    0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,    0,   0,   737, 548, 548, 917, 672, 766, 766,
    782, 599, 699, 631, 794,  794, 794, 794, 794, 794, 794, 794, 794, 794,
    794, 794, 794, 794, 794,  794, 794, 794, 794, 794, 794, 794, 794, 794,
    794, 794, 794, 794, 794,  794, 794, 794, 794, 794, 794, 794, 794, 794,
    794, 794, 901, 844, 1024, 461, 753, 931, 753, 925, 934, 935, 935, 840,
    879, 834, 931, 931, 924,  937, 938, 466, 890, 842, 842, 873, 873, 701,
    701, 880, 0,   880, 766,  953, 777, 871, 777, 895, 974, 895, 837, 879,
    934, 977, 925, 0,
};

static const unsigned short courier_widths[256] = {
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604, 604,
    604,
};

__asm__("\n&FUNC    SETC 'pdf_text_pixel_width'");
static int pdf_text_pixel_width(const char *text, int text_len, int size,
                                const unsigned short *widths)
{
    int len = 0;
    int i;

    if (text_len < 0)
        text_len = strlen(text);

    for (i = 0; i < text_len;) {
#if 0
        uint32_t code;
        int code_len;
        code_len = utf8_to_utf32(&text[i], text_len - i, &code);
        if (code_len < 0)
            return code_len;
        if (code >= 255)
            return -EINVAL;
#else
        unsigned code = text[i];
        int code_len  = 1;
#endif
        i += code_len;

        if (code != '\n' && code != '\r')
#if 1
            /* all the widths tables assume the characters are ASCII (or UTF8)
               so we need to use the ASCII equivalent for our EBCDIC code */
            code = ebc2asc[(unsigned char)code];
#endif
            len += widths[(unsigned char)code];
    }

    /* Our widths arrays are for 14pt fonts */
    return len * size / (14 * 72);
}

#ifndef strcasecmp
#define strcasecmp(s1,s2) stricmp((s1),(s2))
#endif
__asm__("\n&FUNC    SETC 'find_font_widths'");
static const unsigned short *find_font_widths(const char *font_name)
{
    if (strcasecmp(font_name, "Helvetica") == 0)
        return helvetica_widths;
    if (strcasecmp(font_name, "Helvetica-Bold") == 0)
        return helvetica_bold_widths;
    if (strcasecmp(font_name, "Helvetica-BoldOblique") == 0)
        return helvetica_bold_oblique_widths;
    if (strcasecmp(font_name, "Helvetica-Oblique") == 0)
        return helvetica_oblique_widths;
    if (strcasecmp(font_name, "Courier") == 0 ||
        strcasecmp(font_name, "Courier-Bold") == 0 ||
        strcasecmp(font_name, "Courier-BoldOblique") == 0 ||
        strcasecmp(font_name, "Courier-Oblique") == 0)
        return courier_widths;
    if (strcasecmp(font_name, "Times-Roman") == 0)
        return times_widths;
    if (strcasecmp(font_name, "Times-Bold") == 0)
        return times_bold_widths;
    if (strcasecmp(font_name, "Times-Italic") == 0)
        return times_italic_widths;
    if (strcasecmp(font_name, "Times-BoldItalic") == 0)
        return times_bold_italic_widths;
    if (strcasecmp(font_name, "Symbol") == 0)
        return symbol_widths;
    if (strcasecmp(font_name, "ZapfDingbats") == 0)
        return zapfdingbats_widths;

    return NULL;
}

__asm__("\n&FUNC    SETC 'pdf_add_raw_rgb24'");
static PDFO *pdf_add_raw_rgb24(PDF *pdf, unsigned char *data, int width, int height)
{
    PDFO *obj;
    int len;
    int i;
    const char *endstream = ">\r\nendstream\r\n";

    obj = pdf_add_object(pdf, OBJ_image);
    if (!obj)
        return NULL;

    if (pdf->flags & PDF_COMPRESS) {
        int data_len = width * height * 3;  /* length of data (RGB) */
        int cmp_status;
        mz_ulong cmp_len = compressBound(data_len);
        unsigned char *pCmp;

        /* try to compress data */
        pCmp = (unsigned char *)malloc((size_t)cmp_len);
        if (pCmp) {
            cmp_status = compress(pCmp, &cmp_len, data, data_len);
            if (cmp_status != Z_OK) {
                if (pdf->flags & PDF_DEBUG) wtof("compress of raw rgb24 stream failed");
                free(pCmp);
            }
            else {
                if (pdf->flags & PDF_DEBUG) wtof("raw rbg24 stream compressed from %u to %u bytes", data_len, cmp_len);
                dstr_printf(&obj->stream,
                    "<</Type /XObject /Name /Image%d /Subtype /Image /ColorSpace /DeviceRGB\r\n"
                    "  /Height %d /Width %d /BitsPerComponent 8 /Filter /FlateDecode\r\n"
                    "  /Length %d\r\n>>stream\r\n",
                    arraycount(&pdf->objects), height, width,
                    cmp_len);

                len = dstr_len(&obj->stream) + cmp_len + strlen(endstream) + 1;
                if (dstr_ensure(&obj->stream, len) < 0) {
                    pdf_set_err(pdf, -ENOMEM, "Unable to allocate %d bytes memory for image", len);
                    return NULL;
                }
                dstr_append_data(&obj->stream, pCmp, cmp_len);
                dstr_append(&obj->stream, endstream, 0);
                free(pCmp);
                return obj;
            }
        }
    }

    /* encode data as ASCII Hex (Yick!) */
    dstr_printf(
        &obj->stream,
        "<<\r\n/Type /XObject\r\n/Name /Image%d\r\n/Subtype /Image\r\n"
        "/ColorSpace /DeviceRGB\r\n/Height %d\r\n/Width %d\r\n"
        "/BitsPerComponent 8\r\n/Filter /ASCIIHexDecode\r\n"
        "/Length %d\r\n>>stream\r\n",
        arraycount(&pdf->objects), height, width,
        width * height * 3 * 2 + 1);

    len = dstr_len(&obj->stream) + width * height * 3 * 2 +
          strlen(endstream) + 1;
    if (dstr_ensure(&obj->stream, len) < 0) {
        pdf_set_err(pdf, -ENOMEM,
                    "Unable to allocate %d bytes memory for image", len);
        return NULL;
    }
    for (i = 0; i < width * height * 3; i++) {
        char buf[2] = {"0123456789ABCDEF"[(data[i] >> 4) & 0xf],
                       "0123456789ABCDEF"[data[i] & 0xf]};
        dstr_append(&obj->stream, buf, 2);
    }
    dstr_append(&obj->stream, endstream, 0);

    return obj;
}

static int pdf_add_image(PDF *pdf, PDFO *page, PDFO *image,
                         int x, int y, int width, int height)
{
    int ret;
    DSTR str = INIT_DSTR;

    dstr_append(&str, "q ", 2);
    dstr_printf(&str, "%d 0 0 %d %d %d cm ", width, height, x, y);
    dstr_printf(&str, "/Image%d Do ", image->index);
    dstr_append(&str, "Q", 1);

    ret = pdf_add_stream(pdf, page, dstr_data(&str));
    dstr_free(&str);
    return ret;
}

static char * pdfatoe(char *buf, int len)
{
    int i;

    if (!len) len = strlen(buf);
    if (len<=0) goto quit;

    for(i=0; i < len; i++) {
        buf[i] = asc2ebc[buf[i]];
    }

quit:
    return buf;
}

static char *pdf_stck(char stck[8])
{
    /* get STCK value */
    __asm__("STCK\t0(%0)" : : "r" (stck));

    return stck;
}

static double *pdf_secs(double *secs)
{
    unsigned long long  tod;
    struct timeval      tv;
    double              tmp;

    if (!secs) secs = &tmp;

    /* get STCK value */
    __asm__("STCK\t0(%0)" : : "r" (&tod));

    /* make Jan 1 1900 (STCK) relative to Jan 1 1970 (unix epoch) */
    tod -=  0x7D91048BCA000000ULL;  /* STCK value for Jan 1 1970 */

    /* convert to microseconds (bits 0-51==number of microseconds) */
    tod >>= 12; /* convert to microseconds (1 us = .000001 sec) */

    /* calc seconds and microseconds (divide by 1000000) */
    __asm__(
        "LM\t0,1,0(%0)       load TOD microseconds\n\t"
        "D\t0,=F'1000000'  divide by 1000000\n\t"
        "ST\t1,0(0,%1)       store seconds (quotient)\n\t"
        "ST\t0,4(0,%1)       store microseconds (remainder)"
        : : "r" (&tod), "r" (&tv));

    /* Scale the microseconds and add to our result (secs.usecs) */
    *secs = ((double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0));

quit:
    return secs;
}

/* forward reference */
static int pdf_put_text_spacing(PDF *pdf, PDFO *page, const char *text, int size,
                                int xoff, int yoff, unsigned colour, double spacing);
__asm__("\n&FUNC    SETC 'pdf_put_text_first'");
static int pdf_put_text_first(PDF *pdf, PDFO *page, const char *text, int size,
                              int xoff, int yoff, unsigned colour, double spacing)
{
    int ret;
    PDFO *obj;
    DSTR *str;

    /* if they didn't provide a page, use the last page created */
    if (!page)  page = pdf_find_last_object(pdf, OBJ_page);

    if (!page)  return pdf_set_err(pdf, -EINVAL, "Invalid pdf page");

    /* create a new text object */
    obj = pdf_add_object(pdf, OBJ_text);
    if (!obj)   return pdf->errval;

    obj->text->colour = 0xFFFFFFFF; /* force colour assignment on first text */

    /* add the next text object to this page */
    ret = arrayadd(&page->page.children, (void*)obj->index);
    if (ret)    return pdf_set_err(pdf, -errno, strerror(errno));

    /* make the text object the current page text object */
    page->page.current_text = obj->index;

    /* continue the actual text processing */
    ret = pdf_put_text_spacing(pdf, page, text, size, xoff, yoff, colour, spacing);
    return ret;
}

__asm__("\n&FUNC    SETC 'pdf_put_text_spacing'");
static int pdf_put_text_spacing(PDF *pdf, PDFO *page, const char *text, int size,
                                int xoff, int yoff, unsigned colour, double spacing)
{
    int     ret = 0;
    int     len = text ? strlen(text) : 0;
    DSTR    *str;
    PDFO    *obj;
    PDFO    *font = pdf_get_object(pdf, pdf->current_font);
    int     i;

    /* if they didn't provide a page, use the last page created */
    if (!page)  page = pdf_find_last_object(pdf, OBJ_page);

    if (!page)  return pdf_set_err(pdf, -EINVAL, "Invalid pdf page");

    obj = pdf_get_object(pdf, page->page.current_text);
    if (!obj || obj->type != OBJ_text) {
        return pdf_put_text_first(pdf, page, text, size, xoff, yoff, colour, spacing);
    }

    /* Don't bother adding empty/null strings */
    if (!len)
        return 0;

    str = &obj->text->stream;

    dstr_append(str, "BT ", 3);
    dstr_printf(str, "%d %d TD ", xoff, yoff);
    obj->text->xoff = xoff;
    obj->text->yoff = yoff;

    if (obj->text->font != font->font.index ||
        obj->text->fontsize != size) {
        dstr_printf(str, "/F%d %d Tf ", font->font.index, size);
        obj->text->font = font->font.index;
        obj->text->fontsize = size;
    }

    if (obj->text->colour != colour) {
        dstr_printf(str, "%g %g %g rg ", PDF_RGB_R(colour), PDF_RGB_G(colour),
                    PDF_RGB_B(colour));
        obj->text->colour = colour;
    }

    if (obj->text->spacing != spacing) {
        dstr_printf(str, "%g Tc ", spacing);
        obj->text->spacing = spacing;
    }

    dstr_append(str, "(", 1);

    /* Escape magic characters properly */
    for (i = 0; i < len; i++) {
        /* since we're running in an EBCDIC environment we know our
           characters are not UFT8 or any other ASCII subset/superset */
        if (strchr("()\\", text[i])) {
            /* Escape some characters */
            dstr_append(str, "\\", 1);
            dstr_append(str, &text[i], 1);
        }
        else if (strrchr("\n\r\t\b\f", text[i])) {
            /* Skip over these characters */
            ;
        }
        else if (!isprint(text[i])) {
            dstr_append(str, ".", 1);
        }
        else {
            dstr_append(str, &text[i], 1);
        }
    }

    dstr_append(str, ") Tj ET\r\n", 9);

    return ret;
}

static struct pdf_private _private = {
    dstr_data,                  /* 00 dstr_data()                   */
    dstr_len,                   /* 04 dstr_len()                    */
    dstr_ensure,                /* 08 dstr_ensure()                 */
    dstr_printf,                /* 0C dstr_printf()                 */
    dstr_append_data,           /* 10 dstr_append_data()            */
    dstr_append,                /* 14 dstr_append()                 */
    dstr_free,                  /* 18 dstr_free()                   */
    pdfetoa,                    /* 1C pdfetoa()                     */
    pdf_set_err,                /* 20 pdf_set_err()                 */
    pdf_get_object,             /* 24 pdf_get_object()              */
    pdf_append_object,          /* 28 pdf_append_object()           */
    pdf_add_object,             /* 2C pdf_add_object()              */
    pdf_object_destroy,         /* 30 pdf_object_destroy()          */
    pdf_find_first_object,      /* 34 pdf_find_first_object()       */
    pdf_find_last_object,       /* 38 pdf_find_last_object()        */
    pdf_fprintf,                /* 3C pdf_fprintf()                 */
    pdf_add_stream,             /* 40 pdf_add_stream()              */
    pdf_add_text_spacing,       /* 44 pdf_add_text_spacing()        */
    pdf_text_pixel_width,       /* 48 pdf_text_pixel_width()        */
    find_font_widths,           /* 4C find_font_widths()            */
    pdf_add_raw_rgb24,          /* 50 pdf_add_raw_rgb24()           */
    pdf_add_image,              /* 54 pdf_add_image()               */
    pdfatoe,                    /* 58 pdfatoe()                     */
    pdf_stck,                   /* 5C pdf_stck()                    */
    pdf_secs,                   /* 60 pdf_secs()                    */
    pdf_put_text_first,         /* 64 pdf_put_text_first()          */
    pdf_put_text_spacing,       /* 68 pdf_put_text_spacing()        */
};

struct pdf_private  *pdfx = &_private;

