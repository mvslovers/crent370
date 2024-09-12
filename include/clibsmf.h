#ifndef CLIBSMF_H
#define CLIBSMF_H

typedef struct smca		SMCA;

struct smca {
	unsigned char 	smcaopt;	/* 00 SMFDEFLT OPTIONS SELECTED AT
                                      INITIALIZATION TIME.  THE OPTIONS APPLY
                                      TO BACKGROUND PROCESSING.  SMCAFOPT
                                      (OFFSET 82) CONTAINS THE FOREGROUND
                                      OPTIONS. */
#define SMCAOPT1 	0x80		/*    JOB ACCOUNTING (OPT=1 */
#define SMCAOPT2 	0x40		/*    STEP ACCOUNTING (OPT=2)*/
#define SMCAEXT  	0x20		/*    USER EXITS WILL BE TAKEN (EXT=YES) */
#define SMCADSA  	0x10		/*    DATA SET ACCOUNTING (DSV=2 OR 3) */
#define SMCAVOL  	0x08		/*    VOLUME ACCOUNTING (DSV=1 OR 3) */
#define SMCARS01 	0x04		/*    RESERVED  */
#define SMCATDS  	0x02		/*    TYPE 17 RECORDS MAINTAINED FOR TEMPORARY  
                                /*    DATA SETS (REC=2 OR 3) */
#define SMCAFGND 	0x01		/*    SMF FOREGROUND OPTIONS BIT.  IF 0, ABOVE
                                      BITS DESCRIBE BACKGROUND OPTIONS.  IF 1, 
                                      ABOVE BITS DESCRIBE FOREGROUND OPTIONS. */
	unsigned char   smcamisc;	/* 01 MISCELLANEOUS INDICATORS  */
#define SMCAUSER 	0x80        /*    SMF RECORDING REQUESTED */
#define SMCAMAN     0x40        /*    SYS1.MAN DATA SET IS/IS NOT PRESENT
                                      BITS 0 AND 1 MEAN                    
                                      00 - NO SMF RECORDING REQUESTED      
                                           (MAN=NONE)                      
                                      01 - ONLY USER RECORDS TO BE RECORDED
                                           (MAN=USER)                      
                                      10 - INVALID COMBINATION             
                                      11 - SMF AND USER RECORDING REQUESTED
                                           (MAN=ALL) */
#define SMCAOPI  	0x20		/*    IF 0, OPERATOR MAY CHANGE SMF FOREGROUND
                                      OPTIONS WHEN HE ISSUES A TSO START      
                                      COMMAND OR TSO MODIFY COMMAND (OPI=YES).
                                      IF 1, OPERATOR MAY NOT CHANGE SMF
                                      FOREGROUND OPTIONS (OPI=NO). */
#define SMCAFIRT 	0x10		/*    SMF DATA SET TO BE OPENED */
#define SMCAPSDP 	0x08		/*    PSEUDO-DUMP SWITCH 
                                      (DEVICE SWITCHING ONLY) */
#define SMCADBSY 	0x04		/*    DUMP IS BUSY (SMF WRITER) */
#define SMCABSW  	0x02		/*    BUFFER SWITCH.  IF 0, LEFT HALF OF BUFFER
                                      IN USE.  IF 1, RIGHT HALF OF BUFFER IN
                                      USE. */
#define SMCADUMP 	0x01		/*    DUMP BUSY  */
	unsigned short	smcatoff;	/* 02 OFFSET OF THE FIRST SMF TIOT ENTRY FROM 
                                      THE BEGINNING OF THE MASTER SCHEDULER 
                                      TIOT */
	void *			smcatiot;	/* 04 ADDRESS OF THE MASTER SCHEDULER TIOT */
/*
** THE FOLLOWING FIELDS ARE SET UP BY IPL INITIALIZATION 
*/
	unsigned 		smcajwt;	/* 08 JOB WAIT TIME LIMIT IN MICROSEC.
                                      TIMER UNITS. DERIVED FROM JWT IN
                                      SMFDEFLT. */ 
	union {
		unsigned 	smcabuf;    /* 0C SMF BUFFER SIZE IN BYTES.  AT
                                      INITIALIZATION, IT CONTAINS BUF=VALUE. */
		unsigned    smcabsiz;	/* 0C AFTER IPL, IT CONTAINS THE BUFFER WORKING 
                                      SIZE  */
	};
	unsigned char	smcasid[4];	/* 10 SYSTEM IDENTIFICATION (SID) */
	void *			smcabufp;	/* 14 ADDRESS OF THE SMF BUFFER */
/*
** SMF DEVICE CHARACTERISTICS 
**
**  CURRENT RECORDING DATA SET
**        WHEN THE SMF RECORDING DEVICE IS A DIRECT ACCESS DEVICE,
**        THE FOLLOWING FIELDS MAY DESCRIBE EITHER THE PRIMARY OR
**        ALTERNATE DATA SET, WHICHEVER IS CURRENTLY BEING WRITTEN.
*/
	unsigned char	smcapdev[6];/* 18 VOLUME SERIAL NUMBER OF THE CURRENTLY
                                      USED SMF DATA SET  */
	unsigned char	smcapsta;	/* 1E CURRENTLY USED SMF DATA SET DEVICE STATUS */
#define SMCAPNAV 	0x80		/*    DATA SET IS NOT AVAILABLE FOR RECORDING */
#define SMCAPTAP 	0x40		/*    THE SMF RECORDING DEVICE IS A MAGNETIC 
                                      TAPE DEVICE */
#define SMCAPDA  	0x20		/*    THE SMF RECORDING DEVICE IS A DIRECT
                                      ACCESS DEVICE */
#define SMCAPMTY 	0x10		/*    THE DATA SET IS READY TO USE */
#define SMCAMOD  	0x08		/*    OPEN MODULE */
#define SMCARS02 	0x04		/*    RESERVED */
#define SMCAPUNT 	0x02		/*    A DEVICE ADDRESS WAS SPECIFIED FOR THE 
                                      SMF DATA SET AT SYSTEM INITIALIZATION  */
#define SMCAPVOL 	0x01		/*    A VOLUME SERIAL NUMBER WAS SPECIFIED FOR
                                      THE SMF DATA SET AT SYSTEM INITIALIZATION */
	unsigned char 	smcapdar[3];/* 1F CURRENTLY USED SMF DATA SET DEVICE 
                                      ADDRESS (EBCDIC) */
	unsigned char   smcaplbl;	/* 22 LABEL STATUS OF THE CURRENTLY USED SMF  DATA SET */
#define SMCARS03 	0x80		/*    RESERVED */
#define SMCARS04 	0x40		/*    RESERVED */
#define SMCARS05 	0x20		/*    RESERVED */
#define SMCARS06 	0x10		/*    RESERVED */
#define SMCARS07 	0x08		/*    RESERVED */
#define SMCAPNSL 	0x04		/*    NON-STANDARD LABEL (NSL) */
#define SMCAPSL  	0x02		/*    STANDARD LABEL (SL) */
#define SMCAPNL  	0x01		/*    NO LABEL (NL) */
	unsigned char	smcaxory;	/* 23 AN EBCDIC X OR Y CORRESPONDING TO THE
                                      DATA SET THAT IS TO RECEIVE THIS ENTRY */
	void *			smcapdcb;	/* 24 ADDRESS OF THE CURRENTLY USED SMF DATASET DCB */
/*
** DATA SET NOT CURRENTLY IN USE
**
**        WHEN THE SMF RECORDING DEVICE IS A DIRECT ACCESS DEVICE,
**        THE FOLLOWING FIELDS MAY DESCRIBE EITHER THE PRIMARY OR 
**        ALTERNATE DATA SET, WHICHEVER IS CURRENTLY NOT IN USE.
*/
	unsigned char	smcaadev[6];/* 28 VOLUME SERIAL NUMBER OF THE NON-CURRENT SMF DATA SET */
	unsigned char   smcasta;	/* 2E NON-CURRENT SMF DATA SET DEVICE STATUS.
                                      BIT SETTINGS ARE SAME AS FOR SMCAPSTA. */
	unsigned char	smcaadar[3];/* 2F NON-CURRENT SMF DATA SET DEVICE ADDRESS */
	unsigned char	smcaalbl;	/* 32 LABEL STATUS OF THE NON-CURRENT SMF DATA
                                      SET.  BIT SETTINGS ARE SAME AS FOR SMCAPLBL. */
	unsigned char	smcayorx;	/* 33 AN EBCDIC X OR Y CORRESPONDING TO THE 
                                      DATA SET THAT IS TO RECEIVE THIS ENTRY */
	void *			smcaadcb;	/* 34 ADDRESS OF THE NON-CURRENT SMF DATA SET DCB */
/*
** SMF ECB'S
*/
	unsigned        smcawecb;	/* 38 WRITE REQUEST ECB WAITED UPON BY THE SMF 
                                      WRITER.  POSTED BY IGC0008C WHEN A WRITE
                                      IS REQUESTED. */
	unsigned        smcabecb;	/* 3C ECB FOR THE SMF BUFFER */
	unsigned		smcasgwr;	/* 40 IF THE LOGICAL RECORD EXCEEDS 1/2 THE 
                                      BUFFER SIZE, THIS FIELD INDICATES THE 
                                      NUMBER OF BUFFER LOADS REQUIRED TO
                                      ACCOMMODATE THE RECORD */
	unsigned 		smcasgft;	/* 44 THE NUMBER OF RECORD SEGMENTS (BUFFER 
                                      LOADS) THAT WILL FIT IN THE DATA SET */
/*
** MISCELLANEOUS POINTERS AND COMMUNICATION AREAS 
*/
	unsigned		smcawait[2];/* 48 THE ACCUMULATED WAIT TIME, EXPRESSED IN 
                                      26 USEC TIMER UNITS.  FIRST WORD IS 
                                      OVERFLOW FROM SECOND WORD. */
/* SMCAENTY DS    0CL2 -         THESE SWITCHES GOVERN ENTRY CONDITIONS
**                               FOR DEVICE SWITCHING/ALLOCATION/
**                               OPENING ROUTINES
*/
	unsigned char	smcaendi;	/* 50 A COMMUNICATION FIELD */
#define SMCARS14 	0x80		/*    RESERVED */
#define SMCARS15 	0x40		/*    RESERVED */
#define SMCARS16 	0x20		/*    RESERVED */
#define SMCARS17 	0x10		/*    RESERVED */
#define SMCARS18 	0x08		/*    RESERVED */
#define SMCARS19 	0x04		/*    RESERVED */
#define SMCARS20 	0x02		/*    RESERVED */
#define SMCADSNF 	0x01		/*    IF ZERO, DATA SET (X OR Y) WAS FOUND.
                                      IF ONE, DATA SET (X OR Y) WAS NOT FOUND. */
	unsigned char	smcaenop;	/* 51 ENTRY CODE THAT INDICATES WHICH LOAD OF 
                                      SVC 83 HAS PASSED CONTROL TO CURRENT LOAD */
	unsigned char	smcafopt;	/* 52 SMF FOREGROUND OPTIONS.
                                      BIT SETTINGS ARE SAME AS SMCAOPT. */
	unsigned char	smcaenal;	/* 53 RESERVED */
	unsigned		smcawrtp;	/* 54 AN OPTIMUM BUFFER LOAD DISPLACEMENT 
                                      FIGURE.  WHEN THE BUFFER IS LOADED TO OR 
                                      BEYOND THIS POINT, IT WILL BE WRITTEN TO
                                      THE SMF DATA SET. */
/*
** XCTL REMOTE LIST USED BY SVC 83
*/
	void *			smcaxctl;	/* 58 ADDRESS OF THE NAME OF THE ROUTINE TO
                                      WHICH XCTL IS TO PASS CONTROL */
	void *			smca_dcb;	/* 5C DCB POINTER.  ALWAYS ZERO ACCORDING TO 
                                      THE XCTL MACRO INSTRUCTION FORMAT. */
	unsigned char   smcaxnam[8];/* 60 NAME OF THE ROUTINE TO WHICH XCTL IS TO 
                                      PASS CONTROL */
	unsigned char   smcaswa;	/* 68 INDICATOR BITS */
#define SMCASWAR 	0x80		/*    RESERVED */
#define SMCADSTR 	0x40		/*    DISASTER BIT.  BOTH DATA SETS ARE FULL. 
                                      SMF IS NOT RECORDING. */
#define SMCAOPFL 	0x20		/*    OPEN FAILURE ON SMF DATA SET.  SMF IS
                                      NOT RECORDING. */
#define SMCANADA 	0x10		/*    NEXT ALLOCATION MUST BE FOR A DIRECT
                                      ACCESS DEVICE */
#define SMCANAVL 	0x08		/*    ALLOCATION SEARCH IS BY VOLUME SERIAL NUMBER */
#define SMCAZEOD 	0x04		/*    SMF HALT END-OF-DAY IS PROCESSING */
#define SMCADSSP 	0x02		/*    ENTRY TO THE WRITER IS FOR A SPACE CHECK 
                                      OF THE DATA SET */
#define SMCADSSW 	0x01		/*    ENTRY TO THE WRITER IS FOR DATA SET SWITCHING ONLY */
	unsigned char	smcaswb;	/* 69 RESERVED */
	unsigned char	smcaswc;	/* 6A RESERVED */
	unsigned char   smcaswd;	/* 6B RESERVED */
	unsigned char   smcadstm[8];/* 6C START TIME AND DATE AT WHICH NO DATA SET 
                                      WAS AVAILABLE TO RECORD ON.  APPEARS IN 
                                      PACKED DECIMAL IN THE FORM 00YYDDDF     
                                      WHERE 00 = ZEROS, YY = LAST 2 DIGITS OF 
                                      THE YEAR, DDD = DAY OF THE YEAR AND F IS
                                      A SIGN. */
	unsigned 		smcadsct;	/* 74 THE NUMBER OF SMF RECORDS THAT HAVE BEEN
                                      OMITTED FROM THE SMF DATA SET DUE TO THE
                                      UNAVAILABILITY OF A DATA SET TO RECORD ON */
	void *			smcaascb;	/* 78  CURRENT TASK ASCB ADDRESS (OS/VS2) MDC005 */
/*000078                              401+SMCAPOST DS    H -            RESERVED (OS/VS1)                  MDC003 30800002
**00007A                              402+SMCATJID DS    CL2 -          CURRENT TASK TJID (OS/VS1)         MDC004 31000002
*/
	unsigned		smcars21;	/* 7C RESERVED */
	void *			smcasave;	/* 80 USER EXIT ADDRESS SAVE FIELD (OS/VS2) */
	unsigned		smcatexp;	/* 84 TIME OF MOST RECENT EXPIRATION OF A 
                                      TEN-MINUTE TIMER QUEUE ELEMENT (TQE) */
/*000088                              409+SMCAPGIN DS    0F -           NUMBER OF PAGE-INS PERFORMED (OS/VS1)     31156003
**                                    410+*                             (MDC371)                         @ZA07764 31160003
*/
	unsigned 		smcadomx;	/* 88 MANX DOM WTO ID (OS/VS2) */
/*00008C                              413+SMCAPGOT DS    0F -           NUMBER OF PAGE-OUTS PERFORMED (OS/VS1)    31166003
**                                    414+*                             (MDC372)                         @ZA07764 31170003
*/
	unsigned		smcadomy;	/* 8C MANY DOM WTO ID (OS/VS2) */
	unsigned 		smcapgrl;	/* 90 NUMBER OF PAGES RECLAIMED.  RECLAMATION 
                                      RESULTS WHEN A PAGE IS NEEDED TO SATISFY  
                                      A PAGE FAULT BUT DOES NOT HAVE TO BE      
                                      RETRIEVED FROM AUXILIARY STORAGE BECAUSE  
                                      IT IS RESIDENT IN REAL MAIN STORAGE       
                                      AWAITING PAGE-OUT. */
	unsigned		smcargns;	/* 94 NUMBER OF REGIONS SWAPPED IN AND OUT */
	unsigned		smcaspin;	/* 98 NUMBER OF SWAP PAGE-INS */
	unsigned		smcaspot;	/* 9C NUMBER OF SWAP PAGE-OUTS */
	unsigned		smcargnm;	/* A0 NUMBER OF REGIONS MIGRATED */
	unsigned		smcaapgm;	/* A4 NUMBER OF PAGES MIGRATED */
	void *			smcau83;	/* A8 ADDRESS OF SMF OUTPUT EXIT (IEFU83) 
                                      TAKEN WHEN RECORDS ARE TO BE WRITTEN TO
                                      AN SMF DATA SET */
	void *			smcawtcb;	/* AC ADDRESS OF SMF WRITER'S TCB - USED BY 
                                      XMPOST ERROR PROCESSOR (IEEMB827) */
	void *			smcastcb;	/* B0 ADDRESS OF SMF SVC CURRENTLY WAITING FOR 
                                      WRITER - USED BY XMPOST ERROR PROCESSOR */
};

/*000B4   438+SMCAEND  EQU   * */
#define SMCASIZE sizeof(struct smca)
#define TDEVSIZE 	16	/* SIZE OF DEVICE ENTRY */

SMCA *__smca(void);						/* @@smca.c */
const unsigned char *__smfid(void);		/* @@smfid.c */

#endif /* ifndef CLIBSMF_H */


