#ifndef CLIBPDF_H
#define CLIBPDF_H

typedef struct pdf_doc      PDF;
typedef struct pdf_object   PDFO;
typedef struct pdf_info     PDFI;

struct pdf_info {
    char creator[64];
    char producer[64];
    char title[64];
    char author[64];
    char subject[64];
    char date[64];
};

/**
 * Convert a value in inches into a number of points.
 * Always returns an integer value
 */
#define PDF_INCH_TO_POINT(inch) ((int)((inch)*72 + 0.5))

/**
 * Convert a value in milli-meters into a number of points.
 * Always returns an integer value
 */
#define PDF_MM_TO_POINT(mm) ((int)((mm)*72 / 25.4 + 0.5))

/**
 * Point width of a standard US-Letter page
 */
#define PDF_LETTER_WIDTH PDF_INCH_TO_POINT(8.5)

/**
 * Point height of a standard US-Letter page
 */
#define PDF_LETTER_HEIGHT PDF_INCH_TO_POINT(11)

/**
 * Point width of a standard A4 page
 */
#define PDF_A4_WIDTH PDF_MM_TO_POINT(210)

/**
 * Point height of a standard A4 page
 */
#define PDF_A4_HEIGHT PDF_MM_TO_POINT(297)

/**
 * Point width of a standard A3 page
 */
#define PDF_A3_WIDTH PDF_MM_TO_POINT(297)

/**
 * Point height of a standard A3 page
 */
#define PDF_A3_HEIGHT PDF_MM_TO_POINT(420)

/**
 * Convert three 8-bit RGB values into a single packed 32-bit
 * colour. These 32-bit colours are used by various functions
 * in PDFGen
 */
#define PDF_RGB(r, g, b)                                                     \
    ((((r)&0xff) << 16) | (((g)&0xff) << 8) | (((b)&0xff)))

/**
 * Utility macro to provide bright red
 */
#define PDF_RED PDF_RGB(0xff, 0, 0)

/**
 * Utility macro to provide bright green
 */
#define PDF_GREEN PDF_RGB(0, 0xff, 0)

/**
 * Utility macro to provide bright blue
 */
#define PDF_BLUE PDF_RGB(0, 0, 0xff)

/**
 * Utility macro to provide black
 */
#define PDF_BLACK PDF_RGB(0, 0, 0)

/**
 * Utility macro to provide white
 */
#define PDF_WHITE PDF_RGB(0xff, 0xff, 0xff)

/**
 * Utility macro to provide a transparent colour
 * This is used in some places for 'fill' colours, where no fill is required
 */
#define PDF_TRANSPARENT (0xff << 24)

enum {
    PDF_ALIGN_LEFT,
    PDF_ALIGN_RIGHT,
    PDF_ALIGN_CENTER,
    PDF_ALIGN_JUSTIFY,
};

/**
 * Create a new PDF object, with the given page
 * width/height
 * @param width Width of the page
 * @param height Height of the page
 * @param info Optional information to be put into the PDF header
 * @return PDF document object, or NULL on failure
 */
PDF *pdf_create(int width, int height, PDFI *info)                          asm("PDFCRTE");

/**
 * Destroy the pdf object, and all of its associated memory
 */
void pdf_destroy(PDF *pdf)                                                  asm("PDFDSTR");

/**
 * Retrieve the error message if any operation fails
 * @param pdf pdf document to retrieve error message from
 * @param errval optional pointer to an integer to be set to the error code
 * @return NULL if no error message, string description of error otherwise
 */
const char *pdf_get_err(PDF *pdf, int *errval)                              asm("PDFGERR");

/**
 * Acknowledge an outstanding pdf error
 * @param pdf pdf document to clear the error message from
 */
void pdf_clear_err(PDF *pdf)                                                asm("PDFCERR");

/**
 * Sets the font to use for text objects. Default value is Times-Roman if
 * this function is not called
 * Note: The font selection should be done before text is output,
 * and will remain until pdf_set_font is called again
 * @param pdf PDF document to update font on
 * @param font New font to use. This must be one of the standard PDF fonts:
 *  Courier, Courier-Bold, Courier-BoldOblique, Courier-Oblique,
 *  Helvetica, Helvetica-Bold, Helvetica-BoldOblique, Helvetica-Oblique,
 *  Times-Roman, Times-Bold, Times-Italic, Times-BoldItalic,
 *  Symbol or ZapfDingbats
 * @return < 0 on failure, 0 on success
 */
int pdf_set_font(PDF *pdf, const char *font)                                asm("PDFSFONT");

