#ifndef OSDEB_H
#define OSDEB_H

typedef struct deb      DEB;        /* DATA EXTENT BLOCK                    */
typedef struct debavt   DEBAVT;     /* APPENDAGE VECTOR TABLE               */
typedef struct debprfx  DEBPRFX;    /* PREFIX TABLE                         */
typedef struct debbasic DEBBASIC;   /* BASIC SECTION                        */
typedef struct debdasd  DEBDASD;    /* DIRECT-ACCESS STORAGE DEVICE         */
typedef struct debacsmd DEBACSMD;   /* EXCP ACCESS METHOD, BSAM AND QSAM    */
typedef struct debsubnm DEBSUBNM;   /* SUBROUTINE NAME                      */
typedef struct debxtn   DEBXTN;     /* DEB EXTENSION (OS/VS2)               */
typedef struct debdds1  DEBDDS1;    /* UNIT RECORD, MAGNETIC TAPE, ...      */
typedef struct debisam  DEBISAM;    /* DEB ISAM DEPENDENT SECTION           */

/* **************************************************************** */
/*                                                                  */
/*            ***** DATA EXTENT BLOCK *****                         */
/*                                                                  */
/*  OS/VS2 RELEASE 3.0 AND 3.7 PTF, 12/20/77, LEVEL=2       @ZA34098*/
/*                                                                  */
/*  METHOD OF ACCESS                                                */
/*      PL/S - DCL (DEBPTR,DEBDAPTR,DEBEXPTR,DEBSBPTR) PTR          */
/*      BAL  - FIVE DSECTS ARE PRODUCED.  USING ON A DSECT NAME     */
/*             GIVES ADDRESSABILITY FOR ALL SYMBOLS WITHIN THAT     */
/*             DSECT.  THE DSECT NAMES AND THE SECTIONS WITHIN EACH */
/*             DSECT ARE                                            */
/*                                                                  */
/*             DEB ***  APPENDAGE VECTOR TABLE SECTION              */
/*                      PREFIX TABLE                                */
/*                      BASIC SECTION                               */
/*                      UNIT RECORD, MAGNETIC TAPE AND              */
/*                        TELECOMMUNICATIONS DEVICES SECTION        */
/*                      3540 ACCESS METHOD DEPENDENT SECTN  @X04AA9A*/
/*                      ISAM DEPENDENT SECTION                      */
/*                      *** POINTERS TO THE DEB IN OTHER CONTROL    */
/*                          BLOCKS SUCH AS DCB POINT TO THE BASIC   */
/*                          SECTION.  USING ON DEBBASIC GIVES       */
/*                          ADDRESSABILITY FOR BASIC SECTION AND    */
/*                          NEXT TWO SECTIONS.  DEBAPPAD IN BASIC   */
/*                          SECTION CONTAINS ADDRESS OF APPENDAGE   */
/*                          VECTOR TABLE (AVT) SECTION.  PREFIX     */
/*                          FOLLOWS AVT SECTION.                    */
/*             DEBDASD  DIRECT ACCESS STORAGE DEVICE SECTION        */
/*             DEBACSMD EXCP, BSAM AND QSAM DEPENDENT SECTION       */
/*                      BPAM DEPENDENT SECTION                      */
/*                      BDAM DEPENDENT SECTION                      */
/*                      BTAM DEPENDENT SECTION                      */
/*                      GAM DEPENDENT SECTION                       */
/*                      ISAM LOAD MODE EXTENSION **                 */
/*                      ISAM SCAN MODE EXTENSION **                 */
/*                      BISAM MODE EXTENSION **                     */
/*                      ** FOR THESE 3 EXTENSIONS, LOAD REGISTER    */
/*                         FROM DEBEXPT IN ISAM DEPENDENT SECTION   */
/*                         TO SET REGISTER FOR USING.               */
/*             DEBSUBNM SUBROUTINE NAME SECTION                     */
/*             DEBXTN   EXTENSION FOR OS/VS2                        */
/*                                                                  */
/*             WHEN LISTING IS SUPPRESSED, YOU CAN DETERMINE WHICH  */
/*             DSECT A SYMBOL IS IN BY USING THE STATEMENT NUMBER   */
/*             IN THE DEFN COLUMN IN THE CROSS REFERENCE LISTING.   */
/*             FOR EXAMPLE, ANY SYMBOL DEFINED BETWEEN THE          */
/*             STATEMENT NUMBERS FOR DEBDASD AND DEBACSMD IS IN     */
/*             THE DIRECT ACCESS STORAGE DEVICE SECTION.            */
/*                                                                  */
/*  F.E.'S                                                          */
/*      MICROFICHE LISTING - IEZDEB                                 */
/*                                                                  */
/*  DEVELOPERS                                                      */
/*      BAL LISTING  - SPECIFY LIST=YES ON MACRO CALL               */
/*      PL/S LISTING - SPECIFY %IHALIST='YES' BEFORE INCLUDE        */
/*                                                                  */
/*      FOR INTEGRATION, A LISTING SHOULD NOT BE REQUESTED.         */
/*                                                                  */
/*  FUNCTION                                                        */
/*      THE DATA EXTENT BLOCK (DEB) CONTAINS AN EXTENSION OF        */
/*      INFORMATION IN THE DCB.  EACH DEB IS ASSOCIATED WITH A      */
/*      DCB, AND THE TWO POINT TO EACH OTHER.  THE DEB CONTAINS     */
/*      INFORMATION CONCERNING THE PHYSICAL CHARACTERISTICS OF      */
/*      THE DATA SET AND OTHER INFORMATION THAT IS USED BY THE      */
/*      CONTROL PROGRAM.                                            */
/*                                                                  */
/* **************************************************************** */

