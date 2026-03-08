#include "emfilei.h"

int emfile_putc(int c, EMFILE *f)
{
	int			rc		= 0;
	char 		buf[2];
	
	wtof("%s: enter", __func__);

	if (!f) goto failed;
	
	if (!(f->flags & EMFILE_FLAG_WRITE)) goto failed;

	buf[0] = (char)c;
	buf[1] = 0;
	
	rc = emfile_write_bytes(f, buf, 1);
	if (rc) goto failed;

	rc = c;
	goto quit;
	
failed:
	rc = -1;

quit:
	wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
