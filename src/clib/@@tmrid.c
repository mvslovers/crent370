#include <clibtmr.h>

static int unique_id(TMR *tmr, unsigned id);

__asm__("\n&FUNC    SETC 'tmr_id'");
unsigned
tmr_id(void)
{
    unsigned    *psa    = (unsigned *)0;
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    unsigned    *ascb   = (unsigned *)psa[0x224/4]; /* ascb     == PSAAOLD  */
    unsigned    asid    = ((ascb[0x24/4]) >> 16);
    TMR         *tmr    = tmr_get();
    unsigned    id;
    int         lockrc;

    tmr_init();

    lockrc = lock(tmr, 0);
    do {
        tmr->id = (tmr->id ^ rand()) & 0x00FFFFFF;
        switch (tmr->id & 3) {
        case 0:
            id = tmr->id - rand();
            break;
        case 1:
            id = tmr->id ^ rand();
            break;
        case 2:
            id = tmr->id % (rand() + 1);
            break;
        case 3:
            id = tmr->id * (rand() & 0xFF);
            break;
        }
        id = id & 0x00FFFFFF;
        if (id > 1000 && unique_id(tmr, id)) break;
    } while(1);
    if (lockrc==0) unlock(tmr, 0);

    return id;
}

__asm__("\n&FUNC    SETC 'unique_id'");
static int
unique_id(TMR *tmr, unsigned id)
{
    int         rc      = 1;    /* assume unique id */
    unsigned    count   = array_count(&tmr->tqe);
    unsigned    n;

    for(n=0; n < count; n++) {
        TQE *tqe = tmr->tqe[n];

        if (!tqe) continue;
        if (tqe->id == id) {
            rc = 0; /* not unique */
            break;
        }
    }

    if (rc) tmr->id = id;
    return rc;
}
