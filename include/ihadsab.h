#ifndef IHADSAB_H
#define IHADSAB_H

typedef struct dsab     DSAB;       /* DATA SET ASSOCIATION BLOCK           */
typedef struct dsabanmi DSABANMI;   /* ALTERNATE DSNAME INFORMATION         */
typedef struct dsabgidl DSABGIDL;   /* DEVICE GROUP-ID LIST                 */

struct dsab {
    char            dsabid[4];      /* 00 IN-CORE ID,CHARACTERS 'DSAB       */
    DSAB            *dsabfchn;      /* 04 NEXT DSAB PTR, 0 IF LAST          */
    DSAB            *dsabbchn;      /* 08 PREVIOUS DSAB PTR,0 IF FIRST      */
    unsigned char   dsablnth;       /* 0C LENGTH OF DSAB                    */
    unsigned short  dsabopct;       /* 0E OPEN DCB COUNT FOR TIOT DD ENTRY  */
    void            *dsabtiot;      /* 10 TIOT DD ENTRY PTR                 */
    char            dsabrs01;       /* 14 RESERVED                          */
    unsigned char   dsabssva[3];    /* 15 SWA VIRTUAL ADDRESS OF SIOT       */
    void            *dsabgidp;      /* 18 DEVICE GROUP-ID LIST PTR          */
    void            *dsabanmp;      /* 1C &NAME OR GDG-ALL DSNAME PTR,     
*                                      0 IF NONE                            */
    union {
        char        dsaborg[2];     /* 20 DATA SET  ORGANIZATION            */
        struct {
            unsigned char dsaborg1; /* 20 1ST BYTE OF DSORG FLAGS           */
#define DSABIS      0x80            /* ... INDEXED SEQUENTIAL ORGANIZATION  */
#define DSABPS      0x40            /* ... PHYSICAL SEQUENTIAL ORGANIZATION */
#define DSABDA      0x20            /* ... DIRECT ACCESS ORGANIZATION       */
#define DSABCX      0x10            /* ... COMMUNICATIONS LINE GROUP        */
#define DSABCQ      0x08            /* ... DIRECT ACCESS MESSAGE QUEUE      */
#define DSABMQ      0x04            /* ... PROBLEM PROGRAM MESSAGE QUEUE    */
#define DSABPO      0x02            /* ... PARTITIONED ORGANIZATION         */
#define DSABU       0x01            /* ... UNMOVEABLE                       */

            unsigned char dsaborg2; /* 21 2ND BYTE OF DSORG FLAGS           */
#define DSABGS      0x80            /* ... GRAPHICS ORGANIZATION            */
#define DSABTX      0x40            /* ... TCAM LINE GROUP                  */
#define DSABTQ      0x20            /* ... TCAM MESSAGE QUEUE               */
#define DSABAM      0x08            /* ... VSAM                             */
#define DSABTR      0x04            /* ... TCAM 3705                        */
        };  /* unnamed struct */
    }; /* unnamed union */

    unsigned char   dsabflg1;       /* 22 FLAGS-RESTORED BY RESTART         */
#define DSABDALC    0x80            /* ... DYNAMICALLY ALLOCATED            */
#define DSABPALC    0x40            /* ... PERMANENTLY ALLOCATED ATTRIBUTE  */
#define DSABDCNV    0x20            /* ... DYNAMICALLY CONVERTED            */
#define DSABCONV    0x10            /* ... CONVERTIBLE ATTRIBUTE            */
#define DSABDCAT    0x08            /* ... DYNAMICALLY CONCATENATED         */
#define DSABPCAT    0x04            /* ... PERMANENTLY CONCATENATED         */
#define DSABCATM    0x02            /* ... CONCATENATED GROUP MEMBER        */
#define DSABNUSE    0x01            /* ... IN-USE ATTRIBUTE                 */

    unsigned char   dsabflg2;       /* 23 FLAGS-RESTORED BY RESTART         */
#define DSABOPEN    0x80            /* ... DATA SET HAS BEEN OPENED         */
#define DSABIRM     0x40            /* ... D.S. REVERSED MERGED FOR INPUT   */
#define DSABUNAL    0x20            /* ... UNALLOCATE WHEN CLOSED           */

    unsigned char   dsabflg3;       /* 24 FLAGS-NOT RESTORED BY RESTART     */
#define DSABDEFR    0x80            /* ... DEFERRED MOUNTING                */
#define DSABPASS    0x40            /* ... PASS/RETAIN IND         @ZD03010 */
#define DSABVAM     0x20            /* ... VAM DATA SET                     */
#define DSABVMSC    0x10            /* ... VAM PAGING SPACE RELEASED        */
#define DSABCATL    0x08            /* ... DATA SET IS A CATALOG            */
#define DSABJSCT    0x04            /* ... JOBCAT OR STEPCAT DATA SET       */
#define DSABVVDS    0x02            /* ... VVDS - ICF CATALOG      @ZA60075 */

    unsigned char   dsabflg4;       /* 25 FLAGS-NOT RESTORED BY RESTART     */
#define DSABCKDS    0x80            /* ... THIS IS A CHECKPT DATA SET       */
#define DSABCKVL    0x40            /* ... VOLUME CONTAINING CHECKPT        
*                                          DATA SET IS SECURE               */
#define DSABCKSI    0x20            /* ... SECURITY INTERFACE EXISTS FOR    
*                                          THE CHECKPT DATA SET             */

    char            dsabrs02[2];    /* 26 RESERVED                          */
    void            *dsabtcbp;      /* 28 TCB UNDER WHICH SET IN-USE        */
    void            *dsabpttr;      /* 2C RELATIVE TTR OF DATA SET         
*                                         PASSWORD                          */
    char            dsabssnm[4];    /* 30 SUB-SYSTEM NAME                   */
    void            *dscbsscm;      /* 34 SUB-SYSTEM COMMUNICATION         
*                                         AREA POINTER                      */
    unsigned char   dsabdcbm[6];    /* 38 BIT MAP OF DCB FIELDS             */
    char            dsabrs03[2];    /* 3E RESERVED                          */

    void            *dsabsiot;      /* 40 SIOT IN-CORE ADDRESS              */
    unsigned        dsabrs04;       /* 44 RESERVED                          */
};
#define DSABL       sizeof(DSAB)    /* LENGTH OF DSECT                      */

struct dsabanmi {                   /* ALTERNATE DSNAME INFORMATION         */
    unsigned char   dsabanml;       /* 00 LENGTH OF ALTERNATE DSNAME        */
    unsigned char   dsabanam[1];    /* 01 ALTERNATE  DSNAME                 */
};
#define DSABANL     sizeof(DSABANMI)/* LENGTH OF DSECT                      */

struct dsabgidl {                   /* DEVICE GROUP-ID LIST                 */
    unsigned        dsabllen;       /* 00 DEVICE GROUP-ID LIST LENGTH       */
    char            dsabgrid[4];    /* 04 DEVICE GROUP-ID                   */
};


#endif
