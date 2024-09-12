#ifndef HASPPDDB_H
#define HASPPDDB_H

typedef struct __pddb       __PDDB;     /* JES Peripheral Data Definition Block */

/* JES Peripheral Data Definition Block */
struct __pddb {
    unsigned char   PDBFLAG1;       /* 00 FLAG BYTE                             */
#define PDB1DSID    0x80            /* ... DSID IN PDBDSID/PDBWTRID FIELD       */
#define PDB1NULL    0x40            /* ... THIS IS A NULL PDDB                  */
#define PDB1LOG     0x20            /* ... THIS PDDB IS FOR THE HASP JOB LOG    */
#define PDB1MDES    0x10            /* ... THIS PDDB IS FOLLOWED BY OTHERS      */
/*                                     INDICATING MULTIPLE DESTINATIONS         */
#define PDB1NSOT    0x08            /* ... DATA SET IS NOT FOR SYSOUT           */
#define PDB1SPIN    0x04            /* ... THIS PDDB IS FOR A SPIN DATA SET     */
#define PDB1HOLD    0x02            /* ... THIS PDDB IS FOR A HELD DATA SET     */
#define PDB1PSO     0x01            /* ... DATA SET MAY BE ACCESSED BY PSO      */

    unsigned char   PDBRECFM;       /* 01 DATA SET RECORD FORMAT                */
    unsigned short  PDBLRECL;       /* 02 MAXIMUM DATA SET LOGICAL RECORD LEN   */
    unsigned int    PDBMTTR;        /* 04 STARTING TRACK ADDR OF DATA SET       */
    unsigned short  PDBDSKEY;       /* 08 DATA SET NUMBER OF DATA SET           */
                                    /* ... DATA SET KEYS FOR SPECIAL DATA SETS  */
#define PDBINJCL    1               /* ... INPUT JCL STATEMENTS                 */
#define PDBOUHJL    2               /* ... HASP JOB LOG                         */
#define PDBOUJCI    3               /* ... JCL IMAGES                           */
#define PDBOUMSG    4               /* ... SYSTEM MESSAGES                      */
#define PDBINTXT    5               /* ... INTERNAL TEXT                        */
#define PDBINJNL    6               /* ... JOB JOURNAL                          */

    unsigned char   PDBCLASS;       /* 0A OUTPUT CLASS OF DATA SET              */
    unsigned char   PDBCOPYS;       /* 0B COPIES OF THIS DATA SET               */
    unsigned short  PDBDEST;        /* 0C DATA SET OUTPUT DESTINATION           */
    unsigned char   PDBCPU;         /* 0E CPU ID                                */
    unsigned char   PDBSEC;         /* 0F DATA SET SECURITY ID                  */
    unsigned char   PDBINDEX;       /* 10 3211 FCB INDEX VALUE                  */
    unsigned char   PDBFUNC;        /* 11 3525 FUCTION BYTE                     */
    unsigned char   PDBFLAG2;       /* 12 SECOND FLAG BYTE                      */
#define PDB2TCEL    0x80            /* ... DATA SET IS TRAKCELL'ED              */
#define PDB2OPTJ    0x40            /* ... OPTCD=J SPECIFIED                    */
#define PDB2BRST    0x20            /* ... BURST=YES SPECIFIED                  */
#define PDB2HDST    0x10            /* ... HOLD DATA SET AT DESTINATION         */
#define PDB2JFMS    0x08            /* ... PDBFORMS SET FROM JCTFORMS           */
#define PDB2HLDS    0x04            /* ... DATA SET SPECIFICALLY HELD           */
#define PDB2NEWS    0x01            /* ... JESNEWS DATA SET                     */

    unsigned char   PDBCPTN;        /* 13 COMPACTION TABLE NUMBER               */
    unsigned int    PDBRECCT;       /* 14 DATA SET RECORD COUNT                 */
    unsigned char   PDBFORMS[4];    /* 18 FOUR-BYTE FORMS NUMBER                */
    unsigned char   PDBFCB[4];      /* 1C FOUR-BYTE 3211 FCB ID                 */
    unsigned char   PDBUCS[4];      /* 20 FOUR-BYTE 1403 OR 3211 UCS ID         */
    unsigned char   PDBWTRID[8];    /* 24 EIGHT-BYTE OUTPUT WRITER ID           */
#define PDBDSID     PDBWTRID        /* 24 DATASET IDENTIFICATION                */
    unsigned char   PDBRBA[8];      /* 2C EIGHT-BYTE CHECKPOINT RECORD          */
    unsigned char   PDBCHAR1[4];    /* 34 N/I  PRINTER XLATE TAB 1              */
    unsigned char   PDBCHAR2[4];    /* 38 N/I  PRINTER XLATE TAB 2              */
    unsigned char   PDBCHAR3[4];    /* 3C N/I  PRINTER XLATE TAB 3              */
    unsigned char   PDBCHAR4[4];    /* 40 N/I  PRINTER XLATE TAB 4              */
    unsigned char   PDBFLASH[4];    /* 44 N/I  PRINTER FLASH CART ID            */
    unsigned char   PDBMODF[4];     /* 48 N/I  PRINTER COPY MOD IMAGE           */
    unsigned char   PDBFLSHC;       /* 4C N/I  PRINTER # FLASH COPIES           */
    unsigned char   PDBMODFT;       /* 4D N/I  PRINTER TBL REF CHAR             */
    unsigned char   PDBCOPYG[8];    /* 4E N/I  PRINTER COPY GROUPS              */
    unsigned short  PDBCKPTP;       /* 56 NO. OF LOGICAL PAGES/CKPT             */
    unsigned short  PDBCKPTL;       /* 58 NO. OF LINES/LOGICAL PAGE             */
    unsigned char   PDBFLAG3;       /* 5A THIRD FLAG BYTE                       */
#define PDBF3RV1    0x80            /* ... RESERVED                             */
#define PDBF3RV2    0x40            /* ... RESERVED                             */
#define PDBF3RV3    0x20            /* ... RESERVED                             */
#define PDBF3RV4    0x10            /* ... RESERVED                             */
#define PDB3BRST    0x08            /* ... BURST (Y OR N) IN DD CARD            */
#define PDBF3RV6    0x04            /* ... RESERVED                             */
#define PDBF3RV7    0x02            /* ... RESERVED                             */
#define PDBF3RV8    0x01            /* ... RESERVED                             */

    unsigned char   __1;            /* 5B RESERVED (FULLWORD ALIGN)             */
    unsigned char   PDBSSOFM[4];    /* 5C                                       */
    unsigned char   __2[8];         /* 60 RESERVED                              */
};                                  /* 68                                       */
#define PDBLENG  sizeof(__PDDB)     /* 68 PDDB LENGTH                           */

#endif
