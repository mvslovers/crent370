/* @@CTDEL.C - cthread_delete()
** delete a CTHDTASK handle
*/
#include "clibthrd.h"

__asm__("\n&FUNC    SETC 'cthread_delete'");
void
cthread_delete(CTHDTASK **task)
{
    CLIBGRT     *grt    = __grtget();
    CTHDTASK    **array;
    unsigned    count;
    unsigned    n;

    if (!task) goto quit;
    if (!*task) goto quit;
    if (strcmp((*task)->eye, CTHDTASK_EYE)!=0) goto quit;

    lock(&grt->grtcthrd,0);
    array = grt->grtcthrd;
    count = arraycount(&array);
    for(n=0; n < count; n++) {
        if (!array[n]) continue;
        if (array[n] == *task) {
            arraydel(&grt->grtcthrd, n+1);
            break;
        }
    }
    unlock(&grt->grtcthrd,0);

    /* detach the thread */
    cthread_detach(*task);

    free(*task);
    *task = 0;

quit:
    return;
}
