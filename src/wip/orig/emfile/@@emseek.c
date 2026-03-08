#include "emfilei.h"

int emfile_seek(EMFILE *f, long int offset, int origin)
{
	int		rc			= 0;
	
	// wtof("%s: enter", __func__);
	
	if (!f) {
		errno = rc = EBADF;
		goto quit;
	}
	
	switch(origin) {
		case SEEK_SET:
			// wtof("%s: SEEK_SET offset=%d", __func__, offset);
			if (offset >= 0) {
				__64_from_u32(&f->offset, (unsigned)offset);
			}
			else {
				__64_from_u32(&f->offset, 0);
			}
			break;

		case SEEK_CUR:
			// wtof("%s: SEEK_CUR offset=%d", __func__, offset);
			if (offset >= 0) {
				__64_add_u32(&f->offset, (unsigned)offset, &f->offset);
			}
			else {
				offset *= -1;	/* make positive value */
				if (__64_cmp_u32(&f->offset, (unsigned)offset) != __64_SMALLER) {
					__64_sub_u32(&f->offset, (unsigned)offset, &f->offset);
				}
				else {
					/* new offset is start of file */
					__64_from_u32(&f->offset, 0);
				}
			}
			break;

		case SEEK_END:
			// wtof("%s: SEEK_END offset=%d", __func__, offset);
			if (offset >= 0) {
				/* this will cause the file to grow beyond end of file */
				__64_add_u32(&f->used, (unsigned)offset, &f->offset);
			}
			else {
				offset *= -1;	/* make positive value */
				if (__64_cmp_u32(&f->used, (unsigned)offset) != __64_SMALLER) {
					__64_sub_u32(&f->used, (unsigned)offset, &f->offset);
				}
				else {
					/* new offset is start of file */
					__64_from_u32(&f->offset, 0);
				}
			}
			break;

		default:
			errno = rc = EINVAL;
			goto quit;
	}

	/* Here we attempt to handle the case of the new offset being
	 * beyond the logical end of file (f->used) and adjust the
	 * offset (READ ONLY) or grow the file to accomodate the new
	 * offset and adjust the end of file for the new offset.
	 */

	if (__64_cmp(&f->offset, &f->used)==__64_LARGER) {
		/* offset is beyond logical end of file */
		__64 	diff;

		if (!(f->flags & EMFILE_FLAG_WRITE)) {
			/* read only file */
			f->offset = f->used;	/* let's keep them in bounds for now */
			goto quit;
		}

		/* write enabled file */

		/* is offset <= allocated bytes? */
		if (__64_cmp(&f->offset, &f->alloc) != __64_LARGER) {
			/* Yes, move end of file to offset */
			f->used = f->offset;
			goto quit;
		}

		/* offset is larger than allocated bytes */

		/* move end of file to total allocated bytes */
		f->used = f->alloc;

		/* calculate how many bytes we need to grow the file */
		__64_sub(&f->offset, &f->alloc, &diff);
		if (diff.u32[1]) {
			rc = emfile_grow(f, diff.u32[1]);
			if (rc) goto quit;
			
			/* add bytes we grew to the end of file offset */
			__64_add(&f->used, &diff, &f->used);
		}
	}
	
quit:
	if (rc==0) {
		/* A successful seek always resets the EOF flag */
		f->flags &= ~EMFILE_FLAG_EOF;	/* reset EOF flag	*/
	}
	if (f) {
		// wtof("%s: alloc=%llu used=%llu offset=%llu", 
		// 	__func__, f->alloc, f->used, f->offset);
	}
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
