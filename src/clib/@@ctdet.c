/* @@CTDET.C - cthread_detach()
** detach a thread (subtask)
*/
#include "clibthrd.h"

static int detach(CTHDTASK *task);

__asm__("\n&FUNC    SETC 'cthread_detach'");
int
cthread_detach(CTHDTASK *task)
{
    int     rc = 0;
#if 0
    char    buf[256] = "";

    __caller(buf);
    wtof("__ctdet called by %s", buf);
#endif
    if (!task) goto quit;
    if (!task->tcb) goto quit;

    /* we use try() to catch any DETACH failures */
    rc = try(detach, task);

    if (rc==0) rc = task->rc;
    task->tcb = 0;

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'detach'");
static int
detach(CTHDTASK *task)
{
    void    *tcb = (void*)(task->tcb);
#if 0
    wtof("Issuing DETACH for task=%08X, TCB=%08X", task, task->tcb);
#endif
    __asm("DS\t0H\n\t"
        "DETACH (%1),STAE=YES   detach the subtask\n\t"
        "ST\t15,0(,%0)          save the return code"
        : : "r"(&task->rc), "r"(&tcb) : "14","15","0","1" );
#if 0
    wtof("Return from DETACH for task=%08X, TCB=%08X, RC=%d", task, task->tcb, task->rc);
#endif
    task->tcb = 0;

    return task->rc;
}
