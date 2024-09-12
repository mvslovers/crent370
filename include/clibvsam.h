#ifndef CLIBVSAM_H
#define CLIBVSAM_H

typedef struct vsfile   VSFILE;     /* VSAM file handle                     */
typedef enum   vstype   VSTYPE;     /* type: KSDS/ESDS/RRDS                 */
typedef enum   vsaccess VSACCESS;   /* access: DIR/SEQ/DYNAM                */
typedef enum   vsmode   VSMODE;     /* mode: IN/OUT/UPD                     */

typedef struct acb      ACB;        /* ACCESS METHOD CONTROL BLOCK          */
typedef struct rpl      RPL;        /* REQUEST PARAMETER LIST               */

typedef struct shwpl    SHWPL;      /* SHOWCAT parameter list               */
typedef struct shwout   SHWOUT;     /* SHOWCAT return area (not D or I)     */
typedef struct shwoutdi SHWOUTDI;   /* SHOWCAT return area (D or I)         */

#pragma pack(1)
struct acb {                        /* ACCESS METHOD CONTROL BLOCK          */
    unsigned char   acbid;          /* 00 ACB IDENTIFIER                    */
#define ACBIDVAL            0xA0    /* ... IDENTIFIER VALUE - X'A0'         */

    unsigned char   acbstyp;        /* 01 ACB SUBTYPE                       */
#define ACBSVSAM            0x10    /* ... VSAM SUBTYPE                     */
#define ACBSVRP             0x11    /* ... VRP SUBTYPE                      */
#define ACBSVTAM            0x20    /* ... VTAM SUBTYPE                     */
#define ACBS3540            0x40    /* ... 3540 SUBTYPE                     */

    unsigned short  acbleng;        /* 02 ACB LENGTH IN BYTES               */

    void            *acbamwap;      /* 04 ACCESS METHOD WORKAREA POINTER    */
    void            *acbinrtm;      /* 08 DATA MANAGEMENT INTERFACE ROUTINE
                                          ADDRESS; VTAM REQUEST PROCESSOR
                                          ADDRESS                           */

    unsigned char   acbmacr1;       /* 0C MACRF FIRST BYTE                  */
#define ACBKEY              0x80    /* ... KEYED PROCESSING VIA INDEX       */
#define ACBADR              0x40    /* ... ADDRESSED PROCESSING             */
#define ACBCNV              0x20    /* ... PROCESSING BY CONTROL INTERVAL   */
#define ACBSEQ              0x10    /* ... SEQUENTIAL PROCESSING            */
#define ACBDIR              0x08    /* ... DIRECT PROCESSING                */
#define ACBIN               0x04    /* ... INPUT PROCESSING USING GET OR
                                           READ                             */
#define ACBOUT              0x02    /* ... OUTPUT PROCESSING USING PUT OR
                                           WRITE                            */
#define ACBUBF              0x01    /* ... USER CONTROLS BUFFERS -
                                           VALID ONLY WITH CONTROL
                                           INTERVAL PROCESSING              */

    unsigned char   acbmacr2;       /* 0D MACRF SECOND BYTE                 */
#define ACBNTRUN            0x80    /* ... DEFINED ONLY WHEN OUTPUT AND
                                           ACBRECAF IS ON. THE SYSTEM IS TO
                                           ENSURE THAT THE LOGICAL RECORD
                                           LENGTH WILL BE THE SAME WHEN THE
                                           DATA IS READ (NO BLANK TRUNCATION).
                                           BIT NOT DEFINED FOR INPUT.       */
#define ACBCCANY            0x40    /* ... THE CONTROL CHARACTER TYPE IS
                                           INDICATED IN RPLOPT4 AFTER EACH
                                           GET. NOT DEFINED FOR OUTPUT.     */
#define ACBSKP              0x10    /* ... SKIP SEQUENTIAL PROCESSING       */
#define ACBLOGON            0x08    /* ... LOGON REQUESTS TO AN APPLICATION
                                           WILL BE REJECTED(VTAM)           */
#define ACBRST              0x04    /* ... SET DATA SET TO EMPTY STATE      */
#define ACBDSN              0x02    /* ... BASIC SUBTASK SHARED CONTROL
                                           BLOCK CONNECTION ON COMMON
                                           DSNAMES                          */
#define ACBAIX              0x01    /* ... ENTITY TO BE PROCESSED IS AIX
                                           PATH SPECIFIED IN THE GIVEN
                                           DDNAME                           */

    unsigned char   acbbstno;       /* 0E NUMBER OF CONCURRENT STRINGS FOR
                                          AIX PATH                          */
    unsigned char   acbstrno;       /* 0F NUMBER OF CONCURRENT REQUEST
                                          STRINGS                           */

    unsigned short  acbbufnd;       /* 10 NUMBER OF DATA RECORD BUFFERS     */
    unsigned short  acbbufni;       /* 12 NUMBER OF INDEX RECORD BUFFERS    */

    unsigned char   acbmacr3;       /* 14 MACRF THIRD BYTE                  */
#define ACBLSR              0x40    /* ... LOCAL SHARED RESOURCE            */
#define ACBGSR              0x20    /* ... GLOBAL SHARED RESOURCE           */
#define ACBICI              0x10    /* ... IMPROVED CONTROL INTERVAL
                                           PROCESSING                       */
#define ACBDFR              0x08    /* ... DEFER WRITES                     */
#define ACBSIS              0x04    /* ... SEQUENTIAL INSERT STRATEGY       */
#define ACBNCFX             0x02    /* ... NFX=0/CFX=1                      */

