#ifndef HASPJOE_H
#define HASPJOE_H

typedef struct __joe        __JOE;      /* work joe                         */
typedef struct __charjoe    __CHARJOE;  /* characteristics joe              */
typedef struct __ckptjoe    __CKPTJOE;  /* checkpoint joe                   */

/* JES Job Output Element */
struct __joe {
    unsigned short  JOENEXT;    /* 00 OFFSET/4 OF NEXT WORK-JOE             */
    unsigned char   JOETYPE;    /* 02 JOE TYPE                              */
#define _JOEWORK    0x80        /* ... THIS IS A WORK JOE                   */
#define _JOECHAR    0x40        /* ... THIS IS A CHAR JOE                   */
#define _JOECKPT    0x20        /* ... THIS IS A CKPT JOE                   */
#define _JOEFREE    0xE0        /* ... THIS IS A FREE JOE                   */

    unsigned char   __1;        /* 03 RESERVED FOR FUTURE USE               */
    unsigned char   JOEFLAG;    /* 04 PRIMARY JOE                           */
#define _JOECKV     0x80        /* ... CHECKPOINT ELEMENT VALID FLAG        */
#define _JOESPIN    0x40        /* ... SPIN JOE FLAG                        */
#define _JOEPRT     0x20        /* ... JOE ON-PRINTER FLAG                  */
#define _JOEPUN     0x10        /* ... JOE ON-PUNCH FLAG                    */
#define _JOEHOLD    0x08        /* ... HOLD JOE FLAG                        */
#define _JOEBUSY    0x07        /* ... JOE BUSY/SYSTEM ID FLAGS             */

    unsigned char   JOEFLAG2;   /* 05 STATUS FLAGS                          */
#define _JOETCEL    0x80        /* ... TRACK-CELL JOE FLAG                  */
#define _JOEDMND    0x40        /* ... DEMAND-SETUP JOE FLAG                */

    unsigned short  JOECKPT;    /* 06 OFFSET/4 OF CKPT-JOE                  */
    unsigned short  JOECHAR;    /* 08 OFFSET/4 OF CHAR-JOE                  */
    unsigned char   JOESEC;     /* 0A SECURITY LEVEL OF DATA                */
    unsigned char   JOECPU;     /* 0B CPU ID OF DATA                        */
    unsigned short  JOEROUT;    /* 0C REMOTE ID OF DATA                     */
    unsigned short  JOEDEST;    /* 0E DESTINATION CODE FROM PDDB            */
    unsigned short  JOEJQE;     /* 10 OFFSET/4 OF HASP JOB QUE ELEMENT      */
    unsigned char   JOECURCL;   /* 12 CURRENT SYSOUT CLASS                  */
    unsigned char   JOEPDBCL;   /* 13 PDDB'S SYSOUT CLASS                   */
    unsigned int    JOERECCT;   /* 14 TOTAL RECORD COUNT                    */
    unsigned int    JOEIOTTR;   /* 18 SPIN JOE IOT TRACK ADDRESS            */
    unsigned short  __2;        /* 1C RESERVED                              */
    unsigned char   JOEPRIO;    /* 1E JOE PRIORITY (X'00' TO X'0F')         */
    unsigned char   __3;        /* 1F RESERVED                              */
    unsigned short  JOEDEVID;   /* 20 USER DEVICE IDENTIFICATION            */
    unsigned short  JOEJOE;     /* 22 OFFSET/4 OF NEXT JOB WK JOE           */
/* JOE1END  DS    0F               24 END OF WORK-JOE                       */
};
#define JOESIZE sizeof(__JOE)   /* LENGTH OF MAX JOE                        */

/* JES Job Output Element Characteristics */
struct __charjoe {
    unsigned short  JOENEXT;    /* 00 OFFSET/4 OF NEXT WORK-JOE             */
    unsigned char   JOETYPE;    /* 02 JOE TYPE                              */
    unsigned char   __1;        /* 03 RESERVED FOR FUTURE USE               */
    unsigned int    JOEFORM;    /* 04 FORMS NUMBER                          */
    unsigned int    JOEFCB;     /* 08 FCB NUMBER                            */
    unsigned int    JOEUCS;     /* 0C UCS NUMBER                            */
    unsigned char   JOEWTRID[8];/* 10 DATA SET EXTERNAL WRITER NAME         */
    unsigned char   JOEFLASH[4];/* 18 OVERLAY-FRAME                         */
    unsigned char   JOECFLAG;   /* 1C CHARACTERISTICS FLAGS                 */
#define _JOEBRST    0x80        /* ... BURST=YES FLAG                       */
/* JOESETUP EQU   JOEFORM,*-JOEFORM   DEVICE SETUP CHARACTERISTICS          */
    unsigned char   __2;        /* 1D RESERVED                              */
    unsigned char   JOEACTPR;   /* 1E # OF ACTIVE PRINTERS                  */
    unsigned char   JOEACTPU;   /* 1F # OF ACTIVE PUNCHES                   */
    unsigned short  JOEUSE;     /* 20 # OF JOES USING THIS ELEMENT          */
    unsigned short  __3;        /* 22 RESERVED FOR FUTURE USE               */
/* JOE2END  DS    0F               24 END OF CHAR-JOE                       */
};

/* JES Job Output Element Checkpoint */
struct __ckptjoe {
    unsigned short  JOEWORK;    /* 00 OFFSET/4 OF WORK-JOE                  */
    unsigned char   JOETYPE;    /* 02 JOE TYPE                              */
    unsigned char   __1;        /* 03 RESERVED FOR FUTURE USE               */
    unsigned short  JOEJRCB;    /* 04 DISPL INTO EJECT BUFFER               */
    unsigned short  JOEPDDB;    /* 06 CURRENT PDDB OFFSET INTO THE IOT      */
    unsigned int    JOEPPCT;    /* 08 PDDB PAGE COUNT                       */
    unsigned int    JOETLNC;    /* 0C TOTAL JOE LINE COUNT                  */
    unsigned int    JOETPCT;    /* 10 TOTAL JOE PAGE COUNT                  */
    unsigned int    JOEMTTR;    /* 14 LAST EJECT BUFFER TRACK ADDRESS       */
    unsigned char   __2[4];     /* 18 CURRENT IOT TRACK ADDR (JOEIOTTR)     */
    unsigned char   JOECOPY;    /* 1C COPY NUMBER IN PROGRESS               */
    unsigned char   JOEBOFF;    /* 1D BUFFER OFFSET INTO TRAKCELL           */
    unsigned char   JOECPYG;    /* 1E CURRENT OFFSET INTO COPY GROUPS       */
    unsigned char   JOETNDS;    /* 1F TOTAL JOE DATA SET COUNT              */
    unsigned int    JOECRECN;   /* 20 NO. OF RECORDS PRINTED SO FAR         */
};

#endif
