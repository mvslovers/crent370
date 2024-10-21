#ifndef IEEBASEA_H
#define IEEBASEA_H

/********************************************************************** 
*
* MODULE NAME = IEEBASEA
*
* DESCRIPTIVE NAME = MASTER SCHEDULER RESIDENT DATA AREA
*                    MACRO LEVEL 14 04/20/78
*
* STATUS = OS/VS2 SYSTEM CONTROL PROGRAM 2
* 
* Pointed to by: CVT->CVTMSER     (cvt->cvtmser)
**********************************************************************/

typedef struct ieebasea IEEBASEA;
typedef struct ieebasea BASE;

#ifndef BIT0
#include <iezbits.h>
#endif

#ifndef BA0
#define BA0         0x80
#define BA1         0x40
#define BA2         0x20
#define BA3         0x10
#define BA4         0x08
#define BA5         0x04
#define BA6         0x02
#define BA7         0x01
#define BAVKEY      BA7         /* VIRTUAL REGION PROTECT KEY */
#endif

struct ieebasea {
    void            *bachn;     /* 00 HANDLE TO COMMAND SCHEDULING CHAIN */
    char            bacbid[4];  /* 04 CONTROL BLOCK IDENTIFIFER     */
#define BASE_BACBID "MSER"      /* ... control block identifier     */

    unsigned        balad;      /* 08 ECB FOR ADDED CHAIN ELEMENT   */
    unsigned        baipl;      /* 0C ECB FOR IPL-COMMUNICATIONS TASK */
                                /* ... WAITS ON IT--POSTED BY IEEVIPL */
// BAIPLCC  EQU   BAIPL+3        USED BY TOD CLOCK MANAGEMENT       Y02139

    union {
        struct {
            unsigned baq;       /* 10 OVERLAYED BY BAMSLNK WORD 1   */
            unsigned baprc;     /* 14 OVERLAYED BY BAMSLNK WORD 2   */
            unsigned mslogsvc;  /* 18 COUNT OF EXECUTING WTL SVC'S  */
            void     *balog;    /* 1C ADDRESS OF LOG CONTROL TABLE  */
#define BALOGINT    BA0         /* INITIALIZED LOG INDICATOR        */

        };

        char        ieamslnk[16];/* 10 IEAMSLNK LINK  EP=IEEVIPL,SF=L */
    };

    unsigned        baspwd01;   /* 20 RESERVED WORD                 */
    
    union {
        char        barsw;      /* 24 BARSW    DS    0C             */
        char        basfl;      /* 24 BASFL    DC    X'00'          */
    };
#define BAIN        BA0         /* IPL FLAG                         */
#define MSTODWTO    BA1         /* FAST IPL TOD WTO/WTOR INDICATOR  */
#define BAINTSET    BA2         /* INDICATES INTERNAL SET FOR TOD   */

    char            baspbt01;   /* 25 RESERVED BYTE                 */
    unsigned short  baictr;     /* 26 INTERPRETER COUNTER           */
    unsigned short  bapkes;     /* 28 MASK OF INITIATOR PROTECT KEYS */
    unsigned short  basphw01;   /* 2A RESERVED HALFWORD             */
    unsigned short  basphw02;   /* 2C RESERVED HALFWORD             */
    char            mslogst;    /* 2E LOG STATUS                    */
#define MSLOGENQ    BA0         /* ... LOG DATASET SCHEDULED TO BE  */
                                /*     QUEUED TO SYSOUT WRITER      */
#define MSLOGTHD    BA1         /* ... LOG NOT SUPPORTED BIT        */
#define MSLOGCOM    BA2         /* ... SIGNAL FOR COM TASK TO STOP  */
                                /*     ISSUING WTLS                 */
#define MSLOGDAR    BA3         /* ... LOG INTERNAL ABEND FLAG      */
#define MSLOGIPL    BA4         /* ... LOG FIRST-TIME ENTRY SWITCH  */
#define MSLOGSTA    BA5         /* ... LOG STAE ENVIRONMENT SWITCH  */

    char            baspbyte;   /* 2F MSTR SCH INIT CPL             */
#define BAMSSTAR    BA0         /* ... STAR RECURSION POINTER       */
#define BATRACE     BA1         /* ... KEEP NIP TRACE ACTIVE        */
#define BAMASCH     BA2         /* ... MASTER SCHEDULER ACTIVE      */

    unsigned        balogecb;   /* 30 LOG ECB                       */
    unsigned        baspwd02;   /* 34 RESERVED WORD                 */
    char            bamonitr;   /* 38 MONITOR FLAGS (TERMINALS-TJB CHAIN, */
                                /*    CONSOLES-UCME CHAIN)          */
#define BADSN       BA0         /* ... DSNAMES ARE BEING MONITORED  */
#define BASPACE     BA1         /* ... SPACE IS BEING MONITORED     */