    unsigned char   acbmacr4;       /* 15 RESERVED                          */
    unsigned short  acbjbuf;        /* 16 NUMBER OF JOURNAL BUFFERS(VSAM)   */

    unsigned char   acbrecfm;       /* 18 RECORD FORMAT                     */
#define ACBRECAF            0x80    /* ... JES FORMAT                       */

    unsigned char   acbcctyp;       /* 19 CONTROL CHARACTER TYPE            */
#define ACBTRCID            0xC0    /* ... 3800 TRANSLATE TABLE (VS1)       */
#define ACBCCASA            0x04    /* ... ASA CONTROL CHARACTERS           */
#define ACBCCMCH            0x02    /* ... MACHINE CONTROL CHARACTERS       */

    unsigned char   acbdsor1;       /* 1A DSORG FIRST BYTE                  */
#define ACBCRNCK            0x80    /* ... NO CHECK BY RESTART FOR
                                           MODIFICATIONS SINCE LAST
                                           CHECKPOINT                       */
#define ACBCRNRE            0x40    /* ... DATA ADDED SINCE LAST CHECKPOINT
                                           NOT ERASED BY RESTART AND NO
                                           REPOSITION TO LAST CHECKPOINT
                                           TAKES PLACE                      */
#define ACBDVIND            0x20    /* ... DEVICE INDICATR                  */
#define ACBOPTJ             0x20    /* ... 3800 CONTROL CHAR PRESENT        */

    unsigned char   acbdsor2;       /* 1B DSORG SECOND BYTE                 */
#define ACBDORGA            0x08    /* ... ACB INDICATOR                    */

    void            *acbmsgar;      /* 1C MSG AREA PTR                      */
    void            *acbpassw;      /* 20 PASSWORD ADDRESS                  */
    void            *acbexlst;      /* 24 USER EXIT LIST ADDRESS            */

    union {
        /*  BEFORE ACB IS OPENED                                            */
        /*  FOR VTAM, ACBDDNM IS INITIALIZED TO X'FF00000000000000')        */
        char    acbddnm[8];         /* 28 DDNAME - MUST BE THE SAME AS THE
                                          NAME FIELD ON THE DD STATEMENT
                                          DEFINING THE DATA SET ASSOCIATED
                                          WITH THIS ACB                     */
        /** AFTER ACB IS OPENED                                             */
        struct {
            unsigned short acbtiot; /* 28 OFFSET FROM TIOT ORIGIN TO THE
                                          TIOELNGH FIELD IN THE TIOT ENTRY
                                          FOR THE DD STATEMENT FOR THIS ACB */
            unsigned char  acbinfl; /* 2A CONTENTS AND MEANING ARE THE SAME
                                          AS ACBINFL1 (BEFORE OPEN)         */

            unsigned char  acbameth;/* 2B ACCESS METHOD TYPE                */
#define ACBVTAM             0x60    /* ... VTAM                             */
#define ACBSUBS             0x41    /* ... SUBSYSTEMS                       */
#define ACBTCAM             0x31    /* ... TCAM                             */
#define ACBRCI              0x23    /* ... JES/RCI                          */
#define ACBRTAM             0x22    /* ... JES/RTAM                         */
#define ACBJAM              0x21    /* ... JES/JAM                          */
#define ACBVSAM             0x11    /* ... VSAM                             */

            unsigned char  acberfl; /* 2C FOR JES, CONTENTS AND MEANING ARE
                                          THE SAME AS ACBERFLG (BEFORE
                                          OPEN) - NOT USED BY VSAM/VTAM     */
            unsigned char  acbdeb[3];/* 2D DEB ADDRESS                      */
        };
    };

    unsigned char   acboflgs;       /* 30 OPEN / CLOSE FLAGS                */
#define ACBEOV              0x20    /* ... EOV CONCATENATION                */
#define ACBOPEN             0x10    /* ... THE ACB IS OPEN                  */
#define ACBDSERR            0x08    /* ... NO FURTHER REQUESTS ARE
                                           POSSIBLE AGAINST THIS ACB        */
#define ACBEXFG             0x02    /* ... USER EXIT FLAG - SET TO 0 BY AN
                                           I/O SUPPORT WHEN A USER EXIT
                                           TAKEN; SET TO 1 ON RETURN        */
#define ACBLOCK             0x02    /* ... ALTERNATE NAME FOR ACBEXFG       */
#define ACBIOSFG            0x01    /* ... OPEN/CLOSE IN CONTROL -
                                           THE ACB IS BEING PROCESSED BY AN
                                           I/O SUPPORT FUNCTION             */
#define ACBBUSY             0x01    /* ... ALTERNATE NAME FOR ACBIOSFG      */

    /*  BEFORE ACB IS OPENED                                                */
    unsigned char   acberflg;       /* 31 ERROR FLAGS - FOR VSAM/VTAM THIS
                                          FIELD IS NOT MOVED BY OPEN AND
                                          ERROR FLAGS ARE RETURNED HERE;
                                          FOR JES THIS FIELD IS MOVED TO
                                          ACBERFL BY OPEN                   */
    /* THE FOLLOWING CODES ARE COMMON TO ALL ACCESS METHODS.                */
#define ACBOALR             0x04    /* ... THE ACB IS ALREADY OPEN          */
#define ACBCALR             0x04    /* ... THE ACB IS NOT OPEN              */

