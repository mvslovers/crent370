#ifndef CLIBLIST_H
#define CLIBLIST_H

typedef struct dslist   DSLIST; 	/* a dataset list record            */
typedef struct pdslist  PDSLIST;	/* a PDS member list                */
typedef struct ispfdata ISPFDATA;   /* ISPF statistics data (udata)     */
typedef struct loaddata LOADDATA;   /* Load module data (udata)         */
typedef struct loads01  LOADS01;    /* Scatter load table           	*/
typedef struct loads02  LOADS02;    /* Alias names                  	*/
typedef struct loads03  LOADS03;    /* SSI info (half word aligned) 	*/
typedef struct loads04  LOADS04;    /* APF info                     	*/
typedef struct ispfstat ISPFSTAT;   /* formatted ISPF statistics        */
typedef struct loadstat LOADSTAT;   /* formatted Load module statistics */
typedef struct vollist	VOLLIST;	/* DASD volume list					*/

/* DASD volume list */
struct vollist {
	char 			volser[7];	/* 00 DASD volume serial				*/
	unsigned char 	status;		/* 07 volume status						*/
#define VOLLIST_STATUS_ONLI 0x80/* ... UCBSTAT = ONLINE					*/
#define VOLLIST_STATUS_RESV 0x40/* ... UCBSTAT = RESERVED				*/
#define VOLLIST_STATUS_PRES 0x20/* ... UCBSTAT = PERM RESIDENT			*/
#define VOLLIST_STATUS_X10	0x10/* ... unused							*/
#define VOLLIST_STATUS_PRV	0x08/* ... UCBSTAB = PRIVATE				*/
#define VOLLIST_STATUS_PUB	0x04/* ... UCBSTAB = PUBLIC					*/
#define VOLLIST_STATUS_STG 	0x02/* ... UCBSTAB = STORAGE				*/
#define VOLLIST_STATUS_X01	0x01/* ... unused							*/	
	void			*ucbdasd;	/* 08 UCB address (UCBDASD iecvucb.h)	*/
	unsigned short  cuu;		/* 0C channel unit (0x0cuu)				*/
	unsigned short  dasdtype;	/* 0E DASD type (0x3350,0x3380,0x3390)	*/
	/* The following values are returned for LSPACE when requested */
	unsigned 		freecyls;	/* 10 free cylinders					*/
	unsigned		freetrks;	/* 14 free tracks						*/
	unsigned		freeexts;	/* 18 free extents						*/
	unsigned		maxfreecyls;/* 1C largest free cylinders			*/
	unsigned 		maxfreetrks;/* 20 largest free tracks				*/
	/* The following values are returned when vatlst is requested */
	char 			*comment;	/* 24 Comment from VATLSTxx				*/
};								/* 28 (40 bytes)						*/

/* __listvl() - return list of volumes matching filter or ALL if
** 		filter is NULL.
**		if dolspace is not zero then request volume free space information.
**		if vatlst is specified the comments from the vatlst is returned.
**		Note: if vatlst is a member name then SYS1.PARMLIB(vatlst) will
**		be opened otherwise vatlst should be a dataset(member) name for
**		the vatlst dataset or NULL.
*/
extern VOLLIST **__listvl(	const char *filter, 
							int dolspace, 
							const char *vatlst) 
							asm("@@LISTVL");

extern void __freevl(		VOLLIST ***vollst) 
							asm("@@FREEVL");

/* dataset list record */
struct dslist {
    char            dsn[45];    /* dataset name                         */
    char            volser[7];  /* first volume for dataset             */
    char            dsorg[5];   /* dataset org: "PS|PO|VS|..."          */
    char            recfm[5];   /* dataset format: "F|FB|FBA|FBM|..."   */
    unsigned short  extents;    /* number of extents on volume          */
    unsigned short  lrecl;      /* logical record length                */
    unsigned short  blksize;    /* physical block size                  */

    unsigned short  cryear;     /* created year: 1980, 2079             */
    unsigned short  crjday;     /* created julian day: 1, 366           */
    unsigned char   crmon;      /* created month: 1, 12                 */
    unsigned char   crday;      /* created day of month: 1, 31          */

    unsigned short  rfyear;     /* last reference year                  */
    unsigned short  rfjday;     /* last reference julian day            */
    unsigned char   rfmon;      /* last reference month                 */
    unsigned char   rfday;      /* last reference day of month          */
};

