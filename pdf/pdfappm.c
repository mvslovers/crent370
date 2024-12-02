#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_ppm'");
int pdf_add_ppm(PDF *pdf, PDFO *page, int x, int y,
                int display_width, int display_height, const char *ppm_file)
{
    FILE *fp    = NULL;
    PDFO *obj;
    unsigned char *data;
    int i;
    char line[1024];
    unsigned width, height, size;

    /* Load the PPM file */
    fp = fopen(ppm_file, "rb");
    if (!fp)
        return pdf_set_err(pdf, -errno, "Unable to open '%s'", ppm_file);

    /* We only support binary ppms */
    if (fgetc(fp) != 0x50 || fgetc(fp) != 0x36 || fgetc(fp) != 0x0A) {   /* ASCII "P6" + ASCII newline */
        fclose(fp);
        return pdf_set_err(pdf, -EINVAL, "Only binary PPM files supported");
    }

    /* Skip the header comments until we get to the dimensions info */
    do {
        for(i=0; i < sizeof(line)-1; i++) {
            line[i] = fgetc(fp);
            if (line[i]==0x0A) break;
        }
        line[i] = 0;
        if (feof(fp)) {
            fclose(fp);
            return pdf_set_err(pdf, -EINVAL, "Unable to find PPM size");
        }
        if (line[0] != 0x23)    /* ASCII '#' */
            break;
    } while (1);

    pdfatoe(line, 0);   /* convert to EBCDIC */
    if (sscanf(line, "%u %u\n", &width, &height) != 2) {
        fclose(fp);
        return pdf_set_err(pdf, -EINVAL, "Unable to find PPM size");
    }

    /* Skip over the byte-size line */
    for(i=0; i < sizeof(line)-1; i++) {
        line[i] = fgetc(fp);
        if (line[i]==0x0A) break;
    }
    line[i] = 0;
    if (feof(fp)) {
        fclose(fp);
        return pdf_set_err(pdf, -EINVAL, "No byte-size line in PPM file");
    }

    /* Try and limit the memory usage to sane images */
    if (width > 2 << 14 || height > 2 << 14) {
        fclose(fp);
        return pdf_set_err(pdf, -EINVAL,
                           "Invalid width/height in PPM file: %ux%u", width,
                           height);
    }

    size = width * height * 3;
    data = malloc(size);
    if (!data) {
        fclose(fp);
        return pdf_set_err(pdf, -ENOMEM,
                           "Unable to allocate memory for RGB data");
    }
    if (fread(data, 1, size, fp) != size) {
        free(data);
        fclose(fp);
        return pdf_set_err(pdf, -EINVAL, "Insufficient RGB data available");
    }
    fclose(fp);
    obj = pdf_add_raw_rgb24(pdf, data, width, height);
    free(data);
    if (!obj)
        return pdf->errval;

    return pdf_add_image(pdf, page, obj, x, y, display_width, display_height);
}
