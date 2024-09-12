#ifndef IEFJESCT_H
#define IEFJESCT_H

typedef struct jesct    JESCT;

struct jesct {
    unsigned        reserved;       /* 00 RESERVED                          */
    void            *jesunits;      /* 04 POINTER TO UCB'S                  */
    void            *jeswaa;        /* 08 ADDRESS OF THE SWA                */
                                    /*    MANAGER - LOCATE MODE             */
    void            *jesqmgr;       /* 0C ADDRESS OF SWA MANAGER MOVE MODE  */
    void            *jesresqm;      /* 10 ENTRY POINT USED TO INTERFACE     */
                                    /*    BETWEEN THE QMNGRIO MACRO AND     */
                                    /*    THE RESIDENT SWA MNGR             */
    void            *jesssreq;      /* 14 ADDRESS OF THE IEFSSREQ ROUTINE   */
    void            *jesssct;       /* 18 ADDRESS OF THE FIRST SUBSYSTEM    */
                                    /*    COMMUNICATIONS TABLE              */
    unsigned char   jespjesn[4];    /* 1C NAME OF PRIMARY JOB ENTRY         */
                                    /*    SUBSYSTEM SET AT SYSGEN           */
    void            *jesalloc;      /* 20 DEVICE ALLOCATION ENTRY           */
                                    /*    POINT USED BY INITIATOR           */
    void            *jesunalc;      /* 24 DEVICE UNALLOCATION ENTRY         */
                                    /*    POINT USED BY INITIATOR           */
    void            *jescatl;       /* 28 DEVICE ALLOCATION PRIVATE         */
                                    /*    CATALOG ENTRY POINT               */
                                    /*    USED BY INITIATOR                 */
    unsigned        jesnucbs;       /* 2C NUMBER OF UCB'S IN SYSTEM.        */
                                    /*    USED BY DEVICE ALLOCATION         */
    void            *jessasta;      /* 30 ADDRESS OF SUBSYSTEM              */
                                    /*    ALLOCATION SEQUENCE TABLE         */
    void            *jesedt;        /* 34 ADDRESS OF ALLOCATION             */
                                    /*    ELIGIBLE DEVICE TABLE             */
    unsigned        reserved2[4];   /* 38 RESERVED                          */
};                                  /* 48 (72 bytes)                        */

#endif /* IEFJESCT_H */
