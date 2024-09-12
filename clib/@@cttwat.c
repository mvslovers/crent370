/* @@CTTWAT.C - cthread_timed_wait()
**
*/
#include "clibthrd.h"
#include "clibcrt.h"

__asm__("\n&FUNC    SETC 'cthread_timed_wait'");
int
cthread_timed_wait(unsigned *ecb, unsigned bintvl, unsigned postcode)
{
    volatile int rc     = 0;    /* volatile needed to bypass bug in GCC */

    if (!ecb) goto quit;

    ecb_timed_wait(ecb, bintvl, postcode);

    /* return value of posted ECB */
    rc = *ecb & ECB_VALUE_MASK;
    *ecb = 0;

quit:
    return rc;
}
