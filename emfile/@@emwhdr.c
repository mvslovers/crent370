#include "emfilei.h"

int emfile_write_header(EMFILE *f)
{
	int			rc		= 0;
	EMFILE10	*hdr	= NULL;
	char		*buf	= NULL;

	// wtof("%s: enter", __func__);

	/* make sure we can write to this dataset */
	if (!(f->flags & EMFILE_FLAG_WRITE)) goto quit;
	
	buf	= calloc(1, f->blksize);
	if (!buf) {
		errno = ENOMEM;
		rc = -1;
		goto quit;
	}
	
	/* read header block */
	rc = emfile_read_block(f, 0, buf);
	if (rc) goto quit;

	/* update header record */
	rc = emfile_create_header(f->r0, f->used);
	if (rc) goto quit;
	hdr	= (EMFILE10 *)f->r0;

	/* copy header record */
	memset(buf, 0, f->blksize);
	memcpy(buf, hdr, sizeof(EMFILE10));
	
	/* write header record to dataset */
	rc = emfile_write_block(f, 0, buf);

quit:
	if (buf) free(buf);
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
