/* @@CTX.C - external anchor
*/
#include "clibthrd.h"

extern void     __ctexit(int);  /* entry point in @@CRT0 */
extern CTHDTASK *__ctcrte(void *func, void *arg1, void *arg2);
extern CTHDTASK *__ctcrtx(void *func, void *arg1, void *arg2, unsigned stack);
extern void     __ctdel(CTHDTASK **task);
extern CTHDTASK *__ctfind(unsigned tcb);
extern CTHDTASK *__ctself(void);
extern int      __ctdet(CTHDTASK *task);
extern unsigned __ctgtcb(CTHDTASK *task);
extern int      __ctpost(unsigned *ecb, unsigned code);
extern int      __ctwait(unsigned *ecb);
extern int      __cttwat(unsigned *ecb, unsigned bintvl, unsigned postcode);
extern int      __ctpush(int (*func)(void*), void *arg);
extern int      __ctpop(CTHDPOP type);

static CTHDX anchor = {
    CTHDX_EYE,      /* 00 eye catcher                           */
    0,              /* 08 CTHDTASK array        (deprecated)    */
    __ctexit,       /* 0C cthread_exit()                        */
    __ctcrte,       /* 10 cthread_create()                      */
    __ctcrtx,       /* 14 cthread_create_ex()                   */
    __ctdel,        /* 18 cthread_delete()                      */
    __ctfind,       /* 1C cthread_find()                        */
    __ctself,       /* 20 cthread_self()                        */
    __ctdet,        /* 24 cthread_detach()                      */
    __ctgtcb,       /* 28 cthread_get_tcb()                     */
    __ctpost,       /* 2C cthread_post()                        */
    __ctwait,       /* 30 cthread_wait()                        */
    0,              /* 34 cthread_lock()        (deprecated)    */
    0,              /* 38 cthread_unlock()      (deprecated)    */
    __cttwat,       /* 3C cthread_timed_wait()                  */
    __ctpush,       /* 40 cthread_push()                        */
    __ctpop,        /* 44 cthread_pop()                         */
};

CTHDX *__ctx = &anchor;