    unsigned char   acbinfl1;       /* 32 FIRST IND FLAGS                   */
    /*             BIT 0 - X'80' MATCHES WITH BIT 0 OF THE DCBMACR FIELD,
                   INDICATING AN EXCP DCB.  THIS BIT IS USED TO
                   DIFFERENTIATE BETWEEN AN ACB AND A DCB AND MUST NEVER
                   BE ASSIGNED IN THE ACB.                                  */
#define ACBJEPS             0x40    /* ... JEPS IS USING THIS ACB           */
#define ACBIJRQE            0x20    /* ... AN RQE IS HELD BY JAM            */
#define ACBCAT              0x10    /* ... ACB FOR VSAM CATALOG             */
#define ACBSCRA             0x08    /* ... CATALOG CONTROL BLOCK
                                           SYSTEM AREA                      */
#define ACBUCRA             0x04    /* ... CATALOG CONTROL BLOCK
                                           USER AREA                        */
#define ACBVVIC             0x02    /* ... DATA SET BEING OPENED
                                           IS SYS1.VVIC                     */
#define ACBSDS              0x02    /* ... OPEN AS SYSTEM DATA SET          */
#define ACBBYPSS            0x01    /* ... BYPASS SECURITY ON OPEN
                                           IF CALLER AUTH                   */

    unsigned char   acbinfl2;       /* 33 2ND IND FLAGS                     */
#define ACBCBIC             0x20    /* ... OPEN WITH CONTROL BLOCKS
                                           IN COMMON STORAGE AREA           */
#define ACBISHRD            0x04    /* ... IGNORE SHR DASD                  */

    /*  NOT MOVED BY OPEN                                                   */
    void            *acbujfcb;      /* 34 USER JFCB ADDRESS                 */

    unsigned        acbbufsp;       /* 38 VIRTUAL CORE AVAILABLE FOR BUFFERS*/
    unsigned short  acbblksz;       /* 3C BLOCKSIZE                         */
    unsigned short  acblrecl;       /* 3E LOGICAL RECORD LENGTH             */

    void            *acbuaptr;      /* 40 USER WORKAREA ADDRESS;
                                          CAXWA ADDRESS FOR CATALOG OPEN    */
    void            *acbcbmwa;      /* 44 CONTROL BLOCK MANIPULATION WORKAREA
                                          ADDRESS                           */
    union {
        void        *acbapid;       /* 48 APPLICATION ID                    */
        void        *acbamax;       /* 48 ACCESS METHOD ACB EXTENSION
                                          ADDRESS(VTAM)                     */
    };
};                                  /* 4C (76 bytes)                        */
#pragma pack(reset)

#pragma pack(1)
struct rpl {
    unsigned char   rplid;          /* 00 RPL IDENTIFIER                    */
#define RPLIDD              0x00    /* ... IDENTIFIER VALUE - X'00'         */

    unsigned char   rplstyp;        /* 01 RPL SUBTYPE - SET TO
                                          X'00' FOR DATA MANAGEMENT AND
                                          X'0D' FOR JECS                    */
#define RPLSVSAM            0x10    /* ... VSAM SUBTYPE                     */
#define RPLSVRP             0x11    /* ... VRP SUBTYPE                      */
#define RPLSVTAM            0x20    /* ... VTAM SUBTYPE                     */
#define RPLS3540            0x40    /* ... 3540 SUBTYPE                     */
#define RPLCRID             0xFF    /* ... CRPL ID (VTAM)                   */

    unsigned char   rplreq;         /* 02 RPL REQUEST TYPE                  */
#define RPLGET              0x00    /* ... GET                              */
#define RPLPUT              0x01    /* ... PUT                              */
#define RPLPOINT            0x03    /* ... POINT                            */
#define RPLERASE            0x05    /* ... ERASE                            */
#define RPLJSFMT            0x07    /* ... JES FORMAT REQUEST               */
    /*  THE FOLLOWING CODES ARE NOT STORED IN RPLREQ, BUT ARE               */
    /*  AVAILABLE IN REGISTER 0 WHEN THE FUNCTION IS ENTERED                */
    /*  AND STORED IN RPLREQ DURING PROCESSING OF THE FUNCTION.             */
#define RPLCHECK            0x02    /* ... CHECK                            */
#define RPLENDRE            0x04    /* ... ENDREQ                           */
#define RPLVERIF            0x06    /* ... VERIFY                           */
#define RPLIMPRT            0x07    /* ... IMPORT                           */
#define RPLPFMTD            0x08    /* ... DATA PREFORMAT                   */
#define RPLPFMTI            0x09    /* ... INDEX PREFORMAT                  */
#define RPLFRCIO            0x0A    /* ... FORCE I/O                        */
#define RPLCNVTA            0x10    /* ... CNVTAD                           */
#define RPLMNTAC            0x11    /* ... MNTACQ(VSAM)                     */
#define RPLWRITE            0x11    /* ... WRITE(VTAM)                      */
#define RPLACQRA            0x12    /* ... ACQRANGE(VSAM)                   */
#define RPLRESET            0x12    /* ... RESET(VTAM)                      */
#define RPLTERM             0x13    /* ... TERMRPL                          */
#define RPLDO               0x13    /* ... DO(VTAM)                         */
#define RPLQUISE            0x15    /* ... SETLOGON(VTAM)                   */
#define RPLSMLGO            0x16    /* ... SIMLOGON(VTAM)                   */
#define RPLOPNDS            0x17    /* ... OPNDST(VTAM)                     */
#define RPLCHNG             0x19    /* ... CHANGE(VTAM)                     */
#define RPLINQIR            0x1A    /* ... INQUIRE(VTAM)                    */
#define RPLINTPT            0x1B    /* ... INTRPRET(VTAM)                   */
#define RPLREAD             0x1D    /* ... READ(VTAM)                       */
#define RPLSLICT            0x1E    /* ... SOLICIT(VTAM)                    */
#define RPLCLOSE            0x1F    /* ... CLSDST(VTAM)                     */
#define RPLCLACB            0x21    /* ... CLOSEACB(VTAM)                   */
#define RPLSNDCD            0x22    /* ... SEND(VTAM)                       */
#define RPLRCVCD            0x23    /* ... RECEIVE(VTAM)                    */
#define RPLRSRCD            0x24    /* ... RESETSR(VTAM)                    */
#define RPLSSCCD            0x25    /* ... SESSIONC(VTAM)                   */
#define RPLSDCMD            0x27    /* ... SENDCMD(VTAM)                    */
#define RPLRVCMD            0x28    /* ... RCVCMD(VTAM)                     */
#define RPLTREQS            0x29    /* ... REQSESS(VTAM)                    */
#define RPLTOPNS            0x2A    /* ... OPNSEC(VTAM)                     */
#define RPLTCLSS            0x2B    /* ... CLSSEC(VTAM)                     */
#define RPLTRMS             0x2C    /* ... TRMSESS(VTAM)                    */

