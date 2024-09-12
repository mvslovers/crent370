/* @@smfid.c
** return pointer to SMFID or NULL if SMF does not exist.
*/
#include "clibsmf.h"

extern const unsigned char *
__smfid(void)
{
    SMCA         	*smca   = __smca();					/* SMF control table, CVTSMCA value */
	unsigned char   *result = (unsigned char *)0;
	
	if (smca) {
		result = smca->smcasid;	/* SMFID is located in the smca->smcaasid 4 character variable */
	}

	return result;
}
#if 0
__asm__( "IEESMCA ,\n\t" );
#endif

