#ifndef IEECDCM_H
#define IEECDCM_H

typedef struct ieecdcm  IEECDCM;
typedef struct ieecdcm  DCM;

struct ieecdcm {
    short           dcmlen;     /* 00 DCM LENGTH                    */
    short           _02;        /* 02 PADDING                       */
    char            dcmflg1;    /* 04 DCM AREA INDICATORS           */
#define DCMOUTPT    0x02        /* ... DCM UPDATED FOR OUTPUT ONLY  */

    char            dcmati;     /* 05 SAVED UCB ATTN INDEX          */
    short           _06;        /* 06 RESERVED                      */
    void            *dcmwtint;  /* 08 DCMWTINT INITIAL VALUE        */
    short           dcmlncnt;   /* 0C NUMBER OF LINES TO BLANK      */
    char            dcmlnnum;   /* 0E FIRST LINE TO BLANK           */
    char            _0F;        /* 0F RESERVED                      */

    unsigned        dcmpack;    /* 10 AREA TO PLACE NUMBER FOR PACKING */
    unsigned        dcmcvbin;   /* 14 AREA FOR CONVERSION TO BINARY */
    char            dcmtimes;   /* 18 TIME RTNS INDICATOR BYTE      */
#define DCMTIMER    0x80        /* ... TIME ELAPSED FOR THIS DISPLAY*/
#define DCMOPTTI    0x40        /* ... OPTIONS TO TI RTN            */
#define DCMOTTMM    0x10        /* ... OPTIONS OR TI RTNS TO MSG MODULE */
#define DCMTASYN    0x04        /* ... TIMER SET FOR ASYNC ERROR MSG*/
#define DCMOCTTI    0x02        /* ... OPEN-CLOSE TO TI RTN         */
#define DCMRMTTI    0x01        /* ... ROLL MODE TO TIMER ROUTINE   */
 
    char            _19;        /* 19 ALIGNMENT BYTE (RESERVED)     */
    short           dcmelgn;    /* 1A ENTRY AREA LAST CHARACTER POINTER */
    void            *dcmbufad;  /* 1C POINTER TO BUFFER ADDRESS TABLE */

    void            *dcmdompk;  /* 20 ADDRESS OF FIRST DOM NUMBER   */
    void            *dcmamtab;  /* 24 ADDRESS OF FIRST SCT ENTRY    */
    void            *dcmadsec;  /* 28 ADDRESS OF FIRST SSCT ENTRY   */
    void            *dcmaddrl;  /* 2C ADDRESS OF LAST SCT ENTRY     */

    void            *dcmascrn;  /* 30 POINTER TO SCREEN IMAGE BUFFER*/
    void            *dcmlscrn;  /* 34 POINTER TO LAST BUFFER LINE   */
    void            *dcmwtbuf;  /* 38 SCREEN LENGTH POINTER         */
    void            *dcmains;   /* 3C POINTER TO INSTRUCTION LINE   */

    void            *dcmaentr;  /* 40 POINTER TO ENTRY AREA         */
    void            *dcmawarn;  /* 44 POINTER TO WARNING LINE       */
    void            *dcmadchp;  /* 48 ADDRESS OF CHANNEL PROGRAM AREA */
    void            *dcmpfkln;  /* 4C POINTER TO PFK LINE           */

    void            *dcmcxsve;  /* 50 CXSA SAVE AREA                */
    void            *dcmadopn;  /* 54 ADDRESS OF COMMAND OPERAND    */
    unsigned        dcmdsav[5]; /* 58 SAVE AND WORK AREA            */
 
/* INPUT BUFFER FOR ISSUING SVC 34 AND SVC 35 */
/* FIELDS DCMWQEXP THROUGH DCMINPUT MUST REMAIN IN ORDER */
    short           dcminlgn;   /* 6C FIELD FOR INPUT LENGTH        */
    short           dcmmcsfl;   /* 6E MCS FLAGS FIELD               */
    char            dcminput[128];/* 70 INPUT MESSAGE TEXT          */
 