    union {
        unsigned char rpllen;       /* 03 LENGTH OF THIS RPL                */
        unsigned char rpllen2;      /* 03 ALTERNATE NAME FOR RPLLEN         */
    };

    void            *rplplhpt;      /* 04 POINTER TO PLACEHOLDER            */
    void            *rplecb;        /* 08 INTERNAL ECB OR
                                          POINTER TO EXTERNAL ECB           */
    /*  ECB FLAGS                                                           */
#define RPLWAIT             0x80    /* ... A REQUEST HAS BEEN ISSUED        */
#define RPLPOST             0x40    /* ... THE REQUEST HAS COMPLETED        */

    union {
        unsigned    rplfdbwd;       /* 0C FEEDBACK WORD                     */
        struct {
            unsigned char rplstat;  /* 0C CURRENT RPL STATUS                */
#define RPLFUNCD    rplstat         /* ... PROB DET FUNCT CD                */
            unsigned char rplrtncd; /* 0D RPL RETURN CODE                   */
#define RPLNOERR            0x00    /* ... NORMAL RETURN                    */
#define RPLBLKER            0x04    /* ... INVALID CONTROL BLOCK            */
#define RPLCBLKE            0x04    /* ... ALTERNATE NAME FOR RPLBLKER      */
#define RPLLOGER            0x08    /* ... ILLOGICAL REQUEST                */
#define RPLLOGIC            0x08    /* ... ALTERNATE NAME FOR RPLLOGER      */
#define RPLPHYER            0x0C    /* ... PHYSICAL I/O ERROR               */
#define RPLPHYSC            0x0C    /* ... ALTERNATE NAME FOR RPLPHYER      */
#define RPLNGRCC            0x10    /* ... A CONDITIONAL COMMAND WAS ISSUED
                                           BUT THE CONDITION WAS NOT
                                           MET(VTAM)                        */
#define RPLSPECC            0x14    /* ... A TEMPORARY OUT-OF-CORE
                                           SITUATION EXISTS(VTAM)           */
#define RPLCMDRT            0x18    /* ... THE REQUEST WAS CANCELLED BY THE
                                           RESET COMMAND(VTAM)              */
#define RPLPURGE            0x1C    /* ... THE COMMAND WAS PURGED(VTAM)     */
#define RPLVTMNA            0x20    /* ... VTAM IS NOT ACTIVE(VTAM)         */
#define RPLSYERR            0x24    /* ... SYSTEM ERROR(VTAM)               */
#define RPLDEVDC            0x28    /* ... DIAL LINE IS DISCONNECTED(VTAM)  */
#define RPLLIMEX            0x2C    /* ... RESPONSE LIMIT EXCEEDED(VTAM)    */
#define RPLEXRQ             0x30    /* ... EXCEPTION REQUEST RECEIVED(VTAM) */
#define RPLEXRS             0x34    /* ... EXCEPTION RESPONSE RECEIVED(VTAM)*/
#define RPLNOIN             0x38    /* ... NO INPUT AVAILABLE(VTAM)         */
#define RPLVABND            0x3C    /* ... VTAM ENCOUNTERED ABEND CONDITION */
        };
    };

    union {
        unsigned char   rplcmpon;   /* 0E COMPONENT ISSUING CODE(VSAM)      */
        unsigned char   rplfdb2;    /* 0E REASON CODE(VTAM)                 */
#define RPLERLK             0x80    /* ... ERROR LOCK SET                   */
#define RPLRVID             0x40    /* ... RVI RECEIVED                     */
#define RPLATND             0x20    /* ... ATTN RECEIVED                    */
#define RPLDVUNS            0x10    /* ... DEVICE UNUSABLE                  */
#define RPLIOERR            0x08    /* ... I/O ERROR TYPE- 0=INPUT/1=OUTPUT */
#define RPLDLGFL            0x04    /* ... DIALOG INIT FAILED               */
#define RPLCUERR            0x02    /* ... CONTROL UNIT FAILURE             */
#define RPLSTSAV            0x01    /* ... SENSE BYTES PRESENT              */
    };

