#ifndef PDFI_H
#define PDFI_H

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <clibwto.h>
#include <clibary.h>    /* dynamic array */
#include <socket.h>     /* has struct timeval, go figure! */
#include <clibprtf.h>   /* new printf function (end with _ character) like printf_() */
#include "../pdf2/pdf.h"

/* we're testing new printf functions */
#define printf      printf_
#define sprintf     sprintf_
#define snprintf    snprintf_
#define vsprintf    vsprintf_
#define vsnprintf   vsnprintf_

#define PDF_ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

#define PDF_RGB_R(c) ((((c) >> 16) & 0xff) / 255.0)
#define PDF_RGB_G(c) ((((c) >> 8) & 0xff) / 255.0)
#define PDF_RGB_B(c) ((((c) >> 0) & 0xff) / 255.0)
#define PDF_IS_TRANSPARENT(c) (((c) >> 24) == 0xff)

#ifndef M_SQRT2
#define M_SQRT2 1.41421356237309504880f
#endif

typedef enum   objtype          OBJTYPE;    /* identifies object type */

/* internal functions */
int pdf_out(PDF *pdf, int len, const char *data)                                SECT("@P2OUT");
int pdf_tell(PDF *pdf)                                                          SECT("@P2TELL");

struct pdf {
    /* */
    char            eye[4];             /* 00 eye catcher for dumps                     */
#define PDF_EYE "PDF*"                  /* ...                                          */
    const char      *ebc2asc;           /* 04 EBCDIC to ASCII translation table         */
    int             holesize;           /* 08 size of holes in paper                    */
    int             lpi;                /* 0C lines per inch                            */

    int             (*out)(void *udata, int len, const char *data);
                                        /* 10 PDF written via the out function pointer  */
    void            *udata;             /* 14 user data for the out and tell functions  */
    int             (*tell)(void *udata);
                                        /* 18 return output position (like ftell())     */
    unsigned        unused2;            /* 1C unused                                    */

    unsigned char   flags;              /* 20 processing flags                          */
#define PDF_FLAG_NO_OUTPUT      0x80    /* ... disable all further output               */

    unsigned char   options;            /* 21 processing options                        */
#define PDF_OPTION_COMPRESS     0x80    /* ... compression requested                    */
#define PDF_OPTION_DEBUG        0x40    /* ... debug output enabled                     */
#define PDF_OPTION_HAS_HOLES    0x20    /* ... page has holes                           */

    signed char     gmthours;           /* 22 local offset from GMT hours (-23 to +23)  */
    unsigned char   gmtmins;            /* 23 local offset from GMT minutes (0 to 59)   */

    PDFOBJ          **objects;          /* 24 array of objects                          */
    int             *offsets;           /* 28 array of object offsets in PDF file       */
    PDFCOLOR        **colors;           /* 2C array of color objects                    */

    PDFCAT          *catalog;           /* 30 catalog object                            */
    PDFPAGES        *pages;             /* 34 pages object                              */
    PDFOUTLINES     *outlines;          /* 38 outlines (bookmark) object                */
    unsigned        unused5;            /* 3C unused                                    */

    PDFPAGE         *current_page;      /* 40 current page object                       */
    int             lpp;                /* 44 lines per page                            */
    int             leading;            /* 48 sets line spacing on page                 */
    unsigned        unused6;            /* 4C unused                                    */

    int             width;              /* 50 this is the default page width in points  */
    int             height;             /* 54 this is the default page height in points */
    int             current_font;       /* 58 current font object number                */
    int             current_index;      /* 5C next object index                         */

    PDFFONT         **pdffonts;         /* 60 array of defined fonts                    */
    PDFINFO         *pdfinfo;           /* 64 information object                        */
    unsigned        unused7[2];         /* 68 unused                                    */

    /* The following are used to set the boundaries of a page */
    int             lmargin;            /* 70 left margin in points                     */
    int             rmargin;            /* 74 right margin in points                    */
    int             tmargin;            /* 78 top margin in points                      */
    int             bmargin;            /* 7C bottom margin in points                   */

