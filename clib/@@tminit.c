#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tmr_init'");
int tmr_init(void)
{
    TMR     *tmr = tmr_get();
    int     lockrc;

    lockrc = lock(tmr, 0);
    if (!(tmr->flags & TMR_FLAG_INIT)) {
        /* not initialized yet */
        strcpy(tmr->eye, TMR_EYE);
        /* init the next avail ID value */
        tmr->id    = ((unsigned)rand() << 8) & 0x00FFFF00; /* pseudo random value */
        tmr->flags = TMR_FLAG_INIT;
    }
    if (lockrc==0) unlock(tmr, 0);

    return 0;
}
