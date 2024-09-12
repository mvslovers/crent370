#ifndef OSDCB_H
#define OSDCB_H

typedef struct dcb      DCB;        /* DCB */
typedef struct exitlist EXITLIST;   /* DCB exit list    */

#ifndef BIT0
#define BIT0     0x80
#define BIT1     0x40
#define BIT2     0x20
#define BIT3     0x10
#define BIT4     0x08
#define BIT5     0x04
#define BIT6     0x02
#define BIT7     0x01
#endif

#pragma pack(1)
struct exitlist {
   unsigned exit_code;              /* 00 actually an enum _e_exit,
                                          possibly with LAST bit set        */
   void *exit_addr;                 /* 04 exit function address             */
};
#pragma pack(reset)


#pragma pack(1)
struct dcb {
    union {
        unsigned    dcbrelad;       /* 00 PARTITIONED ORGANIZATION DATA SET -
                                          ADDRESS (IN THE FORM TTRN) OF MEMBER
                                          CURRENTLY USED.  ---
                                          SYS1.LOGREC DATA SET - IF CCH OPTION
                                          HAS BEEN SPECIFIED IN SYSGEN PROCESS,
                                          ADDRESS OF A 12-BYTE PARAMETER IN
                                          THE EXPANSION OF MACRO INSTRUCTION
                                          IGFCATAP                          */
        char        ttrn[4];
    };

    char            dcbkeycn;       /* 04 KEYED BLOCK OVERHEAD CONSTANT     */
    char            dcbfdad[8];     /* 05 FULL DISK ADDRESS IN THE FORM OF
                                          MBBCCHHR OF RECORD THAT WAS JUST
                                          READ OR WRITTEN                   */
#define dcbdvtbl    dcbfdad[7]      /* 0C LAST BYTE OF DCBFDAD              */
    char            dcbdvtba[3];    /* 0D ADDRESS OF ENTRY IN I/O DEVICE
                                          CHARACTERISTICS TABLE FOR DEVICE
                                          BEING USED                        */
    char            dcbkeyle;       /* 10 KEY LENGTH OF DATA SET            */
    char            dcbdevt;        /* 11 DEVICE TYPE                       */
#define DCBDV311    0x21            /* ... 2311 DISK STORAGE                */
#define DCBDV301    0x22            /* ... 2301 PARALLEL DRUM               */
#define DCBDV303    0x23            /* ... 2303 SERIAL DRUM                 */
#define DCBDV302    0x24            /* ... 2302 DISK STORAGE                */
#define DCBDV321    0x25            /* ... 2321 DATA CELL STORAGE           */
#define DCBD1305    0x26            /* ... 2305 DRUM MODEL-1                */
#define DCBDV305    0x27            /* ... 2305 DRUM MODEL-2                */
#define DCBDV314    0x28            /* ... 2314/2319 DISK STORAGE FACILITY  */
#define DCBDV330    0x29            /* ... 3330 DISK STORAGE FACILITY
                                           3330 MODEL-1
                                           3330 MODEL-2
                                           3333 MODEL-1                     */
#define DCBDV340    0x2A            /* ... 3340/3344 DISK STORAGE FACILITY  */
#define DCBDV350    0x2B            /* ... 3350 DISK STORAGE FACILITY
                                           MODELS A2, B2, AND C2            */
#define DCBDV375    0x2C            /* ... 3375 DISK STORAGE FACILITY       */
#define DCBDV331    0x2D            /* ... 3330 MODEL-11 OR 3333 MODEL-11
                                           DISK STORAGE FACILITY            */
#define DCBDV380    0x2E            /* ... 3380 DISK STORAGE FACILITY       */
#define DCBDV390    0x2F            /* ... 3390 DISK STORAGE FACILITY       */
#define DCBDVTRM    0x4F			/* ... TERMINAL.  (DD CONTAINS TERM=TS) */

    short           dcbtrbal;       /* 12  TRACK BALANCE.  NUMBER OF BYTES
                                           REMAINING ON CURRENT TRACK AFTER
                                           A WRITE OPERATION
                                           (THIS QUANTITY MAY BE NEGATIVE IF
                                           THERE ARE NO BYTES REMAINING ON
                                           TRACK).                          */
    union {
        void        *dcbbufcb;      /* 14 ADDRESS OF BUFFER POOL CONTROL
                                          BLOCK                             */
        struct {
            char    dcbbufno;       /* 14 NUMBER OF BUFFERS REQUIRED FOR
                                          THIS DATA SET.  MAY RANGE FROM 0
                                          TO 255.
                                          IF UNBLOCKED SPANNED RECORDS ARE
                                          USED, NUMBER OF SEGMENT WORK AREAS
                                          REQUIRED FOR THIS DATA SET.       */
            char    dcbbufca[3];    /* 15 ADDRESS OF BUFFER POOL CONTROL
                                          BLOCK                             */
        };
    };
    short           dcbbufl;        /* 18 LENGTH OF BUFFER.  MAY RANGE FROM
                                          0 TO 32,767.                      */
    union {
        short       dcbdsorg;       /* 1A DATA SET ORGANIZATION BEING USED  */
        struct {
            char    dcbdsrg1;       /* 1A FIRST BYTE OF DCBDSORG            */
#define DCBDSGIS    BIT0            /* ... IS - INDEXED SEQUENTIAL          */
#define DCBDSGPS    BIT1            /* ... PS - PHYSICAL SEQUENTIAL         */
#define DCBDSGDA    BIT2            /* ... DA - DIRECT ORGANIZATION         */
#define DCBDSGCX    BIT3            /* ... CX - BTAM OR QTAM LINE GROUP     */
#define DCBDSGPO    BIT6            /* ... PO - PARTITIONED ORGANIZATION    */
#define DCBDSGU     BIT7            /* ... U  - UNMOVABLE, THE DATA CONTAINS
                                           LOCATION DEPENDENT INFORMATION   */
            char    dcbdsrg2;       /* 1B SECOND BYTE OF DCBDSORG           */
#define DCBDSGGS    BIT0            /* ... GS - GRAPHICS ORGANIZATION       */
#define DCBDSGTX    BIT1            /* ... TX - TCAM LINE GROUP             */
#define DCBDSGTQ    BIT2            /* ... TQ - TCAM MESSAGE QUEUE          */
#define DCBACBM     BIT4            /* ... ACCESS METHOD CONTROL BLOCK      */
#define DCBDSGTR    BIT5            /* ... TR - TCAM 3705                   */
        };
    };