/**********************************************************************
 *            APPENDAGE VECTOR TABLE SECTION OF THE DEB               *
 *              POINTED TO BY DEBAPPAD                                *
 **********************************************************************/
#pragma pack(1)
struct debavt {
    union {
        void        *debeoea;       /* 00 ADDRESS OF END-OF-EXTENT
                                          APPENDAGE ROUTINE                 */
        struct {
            char    debeoeab;       /* 00 FLAG BYTE                         */
#define debtcamq    debeoeab        /* 00 TCAM USES AS WORK AREA (BITS 0-3) */
#define DEBEOENP    0x0F            /* ... NUMBER OF 2K PAGES TO BE FIXED
                                           FOR THE END-OF-EXTENT APPENDAGE  */
            char    debeoead[3];    /* 01 ADDRESS OF END-OF-EXTENT
                                          APPENDAGE ROUTINE                 */
        };
    };

    union {
        void        *debsioa;       /* 04 ADDRESS OF START I/O APPENDAGE
                                          ROUTINE                           */
        struct {
            char    debsioab;       /* 04 FLAG BYTE                         */
#define DEBPGFX     0x80            /* ... ADDRESS IN DEBSIOAD CAN BE USED
                                           TO DETERMINE THE ENTRY POINT TO
                                           THE PAGE FIX (PGFX) APPENDAGE
                                           ROUTINE BY ADDING 4 TO THE
                                           ADDRESS IN DEBSIOAD              */
#define DEBSIOX     0x40            /* ... IF ZERO, DO NOT ENTER SIO
                                           APPENDAGE WHEN ERP IS ACTIVE.
                                           IF ONE, ENTER SIO APPENDAGE EVEN
                                           WHEN ERP IS ACTIVE.              */
#define DEBIOVR     0x20            /* ... IF ONE, EXCPVR REQUEST IS VALID.
                                           IF ZERO, EXCPVR REQUEST IS INVALID
                                           AND WILL NOT BE EXECUTED.        */
#define DEBFIX      0x10            /* ... INDICATION THAT DEB HAS BEEN
                                           FIXED (OS/VS2)                   */
#define DEBSIONP    0x0F            /* ... NUMBER OF 2K PAGES TO BE FIXED
                                           FOR THE SIO APPENDAGE            */
            char    debsioad[3];    /* 05 ADDRESS OF START I/O APPENDAGE
                                          ROUTINE                           */
        };
    };

    union {
        void        *debpcia;       /* 08 ADDRESS OF PCI APPENDAGE ROUTINE  */
        struct {
            char    debpciab;       /* 08 FLAG BYTE                         */
#define DEBRSV24    0x80            /* ... RESERVED                         */
#define DEBRSV25    0x40            /* ... RESERVED                         */
#define DEBRSV26    0x20            /* ... RESERVED                         */
#define DEBRSV27    0x10            /* ... RESERVED                         */
#define DEBPCINP    0x0F            /* ... NUMBER OF 2K PAGES TO BE FIXED
                                           FOR THE PCI APPENDAGE            */
            char    debpicad[3];    /* 09 ADDRESS OF PROGRAM-CONTROLLED-
                                          INTERRUPTION (PCI) APPENDAGE
                                          ROUTINE                           */
        };
    };

    union {
        void        *debcea;        /* 0C ADDRESS OF CHANNEL-END APPENDAGE
                                          ROUTINE                           */
        struct {
            char    debceab;        /* 0C FLAG BYTE                         */
#define DEBESMVR    0x80            /* ... VALIDITY CHECK FOR EXCPVR CALLER */
#define DEBRSV29    0x40            /* ... RESERVED                         */
#define DEBRSV30    0x20            /* ... RESERVED                         */
#define DEBRSV31    0x10            /* ... RESERVED                         */
#define DEBCENP     0x0F            /* ... NUMBER OF 2K PAGES TO BE FIXED
                                           FOR THE CHANNEL-END APPENDAGE    */
            char    debcead[3];     /* 0D ADDRESS OF CHANNEL-END APPENDAGE
                                          ROUTINE                           */
        };
    };