    union {
        unsigned char   rplerrcd;   /* 0F ERROR CODE(VSAM)                  */
        unsigned char   rplfdb3;    /* 0F DATA FLAGS(VTAM)                  */
#define RPLUINPT            0x80    /* ... UNSOLICITED INPUT                */
#define RPLSV32             0x40    /* ... RESERVED                         */
#define RPLREOB             0x20    /* ... END OF BLOCK                     */
#define RPLREOM             0x10    /* ... END OF MESSAGE                   */
#define RPLREOT             0x08    /* ... END OF TRANSMISSION              */
#define RPLLGFRC            0x04    /* ... LOGOFF DETECTED                  */
#define RPLRLG              0x02    /* ... LEADING GRAPHICS RECEIVED        */
#define RPLRDSOH            0x01    /* ... START OF HEADER (SOH) RECEIVED   */
    };

    union {
        unsigned short  rplkeyle;   /* 10 KEY LENGTH (PROC=GEN)             */
        unsigned short  rplkeyl;    /* 10 ALTERNATE NAME FOR RPLKEYLE       */
    };

    unsigned short  rplstrid;       /* 12 CCW STRING IDENTIFIER             */
    void            *rplcchar;      /* 14 POINTER TO CONTROL CHARACTER FOR
                                          UNIT RECORD DEVICES               */
    void            *rpldacb;       /* 18 POINTER TO DATA ACB               */
    void            *rpltcbpt;      /* 1C POINTER TO TCB                    */
    void            *rplarea;       /* 20 POINTER TO AREA CONTAINING DATA
                                          RECORD                            */
    union {
        void        *rplarg;        /* 24 POINTER TO SEARCH ARGUMENT;
                                          POINTER TO RELATIVE ADDRESS FOR
                                          POINT OPERATION;
                                          POINTER TO SETPRT PARMLIST        */
        struct {
            unsigned char rplsaf[2];/* 24 SOURCE ADDRESS FIELD(VTAM)        */
            unsigned char rpldaf[2];/* 26 DESTINATION ADDRESS FIELD(VTAM)   */
        };
    };

    union {
        unsigned    rploptcd;       /* 28 OPTION CODES                      */
        struct {
            unsigned char rplopt1;  /* 28 OPTION BYTE 1                     */
#define RPLLOC              0x80    /* ... LOCATE MODE; MOVE MODE IF 0      */
#define RPLDIR              0x40    /* ... DIRECT ACCESS                    */
#define RPLSEQ              0x20    /* ... SEQUENTIAL ACCESS                */
#define RPLSKP              0x10    /* ... SKIP SEQUENTIAL ACCESS           */
#define RPLASY              0x08    /* ... ASYNCHRONOUS PROCESSING          */
#define RPLKGE              0x04    /* ... SEARCH KEY GT/EQ                 */
#define RPLGEN              0x02    /* ... GENERIC KEY REQUEST              */
#define RPLECBSW            0x01    /* ... EXTERNAL ECB                     */
#define RPLECBIN            0x01    /* ... ALTERNATE NAME FOR RPLECBSW      */

            unsigned char rplopt2;  /* 29 OPTION BYTE 2                     */
#define RPLKEY              0x80    /* ... KEYED ACCESS                     */
#define RPLADR              0x40    /* ... ADDRESSED ACCESS                 */
#define RPLADD              0x40    /* ... ALTERNATE NAME FOR RPLADR        */
#define RPLCNV              0x20    /* ... CONTROL INTERVAL ACCESS          */
#define RPLBWD              0x10    /* ... FWD=0/BWD=1                      */
#define RPLLRD              0x08    /* ... ARD=0/LRD=1                      */
#define RPLWAITX            0x04    /* ... AYNCH PROC WAIT                  */
#define RPLUPD              0x02    /* ... UPDATE                           */
#define RPLNSP              0x01    /* ... NOTE STRING POSITION             */

            unsigned char rplopt3;  /* 2A OPTION BYTE 3                     */
#define RPLEODS             0x80    /* ... END OF USER SYSOUT               */
#define RPLSFORM            0x40    /* ... SPECIAL FORM ON REMOTE PRINTER   */
#define RPLBLK              0x20    /* ... BLOCKED UCS DATA CHECKS
                                           FIXED BLOCK PROCESSING           */
#define RPLVFY              0x10    /* ... VERIFY UCS/FCB INFORMATION       */
#define RPLFLD              0x08    /* ... LOAD UCS BUFFER IN FOLD MODE     */
#define RPLFMT              0x02    /* ... FCB LOAD                         */
#define RPLFRMT             0x06    /* ... UCS LOAD IF 00                   */
#define RPLALIGN            0x01    /* ... ALIGN FCB BUFFER LOADING         */

        unsigned char rplopt4;      /* 2B OPTCD BYTE 4                      */
#define RPLENDTR            0x80    /* ... 3800 END OF TRANSMISSION(VS1)    */
#define RPLMKFRM            0x40    /* ... 3800 MARK FORM  (VS1)            */
    /* NO MORE THAN ONE OF THE FOLLOWING THREE BITS CAN BE ON.              */
    /* ONE OF THEM IS SET ONLY WHEN ACBCCANY IS ON AND THE                  */
    /* OPERATION IS INPUT.                                                  */
#define RPLCTA              0x10    /* ... RPLCCHAR POINTS TO AN ANSI
                                           CONTROL CHARACTER                */
#define RPLCTM              0x08    /* ... RPLCCHAR POINTS TO A MACHINE
                                           CONTROL CHARACTER                */
#define RPLCTO              0x04    /* ... OTHER FORMAT.
                                           RPLCCHAR POINTS TO A CODE BYTE
                                           THAT IDENTIFIES THE FORMAT.
                                           A CODE OF X'5A' MEANS CPDS.      */
        };
    };

    union {
        RPL             *rplnxtrp;  /* 2C POINTER TO NEXT RPL               */
        RPL             *rplchain;  /* 2C ALTERNATE NAME FOR RPLNXTRP       */
    };