    short           dcmlgnth;   /* F0 LENGTH OF A LINE              */
    short           dcmbainc;   /* F2 ADDRESS TO INSERT CURSOR      */
    short           dcmirctr;   /* F4 INTERVENTION REQ'D MSG COUNTER */
    short           dcmbadln;   /* F6 BUFFER ADDR TO BEGIN MSG WRITE */
    short           dcmbytct;   /* F8 NUMBER OF BYTES TO WRITE      */
    short           dcmadnum;   /* FA NEXT LINE NUMBER              */
    short           dcmaxlgn;   /* FC MAXIMUM LINE LENGTH           */
    short           dcmmsgal;   /* FE NUMBER OF LINES IN MESSAGE AREA */

    short           dcmrminc;   /* 100 INCREMENT INTO RMI           */
    short           dcmsctcn;   /* 102 LENGTH OF ONE SCT ENTRY      */
    short           dcmcorln;   /* 104 LENGTH OF DCM LINE IN CORE   */
    short           _106;       /* 106 TIME COUNTER                 */
    char            dcmpfknm;   /* 108 NUMBER OF KEY BEING PROCESSED*/
    char            dcmpfkkn;   /* 109 LIST KEY NUMBER              */
    char            dcmdel[2];  /* 10A DEL VALUE                    */
    char            dcmcon;     /* 10C CON VALUE                    */
    char            dcmseg;     /* 10D SEG VALUE                    */
    char            dcmdl;      /* 10E DISPLAY AREA OPTION          */
    char            dcmrnum;    /* 10F ROLL NUMBER VALUE            */

    short           dcmrtme;    /* 110 ROLL TIME VALUE              */
/* DEFAULT VALUES FOR OPTIONS */
    char            dcmsegdf;   /* 112 SEG DEFAULT                  */
    char            dcmrnumd;   /* 113 RNUM DEFAULT                 */
    short           dcmrtmed;   /* 114 RTME DEFAULT                 */

/* THE 5 BYTES BELOW ARE DEVICE DEPENDENT AND ARE INITIALIZED VIA AN ORG */
    char            dcmasken;   /* 116 ENTER MASK                   */
    char            dcmaskcn;   /* 117 CANCEL MASK                  */
    char            dcmaskcr;   /* 118 CURSOR MASK                  */
    char            dcmasklp;   /* 119 LIGHT PEN MASK               */
    char            dcmaskpf;   /* 11A PFK MASK                     */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 *                         COMMUNICATIONS AREA                         *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
    char            dcmoptst;   /* 11B STATUS OF SCREEN CONTROL OPTIONS */
#define DCMOPTVR    0x80        /* ... DELETE VERIFICATION  CON=(Y=1,N=0) */
#define DCMOPTAD    0x40        /* ... AUTOMATIC DELETION   DEL=(Y=1,N=0) */
#define DCMOPTSG    0x20        /* ... DEFAULT SEGMENT SPECIFIED  SEG=(0=0) */
#define DCMOPRLL    0x10        /* ... ROLL MODE  (Y=1,N=0)         */
 
    char            dcmcs;      /* 11C OPEN/CLOSE REQUEST           */
#define DCMCSC      0x80        /* ... CLOSE REQUEST                */
#define DCMCSO      0x40        /* ... OPEN REQUEST                 */
 
    char            dcmutilt;   /* 11D RESERVED                     */
#define DCMUTILA    0x80        /* ... THESE BITS ARE               */
#define DCMUTILB    0x40        /* ...  INITIALIZED AND USED        */
#define DCMUTILC    0x20        /* ...   SOLELY WITHIN              */
#define DCMUTILD    0x10        /* ...    EACH MODULE               */
#define DCMUTILE    0x08        /* ...     THEY ARE NEVER           */
#define DCMUTILF    0x04        /* ...      USED FOR INTERFACE      */
#define DCMTEST1    0x02        /* ...       FOR TESTING            */
#define DCMTEST2    0x01        /* ...        FOR TESTING           */
 
    char            dcmdstat;   /* 11E CURRENT DISPLAY STATUS       */
#define DCMDSTNM    0x20        /* ... MESSAGES ARE NUMBERED        */
#define DCMDSTNH    0x10        /* ... MSGS NUMBERED - HOLD OPTION  */
#define DCMDSINR    0x08        /* ... INTERVENTION REQ'D DELETION TRIED */
#define DCMDSAUT    0x04        /* ... AUTOMATIC DELETION TRIED     */
 
