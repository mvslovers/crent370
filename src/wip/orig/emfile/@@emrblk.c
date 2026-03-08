#include "emfilei.h"

int emfile_read_block(EMFILE *f, unsigned block, char *buf)
{
	int			rc			= 0;
	int			retry		= 0;
	void		*old_synad	= 0;
	void 		*new_synad	= 0;
	unsigned	ecb;

	// wtof("%s: enter block=%u", __func__, block);

	/* if the data in the buffer has changed we need to write
	 * that data to disk before we read in the next block.
	 */
	rc = emfile_flush(f);
	if (rc) goto quit;

	if (!f->blocks) {
		/* empty file, fail the read */
		wtof("%s: empty file", __func__);
		rc = 8;
		goto quit;
	}

	if (block > f->blocks) {
		/* attempt to read past end of dataset */
		wtof("%s: desired block %u beyond EOF %u",
			__func__, block, f->blocks);
		rc = 12;
		goto quit;
	}

	/* When we've added another track vai emfile_grow() creating
	 * additional blocks, the existing BDAM DCB doesn't know about
	 * the new tracks and will fail the read generating IEC020
	 * messages along the way.
	 * 
	 * To prevent this unwanted behavior we're going to use a dummy
	 * SYNAD routine (see after end of thsi function) so that control
	 * returns without generating any message.
	 * 
	 * It's then up to us to check the ECB in the DECB area as
	 * being POSTED with the error information.
	 */

	__asm__("LA\t0,RDSYNAD\n\t"
			"ST\t0,0(,%0)" : : "r"(&new_synad));
	old_synad = f->bdamdcb->dcbsynad;
	f->bdamdcb->dcbsynad = new_synad;

again:	
	rc = osdread(f->bdamdecb, f->bdamdcb, buf, f->blksize, block);
	if (rc) {
		wtof("%s: osdread() block=%u rc=%d", __func__, block, rc);
		wtodumpf(f->bdamdcb, sizeof(DCB), "%s: BDAMDCB", __func__);
		goto quit;
	}

	rc = oscheck(f->bdamdecb);
	ecb = f->bdamdecb->decsdecb;
	
	// wtodumpf(f->bdamdecb, sizeof(DECB), "%s: BDAMDECB", __func__);
	if (rc || ecb != 0x40000000) {
		wtof("%s: oscheck() block=%u rc=%d ecb=0x%08X", __func__, block, rc, ecb);
		// wtodumpf(f->bdamdcb, sizeof(DCB), "%s: BDAMDCB", __func__);
		if (!retry) {
			retry++;
			/* lets try closing and reopening */
			// wtof("%s: closing f->bdamdcb=0x%08X", __func__, f->bdamdcb);
			osdclose(f->bdamdcb, 1);

			// wtof("%s: opening f->ddname=%s", __func__, f->ddname);
			f->bdamdcb = osddcb(f->ddname);
			// wtof("%s: f->bdamdcb=0x%08X", __func__, f->bdamdcb);

			rc = osdopen(f->bdamdcb, 0);
			// wtof("%s: osdopen() rc=%d", __func__, rc);

			/* install out dummy SYNAD routine */
			f->bdamdcb->dcbsynad = new_synad;

			/* clear the DECB area */
			memset(f->bdamdecb, 0, sizeof(DECB));
			if (rc==0) goto again;
		}
		if (!rc) rc = ecb;	/* we don't want to exit rc=0 if we failed */
	}

	/* restore previous synad */
	f->bdamdcb->dcbsynad = old_synad;

	if ((rc==0) && (buf == f->buf)) {
		f->block 	= block;
		f->flags	&= ~EMFILE_FLAG_DIRTY;
	}

quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
__asm__("DS\t0H\n"
"* Dummy SYNAD for our READ BDAM DCB\n"
"RDSYNAD\tDS\t0H\n"
"         BR\t14"
);