/* PDS member record */
struct pdslist {
    char            name[8];    /* member name                          */
    unsigned char   ttr[3];     /* relative address                     */
    unsigned char   idc;        /* alias/ttrs/udata size                */
#define PDSLIST_IDC_ALIAS   0x80/* ... member name is an alias          */
#define PDSLIST_IDC_TTRS    0x60/* ... number of TTR's in user data     */
#define PDSLIST_IDC_UDATA   0x1F/* ... udata size in half words         */
    unsigned char   udata[0];   /* start of user data                   */
};

/* ISPF user data */
struct ispfdata {
    unsigned char   ver;        /* version number X'01' to X'99'        */
    unsigned char   mod;        /* modification number X'00' to X'99'   */
    unsigned char   flags;      /* flags                                */
#define ISPFDATA_FLAG_SCLM  0x80/* ... last edited by SCLM              */

    unsigned char   seconds;    /* last modified seconds packed         */
    unsigned char   crecent;    /* created century. 0=1900, 1=2000      */
    unsigned char   creydd[3];  /* created julian date packed           */
    unsigned char   modcent;    /* modified century. 0=1900, 1=2000     */
    unsigned char   modydd[3];  /* modified julian date packed          */
    unsigned char   modhm[2];   /* modified time hour,min packed        */
    unsigned short  curlines;   /* current number of lines              */
    unsigned short  initlines;  /* initial number of lines              */
    unsigned short  modlines;   /* modified lines                       */
    char            userid[8];  /* userid                               */
    char            unused[2];  /* unused/reserved                      */
};

/* ISPF statistics from PDSLIST record (recfm=F|V) */
struct ispfstat {
    char            name[9];    /* "member\0"                           */
    char            ttr[7];     /* "ttttrr\0"                           */
    char            ver[6];     /* "vv.mm\0"                            */
    char            created[9]; /* "yy-mm-dd\0"                         */
    char            changed[18];/* "yy-mm-dd hh:mm:ss\0"                */
    char            init[6];    /* "nnnnn\0"                            */
    char            size[6];    /* "nnnnn\0"                            */
    char            mod[6];     /* "nnnnn\0"                            */
    char            userid[9];  /* "username\0"                         */
};

/* ISPF statistics from PDSLIST record (recfm=U) */
struct loadstat {
    char            name[9];    /* "member\0"                           */
    char            ttr[7];     /* "ttttrr\0"                           */
    char            size[7];    /* "xxxxxx\0"                           */
    char            aliasof[9]; /* "member\0"                           */
    char            ac[3];      /* "xx\0"                               */
    char            ep[7];      /* "xxxxxx\0"                           */
    char            attr[24];   /* "NE OL PG RF RN RU OV TS\0"          */
    char            ssi[9];     /* "xxxxxxxx\0"                         */
};

struct loaddata {
    unsigned char   loadttrt[3];/* TTR OF FIRST BLOCK OF TEXT           */
    unsigned char   loadzero;   /* ZERO                                 */
    unsigned char   loadttrn[3];/* TTR OF NOTE LIST OR SCATTER/TRANSLATION
                                   TABLE.  USED FOR MODULES IN SCATTER LOAD
                                   FORMAT OR OVERLAY STRUCTURE ONLY.    */
    unsigned char   loadnl;     /* NUMBER OF ENTRIES IN NOTE LIST FOR
                                   MODULES IN OVERLAY STRUCTURE,
                                   OTHERWISE ZERO                       */
    unsigned char   loadatr1;   /* FIRST BYTE OF MODULE ATTRIBUTE FIELD */
#define LOADRENT    0x80        /* ... REENTERABLE                      */
#define LOADREUS    0x40        /* ... REUSABLE                         */
#define LOADOVLY    0x20        /* ... IN OVERLAY STRUCTURE             */
#define LOADTEST    0x10        /* ... MODULE TO BE TESTED - TESTRAN    */
#define LOADLOAD    0x08        /* ... ONLY LOADABLE                    */
#define LOADSCTR    0x04        /* ... SCATTER FORMAT                   */
#define LOADEXEC    0x02        /* ... EXECUTABLE                       */
#define LOAD1BLK    0x01        /* ... IF ZERO, MODULE CONTAINS MULTIPLE
                                       RECORDS WITH AT LEAST ONE BLOCK
                                       OF TEXT.
                                       IF ONE, MODULE CONTAINS NO RLD ITEMS
                                       AND ONLY ONE BLOCK OF TEXT.      */