    unsigned            rplrlen;    /* 30 LENGTH OF RECORD                  */
    unsigned            rplbufl;    /* 34 USER BUFFER LENGTH                */

    union {
        unsigned        rploptc2;   /* 38 VTAM OPTIONS                      */
        struct {
            unsigned char rplopt5;  /* 38 OPTION BYTE 5                     */
#define RPLDLGIN            0x80    /* ... CONTINUE READING IN SPECIFIC
                                           TERMINAL MODE; IF 0, CONTINUE
                                           READING IN ANY TERMINAL MODE     */
#define RPLSSNIN            0X40    /* ... CONTINUE DIALOG WITH THE SAME
                                           TERMINAL; IF 0, END DIALOG WITH
                                           THAT TERMINAL                    */
#define RPLPSOPT            0x20    /* ... PASS TERMINAL TO REQUESTING
                                           APPLICATION; IF 0, MAKE TERMINAL
                                           AVAILABLE TO ANY APPLICATION     */
#define RPLNERAS            0x10    /* ... WRITE TO 3270 BUT DO NOT ERASE
                                           WHAT IS CURRENTLY DISPLAYED      */
#define RPLEAU              0x08    /* ... WRITE TO 3270 AND ERASE
                                           UNPROTECTED FIELDS               */
#define RPLERACE            0x04    /* ... WRITE TO 3270 AND ERASE
                                           CURRENT DISPLAY                  */
#define RPLNODE             0x02    /* ... READ FROM ANY TERMINAL; IF 0,
                                           READ FROM A SPECIFIC TERMINAL    */
#define RPLWROPT            0x01    /* ... CONVERSATIONAL MODE; IF 0,
                                           NON-CONVERSATIONAL MODE          */

            unsigned char rplopt6;  /* 39 OPTION BYTE 6                     */
#define RPLEOB              0x80    /* ... WRITE A BLOCK OF DATA            */
#define RPLEOM              0x40    /* ... WRITE THE LAST BLOCK OF A MESSAGE*/
#define RPLEOT              0x20    /* ... WRITE THE LAST BLOCK OF THE
                                           TRANSMISSION                     */
#define RPLCOND             0x10    /* ... DO NOT STOP OPERATION IF STARTED
                                           (USED WITH RESET REQUEST)        */
#define RPLNCOND            0x08    /* ... STOP OPERATION IMMEDIATELY
                                           (USED WITH RESET REQUEST)        */
#define RPLLOCK             0x04    /* ... RESET ERROR LOCK TO UNLOCKED
                                           STATUS                           */
#define RPLRSV67            0x02    /* ... RESERVED                         */
#define RPLRSV68            0x01    /* ... RESERVED                         */

            unsigned char rplopt7;  /* 3A OPTION BYTE 7                     */
#define RPLCNALL            0x80    /* ... ALL TERMINALS IN OPNDST LIST MUST
                                           BE AVAILABLE BEFORE ANY ARE
                                           CONNECTED                        */
#define RPLCNANY            0x40    /* ... CONNECT ANY ONE TERMINAL IN
                                           OPNDST LIST                      */
#define RPLCNIMM            0x20    /* ... RESERVED                         */
#define RPLQOPT             0x10    /* ... QUEUE THE OPNDST REQUEST IF IT
                                           CANNOT BE SATISFIED IMMEDIATELY;
                                           IF 0, REJECT THE OPNDST REQUEST
                                           IF IT CANNOT BE SATISFIED
                                           IMMEDIATELY                      */
#define RPLTPOST            0x08    /* ... RPL ALREADY UNDER PSS            */
#define RPLRLSOP            0x04    /* ... SCHEDULE THE RELREQ EXIT OF THE
                                           REQUIRED TERMINAL IMMEDIATELY;
                                           IF 0, EITHER WAIT FOR THE TERMINAL
                                           TO BECOME AVAILABLE OR REJECT THE
                                           REQUEST IF THE TERMINAL IS BUSY
                                           (DEPENDS ON THE SETTING OF
                                           RPLQOPT)                         */
#define RPLTCRNO            0x02    /* ... CLOSE IN PROCESS FOR PO INTERFACE*/
#define RPLRSV78            0x01    /* ... RESERVED                         */

            unsigned char rplopt8;  /* 3B OPTION BYTE 8                     */
#define RPLODACQ            0x80    /* ... THE APPLICATION REQUIRES
                                           A SPECIFIC TERMINAL              */
#define RPLODACP            0x40    /* ... THE APPLICATION WILL ACCEPT ANY
                                           TERMINAL DESIRING LOGON          */
#define RPLODPRM            0x20    /* ... A SPECIFIC TERMINAL IS TO BE
                                           PREEMPTED EVEN THOUGH ANOTHER
                                           APPLICATION IS HOLDING
                                           IT (TOLTEP ONLY)                 */
#define RPLPEND             0x10    /* ... PREEMPT THE TERMINAL AFTER ALL
                                           PENDING OPERATIONS ARE COMPLETED
                                           (TOLTEP ONLY)                    */
#define RPLSESS             0x08    /* ... PREEMPT THE TERMINAL AFTER
                                           COMPLETION OF THE CURRENT DIALOG
                                           SESSION (TOLTEP ONLY)            */
#define RPLACTV             0x04    /* ... PREEMPT THE TERMINAL IF CONNECTED
                                           BUT NOT BUSY (TOLTEP ONLY)       */
#define RPLUNCON            0x02    /* ... PREEMPT THE TERMINAL IMMEDIATELY
                                           (TOLTEP ONLY)                    */
#define RPLRSV88            0x01    /* ... RESERVED                         */
        };
    };

