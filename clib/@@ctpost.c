/* @@CTPOST.C - cthread_post()
*/
#include "clibthrd.h"

__asm__("\n&FUNC    SETC 'cthread_post'");
int
cthread_post(ECB *ecb, unsigned code)
{
    int     rc  = 0;

    if (!ecb) goto quit;

    code = code & ECB_VALUE_MASK;
    rc = ecb_post(ecb, code);

quit:
    return rc;
}
