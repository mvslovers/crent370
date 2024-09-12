#ifndef HASPTAB_H
#define HASPTAB_H

typedef struct __tab        __TAB;      /* JES Track Allocation Block */

/* JES Track Allocation Block */
struct __tab {
    unsigned int    TABMTTR;        /* 00 LAST ALLOCATED BUFFER                 */
    unsigned char   TABFLAG;        /* 04 FLAG BYTE                             */
#define TABMINOR    0x00            /* ... NON-TRACK-CELLED -- PDDB LEVEL       */
#define TABMAJOR    0x40            /* ... TRACK-CELLED     -- PDDB LEVEL       */
#define TABMASTR    0xC0            /* ... NON-TRACK-CELLED --  JOB LEVEL       */

    unsigned char   TABSPN;         /* 05 SUB-PERMUTATION NUMBER                */
    unsigned char   TABMAXR;        /* 06 MAX RECD NBR ON TRACK                 */
    unsigned char   TABUFCNT;       /* 07 NBR BUFFERS LEFT IN CELL              */
    unsigned int    TABAIOT;        /* 08 ADDR OF ALLOCATION IOT                */
};
#define TABLNGTH    sizeof(__TAB)   /* 0C TAB DSECT LENGTH                      */

#endif
