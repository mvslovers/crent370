#include <stdio.h>
#include <string.h>

#include "clibpdf.h"
#include "clibwto.h"

int main(int argc, char *argv[])
{
    struct pdf_info info = {.creator = "My software",
                            .producer = "My software",
                            .title = "My document",
                            .author = "My name",
                            .subject = "My subject"};
    struct pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, &info);
    int i;
    int height;
    int bm;
    int err;

    /* Unused */
    (void)argc;
    (void)argv;

    pdf_set_compression(pdf, 0);    /* disable compression of streams   */
    pdf_set_debug(pdf,1);           /* enable debug output (wto)        */

    if (pdf_width(pdf) != PDF_A4_WIDTH || pdf_height(pdf) != PDF_A4_HEIGHT) {
        fprintf(stderr, "PDF Size mismatch: %dx%d\n", pdf_width(pdf),
                pdf_height(pdf));
        return -1;
    }

    i = pdf_get_font_text_width(pdf, "Times-BoldItalic", "foo", 14);
    if (i < 18) {
        fprintf(stderr, "Font width invalid: %d\n", i);
        return -1;
    }

#if 0
    /* These calls should fail, since we haven't added a page yet */
    if (pdf_add_ppm(pdf, NULL, 10, 10, 20, 30, "data/teapot.ppm") >= 0)
        return -1;

    if (pdf_add_jpeg(pdf, NULL, 100, 500, 50, 150, "data/penguin.jpg") >= 0)
        return -1;

    if (pdf_add_text(pdf, NULL, "Page One", 10, 20, 30,
                     PDF_RGB(0xff, 0, 0)) >= 0)
        return -1;

    if (pdf_add_bookmark(pdf, NULL, -1, "Another Page") >= 0)
        return -1;

    if (!pdf_get_err(pdf, &err))
        return -1;
#endif

    pdf_clear_err(pdf);
    /* From now on, we shouldn't see any errors */

    pdf_set_font(pdf, "Times-BoldItalic");
    pdf_append_page(pdf);

    height = pdf_add_text_wrap(
        pdf, NULL,
        "This is a great big long string that I hope will wrap properly "
        "around several lines.\nThere are some odd length "
        "linesthatincludelongwords to check the justification. "
        "I've put some embedded line breaks in to "
        "see how it copes with them. Hopefully it all works properly.\n\n\n"
        "We even include multiple breaks\n"
        "thisisanenourmouswordthatwillneverfitandwillhavetobecut",
        16, 60, 800, PDF_RGB(0, 0, 0), 300, PDF_ALIGN_JUSTIFY);

    pdf_add_rectangle(pdf, NULL, 58, 800 + 16, 304, -height, 2,
                      PDF_RGB(0, 0, 0));
    pdf_add_ppm(pdf, NULL, 10, 10, 200, 200, "mdr.crent370.ppm(teapot)");

    pdf_add_jpeg(pdf, NULL, 100, 500, 50, 50, "mdr.crent370.jpeg(penguin)");

    pdf_add_barcode(pdf, NULL, PDF_BARCODE_128A, 50, 300, 200, 50, "Code128",
                    PDF_RGB(0, 0, 0));
    pdf_add_barcode(pdf, NULL, PDF_BARCODE_39, 50, 400, 400, 50, "CODE39",
                    PDF_RGB(0, 0, 0));

    pdf_add_text(pdf, NULL, "Page One", 10, 20, 30, PDF_RGB(0xff, 0, 0));
    pdf_add_text(pdf, NULL, "PjGQji", 18, 20, 130, PDF_RGB(0, 0xff, 0xff));
#if 0
    pdf_add_line(pdf, NULL, 10, 24, 100, 24, 4, PDF_RGB(0xff, 0, 0));
#endif
    pdf_add_circle(pdf, NULL, 100, 240, 50, 5, PDF_RGB(0xff, 0, 0),
                   PDF_TRANSPARENT);
    pdf_add_ellipse(pdf, NULL, 100, 240, 40, 30, 2, PDF_RGB(0xff, 0xff, 0),
                    PDF_RGB(0, 0, 0));
    pdf_add_rectangle(pdf, NULL, 150, 150, 100, 100, 4, PDF_RGB(0, 0, 0xff));
    pdf_add_filled_rectangle(pdf, NULL, 150, 450, 100, 100, 4,
                             PDF_RGB(0, 0xff, 0));
    int p1X[] = {200, 200, 300, 300};
    int p1Y[] = {200, 300, 200, 300};
    pdf_add_polygon(pdf, NULL, p1X, p1Y, 4, 4, PDF_RGB(0xaa, 0xff, 0xee));
    int p2X[] = {400, 400, 500, 500};
    int p2Y[] = {400, 500, 400, 500};
    pdf_add_filled_polygon(pdf, NULL, p2X, p2Y, 4, 4,
                           PDF_RGB(0xff, 0x77, 0x77));
    pdf_add_text(pdf, NULL, "", 20, 20, 30, PDF_RGB(0, 0, 0));
    pdf_add_text(pdf, NULL, "Date (YYYY-MM-DD):", 20, 220, 30,
                 PDF_RGB(0, 0, 0));

    pdf_add_bookmark(pdf, NULL, -1, "First page");

    /* testing pdf_put_text() */
    pdf_append_page(pdf);
    pdf_put_text(pdf, NULL, "Page Two", 10, 20, 30, PDF_RGB(0, 0, 0));
    pdf_put_text(pdf, NULL, "This is some weird text () \\ # : - Wi-Fi",
                 10, 20, 720, PDF_RGB(255, 0, 0));
    pdf_put_text(pdf, NULL, "Control characters ( ) < > [ ] { } / % \n \r \t \b \f ending",
                 10, 20, 700, PDF_RGB(255, 0, 0));
    pdf_put_text(pdf, NULL, "Special characters: �܎������������",
                 10, 20, 680, PDF_RGB(255, 0, 0));
    pdf_put_text(pdf, NULL, "This one has a new line in it\nThere it was",
                 10, 20, 660, PDF_RGB(255, 0, 0));
