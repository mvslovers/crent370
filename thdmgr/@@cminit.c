/* @@CMINIT.C - cthread_init()
*/
#include "clibthdi.h"

#if 0
#define WTODEBUG    /* define for wtof() debug messages */
#endif

static int dispatch_thread(CTHDMGR *mgr);
static int dispatch_thread_init(CTHDMGR *mgr);
static int dispatch_thread_check(CTHDMGR *mgr);
static int dispatch_thread_quiesce(CTHDMGR *mgr);
static int dispatch_thread_work(CTHDMGR *mgr, int timer);
static int dispatch_thread_create(CTHDMGR *mgr);
static int dispatch_thread_term(CTHDMGR *mgr);
static int dispatch_thread_timed_wait(CTHDMGR *mgr, int quiesce, int pending, int timer);
static void dispatch_work(CTHDMGR *mgr, CTHDWORK *work);

__asm__("\n&FUNC    SETC 'cthread_manager_init'");
CTHDMGR *
cthread_manager_init(unsigned count, void *func, void *udata, unsigned stacksize)
{
    CTHDMGR         *mgr    = calloc(1, sizeof(CTHDMGR));
    unsigned        *psa    = (unsigned *)0;
    unsigned        *ascb   = (unsigned *)psa[0x224/4];
    unsigned        asid    = ((ascb[0x24/4]) >> 16);
    unsigned        n;

    if (!mgr) goto quit;

    strcpy(mgr->eye, CTHDMGR_EYE);
    mgr->func       = func;
    mgr->udata      = udata;
    mgr->state      = CTHDMGR_STATE_INIT;
    mgr->stacksize  = stacksize;
    mgr->mintask    = count > 5 ? 3 : count > 3 ? 1 : 0;
    mgr->maxtask    = count;
    sprintf(mgr->rname, "CTHDMGR.%04X.%08X", asid, mgr);

    /* create thread manager dispatch thread */
    mgr->task       = cthread_create_ex(dispatch_thread, mgr, 0, 32*1024);
    if (!mgr->task) {
        cthread_manager_term(&mgr);
        goto quit;
    }

quit:
    return mgr;
}

