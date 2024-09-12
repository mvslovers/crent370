#ifndef OSJFCB_H
#define OSJFCB_H

#include "osdcb.h"

typedef struct jfcb     JFCB;       /* Job File Control Block               */

#pragma pack(1)
struct jfcb {
    char            jfcbdsnm[44];   /* 00 DATA SET NAME                     */
    char            jfcbelnm[8];    /* 2C ELEMENT NAME OR RELATIVE GENERATION
                                          NUMBER.
                                          TYPE OF AREA (INDEX, PRIME OR
                                          OVERFLOW) FOR AN INDEXED SEQUENTIAL
                                          DATA SET ONLY.                    */
    char            jfcbtsdm;       /* 34 JOB MANAGEMENT/DATA MANAGEMENT
                                          INTERFACE                         */
#define JFCCAT      0x80            /* ... DATA SET IS CATALOGED            */
#define JFCVSL      0x40            /* ... VOLUME SERIAL LIST HAS BEEN
                                           CHANGED                          */
#define JFCSDS      0x20            /* ... DATA SET IS A SYSIN OR SYSOUT
                                           DATA SET                         */
#define JFCTTR      0x10            /* ... A JOB STEP IS TO BE RESTARTED.
                                           USE JFCBOTTR INSTEAD OF DS1LSTAR
                                           FIELD TO REPOSITION DATA SET
                                           IF AUTOMATIC STEP RESTART OCCURS.
                                           (THIS JOB HAD ABEND PROCESSING
                                           FOR A DATA SET OPENED FOR MOD.)  */
#define JFCNWRIT    0x08            /* ... DO NOT WRITE BACK THE JFCB DURING
                                           OPEN PROCESSING                  */
#define JFCNDSCB    0x04            /* ... DO NOT MERGE DSCB OR LABEL FIELDS
                                           INTO THIS JFCB                   */
#define JFCNDCB     0x02            /* ... DO NOT MERGE DCB FIELDS INTO
                                           THIS JFCB                        */
#define JFCPAT      0x01            /* ... THE PATTERNING DSCB IS COMPLETE  */
    char            jfcbdscb[3];    /* 35 TTR ADDRESS OF THE FORMAT 1 DSCB
                                          FOR DATA SET PART ON THE FIRST
                                          VOLUME OF THE DATA SET            */
    char            jfcamcro[2];    /* 38 VSAM CHECKPOINT/RESTART OPTION
                                          INDICATORS                        */
    unsigned short  jfcamstr;       /* 3A NUMBER OF STRINGS                 */
    unsigned short  jfcbadbf;       /* 3C NUMBER OF DATA BUFFERS            */
    unsigned short  jfcnlrec;       /* 3E LOGICAL RECORD LENGTH FOR VSAM    */
    unsigned short  jfcvindx;       /* 40 MASS STORAGE SYSTEM COMMUNICATOR
                                          (MSSC) VOLUME SELECTION INDEX     */
    char            jfcbltyp;       /* 42 LABEL TYPE                        */
#define JFCRSV38    0x80            /* ... RESERVED                         */
#define JFCBAL      0x40            /* ... AMERICAN NATIONAL STANDARD TAPE
                                           LABELS (AL OR IF BIT 4 IS ALSO ON,
                                           AUL)                             */
#define JFCBLTM     0x20            /* ... UNLABELLED TAPE CREATED BY DOS
                                           MAY HAVE LEADING TAPE MARK.
                                           OPEN/CLOSE/EOV AND RESTART
                                           MUST SPACE OVER A TAPE MARK
                                           IF ONE EXISTS.                   */
#define JFCBLP      0x10            /* ... BYPASS LABEL PROCESSING          */
#define JFCSUL      0x0A            /* ... USER LABEL                       */
#define JFCNSL      0x04            /* ... NONSTANDARD LABEL                */
#define JFCSL       0x02            /* ... STANDARD LABEL                   */
#define JFCNL       0x01            /* ... NO LABEL                         */
    char            jfcbottr[3];    /* 43 DASD MOD DATA SET - IF AUTOMATIC
                                          STEP RESTART WAS REQUESTED, TTR
                                          OF THE END-OF-DATA INDICATOR
                                          EXISTING WHEN THE DATA SET WAS
                                          FIRST OPENED DURING THE ORIGINAL
                                          EXECUTION OF THE CURRENT STEP     */
#define jfcbufof    jfcbottr[0]     /* 43 TAPE DATA SET - THIS FIELD CONTAINS
                                          THE BUFFER OFFSET (DCB SUBPARAMETER
                                          VALUE)                            */
#define JFCBFOFL    0x80            /* ... IF 1, THE OFFSET EQUALS FOUR AND
                                           THE BUFFER OFFSET FIELD OF EACH
                                           BLOCK (D-FORMAT RECORDS) CONTAINS
                                           THE BLOCK LENGTH (SPECIFIED BY
                                           BUFOFF=L).
                                           IF 0, THE OFFSET IS AS SPECIFIED
                                           IN THE REMAINING SEVEN BITS AND
                                           THE BUFFER OFFSET FIELD OF EACH
                                           BLOCK DOES NOT CONTAIN THE BLOCK
                                           LENGTH.                          */
#define jfcfunc     jfcbottr[1]     /* 44 FUNCTION INDICATORS FOR THE 3525
                                          CARD PUNCH (SPECIFIED BY THE FUNC
                                          PARAMETER)                        */
#define JFCFNCBI    0x80            /* ... I - INTERPRET (PUNCH AND PRINT
                                           TWO LINES)                       */