    union {
        void        *dcbiobad;      /* 1C ADDRESS OF IOB WHEN CHAINED
                                          SCHEDULING IS USED OR FOR
                                          1419/1275                         */
        void        *dcbodeb;       /* 1C ADDRESS OF OLD DEB                */
        unsigned    dcblnp;         /* 1C 3525 PRINTER LINE POSITION COUNTER*/
        struct {
            char    dcbqslm;        /* 1C QSAM LOCATE MODE LOGICAL RECORD
                                          INTERFACE INDICATOR BYTE FOR UPDAT
                                          PROCESSING OF SPANNED RECORDS     */
#define DCB1DVDS    BIT0            /* ... ONLY ONE DEVICE IS ALLOCATED TO
                                           THIS DATA SET                    */
#define DCBUPDCM    BIT1            /* ... UPDATE COMPLETE, FREE OLD DEB    */
#define DCBUPDBT    BIT2+BIT3       /* ... UPDATE BITS                      */
#define DCBUPDT     BIT2            /* ... UPDATE TO TAKE PLACE             */
#define DCBNUPD     BIT2+BIT3       /* ... NO UPDATE TO TAKE PLACE          */
#define DCBSVDEB    BIT3            /* ... OLD DEB ADDRESS MUST BE SAVED    */
            union {
                char dcbiobaa[3];   /* 1D SAME AS DCBIOBAD ABOVE            */
                char dcbodeba[3];   /* 1D ADDRESS OF OLD DEB                */
            };
        };
    };

/***********************************************************************
 *                       FOUNDATION EXTENSION
 ***********************************************************************/
    union {
        void        *dcbeodad;      /* 20 SAME AS DCBEODA BELOW             */
        struct {
            union {
                char dcbhiarc;      /* 20 HIERARCHY BITS                    */
                char dcbbftek;      /* 20 BUFFERING TECHNIQUE BITS          */
                char dcbbfaln;      /* 20 BUFFER ALIGNMENT BITS             */
#define DCBH1       BIT0            /* ... HIERARCHY 1 MAIN STORAGE -
                                           BIT 5 IS ZERO                    */
#define DCBBFT      BIT1+BIT2+BIT3  /* ... BUFFERING TECHNIQUE              */
#define DCBBFTA     BIT1+BIT2       /* ... QSAM LOCATE MODE PROCESSING OF
                                           SPANNED RECORDS - OPEN IS TO
                                           CONSTRUCT A RECORD AREA IF IT
                                           AUTOMATICALLY CONSTRUCTS BUFFERS */
#define DCBBFTR     BIT2            /* ... FOR BSAM CREATE BDAM PROCESSING
                                           OF UNBLOCKED SPANNED RECORDS -
                                           SOFTWARE TRACK OVERFLOW.  FOR
                                           BSAM INPUT PROCESSING OF UNBLOCKED
                                           SPANNED RECORDS WITH KEYS - RECORD
                                           OFFSET PROCESSING.               */
#define DCBBFTS     BIT1            /* ... SIMPLE BUFFERING - BIT 3 IS ZERO */
#define DCBBFTKR    BIT2            /* ... UNBLOCKED SPANNED RECORDS -
                                           SOFTWARE TRACK OVERFLOW (BDAM)   */
#define DCBBFTE     BIT3            /* ... EXCHANGE BUFFERING - BIT 1 IS ZERO*/
#define DCBBFTKD    BIT4            /* ... DYNAMIC BUFFERING (BTAM)         */
#define DCBH0       BIT5            /* ... HIERARCHY 0 MAIN STORAGE - BIT 0
                                           IS ZERO                          */
#define DCBBFA      BIT6+BIT7       /* ... BUFFER ALIGNMENT                 */
#define DCBBFAD     BIT6            /* ... DOUBLEWORD BOUNDARY              */
#define DCBBFAF1    BIT7            /* ... FULLWORD NOT A DOUBLEWORD BOUNDARY,
                                           CODED IN DCB MACRO INSTRUCTION   */
#define DCBBFAF2    BIT6+BIT7       /* ... FULLWORD NOT A DOUBLEWORD BOUNDARY,
                                           CODED IN DCB MACRO INSTRUCTION   */
            };
            char    dcbeoda[3];     /* 21  ADDRESS OF A USER-PROVIDED ROUTINE
                                           TO HANDLE END-OF-DATA CONDITIONS */
        };
    };

