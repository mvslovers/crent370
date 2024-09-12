#ifndef IHASRB_H
#define IHASRB_H

/* IHASRB in SYS1.MACLIB */
/* http://tommysprinkle.com/mvssp/category/srb-service-request-block/srb-overview/ */

/* allocate SRB in CSA storage using subpool 228, 229 or 239 only:
    228 fixed, requester key, fetch protected
    229 fixed, requester key, not fetch prptected
    239 fixed, key 0, fetch protected
*/
#define SRB_SUBPOOL     228     /* fixed, requester key, not fetch protected    */

typedef struct srb      SRB;

struct srb {
    char            SRBID[4];           /* 00 EBCDIC ACRONYM   FOR SRB          */
#define SRB_EYE     "SRB "              /* ...                                  */
    SRB             *SRBFLNK;           /* 04 FORWARD CHAIN FIELD               */
    void            *SRBASCB;           /* 08 PTR TO ASCB OF ADDRESS SPACE      */
                                        /*    SRB IS TO BE DISPATCHED TO        */
    union {
        char        SRBFLC[8];          /* 0C SRB AREA MOVED TO LOW CORE        */
        struct {
            char    SRBCPAFF[2];        /* 0C CPU AFFINITY MASK                 */
            short   SRBPASID;           /* 0E PURGEDQ ASID IDENTIFIER           */
            void    *SRBPTCB;           /* 10 PURGEDQ TCB IDENTIFIER            */
        };
    };

    void            *SRBEP;             /* 14 ENTRY POINT OF ROUTINE            */
    void            *SRBRMTR;           /* 18 ADDRESS OF RESOURCE MGR RTN       */
    void            *SRBPARM;           /* 1C USER PARAMETER                    */
    void            *SRBSAVE;           /* 20 SAVE AREA POINTER                 */
    unsigned char   SRBPKF;             /* 24 PROTECT KEY INDICATION            */
    unsigned char   SRBPRIOR;           /* 25 PRIORITY LEVEL INDICATION         */
#define SRBPSYS     0                   /* ... SYSTEM PRIORITY LEVEL            */
#define SRBPNONQ    4                   /* ... NON-QUIESCEABLE PRIORITY         */
    unsigned char   unused1[2];         /* 26 RESERVED                          */
    unsigned        unused2;            /* 28 RESERVED                          */
};
#define SRBSIZE     sizeof(SRB)         /* 2C (44 bytes)                        */

#endif  /* IHASRB_H */
