#ifndef HASPCMB_H
#define HASPCMB_H

/* HASP CONSOLE MESSAGE BUFFER (CMB) DSECT */
typedef struct haspcmb  HASPCMB;
typedef struct haspcmb  CMB;

struct haspcmb {
    HASPCMB     *cmbcmb;        /* 00 NEXT CMB BUFFER               */
    char        cmbflag;        /* 04 FLAG BYTE                     */
#define CMBFLAGC    0x80        /* ... CMB CONTAINS A COMMAND       */
#define CMBFLAGW    0x40        /* ... CMBOUT HAS REMOTE WORKSTATION NUMB */
#define CMBFLAGT    0x20        /* ... CMBOUT HAS TSO USER ID       */
#define CMBFLAGU    0x10        /* ... CMBOUT HAS UCMID INFORMATION */
#define CMBFLAGR    0x08        /* ... CONSOLE IS ONLY REMOTE AUTHORIZED */
#define CMBFLAGJ    0x04        /* ....CONSOLE NOT JOB AUTHORIZED   */
#define CMBFLAGD    0x02        /* ... CONSOLE NOT DEVICE AUTHORIZED*/
#define CMBFLAGS    0x01        /* ... CONSOLE NOT SYSTEM AUTHORIZED*/

// CMBLEVEL DC    0X'0'               IMPORTANCE LEVEL (HIGH 4 BITS)    
    char        cmbprio;        /* 05 OUTPUT PRIORITY (LOW 4 BITS)  */
    char        cmbtype;        /* 06 TYPE BYTE                     */
#define CMBTYPEX    0xF0        /* ... RESERVED BITS                */
#define CMBTYPED    0x01        /* ... FORMATTED DOM CMB            */

    char        cmbml;          /* 07 LENGTH OF MESSAGE             */

// CMBTO    DC    0XL2'0'             TO SYSTEM                         
    char        cmbtosys;       /* 08 SYSTEM ID                     */
    char        cmbtoqul;       /* 09 QUALIFIER                     */
    union {
        char    cmbout[8];      /* 0A LOCAL OUTPUT INFORMATION      */
        struct {                /* 0A FORMAT FOR UCMID MESSAGES     */
            char cmbucm;        /* 0A MCS CONSOLE ID                */
            char cmbucma;       /* 0B MCS CONSOLE AREA              */
            char cmblinet[2];   /* 0C LINE TYPE FOR MLWTO           */
        };
        struct {                /* 0A FORMAT FOR LOGICAL ROUTED MESSAGE */
            char cmbdesc[2];    /* 0A MCS DESCRIPTOR CODES          */
            char cmbrout[2];    /* 0C MCS CONSOLE ROUTINGS          */
            char cmbdomid[4];   /* 0E MCS DOM ID                    */
        };
        struct {                /* 0A FORMAT FOR REMOTE MESSAGES    */
            char cmbrmt;        /* 0A REMOTE NUMBER                 */
        };
        struct {                /* 0A FORMAT FOR TSO USER MESSAGES  */
            char cmbuser[8];    /* 0A TSO USER ID                   */
        };
    };

// CMBFM    DC    0XL2'0'             FROM SYSTEM                       
    char        cmbfmsys;       /* 12 SYSTEM ID                     */
    char        cmbfmqul;       /* 13 QUALIFIER                     */

// CMBMSG   DC    0CL132' '           CONSOLE MESSAGE                   
    char        cmbtime[8];     /* 14 TIME STAMP FOR REMOTE SYSTEMS */
    char        _1c;            /* 1C SPACER                        */
    char        cmbjobid[8];    /* 1D JOB ID                        */
    char        _25;            /* 25 SPACER                        */
    char        cmbmid[9];      /* 26 MESSAGE ID FIELD              */
    char        cmbjobn[8];     /* 2F JOB NAME                      */
    char        _37;            /* 37 SPACER                        */
// CMBTEXT  DC    CL(L'CMBMSG-(*-CMBMSG))' ' MESSAGE TEXT               
    char        cmbtext[96];    /* 38 MESSAGE TEXT                  */
};                              /* 98 (152 bytes)                   */

#define CMBL    sizeof(HASPCMB);

#endif  /* HASPCMB_H */
