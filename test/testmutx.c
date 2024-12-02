#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "clibwto.h"
#include "clibmutx.h"

int
main(int argc, char**argv)
{
    int         rc      = 0;
    CLIBMUTX    *mutex  = mtxnew();

    wtof("mutex %08X", mutex);
    if (!mutex) return 8;

    mtxlock(mutex);
    wtof("mtxlock()");

    rc = mtxheld(mutex);
    wtof("mtxheld(), rc=%d", rc);

    rc = mtxnheld(mutex);
    wtof("mtxnheld(), rc=%d", rc);

    rc = mtxavail(mutex);
    wtof("mtxavail(), rc=%d", rc);

    wtof("sleeping 60 seconds");
    sleep(60);

    wtof("awake");

    mtxunlk(mutex);
    wtof("mtxunlk()");

    rc = mtxheld(mutex);
    wtof("mtxheld(), rc=%d", rc);

    rc = mtxnheld(mutex);
    wtof("mtxnheld(), rc=%d", rc);

    rc = mtxavail(mutex);
    wtof("mtxavail(), rc=%d", rc);

    wtof("freeing mutex %08X", mutex);

    mtxfree(mutex);

    return 0;
}
