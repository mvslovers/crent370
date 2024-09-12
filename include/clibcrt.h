#ifndef CLIBCRT_H
#define CLIBCRT_H

#include "clibgrt.h"                /* process level runtime work area      */

typedef struct clibcrt  CLIBCRT;    /* per thread runtime work area         */

#include "clibary.h"                /* dynamic array                        */

/* This structure holds data unique to each task/thread (TCB)
**
** When a task is created, a CLIBCRT is allocated and saved
** in the task CLIBPPA->PPACRT dynamic array. This occurs for both the main
** task via the startup code in @@CRT0.ASM and in the startup code in
** CTHREAD entry point.
**
** The CLIBPPA is found by calling the @@PPAGET entry point in @@CRT0.
**
** The CRTGRT field below is a pointer to the process (main) structure
** that holds data unique to the process regardless of how many
** task/threads are in use (global data).
*/
struct clibcrt {
    char        crteye[8];          /* 00 Eye catcher for dumps "CLIBCRT "  */
    void        *crttcb;            /* 08 Owning TCB                        */
    void        *crtsave;           /* 0C first save area address           */
    void        *crtacee;           /* 10 ACEE for this task/thread         */
    unsigned    crtseed;            /* 14 seed for rand()/srand()           */
    char        crtctime[28];       /* 18 result for asctime()/ctime()      */
    int         crttzoff;           /* 34 time zone offset                  */
    void        *crtstime;          /* 38 STIMER exit plist                 */
    unsigned    crtuserl;           /* 3C length of CRTUSER area            */
    unsigned    crthoste[10];       /* 40 hostent areas for DYN75           */
    char        crthostn[80];       /* 68 host name for DYN75               */
    int         crtestct;           /* B8 ESTAE stack count                 */
    unsigned    crtestpl[10*2];     /* BC ESTAE parameter list              */
    char        crtopts;            /* 10C copy of original JFCBOPTS byte   */
#define CRTOPTS_AUTH        0x01    /* ... JFCBAUTH bit for APF authorized  */
    char        crtauth;            /* 10D authorization flags              */
#define CRTAUTH_ON          0x80    /* ... task auth via __autask()         */
#define CRTAUTH_STEPLIB     0x40    /* ... steplib auth via __austep()      */
	char 		crtflag;			/* 10E processing flag(s)				*/
#define CRTFLAG_TSO			0x80	/* ... TSO environment					*/
#define CRTFLAG_TSOB		0x40	/* ... TSO background environment		*/
#define CRTFLAG_TIN			0x08	/* ... STDIN is terminal				*/
#define CRTFLAG_TOUT		0x04	/* ... STDOUT is terminal				*/
#define CRTFLAG_TERR		0x02	/* ... STDERR is terminal				*/
    char        unused;             /* 10F unused                           */
    int         crterrno;           /* 110 error number                     */
    char        *crtstrtk;          /* 114 used by strtok() for "old" ptr   */
    CLIBGRT     *crtgrt;            /* 118 process level C runtime anchor   */
    char        crttmpnm[12];       /* 11C tmpnam() buffer                  */
    char        crttms[4*9];        /* 128 struct tm for gmtime()           */
    void        **crtpush;          /* 14C push/pop function array          */
    void        **crtargs;          /* 150 push/pop arg array               */
    void        **crtmutx;          /* 154 mutex cleanup array              */
    void		*crtapp1;			/* 158 application use #1				*/
    void		*crtapp2;			/* 15C application use #2				*/
    void 		*crtufs;			/* 160 Unix "like" File System			*/
    unsigned    unused2;			/* 164 unused/available					*/
    char        crtntoa[16];        /* 168 "nnn.nnn.nnn.nnn" xxxx_ntoa()    */
    unsigned    crttryrc;			/* 178 return/abend code from try()     */
    unsigned    crtavail[3];		/* 17C unused/available					*/
};                                  /* 188 (392 bytes)                      */

extern CLIBCRT  *__crtget(void);
extern int      __crtset(void);
extern int      __crtres(void);


#endif
