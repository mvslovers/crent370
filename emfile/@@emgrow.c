#include "emfilei.h"

/* attempt to grow our dataset to accomodate the requested
 * number of bytes.
 */
int emfile_grow(EMFILE *f, unsigned bytes)
{
	int			rc			= 0;
	unsigned	asize		= f->blksize - 1;
	unsigned	blocks		= ((bytes+asize) / f->blksize);
	unsigned	block		= 0;
	unsigned	adjust		= 0;
	char 		*buf		= NULL;
	DCB			*dcb		= NULL;
	DECB		decb		= {0};
	char 		ddname[12]	= "";
	int			i;
	
	wtof("%s: enter bytes=%u", __func__, bytes);

	if (!f->growdd) {
		/* attempt to allocate our dataset with DISP=MOD */
		rc = emfile_allocate_mod(f, ddname);
		// wtof("%s: emfile_allocate_mod() rc=%d ddname=%s", __func__, rc, ddname);
		if (rc) goto quit;

		f->growdd = strdup(ddname);
		if (!f->growdd) {
			errno = rc = ENOMEM;
			goto quit;
		}
	}
			
	/* allocate a buffer for our writes */
    buf = calloc(1, f->blksize);
    if (!buf) {
		wtof("%s: calloc() failed for %u bytes", __func__, f->blksize);
		errno = rc = ENOMEM;
		goto quit;
	}

	/* open a DCB for this ddname */
	dcb = osbdcb(f->growdd, NULL);
	if (!dcb) {
		wtof("%s: osbdcb(\"%s\", NULL) failed", __func__, f->growdd);
		errno = rc = ENOMEM;
		goto quit;
	}

	/* set block size in DCB */
	dcb->dcbrecfm = DCBRECF;
	dcb->dcbblksi = (unsigned short)f->blksize;
	dcb->dcblrecl = (unsigned short)f->blksize;
	
	/* open BSAM dataset in write mode */
	rc = osbopen(dcb, 0, "w");
	if (rc) {
		wtof("%s: osbopen() failed with rc=%d", __func__, rc);
		errno = rc = EIO;
		goto quit;
	}
    
	rc = 0;

#if 1 /* new code testing */	
	/* for performance reasons we want to grow a full track at a time
	 * so we'll adjust the blocks count to the blocks per track
	 */
	// wtof("%s: f->blocks=%u f->blkstrk=%u", __func__, f->blocks, f->blkstrk);
	adjust = f->blkstrk - ((f->blocks + blocks) % f->blkstrk);
	// wtof("%s: adjust=%u", __func__, adjust);

	/* adjust is how many blocks we need to align to track boundary */
	if (adjust > 0 && adjust <= f->blkstrk) {
		blocks += adjust;
		// wtof("%s:adjusted blocks=%u", __func__, blocks);
	}
#endif

    /* we're extending the blocks in this dataset
     * rc=4 is end of track, rc=8 is end of extent, 
     * rc=12 is write error, 
     * 	no more tracks 	(SB37) 
     *  no more extents (SD37)
     */
    // wtof("%s: blocks=%u", __func__, blocks);
    
    for(block=0; block < blocks && rc<=8; block++) {
        rc = oswrite(&decb, dcb, buf, f->blksize);

        /* check for real write errors */
        if (rc > 8) {
            wtof("%s: oswrite() returned rc=%d for block %d", __func__, rc, block);
            goto quit;
        }

        /* we have to CHECK to make sure the write completed okay */
        rc = oscheck(&decb);
        // wtof("%s: oscheck() rc=%d", __func__, rc);
        // wtodumpf(&decb, sizeof(DECB), "%s: DECB", __func__);
        if (rc) {
			unsigned abcode = (unsigned)rc & 0x00FFFFFF;
			unsigned sysabend = abcode >> 12;
			unsigned userabend = abcode & 0xFFF;
			
			if (sysabend) {
				if (sysabend == 0x0B37 || sysabend == 0x0D37 || sysabend == 0x0E37) {
					wtof("%s: S%03X Abend attempting to grow dataset %s", __func__, sysabend, "ENOSPC");
					errno = rc = ENOSPC;
				}
				else {
					wtof("%s: S%03X Abend attempting to grow dataset %s", __func__, sysabend, "EIO");
					errno = rc = EIO;
				}
				break;
			}
			if (userabend) {
				wtof("%s: U%04u Abend attempting to grow dataset EINTR", __func__, userabend);
				errno = rc = EINTR;
				break;
			}
			wtof("%s: Unexpected error rc=%d 0x%08X EIO", __func__, rc, rc);
			errno = rc = EIO;
			break;
		}
    }
	
	// wtof("%s: wrote %u blocks", __func__, block);
	// wtof("%s: old blocks=%u", __func__, f->blocks);
	
quit:
	if (dcb) {
		osbclose(dcb, NULL, 1, 0);
		dcb = NULL;
	}
	if (buf) free(buf);

	/* even if we failed we should recalculate the dataset size */
	emfile_calc_size(f);
	// wtof("%s: new blocks=%u", __func__, f->blocks);

	wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