__asm__("\n&FUNC    SETC 'dispatch_thread'");
static int
dispatch_thread(CTHDMGR *mgr)
{
    int                 rc          = 0;
    int                 running     = 1;
    int                 pending     = 0;
    int					timer		= 1;	/* assume we need timer */
    int                 quiesce     = 0;
    unsigned   			count       = 0;
    unsigned            n;
    CTHDWORK            *work;
    CTHDTASK            *task;

	/* initialize worker threads for dispatcher */
	dispatch_thread_init(mgr);

    /* do {} while(running) */
    do {
        /* wait for something to do or timeout */
		rc = dispatch_thread_timed_wait(mgr, quiesce, pending, timer);

		/* check post code value */
        if (rc == CTHDMGR_POST_SHUTDOWN) {
			/* server is shutting down NOW */
            running = 0;	
            break;
        }
		else if (rc == CTHDMGR_POST_QUIESCE) {
			/* server is shutting down, start termination of threads */
            quiesce = 1;    
        }

		/* check for worker thread termination or workers that need timer post */
		timer = dispatch_thread_check(mgr);

        if (quiesce) {
            /* quiesced, we need to shutdown any waiting workers */
            running = dispatch_thread_quiesce(mgr);
            if (!running) break;
        }
        else {
			pending = dispatch_thread_work(mgr, timer);
		}

#if 0
        if (pending) {
            /* We have queued work we could't dispatch. */
            /* Create a worker thread if we're less than the max */
			dispatch_thread_create(mgr);

            /* Wait .1 seconds so any new worker threads can initialize. */
			lock(mgr,0);
			mgr->state = CTHDMGR_STATE_WAITING;
			unlock(mgr,0);
            __asm__("STIMER WAIT,BINTVL==F'10'   0.10 seconds");

            /* Post our thread manager (mgr->wait) ECB. */
            cthread_post(&mgr->wait, CTHDMGR_POST_DATA);
        }
#endif

    } while(running);

	/* if we have any workers still running we have to kill them */
	dispatch_thread_term(mgr);

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'dispatch_thread_init'");
static int
dispatch_thread_init(CTHDMGR *mgr)
{
    int                 rc          = 0;
    volatile unsigned   count       = 0;
    unsigned            n;

    lock(mgr,0);

    mgr->state = CTHDMGR_STATE_RUNNING;

    /* do we need to start some workers? */
    count = arraycount(&mgr->worker);
    for(n=count; n < mgr->mintask; n++) {
		/* start another worker thread */
		cthread_worker_add(mgr);
	}

    unlock(mgr,0);

	return rc;
}

__asm__("\n&FUNC    SETC 'dispatch_thread_timed_wait'");
static int
dispatch_thread_timed_wait(CTHDMGR *mgr, int quiesce, int pending, int timer)
{
    int                 rc          = 0;
    unsigned            timeout;  			/* 100 = 1 second */

	if (quiesce) {
		/* server is shutting down */
		timeout = 10;	/* 0.10 seconds */
		goto wait;
	}

    if (pending) {
        /* We have queued work and not enough worker threads. */
		pending = 0;	/* reset the pending flag */
		timeout = 10;	/* 0.10 seconds */

        /* Create a worker thread if we're less than the max */
		dispatch_thread_create(mgr);
		goto wait;
	}

	if (timer) {
		/* We have least 1 worker that wants timer post 
		 * OR we had a worker thread terminate.
		 */
		timeout = 100;	/* 1 second */
		goto wait;
	}

	/* We don't have any workers that need a timer pop */
	timeout = 1000;	/* 10 seconds */
		
wait:	
	/* prepare to wait for timer or work */
	lock(mgr,0);
    mgr->state = CTHDMGR_STATE_WAITING;
    unlock(mgr,0);

    /* wait for work *or* timeout, rc==CTHDMGR_POST_TIMER */
    rc = cthread_timed_wait(&mgr->wait, timeout, CTHDMGR_POST_TIMER);

	lock(mgr,0);
    mgr->state = CTHDMGR_STATE_RUNNING;
    unlock(mgr,0);
    
    return rc;
}

__asm__("\n&FUNC    SETC 'dispatch_thread_check'");
static int
dispatch_thread_check(CTHDMGR *mgr)
{
    int         rc          = 0;
    unsigned   	count       = 0;
    unsigned	deleted		= 0;
    unsigned    n;
    CTHDWORK    *work;
    CTHDTASK    *task;

    lock(mgr,0);

    /* do we need to do some cleanup for our workers threads? */
    count = arraycount(&mgr->worker);
    for(n=0; n < count; n++) {
        work = mgr->worker[n];
        if (!work) continue;

        task = work->task;
        if (!task) continue;

        if (work->opt & CTHDWORK_OPT_TIMER) {
			rc = 1;	/* indicate timer interval needed */
		}

        /* has this worker subtask ended? */
        if (task->termecb & 0x40000000) {
            /* this worker thread has terminated */
            unsigned    sys     = (task->termecb >> 12) & 0XFFF;

            if (sys) {
                wtof("worker %08X, task %08X ended ABEND S%03X",
                    work, task, sys);
            }

            work->state = CTHDWORK_STATE_STOPPED;
            cthread_delete(&task);
            work->task = 0;
            cthread_worker_del(&work);
            rc = 1;	/* indicate timer interval needed or deleted worker */
            /* we can only process one termination at a time */
            break;	/* so we leave the loop now */
        }
	}
	
    unlock(mgr,0);

	return rc;
}

__asm__("\n&FUNC    SETC 'dispatch_thread_quiesce'");
static int
dispatch_thread_quiesce(CTHDMGR *mgr)
{
    int                 running     = 1;
    unsigned   			count       = 0;
    unsigned            n;
    CTHDWORK            *work;
    CTHDTASK            *task;

    lock(mgr,0);

	/* we shut down workers in reverse order we created them */
    count = arraycount(&mgr->worker);
    for(n=count; n > 0; n--) {
        work = arrayget(&mgr->worker, n);
        if (!work) continue;

        task = work->task;
        if (!task) continue;

        if (task->termecb & 0x40000000) continue;
        if (work->state != CTHDWORK_STATE_WAITING) continue;

        cthread_worker_shutdown(work);
    }

    unlock(mgr,0);

    if (!count) running = 0; /* no worker threads */

	return running;
}

__asm__("\n&FUNC    SETC 'dispatch_work'");
static void
dispatch_work(CTHDMGR *mgr, CTHDWORK *work)
{
    time64_t	now;
    unsigned   	count;
    CTHDTASK    *task;
    int			post_request;
    int			post_timer;
    time64_t	tmp;

	/* Note: caller holds lock on mgr */
	
    if (!work) goto quit;	/* no worker thread */

    task = work->task;
    if (!task) goto quit;	/* no worker task */

    if (task->termecb & 0x40000000) goto quit;	/* terminated */
    if (work->state != CTHDWORK_STATE_WAITING) goto quit;	/* busy */

	/* get number of waiting queued request */
	post_request = count = arraycount(&mgr->queue);
	
	/* check worker processing options */
	if (work->opt & CTHDWORK_OPT_NOWORK) {
		/* Worker doesn't want any pending work */
		post_request = 0;	/* force no work available */
		if (!(work->opt & CTHDWORK_OPT_TIMER)) {
			/* Worker does not want timer */
			goto quit;	/* no post for this worker */
		}
	}
	else {
		/* Worker wants to get pending work */
		if (!post_request) {
			/* But we don't have any work, so timer only */
			if (!(work->opt & CTHDWORK_OPT_TIMER)) {
				/* Worker does not want timer post */
				goto quit;	/* no post for this worker */
			}
		}
	}

	/* get the current time and calculate if we need to post timer */
	now = time64(NULL);	/* get the current time_t value */
#if 0
	post_timer = ((now - work->wait_time) > 1);
#else
	__64_sub(&now, &work->wait_time, &tmp);
	post_timer = __64_to_i32(&tmp);
#endif

	if (post_request || post_timer) {
		/* common code for both request and timer processing */
		__64_add_u32(&mgr->dispatched, 1, &mgr->dispatched);
		__64_add_u32(&work->dispatched, 1, &work->dispatched);
		work->disp_time = now;
		work->state     = CTHDWORK_STATE_DISPATCH;
	}

    if (post_request) {
		/* dispatch this worker with queued work request */
		work->queue     = arraydel(&mgr->queue, 1);
		cthread_post(&work->wait, CTHDWORK_POST_REQUEST);
	}
	else if (post_timer) {
		/* dispatch this worker with timer post */
		work->queue		= NULL;
		cthread_post(&work->wait, CTHDWORK_POST_TIMER);
	}

quit:
    return;
}

__asm__("\n&FUNC    SETC 'dispatch_thread_work'");
static int
dispatch_thread_work(CTHDMGR *mgr, int timer)
{
    int                 rc          = 0;
    unsigned            pending     = 0;
    unsigned   			count       = 0;
    unsigned            n;

    lock(mgr,0);

    /* do we need to start some workers? */
    count = arraycount(&mgr->worker);
    if (count < mgr->mintask) {
        /* add a worker task to this thread manager */
        cthread_worker_add(mgr);
		count = arraycount(&mgr->worker);
    }

	if (count > mgr->maxtask) {
        /* deleted the last worker task from this thread manager */
        for(n=count; n > 0; n--) {
			CTHDWORK *work = arrayget(&mgr->worker, n);
			if (!work) continue;
			if (work->state == CTHDWORK_STATE_WAITING) {
				/* worker is waiting so it's safe to delete */
				cthread_worker_shutdown(work);
				cthread_worker_del(&work);
				count--;
				if (count > mgr->maxtask) continue;
				break;
			}
		}
	}

	if (!timer) {
		/* no timer post needed, do we have any queued work? */
		if (!arraycount(&mgr->queue)) {
			/* no queued work available, do nothing */
			goto quit; 	
		}
	}

    /* do we have any worker subtask? */
    count = arraycount(&mgr->worker);
    if (count) {
        /* give queued request to waiting workers */
        /* all other workers will receive a timer post */
        mgr->start++;
        if (mgr->start >= count) mgr->start = 0;

		/* give queued work or timer post to worker threads */
        for(n=mgr->start; n < count; n++) {
            dispatch_work(mgr, mgr->worker[n]);
        }

        /* now do the worker threads we skipped before */
        for(n=0; n < mgr->start; n++) {
            dispatch_work(mgr, mgr->worker[n]);
        }

		/* see if we have anything pending in the queue */
        if (arraycount(&mgr->queue)) rc = 1;
	}

quit:	
    unlock(mgr,0);
    
	return rc;
}

__asm__("\n&FUNC    SETC 'dispatch_thread_create'");
static int
dispatch_thread_create(CTHDMGR *mgr)
{
    int                 rc          = 0;
    unsigned   			count       = 0;

    lock(mgr,0);

    /* do we need to start additional workers? */
    count = arraycount(&mgr->worker);
    if (count < mgr->maxtask) {
        /* add a worker task to this thread manager */
        cthread_worker_add(mgr);
    }

    unlock(mgr,0);
	return rc;
}

__asm__("\n&FUNC    SETC 'dispatch_thread_term'");
static int
dispatch_thread_term(CTHDMGR *mgr)
{
    int         rc          = 0;
    unsigned   	count       = 0;
    unsigned    n;
    CTHDWORK    *work;

    /* terminate worker threads (reverse walk) */
    lock(mgr,0);
    mgr->state = CTHDMGR_STATE_QUIESCE;

	/* if we have any workers still running we have to kill them */
    count = arraycount(&mgr->worker);
    for(n=count; n > 0; n--) {
        work = arrayget(&mgr->worker, n);
        if (!work) continue;
        cthread_worker_shutdown(work);
        cthread_worker_del(&work);
    }

    mgr->state = CTHDMGR_STATE_STOPPED;
    unlock(mgr,0);

	return rc;
}