    unsigned char   loadatr2;   /* SECOND BYTE OF MODULE ATTRIBUTE FIELD*/
#define LOADFLVL    0x80        /* ... IF ZERO, MODULE CAN BE PROCESSED
                                       BY ALL LEVELS OF LINKAGE EDITOR.
                                       IF ONE, MODULE CAN BE PROCESSED ONLY
                                       BY F LEVEL OF LINKAGE EDITOR.    */
#define LOADORG0    0x40        /* ... LINKAGE EDITOR ASSIGNED ORIGIN OF
                                       FIRST BLOCK OF TEXT IS ZERO.     */
#define LOADEP0     0x20        /* ... ENTRY POINT ASSIGNED BY LINKAGE
                                       EDITOR IS ZERO                   */
#define LOADNRLD    0x10        /* ... MODULE CONTAINS NO RLD ITEMS     */
#define LOADNREP    0x08        /* ... MODULE CANNOT BE REPROCESSED BY
                                       LINKAGE EDITOR                   */
#define LOADTSTN    0x04        /* ... MODULE CONTAINS TESTRAN SYMBOL CARDS */
#define LOADLEF     0x02        /* ... MODULE CREATED BY LINKAGE EDITOR F */
#define LOADREFR    0x01        /* ... REFRESHABLE MODULE               */

    unsigned char   loadstor[3];/* TOTAL CONTIGUOUS MAIN STORAGE
                                   REQUIREMENT OF MODULE                */
    unsigned char   loadftbl[2];/* LENGTH OF FIRST BLOCK OF TEXT        */
    unsigned char   loadepa[3]; /* ENTRY POINT ADDRESS ASSOCIATED WITH
                                   MEMBER NAME OR WITH ALIAS NAME IF
                                   ALIAS INDICATOR IS ONE               */

    unsigned char   loadftb1;   /* BYTE 1 OF PDS2FTBO                   */
#define LOADOSLE    0x80        /* ... MODULE HAS BEEN PROCESSED BY AOS
                                       LINKAGE EDITOR                   */
/*       BIT1 IS RESERVED TO INDICATE ANOTHER EXPANSION WHEN IT
         BECOMES NECESSARY                                              */
#define LOADPAGA    0x20        /* ... PAGE ALIGNMENT REQUIRED FOR LOAD
                                       MODULE                           */
#define LOADSSI     0x10        /* ... SSI INFORMATION PRESENT          */
#define LOADAPFLG   0x08        /* ... INFORMATION IN LOADAPF IS VALID  */

    unsigned char   loadftb2;   /* BYTE 2 OF PDS2FTBO                   */
    unsigned char   loadftb3;   /* BYTE 3 OF PDS2FTBO                   */
    unsigned char   loadbcend[0];   /* END OF BASIC SECTION             */
};

/* THE FOLLOWING SECTION IS FOR LOAD MODULES WITH SCATTER LOAD */
struct loads01 {                /* START OF SCATTER LOAD SECTION        */
    unsigned short  loadslsz;   /* NUMBER OF BYTES IN SCATTER LIST      */
    unsigned short  loadttsz;   /* NUMBER OF BYTES IN TRANSLATION TABLE */
    unsigned short  loadesdt;   /* IDENTIFICATION OF ESD ITEM (ESDID) OF
                                   CONTROL SECTION TO WHICH FIRST BLOCK
                                   OF TEXT BELONGS                      */
    unsigned short  loadesdc;   /* IDENTIFICATION OF ESD ITEM (ESDID) OF
                                   CONTROL SECTION CONTAINING ENTRY POINT */
    unsigned char   load01nd[0];/* END OF SCATTER LOAD SECTION          */
};

/* THE FOLLOWING SECTION IS FOR LOAD MODULES WITH ALIAS NAMES    */
struct loads02 {                /* START OF ALIAS SECTION               */
    unsigned char   loadepm[3]; /* ENTRY POINT FOR MEMBER NAME          */
    unsigned char   loadmnm[8]; /* MEMBER NAME OF LOAD MODULE.  WHEN THE
                                   FIRST FIELD (PDS2NAME) IS AN ALIAS NAME,
                                   THIS FIELD CONTAINS THE ORIGINAL NAME OF
                                   THE MEMBER EVEN AFTER THE MEMBER HAS
                                   BEEN RENAMED.  (MDC302)              */
    unsigned char   load02nd[0];/* END OF ALIAS SECTION                 */
};