#define JFCFNCBR    0x40            /* ... R - READ                         */
#define JFCFNCBP    0x20            /* ... P - PUNCH                        */
#define JFCFNCBW    0x10            /* ... W - PRINT                        */
#define JFCFNCBD    0x08            /* ... D - DATA PROTECTION              */
#define JFCFNCBX    0x04            /* ... X - THIS DATA SET IS TO BE
                                           PRINTED.  THIS MAY BE CODED WITH
                                           PW OR RPW TO DISTINGUISH THE DATA
                                           SET TO BE PRINTED FROM THE DATA
                                           SET TO BE PUNCHED.               */
#define JFCFNCBT    0x02            /* ... T - TWO-LINE PRINT SUPPORT REQUEST.
                                           THE SECOND PRINT LINE IS LOCATED
                                           ON CARD LINE THREE.              */
#define JFCRSV31    0x01            /* ... RESERVED                         */
#define jfcbflsq    jfcbottr[1]     /* 44 FOR MAGNETIC TAPE DEVICES, FILE
                                          SEQUENCE NUMBER (2 bytes)         */
    unsigned short  jfcbvlsq;       /* 46 VOLUME SEQUENCE NUMBER            */

    char    jfcbmask[8];            /* 48 DATA MANAGEMENT MASK              */
#define jfcbops1    jfcbmask        /* 48 OPEN ROUTINE INTERNAL SWITCHES
                                          (5 bytes)                         */
#define jfcbflg1    jfcbmask[5]     /* 4D FLAG BYTE                         */
#define JFCSTAND    0x80            /* ... VOLUME LABEL PROCESSING STANDARD */
#define JFCSLCRE    0x40            /* ... CREATION OF A STANDARD LABEL IS
                                           NECESSARY                        */
#define JFCSLDES    0x20            /* ... DESTRUCTION OF A STANDARD LABEL
                                           IS NECESSARY                     */
#define JFCDUAL     0x10            /* ... DUAL-DENSITY CHECK DETECTED      */
#define JFCOPEN     0x0F            /* ... OPEN ROUTINE INTERNAL SWITCHES   */
#define JFCBPWBP    0x01            /* ... PASSWORD BYPASS INDICATOR        */

#define jfcbflg2    jfcbmask[6]     /* 4E FLAG BYTE OF OPEN SWITCHES        */
#define JFCINOP     0x80            /* ... TREAT THE INOUT OPTION OF OPEN
                                           AS INPUT                         */
#define JFCOUTOP    0x40            /* ... TREAT THE OUTIN OPTION OF OPEN
                                           AS OUTPUT                        */
#define JFCDEFER    0x20            /* ... SET ONLY IN A JFCB RECORDED IN A
                                           DATA SET DESCRIPTOR RECORD (DSDR)
                                           BY THE CHECKPOINT ROUTINE.
                                           INDICATES THAT THE DATA SET RELATED
                                           TO THE JFCB IS BEING PROCESSED
                                           SEQUENTIALLY, AT THE CHECKPOINT,
                                           ON A VOLUME OTHER THAN THE VOLUME
                                           ON WHICH PROCESSING BEGAN IN THE
                                           CURRENT STEP.  WHEN RESTART OCCURS,
                                           THIS BIT CAUSES DEFERRED VOLUME
                                           MOUNTING.                        */
#define JFCNRPS     0x20            /* ... USE BY OPEN ROUTINES - SET TO
                                           INDICATE THAT THIS DATA SET
                                           RESIDES ON A NON-RPS DEVICE.
                                           RESET TO ZERO WHEN OPEN PROCESSING
                                           IS COMPLETED.                    */
#define JFCMODNW    0x10            /* ... DISPOSITION OF THIS DATA SET HAS
                                           BEEN CHANGED FROM MOD TO NEW.
                                           DISPOSITION (IN JFCBIND2) WILL BE
                                           RESTORED TO MOD AFTER OPEN.      */
#define JFCSDRPS    0x08            /* ... USE SEARCH DIRECT FOR ROTATIONAL
                                           POSITION SENSING (RPS) DEVICES   */
#define JFCTRACE    0x04            /* ... GTF TRACE IS TO OCCUR DURING
                                           OPEN/CLOSE/EOV AND DYNAMIC
                                           ALLOCATION PROCESSING OF DCB     */
#define JFCBBUFF    0x02            /* ... INDICATOR TO OPEN THAT A NON-ZERO
                                           VALUE IN JFCBOTTR IS NOT TO
                                           PREVENT THE NORMAL STORING BY
                                           OPEN OF A TTR IN JFCBOTTR.
                                           BEFORE OPEN - JFCBUFOF (OFFSET 67)
                                           CONTAINS A BUFFER OFFSET OR INVALID
                                           INFORMATION RESULTING FROM A
                                           JFCB-TO-JFCB MERGE.
                                           AFTER OPEN - OPEN MAY HAVE STORED
                                           A TTR IN JFCBOTTR (OFFSET 67), IN
                                           WHICH CASE OPEN WILL HAVE SET THIS
                                           BIT TO ZERO.                     */