/**
 * Returns the width of a given string in the current font
 * @param pdf PDF document
 * @param font_name Name of the font to get the width of.
 *  This must be one of the standard PDF fonts:
 *  Courier, Courier-Bold, Courier-BoldOblique, Courier-Oblique,
 *  Helvetica, Helvetica-Bold, Helvetica-BoldOblique, Helvetica-Oblique,
 *  Times-Roman, Times-Bold, Times-Italic, Times-BoldItalic,
 *  Symbol or ZapfDingbats
 * @param text Text to determine width of
 * @param size Size of the text, in points
 * @return < 0 on failure, 0 on success
 */
int pdf_get_font_text_width(PDF *pdf, const char *font_name,
                            const char *text, int size)                     asm("PDFGFTW");

/**
 * Retrieves a PDF document height
 */
int pdf_height(PDF *pdf)                                                    asm("PDFHGHT");

/**
 * Retrieves a PDF document width
 */
int pdf_width(PDF *pdf)                                                     asm("PDFWIDTH");

/**
 * Add a new page to the given pdf
 * @return new page object
 */
PDFO *pdf_append_page(PDF *pdf)                                             asm("PDFAPAGE");

/**
 * Adjust the width/height of a specific page
 * @param pdf PDF document that the page belongs to
 * @param page object returned from @ref pdf_append_page
 * @param width Width of the page in points
 * @param height Height of the page in points
 * @return < 0 on failure, 0 on success
 */
int pdf_page_set_size(PDF *pdf, PDFO *page, int width, int height)          asm("PDFPGSS");

/**
 * Save the given pdf document to the supplied filename
 * If the filename is NULL, defaults to stdout
 */
int pdf_save(PDF *pdf, const char *filename)                                asm("PDFSAVE");

/**
 * Save the given pdf document to the given FILE output
 */
int pdf_save_file(PDF *pdf, FILE *fp)                                       asm("PDFSFILE");

/**
 * Add a text string to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param text String to display
 * @param size Point size of the font
 * @param xoff X location to put it in
 * @param yoff Y location to put it in
 * @param colour Colour to draw the text
 * @return 0 on success, < 0 on failure
 */
int pdf_add_text(PDF *pdf, PDFO *page,
                 const char *text, int size, int xoff, int yoff,
                 unsigned colour)                                           asm("PDFATEXT");

/**
 * Add a text string to the document, making it wrap if it is too
 * long
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param text String to display
 * @param size Point size of the font
 * @param xoff X location to put it in
 * @param yoff Y location to put it in
 * @param colour Colour to draw the text
 * @param wrap_width Width at which to wrap the text
 * @param align Text alignment (see PDF_ALIGN_xxx)
 * @return height of drawn text on success, < 0 on failure
 */
int pdf_add_text_wrap(PDF *pdf, PDFO *page,
                      const char *text, int size, int xoff, int yoff,
                      unsigned colour, int wrap_width, int align)           asm("PDFATXTW");

/**
 * Add a line to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param x1 X offset of start of line
 * @param y1 Y offset of start of line
 * @param x2 X offset of end of line
 * @param y2 Y offset of end of line
 * @param width Width of the line
 * @param colour Colour to draw the line
 * @return 0 on success, < 0 on failure
 */
int pdf_add_line(PDF *pdf, PDFO *page, int x1, int y1,
                 int x2, int y2, int width, unsigned colour)                asm("PDFALINE");

/**
 * Add an ellipse to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param x X offset of the center of the ellipse
 * @param y Y offset of the center of the ellipse
 * @param xradius Radius of the ellipse in the X axis
 * @param yradius Radius of the ellipse in the Y axis
 * @param colour Colour to draw the ellipse outline stroke
 * @param width Width of the ellipse outline stroke
 * @param fill_colour Colour to fill the ellipse
 * @return 0 on success, < 0 on failure
 */
int pdf_add_ellipse(PDF *pdf, PDFO *page, int x,
                    int y, int xradius, int yradius, int width,
                    unsigned colour, unsigned fill_colour)                  asm("PDFAELIP");

/**
 * Add a circle to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param x X offset of the center of the circle
 * @param y Y offset of the center of the circle
 * @param radius Radius of the circle
 * @param width Width of the circle outline stroke
 * @param colour Colour to draw the circle outline stroke
 * @param fill_colour Colour to fill the circle
 * @return 0 on success, < 0 on failure
 */
int pdf_add_circle(PDF *pdf, PDFO *page, int x, int y,
                   int radius, int width, unsigned colour,
                   unsigned fill_colour)                                    asm("PDFACRCL");

/**
 * Add an outline rectangle to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param x X offset to start rectangle at
 * @param y Y offset to start rectangle at
 * @param width Width of rectangle
 * @param height Height of rectangle
 * @param border_width Width of rectangle border
 * @param colour Colour to draw the rectangle
 * @return 0 on succss, < 0 on failure
 */
