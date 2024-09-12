#ifndef IEFTIOT_H
#define IEFTIOT_H

typedef struct tiot     TIOT;
typedef struct tiotdd   TIOTDD;

static __inline TIOT *get_tiot(void)
{
    unsigned    *psa        = (unsigned *)0;
    unsigned    *tcb        = (unsigned *)psa[0x21C/4]; /* A(TCB)       */
    TIOT        *tiot       = (TIOT*)tcb[0xC/4];        /* A(TIOT)      */

    return tiot;
}

/* **************************************************************** */
/*            TASK INPUT/OUTPUT TABLE                               */
/*                                                                  */
/*  OS/VS1 RELEASE 4, OS/VS2 RELEASE 3, 09/30/74, LEVEL=1           */
/*                                                                  */
/*  METHOD OF ACCESS                                                */
/*      BAL  - A DSECT CARD SHOULD PRECEDE MACRO CALL.  USING ON    */
/*             TIOT1 GIVES ADDRESSABILITY FOR ALL SYMBOLS.          */
/*      PL/S - DCL TIOTPTR PTR                                      */
/* **************************************************************** */
struct tiot {
/* TIOT1    EQU   * -            TIOTPTR                                        */
    char        TIOCNJOB[8];    /* 00 JOB NAME                                  */
    char        TIOCSTEP[16];   /* 08 FOR A JOB STEP THAT IS NOT A PROCEDURE    */
                                /*    STEP, 8-BYTE JOB STEP NAME AND 8 RESERVED */
                                /*    BYTES.  FOR A JOB STEP THAT IS A          */
                                /*    PROCEDURE STEP, 8-BYTE PROCEDURE STEP     */
                                /*    NAME AND 8-BYTE JOB STEP NAME OF THE JOB  */
                                /*    STEP THAT CALLED THE PROCEDURE.           */
    char        TIOTDD[0];      /* 18 DD Entries                                */
};

