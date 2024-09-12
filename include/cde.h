#ifndef CDE_H
#define CDE_H
#include <ihaxtlst.h>

typedef struct cde      CDE;

#pragma pack(1)
struct cde {
/***********************************************************************
 *          MACCOMP OS/VS2,RELEASE 4       SC1CJ/PZD81                 *
 *                                                                     *
 *          MACSTAT OS/VS2,RELEASE 4       74240                       *
 *                                                                     *
 *          MACMEAN CDE MEANS CONTENTS DIRECTORY ENTRY                 *
 ***********************************************************************/
    CDE             *CDCHAIN;   /* 00 ADDRESS OF NEXT CDE IN QUEUE (EITHER JPAQ
                                      OR LPAQ) */
    unsigned        CDRRBP;     /* 04 IF THE MODULE IS REENTERABLE, THIS FIELD
                                      CONTAINS THE ADDRESS OF THE LAST RB THAT
                                      CONTROLLED THE MODULE.  IF THE MODULE IS
                                      SERIALLY REUSABLE, THIS FIELD CONTAINS
                                      THE ADDRESS OF THE RB AT THE TOP OF THE
                                      WAITING (RBPGMQ) QUEUE.  IF THE MODULE
                                      WAS REQUESTED ONLY THROUGH LOAD MACRO
                                      INSTRUCTIONS, CONTAINS ZERO. */
    unsigned char   CDNAME[8];  /* 08 8-BYTE NAME */
    unsigned        CDENTPT;    /* 10 MODULE'S RELOCATED ENTRY POINT ADDRESS */
    union {
        unsigned    CDXLMJP;    /* 14 EXTENT LIST ADDRESS OR MAJOR CDE ADDRESS
                                      IF THIS CDE IS A MINOR */
        XTLST       *xtlst;     /* 14 extent list address, if (!(CDATTR & CDMIN)) */
        CDE         *major;     /* 14 contents directory entry, if (CDATTR & CDMIN) */
    };
    unsigned short  CDUSE;      /* 18 VALUE CONTAINS THE TOTAL MODULE USE
                                      COUNT */
    unsigned char   CDATTRB;    /* 1A FLAG BYTE */
#define CDIDENTY    0x40        /* ... ON=MAJOR BUILT BY IDENTIFY FOR AN
                                       UNAUTHORIZED CALLER THAT IDENTIFIED TO
                                       AN APF LIBRARY JPA MODULE */
#define CDCONTMN    0x02        /* ... ON=CONTAMINATION */

    unsigned char   CDRESV1;    /* 1B RESERVED - D */

    unsigned char   CDATTR;     /* 1C ATTRIBUTE FLAGS */
#define CDNIP       0x80        /* ... MODULE LOADED BY NIP OR FIXED/MODIFIED
                                       LPA MODULE */
#define CDNIC       0x40        /* ... MODULE IS IN PROCESS OF BEING LOADED */
#define CDREN       0x20        /* ... MODULE IS REENTERABLE */
#define CDSER       0x10        /* ... MODULE IS SERIALLY REUSABLE */
#define CDNFN       0x08        /* ... MODULE IS NOT REUSABLE (NON-FUNCTIONAL)*/
#define CDMIN       0x04        /* ... THIS IS A MINOR CDE */
#define CDJPA       0x02        /* ... MODULE IS IN JOB PACK AREA */
#define CDNLR       0x01        /* ... MODULE IS NOT LOADABLE-ONLY */

    unsigned char   CDATTR2;    /* 1D SECOND ATTRIBUTE FIELD */
#define CDSPZ       0x80        /* ... MODULE IS IN SUBPOOL ZERO */
#define CDREL       0x40        /* ... MODULE IS INACTIVE AND MAY BE RELEASED*/
#define CDXLE       0x20        /* ... EXTENT LIST HAS BEEN BUILT FOR MODULE.
                                       MAIN STORAGE OCCUPIED BY MODULE IS
                                       DESCRIBED THEREIN. */
#define CDRLC       0x10        /* ... THIS CDE CONTAINS A MINOR ENTRY POINT
                                       ADDRESS THAT HAS BEEN RELOCATED BY THE
                                       PROGRAM FETCH ROUTINE */
#define CDOLY       0x04        /* ... MODULE IS IN OVERLAY FORMAT */
#define CDSYSLIB    0x02        /* ... AUTHORIZED LIBRARY MODULE */
#define CDAUTH      0x01        /* ... PROGRAM AUTHORIZATION FLAG */

    unsigned short  CDATTR3;    /* 1E RESERVED */
};
#pragma pack(reset)

#endif
