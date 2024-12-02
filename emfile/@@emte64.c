#include "emfilei.h"

__64 emfile_tell64(EMFILE *f)
{
	__64	offset;
	
	if (f) {
		offset = f->offset;
	}
	else {
		offset.u32[0] = 0xFFFFFFFF;
		offset.u32[1] = 0xFFFFFFFF;
		errno = EBADF;
	}
	
	return offset;
}
