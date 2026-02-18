#include <clibtmr.h>

static TMR key = {0};

__asm__("\n&FUNC    SETC 'tmr_get'");
TMR *tmr_get(void)
{
    TMR     *tmr = __wsaget(&key, sizeof(TMR));

    return tmr;
}