    char            dcmmcsst;   /* 11F MCS INTERFACE BYTE           */
#define DCMDUSE     0x80        /* ... OUR SUPPORT IN CONTROL       */
#define DCMOOMSS    0x04        /* ... MESSAGE STREAM ENTRY         */
#define DCMOOSDS    0x01        /* ... STATUS DISPLAY ENTRY         */
 
    char            dcmiounq;   /* 120 UNIQUE IO BYTE               */
/* UNIQUE INTERFACE BITS FOR 2260 */
#define DCMIO226    0x80        /* ... RMI PERFORMED                */
#define DCMRPCUR    0x40        /* ... ADVANCE CURSOR TO BLANKS     */
#define DCMFRSCN    0x20        /* ... PUT OUTPUT IN HOLD MODE      */
/* UNIQUE INTERFACE BITS FOR 2250 */
#define DCMRDARM    0x10        /* ... PERFORM READ AFTER RMI       */
#define DCMW2250    0x08        /* ... DEVICE HAS LIGHT PEN         */
#define DCMINNOR    0x04        /* ... NORMAL INSTRUCTION LINE      */
#define DCMINERR    0x02        /* ... ERROR INSTRUCTION LINE       */
 
    char            dcmiocm1;   /* 121 IO COMMUNICATIONS BYTE 1     */
#define DCMDORMI    0x80        /* ... ISSUE RMI                    */
#define DCMSOUND    0x40        /* ... SOUND ALARM                  */
#define DCMWRWRN    0x20        /* ... WRITE WARNING LINE           */
#define DCMWRMSG    0x10        /* ... WRITE FULL MESSAGE AREA      */
#define DCMWRPAR    0x08        /* ... WRITE PARTIAL MESSAGE AREA   */
#define DCMWRINS    0x04        /* ... WRITE INSTRUCTION LINE       */
#define DCMWRENT    0x02        /* ... WRITE ENTRY AREA             */
#define DCMINSC     0x01        /* ... INSERT CURSOR                */

    char            dcmiocm2;   /* 122 IO COMMUNICATIONS BYTE 2     */
#define DCMBLENT    0x80        /* ... BLANK ENTRY AREA             */
#define DCMBLWRL    0x40        /* ... BLANK LEFT HALF WARNING LINE */
#define DCMBLWRR    0x20        /* ... BLANK RIGHT HALF WARNING LINE*/
#define DCMINSSH    0x10        /* ... INIT AND SHIFT INSTRUCTION LINE */
#define DCMWINFD    0x08        /* ... WRITE INFORMATIONAL DISPLAY  */
#define DCMERASE    0x04        /* ... PERFORM ERASE                */
#define DCMIOCRD    0x02        /* ... PERFORM READ (2250,22DOC)    */
#define DCMWRASY    0x01        /* ... WRITE ASYNC ERROR MSG TO MID-SCREEN */
 
    char            dcmiocm3;   /* 123 IO COMMUNICATIONS BYTE 3     */
#define DCMOPRMI    0x80        /* ... RMI AFTER OPEN TO UNLOCK KEYBOARD */
#define DCMSSRG     0x40        /* ... SUPPRESS START REGENERATION  */
#define DCMWRPFK    0x10        /* ... DCM WRITE PFK AREA           */
#define DCMPFKAT    0x08        /* ... PFK ATTENTION                */
#define DCMRDPFK    0x04        /* ... PFK AREA READ                */
#define DCMACPFK    0x02        /* ... TURN ACTIVE PFK LIGHTS ON    */
#define DCMLTPFK    0x01        /* ... TURN ALL PFK LIGHTS ON       */
 
