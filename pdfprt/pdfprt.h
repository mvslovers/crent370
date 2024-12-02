#ifndef PDFPRT_H
#define PDFPRT_H

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
#include <clibary.h>        /* dynamic array */
#include <socket.h>         /* has struct timeval, go figure! */
#include <clibprtf.h>       /* new printf function (end with _ character) like printf_() */
#include "../pdf2/pdf.h"    /* pdf prototypes */

/* we're testing new printf functions */
#define printf      printf_
#define sprintf     sprintf_
#define snprintf    snprintf_
#define vsprintf    vsprintf_
#define vsnprintf   vsnprintf_

#ifndef __MVS__
#define __MVS__
#endif

#ifdef __MVS__
#define SECT(name)      asm(name)
#else
#define SECT(name)
#endif

typedef struct pdfprt       PDFPRT;

struct pdfprt {
    char            eye[8];                 /* 00 eye catcher for dumps                 */
#define PDFPRT_EYE  "*PDFPRT*"              /* ... eye catcher for dumps                */
    unsigned        incount;                /* 08 input record count                    */
    unsigned        outcount;               /* 0C output record count                   */

    unsigned        pagelines;              /* 10 number of lines written to page       */
    unsigned        sumlines;               /* 14 number of line written to summary page*/
    unsigned        pagecount;              /* 18 number of pages created               */
    unsigned        sumcount;               /* 1C number of summary pages               */
    int             (*out)(void *udata, int len, const char *data);
                                            /* 20 write output via the out function pointer  */
    void            *udata;                 /* 24 user data for the out and tell functions  */
    int             (*tell)(void *udata);   /* 28 returns offset in current output      */
    unsigned        unused1;                /* 2C unused                                */

    PDF             *pdf;                   /* 30 output PDF handle                     */
    PDFPAGE         *page;                  /* 34 page object                           */
    PDFPAGE         *sumpage;               /* 38 summary page                          */
    unsigned        unused2;                /* 3C unused                                */

    PDFOUTLINES     *outlines;              /* 40 outlines dictionary                   */
    PDFOUTLINE      *outlinepages;          /* 44 outline (bookmark) for pages          */
    PDFOUTLINE      *outline;               /* 48 outline (bookmark) object             */
    PDFOUTLINE      *outlinesum;            /* 4C summary outline (bookmark) object     */

    PDFSTREAM       *background;            /* 50 stream for background goodies         */
    PDFSTREAM       *pagestream;            /* 54 stream for page contents              */
    PDFSTREAM       *sumstream;             /* 58 stream for summary page contents      */
    unsigned        fontsize;               /* 5C font size in points                   */

    PDFRESOURCE     *resource;              /* 60 resource dictionary for fonts         */
    char            *greenbarcolor;         /* 64 greenbar color name                   */
    char            *watermarktext;         /* 68 watermark text                        */
    unsigned char   flags;                  /* 6C processing flags                      */
    unsigned char   options;                /* 6D processing options                    */
#define PDFPRT_OPTION_THREERING     0x80    /* ... add holes for binder                 */
#define PDFPRT_OPTION_LANDSCAPE     0x40    /* ... landscape pages                      */
#define PDFPRT_OPTION_BOOKMARK      0x20    /* ... create bookmarks                     */
#define PDFPRT_OPTION_SUMMARY       0x10    /* ... create summary page                  */
#define PDFPRT_OPTION_GREENBAR      0x08    /* ... create greenbar on each page         */
#define PDFPRT_OPTION_WATERMARK     0x04    /* ... create watermark on each page        */
#define PDFPRT_OPTION_BOLD          0x02    /* ... use BOLD font                        */
    unsigned char   unused4;                /* 6E unused                                */
    unsigned char   unused5;                /* 6F unused                                */
};                                          /* 70 (112 bytes)                           */

PDFPRT *pdfprt_new(int(*out)(void *udata, int len, const char *data), int (*tell)(void *udata), void *udata)    SECT("@P3NPRT");
int pdfprt_out(void *udata, int len, const char *data)                              SECT("@P3PROUT");
int pdfprt_tell(void *udata)                                                        SECT("@P3PRTEL");

#endif  /* PDFPRT_H */
