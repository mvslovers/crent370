#include "emfilei.h"

int emfile_create_header(char *buf, __64 size)
{
	int			rc		= 0;
	EMFILE10	*hdr	= (EMFILE10 *)buf;

	// wtof("%s: enter buf=0x%08X, size=%llu", __func__, buf, size);

	// wtodumpf(hdr, sizeof(EMFILE10), "%s HDR Before", __func__);

	/* update header record */
	if (!hdr->eye[0]) strcpy(hdr->eye, EMFILEEYE10);
	hdr->modified = time64(NULL);
	if (__64_is_zero(&hdr->create)) {
		hdr->create = hdr->modified;
	}
	hdr->size = size;

	// wtodumpf(hdr, sizeof(EMFILE10), "%s HDR After", __func__);

	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