    /* The following are set for each new page */
    int             paperw;             /* 80 paper width in points                     */
    int             paperh;             /* 84 paper height in points                    */
    int             pagel;              /* 88 page left margin                          */
    int             pager;              /* 8C page right margin                         */
    int             paget;              /* 90 page top margin                           */
    int             pageb;              /* 94 page bottom margin                        */
    int             pagew;              /* 98 page width                                */
    int             pageh;              /* 9C page height                               */

    int             cropl;              /* A0 crop left margin                          */
    int             cropr;              /* A4 crop right margin                         */
    int             cropt;              /* A8 crop top margin                           */
    int             cropb;              /* AC crop bottom margin                        */
    int             cropw;              /* B0 crop width                                */
    int             croph;              /* B4 crop Height                               */

    int             textl;              /* B8 text left margin                          */
    int             textr;              /* BC text right margin                         */
    int             textt;              /* C0 text top margin                           */
    int             textb;              /* C4 text bottom margin                        */
    int             textw;              /* C8 text width                                */
    int             texth;              /* CC text height                               */
};

/* every PDF object has a type code value */
enum pdftype {
    OBJNULL = 0,                /* Object is a null object                              */
    OBJARRAY,                   /* Object is a [array]                                  */
    OBJBOOL,                    /* Object is a boolean value                            */
    OBJDATE,                    /* Object is a date (string)                            */
    OBJDEST,                    /* Object is a dest [page /XYZ left top null]           */
    OBJFILE,                    /* Object is a file specification (string or dictionary)*/
    OBJIMAGE,                   /* Object is an Image (XObject stream)                  */
    OBJINFO,                    /* Object is a information dictionary                   */
    OBJINT,                     /* Object is an integer                                 */
    OBJNAME,                    /* Object is a /name                                    */
    OBJNAMETREE,                /* Object is a name tree (dictionary)                   */
    OBJNUM,                     /* Object is a number (real or integer)                 */
    OBJNUMTREE,                 /* Object is a number tree (dictionary)                 */
    OBJNUMPAIR,                 /* Object is a number pair (part of number tree)        */
    OBJRECT,                    /* Object is a rectangle (array)                        */
    OBJSTREAM,                  /* Object is a stream ... endstream                     */
    OBJSTR,                     /* Object is a (string)                                 */
    OBJVIEWPREF,                /* Object is a view preference (dictionary)             */
    OBJOUTLINES,                /* Object is a outlines (dictionary)                    */
    OBJOUTLINE,                 /* Object is a outline (dictionary) aka Bookmark        */
    OBJPAGE,                    /* Object is a page (dictionary)                        */
    OBJPAGES,                   /* Object is a pages (dictionary)                       */
    OBJRESOURCE,                /* Object is a resource (dictionary)                    */
    OBJFONT,                    /* Object is a font (dictionary)                        */
    OBJSTROBJPAIR,              /* Object is a string object pair "(string) nn 0 R"     */
    OBJNAMEOBJPAIR,             /* Object is a name object pair "/name nn 0 R"          */
    OBJCOLOR,                   /* Object is a color object RGB values "n.nn n.nn n.nn" */
    OBJCATALOG                  /* Object is a catalog (dictionary)                     */
};

/* all PDF objects has a common header */
struct pdfobj {
    int         type;                       /* 00 object type code                      */
    int         index;                      /* 04 object number                         */
    int         offset;                     /* 08 offset of object in PDF file          */
    unsigned    unused;                     /* 0C unused, align to double word          */
};

struct pdfnull {
    PDFOBJ      obj;                        /* 00 object header                         */
};                                          /* 10 (16 bytes)                            */

struct pdfarray {
    PDFOBJ      obj;                        /* 00 object header                         */
    PDFOBJ      **objects;                  /* 10 array of objects                      */
};                                          /* 14 (20 bytes)                            */

struct pdfbool {
    PDFOBJ      obj;                        /* 00 object header                         */
    int         value;                      /* 10 value (boolean)                       */
};                                          /* 14 (20 bytes)                            */

struct pdfdate {
    PDFOBJ      obj;                        /* 00 object header                         */
    struct tm   time;                       /* 10 time as struct tm                     */
};                                          /* 34 (52 bytes)                            */

struct pdffile {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        *file;                      /* 10 file name                             */
};                                          /* 14 (20 bytes)                            */

struct pdfint {
    PDFOBJ      obj;                        /* 00 object header                         */
    int         value;                      /* 10 integer value                         */
};                                          /* 14 (20 bytes)                            */

