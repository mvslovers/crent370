#include "emfilei.h"

int emfile_set_volser(EMFILE *f, JFCB *jfcb)
{
	int			rc = 0;
	int			i;
	unsigned 	count;
	unsigned	n;
	unsigned	maxvol = sizeof(jfcb->jfcbvols) / 6;

	if (f->volser) {
		count = array_count(&f->volser);
		for(n=count; n > 0; n--) {
			char *vol = array_del(&f, n);
			if (!vol) continue;
			free(vol);
		}
		array_free(&f->volser);
	}
	
	if (jfcb->jfcbnvol < maxvol) maxvol = jfcb->jfcbnvol;

	for(n=0; n < maxvol; n++) {
		char 	*volser = &jfcb->jfcbvols[n*6];
		char	*dest   = calloc(1, 8);

		if (!dest) {
			rc = ENOSPC;
			goto quit;
		}
	
		for(i=0; (i < 6) && (volser[i]); i++) {
			dest[i] = toupper(volser[i]);
		}
		dest[i] = 0;
		
		rc = array_add(&f->volser, dest);
		if (rc) {
			rc = ENOSPC;
			goto quit;
		}
	}

quit:	
	return rc;
}
