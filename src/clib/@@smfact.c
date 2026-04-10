/* @@smfact.c
** smf_active() - check if SMF recording is active.
** Returns: 1=active, 0=inactive or SMCA not found
*/
#include "clibsmf.h"

__asm__("\n&FUNC    SETC 'smf_active'");
int
smf_active(void)
{
    SMCA *smca = __smca();
    if (!smca) return 0;

    /* SMCAUSER + SMCAMAN = SMF and user recording requested */
    return (smca->smcamisc & (SMCAUSER | SMCAMAN)) != 0;
}
