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

void (*signal(int sig, void (*func)(int)))(int)
{
    if (sig >= SIGABRT && sig <= SIGTERM) {
		__SIGHDL *sighdl = __sighdl();
		sighdl[sig] = func;
	}

    return (func);
}
