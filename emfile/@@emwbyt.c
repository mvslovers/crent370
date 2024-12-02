#include "emfilei.h"

int emfile_write_bytes(EMFILE *f, const char *buf, unsigned size) 
{
	int			rc			= EPERM;
	unsigned	length		= (unsigned)size;
	unsigned	len;
	unsigned	block;
	unsigned    pos;
	
	// wtof("%s: enter", __func__);

	if (!(f->flags & EMFILE_FLAG_WRITE)) goto quit;

	while (size > 0) {
		/* calculate buffer position and block number */
		rc = emfile_offset_block_pos(f, &block, &pos);
		if (rc) goto quit;

		// wtof("%s: block=%u pos=%u", __func__, block, pos);

		if (block != f->block) {
			/* flush any pending output */
			rc = emfile_flush(f);
			wtof("%s: emfile_flush() rc=%d", __func__, rc);
			if (rc) goto quit;

			/* check if we need to grow the file */
			if (block >= f->blocks) {
				rc = emfile_grow(f, size);
				wtof("%s: emfile_grow(%u) rc=%d", __func__, size, rc);
				if (rc) goto quit;
			}

			/* read the block for this write */
			rc = emfile_read_block(f, block, f->buf);
			wtof("%s: emfile_read_block(%u) rc=%d", __func__, block, rc);
			if (rc) goto quit;
		}

		if ((pos + size) > f->blksize) {
			len = f->blksize - pos;
		}
		else {
			len = size;
		}

		memcpy(&f->buf[pos], buf, len);
		f->flags |= EMFILE_FLAG_DIRTY;

		buf 	+= len;
		size 	-= len;
		__64_add_u32(&f->offset, len, &f->offset);
		if (__64_cmp(&f->offset, &f->used) == __64_LARGER) {
			f->used = f->offset;
		}
	}

	rc = 0;

quit:
	if (rc) {
		f->error = rc;
		if (!errno) errno = rc;
	}

	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
