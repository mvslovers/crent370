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

static __SIGHDL static_sighdl[] = {
    __sigdfl,	// unused
    __sigdfl,	// SIGABRT
    __sigdfl,	// SIGFPE
    __sigdfl,	// SIGILL
    __sigdfl,	// SIGINT
    __sigdfl,	// SIGSEGV
    __sigdfl	// SIGTERM
};

__SIGHDL *__sighdl(void)
{
	__SIGHDL *sighdl = (__SIGHDL*) __wsaget(static_sighdl, sizeof(static_sighdl));
	
	return sighdl;
}
