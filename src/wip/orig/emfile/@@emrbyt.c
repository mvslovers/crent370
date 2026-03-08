#include "emfilei.h"

/* returns bytes read (>=0) or error (<0) */
int emfile_read_bytes(EMFILE *f, char *buf, unsigned size, const char *stopc) 
{
	int			rc			= EPERM;
	char 		*cp			= NULL;
	int			read		= 0;
	unsigned	length		= (unsigned)size;
	unsigned	len;
	unsigned	block;
	unsigned    pos;
	__64		toffset;
	
	// wtof("%s: enter", __func__);

	if (!(f->flags & EMFILE_FLAG_READ)) goto quit;

	if (f->flags & EMFILE_FLAG_EOF) {
		read = EOF;
		goto quit_eof;
	}

	rc = 0;
	while (size > 0) {
		if (__64_cmp(&f->offset, &f->used) != __64_SMALLER) {
			f->flags |= EMFILE_FLAG_EOF;
			/* we don't set f->error as EOF is not an error */
			break;	/* we'll return the bytes we've already read */
		}
		
		/* calculate buffer position and block number */
		rc = emfile_offset_block_pos(f, &block, &pos);
		if (rc) goto quit;

		// wtof("%s: block=%u pos=%u", __func__, block, pos);

		if (block != f->block) {
			/* flush any pending output */
			rc = emfile_flush(f);
			if (rc) goto quit;

			/* read the block for this write */
			rc = emfile_read_block(f, block, f->buf);
			if (rc) goto quit;
		}

		if ((pos + size) > f->blksize) {
			len = f->blksize - pos;
		}
		else {
			len = size;
		}

		/* if (offset + len > used) len = used - offset; */
		// wtof("%s: f->offset=%llu len=%u f->used=%llu", __func__, f->offset, len, f->used);
		__64_add_u32(&f->offset, len, &toffset);
		if (__64_cmp(&toffset, &f->used) == __64_LARGER) {
			__64_sub(&f->used, &f->offset, &toffset);
			len = toffset.u32[1];
			// wtof("%s: new len=%u", __func__, len);
		}

		if (!len) {
			// wtof("%s: len==0 EOF detected", __func__);
			f->flags |= EMFILE_FLAG_EOF;
			break;
		}
		if (len > f->blksize) {
			/* should never happen */
			// wtof("%s: len > f->blksize", __func__);
			rc = EPERM;
			goto quit;
		}
		
		memcpy(buf, &f->buf[pos], len);
		if (len < size) buf[len] = 0;
		if (stopc) {
			cp = memchr(buf, *stopc, len);
			// wtof("%s: len=%u buf=0x%08X cp=0x%08X", __func__, len, buf, cp);
			
			if (cp) {
				unsigned bytes = (unsigned)((cp - buf) + 1);
				unsigned i = len - bytes;
				
				// wtof("%s: stopc=0x%02X bytes=%u i=%u", __func__, *stopc, bytes, i);
				if (i>0) memset(&buf[bytes], 0, i);
				// wtodumpf(buf, len, "%s: buf", __func__);
				len = bytes;
			}
		}

		read	+= len;
		buf 	+= len;
		size 	-= len;
		__64_add_u32(&f->offset, len, &f->offset);
		// wtof("%s: f->offset=%llu f->used=%llu", __func__, f->offset, f->used);

		if (cp) break;
	}

	rc = 0;

quit:
	if (rc) {
		f->error = rc;
		if (!errno) errno = rc;
		if (rc > 0) rc *= -1;	/* make rc negative value */
		read = rc;
	}

quit_eof:
	// wtof("%s: exit rc=%d", __func__, read);
	return read;
}
