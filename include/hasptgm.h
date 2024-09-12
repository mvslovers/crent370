#ifndef HASPTGM_H
#define HASPTGM_H

typedef struct __tgm        __TGM;      /* JES Track Group Map                  */

/* JES Track Group Map */
struct __tgm {
    unsigned int    TGMCYMXM;       /* 00 MAX TTR THIS TRACK GROUP              */
    unsigned int    TGMCELL;        /* 04 MTTR OF NEXT AVAILABLE TRAKCELL       */
/* TGMAP    EQU   *                   START OF ALLOCATION MAP                   */
};

#endif