struct pdfname {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        *name;                      /* 10 name                                  */
};                                          /* 14 (20 bytes)                            */

struct pdfstrobjpair {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        *str;                       /* 10 "(string) ..."                        */
    PDFOBJ      *pdfobj;                    /* 14 " ...     nn 0 R"                     */
};                                          /* 18 (24 bytes)                            */

struct pdfnameobjpair {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        *name;                      /* 10 "/name ..."                           */
    PDFOBJ      *pdfobj;                    /* 14 " ...  nn 0 R"                        */
};                                          /* 18 (24 bytes)                            */

struct pdfnametree {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        *namelow;                   /* 10 "/Limits [(low) ...]"                 */
    char        *namehigh;                  /* 14 "/Limits [...(high)]"                 */
    PDFOBJ      **kids;                     /* 18 "/Kids [nn 0 R ... nn 0 R]"           */
    PDFSTROBJPAIR **strobjpair;             /* 1C "/Names [(name) nn 0 R ... (name) nn 0 R]" */
};                                          /* 20 (32 bytes)                            */

struct pdfnum {
    PDFOBJ      obj;                        /* 00 object header                         */
    double      value;                      /* 10 value                                 */
};                                          /* 18 (24 bytes)                            */

struct pdfnumpair {
    PDFOBJ      obj;                        /* 00 object header                         */
    int         value;                      /* 10 nnn ...                               */
    PDFOBJ      *pdfobj;                    /* 14 ... nn 0 R                            */
};                                          /* 18 (24 bytes)                            */

struct pdfnumtree {
    PDFOBJ      obj;                        /* 00 object header                         */
    PDFOBJ      *intlow;                    /* 10 "/Limits [ low ...]"                  */
    PDFOBJ      *inthigh;                   /* 14 "/Limits [... high]"                  */
    PDFOBJ      **kids;                     /* 18 "/Kids [nn 0 R ... nn 0 R]"           */
    PDFNUMPAIR  **pdfnumpair;               /* 1C "/Nums [ int nn 0 R ... int nn 0 R]"  */
};

struct pdfrect {
    PDFOBJ      obj;                        /* 00 object header                         */
    int         bx;                         /* 10 bottom x                              */
    int         by;                         /* 14 bottom y                              */
    int         tx;                         /* 18 top x                                 */
    int         ty;                         /* 1C top y                                 */
};

typedef struct dstr {
    int         size;                       /* 00 size of stream                        */
    int         len;                        /* 04 length of data in stream              */
    char        *stream;                    /* 08 stream Data                           */
} DSTR;

struct pdfstream {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        **keyvals;                  /* 10 "other key value pairs"               */
    int         len;                        /* 14 "/Length nnn" Length of stream        */
    PDFOBJ      **objfilters;               /* 18 "/Filter [...]"                       */
    PDFOBJ      **objdecodes;               /* 1C "/DecodeParms [...]"                  */
    PDFOBJ      *objfile;                   /* 20 "/F ..." file specification           */
    PDFOBJ      **objffilters;              /* 24 "/FFilter [...]"                      */
    PDFOBJ      **objfdecodes;              /* 28 "/FDecodeParms [...]"                 */
    DSTR        **dstrs;                    /* 2C "stream\r\n...\r\nendstream\r\n"      */
};

struct pdfcolor {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        *name;                      /* 10 color common name                     */
    char        *abbrev;                    /* 14 color abbreviation                    */
    unsigned    rgb;                        /* 18 color red,green,blue value            */
};                                          /* 1C (28 bytes)                            */

struct pdfstr {
    PDFOBJ      obj;                        /* 00 object header                         */
    char        *str;                       /* 10 string                                */
};                                          /* 14 (20 bytes)                            */

