#ifndef RACINIT_H
#define RACINIT_H

typedef struct racinit  RACINIT;

struct racinit {
    char    len;                    /* 00 list length                       */
    char    subpool;                /* 01 subpool number                    */
    char    unused1;                /* 02 reserved                          */
    char    flag;                   /* 03 flags from envir parm             */
#define RACINIT_FLAG_VERIFY   0x80  /* ... ENVIR=VERIFY                     */
#define RACINIT_FLAG_CHANGE   0x40  /* ... ENVIR=CHANGE                     */
#define RACINIT_FLAG_SMC      0x20  /* ... SMC=YES                          */
#define RACINIT_FLAG_SUBPOOL  0x10  /* ... SUBPOOL=nn                       */
#define RACINIT_FLAG_PASSCHK  0x08  /* ... PASSCHK=NO                       */
#define RACINIT_FLAG_STAT     0x04  /* ... STAT=NO                          */
/*                            0x02                                          */
#define RACINIT_FLAG_ENCRYPT  0x01  /* ... ENCRYPT=NO                       */
    void    *userid;                /* 04 userid address                    */
    void    *passwrd;               /* 08 password address                  */
    void    *start;                 /* 0C procedure name                    */
    void    *instln;                /* 10 installation parm address         */
    void    *group;                 /* 14 group address                     */
    void    *newpass;               /* 18 new password address              */
    void    *pgmname;               /* 1C program name address              */
    void    *actinfo;               /* 20 account info address              */
    void    *oidcard;               /* 24 oid card address                  */
    void    *termid;                /* 28 term id address                   */
    void    *jobname;               /* 2C job name address                  */
    void    *appl;                  /* 30 application name                  */
    void    *acee;                  /* 34 acee address                      */
};

#endif
