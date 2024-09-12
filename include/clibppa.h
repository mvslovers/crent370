#ifndef CLIBPPA_H
#define CLIBPPA_H

#include "clibcrt.h"
#include "clibgrt.h"

typedef struct clibppa  CLIBPPA;

struct clibppa {
    char    ppaeye[4];          /* 00 Eye Catcher                       */
#define PPAEYE  "@PPA"          /* ...                                  */
    void    *ppaprev;           /* 04 Previous Save Area                */
    void    *ppanext;           /* 08 Next Save Area                    */
    CLIBCRT **ppacrt;           /* 0C C Runtime Library Anchor (Task)   */
    CLIBGRT *ppagrt;            /* 10 C Runtime Global Anchor (AS)      */
    void    *ppasave;           /* 14 saved "next" from TCBFSA          */
    void    *ppatiot;           /* 18 TIOT address                      */
    void    *ppapscb;           /* 1C PSCB address                      */
    char 	ppaflag;			/* 20 Processing flag(s)				*/
#define PPAFLAG_TSOFG	0x80	/* ... TSO environment					*/
#define PPAFLAG_TSOBG	0x40	/* ... TSO background environment		*/
#define PPAFLAG_TIN		0x08	/* ... STDIN is terminal				*/
#define PPAFLAG_TOUT	0x04	/* ... STDOUT is terminal				*/
#define PPAFLAG_TERR	0x02	/* ... STDERR is terminal				*/
    char    ppasubpl;			/* 21 save area subpool number          */
	char 	unused[2];			/* 22 unused/available					*/
	unsigned ppastkln;			/* 24 stack area length 				*/
	void	*ppaexita;			/* 28 EXITA entry point address			*/
	void    *ppacppl;			/* 2C TSO CPPL							*/
};								/* 30 (48 bbytes)						*/

CLIBPPA * __PPAGET(void);
CLIBPPA * __ppaget(void);

#endif