    union {
        unsigned char   rplrbar[8]; /* 3C RBA RETURN LOCATION               */
        struct {
            unsigned char rplaixpc[2];/* 3C AIX POINTER COUNT               */
            unsigned char rplaixid; /* 3E AIX POINTER TYPE                  */
#define RPLAXPKP            0x80    /* ... RBA=1/PRIME=0                    */
            unsigned char unused1;  /* 3F RESERVED                          */
            unsigned char rpldddd[4];/* 40 RETURN AREA FOR RELATIVE BYTE
                                           ADDRESS                          */
        };
    };

    union {
        unsigned char   rplextds;   /* 44 EXIT DEFINITIONS                  */
        unsigned char   rplextd1;   /* 44 ALTERNATE NAME FOR RPLEXTDS       */
#define RPLEXSCH            0x80    /* ... AN EXIT HAS BEEN SCHEDULED       */
#define RPLNEXIT            0x40    /* ... NO EXIT WAS SPECIFIED            */
#define RPLEXIT             0x20    /* ... ASYNCH EXIT                      */
#define RPLTCRYP            0x08    /* ... IF ON, ENCRYPTION FEATURE REQ    */
#define RPLNIB              0x04    /* ... THE RPLARG FIELD CONTAINS A
                                           POINTER TO THE NIB               */
#define RPLBRANC            0x02    /* ... USE A BRANCH ENTRY TO THE MACRO  */
    };

    unsigned char   rplactiv;       /* 45 ACTIVE INDICATOR -
                                          X'FF' INDICATES ACTIVE;
                                          X'00' INDICATES INACTIVE          */

    unsigned short  rplemlen;       /* 46 LENGTH OF THE ERROR MESSAGE AREA  */
    void            *rplermsa;      /* 48 POINTER TO THE ERROR MESSAGE AREA */
};                                  /* 4C (76 bytes)                        */
#pragma pack(reset)

#pragma pack(1)
struct shwpl {                      /* SHOW CATALOG INPUT MAPPING           */
    unsigned char   shwflgs;        /* 00 FIRST SHOW CAT FLAGS              */
#define SHWNAME             0x80    /* ... 1 - NAME SPECIFIED
                                           0 - CI SPECIFIED                 */
    unsigned char   unsused[3];     /* 01 RESERVED                          */
    void            *shwent;        /* 04 NAME/CI ENTRY ADDRESS             */
    ACB             *shwacb;        /* 08 ACB ADDRESS                       */
    void            *shwarea;       /* 0C RETURN AREA ADDRESS               */
};                                  /* 10 (16 bytes)                        */
#pragma pack(reset)

#pragma pack(1)
struct shwout {                     /* SHOW CATALOG OUTPUT MAPPING          */
    unsigned short  shwlen1;        /* 00 CALLER WORK AREA LENGTH           */
    unsigned short  shwlen2;        /* 02 WORK AREA LENGTH REQUIRED BY
                                          VSAM SHOW CATALOG                 */
    ACB             *shwacbp;       /* 04 VSAM CATALOG ACB ADDRESS          */
    unsigned char   shwtype;        /* 08 ENTRY TYPE                        */
                                    /* ... C    Cluster                     */
                                    /* ... G    Alternate index             */
                                    /* ... R    Path                        */
                                    /* ... Y    Upgrade set                 */
    unsigned char   shwattr;        /* 09 PATH/AIX ATTRIBUTES               */
#define SHWUP               0x80    /* ... UPDATE PATH/UPGRADE
                                           MEMBERSHIP INDICATOR             */
    unsigned short  shwact;         /* 0A ASSOCIATION COUNT                 */
    char            shwass[0];      /* 0C ASSOCIATIONS BEGIN HERE -
                                          NOT D OR I                        */
};

struct shwoutdi {                   /* SHOW CATALOG OUTPUT MAPPING (D or I) */
    unsigned short  shwlen1;        /* 00 CALLER WORK AREA LENGTH           */
    unsigned short  shwlen2;        /* 02 WORK AREA LENGTH REQUIRED BY
                                          VSAM SHOW CATALOG                 */
    ACB             *shwacbp;       /* 04 VSAM CATALOG ACB ADDRESS          */
    unsigned char   shwtype;        /* 08 ENTRY TYPE                        */
                                    /* ... D    Data component              */
                                    /* ... I    Index                       */
    unsigned char   unused;         /* 09 reserved                          */
    unsigned short  shwdsb;         /* 0A AMDSB FIELDS FOR D OR I           */


    unsigned short  shwkeyln;       /* 0C KEY LENGTH                        */
    unsigned char   shwcisz[4];     /* 0E CI SIZE                       FL4 */
    unsigned char   shwmrec[4];     /* 12 MAX RECORD SIZE               FL4 */
    unsigned short  shwact;         /* 16 ASSOCIATION COUNT                 */
    char            shwass[0];      /* 18 ASSOCIATIONS BEGIN HERE -
                                          D OR I                            */
};
#pragma pack(reset)

#pragma pack(1)
struct shwassoc {                   /* SHOW CATALOG OUTPUT MAPPING          */
    unsigned char   shwatype;       /* 00 ASSOCIATION TYPE                  */
    unsigned char   shwaci[3];      /* 01 ASSOCIATION CI NUMBER             */
};
#pragma pack(reset)

/* __vsshwc() - issue SHOWCAT for name, ACB is optional, info returned in buf*/
extern int  __vsshwc(ACB *acb, const char *name, char *buf, int buflen);