#define JFCRCTLG    0x01            /* ... OPEN HAS UPDATED THE TTR.
                                           SCHEDULER STEP TERMINATION ROUTINE
                                           IS TO RECATALOG THIS DATA SET AND
                                           PLACE IN THE CATALOG ENTRY THE DSCB
                                           TTR CONTAINED IN JFCBDSCB IF THIS
                                           DATA SET IS CATALOGED.           */

#define jfcbops2    jfcbmask[7]     /* 4F OPEN ROUTINE INTERNAL SWITCHES    */

    char            jfcbcrdt[3];    /* 50 DATA SET CREATION DATE
                                          (YDD, Y=YEAR AND DD=DAY)          */
    char            jfcbxpdt[3];    /* 53 DATA SET EXPIRATION DATE (YDD)    */
    char            jfcbind1;       /* 56 INDICATOR BYTE 1                  */
#define JFCRLSE     0xC0            /* ... RELEASE EXTERNAL STORAGE         */
#define JFCLOC      0x30            /* ... DATA SET HAS BEEN LOCATED        */
#define JFCADDED    0x0C            /* ... NEW VOLUME HAS BEEN ADDED TO THE
                                           DATA SET                         */
#define JFCGDG      0x02            /* ... DATA SET IS A MEMBER OF A
                                           GENERATION DATA GROUP            */
#define JFCPDS      0x01            /* ... DATA SET IS A MEMBER OF A
                                           PARTITIONED DATA SET             */

    char            jfcbind2;       /* 57 INDICATOR BYTE 2                  */
#define JFCDISP     0xC0            /* ... BIT PATTERN FOR NEW, MOD, OLD    */
#define JFCNEW      0xC0            /* ... NEW DATA SET                     */
#define JFCMOD      0x80            /* ... MOD DATA SET                     */
#define JFCOLD      0x40            /* ... OLD DATA SET                     */
#define JFCBRWPW    0x30            /* ... PASSWORD IS REQUIRED TO WRITE BUT
                                           NOT TO READ (DATA SET SECURITY)  */
#define JFCSECUR    0x10            /* ... PASSWORD IS REQUIRED TO READ OR
                                           TO WRITE (DATA SET SECURITY)     */
#define JFCSHARE    0x08            /* ... SHARED DATA SET                  */
#define JFCENT      0x04            /* ... DELETE THIS JFCB BEFORE ALLOCATION
                                           FOR A RESTARTED GENERATION DATA
                                           GROUP                            */
#define JFCREQ      0x02            /* ... STORAGE VOLUME REQUESTED         */
#define JFCTEMP     0x01            /* ... TEMPORARY DATA SET               */


    char            jfcbufno;       /* 58 NUMBER OF BUFFERS REQUIRED FOR THIS
                                          DATA SET (ACCESS METHODS OTHER THAN
                                          TCAM AND QTAM)                    */
    char            jfcbgncp;       /* 59 FOR GAM, THIS FIELD IS USED FOR THE
                                          NUMBER OF IOB'S CONSTRUCTED BY THE
                                          OPEN ROUTINE. MAXIMUM NUMBER IS 99.*/
#define jfcbhiar    jfcbgncp        /* 59 BUFFER POOL LOCATION IN MAIN STORAGE
                                          (HIERARCHY)                       */
#define jfcbfaln    jfcbgncp        /* 59 BUFFER ALIGNMENT                  */
#define jfcbftek    jfcbgncp        /* 59 BUFFERING TECHNIQUE               */
#define JFCHIER     0x84            /* ... BITS 0 AND 5 DESCRIBE MAIN STORAGE
                                           HIERARCHY.
                                           BOTH BITS OFF, HIERARCHY 0.
                                           BIT 0 OFF AND BIT 5 ON, HIERARCHY 1.
                                                                            */
#define JFCSIM      0x40            /* ... S - SIMPLE BUFFERING             */
#define JFCBBFTA    0x60            /* ... A - FOR QSAM LOCATE MODE
                                           PROCESSING OF SPANNED RECORDS,
                                           AUTOMATIC RECORD AREA CONSTRUCTION
                                           DURING LOGICAL RECORD INTERFACE
                                           PROCESSING.
                                           OPEN IS TO CONSTRUCT A RECORD AREA
                                           IF IT AUTOMATICALLY CONSTRUCTS
                                           BUFFERS.                         */
