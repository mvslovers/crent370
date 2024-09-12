/* ON@EXIT.C */
#include <stdlib.h>
#include <stddef.h>
#include "cliblock.h"
#include "clibcrt.h"
#include "clibary.h"

int
on_exit(void (*func)(int,void*), void *arg)
{
    CLIBGRT *grt        = __grtget();

    if (func) {
        lock(&grt->grtexit,0);
        arrayadd(&grt->grtexit, func);
        arrayadd(&grt->grtexita, arg);
        unlock(&grt->grtexit,0);
    }

    return 0;
}
