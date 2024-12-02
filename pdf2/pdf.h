#ifndef PDF_H
#define PDF_H

/* typedefs for our PDF routines */
typedef struct pdf              PDF;
typedef struct pdfobj           PDFOBJ;
typedef struct pdfcat           PDFCAT;
typedef struct pdfpage          PDFPAGE;
typedef struct pdfpages         PDFPAGES;
typedef struct pdfnull          PDFNULL;
typedef struct pdfarray         PDFARRAY;
typedef struct pdfbool          PDFBOOL;
typedef struct pdfdate          PDFDATE;
typedef struct pdffile          PDFFILE;
typedef struct pdfint           PDFINT;
typedef struct pdfname          PDFNAME;
typedef struct pdfstrobjpair    PDFSTROBJPAIR;
typedef struct pdfnameobjpair   PDFNAMEOBJPAIR;
typedef struct pdfnametree      PDFNAMETREE;
typedef struct pdfnum           PDFNUM;
typedef struct pdfnumpair       PDFNUMPAIR;
typedef struct pdfnumtree       PDFNUMTREE;
typedef struct pdfrect          PDFRECT;
typedef struct pdfstream        PDFSTREAM;
typedef struct pdfstream        PDFXOBJ;
typedef struct pdfstr           PDFSTR;
typedef struct pdfviewpref      PDFVIEWPREF;
typedef struct pdfoutlines      PDFOUTLINES;
typedef struct pdfoutline       PDFOUTLINE;
typedef struct pdfdest          PDFDEST;
typedef struct pdffont          PDFFONT;
typedef struct pdfresource      PDFRESOURCE;
typedef struct pdfcolor         PDFCOLOR;
typedef struct pdfinfo          PDFINFO;
typedef struct pdfimage         PDFIMAGE;

/**
 * Convert a value in inches into a number of points.
 * Always returns an integer value
 */
#define PDF_INCH_TO_POINT(inch) ((int)((inch)*72 + 0.5))

#define PDF_POINT_TO_INCH(point) ((double)((point)/72.0))

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


#ifndef __MVS__
#define __MVS__
#endif

#ifdef __MVS__
#define SECT(name)      asm(name)
#else
#define SECT(name)
#endif

PDF *pdf_new(int(*out)(void *udata, int len, const char *data), int (*tell)(void *udata), void *udata)    SECT("@P2NPDF");
void pdf_free(PDF **pp)                                                         SECT("@P2FPDF");

/* output functions */
int pdf_out_default(void *udata, int len, const char *data)                     SECT("@P2ODEF");
int pdf_out_null(void *udata, int len, const char *data)                        SECT("@P2ONUL");
int pdf_tell_default(void *udata)                                               SECT("@P2TDEF");

/* set functions */
int pdf_set_out(PDF *pdf, int (*out)(void *udata, int len, const char *data))   SECT("@P2SOUT");
int pdf_set_user_data(PDF *pdf, void *udata)                                    SECT("@P2SUDAT");
int pdf_set_tell(PDF *pdf, int (*tell)(void *udata))                            SECT("@P2STELL");
int pdf_set_default_page(PDF *pdf, int width, int height)                       SECT("@P2SDPAG");

