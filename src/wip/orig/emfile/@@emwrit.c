#include "emfilei.h"

size_t 
emfile_write(const void *ptr, size_t size, size_t nmemb, EMFILE *f)
{
	size_t		written		= 0;
	const char	*buf		= (const char*)ptr;
	unsigned	bytes;
	int			rc;
	
	wtof("%s: enter", __func__);

	if (!(f->flags & EMFILE_FLAG_WRITE)) goto quit;

	while(nmemb > 0) {
		rc = emfile_write_bytes(f, buf, size);
		if (rc) break;
		written++;
		buf += size;
		nmemb--;
	}

	if (rc) {
		f->error = errno;
		if (!f->error) f->error = rc;
	}
	
quit:
	wtof("%s: exit written=%u", __func__, written);
	return written;
}
