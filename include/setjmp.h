/*********************************************************************/
/*                                                                   */
/*  This Program Written by Paul Edwards.                            */
/*  Released to the Public Domain                                    */
/*                                                                   */
/*********************************************************************/
/*********************************************************************/
/*                                                                   */
/*  setjmp.h - setjmp header file.                                   */
/*                                                                   */
/*********************************************************************/

#ifndef __SETJMP_INCLUDED
#define __SETJMP_INCLUDED

typedef struct {
    int regs[15];	/* R0-R14 */
    int retval;		/* R15 */
} jmp_buf[1];

int __setj(jmp_buf env);
#define setjmp(x) (__setj(x))
void longjmp(jmp_buf env, int val);

#endif