#define JFCBBFTR    0x20            /* ... R - FOR BSAM CREATE BDAM PROCESSING
                                           OR BDAM PROCESSING OF UNBLOCKED
                                           SPANNED RECORDS, SOFTWARE TRACK
                                           OVERFLOW.
                                           OPEN FORMS A SEGMENT WORK AREA
                                           POOL AND STORES THE ADDRESS OF THE
                                           SEGMENT WORK AREA CONTROL BLOCK
                                           IN THE DCBEOBW FIELD OF THE DATA
                                           CONTROL BLOCK.
                                           WRITE USES A SEGMENT WORK AREA TO
                                           WRITE A RECORD AS ONE OR MORE
                                           SEGMENTS.
                                           FOR BSAM INPUT PROCESSING OF
                                           UNBLOCKED SPANNED RECORDS WITH
                                           KEYS, RECORD OFFSET PROCESSING.
                                           READ READS ONE RECORD SEGMENT
                                           INTO THE RECORD AREA.
                                           THE FIRST SEGMENT OF A RECORD IS
                                           PRECEDED IN THE RECORD AREA BY
                                           THE KEY.
                                           SUBSEQUENT SEGMENTS ARE AT AN
                                           OFFSET EQUAL TO THE KEY LENGTH.  */
#define JFCEXC      0x10            /* ... E - EXCHANGE BUFFERING           */
#define JFCDYN      0x08            /* ... DYNAMIC BUFFERING                */
#define JFCHIER1    0x04            /* ... HIERARCHY 1 MAIN STORAGE         */
#define JFCDWORD    0x02            /* ... D - DOUBLE WORD BOUNDARY         */
#define JFCFWORD    0x01            /* ... F - FULL WORD NOT A DOUBLE WORD
                                           BOUNDARY                         */
    unsigned short  jfcbufl;        /* 5A BUFFER LENGTH (2 bytes)           */
    char            jfceropt;       /* 5C ERROR OPTION.  DISPOSITION OF
                                          PERMANENT ERRORS IF USER RETURNS
                                          FROM A SYNCHRONOUS ERROR EXIT.
                                          (QSAM)                            */
#define JFCACC      0x80            /* ... ACCEPT                           */
#define JFCSKP      0x40            /* ... SKIP                             */
#define JFCABN      0x20            /* ... ABNORMAL END OF TASK             */
#define JFCTOPT     0x10            /* ... ON-LINE TERMINAL TEST (BTAM)     */

    char            jfckeyle;       /* 5D DIRECT ACCESS KEY LENGTH          */
#define jfcprtsp    jfckeyle        /* 5D NORMAL PRINTER SPACING            */
#define JFCSPTHR    0x19            /* ... 3 - SPACE THREE LINES            */
#define JFCSPTWO    0x11            /* ... 2 - SPACE TWO LINES              */
#define JFCSPONE    0x09            /* ... 1 - SPACE ONE LINE               */
#define JFCSPNO     0x01            /* ... 0 - NO SPACING                   */

    char            jfcden;         /* 5E TAPE DENSITY - 2400/3400 SERIES
                                          MAGNETIC TAPE UNITS               */
#define JFC200      0x03            /* ... 7-TRACK 200 BPI                  */
#define JFC556      0x43            /* ... 7-TRACK 556 BPI                  */
#define JFC800      0x83            /* ... 7-TRACK AND 9-TRACK 800 BPI      */
#define JFC1600     0xC3            /* ... 9-TRACK 1600 BPI                 */
#define JFC6250     0xD3            /* ... 9-TRACK 6250 BPI                 */

    char            jfcbabfs[3];    /* 5F TOTAL BUFFER SIZE FOR ALL VSAM
                                          BUFFERS                           */
#define jfclimct    jfcbabfs        /* 5F SEARCH LIMIT (BDAM)               */
#define jfctrkbl    jfcbabfs[1]     /* 60 DATA SET OPENED FOR MOD - IF
                                          AUTOMATIC STEP RESTART WAS REQUESTED,
                                          TRACK BALANCE EXISTING WHEN THE
                                          DATA SET WAS FIRST OPENED DURING
                                          THE ORIGINAL EXECUTION OF THE
                                          CURRENT STEP                      */
    union {
        unsigned short jfcdsorg;    /* 62 DATA SET ORGANIZATION BEING USED  */
        struct {
            char    jfcdsrg1;       /* 62 BYTE 1 OF JFCDSORG                */
#define JFCORGIS    0x80            /* ... INDEXED SEQUENTIAL               */
#define JFCORGPS    0x40            /* ... PHYSICAL SEQUENTIAL              */
#define JFCORGDA    0x20            /* ... DIRECT                           */
#define JFCORGCX    0x10            /* ... BTAM OR QTAM LINE GROUP          */
#define JFCORGCQ    0x08            /* ... QTAM DIRECT ACCESS MESSAGE QUEUE */
#define JFCORGMQ    0x04            /* ... QTAM PROBLEM PROGRAM MESSAGE
                                           QUEUE                            */
#define JFCORGPO    0x02            /* ... PARTITIONED                      */
#define JFCORGU     0x01            /* ... UNMOVABLE - THE DATA CONTAINS
                                           LOCATION DEPENDENT INFORMATION   */

            char    jfcdsrg2;       /* 63 BYTE 2 OF JFCDSORG                */
#define JFCORGGS    0x80            /* ... GRAPHICS                         */
#define JFCORGTX    0x40            /* ... TCAM LINE GROUP                  */
#define JFCORGTQ    0x20            /* ... TCAM MESSAGE QUEUE               */
#define JFCRSV13    0x10            /* ... RESERVED, BINARY ZERO            */
#define JFCORGAM    0x08            /* ... VSAM                             */
#define JFCORGTR    0x04            /* ... TCAM 3705                        */
#define JFCRSV15    0x02            /* ... RESERVED, BINARY ZERO            */
#define JFCRSV16    0x01            /* ... RESERVED, BINARY ZERO            */
        };
    };

    char            jfcrecfm;       /* 64 RECORD FORMAT                     */
