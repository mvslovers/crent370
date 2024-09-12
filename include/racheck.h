#ifndef RACHECK_H
#define RACHECK_H

typedef struct racheck  RACHECK;
typedef struct raclass  RACLASS;
typedef struct raentity RAENTITY;

struct racheck {
    char    len;                    /* 00 length of racheck struct (plist)  */
    char    instdata[3];            /* 01 AL3(address of installation data) */
    char    flag1;                  /* 04 flags                             */
#define RACHECK_FLAG1_LOG_NONE	0x10/* ... LOG=(NONE)						*/
    char    entity[3];              /* 05 AL3(entity name)                  */
    char    attr;                   /* 08 attr flags                        */
#define RACHECK_ATTR_READ       0x02/* ... READ                             */
#define RACHECK_ATTR_UPDATE     0x04/* ... UPDATE                           */
#define RACHECK_ATTR_CONTROL    0x08/* ... CONTROL                          */
#define RACHECK_ATTR_ALTER      0x80/* ... ALTER                            */

    char    aclass[3];              /* 09 AL3(class name)                   */

    char    flag2;                  /* 0C flags                             */
    char    volser[3];              /* 0D AL3(volser name)                  */

    void    *oldvolser;             /* 10 old volser addr                   */
    void    *appl;                  /* 14 appl                              */
    void    *acee;                  /* 18 ACEE                              */
    void    *owner;                 /* 1C owner                             */
    void    *unused[4];             /* 20 unused                            */
    void    *access1;               /* 30 access value address              */
    void    *access2;               /* 34 2nd access address                */
};

struct raclass {
	char    len;					/* 00 length of class name				*/
	char    name[8];				/* 01 class name						*/
};

struct raentity {
	char	name[40];				/* 00 entity name						*/
};

#endif
