/* @@CTCRTE.C - cthread_create()
** create a thread (subtask) instance
** returns CTHDTASK handle or NULL on error.
*/
#include "clibthrd.h"

__asm__("\n&FUNC    SETC 'cthread_create'");
CTHDTASK *
cthread_create(void *func, void *arg1, void *arg2)
{
    return cthread_create_ex(func,arg1,arg2,0);
}
