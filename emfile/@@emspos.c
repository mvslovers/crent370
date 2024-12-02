#include "emfilei.h"

int emfile_setpos(EMFILE *f, const __64 *pos)
{
	int			rc = EBADF;
	
	wtof("%s: enter", __func__);
	
	if (!f) goto quit;
	if (!pos) goto quit;

	if (__64_cmp((__64*)pos, &f->used) == __64_LARGER) {
		f->error = rc = EINVAL;
		goto quit;
	}
	
	f->offset = *pos;
	rc = 0;

quit:
	if (rc==0) {
		/* reset the EOF flag */
		f->flags &= ~EMFILE_FLAG_EOF;
	}
	else {
		errno = rc;
	}

	wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
