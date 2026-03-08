#include "emfilei.h"

/* this function is limited to 2G-1 size files */
int emfile_truncate(EMFILE *f, long int length)
{
	int			rc			= 0;
	__64		diff;
	__64 		offset;
	unsigned	len;
	unsigned	block;
	unsigned    pos;
	unsigned	size;
	
	wtof("%s: enter length=%u", __func__, length);

	if (length < 0) {
		errno = f->error = EINVAL;
		rc = -1;
		goto quit;
	}

	/* position to the desired offset (length) */
	rc = emfile_seek(f, length, SEEK_SET);
	if (rc) goto quit;

	/* remember our truncation offset */
	offset = f->offset;

	if (__64_cmp(&f->used, &f->offset) == __64_LARGER) {
		/* we need to clear the bytes after end of file */
		__64_sub(&f->used, &f->offset, &diff);
		size = diff.u32[1];
		wtof("%s: erasing %u bytes", __func__, size);

		while (size > 0) {
			/* calculate buffer position and block number */
			rc = emfile_offset_block_pos(f, &block, &pos);
			wtof("%s: emfile_offset_block_pos() rc=%d", __func__, rc);
			if (rc) goto quit;

			if (block != f->block) {
				/* flush any pending output */
				rc = emfile_flush(f);
				wtof("%s: emfile_flush() rc=%d", __func__, rc);
				if (rc) goto quit;

				/* read the block for this write */
				rc = emfile_read_block(f, block, f->buf);
				wtof("%s: emfile_read_block() rc=%d", __func__, rc);
				if (rc) goto quit;
			}

			if ((pos + size) > f->blksize) {
				len = f->blksize - pos;
			}
			else {
				len = size;
			}

			wtof("%s: clearing block=%u pos=%u bytes=%u", 
				__func__, block, pos, len);
			memset(&f->buf[pos], 0, len);
			f->flags |= EMFILE_FLAG_DIRTY;

			size 	-= len;
			__64_add_u32(&f->offset, len, &f->offset);
		}
	}

	/* truncate the file */
	f->offset 	= offset;
	f->used 	= offset;
	
	/* reset the EOF flag */
	f->flags &= ~EMFILE_FLAG_EOF;

	/* sync the file */
	rc = emfile_sync(f);
	wtof("%s: emfile_sync() rc=%d", __func__, rc);
	if (rc) goto quit;

quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
