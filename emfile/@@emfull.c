#include "emfilei.h"

int emfile_full_init(const char *ddname, unsigned blksize, JFCB *jfcb)
{
	int			rc			= 1;
	unsigned	block		= 0;
	unsigned	blocks		= 0;
	unsigned	tracks		= 0;
	unsigned	blkstrk		= 0;
	unsigned	pri			= 0;
	unsigned	sec			= 0;
	char 		*buf		= NULL;
	DCB			*dcb		= NULL;
	DVATAB		dvatab 		= {0};
	DECB		decb		= {0};
	__64 		zero;
	
	wtof("%s: enter", __func__);

	/* calculate the number of blocks to initialize */

	/* get the device type information for the DDNAME */
	__asm__("LR\t0,%0        Output area\n\t"
			"LCR\t0,0        DEVTAB desired\n\t"
			"LR\t1,%1        DD name\n\t"
			"SVC\t24         DEVTYPE" 
			: 
			: "r"(&dvatab), "r"(ddname) );

	/* get the number of blocks per track for this device type */
	blkstrk = trkcalc((DEVTYPE)dvatab.dvaunit, 0, blksize);
	wtof("%s: blocks per track=%u", __func__, blkstrk);

	/* get the primary and secondary allocation size */
	pri = (jfcb->jfcbpqty[0] << 16 | jfcb->jfcbpqty[1] << 8 | jfcb->jfcbpqty[2]);
	sec = (jfcb->jfcbsqty[0] << 16 | jfcb->jfcbsqty[1] << 8 | jfcb->jfcbsqty[2]);
	wtof("%s: pri=%u sec=%u", __func__, pri, sec);
	
	if ((jfcb->jfcbctri & JFCBCYL) == JFCBCYL) {
		pri *= 15;
		sec *= 15;
		wtof("%s: CYL adjusted pri=%u sec=%u", __func__, pri, sec);
	}

	/* first volume tracks */
	tracks = pri + (sec * 15);
	wtof("%s: first volume tracks=%u", __func__, tracks);

	if (jfcb->jfcbnvol > 1) {
		tracks += (sec * 16) * (jfcb->jfcbnvol - 1);
		wtof("%s: plus additional volumes tracks=%u", __func__, tracks);
	}

	blocks = blkstrk * tracks;
	wtof("%s: total blocks=%u", __func__, blocks);

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

	/* format a header record in our buf */
	__64_from_u32(&zero, 0);
	rc = emfile_create_header(buf, zero);
	if (rc) goto quit;
	
    wtof("%s: initializing %u blocks", __func__, blocks);

    /* we are going to write a header and then empty blocks to all extents and volumes */
    /* rc=4 is end of track, rc=8 is end of extent, rc=12 is write error, no more tracks (SB37) */
    for(block=0; rc < 12 && block < blocks; block++) {
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
