#ifndef CLIBPDFI_H
#define CLIBPDFI_H
/* Borrowed from the PDFGEN project (public domain license) */

/**
 * PDF HINTS & TIPS
 * The following sites have various bits & pieces about PDF document
 * generation
 * http://www.mactech.com/articles/mactech/Vol.15/15.09/PDFIntro/index.html
 * http://gnupdf.org/Introduction_to_PDF
 * http://www.planetpdf.com/mainpage.asp?WebPageID=63
 * http://archive.vector.org.uk/art10008970
 * http://www.adobe.com/devnet/acrobat/pdfs/pdf_reference_1-7.pdf
 * https://blog.idrsolutions.com/2013/01/understanding-the-pdf-file-format-overview/
 *
 * To validate the PDF output, there are several online validators:
 * http://www.validatepdfa.com/online.htm
 * http://www.datalogics.com/products/callas/callaspdfA-onlinedemo.asp
 * http://www.pdf-tools.com/pdf/validate-pdfa-online.aspx
 *
 * In addition the 'pdftk' server can be used to analyse the output:
 * https://www.pdflabs.com/docs/pdftk-cli-examples/
 *
 * PDF page markup operators:
 * b    closepath, fill,and stroke path.
 * B    fill and stroke path.
 * b*   closepath, eofill,and stroke path.
 * B*   eofill and stroke path.
 * BI   begin image.
 * BMC  begin marked content.
 * BT   begin text object.
 * BX   begin section allowing undefined operators.
 * c    curveto.
 * cm   concat. Concatenates the matrix to the current transform.
 * cs   setcolorspace for fill.
 * CS   setcolorspace for stroke.
 * d    setdash.
 * Do   execute the named XObject.
 * DP   mark a place in the content stream, with a dictionary.
 * EI   end image.
 * EMC  end marked content.
 * ET   end text object.
 * EX   end section that allows undefined operators.
 * f    fill path.
 * f*   eofill Even/odd fill path.
 * g    setgray (fill).
 * G    setgray (stroke).
 * gs   set parameters in the extended graphics state.
 * h    closepath.
 * i    setflat.
 * ID   begin image data.
 * j    setlinejoin.
 * J    setlinecap.
 * k    setcmykcolor (fill).
 * K    setcmykcolor (stroke).
 * l    lineto.
 * m    moveto.
 * M    setmiterlimit.
 * n    end path without fill or stroke.
 * q    save graphics state.
 * Q    restore graphics state.
 * re   rectangle.
 * rg   setrgbcolor (fill).
 * RG   setrgbcolor (stroke).
 * s    closepath and stroke path.
 * S    stroke path.
 * sc   setcolor (fill).
 * SC   setcolor (stroke).
 * sh   shfill (shaded fill).
 * Tc   set character spacing.
 * Td   move text current point.
 * TD   move text current point and set leading.
 * Tf   set font name and size.
 * Tj   show text.
 * TJ   show text, allowing individual character positioning.
 * TL   set leading.
 * Tm   set text matrix.
 * Tr   set text rendering mode.
 * Ts   set super/subscripting text rise.
 * Tw   set word spacing.
 * Tz   set horizontal scaling.
 * T*   move to start of next line.
 * v    curveto.
 * w    setlinewidth.
 * W    clip.
 * y    curveto.
 */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <clibpdf.h>    /* PDF public interfaces and prototypes */
#include <clibary.h>    /* dynamic array */
#include <socket.h>     /* has struct timeval, go figure! */

#define PDF_ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

#define PDF_RGB_R(c) ((((c) >> 16) & 0xff) / 255.0)
#define PDF_RGB_G(c) ((((c) >> 8) & 0xff) / 255.0)
#define PDF_RGB_B(c) ((((c) >> 0) & 0xff) / 255.0)
#define PDF_IS_TRANSPARENT(c) (((c) >> 24) == 0xff)

#ifndef M_SQRT2
#define M_SQRT2 1.41421356237309504880f
#endif

#define INIT_DSTR {0,0,0,{0}}

enum {
    OBJ_none,       /* 0 skipped */
    OBJ_info,       /* 1 */
    OBJ_stream,     /* 2 */
    OBJ_font,       /* 3 */
    OBJ_page,       /* 4 */
    OBJ_bookmark,   /* 5 */
    OBJ_outline,    /* 6 */
    OBJ_catalog,    /* 7 */
    OBJ_pages,      /* 8 */
    OBJ_image,      /* 9 */
    OBJ_text,       /* 10 experimental, text stream */

    OBJ_count,      /* 11 */
};

/**
 * Simple dynamic string object. Tries to store a reasonable amount on the
 * stack before falling back to malloc once things get large
 */
