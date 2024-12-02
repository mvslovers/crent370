#include "emfilei.h"

int emfile_offset_block_pos(EMFILE *f, unsigned *b, unsigned *p)
{
	int 		rc			= 0;
	__64 		block64;
	__64		pos64;
	
	// wtof("%s: enter offset=%llu", __func__, f->offset);
	
	/* calculate buffer position and block number */
	__64_divmod_u32(&f->offset, f->blksize, &block64, &pos64); 

	/* adjust block calculations up by 1 block */
	__64_add_u32(&block64, 1, &block64);

	rc = block64.u32[0]; /* !=0 overflow occured */

	if (b) *b = block64.u32[1];
	if (p) *p = pos64.u32[1];
	
quit:
	// wtof("%s: exit block=%u pos=%u%s", 
	// 	__func__, block64.u32[1], pos64.u32[1], rc ? " OVERFLOW" : "");
	return rc;
}