    union {
        void        *dcbexlst;      /* 24 ADDRESS OF USER-PROVIDED LIST OF
                                          EXITS                             */
        struct {
            char    dcbrecfm;       /* 24 RECORD FORMAT                     */
#define DCBRECLA    BIT0+BIT1+BIT2  /* ... RECORD LENGTH INDICATOR - ASCII  */
#define DCBRECD     BIT2            /* ... ASCII VARIABLE RECORD LENGTH     */
#define DCBRECL     BIT0+BIT1       /* ... RECORD LENGTH INDICATOR          */
#define DCBRECF     BIT0            /* ... FIXED RECORD LENGTH              */
#define DCBRECV     BIT1            /* ... VARIABLE RECORD LENGTH           */
#define DCBRECU     BIT0+BIT1       /* ... UNDEFINED RECORD LENGTH          */
#define DCBRECTO    BIT2            /* ... TRACK OVERFLOW                   */
#define DCBRECBR    BIT3            /* ... BLOCKED RECORDS                  */
#define DCBRECSB    BIT4            /* ... FOR FIXED LENGTH RECORD FORMAT -
                                           STANDARD BLOCKS.
                                           FOR VARIABLE LENGTH RECORD FORMAT -
                                           SPANNED RECORDS                  */
#define DCBRECCC    BIT5+BIT6       /* ... CONTROL CHARACTER INDICATOR      */
#define DCBRECCA    BIT5            /* ... ASA CONTROL CHARACTER            */
#define DCBRECCM    BIT6            /* ... MACHINE CONTROL CHARACTER        */
#define DCBRECC     0x00            /* ... NO CONTROL CHARACTER             */
#define DCBRECKL    BIT7            /* ... KEY LENGTH (KEYLEN) WAS SPECIFIED
                                           IN DCB MACRO INSTRUCTION         */
            char    dcbexlsa[3];    /* 25 ADDRESS OF USER-PROVIDED LIST OF
                                          EXITS                             */
        };
    };

/***********************************************************************
 *                       FOUNDATION BEFORE OPEN
 ***********************************************************************/
    union {
        struct {    /* foundation before open */
            char    dcbddnam[8];    /* 28 NAME ON THE DD STATEMENT WHICH
                                          DEFINES THE DATA SET ASSOCIATED
                                          WITH THIS DCB                     */
            char    dcboflgs;       /* 30 FLAGS USED BY OPEN ROUTINE        */
#define DCBOFLWR    BIT0            /* ... IF ZERO, LAST I/O OPERATION WAS
                                           READ OR POINT.
                                           IF ONE, LAST I/O OPERATION WAS
                                           WRITE.                           */
#define DCBOFIOD    BIT0            /* ... DATA SET IS BEING OPENED FOR
                                           INPUT OR OUTPUT (BDAM)           */
#define DCBOFLRB    BIT1            /* ... LAST I/O OPERATION WAS IN READ
                                           BACKWARD MODE                    */
#define DCBOFEOV    BIT2            /* ... SET TO 1 BY EOV WHEN IT CALLS
                                           CLOSE ROUTINE FOR CONCATENATION
                                           OF DATA SETS WITH UNLIKE
                                           ATTRIBUTES                       */
#define DCBOFOPN    BIT3            /* ... AN OPEN HAS BEEN SUCCESSFULLY
                                           COMPLETED                        */
#define DCBOFPPC    BIT4            /* ... SET TO 1 BY PROBLEM PROGRAM TO
                                           INDICATE A CONCATENATION OF
                                           UNLIKE ATTRIBUTES                */
#define DCBOFTM     BIT5            /* ... TAPE MARK HAS BEEN READ          */
#define DCBOFUEX    BIT6            /* ... SET TO 0 BY AN I/O SUPPORT FUNCTION
                                           WHEN THAT FUNCTION TAKES A USER
                                           EXIT. SET TO 1 ON RETURN FROM USER
                                           EXIT TO THE I/O SUPPORT FUNCTION
                                           WHICH TOOK THE EXIT.             */
#define DCBOFIOF    BIT7            /* ... SET TO 1 BY AN I/O SUPPORT
                                           FUNCTION IF DCB IS TO BE PROCESSED
                                           BY THAT FUNCTION                 */

