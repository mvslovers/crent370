#ifndef MODMAP_H
#define MODMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <mvssupa.h>
#include "clibary.h"
#include "clibstae.h"

/* Module Map */
typedef struct modmap       MODMAP; /* Module Map                       */
typedef struct mmsd         MMSD;   /* Module Map Section               */
typedef struct mmlr         MMLR;   /* Module Map Label Reference       */
typedef struct mmrl         MMRL;   /* Module Map Relocation Label      */
typedef struct mmld         MMLD;   /* Module Map Load Data             */

struct modmap {
    unsigned char   eye[8];         /* 00 eye catcher                   */
#define MODMAP_EYE  "*MODMAP*"      /* ...                              */
    FILE            *fp;            /* 08 file handle                   */
    MMSD            **mmsd;         /* 0C array of sections             */
    unsigned char   fn[56];         /* 10 dataset(member)               */
    MMLD            **mmld;         /* 48 array of load data            */
};                                  /* 4C (76 bytes)                    */

struct mmld {
    unsigned        esdid;          /* 00 section identifier            */
    unsigned        size;           /* 04 section text size             */
};

struct mmsd {
    unsigned char   name[8];        /* 00 section name                  */
    unsigned        esdid;          /* 08 identifier                    */
    unsigned        address;        /* 0C address of this section       */
    unsigned        size;           /* 10 size of this section          */
    MMLR            **mmlr;         /* 14 array of labels               */
    MMRL            **mmrl;         /* 18 array of relocation           */
    unsigned char   type;           /* 1C type (see ESD_TYPE_ below)    */
    unsigned char   unused[3];      /* 1D unused                        */
    unsigned char   *text;          /* 20 text for this section         */
};                                  /* 24 (36 bytes)                    */

struct mmlr {
    unsigned char   name[8];        /* 00 label name                    */
    unsigned        esdid;          /* 08 identifier                    */
    unsigned        address;        /* 0C address of this label         */
    unsigned char   type;           /* 10 type (see ESD_TYPE_ below)    */
    unsigned char   unused[3];      /* 11 unused                        */
};                                  /* 15 (20 bytes)                    */

struct mmrl {
    unsigned        esdid;          /* 00 esdid of target section       */
    unsigned        address;        /* 04 address of target section     */
    unsigned char   unres;          /* 08 unresolved                    */
    unsigned char   type;           /* 09 (see RLD_FLAG_TYPExxx)        */
    unsigned char   size;           /* 0A size of address target        */
    unsigned char   neg;            /* 0B negative relocation           */
    unsigned        value;          /* 0C value before relocation       */
};                                  /* 10 (16 bytes)                    */

/* find MMSD record by ESD ID */
extern MMSD *   mmapfsd(MODMAP *mm, unsigned esdid)             asm("MMAPFSD");
extern MMSD *   modmap_find_sd(MODMAP *mm, unsigned esdid)      asm("MMAPFSD");

/* find MMLR record by ESD ID */
extern MMLR *   mmapflr(MODMAP *mm, unsigned esdid)             asm("MMAPFLR");
extern MMLR *   modmap_find_lr(MODMAP *mm, unsigned esdid)      asm("MMAPFLR");

/* free MMLD record */
extern void     mmapfrld(MMLD **mmld)                           asm("MMAPFRLD");
extern void     modmap_free_ld(MMLD **mmld)                     asm("MMAPFRLD");

/* free MMRL record */
extern void     mmapfrrl(MMRL **mmrl)                           asm("MMAPFRRL");
extern void     modmap_free_rl(MMRL **mmrl)                     asm("MMAPFRRL");

/* free MMLR record */
extern void     mmapfrlr(MMLR **mmlr)                           asm("MMAPFRLR");
extern void     modmap_free_lr(MMLR **mmlr)                     asm("MMAPFRLR");

/* free MMSD record */
extern void     mmapfrsd(MMSD **mmsd)                           asm("MMAPFRSD");
extern void     modmap_free_sd(MMSD **mmsd)                     asm("MMAPFRSD");

/* reset MODMAP record */
extern MODMAP * mmaprset(MODMAP *mm)                            asm("MMAPRSET");
extern MODMAP * modmap_reset(MODMAP *mm)                        asm("MMAPRSET");

/* reset MODMAP MMLD array */
extern MODMAP * mmaprsld(MODMAP *mm)                            asm("MMAPRSLD");
extern MODMAP * modmap_reset_ld(MODMAP *mm)                     asm("MMAPRSLD");

/* free MODMAP record */
extern void     mmapfree(MODMAP **mm)                           asm("MMAPFREE");
extern void     modmap_free(MODMAP **mm)                        asm("MMAPFREE");

/* allocate a new MODMAP record */
extern MODMAP * mmapnew(void)                                   asm("MMAPNEW");
extern MODMAP * modmap_new(void)                                asm("MMAPNEW");

/* open file (dataset) containing load module to be mapped */
extern int      mmapopen(MODMAP *mm, const char *fn)            asm("MMAPOPEN");
extern int      modmap_open(MODMAP *mm, const char *fn)         asm("MMAPOPEN");

