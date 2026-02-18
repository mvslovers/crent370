/* @@CTSELF.C - cthread_self()
** find thread (subtask) instance for this thread
** returns CTHDTASK handle or NULL if not found.
*/
#include "clibthrd.h"

__asm__("\n&FUNC    SETC 'cthread_self'");
CTHDTASK *
cthread_self(void)
{
    unsigned    *psa    = (unsigned*)0;         /* MVS prefixed save area */
    unsigned    tcb     = psa[0x21C/4];         /* get our TCB address */
    CTHDTASK    *task   = cthread_find(tcb);

quit:
    return task;
}