            char    dcbiflg;        /* 31 FLAGS USED BY IOS IN COMMUNICATING
                                          ERROR CONDITIONS AND IN DETERMINING
                                          CORRECTIVE PROCEDURES             */
#define DCBIBEC     BIT0+BIT1       /* ... ERROR CORRECTION INDICATOR       */
#define DCBIFNEP    0x00            /* ... NOT IN ERROR PROCEDURE           */
#define DCBEX       BIT1            /* ... ERROR CORRECTION OR IOS PAGE
                                           FIX IN PROCESS                   */
#define DCBIFPEC    BIT0+BIT1       /* ... PERMANENT ERROR CORRECTION       */
#define DCBIBPCT    BIT2+BIT3       /* ... PRINTER CARRIAGE TAPE PUNCH
                                           INDICATOR                        */
#define DCBIFC9     BIT2            /* ... CHANNEL 9 PRINTER CARRIAGE TAPE
                                           PUNCH SENSED                     */
#define DCBIFC12    BIT3            /* ... CHANNEL 12 PRINTER CARRIAGE TAPE
                                           PUNCH SENSED                     */
#define DCBIBIOE    BIT4+BIT5       /* ... IOS ERROR ROUTINE USE INDICATOR  */
#define DCBIFER     0x00            /* ... ALWAYS USE I/O SUPERVISOR ERROR
                                           ROUTINE                          */
#define DCBIFNE1    BIT5            /* ... NEVER USE I/O SUPERVISOR ERROR
                                           ROUTINE                          */
#define DCBIFTIM    BIT5            /* ... TEST IOS MASK (IMSK) FOR ERROR
                                           PROCEDURE (BTAM)                 */
#define DCBIFNE2    BIT4            /* ... NEVER USE I/O SUPERVISOR ERROR
                                           ROUTINE                          */
#define DCBIFNE3    BIT4+BIT5       /* ... NEVER USE I/O SUPERVISOR ERROR
                                           ROUTINE                          */

            union {
                short   dcbmacr;    /* 32 MACRO INSTRUCTION REFERENCE       */
                struct {
                    char dcbmacr1;  /* 32 FIRST BYTE OF DCBMACR             */
#define DCBMRECP    BIT0            /* ... EXECUTE CHANNEL PROGRAM (EXCP) ---
                                           ALWAYS ZERO (BSAM, QSAM, BPAM,
                                           BISAM, QISAM, BDAM) ---
                                           RESERVED (QTAM, BTAM)            */
#define DCBMRFE     BIT1            /* ... FOUNDATION EXTENSION IS PRESENT
                                           EXCP)                            */
#define DCBMRGET    BIT1            /* ... GET (QSAM, QISAM, TCAM)          */
#define DCBMRPTQ    BIT1            /* ... PUT FOR MESSAGE GROUP (QTAM) ---
                                           ALWAYS ZERO (BSAM, BPAM, BISAM,
                                           BDAM) --- RESERVED (BTAM)        */
#define DCBMRAPG    BIT2            /* ... APPENDAGES ARE REQUIRED (EXCP)   */
#define DCBMRRD     BIT2            /* ... READ (BSAM, BPAM, BISAM, BDAM,
                                           BTAM)                            */
#define DCBMRWRQ    BIT2            /* ... WRITE FOR LINE GROUP (QTAM) ---
                                           ALWAYS ZERO (QSAM, QISAM)        */
#define DCBMRCI     BIT3            /* ... COMMON INTERFACE (EXCP)          */
#define DCBMRMVG    BIT3            /* ... MOVE MODE OF GET (QSAM, QISAM)   */
#define DCBMRRDK    BIT3            /* ... KEY SEGMENT WITH READ (BDAM) ---
                                           ALWAYS ZERO (BISAM) ---
                                           RESERVED (BSAM, BPAM, QTAM, BTAM)*/
#define DCBMRLCG    BIT4            /* ... LOCATE MODE OF GET (QSAM, QISAM) */
#define DCBMRRDI    BIT4            /* ... ID ARGUMENT WITH READ (BDAM) ---
                                           ALWAYS ZERO (BISAM) ---
                                           RESERVED (EXCP, BSAM, BPAM, QTAM,
                                           BTAM)                            */
#define DCBMRABC    BIT5            /* ... USER'S PROGRAM MAINTAINS ACCURATE
                                           BLOCK COUNT (EXCP)               */
#define DCBMRPT1    BIT5            /* ... POINT (WHICH IMPLIES NOTE) (BSAM,
                                           BPAM)                            */
#define DCBMRSBG    BIT5            /* ... SUBSTITUTE MODE OF GET (QSAM)    */
#define DCBMRDBF    BIT5            /* ... DYNAMIC BUFFERING (BISAM, BDAM) ---
                                           ALWAYS ZERO (QISAM) ---
                                           RESERVED (QTAM, BTAM)            */
#define DCBPGFXA    BIT6            /* ... PAGE FIX APPENDAGE IS SPECIFIED
                                           (EXCP)                           */
#define DCBMRCRL    BIT6            /* ... CNTRL (BSAM, QSAM)               */
#define DCBMRCHK    BIT6            /* ... CHECK (BISAM)                    */
#define DCBMRRDX    BIT6            /* ... READ EXCLUSIVE (BDAM) ---
                                           RESERVED (BPAM, QISAM, QTAM, BTAM)*/
#define DCBMRDMG    BIT7            /* ... DATA MODE OF GET (QSAM)          */
#define DCBMRCK     BIT7            /* ... CHECK (BDAM) ---
                                           RESERVED (EXCP, BSAM, BPAM, BISAM,
                                           QISAM, QTAM, BTAM)               */

