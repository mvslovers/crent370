#ifndef IEFSSCS_H
#define IEFSSCS_H

#include <iefssobh.h>           /* SSOB Header                              */

#define SSOBCANC    2           /* CANCEL FUNCTION ID (SSOBFUNC)            */
#define SSOBSTAT    3           /* JOB STATUS FUNCTION ID (SSOBFUNC)        */
/*
 *  CANCEL/STATUS RETURN CODES (SSOBRETN)
*/
#define SSCSRTOK    0           /* CANCEL/STATUS COMPLETED                  */
#define SSCSNOJB    4           /* JOB NAME NOT FOUND                       */
#define SSCSBADI    8           /* INVALID JOBNAME/JOB ID COMBINATION       */
#define SSCSNCAN    12          /* JOB NOT CANCELLED - DUPLICATE            */
/*                                 JOBNAMES AND NO JOB ID GIVEN             */
#define SSCSMALL    16          /* STATUS ARRAY TOO SMALL                   */
#define SSCSOUTP    20          /* JOB NOT CANCELLED-JOB ON OUTPUT QUEUE    */
#define SSCSYNTX    24          /* JOBID WITH INVALID SYNTAX FOR            */
/*                                 SYBSYSTEM                                */
#define SSCSICAN    28          /* INVALID CANCEL REQUEST - CANNOT          */
/*                                 CANCEL AN ACTIVE TSO USER OR STARTED     */
/*                                 TASK / TSO USER MAY NOT CANCEL THE       */
/*                                 ABOVE JOBS UNLESS THEY ARE ON AN         */
/*                                 OUTPUT QUEUE.                            */

typedef struct sscs         SSCS;
typedef struct sscsaray     SSCSARAY;

/*  SSCSARAY MAPS AN ELEMENT OF AN ARRAY GOTTEN BY THE CALLER FOR
/*  THE SUBSYSTEM TO RETURN RESULTS IN.  IF MORE THAN ONE ELEMENT
/*  EXISTS, ADDRESSABILITY TO THIS ARRAY MUST BE UPDATED BY THE
/*  ELEMENT SIZE (SSCSELSZ). THE TOTAL ARRAY SPACE USED FOR JOB
/*  STATUS REPLIES FROM THE SUBSYSTEM(ARRAY ELEMENT SIZE IN BYTES
/*  TIMES THE NUMBER OF ELEMENTS) MUST BE INDICATED IN SSCSDIMR.
/*  MESSAGES MUST FOLLOW THE LAST SSCSARAY ELEMENT USED FOR JOB
/*  STATUS.
*/
struct sscsaray {
    unsigned char   SSCSARID[8];/* 00 JOB IDENTIFIER                        */
    unsigned char   SSCSFLG1;   /* 08 FLAGS SET BY SUBSYSTEM                */
#define SSCSJACT    0x80        /* ... JOB IS CURRENTLY ACTIVE (EXECUTING   */
/*                                     AFTER BEING GIVEN CONTROL BY THE     */
/*                                     INITIATOR)                           */
#define SSCSEXCQ    0x40        /* ... JOB IS WAITING FOR EXECUTION (ON A   */
/*                                     PRE-EXECUTION QUEUE)                 */
#define SSCSOUTQ    0x20        /* ... JOB IS ON OUTPUT QUEUE               */
#define SSCSHOLD    0x10        /* ... JOB IS HELD IN ITS CURRENT QUEUE     */
#define SSCSSECL    0x08        /* ... JOB HAS A SECOND LEVEL MESSAGE       */
#define SSCSNJEA    0x04        /* ... JOB ACTIVE IN NJE                    */

    unsigned char   SSCSUJOB;   /* 09 JOBNAME CHARACTER RETURNED            */
/*                                 BY SUBSYSTEM FOR USERID AS JOBNAME       */
    unsigned char   SSCSRSV2[2];/* 0A RESERVED                              */
    void           *SSCSMPTR;   /* 0C POINTER TO MESSAGE RETURNED IN ARRAY  */
/*
/*  THE SECOND LEVEL MESSAGE AREA IS MAPPED BY A MULTI-LEVEL PUTLINE
/*  OUTPUT LINE DESCRIPTOR (OLD).  THE FIRST 9 BYTES OF THE FIRST OR
/*  ONLY MESSAGE SEGMENT ARE RESERVED FOR THE INSERTION OF A MESSAGE
/*  ID BY THE CALLER.  ONE TO 62 BYTES OF MESSAGE TEXT MAY BE PROVIDED
/*  BY THE SUBSYSTEM. A MAPPING OF THE OLD FORMAT NEEDED FOLLOWS.
/*
/*  SSCSMPTR -> ONE TSO PUTLINE OUTPUT LINE DESCRIPTOR (OLD)
/*     +0 0 (NO OTHER OLD)
/*     +4 NUMBER OF MESSAGE SEGMENTS
/*     +8 PTR TO FIRST MESSAGE SEGMENT
/*     +. PTR TO NTH MESSAGE SEGMENT
/*     ........ MESSAGE SEGMENT FORMAT......
/*     +0 TOTAL LENGTH OF MSG SEGMENT (INCLUDING THIS FIELD)
/*     +2 0 IF FIRST SEGMENT, OR OFFSET FOR INSERT IN FIRST
/*     +4 10 BLANKS FOR MSG ID (ONLY IN FIRST SEGMENT)
/*     +D MESSAGE TEXT (1-62 BYTES TOTAL FOR ALL SEGMENTS)
*/
};
#define SSCSELSZ    sizeof(SSCSARAY)

struct sscs {
    unsigned short  SSCSLEN;    /* 00 CANCEL/STATUS EXTENSION LENGTH        */
    unsigned char   SSCSFLGS;   /* 02 USER SELECTION FLAGS                  */
#define SSCSUSID    0x80        /* ... USERID IS IN JOBNAME FIELD           */
#define SSCSCOUT    0x40        /* ... CANCEL THE JOBS OUTPUT               */

    unsigned char   SSCSULEN;   /* 03 USERID LENGTH                         */
    unsigned char   SSCSJOBN[8];/* 04 JOB NAME                              */
    unsigned char   SSCSJOBI[8];/* 0C JOB ID OR BLANKS                      */
    unsigned short  SSCSDIMP;   /* 14 SET BY CALLER TO INDICATE SIZE        */
/*                                 OF ARRAY AVAILABLE TO SUBSYSTEM          */
/*                                 TO STORE RESULTS IN                      */
    unsigned short  SSCSDIMR;   /* 16 SET BY SUBSYSTEM TO INDICATE SIZE     */
/*                                 OF ARRAY USED, OR NEEDED IF NOT          */
/*                                 ENOUGH IS AVAILABLE                      */
    SSCSARAY        SSCSARAY[1];/* 18 array area start                      */
};
#define SSCSIZE     sizeof(SSCS)
#define SSOBLEN2    (SSOBHSIZ+SSCSIZE)

#endif
