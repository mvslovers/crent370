#ifndef IHAXTLST_H
#define IHAXTLST_H

typedef struct xtlst        XTLST;

struct xtlst {
/**********************************************************************
/*                         EXTENT LIST                                *
/*                                                                    *
/*                     OS/VS2 RELEASE 2  8/28/74                      *
/*********************************************************************/
    unsigned        xtllnth;            /* 00 NUMBER OF BYTES IN EXTENT LIST (=16)      */
    unsigned        xtlnrfac;           /* 04 NUMBER OF RELOCATION FACTORS (=1)         */
    union {
        unsigned    xtlmsbla;           /* 08 WORD REFERENCE FOR XTLMSBLN               */
        struct {
            unsigned x80 : 8;           /* 08 0x80                                      */
            unsigned xtlmsbln : 24;     /* 09 LENGTH OF MAIN STORAGE BLOCK              */
        } __attribute__((packed));
    };
    union {
        unsigned    xtlmsbaa;           /* 0C WORD REFERENCE FOR XTLMSBAD               */
        struct {
            unsigned x00 : 8;           /* 0C ONE BYTE OF X'00'                         */
            unsigned xtlmsbad : 24;     /* 0D ADDRESS OF MAIN STORAGE BLOCK             */
        } __attribute__((packed));
    };
} __attribute__((packed));

#endif /* IHAXTLST_H */