                char    dcbmacr2;   /* 33 SECOND BYTE OF DCBMACR            */
#define DCBMRSTL    BIT0            /* ... SETL (QISAM) ---
                                           ALWAYS ZERO (BSAM, QSAM, BPAM,
                                           BISAM, BDAM) ---
                                           RESERVED (EXCP, QTAM, BTAM)      */
#define DCBMRPUT    BIT1            /* ... PUT (QSAM, TCAM) -
                                           PUT OR PUTX (QISAM)              */
#define DCBMRGTQ    BIT1            /* ... GET FOR MESSAGE GROUP (QTAM) ---
                                           ALWAYS ZERO (BSAM, BPAM, BISAM,
                                           BDAM) ---
                                           RESERVED (EXCP, BTAM)            */
#define DCBMRWRT    BIT2            /* ... WRITE (BSAM, BPAM, BISAM, BDAM,
                                           BTAM)                            */
#define DCBMRRDQ    BIT2            /* ... READ FOR LINE GROUP (QTAM) ---
                                           ALWAYS ZERO (QSAM, QISAM) ---
                                           RESERVED (EXCP)                  */
#define DCBMRMVP    BIT3            /* ... MOVE MODE OF PUT (QSAM, QISAM)   */
#define DCBMRWRK    BIT3            /* ... KEY SEGMENT WITH WRITE (BDAM) ---
                                           ALWAYS ZERO (BISAM) ---
                                           RESERVED (EXCP, BSAM, BPAM, QTAM,
                                           BTAM)                            */
#define DCBMR5WD    BIT4            /* ... FIVE-WORD DEVICE INTERFACE (EXCP)*/
#define DCBMRLDM    BIT4            /* ... LOAD MODE BSAM (CREATE BDAM DATA
                                           SET) (BSAM)                      */
#define DCBMRLCP    BIT4            /* ... LOCATE MODE OF PUT (QSAM, QISAM) */
#define DCBMRIDW    BIT4            /* ... ID ARGUMENT WITH WRITE (BDAM) ---
                                           ALWAYS ZERO (BISAM) ---
                                           RESERVED (BPAM, QTAM, BTAM)      */
#define DCBMR4WD    BIT5            /* ... FOUR-WORD DEVICE INTERFACE (EXCP)*/
#define DCBMRPT2    BIT5            /* ... POINT (WHICH IMPLIES NOTE)
                                           (BSAM, BPAM)                     */
#define DCBMRTMD    BIT5            /* ... SUBSTITUTE MODE (QSAM)           */
#define DCBMRUIP    BIT5            /* ... UPDATE IN PLACE (PUTX) (QISAM) ---
                                           ALWAYS ZERO (BISAM) ---
                                           RESERVED (BDAM, QTAM, BTAM)      */
#define DCBMR3WD    BIT6            /* ... THREE-WORD DEVICE INTERFACE (EXCP)*/
#define DCBMRCTL    BIT6            /* ... CNTRL (BSAM, QSAM)               */
#define DCBMRSTK    BIT6            /* ... SETL BY KEY (QISAM)              */
#define DCBMRAWR    BIT6            /* ... ADD TYPE OF WRITE (BDAM) ---
                                           ALWAYS ZERO (BISAM) ---
                                           RESERVED (BPAM, QTAM, BTAM)      */
#define DCBMR1WD    BIT7            /* ... ONE-WORD DEVICE INTERFACE (EXCP) */
#define DCBMRSWA    BIT7            /* ... USER'S PROGRAM HAS PROVIDED A
                                           SEGMENT WORK AREA POOL
                                           (BSAM CREATE BDAM, BDAM)         */
#define DCBMRDMD    BIT7            /* ... DATA MODE (QSAM)                 */
#define DCBMRSTI    BIT7            /* ... SETL BY ID (QISAM) ---
                                           ALWAYS ZERO (BISAM) ---
                                           RESERVED (BPAM, QTAM, BTAM)      */
                };
            };
        };

