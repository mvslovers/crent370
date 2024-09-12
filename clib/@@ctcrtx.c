/* @@CTCRTX.C - cthread_create_ex()
** create a thread (subtask) instance with stack size
** returns CTHDTASK handle or NULL on error.
*/
#include <stdlib.h>
#include <stddef.h>
#include "clibthrd.h"
#include "cliblock.h"
#include "clibcrt.h"
#include "clibary.h"
#include "clibmutx.h"

static CTHDTASK *newthread(unsigned tcb, unsigned owntcb, unsigned stacksize);
static int attach(CTHDTASK *task);
static int dummy(void *arg1, void *arg2);

__asm__("\n&FUNC    SETC 'cthread_create_ex'");
CTHDTASK *
cthread_create_ex(void *func, void *arg1, void *arg2, unsigned stacksize)
{
    unsigned    *psa    = (unsigned*)0;         /* MVS prefixed save area */
    unsigned    tcb     = psa[0x21C/4];         /* get our TCB address */
    CTHDTASK    *owner  = cthread_find(tcb);    /* get owner thread */
    CTHDTASK    *task   = NULL;
    int         rc;

    /* wtof("%s(%08X, %08X, %08X, %u)", __func__, func, arg1, arg2, stacksize); */

    if (!stacksize) stacksize = (64 * 1024);    /* default 64K stack */
    if (!func) func = dummy;

    /* wtodumpf(func, 32, "FUNC"); */

    if (!owner) {
        /* we do this so that the main() thread will have
        ** CTHDTASK handle as a parent/owner for the new thread.
        */

        /* create the owner thread handle */
        owner = newthread(tcb, 0, 0);
        if (!owner) goto quit;      /* should never happen */
    }

    /* we create a new task handle */
    task = newthread(0, owner->tcb, stacksize);
    if (!task) goto quit;           /* must be out of memory! */

    task->func      = func;         /* thread function */
    task->arg1      = arg1;         /* thread arg1 */
    task->arg2      = arg2;         /* thread arg2 */

    /* attach our subtask driver module.
    ** we use try() to catch any abend caused by an ATTACH failure.
    */
#if 1
    rc = try(attach, task);
#else
    rc = attach(task);
#endif
    if (rc==0) rc = task->rc;
#if 0   /* debug code */
    if (rc==0) {
        wtof("%s NEWTCB(%06X)", __func__, task->tcb);
    }
#endif
    if (rc) {
        /* well that's unexpected */
        task->tcb = 0;  /* make sure we clear the TCB address */
        cthread_delete(&task);
    }

quit:
    return task;
}

__asm__("\n&FUNC    SETC 'attach'");
static int
attach(CTHDTASK *task)
{
    unsigned    work[16]    = {0};

    /* attach our subtask driver module.
    ** the task->tcb is created here if the attach was a success.
    */
    __asm__(
        "LA\t1,0(,%2)\n\t"
        "ATTACH EP=CTHREAD,ECB=(%3),DPMOD=-1,SF=(E,(%4))\n\t"
        "ST\t1,%0\n\t"
        "ST\t15,%1"
        : "=m"(task->tcb), "=m"(task->rc)
        : "r"(task), "r"(&task->termecb), "r"(work) );

    return task->rc;
}

__asm__("\n&FUNC    SETC 'newthread'");
static CTHDTASK *
newthread(unsigned tcb, unsigned owntcb, unsigned stacksize)
{
    CLIBGRT     *grt    = __grtget();
    unsigned    newstack= (stacksize > 0 && stacksize < 80) ? 80 :
                            ((stacksize+7) & 0x000FFFF8);
    CTHDTASK    *task   = calloc(1, sizeof(CTHDTASK) + newstack);

    if (task) {
        strcpy(task->eye, CTHDTASK_EYE);
        task->tcb       = tcb;
        task->owntcb    = owntcb;
        task->stacksize = newstack;
        lock(&grt->grtcthrd,0);
        arrayadd(&grt->grtcthrd, task);
        unlock(&grt->grtcthrd,0);
    }

    return task;
}

__asm__("\n&FUNC    SETC 'dummy'");
static int
dummy(void *arg1, void *arg2)
{
    CTHDTASK    *task   = cthread_self();

    wtof("dummy(arg1=%08X, arg2=%08X)\n", arg1, arg2);
    wtof("CTHDTASK handle=%08X\n", task);
    if (task) {
        wtof("task->eye         %-8.8s\n", task->eye);
        wtof("task->tcb         %08X\n", task->tcb);
        wtof("task->owntcb      %08X\n", task->owntcb);
        wtof("task->termecb     %08X\n", task->termecb);
        wtof("task->rc          %08X (%d)\n", task->rc, task->rc);
        wtof("task->stacksize   %08X (%d)\n", task->stacksize, task->stacksize);
        wtof("task->func        %08X\n", task->func);
        wtof("task->arg1        %08X\n", task->arg1);
        wtof("task->arg2        %08X\n", task->arg2);
    }

    return -1;
}

__asm__("\n&FUNC    SETC 'cleanup_thread'");
static void
cleanup_thread(void)
{
    int         rc              = 0;
    CLIBCRT     *crt            = __crtget();
    unsigned    count;

    if (!crt) goto quit;    /* no thread level data, we're done */

    if (crt->crtpush) {
        /* cleanup the cthread_push() array's */
        count = arraycount(&crt->crtpush);
        while(count) {
            /* pop and execute in a try() wrapper */
            cthread_pop(CTHDPOP_TRY);
            count--;
        }
        /* cthread_push() array's should be empty now */
        arrayfree(&crt->crtpush);
        arrayfree(&crt->crtargs);
    }

    if (crt->crtmutx) {
        /* cleanup the mutex lock array */
        count = arraycount(&crt->crtmutx);
        while(count) {
            CLIBMUTX *x = arraydel(&crt->crtmutx, count);
            if (x) mtxclup(x);
            count--;
        }
        arrayfree(&crt->crtmutx);
    }

quit:
    return;
}

/* When a thread terminates and returns to the runtime code in @CRT0
** a call is made to @@CTCLUP so that thread level cleanup can be done
**/
void
__ctclup(void)
{
    try(cleanup_thread,0);
}