/* process load module into MMSD and MMLR records */
extern int      mmapproc(MODMAP *mm)                            asm("MMAPPROC");
extern int      modmap_process(MODMAP *mm)                      asm("MMAPPROC");

/* dump MODMAP via wtof() */
extern int      mmapdump(MODMAP *mm)                            asm("MMAPDUMP");
extern int      modmap_dump(MODMAP *mm)                         asm("MMAPDUMP");

/* sort MMSD and MMLR records in the MODMAP record */
extern int      mmapsort(MODMAP *mm)                            asm("MMAPSORT");
extern int      modmap_sort(MODMAP *mm)                         asm("MMAPSORT");

/* add base to address for all records */
extern int      modmap_base(MODMAP *mm, unsigned base)          asm("MMAPBASE");

/* zap memory using modmap addresses between base and base + size */
extern int      modmap_zap(MODMAP *mm, unsigned base, unsigned size) asm("MMAPZAP");

/* Load module mapping records */
typedef struct mmcesdr      MMCESDR;/* Module Map CESD record           */
typedef struct mmrldr       MMRLDR; /* Module Map RLD record            */
typedef struct mmidr        MMIDR;  /* Module Map IDR record            */
typedef struct mmctl        MMCTL;  /* Module Map CTL record            */

/* Module Map mapping internals */
typedef struct mmod         MMOD;   /* Load module record id            */
typedef struct mmesd        MMESD;  /* Module Map ESD                   */
typedef struct mmrld        MMRLD;  /* Relocation Dictionary            */
typedef struct mmrldf       MMRLDF; /* Relocation Dict Flag and Address */
typedef struct mmctld       MMCTLD; /* Control Record Data              */

#if !defined(GET3)
/* Use GET3 to convert a 3 byte character array to a value.
** Example: int addr = (int) GET3(esd->address);
*/
#define GET3(s) ( \
    ((unsigned char*)(s))[0] << 16 | \
    ((unsigned char*)(s))[1] <<  8 | \
    ((unsigned char*)(s))[2] )
#endif

/* Module record identifier */
struct mmod {
    unsigned char   id;             /* 00 ID                            */
#define MMOD_ID_CTL         0x01    /* ... Control record               */
#define MMOD_ID_RLD         0x02    /* ... Relocation record            */
#define MMOD_ID_CTLRLD      0x03    /* ... Control Relocation record    */
#define MMOD_ID_CTLEOS      0x05    /* ... Control EOS record           */
#define MMOD_ID_RLDEOS      0x06    /* ... Relocation EOS record        */
#define MMOD_ID_CTLRLDEOS   0x07    /* ... Control Relocation EOS rec   */
#define MMOD_ID_CTLEOM      0x0D    /* ... Control EOM record           */
#define MMOD_ID_RLDEOM      0x0E    /* ... Relocation EOM record        */
#define MMOD_ID_CTLRLDEOM   0x0F    /* ... Control Relocation EOM rec   */
#define MMOD_ID_SCAT        0x10    /* ... Scatter/Translation record   */
#define MMOD_ID_CESD        0x20    /* ... CESD record                  */
#define MMOD_ID_SYM         0x40    /* ... SYM record                   */
#define MMOD_ID_IDR         0x80    /* ... IDR record                   */
};

/* Module Map ESD entry */
struct mmesd {
    unsigned char   symbol[8];      /* 00 symbol name                   */
    unsigned char   type;           /* 08 type                          */
#define ESD_TYPE_SD     0x00        /* ... Section Definition           */
#define ESD_TYPE_ER     0x02        /* ... External Reference           */
#define ESD_TYPE_LR     0x03        /* ... Label Reference              */
#define ESD_TYPE_PC     0x04        /* ... Private Code                 */
#define ESD_TYPE_CM     0x05        /* ... Common                       */
#define ESD_TYPE_PR     0x06        /* ... Pseudo Register              */
#define ESD_TYPE_NULL   0x07        /* ... NULL                         */
#define ESD_TYPE_WX     0x0A        /* ... Weak External Reference      */
#define ESD_TYPE_QSD    0x0D        /* ... Quad Aligned SD              */
#define ESD_TYPE_QPC    0x0E        /* ... Quad Aligned PC              */
#define ESD_TYPE_QCM    0x0F        /* ... Quad Aligned CM              */
#define ESD_TYPE_DPC    0x14        /* ... Deleted PC                   */

    unsigned char   address[3];     /* 09 address (3 bytes)             */
    unsigned char   flag;           /* 0C flags                         */
#define ESD_FLAG_RMODE64    0x20    /* ... RMODE 64 if 1                */
#define ESD_FLAG_AMODE64    0x10    /* ... AMODE 64 if 1                */
#define ESD_FLAG_RSECT      0x08    /* ... RSECT if 1                   */
#define ESD_FLAG_RMODE31    0x04    /* ... RMODE 31 if 1, 24 if 0       */
#define ESD_FLAG_AMODE      0x03    /* ... 00=24, 01=24, 10=31, 11=ANY  */