#define JFCFMREC    0xC0            /* ... HIGH-ORDER TWO BITS OF JFCRECFM
                                           TO BE TESTED FOR RECORD FORMAT   */
#define JFCUND      0xC0            /* ... U - UNDEFINED                    */
#define JFCFIX      0x80            /* ... F - FIXED                        */
#define JFCVAR      0x40            /* ... V - VARIABLE                     */
#define JFCRCFM     0xE0            /* ... RECORD FORMAT (USASI/USASCII)    */
#define JFCVARD     0x20            /* ... D - VARIABLE (FORMAT D FOR
                                           USASI/USASCII)                   */
#define JFCRFO      0x20            /* ... T - TRACK OVERFLOW               */
#define JFCRFB      0x10            /* ... B - BLOCKED - MAY NOT OCCUR WITH
                                           UNDEFINED                        */
#define JFCRFS      0x08            /* ... S - FOR FIXED LENGTH RECORD
                                           FORMAT, STANDARD BLOCKS.
                                           NO TRUNCATED BLOCKS OR UNFILLED
                                           TRACKS ARE EMBEDDED IN THE DATA SET.
                                           FOR VARIABLE LENGTH RECORD FORMAT,
                                           SPANNED RECORDS.                 */
#define JFCCHAR     0x06            /* ... CONTROL CHARACTER                */
#define JFCASA      0x04            /* ... A - AMERICAN NATIONAL STANDARD
                                           (ASA) CONTROL CHARACTER          */
#define JFCMAC      0x02            /* ... M - MACHINE CODE CONTROL
                                           CHARACTER                        */
#define JFCNOCC     0x00            /* ... NO CONTROL CHARACTER             */

    char            jfcoptcd;       /* 65 OPTION CODES                      */
    /*              QSAM - BSAM - BPAM                                      */
#define JFCWVCSP    0x80            /* ... W - WRITE VALIDITY CHECK         */
#define JFCALLOW    0x40            /* ... U - ALLOW A DATA CHECK CAUSED BY
                                           AN INVALID CHARACTER (1403 PRINTER
                                           WITH UCS FEATURE)                */
#define JFCPCIBT    0x20            /* ... C - CHAINED SCHEDULING USING THE
                                           PROGRAM CONTROLLED INTERRUPTION  */
#define JFCBCKPT    0x10            /* ... BYPASS EMBEDDED DOS CHECKPOINT
                                           RECORDS ON TAPE                  */
#define JFCRSV18    0x08            /* ... RESERVED                         */
#define JFCREDUC    0x04            /* ... Z - USE REDUCED ERROR RECOVERY
                                           PROCEDURE
                                           (MAGNETIC TAPE)   (EXCP ALSO)    */
#define JFCSRCHD    0x04            /* ... USE SEARCH DIRECT (SD), INSTEAD OF
                                           SEARCH PREVIOUS, ON ROTATIONAL
                                           POSITION SENSING (RPS) DEVICE.
                                           (DIRECT ACCESS)                  */
#define JFCRSV21    0x02            /* ... RESERVED                         */
#define JFCOPTJ     0x01            /* ... J - 3800 CONTROL CHARACTER       */

    /*              BISAM - QISAM                                           */
#define JFCWVCIS    0x80            /* ... W - WRITE VALIDITY CHECK         */
#define JFCRSV17    0x40            /* ... RESERVED                         */
#define JFCMAST     0x20            /* ... M - MASTER INDEXES               */
#define JFCIND      0x10            /* ... I - INDEPENDENT OVERFLOW AREA    */
#define JFCCYL      0x08            /* ... Y - CYLINDER OVERFLOW AREA       */
#define JFCRSV19    0x04            /* ... RESERVED                         */
#define JFCDEL      0x02            /* ... L - DELETE OPTION                */
#define JFCREORG    0x01            /* ... R - REORGANIZATION CRITERIA      */

    /*              BDAM                                                    */
#define JFCWVCBD    0x80            /* ... W - WRITE VALIDITY CHECK         */
#define JFCOVER     0x40            /* ... TRACK OVERFLOW                   */
#define JFCEXT      0x20            /* ... E - EXTENDED SEARCH              */
#define JFCFEED     0x10            /* ... F - FEEDBACK                     */
#define JFCACT      0x08            /* ... A - ACTUAL ADDRESSING            */
#define JFCRSV20    0x04            /* ... RESERVED                         */
#define JFCRSV22    0x02            /* ... RESERVED                         */
#define JFCREL      0x01            /* ... R - RELATIVE BLOCK ADDRESSING    */

    /*              USASI/USASCII                                           */
#define JFCOPTQ     0x08            /* ... EBCDIC TO ASCII OR ASCII TO EBCDIC
                                           TRANSLATION REQUIRED             */

    /*              TCAM                                                    */
