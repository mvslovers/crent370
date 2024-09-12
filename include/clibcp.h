#ifndef CLIBCP_H
#define CLIBCP_H

#include "osdcb.h"
#include "hasphct.h"    /* JES Checkpoint Control Table, record 3 in HASPCKPT */
#include "haspjqe.h"    /* JES Job Queue Elements                             */
#include "haspjot.h"    /* JES Job Output Table                               */

typedef struct haspcp   HASPCP;     /* JES Checkpoint Dataset   */

struct haspcp {
    char            eye[8];         /* 00 eye catcher for dumps             */
#define HASPCP_EYE   "HASPCP"       /* ...                                  */
    char            ddname[8];      /* 08 DD name                           */
    DCB             *dcb;           /* 10 DCB address                       */
    __HCT           hct;            /* 14 Checkpoint Control Table          */
    unsigned int    pddb1;          /* E0 Offset to first PDDB in IOT       */
    unsigned short  jqeblks;        /* E4 Number of JQE blocks              */
    unsigned short  jotblks;        /* E6 number of JOT blocks              */
    unsigned        buflen;         /* E8 Length of Checkpoint buffer       */
    char            *buf;           /* EC Checkpoint buffer                 */
    __JQE           *jqe;           /* F0 Job Queue Elements                */
    __JQE           *jqeend;        /* F4 End of Job Queue Elements         */
    __JOT           *jot;           /* F8 Job Output Table                  */
    __JOT           *jotend;        /* FC End of Job Output Table           */
};

extern HASPCP * __cpopen(const char *dataset);
extern HASPCP * checkpoint_open(const char *dataset);           /* pseudo name for codeblocks */
#define checkpoint_open(dataset)    __cpopen((dataset))

extern int      __cpclos(HASPCP *cp);
extern int      checkpoint_close(HASPCP *cp);                   /* pseudo name for codeblocks */
#define checkpoint_close(cp)        __cpclos((cp))

extern int      __cppoin(HASPCP *cp, unsigned TTRz);
extern int      checkpoint_point(HASPCP *cp, unsigned TTRZ);    /* pseudo name for codeblocks */
#define checkpoint_point(cp,ttrz)   __cppoin((cp),(ttrz))

extern int      __cpread(HASPCP *cp, void *buf4k);
extern int      checkpoint_read(HASPCP *cp, void *buf4k);       /* pseudo name for codeblocks */
#define checkpoint_read(cp,buf4k)   __cpread((cp),(buf4k))

#endif