    union {
        void        *debxcea;       /* 10 ADDRESS OF ABNORMAL-END APPENDAGE
                                          ROUTINE                           */
        struct {
            char    debxcean;       /* 10 FLAG BYTE                         */
#define DEBRSV32    0x80            /* ... RESERVED                         */
#define DEBRSV33    0x40            /* ... RESERVED                         */
#define DEBRSV34    0x20            /* ... RESERVED                         */
#define DEBRSV35    0x10            /* ... RESERVED                         */
#define DEBXCENP    0x0F            /* ... NUMBER OF 2K PAGES TO BE FIXED
                                           FOR THE ABNORMAL-END APPENDAGE   */
            char    debxcead[3];    /* 11 ADDRESS OF ABNORMAL-END APPENDAGE
                                          ROUTINE                           */
        };
    };
};
#pragma pack(reset)

/**********************************************************************
 *                    DEB PREFIX TABLE                                *
 **********************************************************************/
#pragma pack(1)
struct debprfx {
    union {
        void        *debwkara;      /* 00 I/O SUPPORT WORK AREA
                                          (DIRECT ACCESS)                   */
        struct {
            char    unused01;
            char    debdscba[7];    /* 01 DSCB ADDRESS (BBCCHHR) USED BY
                                          I/O SUPPORT (DIRECT ACCESS)       */
        };
    };

    union {
        void        *debxtnp;       /* 08 POINTER TO DEB EXTENSION (OS/VS2) */
        char        debdcbmk[4];    /* 08 DCB MODIFICATION MASK USED BY
                                          I/O SUPPORT (OS/VS1)              */
    };

    char            deblngth;       /* 0C LENGTH OF DEB IN DOUBLE WORDS     */
    char            debamtyp;       /* 0D ACCESS METHOD TYPE                */
#define DEBAMNON        0x00        /* ... ACCESS METHOD TYPE NOT KNOWN     */
#define DEBAMVSM        0x01        /* ... VSAM ACCESS METHOD TYPE          */
#define DEBAMXCP        0x02        /* ... EXCP ACCESS METHOD TYPE          */
#define DEBAMTCM        0x04        /* ... TCAM ACCESS METHOD TYPE          */
#define DEBAMGAM        0x08        /* ... GRAPHICS ACCESS METHOD TYPE      */
#define DEBAMTAM        0x10        /* ... BTAM ACCESS METHOD TYPE          */
#define DEBAMBPM        0x20        /* ... BPAM ACCESS METHOD TYPE          */
#define DEBAMSAM        0x20        /* ... SEQUENTIAL ACCESS METHOD TYPE    */
#define DEBAMBDM        0x40        /* ... DIRECT ACCESS METHOD TYPE        */
#define DEBAMISM        0x80        /* ... ISAM ACCESS METHOD TYPE          */
#define DEBAMSUB        0x81        /* ... SUBSYSTEM ACCESS METHOD TYPE     */
#define DEBAMVTM        0x82        /* ... VTAM® ACCESS METHOD TYPE         */
#define DEBAMTAP        0x84        /* ... TCAM APPLICATION ACC METHOD TYPE */

    short           debtblof;       /* 0E2 OFFSET IN THE DEB TABLE TO THE
                                          ENTRY FOR THIS DEB                */
};
#pragma pack(reset)

/***********************************************************************
 *                     DEB BASIC SECTION                               *
 ***********************************************************************/
#pragma pack(1)
struct debbasic {
    union {
        void        *debtcbad;      /* 00 ADDRESS OF TCB FOR THIS DEB       */
        struct {
            char    debamid;        /* 00 VTAM/TCAM DEB ID FLAG             */
#define DEBTAMID    0x00            /* ... TCAM DEB ID                      */
#define DEBVAMID    0x0F            /* ... VTAM DEB ID                      */
#define debnmsub    debamid         /* 00 NUMBER OF SUBROUTINES LOADED BY
                                          OPEN EXECUTOR ROUTINES            */
            char    debtcbb;        /* 01 ADDRESS OF TCB FOR THIS DEB       */
            char    unused02[2];
        };
    };

    union {
        void        *debdebad;      /* 04 ADDRESS OF THE NEXT DEB IN THE
                                          SAME TASK                         */
        struct {
            char    debamlng;       /* 04 NUMBER OF BYTES IN THE ACCESS
                                          METHOD DEPENDENT SECTION.
                                          FOR BDAM THIS FIELD CONTAINS THE
                                          LENGTH EXPRESSED IN NUMBER OF
                                          WORDS.                            */
            char    debdebb[3];     /* 05 ADDRESS OF THE NEXT DEB IN THE
                                          SAME TASK                         */
        };
    };