int pdf_add_rectangle(PDF *pdf, PDFO *page, int x,
                      int y, int width, int height, int border_width,
                      unsigned colour)                                      asm("PDFARECT");

/**
 * Add a filled rectangle to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param x X offset to start rectangle at
 * @param y Y offset to start rectangle at
 * @param width Width of rectangle
 * @param height Height of rectangle
 * @param border_width Width of rectangle border
 * @param colour Colour to draw the rectangle
 * @return 0 on succss, < 0 on failure
 */
int pdf_add_filled_rectangle(PDF *pdf, PDFO *page,
                             int x, int y, int width, int height,
                             int border_width, unsigned colour)             asm("PDFAFREC");

/**
 * Add an outline polygon to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param x array of X offsets for points comprising the polygon
 * @param y array of Y offsets for points comprising the polygon
 * @param count Number of points comprising the polygon
 * @param border_width Width of polygon border
 * @param colour Colour to draw the polygon
 * @return 0 on succss, < 0 on failure
 */
int pdf_add_polygon(PDF *pdf, PDFO *page, int x[],
                    int y[], int count, int border_width, unsigned colour)  asm("PDFAPOLY");

/**
 * Add a filled polygon to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param x array of X offsets of points comprising the polygon
 * @param y array of Y offsets of points comprising the polygon
 * @param count Number of points comprising the polygon
 * @param border_width Width of polygon border
 * @param colour Colour to draw the polygon
 * @return 0 on succss, < 0 on failure
 */
int pdf_add_filled_polygon(PDF *pdf, PDFO *page,
                           int x[], int y[], int count, int border_width,
                           unsigned colour)                                 asm("PDFAFPLY");

/**
 * Add a bookmark to the document
 *
 * @param pdf PDF document to add bookmark to
 * @param page Page to jump to for bookmark
               (or NULL for the most recently added page)
 * @param parent ID of a previosly created bookmark that is the parent
               of this one. -1 if this should be a top-level bookmark.
 * @param name String to associate with the bookmark
 * @return < 0 on failure, new bookmark id on success
 */
int pdf_add_bookmark(PDF *pdf, PDFO *page, int parent, const char *name)    asm("PDFABKMK");

/**
 * List of different barcode encodings that are supported
 */
enum {
    PDF_BARCODE_128A,
    PDF_BARCODE_39,
};

/**
 * Add a barcode to the document
 * @param pdf PDF document to add bookmark to
 * @param page Page to add barcode to (NULL => most recently added page)
 * @param code Type of barcode to add (PDF_BARCODE_xxx)
 * @param x X offset to put barcode at
 * @param y Y offset to put barcode at
 * @param width Width of barcode
 * @param height Height of barcode
 * @param string Barcode contents
 * @param colour Colour to draw barcode
 */
int pdf_add_barcode(PDF *pdf, PDFO *page, int code,
                    int x, int y, int width, int height, const char *string,
                    unsigned colour)                                        asm("PDFABARC");

/**
 * Add a PPM file as an image to the document
 * @param pdf PDF document to add bookmark to
 * @param page Page to add PPM to (NULL => most recently added page)
 * @param x X offset to put PPM at
 * @param y Y offset to put PPM at
 * @param display_width Displayed width of image
 * @param display_height Displayed height of image
 * @param ppm_file Filename of P6 (binary) ppm file to display
 */
int pdf_add_ppm(PDF *pdf, PDFO *page, int x, int y,
                int display_width, int display_height, const char *ppm_file) asm("PDFAPPM");

/**
 * Add a JPEG file as an image to the document
 * @param pdf PDF document to add bookmark to
 * @param page Page to add PPM to (NULL => most recently added page)
 * @param x X offset to put JPEG at
 * @param y Y offset to put JPEG at
 * @param display_width Displayed width of image
 * @param display_height Displayed height of image
 * @param jpeg_file Filename of JPEG file to display
 */
int pdf_add_jpeg(PDF *pdf, PDFO *page, int x, int y,
                 int display_width, int display_height,
                 const char *jpeg_file)                                     asm("PDFAJPEG");

/**
 * Add a text string to the document
 * @param pdf PDF document to add to
 * @param page Page to add object to (NULL => most recently added page)
 * @param text String to display
 * @param size Point size of the font
 * @param xoff X location to put it in
 * @param yoff Y location to put it in
 * @param colour Colour to draw the text
 * @return 0 on success, < 0 on failure
 */
int pdf_put_text(PDF *pdf, PDFO *page,
                 const char *text, int size, int xoff, int yoff,
                 unsigned colour)                                           asm("PDFPTEXT");

int pdf_set_compression(PDF *pdf, int on)                                   asm("PDFSCOMP");

int pdf_set_debug(PDF *pdf, int on)                                         asm("PDFSDBG");

#endif
