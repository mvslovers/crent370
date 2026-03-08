#include "emfilei.h"

int emfile_puts(const char *str, EMFILE *f)
{
	int			rc		= 0;
	int			len;

	wtof("%s: enter str=\"%s\"", __func__, str);
	
	len = strlen(str);
	if (len) {
		rc = emfile_write_bytes(f, str, len);
		if (rc) {
			if (!f->error) f->error = rc;
			rc = -1;
		}
	}

quit:
	wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
