#include "emfilei.h"

int emfile_getpos(EMFILE *f, __64 *pos)	
{
	int			rc = EBADF;
	
	wtof("%s: enter", __func__);
	
	if (!f) goto quit;
	if (!pos) goto quit;

	*pos = f->offset;
	rc = 0;

quit:
	if (rc) errno = rc;

	wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
