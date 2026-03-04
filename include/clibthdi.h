#ifndef CLIBTHDI_H
#define CLIBTHDI_H
#include <time.h>
#include <time64.h>
#include "clibthrd.h"

typedef struct cthdmgr      CTHDMGR;    /* thread manager instance          */
typedef struct cthdque      CTHDQUE;    /* thread manager queue             */
typedef struct cthdwork     CTHDWORK;   /* worker thread instance           */

struct cthdmgr {
    char        eye[8];                 /* 00 eye catcher for dumps         */
#define CTHDMGR_EYE     "CTHDMGR"       /* ...                              */
    CTHDTASK    *task;                  /* 08 thread manager task           */
    unsigned    wait;                   /* 0C wait for work (ECB)           */
#define CTHDMGR_POST_DATA       0       /* ... data was queued              */
#define CTHDMGR_POST_WAIT       1       /* ... worker waiting for data      */
#define CTHDMGR_POST_QUIESCE    2       /* ... quiesce thread manager       */
#define CTHDMGR_POST_SHUTDOWN   3       /* ... terminate thread manager     */
#define CTHDMGR_POST_TIMER      4       /* ... timer                        */

    void        *func;                  /* 10 thread function               */
    void        *udata;                 /* 14 user data for threads         */
    unsigned    stacksize;              /* 18 thread stack size             */
    CTHDWORK    **worker;               /* 1C work threads                  */

    CTHDQUE     **queue;                /* 20 work queue                    */
    volatile int state;                 /* 24 thread manager state          */
#define CTHDMGR_STATE_INIT      0       /* ... initialized                  */
#define CTHDMGR_STATE_RUNNING   1       /* ... thread manager is active     */
#define CTHDMGR_STATE_QUIESCE   2       /* ... thread manager is quiesced   */
#define CTHDMGR_STATE_STOPPED   3       /* ... thread manager is stopped    */
#define CTHDMGR_STATE_WAITING   4       /* ... thread manager is waiting    */
    unsigned    mintask;                /* 28 min task                      */
    unsigned    maxtask;                /* 2C max task                      */

    __64        dispatched;             /* 30 dispatched counter            */
    unsigned    start;                  /* 38 round robbin start index      */
    char        rname[24];              /* 3C resource name                 */
};                                      /* 54 (84 bytes)                    */

struct cthdwork {
    char        eye[8];                 /* 00 eye catcher for dumps         */
#define CTHDWORK_EYE    "CTHDWORK"      /* ...                              */
    unsigned    wait;                   /* 08 thread wait ecb               */
#define CTHDWORK_POST_REQUEST   0       /* ... process request              */
#define CTHDWORK_POST_TIMER     1       /* ... timer pop                    */
#define CTHDWORK_POST_SHUTDOWN  2       /* ... shutdown thread              */
    CTHDMGR     *mgr;                   /* 0C thread manager instance       */

    CTHDTASK    *task;                  /* 10 thread instance               */
    CTHDQUE     *queue;                 /* 14 queued work                   */
    volatile int state;                 /* 18 thread worker state           */
#define CTHDWORK_STATE_INIT     0       /* ... initialized                  */
#define CTHDWORK_STATE_RUNNING  1       /* ... worker thread is active      */
#define CTHDWORK_STATE_WAITING  2       /* ... worker thread is waiting     */
#define CTHDWORK_STATE_DISPATCH 3       /* ... worker thread is dispatched  */
#define CTHDWORK_STATE_SHUTDOWN 4       /* ... worker thread is stopping    */
#define CTHDWORK_STATE_STOPPED  5       /* ... worker thread is stopped     */
    unsigned    opt;                    /* 1C worker optionsnt              */
#define CTHDWORK_OPT_TIMER	0x00000001	/* on=post timer desired (1 sec)	*/
#define CTHDWORK_OPT_NOWORK	0x00000002  /* on=don't give queued work		*/

    time64_t    start_time;             /* 20 time worker created           */
    time64_t    wait_time;              /* 28 time worker waited for work   */
    time64_t    disp_time;              /* 30 time worker was dispatched    */
    __64		dispatched;				/* 38 dispatched count				*/
};                                      /* 40 (64 bytes)                    */

struct cthdque {
    char        eye[8];                 /* 00 eye catcher for dumps         */
#define CTHDQUE_EYE     "CTHDQUE"       /* ...                              */
    CTHDMGR     *mgr;                   /* 0C thread manager instance       */
    void        *data;                  /* 10 queue data item               */
};                                      /* 14 (20 bytes)                    */


CTHDMGR *cthread_manager_init(unsigned count, void *func, void *udata, unsigned stacksize)  asm("@@CMINIT");
int cthread_manager_term(CTHDMGR **cthdmgr)                                                 asm("@@CMTERM");
int cthread_worker_add(CTHDMGR *mgr)                                                        asm("@@CMWADD");
int cthread_worker_del(CTHDWORK **work)                                                     asm("@@CMWDEL");
int cthread_queue_del(CTHDQUE **queue)                                                      asm("@@CMQDEL");
int cthread_worker_shutdown(CTHDWORK *work)                                                 asm("@@CMWSHU");
int cthread_queue_add(CTHDMGR *mgr, void *data)                                             asm("@@CMQADD");
int cthread_worker_wait(CTHDWORK *work, char **data)                                        asm("@@CMWWAT");

#endif
