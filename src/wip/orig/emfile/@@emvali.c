#include "emfilei.h"

/* emfile_validate() - validate the header (r0) values */
int emfile_validate(EMFILE *f)
{
	int			rc;
	EMFILE10	*hdr	= (EMFILE10 *)f->r0;

	// wtof("%s: enter hdr=0x%08X", __func__, hdr);

	if (!hdr) goto failed;

	// wtodumpf(hdr, sizeof(EMFILE10), "%s EMFILE10", __func__);

	/* eye catcher should be "EMFILE MVS" */
	if (memcmp(hdr->eye, EMFILEMVS, strlen(EMFILEMVS))!=0) goto failed;
	// wtof("%s: hdr->eye OKAY", __func__);
	
	/* the create date should not be zero */
	if (__64_is_zero(&hdr->create)) goto failed;
	// wtof("%s: hdr->create OKAY", __func__);
	
	/* the modified date should not be zero */
	if (__64_is_zero(&hdr->modified)) goto failed;
	// wtof("%s: hdr->modified OKAY", __func__);
	
	/* the create date should not be greater than the modified date */
	if (__64_cmp(&hdr->create, &hdr->modified) == __64_LARGER) goto failed;
	// wtof("%s: hdr->create <= hdr->modified OKAY", __func__);

#if 0	/* not really needed here as this should have been detected long ago */
	if (f->bdamdcb) {
		/* block size should be a multiple of 512 bytes */
		if (f->bdamdcb->dcbblksi & 0x1ff) goto failed;
		/* lrecl should be same as block size */
		if (f->bdamdcb->dcblrecl != f->bdamdcb->dcbblksi) goto failed;
		/* record format should be fixed */
		if ((f->bdamdcb->dcbrecfm & DCBRECU) != DCBRECF) goto failed;
	}
#endif

	rc = 0;
	goto quit;

failed:
	rc = EINVAL;
	errno = EINVAL;
	wtof("%s: dsn=\"%s\" failed validation check", __func__, f->dsname);

quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
