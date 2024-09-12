#ifndef CLIBLOCK_H
#define CLIBLOCK_H

#define LOCKQNAME       "CLIBLOCK"
#define LOCKRNAME       "LOCK.%08X"
#define LOCKRNAMESZ     20

#define SYSLOCKQNAME    "CSYSLOCK"
#define SYSLOCKRNAME    "G.LOCK.%08X"
#define SYSLOCKRNAMESZ  20

#define LOCK_EXC		0			/* exclusive lock (read/write) */
#define LOCK_RW			LOCK_EXC	/* exclusive lock (read/write) */
#define LOCK_SHR		1			/* shared lock (read only) */
#define LOCK_READ		LOCK_SHR	/* shared lock (read only) */

/* ---- resource address lock functions ---- */

/* __lk() - lock "thing" address, read: 0=exclusive, 1=shared */
/* return 0 if lock acquired, 8 if you already have the lock. */
int  __lk(void *thing, int read);
int  lock(void *thing, int read) asm("@@LK");

/* __lktry() - lock "thing" address if available, immediate return. */
/* return 0 if lock acquired, 4 if the lock is not immediately available, 8 if you already have the lock. */
int  __lktry(void *thing, int read);
int  trylock(void *thing, int read) asm("@@LKTRY");

/* __lktest() - test if "thing" address is locked */
/* return 0 if not locked, 4 if the lock is not immediately available, 8 if you already have the lock. */
int  __lktest(void *thing, int read);
int  testlock(void *thing, int read) asm("@@LKTEST");

/* __lkunlk() - release lock previously acquired */
/* return 0 if successful, otherwise you didn't have the lock */
int  __lkunlk(void *thing, int read);
int  unlock(void *thing, int read) asm("@@LKUNLK");

/* ---- resource address lock functions (SCOPE=SYSTEM) ---- */

/* syslock() - lock "thing" address (SCOPE=SYSTEM), read: 0=exclusive, 1=shared */
/* return 0 if lock acquired, 8 if you already have the lock. */
int  syslock(void *thing, int read) asm("@@SL");

/* systrylock() - lock "thing" address if available (SCOPE=SYSTEM), immediate return. */
/* return 0 if lock acquired, 4 if the lock is not immediately available, 8 if you already have the lock. */
int  systrylock(void *thing, int read) asm("@@SLTRY");

/* systestlock() - test if "thing" address is locked (SCOPE=SYSTEM) */
/* return 0 if not locked, 4 if the lock is not immediately available, 8 if you already have the lock. */
int  systestlock(void *thing, int read) asm("@@SLTEST");

/* sysunlock() - release lock previously acquired (SCOPE=SYSTEM) */
/* return 0 if successful, otherwise you didn't have the lock */
int  sysunlock(void *thing, int read) asm("@@SLUNLK");

/* ---- resource name lock functions ---- */

/* __lfrn() - lock resource name, read: 0=exclusive, 1=shared */
/* return 0 if lock acquired, 8 if you already have the lock. */
int  __lkrn(const char *rname, int read);
int  lock_res(const char *rname, int read) asm("@@LKRN");

/* __lkrnte() - test if resource is locked */
/* return 0 if not locked, 4 if locked, 8 if you already have the lock. */
int  __lkrnte(const char *rname, int read);
int  testlock_res(const char *rname, int read) asm("@@LKRNTE");

/* __lkuntr() - lock resource if available, immediate return. */
/* return 0 if not locked, 4 if locked, 8 if you already have the lock. */
int  __lkuntr(const char *rname, int read);
int  trylock_res(const char *rname, int read) asm("@@LKUNTR");

/* __lkrnun() - unlock resource name */
/* return 0 if successful, otherwise you didn't have the lock */
int  __lkrnun(const char *rname, int read);
int  unlock_res(const char *rname, int read) asm("@@LKRNUN");

/* ---- printf style resource name lock functions ---- */

/* __lkrnf() - lock printf style resource name */
/* return 0 if lock acquired, 8 if you already have the lock. */
int  __lkrnf(const char *fmt, int read, ...);
int  lock_resf(const char *fmt, int read, ...) asm("@@LKRNF");

/* __lkrtef() - test lock printf style resource name */
/* return 0 if lock acquired, 8 if you already have the lock. */
int  __lkrtef(const char *fmt, int read, ...);
int  testlock_resf(const char *fmt, int read, ...) asm("@@LKRTEF");

/* __lkuntf() - lock printf style resource name if available. */
/* return 0 if not locked, 4 if locked, 8 if you already have the lock. */
int  __lkuntf(const char *fmt, int read, ...);
int  trylock_resf(const char *fmt, int read, ...) asm("@@LKUNTF");

/* __lkrnuf() - unlock printf style resource name */
/* return 0 if successful, otherwise you didn't have the lock */
int  __lkrnuf(const char *fmt, int read, ...);
int  unlock_resf(const char *fmt, int read, ...) asm("@@LKRNUF");

#if 0
#define lock(thing,read)        (__lk((thing),(read)))
#define trylock(thing,read)     (__lktry((thing),(read)))
#define testlock(thing,read)    (__lktest((thing),(read)))
#define unlock(thing,read)      (__lkunlk((thing),(read)))
#define lock_res(rname,read)    (__lkrn((rname),(read)))
#define testlock_res(rname,read) (__lkrnte((rname),(read)))
#define trylock_res(rname,read) (__lkuntr((rname),(read)))
#define unlock_res(rname,read)  (__lkrnun((rname),(read)))
#define lock_resf(fmt,read,...) (__lkrnf((fmt),(read), ##__VA_ARGS__))
#define testlock_resf(fmt,read,...) (__lkrtef((fmt),(read), ##__VA_ARGS__))
#define trylock_resf(fmt,read,...) (__lkrntf((fmt),(read), ##__VA_ARGS__))
#define unlock_resf(fmt,read,...) (__lkrnuf((fmt),(read), ##__VA_ARGS__))
#endif

#endif