    union {
        void        *debirbad;      /* 08 IRB STORAGE ADDRESS USED FOR
                                          APPENDAGE ASYNCHRONOUS EXITS      */
        struct {
            char    deboflgs;       /* 08 DATA SET STATUS FLAGS             */
#define DEBDISP     0xC0            /* ... DATA SET DISPOSITION FLAGS
                                             BIT SETTING  DISPOSITION
                                      DEBDSOLD  01        OLD DATA SET
                                      DEBDSMOD  10        MOD DATA SET
                                      DEBDSNEW  11        NEW DATA SET      */
#define DEBEOF      0x20            /* ... END-OF-FILE (EOF) ENCOUNTERED
                                           (TAPE INPUT)
                                           FORMAT 1 DSCB BIT 93.0 INDICATES
                                           THAT THE CURRENT VOLUME IS THE LAST
                                           VOLUME OF THE DATA SET
                                           (DASD INPUT)                     */
#define DEBRLSE     0x10            /* ... RELEASE UNUSED EXTERNAL STORAGE
                                           (DASD)
                                           EMULATOR TAPE WITH SECOND GENERATION
                                           FORMAT. TAPE MAY CONTAIN BLOCKS
                                           SHORTER THAN 12 CHARACTERS.
                                           (TAPE)                           */
#define DEBDCB      0x08            /* ... DCB MODIFICATION                 */
#define DEBSPLIT    0x04            /* ... SPLIT CYLINDER (DASD)
                                           7-TRACK EMULATOR TAPE WITH POSSIBLE
                                           MIXED PARITY RECORDS (TAPE)      */
#define DEBLABEL    0x02            /* ... NONSTANDARD LABELS               */
#define DEBRERR     0x01            /* ... USE REDUCED ERROR RECOVERY PROCEDURE
                                           (TAPE)
                                           CONCATENATED PARTITIONED ORGANIZATION
                                           DATA SETS PROCESSED USING BPAM
                                           (DASD)                           */
            char    debirbb[3];     /* 09/2D IRB STORAGE ADDRESS USED FOR
                                          APPENDAGE ASYNCHRONOUS EXITS      */
        };
    };


    char            debopatb;       /* 0C FLAGS INDICATING BOTH THE METHOD OF
                                          I/O PROCESSING AND THE DISPOSITION
                                          THAT IS TO BE PERFORMED WHEN AN
                                          END-OF-VOLUME (EOV) CONDITION
                                          OCCURS                            */
#define DEBABEND    0x80            /* ... SET BY ABEND INDICATING A SYSABEND
                                           OR SYSUDUMP DATA SET (OS/VS2)    */
#define DEBZERO     0x40            /* ... ALWAYS ZERO                      */
#define DEBPOSIT    0x30            /* ... DATA SET POSITIONING FLAGS
                                                    BIT SETTING    POSITIONING
                                           DEBRERED 01             REREAD
                                           DEBLEAVE 11             LEAVE    */
#define DEBACCS     0x0F            /* ... TYPE OF I/O ACCESSING BEING DONE
                                                      BIT SETTING  ACCESSING
                                           DEBINPUT     0000         INPUT
                                           DEBOUTPT     1111         OUTPUT
                                           DEBINOUT     0011         INOUT
                                           DEBOUTIN     0111         OUTIN
                                           DEBRDBCK     0001         RDBACK
                                           DEBUPDAT     0100         UPDAT  */
    char            debqscnt;       /* 0D PURGE (SVC 16) - QUIESCE COUNT.
                                          NUMBER OF DEVICES EXECUTING USER'S
                                          CHANNEL PROGRAMS, AS SHOWN BY BITS
                                          5 AND 6 OF UCBFL1 FIELDS.         */
    char            debflgs1;       /* 0E FLAG FIELD                        */
#define DEBPWCKD    0x80            /* ... PASSWORD WAS SUPPLIED DURING OPEN.
                                           EOV WILL NOT REQUEST A PASSWORD
                                           FOR EACH ADDITIONAL VOLUME OF A
                                           MULTIVOLUME DATA SET.            */
#define DEBEOFDF    0x40            /* ... SET BY EOV TO INFORM CLOSE THAT
                                           AN END-OF-FILE HAS BEEN ENCOUNTERED
                                           AND, THEREFORE, DEFERRED USER LABEL
                                           PROCESSING IS ALLOWED.           */
#define DEBRSIOA    0x20            /* ... SIO APPENDAGE RE-ENTRY AUTHORIZATION
                                           BIT (OS/VS1)                     */
#define DEBEXCPA    0x10            /* ... EXCP IS AUTHORIZED FOR THIS DEB  */
#define DEBCINDI    0x08            /* ... DCB ASSOCIATED WITH THIS DEB IS
                                           BEING PROCESSED BY THE COMPATIBILITY
                                           INTERFACE ROUTINES (VSAM)        */
#define DEBF1CEV    0x04            /* ... EOV PROCESSING OCCURRED DURING
                                           CLOSE PROCESSING. TESTED AND SET
                                           TO ZERO BY CLOSE, SET TO ONE BY
                                           EOV.                             */
#define DEBAPFIN    0x02            /* ... IF ON, AUTHORIZED PROGRAMS CAN BE
                                           LOADED                           */
#define DEBXTNIN    0x01            /* ... IF ONE, DEB EXTENSION EXISTS
                                           (OS/VS2)                         */
    char            debrsv05;       /* 0F RESERVED                          */

