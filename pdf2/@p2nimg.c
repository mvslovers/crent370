#define PDF_PRIVATE
#include "../pdf2/pdfi.h"
#include <clibgrt.h>

__asm__("\n&FUNC    SETC 'pdf_new_image'");
PDFIMAGE *pdf_new_image(PDF *pdf, unsigned width, unsigned height, const char *colorspace, unsigned bitspercomponent)
{
    int     len         = (((width * bitspercomponent) + 7) / 8) * height;
    PDFIMAGE *pdfimage  = calloc(1, sizeof(PDFIMAGE));
    DSTR    *dstr;

    /* colorspace: DeviceGray, DeviceRGB, DeviceCMYK, CalGray, CalRGB, Lab, ICCBased, Indexed, Pattern, Seperation, DeviceN */
    if (*colorspace == '/') colorspace++;

    /* Adjust iLen to number of bytes for image data */
    if (pdf_case_cmp(colorspace, "DeviceGray")==0) {
        /* nothing to do */
    }
    else if (pdf_case_cmp(colorspace, "DeviceRGB")==0) {
        len *= 3;
    }
    else if (pdf_case_cmp(colorspace, "DeviceCMYK")==0) {
        len *= 4;
    }
    else if (pdf_case_cmp(colorspace, "CalGray")==0) {
        /* nothing to do */
    }
    else if (pdf_case_cmp(colorspace, "CalRGB")==0) {
        len *= 3;
    }
    else if (pdf_case_cmp(colorspace, "Lab")==0) {
        len *= 3;
    }

    if (pdfimage) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfimage;

        pdfobj->type = OBJIMAGE;
        pdfobj->index = ++pdf->current_index;

        pdfimage->width = width;
        pdfimage->height = height;
        pdfimage->bitspercomponent = bitspercomponent;

        pdfimage->colorspace = calloc(1, strlen(colorspace) + 2);
        sprintf(pdfimage->colorspace, "/%s", colorspace);

        arrayadd(pdf->objects, pdfimage);
        arrayadd(pdf->offsets, (void*)0);

        dstr = calloc(1, sizeof(DSTR) + len + 1);
        if (dstr) {
            dstr->size = len;
            dstr->stream = ((char *)dstr + sizeof(DSTR));

            pdfimage->dstr = dstr;
        }
    }

    return pdfimage;
}
