#ifndef CLIBSSCT_H
#define CLIBSSCT_H
#include "clibssvt.h"

typedef struct ssct     SSCT;   /* subsystem CVT, SP=241 KEY=0              */
/* Note: The address of the first SSCT is in CVTJESCT at offset 0x18        */
/*       ssct = cvt->cvtjesct->jesssct                                      */

struct ssct {
    char        ssctid[4];      /* 00 CL4'SSCT' CONTROL BLOCK IDENTIFIER    */
#define SSCT_EYE    "SSCT"      /* ...                                      */
    SSCT        *ssctscta;      /* 04 PTR TO NEXT SSCVT OR ZERO             */
    char        ssctsnam[4];    /* 08 SUBSYSTEM NAME                        */
    char        ssctflg1;       /* 0C FLAGS                                 */
#define SSCTSFOR    0x80        /* ... SERIAL FIB OPERATIONS REQUIRED       */
#define SSCTUPSS    0x40        /* ... USE PRIMARY SUBSYSTEM'S
                                       SERVICES FOR THIS SUBSYSTEM          */
    char        ssctssid;       /* 0D SUBSYSTEM IDENTIFIER. SET BY
                                      SUBSYSTEM FIRST TIME IT IS
                                      INVOKED AFTER IPL                     */
#define SSCTUNKN    0x00        /* ... UNKNOWN SUBSYSTEM ID                 */
#define SSCTJES2    0x02        /* ... JES2 SUBSYSTEM ID                    */
#define SSCTJES3    0x03        /* ... JES3 SUBSYSTEM ID                    */
    char        ssctrsv1[2];    /* 0E RESERVED                              */
    SSVT        *ssctssvt;      /* 10 SUBSYSTEM VECTOR TABLE POINTER        */
    void        *ssctsuse;      /* 14 RESERVED FOR SUBSYSTEM USAGE          */
};

/* ssct_new() allocate SSCT storage, requires supervisor state */
SSCT *ssct_new(const char *name, SSVT *ssvt, void *suse)            asm("@@SSNEW");

/* ssct_free() deallocate SSCT storage, requires supervisor state */
void ssct_free(SSCT *ssct)                                          asm("@@SSFREE");

/* ssct_find() find subsystem storage by name */
SSCT *ssct_find(const char *name)                                   asm("@@SSFIND");

/* ssct_install() install SSCT as subsystem after after_name subsystem, requires supervisor state */
/* note: when after_name is NULL ssct is placed after the first subsystem, usually "JES2" or "MSTR" */
/* note: when after_name is not found, ssct is placed after the last subsystem */
int ssct_install(SSCT *ssct, const char *after_name)                asm("@@SSINST");

/* ssct_remove() remove SSCT as subsystem, requires supervisor state and key 0 */
int ssct_remove(SSCT *ssct)                                         asm("@@SSREM");

/* ssct_remove_by_name() remove SSCT as subsystem, requires supervisor state and key 0 */
int ssct_remove_by_name(const char *name)                           asm("@@SSREMN");

#endif