#define JFCSDNAM    0x80            /* ... SOURCE OR DESTINATION NAME PRECEDES
                                           MESSAGE (AFTER CONTROL BYTE)     */
#define JFCWUMSG    0x40            /* ... WORK UNIT IS A MESSAGE (DEFAULT WORK
                                           UNIT IS A RECORD)                */
#define JFCCBWU     0x20            /* ... CONTROL BYTE PRECEDES WORK UNIT  */
    unsigned short  jfcblksi;       /* 66 MAXIMUM BLOCK SIZE                */
#define jfcbufsi    jfcblksi        /* 66 MAXIMUM BUFFER SIZE               */
#define jfcbaxbf    jfcblksi        /* 66 NUMBER OF INDEX BUFFERS (VSAM)    */

    union {
        char        jfcamsyn[8];    /* 68 MODULE NAME FOR SYNAD ROUTINE FOR
                                          VSAM                              */
        struct {
            unsigned short jfclrecl;/* 68 LOGICAL RECORD LENGTH (2 bytes)   */
            unsigned short jfcncp;  /* 6A NUMBER OF CHANNEL PROGRAMS.  NUMBER
                                          OF READ OR WRITE REQUESTS WHICH MAY
                                          BE ISSUED PRIOR TO A CHECK.
                                          NUMBER OF IOB'S GENERATED.
                                          (MAXIMUM NUMBER IS 99.)
                                          NOTE - GAM USES JFCBFTEK FOR THIS
                                          INFORMATION AND DOES NOT USE THIS
                                          FIELD AT ALL. (2 bytes)           */
            char    unused6C[4];
        };
    };
#define jfcbufmx    jfcamsyn[2]     /* 6A THE MAXIMUM NUMBER OF BUFFERS TO BE
                                          USED FOR DATA TRANSFER FOR EACH LINE
                                          IN THIS LINE GROUP (TCAM) (1 byte)*/
#define jfcbfseq    jfcamsyn[3]     /* 6B TAPE POSITIONING INFORMATION FOR
                                          CHECKPOINT RESTART.  THIS FIELD IS
                                          USED TO PASS A PHYSICAL FILE SEQUENCE
                                          COUNT FROM CHECKPOINT TO RESTART.
                                          THE COUNT TELLS THE PHYSICAL
                                          POSITION OF THE TAPE VOLUME THAT
                                          WAS BEING PROCESSED WHEN THE
                                          CHECKPOINT WAS TAKEN. (1 byte)    */
#define jfcntm      jfcamsyn[3]     /* 6B THE NUMBER OF TRACKS THAT DETERMINE
                                          THE DEVELOPMENT OF A MASTER INDEX.
                                          MAXIMUM NUMBER IS 99.  (ISAM)     */
#define jfcpci      jfcamsyn[3]     /* 6B PROGRAM-CONTROLLED INTERRUPTION
                                          (PCI) FLAG BYTE  (TCAM)           */
#define JFCPCIX1    0x80            /* ... PCI=(X,) RECEIVE OPERATIONS      */
#define JFCPCIX2    0x40            /* ... PCI=(,X) SEND OPERATIONS
                                           X INDICATES THAT AFTER THE FIRST
                                           BUFFER IS FILLED (ON RECEIVE
                                           OPERATIONS) OR EMPTIED (ON SEND
                                           OPERATIONS), A PCI OCCURS DURING
                                           THE FILLING OR EMPTYING OF THE
                                           NEXT BUFFER.  THE FIRST BUFFER
                                           REMAINS ALLOCATED AND ANOTHER
                                           IS ALLOCATED.                    */
#define JFCPCIA1    0x20            /* ... PCI=(A,) RECEIVE OPERATIONS      */
#define JFCPCIA2    0x10            /* ... PCI=(,A) SEND OPERATIONS
                                           A INDICATES THAT AFTER THE FIRST
                                           BUFFER IS FILLED (ON RECEIVE
                                           OPERATIONS) OR EMPTIED (ON SEND
                                           OPERATIONS), A PCI OCCURS DURING
                                           THE FILLING OR EMPTYING OF THE
                                           NEXT BUFFER.  THE FIRST BUFFER IS
                                           DEALLOCATED.  A BUFFER IS ALLOCATED
                                           IN PLACE OF THE DEALLOCATED
                                           BUFFER.                          */
#define JFCPCIN1    0x08            /* ... PCI=(N,) RECEIVE OPERATIONS      */
#define JFCPCIN2    0x04            /* ... PCI=(,N) SEND OPERATIONS
                                           N INDICATES THAT NO PCI'S ARE TAKEN
                                           DURING FILLING (ON RECEIVE
                                           OPERATIONS) OR EMPTYING (ON SEND
                                           OPERATIONS) OF BUFFERS.  BUFFERS
                                           ARE DEALLOCATED AT THE END OF
                                           TRANSMISSION.                    */
