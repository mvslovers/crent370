/* @@smca.c
** return pointer to SMF control table or NULL if it doesn't exist.
*/
#include "clibsmf.h"
#include "cvt.h"

SMCA *
__smca(void)
{
    unsigned    	*psa    = (unsigned *)0;			/* PSA address */
    CVT				*cvt    = (CVT *)psa[16/4];			/* CVT address */
    SMCA         	*smca   = (SMCA *)cvt->cvtsmca;		/* SMF control table, CVTSMCA value */

	return smca;
}

