#include "emfilei.h"

int emfile_getc(EMFILE *f)
{
	int		rc;
	char	buf[4] = {0};
	
	// wtof("%s: enter", __func__);
	
	rc = emfile_read_bytes(f, buf, 1, NULL);
	// wtodumpf(buf, sizeof(buf), "%s: buf rc=%d", __func__, rc);
	if (rc==1) {
		/* success is we read 1 byte */
		rc = buf[0];
	}
	else {
		/* otherwise error */
		rc = EOF;
	}

	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
