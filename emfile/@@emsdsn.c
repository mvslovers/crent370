#include "emfilei.h"

int emfile_set_dsn(const char *dsn, char *dest)
{
	int		rc = 0;
	int		i;
	
	for(i=0; (i < MAXDSN) && (dsn[i] > ' '); i++) {
		if (!dsn[i]) break;
		dest[i] = toupper(dsn[i]);
	}
	dest[i] = 0;
	
	return rc;
}
