#include "emfilei.h"

int emfile_vprintf(EMFILE *f, const char *format, va_list arg)
{
	int		rc;
	int		len;
	char 	buf[8192];

	// wtof("%s: enter format=\"%s\"", __func__, format);

	if (!f) {
		errno = EBADF;
		if (!f->error) f->error = EBADF;
		rc = -1;
		goto quit;
	}

    len = vsnprintf(buf, sizeof(buf), format, arg);
    if (len > sizeof(buf)) len = sizeof(buf);

    rc = emfile_write_bytes(f, buf, len);
    if (rc) {
		if (!f->error) f->error = rc;
		rc = -1;
	}
	else {
		rc = len;
	}

quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