/***********************************************************************
 *                       FOUNDATION AFTER OPEN
 ***********************************************************************/
        struct {    /* foundation after open */
            short   dcbtiot;        /* 28 OFFSET FROM TIOT ORIGIN TO TIOELNGH
                                          FIELD IN TIOT ENTRY FOR DD STATEMENT
                                          ASSOCIATED WITH THIS DCB          */
            union {
                short   dcbmacrf;   /* 2A SAME AS DCBMACR BEFORE OPEN       */
                struct {
                    char dcbmacf1;  /* 2A FIRST BYTE OF DCBMACRF            */
                    char dcbmacf2;  /* 2B SECOND BYTE OF DCBMACRF           */
                };
            };

            union {
                void    *dcbdebad;  /* 2C ADDRESS OF ASSOCIATED DEB         */
                struct {
                    char dcbiflgs;  /* 2C SAME AS DCBIFLG BEFORE OPEN       */
#define DCBIFEC     BIT0+BIT1       /* ... ERROR CORRECTION INDICATOR       */
#define DCBIFPCT    BIT2+BIT3       /* ... PRINTER CARRIAGE TAPE PUNCH
                                           INDICATOR                        */
#define DCBIFIOE    BIT4+BIT5       /* ... IOS ERROR ROUTINE USE INDICATOR  */
#define DCBIFLDT    BIT6            /* ... 3800 PRINTER LOST DATA INDICATOR */
                    char dcbdeba[3];/* 2D ADDRESS OF ASSOCIATED DEB         */
                };
            };

            union {
                void    *dcbread;   /* 30 ADDRESS OF READ MODULE            */
                void    *dcbwrite;  /* 30 ADDRESS OF WRITE MODULE           */
                void    *dcbget;    /* 30 ADDRESS OF GET MODULE             */
                void    *dcbput;    /* 30 ADDRESS OF PUT MODULE             */
                struct {
                    union {
                        char dcboflg;   /* 30 SAME AS DCBOFLGS BEFORE OPEN  */
                        char dcboflg1;  /* 30 SAME AS DCBOFLGS BEFORE OPEN  */
                    };
                    union {
                        char dcbreada[3];   /* 31 ADDRESS OF READ MODULE    */
                        char dcbwrita[3];   /* 31 ADDRESS OF WRITE MODULE   */
                        char dcbgeta[3];    /* 31 ADDRESS OF GET MODULE     */
                        char dcbputa[3];    /* 31 ADDRESS OF PUT MODULE     */
                    };
                };
            };

/***********************************************************************
 *                       QSAM-BSAM-BPAM COMMON INTERFACE
 ***********************************************************************/
            union {
                void    *dcbgerr;   /* 34 ADDRESS OF SYNCHRONIZING ROUTINE
                                          FOR GET                           */
                void    *dcbperr;   /* 34 ADDRESS OF SYNCHRONIZING ROUTINE
                                          FOR PUT                           */
                void    *dcbcheck;  /* 34 ADDRESS OF CHECK MODULE           */
                struct {
                    char dcboptcd;  /* 34 OPTION CODES (1 byte)             */
#define DCBOPTW     BIT0            /* ... WRITE VALIDITY CHECK (DASD)
                                           (BSAM, BPAM, QSAM, ISAM, BDAM)   */
#define DCBOPTU     BIT1            /* ... ALLOW DATA CHECK CAUSED BY INVALID
                                           CHARACTER (1403 PRINTER WITH UCS
                                           FEATURE) (BSAM, BPAM, QSAM)
                                           MSS WINDOW PROCESSING REQUESTED
                                           (BSAM, QSAM)                     */
#define DCBOPTC     BIT2            /* ... CHAINED SCHEDULING USING PCI
                                           (BSAM, BPAM, QSAM)               */
#define DCBOPTH     BIT3            /* ... 1287/1288 OPTICAL READER - HOPPER
                                           EMPTY EXIT (BSAM, BPAM)
                                           PDS STAGING ON MSS REQUEST(BPAM) */
#define DCBOPTO     BIT3            /* ... 1285/1287 OPTICAL READER - ON-LINE
                                           CORRECTION (QSAM)                */
#define DCBBCKPT    BIT3            /* ... CHANNEL-END APPENDAGE IS TO BYPASS
                                           DOS EMBEDDED CHECKPOINT RECORDS ON
                                           TAPE (BSAM, QSAM)                */
#define DCBOPTQ     BIT4            /* ... TRANSLATION TO OR FROM ASCII
                                           (BSAM, BPAM, QSAM)               */
#define DCBOPTZ     BIT5            /* ... MAGNETIC TAPE DEVICES - USE REDUCED
                                           ERROR RECOVERY PROCEDURE
                                           (EXCP, BSAM, BPAM, QSAM)         */
#define DCBSRCHD    BIT5            /* ... USE SEARCH DIRECT, INSTEAD OF
                                           SEARCH PREVIOUS, ON RECORD POSITION
                                           SENSING DEVICE
                                           (EXCP, BSAM, BPAM, QSAM)         */
#define DCBOPTT     BIT6            /* ... USER TOTALING (BSAM, QSAM)       */
#define DCBOPTJ     BIT7            /* ... 3800 PRINTER, OPTCD=J; (DYNAMIC
                                           SELECT OF TRANSLATE TABLES)      */

                    union {
                        char dcbgerra[3];   /* 35 ADDRESS OF SYNCHRONIZING
                                                  ROUTINE FOR GET           */
                        char dcbperra[3];   /* 35 ADDRESS OF SYNCHRONIZING
                                                  ROUTINE FOR PUT           */
                        char dcbchcka[3];   /* 35 ADDRESS OF CHECK MODULE   */
                    };
                };
            };

            union {
                void    *dcbsynad;  /* 38 ADDRESS OF USER-PROVIDED SYNAD
                                          ROUTINE                           */
                struct {
                    char  dcbiobl;  /* 38 IOB LENGTH IN DOUBLE WORDS        */
                    char  dcbsyna[3];/* 39 ADDRESS OF USER-PROVIDED SYNAD
                                          ROUTINE                           */
                };
            };

            union {
                char    dcbflag1;   /* 3C TCAM APPLICATION PROGRAM FLAGS
                                          (BSAM, BPAM, QSAM)                */
                char    dcbcind1;   /* 3C CONDITION INDICATORS              */
#define DCBCNTOV    BIT0            /* ... DIRECT ACCESS - TRACK OVERFLOW IN
                                           USE (BSAM, BPAM, QSAM)
                                           2540 CARD PUNCH - DATA SET WAS
                                           OPENED BUT NO DATA WAS WRITTEN
                                           (QSAM)                           */
#define DCBSTQCK    BIT0            /* ... STOP EQUAL QUICK WAS SPECIFIED FOR
                                           APPLICATION PROG. DCBS (TCAM)    */
#define DCBSTFLS    BIT1            /* ... STOP EQUAL FLUSH WAS SPECIFIED FOR
                                           APPLICATION PROG. DCBS (TCAM)    */
#define DCBCNSRD    BIT1            /* ... SEARCH DIRECT (BSAM, BPAM, QSAM) */
#define DCBCNEVB    BIT2            /* ... END OF VOLUME - USED BY EOB ROUTINES
                                           (BSAM, BPAM, QSAM)               */
#define DCBCNEVA    BIT3            /* ... END OF VOLUME - USED BY CHANNEL-END
                                           APPENDAGE ROUTINES
                                           (BSAM, BPAM, QSAM)               */
#define DCBCNBRM    BIT5            /* ... BLOCKED RECORD BIT MODIFIED
                                           (BSAM,BPAM,QSAM)                 */
#define DCBCNEXB    BIT7            /* ... EXCHANGE BUFFERING SUPPORTED
                                           (QSAM)                           */
            };

            char    dcbcind2;       /* 3D CONDITION INDICATORS              */
