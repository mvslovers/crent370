/*********************************************************************/
/*                                                                   */
/*  This Program Written by Paul Edwards.                            */
/*  Released to the Public Domain                                    */
/*                                                                   */
/*********************************************************************/
/*********************************************************************/
/*                                                                   */
/*  setjmp.c - implementation of stuff in setjmp.h                   */
/*                                                                   */
/*********************************************************************/

#include "setjmp.h"
#include "stddef.h"

extern int __longj(void *);

__PDPCLIB_API__ void longjmp(jmp_buf env, int val)
{
	// wtof("%s: enter val=%d", __func__, val);

    if (val == 0) {
        val = 1;
    }

    env[0].retval = val;
    // wtodumpf(env, sizeof(jmp_buf), "%s: jmp_buf", __func__);

    /* load regs */
	// wtof("%s: calling __longj()", __func__);
    __longj(env);

	// wtof("%s: enter exit", __func__);
    return;
}
