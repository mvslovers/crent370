/* MTXAVAIL.C */
#include "clibmutx.h"
#include "cliblock.h"

int
mtxavail(CLIBMUTX *mutex)
{
    /* return true if mutex is not locked */
    return (mutex->count == 0 && mutex->owner == 0);
}