#define DCBCNSTO    BIT0            /* ... PARTITIONED DATA SET - STOW HAS BEEN
                                           PERFORMED (BSAM, BPAM, QSAM)
                                           SEQUENTIAL DATA SET - UPDATE
                                           (BSAM, BPAM)                     */
#define DCBCNWR0    BIT1            /* ... DIRECT ORGANIZATION DATA SET -
                                           LAST I/O WAS A WRITE RECORD ZERO
                                           (BSAM, BPAM, QSAM)
                                           SEQUENTIAL DATA SET - UPDATE EOF IS
                                           INDICATED (BSAM, BPAM)           */
#define DCBCNCLO    BIT2            /* ... CLOSE IN PROCESS (QSAM)          */
#define DCBCNIOE    BIT3            /* ... PERMANENT I/O ERROR
                                           (BSAM, BPAM, QSAM)               */
#define DCBCNBFP    BIT4            /* ... OPEN ACQUIRED BUFFER POOL
                                           (BSAM, BPAM, QSAM)               */
#define DCBCNCHS    BIT5            /* ... CHAINED SCHEDULING BEING SUPPORTED
                                           (BSAM, BPAM, QSAM)               */
#define DCBCNFEO    BIT6            /* ... FEOV BIT (BSAM, BPAM, QSAM)      */
#define DCBCNQSM    BIT7            /* ... ALWAYS ZERO (BSAM, BPAM)
                                           THIS IS A QSAM DCB (QSAM)        */

            unsigned short dcbblksi;/* 3E MAXIMUM BLOCK SIZE                */
            char    dcbwcpo;        /* 40 OFFSET OF WRITE CHANNEL PROGRAM
                                          FROM THE START OF IOB             */
            char    dcbwcpl;        /* 41 LENGTH OF WRITE CHANNEL PROGRAM   */
            char    dcboffsr;       /* 42 OFFSET OF READ CCW FROM BSAM/BPAM
                                          PREFIX OF IOB                     */
            char    dcboffsw;       /* 43 OFFSET OF WRITE CCW FROM BSAM/BPAM
                                          PREFIX OF IOB                     */

            union {
                void    *dcbioba;   /* 44 FOR NORMAL SCHEDULING, ADDRESS OF
                                          QSAM OR BSAM/BPAM PREFIX OF IOB.
                                          FOR CHAINED SCHEDULING, ADDRESS OF
                                          ICB.
                                          FOR 1419/1275, ADDRESS OF MAGNETIC
                                          INTERRUPT CONTROL BLOCK (MICB)
                                          CURRENTLY BEING PROCESSED BY READ
                                          ROUTINE.
                                          FOR TSO TERMINAL DATA SET OPENED FOR
                                          INPUT AND FORMAT U, SIMULATED
                                          LOW-ORDER FOUR BYTES OF IOBCSW    */

                void    *dcbcicb;   /* 44 SAME AS DCBCICBA BELOW            */
                struct {
                    char unused45;   /* 45 unused                        */
                    char dcbcicba[3];/* 45 POINTER TO JES C.I. CONTROL BLOCK
                                          (CICB)                            */
                };
            };

            union {
                void    *dcbeobr;   /* 48 ADDRESS OF END-OF-BLOCK MODULE
                                          FOR READ                          */
                void    *dcblccw;   /* 48 FOR EXCHANGE BUFFERING, ADDRESS
                                          OF LAST CCW IN LIST (4 bytes)     */
                void    *dcbeobad;  /* 48 FOR SIMPLE BUFFERING, ADDRESS
                                          OF LAST BYTE OF CURRENT BUFFER    */
                struct {
                    char dcbncp;    /* 48 NUMBER OF CHANNEL PROGRAMS.
                                          NUMBER OF READ OR WRITE REQUESTS
                                          WHICH MAY BE ISSUED PRIOR TO A CHECK,
                                          NUMBER OF IOB'S GENERATED.
                                          (99 MAXIMUM) (1 byte)             */
                    char dcbeodra[3];/* 49 ADDRESS OF END-OF-BLOCK MODULE FOR
                                          READ (3 bytes)                    */
                };
            };

            union {
                void    *dcbeobw;   /* 4C ADDRESS OF END-OF-BLOCK MODULE FOR
                                          WRITE.
                                          FOR BSAM CREATE BDAM PROCESSING OF
                                          UNBLOCKED SPANNED RECORDS WITH
                                          BKTEK=R SPECIFIED, ADDRESS OF
                                          SEGMENT WORK AREA CONTROL BLOCK   */
                void    *dcbcccw;   /* 4C FOR EXCHANGE BUFFERING, ADDRESS
                                          OF CURRENT OR NEXT CCW            */
                void    *dcbrecad;  /* 4C ADDRESS OF CURRENT OR NEXT LOGICAL
                                          RECORD                            */
                struct {
                    char dcbrecbt;  /* 4C FLAG BYTE                         */
#define DCBRCREL    BIT0+BIT1+BIT2+BIT3
                                    /* ... RELSE MACRO HAS BEEN ISSUED (QSAM
                                           WITH SIMPLE BUFFERING)           */
#define DCBRCTRU    BIT0            /* ... TRUNC MACRO HAS BEEN ISSUED (QSAM
                                           LOCATE MODE)                     */
#define DCBRCFGT    BIT1            /* ... FIRST GET AFTER OPEN (QSAM LOCATE
                                           MODE)                            */
                    char dcbreca[3];/* 4D ADDRESS OF CURRENT OR NEXT LOGICAL
                                          RECORD (3 bytes)                  */
                };
            };

            union {
                short dcbdirct;     /* 50 NUMBER OF BYTES USED IN LAST
                                          DIRECTORY BLOCK (RANGE 0-254)
                                          (BSAM, BPAM) (2 bytes)            */
                char dcbqsws;       /* 50 FLAG BYTE                         */
#define DCBPOPEN    BIT5            /* ... QSAM PARALLEL INPUT PROCESSING   */

                char dcbusasi;      /* 50 FLAG BYTE FOR ASCII TAPES         */
#define DCBBLBP     BIT1            /* ... BLOCK PREFIX IS FOUR BYTE FIELD
                                           CONTAINING BLOCK LENGTH IN UNPACKED
                                           DECIMAL (SPECIFIED BY BUFFER=L). */
#define DCBQADFS    BIT2+BIT3+BIT4  /* ... USED TO PERFORM SEQUENCE CHECKING
                                           WITH MULTIPLE FUNCTION SUPPORT
                                           FOR 3525 (BSAM, QSAM)            */
#define DCBQADF1    BIT2            /* ... FIRST BIT OF DCBQADFS            */
#define DCBQADF2    BIT3            /* ... SECOND BIT OF DCBQADFS           */
#define DCBQADF3    BIT4            /* ... THIRD BIT OF DCBQADFS            */
#define DCB3525A    BIT6            /* ... DCB IS 3525 - ASSOCIATED DATA
                                           SETS EXIST                       */
#define DCBQSTRU    BIT7            /* ... TRUNC ENTRY POINT ENTERED (QSAM) */
                struct {
                  char    unused50;
                  union {
                    char dcbbufof;  /* 51 BLOCK PREFIX LENGTH (0-99),
                                          SPECIFIED BY BUFOFF=N OR BUFOFF=L */
                    char dcbdircq;  /* 51 NUMBER OF BYTES USED IN LAST
                                          DIRECTORY BLOCK (RANGE 0-254)
                                          (QSAM)                            */
                  };
                };
            };

            unsigned short dcblrecl;/* 52 LOGICAL RECORD LENGTH (2 bytes)   */

            union {
                void    *dcbcntrl;  /* 54 ADDRESS OF CNTRL MODULE (4 bytes) */
                void    *dcbnote;   /* 54 ADDRESS OF NOTE/POINT MODULE      */
                void    *dcbpoint;  /* 54 ADDRESS OF NOTE/POINT MODULE      */
                struct {
                    char dcberopt;  /* 54 ERROR OPTION                      */
#define DCBERACC    BIT0            /* ... ACCEPT PERMANENT ERROR           */
#define DCBERSKP    BIT1            /* ... SKIP PERMANENT ERROR             */
#define DCBERABE    BIT2            /* ... ABNORMAL END OF TASK             */
                    char unused55[3];
                };
            };

            short   unused58;       /* 58 unused?                           */

            short   dcbprecl;       /* 5A FORMAT F RECORDS: (2 bytes)
                                          BLOCK LENGTH
                                          FORMAT U RECORDS:
                                            MAXIMUM BLOCK LENGTH
                                          FORMAT V RECORDS:
                                          UNSPANNED RECORDS:
                                            MAXIMUM BLOCK LENGTH
                                          SPANNED RECORDS:
                                            PUT, NOT DATA MODE:
                                              MAXIMUM BOLCK LENGTH
                                            PUT, DATA MODE:
                                              DATA LENGTH
                                            GET:
                                              SEGMENT CONTROL CODE OF PREVIOUS
                                              SEGMENT                       */
            void    *dcbeob;        /* 5C ADDRESS OF END OF BLOCK MODULE    */
        };  /* struct */
    };  /* union */

    /* extensions to the standard BSAM DCB for our own use */
    void    *dcbuser;               /* 60 not part of DCB proper, user data */
    void    *dcbpriv;               /* 64 not part of DCB proper, internal  */
};  /* struct dcb */
#pragma pack(reset)

#endif
