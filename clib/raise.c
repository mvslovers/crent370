/*********************************************************************/
/*                                                                   */
/*  This Program Written by Paul Edwards.                            */
/*  Released to the Public Domain                                    */
/*                                                                   */
/*********************************************************************/
/*********************************************************************/
/*                                                                   */
/*  signal.c - implementation of stuff in signal.h                   */
/*                                                                   */
/*********************************************************************/

#include "signal.h"
#include "stdlib.h"
#include "stddef.h"

int raise(int sig)
{
    if (sig >= SIGABRT && sig <= SIGTERM) {
		__SIGHDL *sighdl = __sighdl();
		(sighdl[sig])(sig);
	}
    return (0);
}