    char            dcmlinen;   /* 124 LINE NUMBER TO BEGIN WRITE   */
    char            dcmculno;   /* 125 LINE IN ENTRY AREA TO INSERT CURSOR */
    char            dcmposcu;   /* 126 POSITION TO INSERT CURSOR    */
    char            dcmasync;   /* 127 ASYN ERROR COMMUNICATIONS/RETRY BYTE */
#define DCMASDA     0x40        /* ... RETRY BIT                    */
#define DCMASIN     0x20        /* ... RETRY BIT                    */
#define DCMASBA     0x10        /* ... RETRY BIT                    */
#define DCMASLOG    0x08        /* ... LOG ASYNCHRONOUS ERROR       */

    char            dcmcom1;    /* 128 COMMUNICATIONS BYTE          */
#define DCMLPENT    0x80        /* ... ENTER BY LP OR CURSOR        */
#define DCMIOPRD    0x40        /* ... READ PERFORMED               */
#define DCMCOMRM    0x20        /* ... RMI PERFORMED                */
#define DCMCOMAU    0x10        /* ... PERFORM AUTO DELETE          */
#define DCMCOMRD    0x08        /* ... PERFORM REGULAR DELETE       */
#define DCMCOMNM    0x04        /* ... NUMBER MESSAGES              */
#define DCMCANCL    0x01        /* ... INDICATE CANCEL TO COMMAND ROUTINE */
 
    char            dcmcom2;    /* 129 COMMUNICATIONS BYTE          */
#define DCMCM2I     0x80        /* ... INPUT TO BE PROCESSED        */
#define DCMSPLIT    0x40        /* ... MSG TO BE SPLIT              */
#define DCMCOMAR    0x20        /* ... ACCEPTED REPLY               */
#define DCMERPF     0x08        /* ... ERASE PERF-PROC CAN NOW CLOSE DEVICE */
#define DCMCMIN5    0x04        /* ... RETURN TO INTER. 5 FOR BLNK  */
#define DCMCBLNK    0x02        /* ... BLANKING REQUIRED            */
#define DCMAE       0x01        /* ... CLEANUP FOR ASY ERROR        */
 
    char            dcmcom3;    /* 12A COMMUNICATIONS BYTE          */
#define DCMCDSP3    0x80        /* ... DISPLAY 3 COMPLETED WORK     */
#define DCMRTPFK    0x40        /* ... RETURN TO PFK ROUTINE        */
#define DCMVLPFK    0x20        /* ... VERIFYING LAST COMMAND       */
#define DCMXINT1    0x10        /* ... ENTRY FOR INTERFACE 1 ROUTINE*/
#define DCMOLUNV    0x08        /* ... O-O-L MSG CAUSED UNVIEW. MSG.*/
#define DCMPFKWR    0x04        /* ... WRITE PFK UPDATES TO LIB     */
#define DCMOLHLD    0x02        /* ... OUT OF LINE MESSAGES HELD    */
#define DCMCMIN7    0x01        /* ... RETURN TO INTER. 7 FOR BLANKING */
 
    char            dcmcmsg1;   /* 12B MSG MODULE COMMUNICATIONS BYTE 1 */
#define DCMMSGWT    0x80        /* ... MOVE IN MESSAGE WAITING      */
#define DCMUNMSG    0x40        /* ... MOVE IN UNVIEWABLE MESSAGE   */
#define DCMSTEX     0x20        /* ... MOVE IN STATUS EXISTS        */
#define DCMCHOPT    0x10        /* ... MOVE IN CHANGE OPTIONS       */
#define DCMELONG    0x08        /* ... MOVE IN ENTRY TOO LONG       */
#define DCMWRCDL    0x04        /* ... MOVE IN CON=N,DEL=Y          */
#define DCMDELNT    0x02        /* ... MOVE IN DEL UNCHANGED, NO TIMER */

    char            dcmcmsg2;   /* 12C MSG MODULE COMMUNICATIONS BYTE 2 */
#define DCMDLREQ    0x80        /* ... MOVE IN DELETION REQUESTED   */
#define DCMRQINC    0x40        /* ... MOVE IN REQUEST INCONSISTENT */
#define DCMMSGCR    0x20        /* ... MOVE IN INVALID CURSOR OPERATION */
#define DCMINVOP    0x10        /* ... MOVE IN INVALID OPERAND      */
#define DCMCILLP    0x08        /* ... MOVE IN ILLEGAL LP OPERATION */
#define DCMDELRI    0x04        /* ... MOVE IN DELETE REQUEST INCONSISTANT */
#define DCMASYRT    0x02        /* ... MOVE IN ASYN ERROR RETRYABLE */
#define DCMASYCD    0x01        /* ... MOVE IN ASYN ERROR MAYBE RETRYABLE */
 
