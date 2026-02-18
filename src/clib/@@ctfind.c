/* @@CTFIND.C - cthread_find()
** find thread (subtask) instance by tcb address
** returns CTHDTASK handle or NULL if not found.
*/
#include "clibthrd.h"

__asm__("\n&FUNC    SETC 'cthread_find'");
CTHDTASK *
cthread_find(unsigned tcb)
{
    CLIBGRT     *grt    = __grtget();
    CTHDTASK    *task   = NULL;
    CTHDTASK    **array;
    int         locked;
    unsigned    count;
    unsigned    n;

    locked  = lock(&grt->grtcthrd,0);
    array   = grt->grtcthrd;
    count   = arraycount(&array);
    for(n=0; n < count; n++) {
        if (!array[n]) continue;
        if (array[n]->tcb == tcb) {
            task = array[n];
            break;
        }
    }
    if (locked==0) {
        unlock(&grt->grtcthrd,0);
    }

quit:
    return task;
}