    char            bamontr2;   /* 39 RESERVED FOR MONITOR          */
    unsigned short  babcmax;    /* 3A MAX NUMBER OF BROADCAST MESSAGES */
    unsigned        baspwd03;   /* 3C RESERVED FULLWORD             */

    unsigned        baspwd04;   /* 40 RESERVED FULLWORD             */
    unsigned        baspwd05;   /* 44 RESERVED FULLWORD             */
    unsigned        baspwd06;   /* 48 RESERVED FULLWORD             */
    void            *balogcom;  /* 4C SYSLOG DEB TABLE ADDR         */

    unsigned        basubecb;   /* 50 SYSTEM SERIALIZATION ECB      */
    unsigned short  bajncnt;    /* 54 # OF DEVICES MONITORING JOBNAMES */
    unsigned short  basesct;    /* 56 # OF DEVICES MONITORING SESSIONS */
    unsigned short  bastcnt;    /* 58 # OF DEVICES MONITORING STATUS */
    unsigned short  basphw03;   /* 5A RESERVED HALFWORD             */
    void            *mscommnd;  /* 5C 'CANNED' COMMAND INTERFACE    */
    
    void            *mssmfprm;  /* 60 POINTER TO THE SMF PARMLIB MEMBER LIST */
    void            *baascb;    /* 64 MASTER SCHEDULER ASCB ADDRESS */
    char            mslogcls;   /* 68 LOG OUTPUT CLASS              */
    char            msloglmt[3];/* 69 NO. OF WTLS IN ONE LOG DATA SET */

    union {
        unsigned    mslgcloz;   /* 6C LOG TERMINATION ECB           */
        struct {
            char    msclossw;   /* 6C ECB WAIT/POST FIELD           */
#define MSCLOSW     BA0         /* ... ECB WAIT BIT                 */
#define MSCLOSP     BA1         /* ... ECB POST BIT                 */
            char    _6d[3];     /* 6D XL3'00'                       */
        };
    };

    union {
        unsigned    mslgwlog;   /* 70 LOG DATA SET SWITCH ECB       */
        struct {
            char    mswlogsw;   /* 70 ECB WAIT/POST FIELD           */
#define MSWLOGW     BA0         /* ... ECB WAIT BIT                 */
#define MSWLOGP     BA1         /* ... ECB POST BIT                 */
            char    _71[3];     /* 71 XL3'00'                       */
        };
    };

    union {
        unsigned    mslgwtr;    /* 74 LOG WTL QUEUE WRITER ECB      */
        struct {
            char    mqwtrsw;    /* 74 ECB WAIT/POST FIELD           */
#define MSWTRW      BA0         /* ... ECB WAIT BIT                 */
#define MSWTRP      BA1         /* ... ECB POST BIT                 */
            char    _75[3];     /* 75 XL3'00'                       */
        };
    };

    union {
        unsigned    mslgstrt;   /* 78 LOG RE-ACTIVATION ECB         */
        struct {
            char    msstrtsw;   /* 78 ECB WAIT/POST FIELD           */
#define MSSTRTW     BA0         /* ... ECB WAIT BIT                 */
#define MSSTRTP     BA1         /* ... ECB POST BIT                 */
            char    msstrtrb[3];/* 79 XL3'00' ECB RB   ADDRESS      */
        };
    };

    void            *mslgjscb;  /* 7C LOG SWAPPED JSCB ADDRESS      */

    unsigned        baspwd07;   /* 80 RESERVED FULLWORD             */
    unsigned        baspwd08;   /* 84 RESERVED FULLWORD             */

    char            baspbt02;   /* 88 RESERVED BYTE                 */
    char            msssb;      /* 89 MONITOR TIME NOTE BYTE        */
// MSBTN    EQU   MSSSB         TIME NOTE BIT IS BIT 6            @G64MP2D 
#define MSTN        BA6         /* ...VALUE TO TURN ON TIME NOTE    */
    char            baspbt03;   /* 8A RESERVED BYTE                 */
    char            msecbfl;    /* 8B SCHEDULER FLAGBYTE            */
#define MSWTL       BIT2        /* ... LOG ABEND RECURSION BIT      */
#define MSSUM       BIT7        /* ... SUMMARY BIT, VARY UCB SCAN REQUIRED. */
    void            *bamttbl;   /* 8C MASTER TRACE TABLE ADDRESS    */
    void            *bamtrtn;   /* 90 MASTER TRACE DATA ENTRY RTN   */
    union {
        unsigned    bamtspsz;   /* 94 MASTER TRACE TABLE SIZE AND SUBPOOL */
        struct {
            char    bamtsp;     /* 94 MASTER TRACE TABLE SUBPOOL */
            char    bamtlen[3]; /* 95 MASTER TRACE TABLE SIZE    */
        };
    };

