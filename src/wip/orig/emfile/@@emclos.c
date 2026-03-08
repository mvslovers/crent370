#include "emfilei.h"

int emfile_close(EMFILE *f)
{
	int			rc		= 0;
	unsigned	count;
	unsigned	n;
	
	// wtof("%s: enter", __func__);
	
	if (!f) goto quit;
	if (memcmp(f->eye, EMFILE_EYE, strlen(EMFILE_EYE))!= 0) goto quit;

	if (f->growdd) {
		emfile_unallocate(f->growdd);
		free(f->growdd);
		f->growdd = NULL;
	}

	if (f->bdamdcb) {
		/* flush any pending output, sync header */
		rc = emfile_sync(f);

		osdclose(f->bdamdcb, 
			1);		/* free dcb			*/
		f->bdamdcb = NULL;
	}
	
	if (f->bdamdecb) {
		free(f->bdamdecb);
		f->bdamdcb = NULL;
	}

	if (f->buf) {
		free(f->buf);
		f->buf = NULL;
	}
	
	if (f->r0) {
		free(f->r0);
		f->r0 = NULL;
	}

	if (f->volser) {
		count = array_count(&f->volser);
		for(n=count; n > 0; n--) {
			char *vol = array_del(&f, n);
			if (!vol) continue;
			free(vol);
		}
		array_free(&f->volser);
	}

	memset(f->eye, 0, sizeof(f->eye));
	free(f);
		
quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
