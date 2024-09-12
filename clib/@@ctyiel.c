#include <clibthrd.h>

__asm__("\n&FUNC    SETC 'cthread_yield'");
int cthread_yield(void)
{
    ECB     ecb = 0;

    /* yield CPU using timed wait of .01 seconds (1 == .01 seconds) */
    ecb_timed_wait(&ecb, 1, 0);

    return 0;
}
