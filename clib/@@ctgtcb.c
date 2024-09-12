/* @@CTGTCB.C - cthread_get_tcb()
** get TCB address for thread
** returns TCB address as unsigned value
*/
#include "clibthrd.h"

__asm__("\n&FUNC    SETC 'cthread_get_tcb'");
unsigned
cthread_get_tcb(CTHDTASK *task)
{
    unsigned    tcb;

    if (task) {
        tcb = task->tcb;            /* get task TCB address */
    }
    else {
        unsigned *psa = (unsigned*)0;
        tcb = psa[0x21C/4];         /* get our TCB address */
    }

quit:
    return tcb;
}