/* object creation */
PDFNULL *pdf_new_null(PDF *pdf)                                                 SECT("@P2NNULL");
PDFARRAY *pdf_new_array(PDF *pdf)                                               SECT("@P2NARRA");
PDFARRAY *pdf_add_array(PDF *pdf, PDFARRAY *pdfarray, void *pdfobj)             SECT("@P2AARRA");
PDFBOOL *pdf_new_bool(PDF *pdf, int value)                                      SECT("@P2NBOOL");
PDFDATE *pdf_new_date(PDF *pdf, const struct tm *time)                          SECT("@P2NDATE");
PDFFILE *pdf_new_file(PDF *pdf, const char *file)                               SECT("@P2NFILE");
PDFINT  *pdf_new_int(PDF *pdf, int value)                                       SECT("@P2NINT");
PDFNAME *pdf_new_name(PDF *pdf, const char *name)                               SECT("@P2NNAME");
PDFSTROBJPAIR *pdf_new_str_obj_pair(PDF *pdf, const char *str, void *obj)       SECT("@P2NSOP");
PDFNAMEOBJPAIR *pdf_new_name_obj_pair(PDF *pdf, const char *name, void *obj)    SECT("@P2NNOP");
PDFNAMETREE *pdf_new_name_tree(PDF *pdf)                                        SECT("@P2NNAT");
PDFNAMETREE *pdf_add_name_tree_limits(PDF *pdf, PDFNAMETREE *pdfnametree, const char *namelow, const char *namehigh) SECT("@P2ANTL");
PDFNAMETREE *pdf_add_name_tree_kids(PDF *pdf, PDFNAMETREE *pdfnametree, void *obj) SECT("@P2ANTK");
PDFNAMETREE *pdf_add_name_tree_pair(PDF *pdf, PDFNAMETREE *pdfnametree, PDFSTROBJPAIR *strobjpair) SECT("@P2ANTP");
PDFNAMETREE *pdf_add_name_tree_names(PDF *pdf, PDFNAMETREE *pdfnametree, const char *name, void *obj) SECT("@P2ANTN");
PDFNUM *pdf_new_num(PDF *pdf, double value)                                     SECT("@P2NNUM");
PDFNUMPAIR *pdf_new_num_pair(PDF *pdf, int value, void *pdfobj)                 SECT("@P2NNUMP");
PDFNUMTREE *pdf_new_num_tree(PDF *pdf)                                          SECT("@P2NNUMT");
PDFNUMTREE *pdf_add_num_tree_limits(PDF *pdf, PDFNUMTREE *pdfnumtree, int low, int high) SECT("@P2ANUTL");
PDFNUMTREE *pdf_add_num_tree_kids(PDF *pdf, PDFNUMTREE *pdfnumtree, void *obj)  SECT("@P2ANUTK");
PDFNUMTREE *pdf_add_num_tree_pair(PDF *pdf, PDFNUMTREE *pdfnumtree, PDFNUMPAIR *pdfnumpair) SECT("@P2ANUTP");
PDFNUMTREE *pdf_add_num_tree_nums(PDF *pdf, PDFNUMTREE *pdfnumtree, int value, void *obj) SECT("@P2ANUTN");
PDFRECT *pdf_new_rect(PDF *pdf, int bx, int by, int tx, int ty)                 SECT("@P2NRECT");

/* stream */
PDFSTREAM *pdf_new_stream(PDF *pdf)                                             SECT("@P2NSTRM");
PDFSTREAM *pdf_add_stream(PDF *pdf, PDFSTREAM *pdfstream, int len, const char *stream) SECT("@P2AS");
PDFSTREAM *pdf_add_streamf(PDF *pdf, PDFSTREAM *pdfstream, const char *fmt, ...) SECT("@P2ASF");
PDFSTREAM *pdf_add_stream_text_stroke(PDF *pdf, PDFSTREAM *pdfstream, const char *text, const char *stroke) SECT("@P2ASTS");
PDFSTREAM *pdf_add_stream_stroke_textf(PDF *pdf, PDFSTREAM *pdfstream, const char *stroke, const char *fmt, ... ) SECT("@P2ASSTF");
PDFSTREAM *pdf_add_stream_text(PDF *pdf, PDFSTREAM *pdfstream, const char *text) SECT("@P2AST");
PDFSTREAM *pdf_add_stream_textf(PDF *pdf, PDFSTREAM *pdfstream, const char *fmt, ... ) SECT("@P2ASTF");
PDFSTREAM *pdf_add_stream_key_val(PDF *pdf, PDFSTREAM *pdfstream, const char *key_val) SECT("@P2ASKV");
PDFSTREAM *pdf_add_stream_key_valf(PDF *pdf, PDFSTREAM *pdfstream, const char *fmt, ...) SECT("@P2ASKVF");
PDFSTREAM *pdf_add_stream_filter(PDF *pdf, PDFSTREAM *pdfstream, void *obj)     SECT("@P2ASFLT");
PDFSTREAM *pdf_add_stream_decode(PDF *pdf, PDFSTREAM *pdfstream, void *obj)     SECT("@P2ASDEC");
PDFSTREAM *pdf_add_stream_file(PDF *pdf, PDFSTREAM *pdfstream, void *obj)       SECT("@P2ASFIL");
PDFSTREAM *pdf_add_stream_ffilter(PDF *pdf, PDFSTREAM *pdfstream, void *obj)    SECT("@P2ASFFI");
PDFSTREAM *pdf_add_stream_fdecode(PDF *pdf, PDFSTREAM *pdfstream, void *obj)    SECT("@P2ASFDE");
PDFSTREAM *pdf_add_stream_begin_text(PDF *pdf, PDFSTREAM *pdfstream)            SECT("@P2ASBT");
PDFSTREAM *pdf_add_stream_end_text(PDF *pdf, PDFSTREAM *pdfstream)              SECT("@P2ASET");
PDFSTREAM *pdf_add_stream_stroking_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color) SECT("@P2ASSC");
PDFSTREAM *pdf_add_stream_non_stroking_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color) SECT("@P2ASNSC");
PDFSTREAM *pdf_add_stream_text_matrix(PDF *pdf, PDFSTREAM *pdfstream, unsigned leftmargin, unsigned topmargin) SECT("@P2ASTMX");
PDFSTREAM *pdf_add_stream_text_leading(PDF *pdf, PDFSTREAM *pdfstream, unsigned leading) SECT("@P2ASTLE");
PDFSTREAM *pdf_add_stream_select_font(PDF *pdf, PDFSTREAM *pdfstream, const char *name, unsigned points) SECT("@P2ASSFO");
PDFSTREAM *pdf_add_stream_render_mode(PDF *pdf, PDFSTREAM *pdfstream, unsigned mode)    SECT("@P2ASRM");
PDFSTREAM *pdf_add_stream_move_to(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y)   SECT("@P2ASMT");
PDFSTREAM *pdf_add_stream_line_to(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y)   SECT("@P2ASLT");