struct pdfpage {
    PDFOBJ      obj;                        /* 00 object header ... "/Type /Page"       */
    PDFPAGES    *pages;                     /* 10 "/Parent nn 0 R"                      */
    PDFRESOURCE *resource;                  /* 14 "/Resources nn 0 R"                   */
    PDFRECT     *medixbox;                  /* 18 "/MediaBox  [bx by tx ty]"            */
    PDFRECT     *cropbox;                   /* 1C "/CropBox [bx by tx ty]"              */
    PDFOBJ      *boxcolorinfo;              /* 20 "/BoxColorInfo nn 0 R"                */
    PDFOBJ      **contents;                 /* 24 "/Contents nn 0 R | [nn 0 R ... nn 0 R]" */
    PDFOBJ      *group;                     /* 28 "/Group nn 0 R"                       */
    PDFOBJ      **annots;                   /* 2C "/Annots [nn 0 R .. nn 0 R]"          */
    int         rotate;                     /* 30 "/Rotate nn"                          */
};                                          /* 34 (52 bytes)                            */

struct pdfpages {
    PDFOBJ      obj;                        /* 00 object header ... "/Type /Pages"      */
    PDFCAT      *pdfcat;                    /* 10 "/Parent nn 0 R"                      */
    PDFPAGE     **pdfpage;                  /* 14 "/Kids [nn 0 R ... nn 0 R]"           */
};

struct pdfviewpref {
    PDFOBJ      obj;                        /* 00 object header ... "/Type /Pages"      */
    int         hidetoolbar;                /* 10 "/HideToolbar true | false"           */
    int         hidemenubar;                /* 14 "/HideMenubar true | false"           */
    int         hidewindowui;               /* 18 "/HideWindowUI true | false"          */
    int         fitwindow;                  /* 1C "/FitWindow true | false"             */
    int         centerwindow;               /* 20 "/CenterWindow true | false"          */
    char        *nonfullscreenpagemode;     /* 24 "/NonFullScreenPageMode UseNone | UseOutlines | UseThumbs" */
    char        *direction;                 /* 28 "/Direction L2R | R2L"                */
};                                          /* 2C (44 bytes)                            */

struct pdfoutlines {
    PDFOBJ      obj;                        /* 00 object header                         */
    PDFOBJ      *first;                     /* 10 "/First nn 0 R"                       */
    PDFOBJ      *last;                      /* 14 "/Last nn 0 R"                        */
    int         count;                      /* 18 "/Count nnn"                          */
};

struct pdfoutline {
    PDFOBJ      obj;                        /* 00 object header                         */
    PDFOBJ      *first;                     /* 10 "/First nn 0 R"                       */
    PDFOBJ      *last;                      /* 14 "/Last nn 0 R"                        */
    int         count;                      /* 18 "/Count nnn"                          */
    char        *title;                     /* 1C "/Title required string"              */
    PDFOBJ      *parent;                    /* 20 "/Parent nn 0 R"                      */
    PDFOBJ      *prev;                      /* 24 "/Prev nn 0 R"                        */
    PDFOBJ      *next;                      /* 28 "/Next nn 0 R"                        */
    PDFOBJ      *dest;                      /* 2C "/Dest name | string | [array]"       */
    PDFOBJ      *a;                         /* 30 "/A nn 0 R"                           */
    PDFOBJ      *se;                        /* 34 "/SE nn 0 R"                          */
    char        *color;                     /* 38 "/C [0.0 0.0 0.0]" RGB color array    */
    int         flag;                       /* 3C "/F n" 1=Italic, 2=Bold, 3=Italic+Bold */
};                                          /* 40 (64 bytes)                            */

struct pdfcat {
    PDFOBJ      obj;                        /* 00 object header "/Type /Catalog"        */
    PDFPAGES    *pages;                     /* 10 "/Pages nn 0 R" Dictionary            */
    PDFVIEWPREF *viewpref;                  /* 14 "/ViewerPreferences nn 0 R" Dictionary */
    char        *pagelayout;                /* 18 "/PageLayout SinglePage|OneColumn|TwoColumnLeft|TwoColumnRight" Name */
    char        *pagemode;                  /* 1C "/PageMode UseNone|UseOutlines|UseThumbs|FullScreen" Name */
    PDFOUTLINES *outlines;                  /* 20 "/Outlines nn 0 R" Dictionary         */
    PDFDEST     *dest;                      /* 24 "/OpenAction destination              */
};                                          /* 28 (40 bytes)                            */

struct pdfdest {
    PDFOBJ      obj;                        /* 00 object header                         */
    PDFPAGE     *page;                      /* 10 Page                                  */
    int         left;                       /* 14            Left                       */
    int         top;                        /* 18                       Top             */
};                                          /* 1C (28 bytes)                            */