    char            dcmcmsg3;   /* 12D MSG MODULE COMMUNICATIONS BYTE 3 */
#define DCMCMRLL    0x80        /* ... MOVE IN ROLL MODE MESSAGE    */
#define DCMCDLR1    0x40        /* ... NO DELETABLE MESSAGES        */
#define DCMCDLR2    0x20        /* ... INVALID RANGE                */
#define DCMCDLR3    0x10        /* ... SEG EQU TO ZERO              */
#define DCMCDLR4    0x08        /* ... DISPLAY NOT ON SCREEN        */
#define DCMCDLR5    0x04        /* ... INVALID OPERAND              */
#define DCMDTBSY    0x01        /* ... COMMAND REJECTED - TASK BUSY */

    char            dcmcmsg4;   /* 12E MSG MODULE COMMUNICATIONS BYTE 4 */
#define DCMPFKNA    0x80        /* ... MOVE IN PFK NOT ALLOCATED FOR */
#define DCMPFKND    0x40        /* ... MOVE IN PFK NOT DEFINED      */
#define DCMPFKNO    0x20        /* ... MOVE IN NO PFK ALLOCATION    */
#define DCMPFKIP    0x10        /* ... MOVE IN PFK IN PROCESS       */

    char            dcmsvc34;   /* 12F SVC 34 COMMUNICATION BYTE    */
#define DCMMYCMD    0x80        /* ... COMMAND TO BE HANDLED BY THIS CONS */
#define DCMINVLD    0x40        /* ... INVALID K COMMAND            */
#define DCMTYPE1    0x20        /* ... K COMMAND IS NOT ROUTABLE    */
 
    char            dcmcom4;    /* 130 COMMUNICATION BYTE 4         */
#define DCMCNTRL    0x80        /* ... CONTROL LINE INDICATOR       */

    char            dcmiondx;   /* 131 INDEX FOR SELECTING THE      */
                                /*     APPROPRIATE IO ROUTINE       */
                                /*     4 - M/165 CONSOLE            */
                                /*     8 - 2250                     */
                                /*    12 - 2260                     */
                                /*    16 - 3277                     */

    short           dcmtest;    /* 132 RESERVED FOR TESTING         */

/* MODULE ADDRESSES */

    void            *dcmiortn;  /* 134 APPROIATE I/O ROUTINE        */
    void            *dcmnprz;   /* 138 PROCESSOR 0 LOAD ONE         */
    void            *dcmnproc;  /* 13C PROCESSOR ROUTINE LOAD ONE   */
 
    void            *dcmndsp1;  /* 140 DISPLAY ROUTINE 1            */
    void            *dcmndsp2;  /* 144 DISPLAY ROUTINE 2            */
    void            *dcmndsp3;  /* 148 DISPLAY ROUTINE 3            */
    void            *dcmncmd1;  /* 14C COMMAND ROUTINE 1            */
 
    void            *dcmndel1;  /* 150 DELETE ROUTINE 1             */
    void            *dcmndel2;  /* 154 DELETE ROUTINE 2             */
    void            *dcmndel3;  /* 158 DELETE ROUTINE 3             */
    void            *dcmndel4;  /* 15C DELETE ROUTINE 4             */

    void            *dcmnopt1;  /* 160 OPTIONS ROUTINE 1            */
    void            *dcmnpfk1;  /* 164 PFK ROUTINE 1                */
    void            *dcmnpfk2;  /* 168 PFK ROUTINE 2                */
    void            *dcmnerro;  /* 16C ASYNCHRONOUS ERROR ROUTINE   */

    void            *dcmnmsg1;  /* 170 MESSAGE ROUTINE 1            */
    void            *dcmnmsg2;  /* 174 MESSAGE ROUTINE 2            */
    void            *dcmnmsg3;  /* 178 MESSAGE ROUTINE 3            */
    void            *dcmnlpcr;  /* 17C LIGHT PEN/CURSOR SERVICE     */

