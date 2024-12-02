#define PDF_PRIVATE
#include "clibpdfi.h"
#include "clibmz.h"

static int pdf_save_object(PDF *pdf, FILE *fp, int index);

__asm__("\n&FUNC    SETC 'pdf_save_file'");
int pdf_save_file(PDF *pdf, FILE *fp)
{
    PDFO *obj;
    int xref_offset;
    int xref_count = 0;
    int i;
    union {
        char        stck[8];
        unsigned    word[2];
    }u;

    pdf_fprintf(fp, "%%PDF-1.2\r\n%%");
    /* Hibit bytes */
    fprintf(fp, "%c%c%c%c", 0xDE, 0xAD, 0xBE, 0xEF);
    pdf_fprintf(fp, "\r\n");

    /* Dump all the objects & get their file offsets */
    for (i = 1; i <= arraycount(&pdf->objects); i++)
        if (pdf_save_object(pdf, fp, i) >= 0)
            xref_count++;

    /* xref */
    xref_offset = ftell(fp);
    pdf_fprintf(fp, "xref\r\n");
    pdf_fprintf(fp, "0 %d\r\n", xref_count + 1);
    pdf_fprintf(fp, "0000000000 65535 f\r\n");
    for (i = 0; i < arraycount(&pdf->objects); i++) {
        obj = pdf->objects[i];
        if (obj->type != OBJ_none) {
            if (!obj->offset) {
                wtodumpf(obj, sizeof(PDFO), "xref object has no offset");
                continue;
            }
            pdf_fprintf(fp, "%10.10d 00000 n\r\n", obj->offset);
        }
    }

    pdf_fprintf(fp,
            "trailer\r\n"
            "<<\r\n"
            "/Size %d\r\n",
            xref_count + 1);
    obj = pdf_find_first_object(pdf, OBJ_catalog);
    pdf_fprintf(fp, "/Root %d 0 R\r\n", obj->index);
    obj = pdf_find_first_object(pdf, OBJ_info);
    pdf_fprintf(fp, "/Info %d 0 R\r\n", obj->index);

    pdf_stck(u.stck);
    pdf_fprintf(fp, "/ID [<%08x%08x> <%08x%08x>]\r\n",
                u.word[0], u.word[1], u.word[0], u.word[1]);
    pdf_fprintf(fp, ">>\r\n"
                "startxref\r\n");
    pdf_fprintf(fp, "%d\r\n", xref_offset);
    pdf_fprintf(fp, "%%%%EOF\r\n");

    return 0;
}