    union {
        unsigned    bastspsz;   /* 98 SYSTEM TRACE TABLE SIZE AND SUBPOOL */
        struct {
            char    bastsp;     /* 98 SYSTEM TRACE TABLE SUBPOOL    */
            char    bastsz[3];  /* 99 SYSTEM TRACE TABLE SIZE       */
        };
    };
    
    void            *bamtcdr;   /* 9C MASTER TRACE TABLE CHNGE RTN ADDR */

    void            *bamtdtab;  /* A0 ADDRESS OF TABLE DUMPED BY THE MASTER TRACE RECOVERY ROUTINE */
    union {
        unsigned    bamtdtsz;   /* A4 SIZE AND SUBPOOL OF TABLE DUMPED  BY THE MASTER TRACE RECOVERY RTN */
        struct {
            char    bamtdtsp;   /* A4 SUBPOOL OF RECOVERY DUMPED TABLE */
            char    bamtdtln[3];/* A5 SIZE OF RECOVERY DUMPED TABLE */
        };
    };

    char            bamtcntl;   /* A8 MASTER TRACE MODULE IN CONTROL FLAG */
#define BAMT808     BA0         /* ... IEEMB808 IN CONTROL          */
#define BAMT809     BA1         /* ... IEEMB809 IN CONTROL          */
#define BAMT816     BA2         /* ... IEEMB816 IN CONTROL          */
#define BAMTRTRY    BA3         /* ... IEEMB816 RETRY RTN ENTERED   */

    char            bamtrecf;   /* A9 MASTER TRACE ERROR RECURSION FLAG */
#define BAMTR808    BA0         /* ... RECURSION IN IEEMB808        */
#define BAMTR809    BA1         /* ... RECURSION IN IEEMB809        */
#define BAMTR816    BA2         /* ... FAILURE IN IEEMB816          */
#define BAMTRUNK    BA3         /* ... UNKNOWN IEEMB816 INVOCATION  */

    char            bamtitfl;   /* AA INTERNAL PROCESSING FLAG USED BY MASTER TRACE FACILITY */
#define BAMTITAB    BA0         /* ... MASTER TRACE TABLE REQUIRED AT SYSTEM INITIALIZATION BIT */
#define BAMTSFRR    BA1         /* ... SETFRR ADD ISSUED BY IEEMB809 */
#define BAMTFRRR    BA2         /* ... SETFRR DELETE RETURNED CONTROL TO IEEMB809 */

    char            baspbt04;   /* AB RESERVED BYTE                 */

    union {
        unsigned    bamtdecb;   /* AC MASTER TRACE RECOVERY SDUMP COMPLETION ECB */
        struct {
            char    bamtdsw;    /* AC ECB WAIT/POST FIELD           */
#define BAMTDW      BA0         /* ... ECB WAIT BIT                 */
#define BAMTDP      BA1         /* ... ECB POST BIT                 */
            char    _AD[3];     /* AD XL3'00'                       */
        };
    };
    
    union {
        unsigned    bamtinit;   /* B0 DEFAULT MASTER TRACE TABLE SIZE AND SUBPOOL REQUESTED */
                                /*    AT SYSTEM INITIALIZATION      */
        struct {
            char    bamtinsp;   /* B0 DEFAULT SUBPOOL               */
            char    bamtinln[3];/* B1 DEFAULT SIZE                  */
        };
    };
    
    void            *bamtvtcb;  /* B4 ADDRESS OF IEEVIPLS TCB FOR   */
                                /*    USE IN MASTER TRACE TABLE     */
                                /*    GETMAIN AND FREEMAIN IN IEEMB809 */
    unsigned        baspwd0a;   /* B8 RESERVED FULLWORD             */
    unsigned        baspwd0b;   /* BC RESERVED FULLWORD             */
    
    unsigned        baspwd0c;   /* C0 RESERVED FULLWORD             */
    unsigned        baspwd0d;   /* C4 RESERVED FULLWORD             */
    unsigned        baspwd0e;   /* C8 RESERVED FULLWORD             */
    unsigned        baspwd0f;   /* CC RESERVED FULLWORD             */
    
    unsigned        baspwd0g;   /* D0 RESERVED FULLWORD             */
};                              /* D4 (212 bytes)                   */

#endif  /* IEEBASEA_H */
