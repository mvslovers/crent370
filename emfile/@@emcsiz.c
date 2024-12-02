#include "emfilei.h"

int emfile_calc_size(EMFILE *f)
{
	int			rc;
	DSCB 		dscb	= {0};
	DSCB1		*dscb1 	= &dscb.dscb1;
	int			i;
	DVATAB		dvatab 	= {0};
	unsigned	count;
	unsigned	n;
	unsigned	tracks;
	unsigned	blocks;

	// wtof("%s: enter", __func__);
	
	f->tracks = 0;
	f->blocks = 0;
	f->blkstrk = 0;

	count = array_count(&f->volser);
	for(n=1; n <= count; n++) {
		char	*volser = array_get(&f->volser, n);
		
		if (!volser) continue;

		/* get the DSCB for this dataset + volser */
		rc = __dscbdv(f->dsname, volser, &dscb);
		if (rc) {
			/* if we've already read the first DSCB we likely have 
			 * an uninitialized multi volume dataset so we continue.
			 */
			if (n > 1) {
				rc = 0;
				continue;
			}
			
			wtof("%s: Unable to read DSCB for \"%s\" volser=\"%s\" rc=%d", 
				__func__, f->dsname, volser, rc);
			goto quit;
		}

		if (!f->blksize) f->blksize = dscb1->blksz;

		if (!f->blkstrk) {
			/* get the device type information for the DDNAME */
			__asm__("LR\t0,%0        Output area\n\t"
					"LCR\t0,0        DEVTAB desired\n\t"
					"LR\t1,%1        DD name\n\t"
					"SVC\t24         DEVTYPE" 
					: 
					: "r"(&dvatab), "r"(f->ddname) );
			f->devtype = dvatab.dvaunit;
	
			/* get the number of blocks per track for this device type */
			f->blkstrk = trkcalc((DEVTYPE)f->devtype, 0, (int)f->blksize);
		}
	
		/* calculate size of dataset */
		/* tracks is relative to 0 in lstar */
		tracks = (dscb1->lstar[0] << 8 | dscb1->lstar[1]);
		f->tracks += tracks;

		/* calculate allocated blocks */
		blocks 		 = dscb1->lstar[2];
		blocks		+= (tracks * f->blkstrk);
		f->blocks 	+= blocks;

		/* make tracks relative to 1 */
		f->tracks++;
	}

	/* calculate allocated bytes for 'file' use */
	/* we check for > 1 because the first block is reserved for the header */
	if (f->blocks > 1) {
		/* calc allocated bytes for file (capacity) */
		__64_from_u32(&f->alloc, f->blksize);
		__64_mul_u32(&f->alloc, f->blocks-1, &f->alloc);
	}
	else {
		/* clear the allocated bytes for file */
		__64_from_u32(&f->alloc, 0);
	}

quit:	
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
