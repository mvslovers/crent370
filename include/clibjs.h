#ifndef CLIBJS_H
#define CLIBJS_H

#include "osdcb.h"

typedef struct haspjs       HASPJS;     /* JES Spool Dataset                */

struct haspjs {
    char            eye[8];         /* 00 eye catcher for dumps             */
#define HASPJS_EYE   "HASPJS"       /* ...                                  */
    char            ddname[8];      /* 08 DD name                           */
    DCB             *dcb;           /* 10 DCB address                       */
    unsigned int    trkcyl;         /* 14 Number of tracks per cylinder     */
};

extern HASPJS * __jsopen(const char *dataset);
extern HASPJS * spool_open(const char *dataset);           /* pseudo name for codeblocks */
#define spool_open(dataset)    __jsopen((dataset))

extern int      __jsclos(HASPJS *js);
extern int      spool_close(HASPJS *js);                   /* pseudo name for codeblocks */
#define spool_close(cp)        __jsclos((cp))

extern int      __jsrd4(HASPJS *js, unsigned mttr, void *buf4k, unsigned buflen);
extern int      spool_read(HASPJS *js, unsigned mttr, void *buf4k, unsigned buflen);
#define spool_read(js,mttr,buf4k,buflen) __jsrd4((js),(mttr),(buf4k),(buflen))

#endif


