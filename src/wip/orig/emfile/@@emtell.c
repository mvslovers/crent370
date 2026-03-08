#include "emfilei.h"

long emfile_tell(EMFILE *f)
{
	long	offset = 0;
	
	// wtof("%s: enter", __func__);
	
	if (f) {
		if (f->offset.u32[0] || f->offset.u32[1] > 0x7FFFFFFF) {
			offset = (long)-1;
			errno = EOVERFLOW;
		}
		else {
			offset = (long)f->offset.u32[1];
		}
	}
	else {
		offset = (long)-1;
		errno = EBADF;
	}
	
	// wtof("%s: exit offset=%u", __func__, offset);
	return offset;
}
