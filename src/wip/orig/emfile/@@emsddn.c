#include "emfilei.h"

int emfile_set_ddn(const char *ddn, char *dest)
{
	int		rc = 0;
	int		i;
	
	for(i=0; (i < MAXDDN) && (ddn[i]); i++) {
		dest[i] = toupper(ddn[i]);
	}
	dest[i] = 0;
	
	return rc;
}
