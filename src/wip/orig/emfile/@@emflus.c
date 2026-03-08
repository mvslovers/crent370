#include "emfilei.h"

int emfile_flush(EMFILE *f)
{
	int		rc		= 0;

	// wtof("%s: enter", __func__);
	
	/* make sure we can write to this dataset */
	if (!(f->flags & EMFILE_FLAG_WRITE)) goto quit;
	
	/* flush any pending output to disk */
	if (f->flags & EMFILE_FLAG_DIRTY) {
		rc = emfile_write_block(f, f->block, f->buf);
		if (rc) goto quit;
	}

quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