    union {
        void        *debusrpg;      /* 10 ADDRESS OF FIRST IOB IN THE USER
                                          PURGE CHAIN (OS/VS1)
                                          ADDRESS OF PURGED I/O RESTORE LIST
                                          (PIRL) (OS/VS2)                   */
        struct {
            char    debnmext;       /* 10 NUMBER OF EXTENTS SPECIFIED IN
                                          DSCB'S                            */
            char    debusrpb[3];    /* 11 ADDRESS OF FIRST IOB IN THE USER
                                          PURGE CHAIN (OS/VS1)
                                          ADDRESS OF PURGED I/O RESTORE LIST
                                          (PIRL) (OS/VS2)                   */
        };
    };

    union {
        void        *debrrq;        /* 14 POINTER TO RELATED REQUEST QUEUE
                                          (OS/VS2)                          */
        void        *debecbad;      /* 14 ADDRESS OF A PARAMETER LIST USED
                                          TO LOCATE THE PURGE ECB FOR AN
                                          SVC PURGE REQUEST (OS/VS1)        */
        struct {
            char    debprior;       /* 14 PRIORITY OF THE TASK OWNING DEB   */
            char    debecbb[3];     /* 15 ADDRESS OF A PARAMETER LIST USED
                                          TO LOCATE THE PURGE ECB FOR AN
                                          SVC PURGE REQUEST (OS/VS1)        */
        };
    };

    union {
        void        *debdcbad;      /* 18 ADDRESS OF DCB ASSOCIATED WITH
                                          THIS DEB                          */
        struct {
            union {
              char  debprotg;       /* 18 TASK PROTECTION KEY IN HIGH-ORDER
                                          4 BITS                            */
              char  debdebid;       /* 18 A HEX F IN LOW-ORDER 4 BITS TO
                                          IDENTIFY THIS BLOCK AS A DEB      */
            };
            char    debdcbb[3];     /* 19 ADDRESS OF DCB ASSOCIATED WITH
                                          THIS DEB                          */
        };
    };

    union {
        void        *debappad;      /* 1C ADDRESS OF THE I/O APPENDAGE
                                          VECTOR TABLE                      */
        struct {
            char    debexscl;       /* 1C EXTENT SCALE - 4 FOR DIRECT ACCESS
                                          DEVICE AND 3525 CARD PUNCH WITH
                                          DEVICE-ASSOCIATED DATA SET SUPPORT
                                          AND 2 FOR NONDIRECT ACCESS DEVICE
                                          AND COMMUNICATION DEVICE.
                                          THIS FIELD IS USED TO DETERMINE
                                          THE SIZE OF THE DEVICE DEPENDENT
                                          SECTION                           */
            char    debappb[3];     /* 1D ADDRESS OF THE I/O APPENDAGE
                                          VECTOR TABLE                      */
        };
    };
};
#pragma pack(reset)

/***********************************************************************
 *      UNIT RECORD, MAGNETIC TAPE, TELECOMMUNICATIONS DEVICES SECTION *
 *                                                                     *
 *        NOTE  FOR TELECOMMUNICATIONS DEVICES, THE UCB ADDRESS IS     *
 *              REPEATED FOR EACH LINE ASSIGNED                        *
 ***********************************************************************/
#pragma pack(1)
struct debdds1 {
    union {
        void        *debsucba;      /* 00 ADDRESS OF A UCB ASSOCIATED WITH
                                          A GIVEN DATA SET                  */
        struct {
            char    debsdvm;        /* 00 DEVICE MODIFIER.
                                          FOR MAGNETIC TAPE, SET MODE
                                          OPERATION CODE.
                                          FOR UNIT RECORD, NOT USED.        */
            char    debsucbb[3];    /* 01 ADDRESS OF A UCB ASSOCIATED WITH
                                          A GIVEN DATA SET                  */
        };
    };

    union {
        char        debdeved[4];    /* 04 END OF COMMON UNIT RECORD FIELDS  */
    /*
     *        THE FOLLOWING FIELDS ARE PRESENT ONLY FOR THE 3525 WITH
     *        DEVICE-ASSOCIATED DATA SET SUPPORT                            */
        void        *debrdcb;       /* 04 ADDRESS OF DCB FOR THE READ
                                          ASSOCIATED DATA SET               */
        struct {
            char    unused04;
            char    debrdcba[3];    /* 05 ADDRESS OF DCB FOR THE READ
                                          ASSOCIATED DATA SET               */
        };
    };

    union {
        void        *debpdcb;       /* 08 ADDRESS OF DCB FOR THE PUNCH
                                          ASSOCIATED DATA SET               */
        struct {
            char    unused08;
            char    debpdcba[3];    /* 09 ADDRESS OF DCB FOR THE PUNCH
                                          ASSOCIATED DATA SET               */
        };
    };