#define JFCPCIR1    0x02            /* ... PCI=(R,) RECEIVE OPERATIONS      */
#define JFCPCIR2    0x01            /* ... PCI=(,R) SEND OPERATIONS
                                           R INDICATES THAT AFTER THE FIRST
                                           BUFFER IS FILLED (ON RECEIVE
                                           OPERATIONS) OR EMPTIED (ON SEND
                                           OPERATIONS), A PCI OCCURS DURING
                                           THE FILLING OR EMPTYING OF EACH
                                           SUCCEEDING BUFFER.
                                           THE COMPLETED BUFFER IS DEALLOCATED,
                                           BUT NO NEW BUFFER IS ALLOCATED TO
                                           TAKE ITS PLACE.                  */

    /*******************************************************************
     *
     *              NORMAL 108 SEGMENT
     */
#define jfcresrv    jfcamsyn[4]     /* 6C FIRST BYTE CONTAINS NUMBER OF BYTES
                                          FOR TIME OF DAY.  SECOND BYTE
                                          CONTAINS NUMBER OF BYTES FOR DATE.
                                          THIRD BYTE CONTAINS NUMBER OF BYTES
                                          FOR OUT SEQ.  FOURTH BYTE CONTAINS
                                          NUMBER OF BYTES IN.  (TCAM)       */
#define jfcrkp      jfcamsyn[4]     /* 6C THE RELATIVE POSITION OF THE FIRST
                                          BYTE OF THE KEY WITHIN EACH LOGICAL
                                          RECORD.  MAXIMUM VALUE IS LOGICAL
                                          RECORD LENGTH MINUS KEY LENGTH.   */
#define jfccylof    jfcamsyn[6]     /* 6E THE NUMBER OF TRACKS TO BE RESERVED
                                          ON EACH CYLINDER TO HOLD RECORDS
                                          THAT OVERFLOW FROM OTHER TRACKS ON
                                          THAT CYLINDER.  MAXIMUM VALUE
                                          IS 99.                            */
#define jfcdbufn    jfcamsyn[7]     /* 6F RESERVED                          */

    char    jfcintvl;               /* 70 INTENTIONAL DELAY, IN SECONDS,
                                          BETWEEN PASSES THROUGH A POLLING
                                          LIST (QTAM)                       */
    /*              END OF NORMAL 108 SEGMENT
     *******************************************************************/

    /*******************************************************************
     *
     *              108 PRINTER SEGMENT
     *
     *        NOTE  THIS SEGMENT REPLACES THE NORMAL 108 SEGMENT IF
     *              THE DD STATEMENT USES THE UCS PARAMETER.
     */
#define jfcucsid    jfcamsyn[4]     /* 6C NAME OF THE UCS IMAGE TO BE LOADED*/
#define jfcucsop    jfcintvl        /* 70 OPERATION OF THE UCS IMAGE TO BE
                                          LOADED                            */
#define JFCBEXTP    0x80            /* ... JFCB EXTENSION PRESENT FOR 3800
                                           DEVICE                           */
#define JFCFOLD     0x40            /* ... UCS IMAGE IS TO BE LOADED IN THE
                                           FOLD MODE                        */
#define JFCRSV25    0x20            /* ... RESERVED                         */
#define JFCVER      0x10            /* ... UCS IMAGE IS TO BE VERIFIED      */
#define JFCFCBAL    0x08            /* ... FORMS ARE TO BE ALIGNED          */
#define JFCFCBVR    0x04            /* ... FORMS CONTROL BUFFER (FCB) IMAGE
                                           IS TO BE VERIFIED                */
#define JFCRSV26    0x02            /* ... RESERVED                         */
#define JFCRSV27    0x01            /* ... RESERVED                         */
    /*              END OF 108 PRINTER SEGMENT
     *******************************************************************/

    char            jfcoutli[3];    /* 71 SMF - SYSOUT LIMIT.  BINARY
                                          REPRESENTATION OF THE OUTLIM=
                                          PARAMETER ON THE SYSOUT DD
                                          STATEMENT.  THE MAXIMUM NUMBER OF
                                          LOGICAL RECORDS SPECIFIED FOR THIS
                                          OUTPUT DATA SET.                  */
#define jfcthrsh    jfcoutli[0]     /* 71 RECORDS TO BE USED                */
#define jfccpri     jfcoutli[0]     /* 71 PRIORITY BETWEEN SEND AND RECEIVE
                                          OPERATIONS (TCAM)                 */
#define JFCRECV     0x04            /* ... RECEIVE PRIORITY                 */
#define JFCEQUAL    0x02            /* ... EQUAL PRIORITY                   */
#define JFCSEND     0x01            /* ... SEND PRIORITY                    */
#define jfcsowa     jfcoutli[1]     /* 72 LENGTH, IN BYTES, OF THE USER-
                                          PROVIDED WORK AREA (QTAM)         */
    char            jfcbntcs;       /* 74 NUMBER OF OVERFLOW TRACKS         */
    char            jfcbnvol;       /* 75 NUMBER OF VOLUME SERIAL NUMBERS   */
    char            jfcbvols[30];   /* 76 THE FIRST FIVE VOLUME SERIAL
                                          NUMBERS                           */
