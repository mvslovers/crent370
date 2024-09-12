#ifndef IHALPDE_H
#define IHALPDE_H

typedef struct lpde     LPDE;   /* pointed to by CVTLPDIR   */

struct lpde {
/***********************************************************************
/*              LINK PACK DIRECTORY ENTRY                              *
/*                                                                     *
/*            AOS/2 REL 2, 04/07/72, LEVEL=3                           *
/**********************************************************************/
    LPDE            *lpdechn;       /* 00 ADDRESS OF NEXT LPDE IN CHAIN OF LPDE SYNONYMS */
    unsigned        lpderbp;        /* 04 RESERVED                                  */
    char            lpdename[8];    /* 08 EITHER MODULE NAME OR ALIAS NAME          */
    void            *lpdentp;       /* 10 RELOCATED ENTRY POINT ADDRESS             */
    unsigned        lpdexlp;        /* 14 RESERVED                                  */
    unsigned short  lpdeuse;        /* 18 COUNT FIELD - COUNT EQUALS ONE            */
    unsigned short  lpderes1;       /* 1A RESERVED FOR FUTURE USE                   */
    unsigned char   lpdeattr;       /* 1C ATTRIBUTE FLAGS                           */
#define LPDENIP     0x80            /* ... MODULE LOADED BY NIP                     */
#define LPDEREN     0x20            /* ... MODULE IS REENTERABLE                    */
#define LPDESER     0x10            /* ... MODULE IS SERIALLY REUSABLE              */
#define LPDEMIN     0x04            /* ... THIS IS A MINOR LPDE                     */
#define LPDENLR     0x01            /* ... NOT LOADABLE ONLY                        */
    unsigned char   lpdeatt2;       /* 1D SECOND ATTRIBUTE FLAG BYTE                */
#define LPDEXLE     0x20            /* ... EXTENT LIST BUILT - MAIN STORAGE         */
                                    /*     OCCUPIED BY MODULE IS DESCRIBED THEREIN  */
#define LPDERLC     0x10            /* ... LPDE CONTAINS A RELOCATED ALIAS ENTRY    */
                                    /*     POINT ADDRESS                            */
#define LPDESYSL    0x02            /* ... AUTHORIZED LIBRARY MODULE                */
#define LPDEAUTH    0x01            /* ... PROGRAM AUTHORIZATION FLAG               */
    unsigned short  lpdeatt3;       /* 1E RESERVED                                  */
    union {
        char        lpdemjnm[8];    /* 20 MAJOR LPDE ENTRY POINT NAME WHEN          */
                                    /*    LPDEMIN=1 OR 8-BYTE EXTENT LIST IF        */
                                    /*    LPDEMIN=0                                 */
        struct {
            unsigned lpdextln;      /* 20 LENGTH OF MAIN STORAGE BLOCK IN WHICH     */
                                    /*    MODULE RESIDES                            */
            void     *lpdextad;     /* 24 ADDRESS OF MAIN STORAGE BLOCK IN WHICH    */
                                    /*    MODULE RESIDES                            */
        } __attribute__((packed));
    };
} __attribute__((packed));

#endif /* IHALPDE_H */
