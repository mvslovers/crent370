#include "emfilei.h"

int emfile_sync(EMFILE *f)
{
	int		rc		= 0;
	
	// wtof("%s: enter", __func__);
	
	if (!f) goto quit;

	/* make sure we can write to this dataset */
	if (!(f->flags & EMFILE_FLAG_WRITE)) goto quit;

	/* flush any pending output to disk */
	rc = emfile_flush(f);
	if (rc) goto quit;

	/* rewrite the dataset header */
	rc = emfile_write_header(f);
	
quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
