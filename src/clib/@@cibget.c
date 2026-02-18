/* @@CIBGET.C */
#include "clibcib.h"

CIB *
__cibget(void)
{
    COM     *com    = __gtcom();
    CIB     *cib    = com ? com->comcibpt : 0;

    return cib;
}