typedef struct dstr     DSTR;
struct dstr {
    int         alloc_len;      /* 00 data allocated bytes                      */
    int         used_len;       /* 04 used bytes (data or static_data)          */
    char        *data;          /* 08 allocated data buffer                     */
    char        static_data[64];/* 0C static data buffer                        */
};                              /* 4C (76 bytes)                                */

typedef struct bkmk     BKMK;
struct bkmk {
    char        name[64];       /* 00 bookmark name                             */
    int         page;           /* 40 page object index                         */
    int         parent;         /* 44 parent object index                       */
    int         *children;      /* 48 array of children object index's          */
};                              /* 4C (76 bytes)                                */

typedef struct page     PAGE;
struct page {
    int         width;          /* 00 page width                                */
    int         height;         /* 04 page height                               */
    int         *children;      /* 08 array of children object index's          */
    int         current_text;   /* 0C current text object                       */
};                              /* 10 (16 bytes)                                */

typedef struct font     FONT;
struct font {
    char        name[64];       /* 00 font name                                 */
    int         index;          /* 40 font index                                */
};                              /* 44 (68 bytes)                                */

typedef struct text     TEXT;
struct text {
    int         xoff;           /* 00 X offset                                  */
    int         yoff;           /* 04 Y offset                                  */
    int         font;           /* 08 font index (not font object index)        */
    int         fontsize;       /* 0C font size                                 */
    double      spacing;        /* 10 character spacing                         */
    unsigned    colour;         /* 18 text color (RBG value)                    */
    DSTR        stream;         /* 1C dynamic string                            */
};                              /* 68 (104 bytes)                               */

struct pdf_object {
    char        eye[4];         /* 00 eye catcher                               */
#define PDF_OBJECT_EYE  "PDFO"  /* ... eye catcher                              */
    int         type;           /* 04 See OBJ_xxxx                              */
    int         index;          /* 08 PDF output index (object number)          */
    int         offset;         /* 0C Byte position within the output file      */
    int         prev;           /* 10 Previous of this type index               */
    int         next;           /* 14 Next of this type index                   */
    union {                     /* 18 anonymous union                           */
        PDFI        *info;      /* 18 document info      (4 bytes)              */
        PAGE        page;       /* 18 page               (16 bytes)             */
        FONT        font;       /* 18 font               (68 bytes)             */
        BKMK        bookmark;   /* 18 bookmark           (76 bytes)             */
        DSTR        stream;     /* 18 stream             (76 bytes)             */
        TEXT        *text;      /* 18 text stream        (4 bytes)              */
    };                          /* 18 anonymous union                           */
};                              /* 64 (100 bytes)                               */

struct pdf_doc {
    char        errstr[128];    /* 00 error string                              */
    int         errval;         /* 80 error number                              */
    PDFO        **objects;      /* 84 array of PDF objects                      */

    int         width;          /* 88 this is the default page width in points  */
    int         height;         /* 8C this is the default page height in points */

    int         current_font;   /* 90 current font object index                 */
    int         current_index;  /* 94 next object index in pdf_append_object()  */
    char        flags;          /* 98 internal processing flags                 */
#define PDF_DEBUG       0x80    /* ... enable debug output (wto messages)       */
#define PDF_COMPRESS    0x40    /* ... enable stream compression                */
    char        unused1[3];     /* 99                                           */
    int         unused2;        /* 9C                                           */

    PDFO        *last_objects[OBJ_count];   /* A0 last object ptr by type code  */
    PDFO        *first_objects[OBJ_count];  /* CC first object ptr by type code */
};                              /* F8 (248 bytes)                               */

