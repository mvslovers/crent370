#ifndef CLIBTHRD_H
#define CLIBTHRD_H

/*  CLIBTHRD - A thread implementation for the CLIB environment.

    cthread_create          Create a thread instance for func(arg1,arg2)
                            with default stack size (64K).
                            Returns a CTHDTASK handle or NULL.

    cthread_create_ex       Create a thread instance for func(arg1,arg2)
                            with specified stack size.
                            Returns a CTHDTASK handle or NULL.

    cthread_delete          Destroy CTHDTASK created by cthread_create or
                            cthread_create_ex functions.
                            Returns nothing (void).

    cthread_detach          Detaches the subtask (TCB) for this thread.
                            The CTHDTASK handle remains allocated.
                            Returns the subtask return code.

    cthread_find            Returns the CTHDTASK handle for a given TCB
                            address or NULL if TCB is not a thread.

    cthread_self            Returns the CTHDTASK handle for the current thread
                            or NULL if this TCB is not a thread.

    cthread_get_tcb         Returns the TCB for the CTHDTASK handle or TCB
                            for the current task if CTHDTASK is NULL.

    cthread_post            Performs MVS POST of Event Control Block (ECB).
                            Returns 0, may ABEND if POST fails.

    cthread_wait            Waits for ECB to be posted.
                            Returns ECB value as a positive integer value.

    cthread_timed_wait      Waits for ECB to be posted or timer to expire.
                            The 'bintvl' value indicates the number of .01
                            seconds to wait for the ECB to be posted.
                            Returns ECB value as a positive integer value.

    cthread_push            Push a function pointer and argument to the
                            current thread/task.
                            Returns 0 if successful.

    cthread_pop             Pop a function pointer and argument from the
                            current thread/task. The function is then:
                            CTHDPOP_NOEXEC      0=do not execute
                            CTHDPOP_EXEC        1=execute
                            CTHDPOP_TRY         2=execute with try()
                            CTHDPOP_ESTAE       3=execute with ESTAE
                            Returns function return code.

    cthread_exit            Terminates the current thread and saves the
                            return code value in the CTHDTASK for this
                            thread.
                            The thread cleanup routine will pop any
                            pushed functions (cthread_push) and execute them
                            inside a try() wrapper.

*/
#include "cliblock.h"
#include "clibstae.h"
#include "clibcrt.h"
#include "clibary.h"
#include "clibecb.h"

typedef struct cthdtask     CTHDTASK;   /* a subtask instance               */
typedef enum   cthdpop      CTHDPOP;    /* cthread_pop() pop type           */

enum cthdpop {
    CTHDPOP_NOEXEC=0,                   /* pop func, do not execute         */
    CTHDPOP_EXEC,                       /* pop func, execute                */
    CTHDPOP_TRY,                        /* pop func, execute with try()     */
    CTHDPOP_ESTAE                       /* pop func, execute with ESTAE     */
};

/* Each subtask (thread) will have a CTHDTASK */
struct cthdtask {
    char        eye[8];                 /* 00 eye catcher for dumps         */
#define CTHDTASK_EYE    "CTHDTASK"      /* ...                              */
    unsigned    tcb;                    /* 08 subtask TCB address           */
    unsigned    owntcb;                 /* 0C owner TCB address (parent)    */
    ECB         termecb;                /* 10 posted by MVS when task ends  */
    int         rc;                     /* 14 return code from function     */
    unsigned    stacksize;              /* 18 stack size in bytes           */
    void        *func;                  /* 1C subtask function address      */
    void        *arg1;                  /* 20 arg1 for subtask function     */
    void        *arg2;                  /* 24 arg2 for subtask function     */
    unsigned    stack[1];               /* 28 stack for subtask             */
};                                      /* 2C (44 bytes)                    */

CTHDTASK *cthread_create(void *func, void *arg1, void *arg2)                        asm("@@CTCRTE");

CTHDTASK *cthread_create_ex(void *func, void *arg1, void *arg2, unsigned stacksize) asm("@@CTCRTX");

void cthread_delete(CTHDTASK **task)                                                asm("@@CTDEL");

int cthread_detach(CTHDTASK *task)                                                  asm("@@CTDET");

CTHDTASK *cthread_find(unsigned tcb)                                                asm("@@CTFIND");

CTHDTASK *cthread_self(void)                                                        asm("@@CTSELF");

unsigned cthread_get_tcb(CTHDTASK *task)                                            asm("@@CTGTCB");

int cthread_post(ECB *ecb, unsigned code)                                           asm("@@CTPOST");

int cthread_wait(ECB *ecb)                                                          asm("@@CTWAIT");

int cthread_timed_wait(ECB *ecb, unsigned bintvl, unsigned postcode)                asm("@@CTTWAT");

int cthread_push(int (*func)(void*), void *arg)                                     asm("@@CTPUSH");

int cthread_pop(CTHDPOP type)                                                       asm("@@CTPOP");

int cthread_exit(int rc)                                                            asm("@@CTEXIT");

int cthread_lock(int shared, const char *rname)                                     asm("@@CTLOCK");

int cthread_unlock(const char *rname)                                               asm("@@CTUNLK");

int cthread_yield(void)                                                             asm("@@CTYIEL");

#endif