    unsigned char   id[3];          /* 0D Length(SD,PC,CM,PR), ID=(LR)  */
};

/* Module Map Consolidated ESD record */
struct mmcesdr {
    unsigned char   id;             /* 00 MMOD_ID_CESD (0x20)           */
    unsigned char   flag;           /* 01 flag byte                     */
    unsigned char   spare[2];       /* 02 binary zeros                  */
    unsigned short  esdid;          /* 04 ESD ID of first ESD item      */
    unsigned short  count;          /* 06 count in bytes of ESD data    */
    MMESD           esd[1];         /* 08 start of ESD data             */
};

/* Module Map Relocation Dictionary Flag and Address */
struct mmrldf {
    unsigned char   flag;           /* 00 x'xxxxLLST'                   */
#define RLD_FLAG_UNRES  0x80        /* ... unresolved external          */
#define RLD_FLAG_ADD4   0x40        /* ... add 4 to the LL value        */
#define RLD_FLAG_TYPE   0x30        /* ... RLD type bits                */
#define RLD_FLAG_TYPEA  0x00        /* ... DC A(name)                   */
#define RLD_FLAG_TYPEV  0x10        /* ... DC V(name)                   */
#define RLD_FLAG_TYPEPR 0x20        /* ... Pseudo register disp         */
#define RLD_FLAG_TYPECP 0x30        /* ... Cumulative pseudo register   */
#define RLD_FLAG_LL     0x0C        /* ... LL mask                      */
#define RLD_FLAG_LL2    0x04        /* ... LL two byte address          */
#define RLD_FLAG_LL3    0x08        /* ... LL three byte address        */
#define RLD_FLAG_LL4    0x0C        /* ... LL four byte address         */
#define RLD_FLAG_NEG    0x02        /* ... S negative relocation dir    */
#define RLD_FLAG_SAME   0x01        /* ... T on next item is MMRLDF     */
                                    /*       off next item is MMRLD     */
    unsigned char   address[3];     /* 01 address (3 bytes)             */
};

/* Module Map Relocation Dictionary */
struct mmrld {
    unsigned short  relid;          /* 00 entry id of relocation symbol */
    unsigned short  posid;          /* 02 entry id of position symbol   */
    MMRLDF          mmrldf[1];      /* 04 RLD flags and address         */
};

/* Module Map Relocation Dictionary Record */
#if 0
struct mmrldr {
    unsigned char   id;             /* 00 MMOD_ID_RLD[[EOS|EOM]]        */
    unsigned char   spare[2];       /* 01 binary zeros                  */
    unsigned char   count;          /* 03 number of RLD following text  */
    unsigned char   count2[2];      /* 04 binary zeros                  */
    unsigned short  bytes;          /* 06 number of RLD in bytes        */
    unsigned char   spare8[8];      /* 08 binary zeros                  */
    MMRLD           rld[1];         /* 10 start of RLD data             */
};
#else
struct mmrldr {
    unsigned char   id;             /* 00 MMOD_ID_CTL[RLD]              */
    unsigned char   spare[3];       /* 01 always zero                   */
    unsigned short  ctlcnt;         /* 04 length of control data        */
    unsigned short  rldcnt;         /* 06 length of relocation data     */
    unsigned char   ccw[8];         /* 08 CCW or zeros                  */
    unsigned char   data[0];        /* 10 start of data                 */
} __attribute__((packed));
#endif

/* Control Record */
struct mmctl {
    unsigned char   id;             /* 00 MMOD_ID_CTL[RLD]              */
    unsigned char   spare[3];       /* 01 always zero                   */
    unsigned short  ctlcnt;         /* 04 length of control data        */
    unsigned short  rldcnt;         /* 06 length of relocation data     */
    unsigned char   ccw[8];         /* 08 CCW or zeros                  */
    unsigned char   data[0];        /* 10 start of data                 */
} __attribute__((packed));

/* Control Record Data */
struct mmctld {
    unsigned short  esdid;          /* 00 ESD ID                        */
    unsigned short  count;          /* 02 ESD size in bytes             */
} __attribute__((packed));

/* Identification Record */
struct mmidr {
    unsigned char   id;             /* 00 MMOD_ID_IDR 0x80              */
    unsigned char   bytes;          /* 01 byte count of IDR data (6-255)*/
    unsigned char   type;           /* 02 sub-type of IDR data          */
#define IDR_TYPE        0x0F        /* ... mask for type values         */
#define IDR_TYPE_ZAP    0x01        /* ... data supplied by HMASPZAP    */
#define IDR_TYPE_LINK   0x02        /* ... linkage editor data          */
#define IDR_TYPE_TRAN   0x04        /* ... translator supplied data     */
#define IDR_TYPE_USER   0x08        /* ... user (system) supplied data  */
#define IDR_LAST        0x80        /* ... indicates last IDR record    */
    unsigned char   data[1];        /* 03 start of data                 */
};


#endif  /* MODMAP_H */
