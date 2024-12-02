#include "emfilei.h"

int emfile_write_block(EMFILE *f, unsigned block, char *buf)
{
	int			rc;

	// wtof("%s: enter block=%u", __func__, block);

	if (!(f->flags & EMFILE_FLAG_WRITE)) {
		wtof("%s: attempt to write block %u of READONLY dataset", 
			__func__, block);
		errno = EINVAL;
		rc = 8;
		goto quit;
	}

	rc = osdwrite(f->bdamdecb, f->bdamdcb, buf, f->blksize, block);
	if (rc) {
		wtof("%s: osdwrite() rc=%d", __func__, rc);
		goto quit;
	}

	rc = oscheck(f->bdamdecb);
	if (rc) {
		wtof("%s: oscheck() rc=%d", __func__, rc);
		goto quit;
	}

	/* success */
	if (buf == f->buf) {
		// wtof("%s: reset DIRTY flag", __func__);
		f->flags	&= ~EMFILE_FLAG_DIRTY;	/* block was written */
	}

quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
