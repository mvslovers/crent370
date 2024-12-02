#define PDF_PRIVATE
#include "clibpdfi.h"

static PDFO *pdf_add_raw_jpeg(PDF *pdf, const char *jpeg_file);

__asm__("\n&FUNC    SETC 'pdf_add_jpeg'");
int pdf_add_jpeg(PDF *pdf, PDFO *page, int x, int y,
                 int display_width, int display_height, const char *jpeg_file)
{
    PDFO *obj;

    obj = pdf_add_raw_jpeg(pdf, jpeg_file);
    if (!obj)
        return pdf->errval;

    return pdf_add_image(pdf, page, obj, x, y, display_width, display_height);
}

__asm__("\n&FUNC    SETC 'jpeg_size'");
/* See http://www.64lines.com/jpeg-width-height for details */
static int jpeg_size(unsigned char *data, unsigned int data_size, int *width,
                     int *height)
{
    int i = 0;

    if (i + 3 < data_size && data[i] == 0xFF && data[i + 1] == 0xD8 &&
        data[i + 2] == 0xFF && data[i + 3] == 0xE0) {
        i += 4;
        if (i + 6 < data_size && data[i + 2] == 0x4A /*'J'*/ && data[i + 3] == 0x46 /*'F'*/ &&
            data[i + 4] == 0x49 /*'I'*/ && data[i + 5] == 0x46 /*'F'*/ && data[i + 6] == 0x00) {
            unsigned short block_length = data[i] * 256 + data[i + 1];
            while (i < data_size) {
                i += block_length;
                if ((i + 8) >= data_size) {
                    return -1;
                }
                if (data[i] != 0xFF) {
                    return -1;
                }
                if (data[i + 1] == 0xC0) {
                    *height = data[i + 5] * 256 + data[i + 6];
                    *width = data[i + 7] * 256 + data[i + 8];
                    return 0;
                }
                i += 2;
                block_length = data[i] * 256 + data[i + 1];
            }
        }
    }

    return -1;
}

__asm__("\n&FUNC    SETC 'pdf_add_raw_jpeg'");
static PDFO *pdf_add_raw_jpeg(PDF *pdf, const char *jpeg_file)
{
    PDFO    *obj    = NULL;
    size_t  len     = 0;
    size_t  avail   = 0;
    size_t  size    = 0;
    size_t  chunk;
    size_t  bytes;
    unsigned char *jpeg_data = NULL;
    FILE *fp;
    int width, height;

    /* we don't have unix like file system, so we have to read the jpeg file to determine the size */

    if ((fp = fopen(jpeg_file, "rb")) == NULL) {
        pdf_set_err(pdf, -errno, "Unable to open %s: %s", jpeg_file,
                    strerror(errno));
        goto quit;
    }

    /* set the chunk size for the jpeg_data buffer */
    if ((fp->recfm & _FILE_RECFM_TYPE) == _FILE_RECFM_U) {
        chunk = fp->blksize;    /* physical block size */
    }
    else {
        chunk = fp->lrecl;      /* logical record length */
    }
    if (chunk < 1024) chunk = 1024; /* set 1K minimum for chunk size */

    while(!feof(fp)) {
        if (avail < chunk) {
            size_t          new_len = size+(chunk*2);
            unsigned char * new_buf = realloc(jpeg_data, new_len);
            if (!new_buf) {
                pdf_set_err(pdf, -ENOMEM, "Unable to allocate: %zd", new_len);
                goto quit;
            }
            jpeg_data = new_buf;        /* update jpeg_data buffer */
            size    = new_len;          /* update jpeg_data buffer size */
            avail   = new_len - len;    /* recalculate available space in jpeg_data */
        }

        /* read jpeg data from file */
        bytes   = fread(&jpeg_data[len], 1, avail, fp);
        if (ferror(fp)) {
            pdf_set_err(pdf, -errno, "Unable to read full jpeg data");
            goto quit;
        }
        len     += bytes;
        avail   -= bytes;
        if (!bytes) break;  /* no more data??? */
    }
    fclose(fp);
    fp = NULL;

    if (jpeg_size(jpeg_data, len, &width, &height) < 0) {
        pdf_set_err(pdf, -EINVAL,
            "Unable to determine jpeg width/height from %s", jpeg_file);
        goto quit;
    }

    obj = pdf_add_object(pdf, OBJ_image);
    if (!obj) goto quit;

    dstr_printf(&obj->stream,
                "<<\r\n/Type /XObject\r\n/Name /Image%d\r\n"
                "/Subtype /Image\r\n/ColorSpace /DeviceRGB\r\n"
                "/Width %d\r\n/Height %d\r\n"
                "/BitsPerComponent 8\r\n/Filter /DCTDecode\r\n"
                "/Length %d\r\n>>stream\r\n",
                arraysize(&pdf->objects), width, height, (int)len);
    dstr_append_data(&obj->stream, jpeg_data, len);

    dstr_printf(&obj->stream, "\r\nendstream\r\n");

quit:
    if (jpeg_data) free(jpeg_data);
    if (fp) fclose(fp);

    return obj;
}
