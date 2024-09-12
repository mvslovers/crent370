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

/* This is the default signal handler function */
void __sigdfl(int sig)
{
    /* reset the signal (sig) to default signal handler */
    if (sig >= SIGABRT && sig <= SIGTERM) {
        __SIGHDL *sighdl = __sighdl();
        sighdl[sig] = SIG_DFL;
    }

    /* default processing for signal sig */
    switch(sig) {
    case SIGABRT:
        exit(EXIT_FAILURE);
        break;
#if 0
    case SIGFPE:
    case SIGILL:
    case SIGINT:
    case SIGSEGV:
    case SIGTERM:
        break;
#endif
    default:
        /* do nothing */
        break;
    }

    return;
}