/* THE FOLLOWING SECTION IS FOR SSI INFORMATION AND IS ON
** A HALF-WORD BOUNDARY
*/
struct loads03 {                /* FORCE HALF-WORD ALIGNMENT FOR SSI SECTION */
    unsigned char   loadchlvl;  /* CHANGE LEVEL OF MEMBER               */
    unsigned char   loadssifb;  /* SSI FLAG BYTE                        */
#define LOADFORCE   0x40        /* ... A FORCE CONTROL CARD WAS USED WHEN
                                       EXECUTING THE IHGUAP PROGRAM     */
#define LOADUSRCH   0x20        /* ... A CHANGE WAS MADE TO MEMBER BY THE
                                       INSTALLATION, AS OPPOSED TO AN
                                       IBM-DISTRIBUTED CHANGE           */
#define LOADEMFIX   0x10        /* ... SET WHEN AN EMERGENCY IBM-AUTHORIZED
                                       PROGRAM 'FIX' IS MADE, AS OPPOSED TO
                                       CHANGES THAT ARE INCLUDED IN AN
                                       IBM-DISTRIBUTED MAINTENANCE PACKAGE */
#define LOADDEPCH   0x08        /* ... A CHANGE MADE TO THE MEMBER IS
                                       DEPENDENT UPON A CHANGE MADE TO
                                       SOME OTHER MEMBER IN THE SYSTEM  */
#define LOADSYSGN   0x06        /* ... BIT5+BIT6 - FLAGS THAT INDICATE
                                       WHETHER OR NOT A CHANGE TO THE
                                       MEMBER WILL NECESSITATE A PARTIAL
                                       OR COMPLETE REGENERATION OF THE
                                       SYSTEM                           */
#define LOADNOSGN   0x00        /* ... NOT CRITICAL FOR SYSTEM GENERATION */
#define LOADCMSGN   0x02        /* ... MAY REQUIRE COMPLETE REGENERATION */
#define LOADPTSGN   0x04        /* ... MAY REQUIRE PARTIAL REGENERATION */
#define LOADIBMMB   0x01        /* ... MEMBER IS SUPPLIED BY IBM        */

    unsigned char   loadmbrsn[2];/* MEMBER SERIAL NUMBER                */
    unsigned char   load03nd[0];/* END OF SSI SECTION                   */
};

/* THE FOLLOWING SECTION IS FOR APF INFORMATION                         */
struct loads04 {                /* START OF APF SECTION                 */
    unsigned char   loadapfct;  /* LENGTH OF PROGRAM AUTHORIZATION CODE
                                   (PDSAPFAC) IN BYTES                  */
    unsigned char   loadapfac;  /* PROGRAM AUTHORIZATION CODE           */
    unsigned char   load04nd[0];/* END OF APF SECTION                   */
};


/* __listc() - envokes IDCAMS LISTC LEVEL('level') to a temp file
**             and then reads records from the temp file passing
**             each record to the (*prt) function.
**
**             option may be NULL or a string of the option keywords
**             allowed by the IDCAMS LISTC command.
**
** returns the IDCAMS return code.
*/
extern int      __listc(const char *level, const char *option,
                    int (*prt)(void *udata, const char *fmt, ...),
                    void *udata);

/* __listds() - returns array of DSLIST records for level
**              with optional dataset name filter.
**              uses the __listc() function to obtain dataset and
**              volume names and then calls __dscbdv() to obtain
**              the DSCB info for each dataset and volume returned.
*/
extern DSLIST **__listds(const char *level,     /* "HLQ.TEST"       */
                         const char *option,    /* "NONVSAM VOLUME" */
                         const char *filter);   /* "HLQ.TEST.*DATA" */

/* __freeds() - free DSLIST array created by __listds() */
extern void     __freeds(DSLIST ***dslist);

/* __listpd() - returns array of PDSLIST records for a PDS dataset.
**              optional filter pattern string can be supplied
**              to filter by PDS member name.
*/
extern PDSLIST **__listpd(const char *dataset, const char *filter);

/* __freepd() - free PDSLIST array created by __listpd() */
extern void     __freepd(PDSLIST ***pdslist);

/* __fmtisp() - format PDSLIST values into ISPFSTAT record */
extern int      __fmtisp(PDSLIST *pdslist, ISPFSTAT *ispfstat);

/* __fmtloa() - format PDSLIST values into LOADSTAT record */
extern int      __fmtloa(PDSLIST *pdslist, LOADSTAT *loadstat);

#endif
