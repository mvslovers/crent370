#ifndef ACEE_H
#define ACEE_H

typedef struct acee         ACEE;
typedef struct conngrp      CONNGRP;

struct conngrp {
    CONNGRP *next;              /* 00 next connect group                    */
    char    group[9];           /* 04 1 byte len, group name                */
};

struct acee {                   /* ACCESSOR ENVIRONMENT ELEMENT             */
    char    aceeacee[4];        /* 00 ACRONYM IN EBCDIC -ACEE-              */
    char    aceesp;             /* 04 ACEE SUBPOOL NUMBER                   */
    char    aceelen[3];         /* 05 LENGTH OF ACEE                        */
    char    aceevrsn;           /* 08 ACEE VERSION NUMBER = 1.              */
    char    unused1[3];         /* 09 RESERVED                              */
    void    *aceeiep;           /* 0C RESERVED FOR INSTALLATION             */
    void    *aceeinst;          /* 10 ADDRESS OF INSTALLATION SUPPLIED
                                      USER DATA - FROM USER ENTRY           */
    char    aceeuser[9];        /* 14 USERID INFORMATION                    */
    char    aceegrp[9];         /* 1D GROUP NAME INFORMATION                */
    char    aceeflg1;           /* 26 USER FLAGS                            */
#define ACEESPEC    0x80        /* ... 1 - SPECIAL ATTRIBUTE                */
#define ACEEADSP    0x40        /* ... 1 - AUTOMATIC DATA SECURITY
                                           PROTECTION                       */
#define ACEEOPER    0x20        /* ... 1 - OPERATIONS ATTRIBUTE             */
#define ACEEAUDT    0x10        /* ... 1 - AUDITOR ATTRIBUTE                */
#define ACEELOGU    0x08        /* ... 1 - USER IS TO HAVE MOST RACF
                                           FUNCTIONS LOGGED                 */
#define ACEEPRIV    0x02        /* ... 1 - USER IS A STARTED PROCEDURE
                                           WITH THE PRIVELEGED ATTRIBUTE    */
#define ACEERACF    0x01        /* ... 1 - RACF DEFINED USER                */

    char    aceeflg2;           /* 27 DEFAULT UNIVERSAL ACCESS              */
#define ACEEALTR    0x80        /* ... 1 - ALTER AUTORITY TO RESOURCE       */
#define ACEECNTL    0x40        /* ... 1 - CONTROL AUTHORITY TO RESOURCE    */
#define ACEEUPDT    0x20        /* ... 1 - UPDATE AUTHORITY TO RESOURCE     */
#define ACEEREAD    0x10        /* ... 1 - READ AUTHORITY TO RESOURCE       */
#define ACEENONE    0x01        /* ... 1 - NO AUTHORITY TO RESOURCE         */

    char    aceeflg3;           /* 28 MISCELLANEOUS FLAGS                   */
#define ACEEGRPA    0x80        /* ... ACCESS LIST OF GROUP DS TO CONTAIN
                                       0 - USERID
                                       1 - GROUP NAME AND USERID            */
    char    aceedate[3];        /* 29 DATE OF RACINIT                       */

    char    aceeproc[8];        /* 2C NAME OF STARTED PROC OR BLANKS
                                      IF NOT A STARTED PROC                 */
    void    *aceetrmp;          /* 34 ADDRESS OF TERMINAL RELATED
                                      INFORMATION. ZERO FOR NON-TERMINAL
                                      USERS                                 */
    char    aceeflg4[2];        /* 38 MISCELLANEOUS FLAGS 2                 */
#define ACEEUATH    0x20        /* ... 1 - USER IS AUTHORIZED TO DEFINE
                                           OTHER USERS                      */
#define ACEEDASD    0x08        /* ... 1 - USER IS AUTHORIZED TO PROTECT
                                           DASD VOLUMES                     */
#define ACEETAPE    0x04        /* ... 1 - USER IS AUTHORIZED TO PROTECT
                                           TAPE VOLUMES                     */
#define ACEETERM    0x02        /* ... 1 - USER IS AUTHORIZED TO PROTECT
                                           TERMINALS                        */

    char    aceeaplv;           /* 3A APPLICTAION LEVEL NUMBER              */
    char    aceetrlv;           /* 3B TERMINAL LEVEL NUMBER                 */

    void    *aceetrda;          /* 3C ADDRESS OF INSTALLATION SUPPLIED
                                      DATA FROM TERMINAL ENTRY              */

    char    aceetrid[8];        /* 40 TERMINAL ID                           */
    void    *aceeamp;           /* 48 ADDRESS 1ST ANCHORED MODEL            */
    char    aceeclth[4];        /* 4C USER CLASS AUTHORIZATIONS -
                                      THESE BIT POSITIONS ARE MAPPED
                                      BY THE CLASS DESCRIPTOR ENTRIES
                                      ANCHORED OFF THE RACF CVT             */

    void    *aceeclcp;          /* 50 ANCHOR FOR INSTORAGE PROFILE
                                      TREES BUILT BY THE RACLIST FUNCTION   */
    void    *aceeaptr;          /* 54 ADDRESS FIELD RESERVED FOR
                                      APPLICATION USAGE                     */
    char    aceeapln[8];        /* 58 NAME OF APPLICATION TO WHICH
                                      USER IS CONNECTED OR BLANKS
                                      IF NO APPLICATION SPECIFIED           */

    void    *aceeapda;          /* 60 ADDRESS INSTALLATION SUPPLIED
                                      DATA FROM APPLICATION ENTRY           */
    void    *aceeunam;          /* 64 ADDRESS OF USER NAME STRING.
                                      ZERO, IF NO NAME PRESENT.
                                      IF PRESENT, THE FIRST BYTE IS
                                      A LENGTH FIELD FOLLOWED BY THE
                                      NAME STRING.                          */
    void    *aceemdls;          /* 68 ADDRESS OF THE MODEL NAME
                                      ARRAY. ZERO, IF ARRAY NOT
                                      OBTAINED BY RACINIT.                  */
    CONNGRP *aceecgrp;          /* 6C ADDRESS OF TABLE CONTAINING
                                      THE LIST OF GROUPS THIS
                                      USERID IS A MEMBER OF.                */

    void    *aceegata;          /* 70 ADDRESS OF THE GENERIC ANCHOR TABLE   */
    void    *aceefcgp;          /* 74 ADDRESS OF LIST OF GROUPS USER
                                      IS A MEMBER OF, BUILT BY RACINIT,
                                      USED BY FRACHECK, IT IS NOT
                                      AUTOMATICALLY REFRESHED               */
    unsigned unused2[6];        /* 78 RESERVED.                             */
};                              /* 90 (144)                                 */

#endif
