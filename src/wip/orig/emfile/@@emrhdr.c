#include "emfilei.h"

int emfile_read_header(EMFILE *f)
{
	int			rc		= 0;
	EMFILE10	*hdr	= (EMFILE10 *)f->r0;
	char		*buf	= NULL;

	// wtof("%s: enter", __func__);

	buf	= calloc(1, f->blksize);
	if (!buf) {
		errno = ENOMEM;
		rc = -1;
		goto quit;
	}
	
	rc = emfile_read_block(f, 0, buf);
	if (rc) goto quit;

	/* copy header record */
	memcpy(f->r0, buf, sizeof(EMFILE10));
	
	/* update emfile handle */
	f->used 		= hdr->size;

	/* sanity check, offset must be less than or equal to bytes */
	if (__64_cmp(&f->used, &f->offset) == __64_SMALLER) {
		f->offset = f->used;
	}
	
quit:
	if (buf) free(buf);
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
