#include "emfilei.h"

int emfile_printf(EMFILE *f, const char *format, ...) 
{
	int		rc;
	va_list args;

	// wtof("%s: enter format=\"%s\"", __func__, format);

	va_start(args, format);
	rc = emfile_vprintf(f, format, args);
	va_end(args);

	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
