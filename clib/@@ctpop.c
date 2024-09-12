/* @@CTPOP.C */
#include <stdlib.h>
#include <stddef.h>
#include "clibthrd.h"
#include "cliblock.h"
#include "clibcrt.h"
#include "clibary.h"
#include "clibstae.h"

__asm__("\n&FUNC    SETC 'cthread_pop'");
int
cthread_pop(CTHDPOP type)
{
    int         rc              = 0;
    CLIBCRT     *crt            = __crtget();
    int         (*func)(void *) = 0;
    void        *arg            = 0;
    unsigned    count;

    lock(&crt->crtpush,0);
    count = arraycount(&crt->crtpush);
    if (count) {
        func = arraydel(&crt->crtpush,count);
        arg  = arraydel(&crt->crtargs,count);
    }
    unlock(&crt->crtpush,0);

    if (!func) goto quit;

    switch(type) {
    default:
    /* case CTHDPOP_NOEXEC: /* pop func, do not execute         */
        break;
    case CTHDPOP_EXEC:      /* pop func, execute                */
        rc = func(arg);
        break;
    case CTHDPOP_TRY:       /* pop func, execute with try()     */
        rc = try(func,arg);
        break;
    case CTHDPOP_ESTAE:     /* pop func, execute with ESTAE     */
        /* if something goes all wrong, capture it! */
        abendrpt(ESTAE_CREATE, DUMP_DEFAULT);
        rc = func(arg);
        /* remove ESTAE */
        abendrpt(ESTAE_DELETE, DUMP_DEFAULT);
        break;
    }

quit:
    return rc;
}
