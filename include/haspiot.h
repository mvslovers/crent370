#ifndef HASPIOT_H
#define HASPIOT_H

#include "hasptgm.h"
#include "hasppddb.h"
#include "hasptab.h"

typedef struct __iot        __IOT;      /* JES Input Output Table               */

/* JES Input Output Table               */
struct __iot {
/* IOTDSECT DSECT                     HASP INPUT/OUTPUT TABLE DSECT
         DS    (BUFSTART-BUFDSECT)X     BUFFER CONTROL INFORMATION
IOTSTART EQU   *                   START OF DATA WRITTEN TO SPOOL
*/
    unsigned char   IOTID[4];       /* 00 CL4'IOT'            IOT IDENTIFIER    */
    unsigned short  IOTLENG;        /* 04 LENGTH OF IOT INCLUDING PREFIX        */
    unsigned char   IOTFLAG1;       /* 06 FIRST  FLAG BYTE                      */
#define IOT1CKPT    0x80            /* ... REWRITE THIS IOT                     */
#define IOT1RSV1    0x40            /* ... RESERVED                             */
#define IOT1RSV2    0x20            /* ... RESERVED                             */
#define IOT1SPIN    0x10            /* ... IOT TYPE IS SPINOFF                  */
#define IOT1ALOC    0x08            /* ... IOT IS AN ALLOCATION IOT             */
#define IOT1NTPR    0x04            /* ... TO BE PROC. BY SPIN/HOLD             */
#define IOT1NEWS    0x02            /* ... JESNEWS IOT                          */
#define IOT1RSV7    0x01            /* ... RESERVED                             */

    unsigned char   IOTFLAG2;       /* 07 SECOND FLAG BYTE                      */
#define IOT2RSV0    0x80            /* ... RESERVED                             */
#define IOT2RSV1    0x40            /* ... RESERVED                             */
#define IOT2RSV2    0x20            /* ... RESERVED                             */
#define IOT2RSV3    0x10            /* ... RESERVED                             */
#define IOT2RSV4    0x08            /* ... RESERVED                             */
#define IOT2RSV5    0x04            /* ... RESERVED                             */
#define IOT2RSV6    0x02            /* ... RESERVED                             */
#define IOT2RSV7    0x01            /* ... RESERVED                             */

    unsigned int    IOTJBKEY;       /* 08 JOB IDENTIFIER KEY                    */
    unsigned int    IOTTRACK;       /* 0C TRACK ADDRESS OF THIS IOT             */
    unsigned int    IOTIOTTR;       /* 10 TRACK ADDRESS OF NEXT IOT             */
    unsigned int    IOTIOT;         /* 14 STORAGE ADDRESS OF NEXT IOT           */
    unsigned int    IOTSJB;         /* 18 ADDRESS OF SJB FOR EXECUTING JOB      */
#define IOTJQOFF    IOTSJB          /* 18 SPUN/HELD IOT -- JQE OFFSET           */
    unsigned int    IOTHQT1;        /* 1C TRACK ADDRESS OF 1ST HQT              */
    unsigned int    IOTHQT;         /* 20 TRACK ADDRESS OF NEW HQT              */
    unsigned int    IOTSPIOT;       /* 24 TRACK ADDRESS OF NEXT SPIN IOT        */
    unsigned short  IOTHQRCT;       /* 28 HOLD REQUEST NUMBER                   */
    unsigned short  __1;            /* 2A                                       */
    unsigned int    IOTPDDBP;       /* 2C OFFSET BEYOND LAST PDDB IN IOT        */
    unsigned char   IOTMSTAB[TABLNGTH]; /* 30 MASTER TAB                        */
    unsigned char   __2[4];         /* 3C ALLIGN IOTTGMAP TO DOUBLEWORD         */
    unsigned char   IOTTGMAP[0];    /* 40 START OF TRACK GROUP MAP              */
};

/* OFFSETS FROM 1ST PDDB OF FIXED PDDB'S */
#define IOTPDBOJ    (0*PDBLENG)     /* PDDB FOR INPUT JCL                       */
#define IOTPDBOL    (1*PDBLENG)     /* PDDB FOR HASP JOB LOG                    */
#define IOTPDBOI    (2*PDBLENG)     /* PDDB FOR JCL IMAGES                      */
#define IOTPDBOM    (3*PDBLENG)     /* PDDB FOR SYSTEM MESSAGES                 */
#define IOTPDBOT    (4*PDBLENG)     /* PDDB FOR INTERNAL TEXT                   */
#define IOTPDBON    (5*PDBLENG)     /* PDDB FOR JOB JOURNAL                     */
#define IOTPDBOD    (6*PDBLENG)     /* PDDB FOR 1ST SYSIN/SYSOUT DATASET        */


#endif // CLIBIOT_H
