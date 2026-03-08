#include "emfilei.h"

char *emfile_gets(char *str, int size, EMFILE *f)
{
	int			rc;
	
	// wtof("%s: enter", __func__);

	if (!str) goto quit;

	/* the size of the str needs to be at least 2 bytes */
	if (size <= 1) {
		*str = 0;
		str = NULL;
		goto quit;
	}

	rc = emfile_read_bytes(f, str, size-1, "\n");
	str[size-1] = 0;

	if (rc <= 0) str = NULL;

#if 0 /* debug stuff */
	if (str) {
		wtodumpf(str, strlen(str), "%s: str", __func__);
	}
#endif

quit:
	// wtof("%s: exit str=0x%08X", __func__, str);
	return str;
}