/* string */
PDFSTR *pdf_new_str(PDF *pdf, const char *str)                                  SECT("@P2NSTR");
PDFSTR *pdf_new_strf(PDF *pdf, const char *fmt, ...)                            SECT("@P2NSTRF");
char *pdf_string(PDF *pdf, const char *str)                                     SECT("@P2STR");
char *pdf_stringf(PDF *pdf, const char *fmt, ...)                               SECT("@P2STRF");
char *pdf_date_string(PDF *pdf, const time_t *time)                             SECT("@P2DSTR");

/* page */
PDFPAGE *pdf_new_page(PDF *pdf, int width, int height)                          SECT("@P2NPAG");
void pdf_boundaries(PDF *pdf)                                                   SECT("@P2BNDS");
void pdf_boundaries_page(PDF *pdf)                                              SECT("@P2BNDP");
void pdf_boundaries_crop(PDF *pdf)                                              SECT("@P2BNDC");
void pdf_boundaries_text(PDF *pdf)                                              SECT("@P2BNDT");
void pdf_boundaries_leading(PDF *pdf)                                           SECT("@P2BNDL");
void pdf_boundaries_lpp(PDF *pdf)                                               SECT("@P2BNDLP");
PDFPAGE *pdf_add_page_contents(PDF *pdf, PDFPAGE *pdfpage, void *obj)           SECT("@P2APCNT");
PDFPAGE *pdf_add_page_annots(PDF *pdf, PDFPAGE *pdfpage, void *obj)             SECT("@P2APANN");

/* pages */
PDFPAGES *pdf_new_pages(PDF *pdf)                                               SECT("@P2NPAGS");
PDFPAGES *pdf_add_pages_page(PDF *pdf, PDFPAGES *pdfpages, PDFPAGE *pdfpage)    SECT("@P2APGSP");

/* view preferences */
PDFVIEWPREF *pdf_new_viewpref(PDF *pdf)                                         SECT("@P2NVPRF");
PDFVIEWPREF *pdf_add_viewpref_non_full_screen_page_mode(PDF *pdf, PDFVIEWPREF *pdfviewpref, const char *mode) SECT("@P2AVNFS");
PDFVIEWPREF *pdf_add_viewpref_direction(PDF *pdf, PDFVIEWPREF *pdfviewpref, const char *mode) SECT("@P2AVPRD");

/* outlines */
PDFOUTLINES *pdf_new_outlines(PDF *pdf)                                         SECT("@P2NOUTS");

/* outline */
PDFOUTLINE *pdf_new_outline(PDF *pdf)                                           SECT("@P2NOUT");

/* dest */
PDFDEST *pdf_new_dest(PDF *pdf, PDFPAGE *pdfpage, int left, int top)            SECT("@P2NDEST");

/* catalog */
PDFCAT *pdf_new_cat(PDF *pdf)                                                   SECT("@P2NCAT");
PDFCAT *pdf_add_cat_page_layout(PDF *pdf, PDFCAT *pdfcat, const char *layout)   SECT("@P2ACPL");
PDFCAT *pdf_add_cat_page_mode(PDF *pdf, PDFCAT *pdfcat, const char *mode)       SECT("@P2ACPM");

/* font */
PDFFONT *pdf_new_font(PDF *pdf, const char *subtype, const char *basefont, const char *encoding, const char *alias, const char *abbrev) SECT("@P2NFONT");
PDFFONT *pdf_find_font(PDF *pdf, const char *name)                              SECT("@P2FFONT");

/* resource */
PDFRESOURCE *pdf_new_resource(PDF *pdf)                                         SECT("@P2NRES");
PDFRESOURCE *pdf_add_resource_proc_set(PDF *pdf, PDFRESOURCE *pdfresource, const char *name) SECT("@P2ARPS");
PDFRESOURCE *pdf_add_resource_name_font(PDF *pdf, PDFRESOURCE *pdfresource, const char *name, PDFFONT *pdffont) SECT("@P2ARNF");
PDFRESOURCE *pdf_add_resource_name_xobj(PDF *pdf, PDFRESOURCE *pdfresource, const char *name, void *xobj) SECT("@P2ARNX");