    union {
        void        *debwdcb;       /* 0C ADDRESS OF DCB FOR THE PRINT
                                          ASSOCIATED DATA SET               */
        struct {
            char    unused0C;
            char    debwdcba[3];    /* 0D ADDRESS OF DCB FOR THE PRINT
                                          ASSOCIATED DATA SET               */
        };
    };

/***********************************************************************
 *                   3540 ACCESS METHOD DEPENDENT SECTION      @X04AA9A*
 *                   (OS/VS1 ONLY)                             @X04AA9A*
 *                                                                     *
 *        NOTE  THIS SECTION FOLLOWS DEBSUCBA IN UNIT RECORD, MAGNETIC *
 *              TAPE, TELECOMMUNICATIONS DEVICES SECTION IF DEB IS     *
 *              FOR 3540 DEVICE.                               @X04AA9A*
 ***********************************************************************/
#define debasc09    debdeved        /* 04 3540 ACCESS METHOD DEPENDENT
                                          SECTION                           */
#define debvolac    debdeved[0]     /* 04 VOLUME ACCESSABILITY INDICATOR    */
#define debdssql    debdeved[1]     /* 05 DATA SET SECURITY QUALIFIER       */
#define debvsequ    debdeved[2]     /* 06 VOLUME SEQUENCE NUMBER            */
#define debeamfg    debdeved[3]     /* 07 FLAG BYTE                         */
#define DEBMULTI    0x80            /* ... MULTI-VOLUME INDICATOR           */
#define DEBDSOPN    0x40            /* ... DATA SET IS OPEN                 */
#define DEBVAMSG    0x20            /* ... VOLUME ACCESSABILITY MESSAGE HAS
                                           BEEN ISSUED                      */
#define DEBSECVL    0x10            /* ... SECURE VOLUME                    */
#define DEBRV004    0x08            /* ... RESERVED                         */
#define DEBRV005    0x04            /* ... RESERVED                         */
#define DEBRV006    0x02            /* ... RESERVED                         */
#define DEBRV007    0x01            /* ... RESERVED                         */

#define debdsid     debpdcb         /* 08 DATA SET IDENTIFIER (DSID) (INPUT)*/
#define debexdte    debpdcb         /* 08 EXPIRATION DATE (OUTPUT)          */
#define debwtpti    debwdcb         /* 0E WRITE PROTECT INDICATOR (OUTPUT)  */

    union {
        void        *debeod;        /* 10 END OF DATA (EOD) ADDRESS (INPUT) */
        void        *debboe;        /* 10 BEGINNING OF EXTENT (BOE) ADDRESS */
        struct {
            char    unused10;
            union {
              char  debeodtt;       /* 11 EOD TRACK NUMBER                  */
              char  debboett;       /* 11 BOE TRACK NUMBER                  */
            };
            union {
              char  debeod0;        /* 12 MUST BE ZERO                      */
              char  debboe0;        /* 12 MUST BE ZERO                      */
            };
            union {
              char  debeodss;       /* 13 EOD SECTOR NUMBER                 */
              char  debboess;       /* 13 BOE SECTOR NUMBER                 */
            };
        };
    };
};
#pragma pack(reset)

/***********************************************************************
 *                DEB ISAM DEPENDENT SECTION                           *
 *                                                                     *
 *        NOTE  PRESENT ONLY IF ISAM IS USED.  FOLLOWS THE BASIC       *
 *              SECTION AND PRECEDES THE DIRECT ACCESS STORAGE DEVICE  *
 *              SECTION.  COUNTED AS ONE EXTENT IN DEBNMEXT.           *
 ***********************************************************************/
#pragma pack(1)
struct debisam {
    union {
        void        *debfiead;      /* 00 ADDRESS OF FIRST INDEX EXTENT     */
        struct {
            char    debniee;        /* 00 NUMBER OF EXTENTS OF INDEPENDENT
                                          INDEX AREA                        */
            char    debfieb[3];     /* 01 ADDRESS OF FIRST INDEX EXTENT     */
        };
    };

    union {
        void        *debfpead;      /* 04 ADDRESS OF THE FIRST PRIME DATA
                                          EXTENT                            */
        struct {
            char    debnpee;        /* 04 NUMBER OF EXTENTS OF PRIME DATA
                                          AREA (M=0 EXTENT)                 */
            char    debfpeb[3];     /* 05 ADDRESS OF THE FIRST PRIME DATA
                                          EXTENT                            */
        };
    };

    union {
        void        *debfoead;      /* 08 ADDRESS OF THE FIRST OVERFLOW
                                          EXTENT                            */
        struct {
            char    debnoee;        /* 08 NUMBER OF EXTENTS OF INDEPENDENT
                                          OVERFLOW AREA                     */
            char    debfoeb[3];     /* 09 ADDRESS OF THE FIRST OVERFLOW
                                          EXTENT                            */
        };
    };

