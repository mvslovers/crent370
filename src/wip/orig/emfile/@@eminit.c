#include "emfilei.h"

int emfile_init(const char *ddname, unsigned blksize, JFCB *jfcb)
{
	int			rc		= 1;
	unsigned	block	= 0;
	char 		*buf	= NULL;
	DCB			*dcb	= NULL;
	DECB		decb	= {0};
	__64 		zero;
	
	wtof("%s: enter", __func__);

    buf = calloc(1, blksize);
    if (!buf) {
		wtof("%s: calloc() failed for %u bytes", __func__, blksize);
		errno = ENOMEM;
		goto quit;
	}
	
	dcb = osbdcb(ddname, NULL);
	if (!dcb) {
		wtof("%s: osbdcb(\"%s\", NULL) failed", __func__, ddname);
		errno = ENOMEM;
		goto quit;
	}

    /* set block size in DCB */
	dcb->dcbrecfm = DCBRECF;
    dcb->dcbblksi = (unsigned short)blksize;
    dcb->dcblrecl = (unsigned short)blksize;

    /* open BSAM dataset in "load" mode */
    rc = osbopen(dcb, 0, "load");
    if (rc) {
		wtof("%s: osbopen() failed with rc=%d", __func__, rc);
        goto quit;
    }
    
    wtodumpf(dcb, sizeof(DCB), "%s: DCB", __func__);

	/* create initial header record in our buf */
	__64_from_u32(&zero, 0);
	rc = emfile_create_header(buf, zero);
	if (rc) goto quit;

    /* we only want to initialize the primary extent, skip secondary extents even if allocated */
    /* rc=4 is end of track, rc=8 is end of extent, rc=12 is write error, no more tracks (SB37) */
    for(block=0; rc < 4; block++) {
        rc = oswrite(&decb, dcb, buf, blksize);

        /* check for real write errors */
        if (rc > 8) {
            wtof("%s: oswrite() returned rc=%d for block %d", __func__, rc, block);
            goto quit;
        }

        /* we have to CHECK to make sure the write completed okay */
        oscheck(&decb);

        if (block==0) {
			memset(buf, 0, blksize);
		}
    }
	
	wtof("%s: initialized %u blocks", __func__, block);
	rc = 0;
	
quit:
	if (dcb) osbclose(dcb, NULL, 1, 0);
	if (buf) free(buf);
	wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