#define jfcmsvgp    jfcbvols[22];   /* 8C MASS STORAGE VOLUME GROUP FROM
                                          WHICH TO SELECT A VOLUME          */
    char            jfcbextl;       /* 94 LENGTH OF BLOCK OF EXTRA VOLUME
                                          SERIAL NUMBERS (BEYOND FIVE)      */
    char            jfcbexad[3];    /* 95 RELATIVE TRACK ADDRESS (TTR) OF
                                          FIRST JFCB EXTENSION BLOCK FOR
                                          VOLUME SERIAL NUMBERS OR TTR OF
                                          JFCB EXTENSION BLOCK FOR 3800     */
    char            jfcbpqty[3];    /* 98 PRIMARY QUANTITY OF DIRECT ACCESS
                                          STORAGE REQUIRED                  */
#define jfcrunit    jfcbpqty        /* 98 UNIT TYPE (EBCDIC) OF A DEVICE AT
                                          A REMOTE TERMINAL.  THE FIRST TWO
                                          CHARACTERS ARE RD (READER),
                                          PR (PRINTER) OR PU (PUNCH).
                                          THE THIRD CHARACTER IS A NUMBER
                                          FROM 1 TO 9                       */
    char            jfcbctri;       /* 9B SPACE PARAMETERS                  */
#define JFCBSPAC    0xC0            /* ... BIT PATTERN FOR SPACE REQUESTS   */
#define JFCBABS     0x00            /* ... ABSTR REQUEST                    */
#define JFCBAVR     0x40            /* ... AVERAGE BLOCK LENGTH REQUEST     */
#define JFCBTRK     0x80            /* ... TRK REQUEST                      */
#define JFCBCYL     0xC0            /* ... CYL REQUEST                      */
#define JFCBMSGP    0x20            /* ... REQUEST IS FOR A MASS STORAGE
                                           VOLUME GROUP (MSVGP) VOLUME      */
#define JFCRSV29    0x10            /* ... RESERVED                         */
#define JFCONTIG    0x08            /* ... CONTIG REQUEST                   */
#define JFCMIXG     0x04            /* ... MXIG REQUEST                     */
#define JFCALX      0x02            /* ... ALX REQUEST                      */
#define JFCROUND    0x01            /* ... ROUND REQUEST                    */
    char            jfcbsqty[3];    /* 9C SECONDARY QUANTITY OF DIRECT ACCESS
                                          STORAGE REQUIRED                  */
#define jfcrqid     jfcbsqty        /* 9C QUEUE IDENTIFICATION (QID) USED BY
                                          ACCESS METHOD TO DETERMINE THE
                                          REMOTE TERMINAL LOCATION FOR THIS
                                          JOB.                              */
    char            jfcflgs1;       /* 9F FLAG BYTE                         */
#define JFCBDLET    0x80            /* ... IF ONE, DELETE THE DATA SET USED
                                           WHEN EXTENDING THE JOB QUEUE OR
                                           SPOOL DATA SETS (OS/VS1)         */
#define JFCTOPEN    0x40            /* ... TAPE DATA SET HAS BEEN OPENED    */
#define JFCBADSP    0x20            /* ... AUTOMATIC DATA SET PROTECTION
                                           INDICATOR                        */
#define JFCBPROT    0x10            /* ... RACF PROTECT REQUESTED (OS/VS2)  */
#define JFCBCEOV    0x08            /* ... IF ONE, CHKPT=EOV SPECIFIED FOR
                                           THIS DATA SET                    */
#define JFCVRDS     0x04            /* ... VIO DATA SET                     */
#define JFCBCKDS    0x02            /* ... DATA SET IS CHECKPOINT DATASET   */
#define JFCBUAFF    0x01            /* ... UNIT AFFINITY SPECIFIED FOR THIS
                                           DATA SET                         */

    char            jfcbdqty[3];    /* A0 QUANTITY OF DIRECT ACCESS STORAGE
                                          REQUIRED FOR A DIRECTORY OR AN
                                          EMBEDDED INDEX AREA               */
    char            jfcbspnm[3];    /* A3 MAIN STORAGE ADDRESS OF THE JFCB
                                          WITH WHICH CYLINDERS ARE SPLIT
                                          (OS/VS1)                          */
#define jfcbflg3    jfcbspnm[0]     /* A3 FLAG BYTE (OS/VS2)                */
#define JFCDQDSP    0x80            /* ... REQUEST DEQUEUE OF TAPE VOLUME
                                           WHEN DEMOUNTED                   */
#define JFCBEXP     0x40            /* ... EXPIRATION DATE SPECIFIED        */

    unsigned short  jfcbabst;       /* A6 RELATIVE ADDRESS OF FIRST TRACK
                                          TO BE ALLOCATED                   */
    char            jfcbsbnm[3];    /* A8 MAIN STORAGE ADDRESS OF THE JFCB
                                          FROM WHICH SPACE IS TO BE
                                          SUBALLOCATED                      */
    char            jfcbdrlh[3];    /* AB AVERAGE DATA BLOCK LENGTH         */
    char            jfcbvlct;       /* AE VOLUME COUNT                      */
    char            jfcbsptn;       /* AF NUMBER OF TRACKS PER CYLINDER TO
                                          BE USED BY THIS DATA SET WHEN
                                          SPLIT CYLINDER IS INDICATED       */
};
#pragma pack(reset)

extern int      __rdjfcb(DCB *dcb, JFCB *jfcb);

#endif
