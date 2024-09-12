#ifndef CLIBGRT_H
#define CLIBGRT_H

#include "clibwsa.h"                /* process level writable static areas  */

typedef struct clibgrt  CLIBGRT;    /* per process runtime work area        */

#ifndef __SIZE_T_DEFINED
#define __SIZE_T_DEFINED
#if (defined(__OS2__) || defined(__32BIT__) || defined(__MVS__) \
    || defined(__CMS__) || defined(__VSE__))
typedef unsigned long size_t;
#elif (defined(__MSDOS__) || defined(__DOS__) || defined(__POWERC) \
    || defined(__WIN32__) || defined(__gnu_linux__))
typedef unsigned int size_t;
#endif
#endif

/* This structure holds data unique for the process (main)
** regardless of the number of task/threads.  The @@CRT0.ASM
** code allocates the CLIBGRT and anchors it in the task level
** CRTGRT field in the CLIBCRT structure.
**
** All of the task/thread level structures refer to the same
** process level CLIBGRT area via the CRTGRT value which is
** propogated from parent task to child task at startup of
** each child task.
*/
struct clibgrt {
    char        grteye[8];          /* 00 Eye catcher for dumps "CLIBGRT "  */
    short       grtclibl;           /* 08 length of CLIBGRT area            */
    char        grtflag1;           /* 0A flags                             */
#define GRTFLAG1_SOCKINIT   0x80    /* ... sockets initialized              */
#define GRTFLAG1_TSO        0x40    /* ... TSO environment                  */

    char        unused1;            /* 0B unused                            */
    unsigned    grttmpnm;           /* 0C tmpnam() counter                  */
    void        **grtexit;          /* 10 atexit() array of functions       */
    void        **grtexita;         /* 14 on_exit() array of args           */
    void        **grtfile;          /* 18 open FILE handle array            */
    void        **grtsock;          /* 1C open sockets array                */
    void        **grtenv;           /* 20 environment variables array       */
    void        *grtin;             /* 24 stdin file handle                 */
    void        *grtout;            /* 28 stdout file handle                */
    void        *grterr;            /* 2C stderr file handle                */
    void        *grtcom;            /* 30 console communication             */
    void        *grtapp1;           /* 34 for use by applications           */
    void        *grtapp2;           /* 38 for use by applications           */
    void        *grtapp3;           /* 3C for use by applications           */
    void        *grtcthrd;          /* 40 CTHDTASK array                    */
    void        **grtwsa;           /* 44 writable static array             */
    void        **grtdevtb;         /* 48 device array                      */
    void        **grtptrs;          /* 4C pointers passed in via argv       */
};                                  /* 50 (80 bytes)                        */

extern CLIBGRT  *__grtget(void);
extern int      __grtres(void);
extern int      __grtset(void);

#endif