#if 0
    pdf_add_text(pdf, NULL, "Page Two", 10, 20, 30, PDF_RGB(0, 0, 0));
    pdf_add_text(pdf, NULL, "This is some weird text () \\ # : - Wi-Fi", 10,
                 50, 60, PDF_RGB(0, 0, 0));
    pdf_add_text(
        pdf, NULL,
        "Control characters ( ) < > [ ] { } / % \n \r \t \b \f ending", 10,
        50, 45, PDF_RGB(0, 0, 0));
    pdf_add_text(pdf, NULL, "Special characters: �܎������������", 10, 50, 15,
                 PDF_RGB(0, 0, 0));
    pdf_add_text(pdf, NULL, "This one has a new line in it\nThere it was", 10,
                 50, 80, PDF_RGB(0, 0, 0));
    pdf_add_text(
        pdf, NULL,
        "This is a really long line that will go off the edge of the screen, "
        "because it is so long. I like long text. The quick brown fox jumped "
        "over the lazy dog. The quick brown fox jumped over the lazy dog",
        10, 100, 100, PDF_RGB(0, 0, 0));
    pdf_set_font(pdf, "Helvetica-Bold");
    pdf_add_text(
        pdf, NULL,
        "This is a really long line that will go off the edge of the screen, "
        "because it is so long. I like long text. The quick brown fox jumped "
        "over the lazy dog. The quick brown fox jumped over the lazy dog",
        10, 100, 130, PDF_RGB(0, 0, 0));
    pdf_set_font(pdf, "ZapfDingbats");
    pdf_add_text(
        pdf, NULL,
        "This is a really long line that will go off the edge of the screen, "
        "because it is so long. I like long text. The quick brown fox jumped "
        "over the lazy dog. The quick brown fox jumped over the lazy dog",
        10, 100, 150, PDF_RGB(0, 0, 0));

    pdf_set_font(pdf, "Courier-Bold");
    pdf_add_text(pdf, NULL, "(5.6.5) RS232 shutdown", 8, 317, 546,
                 PDF_RGB(0, 0, 0));
    pdf_add_text(pdf, NULL, "", 8, 437, 546, PDF_RGB(0, 0, 0));
    pdf_add_text(pdf, NULL, "Pass", 8, 567, 556, PDF_RGB(0, 0, 0));
    pdf_add_text(pdf, NULL, "(5.6.3) RS485 pins", 8, 317, 556,
                 PDF_RGB(0, 0, 0));

    bm = pdf_add_bookmark(pdf, NULL, -1, "Another Page");
    bm = pdf_add_bookmark(pdf, NULL, bm, "Another Page again");
    pdf_add_bookmark(pdf, NULL, bm, "A child page");
    pdf_add_bookmark(pdf, NULL, -1, "Top level again");
#endif
#if 0
    pdf_append_page(pdf);

    pdf_set_font(pdf, "Times-Roman");
    for (i = 0; i < 3000; i++) {
        int xpos = (i / 100) * 40;
        int ypos = (i % 100) * 10;
        pdf_add_text(pdf, NULL, "Text blob", 8, xpos, ypos,
                     PDF_RGB(i, (i * 4) & 0xff, (i * 8) & 0xff));
    }
    pdf_add_text(pdf, NULL, "", 10, (i / 100) * 100, (i % 100) * 12,
                 PDF_RGB(0xff, 0, 0));

    pdf_append_page(pdf);
    pdf_page_set_size(pdf, NULL, PDF_A3_HEIGHT, PDF_A3_WIDTH);
    pdf_add_text(pdf, NULL, "This is an A3 landscape page", 10, 20, 30,
                 PDF_RGB(0xff, 0, 0));
#endif

#if 1
    pdf_save(pdf, "output.pdf");
#endif

#if 0
    const char *err_str = pdf_get_err(pdf, &err);
    if (err_str) {
        fprintf(stderr, "PDF Error: %d - %s\n", err, err_str);
        pdf_destroy(pdf);
        return -1;
    }
#endif
    pdf_destroy(pdf);

    return 0;
}

