/* MTXUNLK.C */
#include "clibmutx.h"
#include "cliblock.h"
#include "clibcrt.h"
#include "clibary.h"

void
mtxunlk(CLIBMUTX *mutex)
{
    if (mtxheld(mutex)) {
        mutex->count--;
        if (mutex->count==0) {
            /* do real unlock of mutex */
            CLIBCRT *crt    = __crtget();
            unsigned count  = arraycount(&crt->crtmutx);

            /* remove the mutex from the array of thread mutex locks */
            while(count) {
                CLIBMUTX *x = arrayget(&crt->crtmutx, count);
                if (x==mutex) {
                    /* found it, remove mutex from array */
                    arraydel(&crt->crtmutx, count);
                    break;
                }
                count--;
            }
            mutex->owner = 0;
            unlock_resf(CLIB_MUTEX_RNAME, 0, mutex);
        }
    }
}
