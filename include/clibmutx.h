#ifndef CLIBMUTX_H
#define CLIBMUTX_H

#define CLIB_MUTEX_RNAME    "MUTEX.%08X"

typedef struct clibmutx     CLIBMUTX;

/* The mutex implemented here allows for recursive operation.
**
** This basically means that you can lock the same mutex repeatedly
** so long as you issue the same number of unlock request.  The mutex
** remains locked so long as the mutex count is greater than one.
**
** Each call to mtxlock() or when mtxtry() is successful, increments
** the mutex lock count.
**
** Each call to mtxunlk() decrements the mutex lock count.
** The call to mtxunlk() that decrements the lock count to zero
** releases the lock on that mutex.
*/
struct clibmutx {
    unsigned        owner;          /* 00 owner thread id   (TCB)           */
    unsigned        count;          /* 04 number of times locked by owner   */
};                                  /* 08 (8 bytes)                         */

#define CLIBMUTX_INITIALIZER  {0,0}

/* mtxnew() - allocate and initialize a mutex handle */
extern CLIBMUTX     *mtxnew(void);          /* allocate a new mutex         */

/* mtxfree() - deallocate a mutex handle allocated by mtxnew() */
extern void         mtxfree(CLIBMUTX *);    /* free mutex storage           */

/* mtxinit() - initialize a mutex handle */
extern void         mtxinit(CLIBMUTX *);    /* initialize mutex structure   */

/* mtxlock() - obtain lock on mutex handle */
extern void         mtxlock(CLIBMUTX *);    /* obtain exclusive lock        */

/* mtxtry() - obtain lock on mutex handle if avaiable (rc=0), otherwise no */
extern int          mtxtry(CLIBMUTX *);     /* obtain exclusive lock if free*/

/* mtxunlk() - release lock on mutex handle */
extern void         mtxunlk(CLIBMUTX *);    /* release exclusive lock       */

/* mtxheld() - returns true if the mutex is locked by this thread */
extern int          mtxheld(CLIBMUTX *);    /* is mutex held by this thread */

/* mtxnheld() - return true if the mutex is unlocked or held by another thread*/
extern int          mtxnheld(CLIBMUTX *);   /* not held by this thread      */

/* mtxavail() - return true if the mutex is not held by any thread */
extern int          mtxavail(CLIBMUTX *);   /* not held by any thread       */

/* mtxclup() - internal use only, cleanup mutex lock */
extern void         mtxclup(CLIBMUTX *);    /* cleaup mutex lock (internal) */

#endif
