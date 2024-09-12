/* @@CTI.C - thread manager anchor
*/
#include "clibthdi.h"

extern CTHDMGR *__cminit(unsigned, void *, void *, unsigned);
extern int __cmterm(CTHDMGR **cthdmgr);
extern int __cmwadd(CTHDMGR *cthdmgr);
extern int __cmwdel(CTHDWORK **cthdwork);
extern int __cmqdel(CTHDQUE **cthdque);
extern int __cmwshu(CTHDWORK *work);
extern int __cmqadd(CTHDMGR *mgr, void *data);
extern int __cmwwat(CTHDWORK *work, char **data);

static CTHDI anchor = {
    CTHDI_EYE,      /* 00 eye catcher               */
    0,              /* 08 unused                    */
    0,              /* 0C unused                    */
    __cminit,       /* 10 cthread_manager_init()    */
    __cmterm,       /* 14 cthread_manager_term()    */
    __cmwadd,       /* 18 cthread_worker_add()      */
    __cmwdel,       /* 1C cthread_worker_del()      */
    __cmqdel,       /* 20 cthread_queue_del()       */
    __cmwshu,       /* 24 cthread_worker_shutdown() */
    __cmqadd,       /* 28 cthread_queue_add()       */
    __cmwwat,       /* 2C cthread_worker_wait()     */
};

CTHDI *__cti = &anchor;