struct pdf_private {
    char *      (*dstr_data)(DSTR *str);
    int         (*dstr_len)(DSTR *str);
    int         (*dstr_ensure)(DSTR *str, int len);
    int         (*dstr_printf)(DSTR *str, const char *fmt, ...);
    int         (*dstr_append_data)(DSTR *str, const void *extend, int len);
    int         (*dstr_append)(DSTR *str, const char *extend, int len);
    void        (*dstr_free)(DSTR *str);
    char *      (*pdfetoa)(char *buf, int len);
    int         (*pdf_set_err)(PDF *doc, int errval, const char *fmt, ...);
    PDFO *      (*pdf_get_object)(PDF *pdf, int index);
    int         (*pdf_append_object)(PDF *pdf, PDFO *obj);
    PDFO *      (*pdf_add_object)(PDF *pdf, int type);
    void        (*pdf_object_destroy)(PDFO *object);
    PDFO *      (*pdf_find_first_object)(PDF *pdf, int type);
    PDFO *      (*pdf_find_last_object)(PDF *pdf, int type);
    int         (*pdf_fprintf)(FILE *stream, const char *format, ...);
    int         (*pdf_add_stream)(PDF *pdf, PDFO *page, const char *buffer);
    int         (*pdf_add_text_spacing)(PDF *pdf, PDFO *page,
                                const char *text, int size, int xoff,
                                int yoff, unsigned colour, double spacing);
    int         (*pdf_text_pixel_width)(const char *text, int text_len, int size,
                                const unsigned short *widths);
    const unsigned short * (*find_font_widths)(const char *font_name);
    PDFO *      (*pdf_add_raw_rgb24)(PDF *pdf, unsigned char *data, int width, int height);
    int         (*pdf_add_image)(PDF *pdf, PDFO *page, PDFO *image, int x, int y, int width, int height);
    char *      (*pdfatoe)(char *buf, int len);
    char *      (*pdf_stck)(char stck[8]);
    double *    (*pdf_secs)(double *secs);
    int         (*pdf_put_text_first)(PDF *pdf, PDFO *page, const char *text, int size,
                                      int xoff, int yoff, unsigned colour, double spacing);
    int         (*pdf_put_text_spacing)(PDF *pdf, PDFO *page, const char *text, int size,
                                        int xoff, int yoff, unsigned colour, double spacing);
};

#ifdef PDF_PRIVATE
extern struct pdf_private   *pdfx;
#define dstr_data(str)                  ((pdfx->dstr_data)((str)))
#define dstr_len(str)                   ((pdfx->dstr_len)((str)))
#define dstr_ensure(str,len)            ((pdfx->dstr_ensure)((str),(len)))
#define dstr_printf(str,fmt,...)        ((pdfx->dstr_printf)((str),(fmt),## __VA_ARGS__))
#define dstr_append_data(str,extend,len) \
                                        ((pdfx->dstr_append_data)((str),(extend),(len)))
#define dstr_append(str,extend,len)     ((pdfx->dstr_append)((str),(extend),(len)))
#define dstr_free(str)                  ((pdfx->dstr_free)((str)))
#define pdfetoa(buf,len)                ((pdfx->pdfetoa)((buf),(len)))
#define pdf_set_err(doc,errval,fmt,...) ((pdfx->pdf_set_err)((doc),(errval),(fmt),## __VA_ARGS__))
#define pdf_get_object(pdf,index)       ((pdfx->pdf_get_object)((pdf),(index)))
#define pdf_append_object(pdf,obj)      ((pdfx->pdf_append_object)((pdf),(obj)))
#define pdf_add_object(pdf,type)        ((pdfx->pdf_add_object)((pdf),(type)))
#define pdf_object_destroy(object)      ((pdfx->pdf_object_destroy)((object)))
#define pdf_find_first_object(pdf,type) ((pdfx->pdf_find_first_object)((pdf),(type)))
#define pdf_find_last_object(pdf,type)  ((pdfx->pdf_find_last_object)((pdf),(type)))
#define pdf_fprintf(fp,fmt, ...)        ((pdfx->pdf_fprintf)((fp),(fmt),## __VA_ARGS__))
#define pdf_add_stream(pdf,page,buffer) ((pdfx->pdf_add_stream)((pdf),(page),(buffer)))
#define pdf_add_text_spacing(pdf,page,text,size,xoff,yoff,colour,spacing) \
    ((pdfx->pdf_add_text_spacing)((pdf),(page),(text),(size),(xoff),(yoff),(colour),(spacing)))
#define pdf_text_pixel_width(text,text_len,size,widths) \
    ((pdfx->pdf_text_pixel_width)((text),(text_len),(size),(widths)))
#define find_font_widths(font)          ((pdfx->find_font_widths)((font)))
#define pdf_add_raw_rgb24(pdf,data,width,height) \
    ((pdfx->pdf_add_raw_rgb24)((pdf),(data),(width),(height)))
#define pdf_add_image(pdf,page,image,x,y,width,height) \
    ((pdfx->pdf_add_image)((pdf),(page),(image),(x),(y),(width),(height)))
#define pdfatoe(buf,len)                ((pdfx->pdfatoe)((buf),(len)))
#define pdf_stck(stck)                  ((pdfx->pdf_stck)((stck)))
#define pdf_secs(secs)                  ((pdfx->pdf_secs)((secs)))
#define pdf_put_text_first(pdf,page,text,size,xoff,yoff,colour,spacing) \
    ((pdfx->pdf_put_text_first)((pdf),(page),(text),(size),(xoff),(yoff),(colour),(spacing)))
#define pdf_put_text_spacing(pdf,page,text,size,xoff,yoff,colour,spacing) \
    ((pdfx->pdf_put_text_spacing)((pdf),(page),(text),(size),(xoff),(yoff),(colour),(spacing)))
#endif

#endif