/* colors */
PDFCOLOR *pdf_new_color(PDF *pdf, const char *name, const char *abbrev, unsigned rgb) SECT("@P2NCOL");
const char *pdf_color_spec(PDFCOLOR **pdfcolors, const char *name, char *buf)   SECT("@P2CSPEC");
const char *pdf_color_spec_array(PDFCOLOR **pdfcolors, const char *name, char *buf) SECT("@P2CSPCA");
PDFCOLOR *pdf_find_color(PDFCOLOR **pdfcolors, const char *name)                SECT("@P2PFCOL");

/* utility functions */
unsigned char *pdf_translate(unsigned char *str, const unsigned char *tab)      SECT("@P2TRANS");
char *pdf_escape(const char *in, char *out)                                     SECT("@P2ESCAP");
int pdf_case_cmp(const char *p1, const char *p2)                                SECT("@P2PCCMP");

/* background */
PDFSTREAM *pdf_new_background(PDF *pdf)                                         SECT("@P2NBACK");
PDFSTREAM *pdf_add_stream_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color) SECT("@P2ASCLR");
PDFSTREAM *pdf_add_stream_bar(PDF *pdf, PDFSTREAM *pdfstream, unsigned width, const char *color) SECT("@P2ASBAR");
PDFSTREAM *pdf_add_stream_file_include(PDF *pdf, PDFSTREAM *pdfstream, const char *file) SECT("@P2ASFI");

typedef enum pdf_watermark_style    PDF_WATERMARK_STYLE;
enum pdf_watermark_style {
    PDF_WATERMARK_BOTTOMUP = 0,
    PDF_WATERMARK_TOPDOWN,
    PDF_WATERMARK_TDBOXED,
    PDF_WATERMARK_BUBOXED
};
PDFSTREAM *pdf_add_stream_text_mark(PDF *pdf, PDFSTREAM *pdfstream, PDF_WATERMARK_STYLE style, const char *strokecolor,
                                    const char *fillcolor, unsigned fontsize, const char *font, const char *text) SECT("@P2ASTM");

/* graphics */
PDFSTREAM *pdf_graphic_save(PDF *pdf, PDFSTREAM *pdfstream)                     SECT("@P2GSAVE");
PDFSTREAM *pdf_graphic_restore(PDF *pdf, PDFSTREAM *pdfstream)                  SECT("@P2GREST");
PDFSTREAM *pdf_graphic_stroke_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color) SECT("@P2GSCOL");
PDFSTREAM *pdf_graphic_fill_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color) SECT("@P2GFCOL");
PDFSTREAM *pdf_graphic_move_to(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y) SECT("@P2GMVTO");
PDFSTREAM *pdf_graphic_line_to(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y) SECT("@P2GLNTO");
PDFSTREAM *pdf_graphic_dash_line(PDF *pdf, PDFSTREAM *pdfstream, unsigned on, unsigned off, unsigned phase) SECT("@P2GDL");
PDFSTREAM *pdf_graphic_solid_line(PDF *pdf, PDFSTREAM *pdfstream)               SECT("@P2GSL");
PDFSTREAM *pdf_graphic_stroke(PDF *pdf, PDFSTREAM *pdfstream)                   SECT("@P2GSTRO");
PDFSTREAM *pdf_graphic_close_path(PDF *pdf, PDFSTREAM *pdfstream)               SECT("@P2GCPTH");
PDFSTREAM *pdf_graphic_line_width(PDF *pdf, PDFSTREAM *pdfstream, unsigned width) SECT("@P2GLINW");
PDFSTREAM *pdf_graphic_circle(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y, unsigned r, const char *stroke) SECT("@P2GCIRC");

/* bookmarks */
PDFOUTLINE *pdf_new_bookmark(PDF *pdf, PDFOUTLINE *parent, const char *title, const char *color, PDFPAGE *pdfpage, unsigned x, unsigned y) SECT("@P2NBKMK");
PDFOUTLINE *pdf_new_bookmark_page(PDF *pdf, PDFOUTLINE *parent, const char *title, const char *color, PDFPAGE *pdfpage) SECT("@P2NBKMP");
PDFOUTLINE *pdf_new_bookmark_dest(PDF *pdf, PDFOUTLINE *parent, const char *title, const char *color, PDFDEST *pdfdest) SECT("@P2NBKMD");

/* document info */
PDFINFO *pdf_new_info(PDF *pdf, const char *title, const char *subject, const char *author, const char *keywords,
                      const char *creator, const char *producer, const time_t *created) SECT("@P2NINFO");

/* image */
PDFIMAGE *pdf_new_image(PDF *pdf, unsigned width, unsigned height, const char *colorspace, unsigned bitspercomponent) SECT("@P2NIMG");
PDFIMAGE *pdf_add_image(PDF *pdf, PDFIMAGE *pdfimage, const unsigned char *data, int len) SECT("@P2AIMG");

#endif /* PDF_H */
