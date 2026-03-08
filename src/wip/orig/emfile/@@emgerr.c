#include "emfilei.h"

int emfile_get_error(EMFILE *f)
{
	int		last_error	= 0;
	
	wtof("%s: enter", __func__);
	
	if (f) {
		last_error	= f->error;
		f->error	= 0;
	}
	
	wtof("%s: exit error=%d", __func__, last_error);
	return last_error;
}