struct pdffont {
    PDFOBJ      obj;                        /* 00 object header "/Type Font"            */
    char        *subtype;                   /* 10 "/Subtype /name"                      */
    char        *basefont;                  /* 14 "/BaseFont /name"                     */
    char        *alias;                     /* 18 not printed (lookup only)             */
    char        *abbrev;                    /* 1C not printed (lookup only)             */
    int         firstchar;                  /* 20 "/FirstChar n"                        */
    int         lastchar;                   /* 24 "/LastChar n"                         */
    PDFOBJ      *widths;                    /* 28 "/Widths nn 0 R"  (array of int)      */
    PDFOBJ      *fontdescriptor;            /* 2C "/FontDescriptor nn 0 R" (dictionary) */
    char        *encoding;                  /* 30 "/Encoding /name"                     */
};                                          /* 34 (52 bytes)                            */

struct pdfresource {
    PDFOBJ      obj;                        /* 00 object header "/Type Font"            */
    char        **procset;                  /* 10 "/ProcSet [/name1 ... /nameN]"        */
    PDFNAMEOBJPAIR **nameobjpairfont;       /* 14 "/Font << ... >>"                     */
    PDFNAMEOBJPAIR **nameobjpairxobj;       /* 18 "/XObject << ... >>"                  */
};                                          /* 1C (28 bytes)                            */

struct pdfinfo {
    PDFOBJ      obj;                        /* 00 object header "/Type Font"            */
    char        *title;                     /* 10 Document Title                        */
    char        *subject;                   /* 14 Subject string                        */
    char        *author;                    /* 18 Author                                */
    char        *keywords;                  /* 1C Keywords                              */
    char        *creator;                   /* 20 Creator of original document          */
    char        *producer;                  /* 24 Creator of output document            */
    char        *created;                   /* 28 Created date (D:YYYYMMDDHHMMSS-HH'MM')*/
};                                          /* 2C (44 bytes)                            */

struct pdfimage {
    PDFOBJ      obj;                        /* 00 object header "/Type /XObject"        */
    unsigned    width;                      /* 10 Width of image             (required) */
    unsigned    height;                     /* 14 Height of image            (required) */
    char        *colorspace;                /* 18 Colorspace                 (required except for imagemask)
                                               ... DeviceGray, DeviceRGB, DeviceCMYK,
                                               ... CalGray, CalRGB, Lab, ICCBased,
                                               ... Indexed, Pattern, Seperation, DeviceN*/
    unsigned    bitspercomponent;           /* 1C Bit per component          (required) */
    char        *intent;                    /* 20 Color rendering intent     (optional) */
    int         imagemask;                  /* 24 boolean                    (optional)
                                               ... if true nBitsPerComponent must be 1
                                               ... and Mask and Colorspace should not
                                               ... be specified                         */
    char        *mask;                      /* 28 an image mask XObject to apply to
                                               ... this image                (optional) */
    char        *smask;                     /* 2C an image soft mask XObject to apply
                                               ... to this image             (optional) */
    char        *decode;                    /* 30 Decode Array [n n ...]     (optional) */
    int         interpolate;                /* 34 boolean                    (optional) */
    DSTR        *dstr;                      /* 38 stream ... endstream       (optional) */
    char        *encoding;                  /* 3C encoding of stream         (optional) */
};                                          /* 40 (64 bytes)                            */

struct pdf_private {
    DSTR *      (*pdf_get_dstr)(PDF *pdf, PDFSTREAM *pdfstream);
    void        (*pdf_add_dstr)(PDF *pdf, PDFSTREAM *pdfstream, int len, const char *stream);
    double *    (*pdf_calc_arc)(double r, double a, double f[8]);
};

#ifdef PDF_PRIVATE
extern struct pdf_private *_p2core;
#define pdf_get_dstr(pdf,pdfstream)                                         \
    ((_p2core->pdf_get_dstr)((pdf),(pdfstream)))
#define pdf_add_dstr(pdf,pdfstream,len,stream)                              \
    ((_p2core->pdf_add_dstr)((pdf),(pdfstream),(len),(stream)))
#define pdf_calc_arc(radius,angle,result)                                   \
    ((_p2core->pdf_calc_arc)((radius),(angle),(result)))
#endif

#endif /* PDFI_H */