    union {
        void        *debexpt;       /* 0C ADDRESS OF ISAM DEB EXTENSION     */
        struct {
            char    debrpsid;       /* 0C ROTATIONAL POSITION SENSING (RPS)
                                          DEVICE INDICATORS                 */
#define DEBRPSP     0x80            /* ... PRIME DATA AREA IS ON RPS DEVICE */
#define DEBRPSI     0x40            /* ... INDEPENDENT INDEX AREA IS ON RPS
                                           DEVICE                           */
#define DEBRPSO     0x20            /* ... INDEPENDENT OVERFLOW AREA IS ON
                                           RPS DEVICE                       */
#define DEBRPSAP    0x10            /* ... RPS SIO APPENDAGE HAS BEEN LOADED*/
#define DEBRSV09    0x08            /* ... RESERVED                         */
#define DEBRSV10    0x04            /* ... RESERVED                         */
#define DEBRSV11    0x02            /* ... RESERVED                         */
#define DEBRSV12    0x01            /* ... RESERVED                         */
            char    debexpta[3];    /* 0D ADDRESS OF ISAM DEB EXTENSION     */
        };
    };
};
#pragma pack(reset)

/***********************************************************************
 *             DIRECT-ACCESS STORAGE DEVICE SECTION                    *
 *                                                                     *
 *        NOTE  IF ISAM IS BEING USED, THIS SECTION FOLLOWS THE ISAM   *
 *              DEVICE DEPENDENT SECTION.  OTHERWISE, IT FOLLOWS THE   *
 *              BASIC SECTION.                                         *
 *                                                                     *
 *              THERE IS ONE OF THESE SECTIONS FOR EACH EXTENT.        *
 ***********************************************************************/
#pragma pack(1)
struct debdasd {
    union {
        void        *debucbad;      /* 00 ADDRESS OF UCB ASSOCIATED WITH
                                          THIS DATA EXTENT                  */
        struct {
            char    debdvmod;       /* 00 DEVICE MODIFIER - FILE MASK       */
            char    debucba[3];     /* 01 ADDRESS OF UCB ASSOCIATED WITH
                                          THIS DATA EXTENT                  */
        };
    };

    unsigned short  debbinum;       /* 04 BIN NUMBER                        */
    unsigned short  debstrcc;       /* 06 CYLINDER ADDRESS FOR THE START OF
                                          AN EXTENT LIMIT                   */
    unsigned short  debstrhh;       /* 08 READ/WRITE TRACK ADDRESS FOR THE
                                          START OF AN EXTENT LIMIT          */
    unsigned short  debendcc;       /* 0A CYLINDER ADDRESS FOR THE END OF
                                          AN EXTENT LIMIT                   */
    unsigned short  debendhh;       /* 0C READ/WRITE TRACK ADDRESS FOR THE
                                          END OF AN EXTENT LIMIT            */
    unsigned short  debnmtrk;       /* 0E NUMBER OF TRACKS ALLOCATED TO A
                                          GIVEN EXTENT.
                                          FOR SPLIT CYLINDER DATA SETS,
                                          THIS FIELD REPRESENTS THE NUMBER
                                          OF TRACKS BETWEEN THE START ADDRESS
                                          OF THE EXTENT AND THE END ADDRESS
                                          OF THE EXTENT.                    */
};
#pragma pack(reset)

/***********************************************************************
 *        EXCP ACCESS METHOD, BSAM AND QSAM DEPENDENT SECTION          *
 ***********************************************************************/
#pragma pack(1)
struct debacsmd {
    union {
        unsigned short  debvolsq;   /* 00 VOLUME SEQUENCE NUMBER FOR
                                          MULTIVOLUME SEQUENTIAL DATA SETS  */
        struct {
            char    debvolbt;       /* 00 FIRST BYTE OF DEBVOLSQ            */
#define DEBEXFUL    0x80            /* ... SET BY EOV WHEN REWRITING AN OLD
                                           DIRECT ACCESS DATA SET TO INDICATE
                                           THAT ALL PREVIOUS EXISTING EXTENTS
                                           HAVE BEEN FILLED                 */
            char    debvlseq;       /* 01 FOR DIRECT ACCESS, SEQUENCE NUMBER
                                          OF THE VOLUME OF THE DATA SET
                                          RELATIVE TO THE FIRST VOLUME OF
                                          THE DATA SET.
                                          FOR TAPE, SEQUENCE NUMBER OF THE
                                          VOLUME OF THE DATA SET RELATIVE
                                          TO THE FIRST VOLUME PROCESSED.    */
        };
    };

    unsigned short  debvolnm;       /* 02 TOTAL NUMBER OF VOLUMES IN A
                                          MULTIVOLUME SEQUENTIAL DATA SET.  */
    char    debdsnm[8];             /* 04 MEMBER NAME.  THIS FIELD APPEARS
                                          ONLY WHEN AN OUTPUT DATA SET HAS
                                          BEEN OPENED FOR A MEMBER NAME AND
                                          THE DSCB SPECIFIES A PARTITIONED
                                          DATA SET.                         */
#define debutsaa    debdsnm         /* 04 ADDRESS OF THE USER TOTALING
                                          SAVE AREA                         */
#define debutsab    debdsnm[1]      /* 05 ADDRESS OF THE USER TOTALING
                                          SAVE AREA                         */

    unsigned short  debblksi;       /* 0C MAXIMUM BLOCK SIZE                */
    unsigned short  deblrecl;       /* 0E LOGICAL RECORD LENGTH             */
};
#pragma pack(reset)