/***********************************************************************
/*                                                                     *
/*   DD ENTRY                                                          *
/*                                                                     *
/*        THERE IS A 16-BYTE DD ENTRY FOR EACH DD STATEMENT IN THE     *
/*        JOB STEP OR PROCEDURE STEP.  (REFERENCES TO GDG (ALL) DATA   *
/*        SETS, THE JOBLIB DATA SET OR PGM=*.DDNAME CREATE STILL       *
/*        OTHER DD ENTRIES.)                                           *
/*                                                                     *
/*        A DD ENTRY INCLUDES A DEVICE ENTRY.  BEFORE ALLOCATION,      *
/*        THERE MAY BE SEVERAL DEVICE ENTRIES IN EACH DD ENTRY.        *
/*                                                                     *
/**********************************************************************/
struct tiotdd {
/* TIOENTRY EQU   * -            TIODDPTR                                       */
    char        TIOELNGH;       /* 00 LENGTH, IN BYTES, OF THIS ENTRY           */
                                /*    (INCLUDING ALL DEVICE ENTRIES)            */
    char        TIOESTTA;       /* 01 STATUS BYTE A                             */
#define TIOSLTYP    0x80        /* ... NONSTANDARD LABEL (TAPE) (OS/VS1)        */
                                /*     ENTRY NOT IN USE (OS/VS2)                */
#define TIOSPLTP    0x40        /* ... DURING ALLOCATION, SPLIT CYLINDER        */
                                /*     PRIMARY.  (THIS IS THE FIRST DD ENTRY FOR*/
                                /*     A SPLIT CYLINDER.)                       */
                                /*     DURING STEP TERMINATION, NO UNALLOCATION */
                                /*     NECESSARY.                               */
#define TIOSPLTS    0x20        /* ... DURING ALLOCATION, SPLIT CYLINDER        */
                                /*     SECONDARY.  (THIS IS NOT THE FIRST DD    */
                                /*     ENTRY FOR A SPLIT CYLINDER.)             */
                                /*     DURING STEP TERMINATION, REWIND BUT NO   */
                                /*     UNLOADING.                               */
#define TIOSJBLB    0x10        /* ... JOBLIB INDICATOR                         */
#define TIOSDADS    0x08        /* ... DADSM ALLOCATION NECESSRY                */
#define TIOSLABL    0x04        /* ... LABELED TAPE.  IF BIT 0 IS OFF, SL OR    */
                                /* ... SUL.  IF BIT 0 IS ALSO ON, AL OR AUL.    */
#define TIOSDSP1    0x02        /* ... REWIND/UNLOAD THE TAPE VOLUME (TAPE)     */
                                /*     PRIVATE VOLUME (DIRECT ACCESS)           */
#define TIOSDSP2    0x01        /* ... REWIND THE TAPE VOLUME (TAPE)            */
                                /*     PUBLIC VOLUME (DIRECT ACCESS)            */
/* TIOERLOC DS    0CL2 -         RELATIVE LOCATION OF POOL                      */
    char        TIOEWTCT;       /* 02 DURING ALLOCATION, NUMBER OF DEVICES      */
                                /*    REQUESTED FOR THIS DATA SET               */
    char        TIOELINK;       /* 03 DURING ALLOCATION, LINK TO THE            */
                                /*    APPROPRIATE PRIME SPLIT, UNIT AFFINITY,   */
                                /*    VOLUME AFFINITY OR SUBALLOCATE TIOT       */
                                /*    ENTRY.  AFTER ALLOCATION, FLAG BYTE.      */
#define TIOSYOUT    0x80        /* ... THIS IS A SYSOUT DATA SET THAT CONTAINS  */
                                /*     DATA (AFTER CLOSE)                       */
#define TIOTRV01    0x40        /* ... RESERVED                                 */
#define TIOTTERM    0x20        /* ... DEVICE IS A TERMINAL                     */
#define TIOEDYNM    0x10        /* ... DYNAM CODED ON DD STATEMENT              */
#define TIOEQNAM    0x08        /* ... QNAME CODED ON DD STATEMENT              */
#define TIOESYIN    0x04        /* ... ENTRY FOR SPOOLED SYSIN DATA SET         */
#define TIOESYOT    0x02        /* ... ENTRY FOR SPOOLED SYSOUT DATA SET   VS1  */
#define TIOESSDS    0x02        /* ... ENTRY FOR A SUBSYSTEM DATA SET      VS2  */
#define TIOTREM     0x01        /* ... ENTRY FOR A REMOTE DEVICE                */
    char        TIOEDDNM[8];    /* 04 DD NAME                                   */
    char        TIOEJFCB[3];    /* 0C RELATIVE TRACK ADDRESS (TTR) OF THE JFCB. */
                                /*    (DURING ALLOCATION, TTR OF THE SIOT IF    */
                                /*    SUBALLOCATE WAS REQUESTED.)               */
    char        TIOESTTC;       /* 0F STATUS BYTE C.  USED DURING ALLOCATION    */
                                /*    ONLY.  SET TO ZEROS AT END OF ALLOCATION. */
#define TIOSDKCR    0x80        /* ... MAIN STORAGE OR DASD ADDRESS             */
#define TIOSDEFR    0x40        /* ... DEFERRED MOUNT                           */
#define TIOSAFFP    0x20        /* ... PRIMARY UNIT AFFINITY                    */
#define TIOSAFFS    0x10        /* ... SECONDARY UNIT AFFINITY                  */
#define TIOSVOLP    0x08        /* ... PRIMARY VOLUME AFFINITY                  */
#define TIOSVOLS    0x04        /* ... SECONDARY VOLUME AFFINITY                */
#define TIOSBALP    0x02        /* ... PRIMARY SUBALLOCATE                      */
#define TIOSBALS    0x01        /* ... SECONDARY SUBALLOCATE                    */

/***********************************************************************
/*                                                                     *
/*   DEVICE ENTRIES                                                    *
/*                                                                     *
/*      1. DURING ALLOCATION -                                         *
/*                ONE DEVICE ENTRY FOR EACH DEVICE REQUIRED, OR FOR    *
/*                EACH PUBLIC DEVICE ELIGIBLE.                         *
/*                                                                     *
/*      2. DURING PROBLEM PROGRAM -                                    *
/*                ONE DEVICE ENTRY FOR EACH ALLOCATED DEVICE.          *
/*                                                                     *
/**********************************************************************/
    char        TIOESTTB;       /* 10 STATUS BYTE B - DURING ALLOCATION AND     */
                                /*    DURING PROBLEM PROGRAM                    */
#define TIOSUSED    0x80        /* ... DATA SET IS ON DEVICE                    */
#define TIOSREQD    0x40        /* ... DATA SET WILL USE DEVICE                 */
#define TIOSPVIO    0x20        /* ... DEVICE VIOLATES SEPARATION               */
#define TIOSVLSR    0x10        /* ... VOLUME SERIAL PRESENT                    */
#define TIOSSETU    0x08        /* ... SETUP MESSAGE REQUIRED                   */
#define TIOSMNTD    0x04        /* ... IF 0, DELETE UNLOADED VOLUME IF UNLOAD   */
                                /*     REQUIRED.  IF 1, RETAIN UNLOADED VOLUME  */
                                /*     IF UNLOAD REQUIRED.                      */
#define TIOSUNLD    0x02        /* ... UNLOAD REQUIRED                          */
#define TIOSVERF    0x01        /* ... VERIFICATION REQUIRED                    */

    char        TIOEFSRT[3];    /* 11 DURING PROBLEM PROGRAM, ADDRESS OF UCB.   */
                                /*    DURING ALLOCATION, BITS 0-11 CONTAIN      */
                                /*    OFFSET, IN THE UCB LOOK-UP TABLE, TO AN   */
                                /*    ADDRESS FOR A DEVICE REQUIRED OR ELIGIBLE */
                                /*    FOR THIS DATA SET.  THE UCB LOOK-UP TABLE */
                                /*    HAS ADDRESSES OF UCB'S.  BITS 12-23       */
                                /*    CONTAIN OFFSET, IN THE STEP VOLUME TABLE  */
                                /*    (VOLT), TO THE VOLUME SERIAL NUMBER FOR   */
                                /*    THE VOLUME REQUIRED OR ELIGIBLE FOR THIS  */
                                /*    DATA SET.                                 */
};

/*        TIOT POOL ENTRY */
struct poolstar {
/* POOLSTAR EQU   * */
    char        __1;            /* 00 RESERVED                                  */
    char        TIOPNSLT;       /* 01 NUMBER OF SLOTS FOR POOL                  */
    char        __2;            /* 02 RESERVED                                  */
    char        TIOPNSRT;       /* 03 NUMBER OF DEVICES (FILLED SLOTS)          */
    char        TIOPPOOL[8];    /* 04 POOL NAME                                 */
    char        TIOPSTTB;       /* 0C STATUS OF SLOT                            */
    char        TIOPSLOT[3];    /* 0D UCB ADDRESS OR EMPTY SLOT                 */
    char        TIOTFEND[4];    /* 10 FINAL END OF THE TIOT - BINARY ZEROS      */
};

#endif /* IEFTIOT_H */
