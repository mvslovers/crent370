/* MTXCLUP.C - mutex clean up */
#include "clibmutx.h"
#include "cliblock.h"
#include "clibstae.h"

__asm__("\n&FUNC    SETC 'cleanup_mutex'");
static void
cleanup_mutex(CLIBMUTX *mutex)
{
    if (mtxheld(mutex)) {
        mutex->owner = 0;
        mutex->count = 0;
        unlock_resf(CLIB_MUTEX_RNAME, 0, mutex);
    }
}

void
mtxclup(CLIBMUTX *mutex)
{
    if (mutex) try(cleanup_mutex,mutex);
}