/***********************************************************************
 *                 SUBROUTINE NAME SECTION                             *
 *                                                                     *
 *        NOTE  FOLLOWS THE ACCESS METHOD DEPENDENT SECTION, OR THE    *
 *              DEVICE DEPENDENT SECTION IF THERE IS NO ACCESS         *
 *              METHOD SECTION                                         *
 ***********************************************************************/
#pragma pack(1)
struct debsubnm {
    char    debsubid[2];            /* 00 SUBROUTINE IDENTIFICATION.
                                          EACH ACCESS METHOD SUBROUTINE,
                                          APPENDAGE SUBROUTINE, AND IRB
                                          ROUTINE WILL HAVE A UNIQUE
                                          EIGHT-BYTE NAME.
                                          THE LOW-ORDER TWO BYTES OF EACH
                                          ROUTINE NAME WILL BE IN THIS FIELD
                                          IF THE SUBROUTINE IS LOADED BY
                                          THE OPEN ROUTINES.                */
};
#pragma pack(reset)

/***********************************************************************
 *                 DEB EXTENSION (OS/VS2)                              *
 *                 POINTED TO BY DEBXTNP                               *
 ***********************************************************************/
#pragma pack(1)
struct debxtn {
    short           debxlngh;       /* 00 LENGTH OF DEB EXTENSION           */
    char            debxflg1;       /* 02 FLAG BYTE                         */
#define DEBXCDCB    0x80            /* ... DEBDCBAD FIELD CONTAINS THE
                                           ADDRESS OF A COPIED DCB.
                                           USED BY END-OF-VOLUME, TCLOSE AND
                                           TASK CLOSE.                      */
#define DEBXTSKC    0x40            /* ... TASK CLOSE IS CLOSING THE RELATED
                                           DCB.  SET BY TASK CLOSE AND
                                           INTERROGATED BY END-OF-VOLUME,
                                           FEOV AND TCLOSE FOR DEB'S NOT ON
                                           THE CURRENT TCB DEB CHAIN.       */
#define DEBXDSSI    0x20            /* ... DATA SET SECURITY INDICATOR.
                                           SET BY OPEN AND CHECKPOINT.
                                           INTERROGATED BY EOV.             */
#define DEBXWIND    0x10            /* ... MSS WINDOW PROCESSING INDICATOR.
                                           SET BY OPEN.  INTERROGATED BY EOV,
                                           SAM EOB AND CLOSE.               */
#define DEBXACIS    0x08            /* ... ACQUIRE ISSUED WITH INHIBIT STAGE
                                           INDICATED DURING OPEN OR EOV.
                                           SET BY OPEN AND EOV.
                                           INTERROGATED BY SVC 126.         */

    char            debxrv48;       /* 03 RESERVED                          */
    void            *debxdsab;      /* 04 POINTER TO DSAB                   */
    unsigned        debxdcbm;       /* 08 DCB MODIFICATION MASK USED BY I/O
                                          SUPPORT                           */
    void            *debxdbpr;      /* 0C POINTER TO DEB                    */
    char            debxdso1;       /* 10 SAME AS DCBDSORG BYTE 1           */
    char            debxdso2;       /* 11 SAME AS DCBDSORG BYTE 2           */
    char            debxmcf1;       /* 12 SAME AS DCBMACRF BYTE 1           */
    char            debxmcf2;       /* 13 SAME AS DCBMACRF BYTE 2           */
    void            *debxxarg;      /* 14 ADDRESS OF BDAM READ EXCLUSIVE
                                          LIST                              */
    void            *debxopnj;      /* 18 POINTER TO DSAB (SEPARATE FROM
                                          DEBXDSAB) DYNAMICALLY ALLOCATED BY
                                          OPEN TYPE=J.  THIS POINTER WILL
                                          EXIST FOR NON-AUTHORIZED CALLERS
                                          OF OPEN TYPE=J FOR A DIRECT ACCESS
                                          DATA SET WHERE THE DATA SET NAME
                                          BEING OPENED IS DIFFERENT FROM THE
                                          DATA SET DESCRIBED BY THE DDNAME
                                          IN DCB AND THE JFCNWRIT BIT IS ON
                                          IN JFCB.  THE POINTER WILL BE USED
                                          BY CLOSE TO DYNAMICALLY UNALLOCATE
                                          THE DATA SET.                     */
    void            *debxsamb;      /* 1C ADDRESS OF SAM BLOCK (SAMB)       */
    char            debxopet[8];    /* 20 DATASET OPEN TIME SET BY OPEN
                                          INITIAL                           */
};
#pragma pack(reset)

#pragma pack(1)
struct deb {
    DEBAVT          debavt;         /* 00 appendage vector table            */
    DEBPRFX         debprfx;        /* 14 prefix table                      */
    DEBBASIC        debbasic;       /* 24 basic section                     */
    DEBDASD         debdasd;        /* 54 dasd section                      */
};
#pragma pack(reset)

#endif