__asm__("\n&FUNC    SETC 'pdf_save_object'");
static int pdf_save_object(PDF *pdf, FILE *fp, int index)
{
    PDFO *object = pdf_get_object(pdf, index);

    if (!object || object->type == OBJ_none)
        return -ENOENT;

    object->offset = ftell(fp);

    pdf_fprintf(fp, "%d 0 obj\r\n", index);

    switch (object->type) {
    case OBJ_stream:
    case OBJ_image: {
        fwrite(dstr_data(&object->stream), dstr_len(&object->stream), 1, fp);
        break;
    }
    case OBJ_info: {
        PDFI *info = object->info;

        pdf_fprintf(fp,
                "<<\r\n"
                "  /Creator (%s)\r\n"
                "  /Producer (%s)\r\n"
                "  /Title (%s)\r\n"
                "  /Author (%s)\r\n"
                "  /Subject (%s)\r\n"
                "  /CreationDate (D:%s)\r\n"
                ">>\r\n",
                info->creator, info->producer, info->title, info->author,
                info->subject, info->date);
        break;
    }

    case OBJ_page: {
        PDFO *pages = pdf_find_first_object(pdf, OBJ_pages);
        PDFO *image = pdf_find_first_object(pdf, OBJ_image);
        PDFO *font;
        int i;

        pdf_fprintf(fp,
                "<<\r\n"
                "/Type /Page\r\n"
                "/Parent %d 0 R\r\n",
                pages->index);
        pdf_fprintf(fp, "/MediaBox [0 0 %d %d]\r\n", object->page.width,
                object->page.height);
        pdf_fprintf(fp, "/Resources <<\r\n");
        pdf_fprintf(fp, "  /Font <<\r\n");
        for (font = pdf_find_first_object(pdf, OBJ_font);
             font; font = pdf_get_object(pdf, font->next))
            pdf_fprintf(fp, "    /F%d %d 0 R\r\n", font->font.index, font->index);
        pdf_fprintf(fp, "  >>\r\n");

        if (image) {
            pdf_fprintf(fp, "  /XObject <<");
            for (; image; image = pdf_get_object(pdf, image->next))
                pdf_fprintf(fp, "/Image%d %d 0 R ", image->index, image->index);
            pdf_fprintf(fp, ">>\r\n");
        }

        pdf_fprintf(fp, ">>\r\n");
        pdf_fprintf(fp, "/Contents [\r\n");
        for (i = 0; i < arraycount(&object->page.children); i++) {
            int child = (int) object->page.children[i];
            pdf_fprintf(fp, "%d 0 R\r\n", child);
        }
        pdf_fprintf(fp, "]\r\n");
        pdf_fprintf(fp, ">>\r\n");
        break;
    }

    case OBJ_bookmark: {
        PDFO *parent_obj;
        PDFO *other;
        int nchildren;

        parent_obj = pdf_get_object(pdf, object->bookmark.parent);
        if (!parent_obj)
            parent_obj = pdf_find_first_object(pdf, OBJ_outline);
        if (!object->bookmark.page)
            break;
        pdf_fprintf(fp,
                "<<\r\n"
                "/A << /Type /Action\r\n"
                "      /S /GoTo\r\n"
                "      /D [%d 0 R /XYZ 0 %d null]\r\n"
                "   >>\r\n"
                "/Parent %d 0 R\r\n"
                "/Title (%s)\r\n",
                object->bookmark.page, pdf->height, parent_obj->index,
                object->bookmark.name);
        nchildren = arraycount(&object->bookmark.children);
        if (nchildren > 0) {
            int f, l;
            f = object->bookmark.children[0];
            l = object->bookmark.children[nchildren - 1];
            pdf_fprintf(fp, "/First %d 0 R\r\n", f);
            pdf_fprintf(fp, "/Last %d 0 R\r\n", l);
        }
        /* Find the previous bookmark with the same parent */
        for (other = pdf_get_object(pdf, object->prev);
             other && other->bookmark.parent != object->bookmark.parent;
             other = pdf_get_object(pdf, other->prev))
            ;
        if (other)
            pdf_fprintf(fp, "/Prev %d 0 R\r\n", other->index);
        /* Find the next bookmark with the same parent */
        for (other = pdf_get_object(pdf, object->next);
             other && other->bookmark.parent != object->bookmark.parent;
             other = pdf_get_object(pdf, other->next))
            ;
        if (other)
            pdf_fprintf(fp, "/Next %d 0 R\r\n", other->index);
        pdf_fprintf(fp, ">>\r\n");
        break;
    }

    case OBJ_outline: {
        PDFO *first, *last, *cur;
        first = pdf_find_first_object(pdf, OBJ_bookmark);
        last = pdf_find_last_object(pdf, OBJ_bookmark);

        if (first && last) {
            int count = 0;
            cur = first;
            while (cur) {
                if (!cur->bookmark.parent)
                    count++;
                cur = pdf_get_object(pdf, cur->next);
            }

            /* Bookmark outline */
            pdf_fprintf(fp,
                    "<<\r\n"
                    "/Count %d\r\n"
                    "/Type /Outlines\r\n"
                    "/First %d 0 R\r\n"
                    "/Last %d 0 R\r\n"
                    ">>\r\n",
                    count, first->index, last->index);
        }
        break;
    }

    case OBJ_font:
        pdf_fprintf(fp,
                "<<\r\n"
                "  /Type /Font\r\n"
                "  /Subtype /Type1\r\n"
                "  /BaseFont /%s\r\n"
                "  /Encoding /WinAnsiEncoding\r\n"
                ">>\r\n",
                object->font.name);
        break;

    case OBJ_pages: {
        int npages = 0;
        PDFO *page;

        pdf_fprintf(fp, "<<\r\n"
                    "/Type /Pages\r\n"
                    "/Kids [ ");
        for (page = pdf_find_first_object(pdf, OBJ_page);
             page; page = pdf_get_object(pdf, page->next)) {
            npages++;
            pdf_fprintf(fp, "%d 0 R ", page->index);
        }
        pdf_fprintf(fp, "]\r\n");
        pdf_fprintf(fp, "/Count %d\r\n", npages);
        pdf_fprintf(fp, ">>\r\n");
        break;
    }

    case OBJ_catalog: {
        PDFO *outline = pdf_find_first_object(pdf, OBJ_outline);
        PDFO *pages = pdf_find_first_object(pdf, OBJ_pages);

        pdf_fprintf(fp, "<<\r\n"
                    "/Type /Catalog\r\n");
        if (outline)
            pdf_fprintf(fp,
                    "/Outlines %d 0 R\r\n"
                    "/PageMode /UseOutlines\r\n",
                    outline->index);
        pdf_fprintf(fp,
                "/Pages %d 0 R\r\n"
                ">>\r\n",
                pages->index);
        break;
    }

    case OBJ_text: {
        /* experimental text stream object */
        int len = dstr_len(&object->text->stream);
        unsigned char *data = dstr_data(&object->text->stream);

        if (pdf->flags & PDF_COMPRESS) {
            int cmp_status;
            mz_ulong cmp_len = compressBound(len);
            unsigned char *pCmp;

            pCmp = (unsigned char *)malloc((size_t)cmp_len);
            if (pCmp) {
                cmp_status = compress(pCmp, &cmp_len, data, len);
                if (cmp_status != Z_OK) {
                    if (pdf->flags & PDF_DEBUG) wtof("compress of text stream failed");
                }
                else {
                    if (pdf->flags & PDF_DEBUG) wtof("text stream compressed from %u to %u bytes", len, cmp_len);
                    if ((cmp_len + 50) < len) {
                        pdf_fprintf(fp, "<</Filter/FlateDecode /Length %d >>stream\r\n", cmp_len);

                        fwrite(pCmp, cmp_len, 1, fp);

                        pdf_fprintf(fp, "endstream\r\n");
                    }
                }
                free(pCmp);
                break;
            }
        }

        pdf_fprintf(fp, "<< /Length %d >>stream\r\n", len);

        fwrite(data, len, 1, fp);

        pdf_fprintf(fp, "endstream\r\n");
        break;
    }

    default:
        return pdf_set_err(pdf, -EINVAL, "Invalid PDF object type %d",
                           object->type);
    }

    pdf_fprintf(fp, "endobj\r\n");

    return 0;
}