    void            *dcmnopcl;  /* 180 OPEN-CLOSE ROUTINE           */
    void            *dcmncln;   /* 184 CLEANUP MODULE               */
    void            *dcmnroll;  /* 188 ROLL MODE ROUTINE            */
    void            *dcmntimr;  /* 18C TIMER INTERPRETER ROUTINE    */
    
    void            *dcmnint1;  /* 190 INTERFACE 1 ROUTINE          */
    void            *dcmnint2;  /* 194 INTERFACE 2 ROUTINE          */
    void            *dcmnint3;  /* 198 INTERFACE 3 ROUTINE          */
    void            *dcmnint4;  /* 19C INTERFACE 4 ROUTINE          */

    void            *dcmnint5;  /* 1A0 INTERFACE 5 ROUTINE          */
    void            *dcmnint6;  /* 1A4 INTERFACE 6 ROUTINE          */
    void            *dcmnint7;  /* 1A8 INTERFACE 7 ROUTINE          */
    char            dcmtrace[30];/*1AC DIDOCS MODULE TRACE AREA     */
#define DCMTRAC2    dcmtrace+2  /* ... TRACE MOVE FROM-ADDRESS      */
#define DCMTRLEN    30          /* ... LENGTH FOR TRACE MOVE        */
    char            dcmtren1;   /* 1CA 1ST BYTE OF TRACE ENTRY      */
    char            dcmtren2;   /* 1CB 2ND BYTE OF TRACE ENTRY      */
/* FIRST BYTE OF SCT ENTRIES */
#define DCMMSGWR    0x80        /*     WTOR MESSAGE DISPLAYED IN LINE */
#define DCMMSGIN    0x40        /*     MESSAGE DISPLAYED IN LINE    */
#define DCMMSGCN    0x20        /*     MESSAGE CONTINUED ON NEXT LINE */
#define DCMMSGJK    0x10        /*     TO WRITE OUT-OF-LINE DISPLAY FROM */
                                /*     MAY CONTAIN JUNK (SDS INTERFACE 2) */
#define DCMMSGAD    0x08        /*     MESSAGE CAN BE DELETED AUTOMATICALLY */
#define DCMMSGRD    0x04        /*     REQUEST HAS SPECIFIED MSG BE REMOVED */
#define DCMMSGIF    0x02        /*     INFORMATIONAL MESSAGE IN LINE */
#define DCMMSGST    0x01        /*     END OF TABLE INDICATOR       */
 
/* SECOND BYTE OF SCT ENTRIES */
#define DCMMSGAC    0x80        /*     ACTION MESSAGE               */
#define DCMMSGC7    0x40        /*     DESCRIPTOR CODE 7 MESSAGE    */
#define DCMMSGDM    0x20        /*     MESSAGE HAS BEEN DOMMED      */
#define DCMMSGAR    0x10        /*     MESSAGE IS AN ACCEPTED REPLY */
#define DCMMSGIR    0x08        /*     INTERVENTION REQUIRED MESSAGE */
#define DCMMSGCT    0x04        /*     CONTINUATION LINE            */
#define DCMMSGPP    0x02        /*     ISSUED BY PROBLEM PROGRAM    */
#define DCMMSGCL    0x01        /*     CONTROL LINE OF IN LINE MLWTO */
 
/* SECONDARY SCT ENTRIES */
#define DCMSECCL    0x80        /*     CONTROL LINE OF OUT OF LINE DISPLAY */
#define DCMSECLL    0x40        /*     LABEL LINE OF OUT OF LINE DISPLAY */
#define DCMSECDL    0x20        /*     DATA LINE OF OUT OF LINE DISPLAY */
#define DCMSECBL    0x10        /*     THIS LINE IS BLANKED         */
#define DCMSECDD    0x02        /*     LINE RESERVED FOR DYNAMIC DISPLAY */
#define DCMSECST    0x01        /*     END OF TABLE INDICATOR       */
    unsigned        filler;     /* 1CC align to double word         */
};                              /* 1D0 (464 bytes)                  */

#endif  /* IEECDCM_H */