/* VSFILE handle for accessing VSAM datasets
** Note: keep this struct sync'd with VSFILE DSECT in CLIBVSFI.COPY
*/
#pragma pack(1)
struct vsfile {
    char                eye[8];     /* 00 eye catcher for dumps             */
#define VSFILE_EYE      "*VSFILE*"  /* ...                                  */
    char                ddname[8];  /* 08 DD Name                           */
    char                zero;       /* 10 zero byte                         */
    unsigned char       flags;      /* 11 flags                             */
#define VSFILE_FLAG_OPEN    0x80    /* ... VSAM cluster is open             */
#define VSFILE_FLAG_STARTGE 0x40    /* ... start greater then or equal      */
#define VSFILE_FLAG_WRITE   0x20    /* ... write record                     */
#define VSFILE_FLAG_ERROR   0x02    /* ... Error has occured                */
#define VSFILE_FLAG_EOF     0x01    /* ... EOF has occured                  */
    unsigned char       rc;         /* 12 VSAM return code                  */
    unsigned char       rsn;        /* 13 VSAM reason code                  */
    unsigned char       component;  /* 14 VSAM component                    */
    unsigned char       type;       /* 15 VSTYPE                            */
    unsigned char       access;     /* 16 VSACCESS                          */
    unsigned char       mode;       /* 17 VSMODE                            */
    ACB                 acb;        /* 18 Access Control Block              */
    unsigned            avail;      /* 64 available                         */
    RPL                 rpl;        /* 68 Request Parameter List            */
                                    /* *** MVSGCC align to double work ***  */
    void                *vsself;    /* B8 pointer to self, used in __vserr  */
    void                *vsreset;   /* BC reset function (called by __vserr)*/
};                                  /* A0 (192 bytes)                       */
#pragma pack(reset)

enum vstype {
    VSTYPE_KSDS=0,                  /* keyed sequential dataset     (key)   */
    VSTYPE_ESDS,                    /* entry sequenced dataset      (rba)   */
    VSTYPE_RRDS                     /* relative record number       (rrn)   */
};

enum vsaccess {
    VSACCESS_DIR=0,                 /* direct access                        */
    VSACCESS_SEQ,                   /* sequential access                    */
    VSACCESS_DYNAM,                 /* dynamic access                       */
    VSACCESS_ADR                    /* address access                       */
};

enum vsmode {
    VSMODE_IN=0,                    /* input (read only)                    */
    VSMODE_OUT,                     /* output (write only)                  */
    VSMODE_UPD                      /* update (read and write)              */
};

/* __vsopen() - open VSAM cluster */
extern int  __vsopen(const char *dd, VSTYPE, VSACCESS, VSMODE, VSFILE **vsfile);
extern int  vsopen(const char *dd, VSTYPE, VSACCESS, VSMODE, VSFILE **vsfile);

/* __vsclos() - close VSAM cluster */
extern int  __vsclos(VSFILE *vs);
extern int  vsclose(VSFILE *vs);

/* __vsmdfy() - resets common attributes, key's and record's */
extern int  __vsmdfy(VSFILE *vs, void *rec, int reclen, void *key, int keylen);

/* __vsread() - read record, return record length read, -1=EOF, -2=Error */
extern int  __vsread(VSFILE *vs, void *rec, int reclen, void *key, int keylen);
extern int  vsread(VSFILE *vs, void *rec, int reclen, void *key, int keylen);

/* __vswrit() - write record, return 0=success, otherwise PUT error */
extern int  __vswrit(VSFILE *vs, void *rec, int reclen, void *key, int keylen);
extern int  vswrite(VSFILE *vs, void *rec, int reclen, void *key, int keylen);

/* __vsupdt() - update record, return 0=success, otherwise PUT error */
extern int  __vsupdt(VSFILE *vs, void *rec, int reclen);
extern int  vsupdate(VSFILE *vs, void *rec, int reclen);

/* __vsdel() - delete record, return 0=success, otherwise ERASE error */
extern int  __vsdel(VSFILE *vs, void *rec, int reclen);
extern int  vsdelete(VSFILE *vs, void *rec, int reclen);

/* __vssteq() - start key =, return 0=success, otherwise POINT error */
extern int  __vssteq(VSFILE *vs, void *rec, int reclen, void *key, int keylen);
extern int  vssteq(VSFILE *vs, void *rec, int reclen, void *key, int keylen);

/* __vsstge() - start key >=, return 0=success, otherwise POINT error */
extern int  __vsstge(VSFILE *vs, void *rec, int reclen, void *key, int keylen);
extern int  vsstge(VSFILE *vs, void *rec, int reclen, void *key, int keylen);

/* __vstell() - get RBA for last I/O operation */
extern unsigned __vstell(VSFILE *vs);
extern unsigned vstell(VSFILE *vs);

/* __vsclr() - reset Error and EOF flags in VSFILE handle */
extern int  __vsclr(VSFILE *vs);
extern int  vsclear(VSFILE *vs);

/* __vseof() - returns 1 if EOF has occured, otherwise 0 */
extern int  __vseof(VSFILE *vs);
extern int  vseof(VSFILE *vs);

/* __vserr() - returns 1 if Error has occured, otherwise 0 */
extern int  __vserr(VSFILE *vs);
extern int  vserror(VSFILE *vs);

/* __vslrec() - return logical record length of data component records */
extern unsigned __vslrec(VSFILE *vs);
extern unsigned vslrecl(VSFILE *vs);

/* __vscinv() - return control interval size of data component */
extern unsigned __vscinv(VSFILE *vs);
extern unsigned vscinv(VSFILE *vs);

#endif
