#include "emfilei.h"

int emfile_set_config(	/* ... 						(default value)	*/
	EMFILE_SPACE space,	/* EMFILE_SPACE_ TRACK or CYL		(track)	*/
	unsigned blksize, 	/* block size 						(4096)	*/
	unsigned primary, 	/* primary tracks or cylinders		(15)	*/
	unsigned secondary,	/* secondary tracks or cylinders	(15)	*/
	const char *vols)	/* volume serial names				(none)	*/
{
	int			rc		= ENOSPC;
	EMFILEWSA	*wsa	= emfile_get_wsa();
	int			i;
	
	if (!wsa) goto quit;

	if (space == EMFILE_SPACE_TRACK) {
		wsa->space = EMFILE_SPACE_TRACK;
	}
	else {
		wsa->space = EMFILE_SPACE_CYL;
	}
	
	if (blksize) {
		wsa->blksize = blksize;
	}
	else {
		wsa->blksize = 4096;	/* default block size */
	}
	
	if (primary) {
		wsa->primary = primary;
	}
	else {
		wsa->primary = 15;		/* default primary space */
	}
	
	wsa->secondary = secondary;

	if (wsa->vols) {
		free(wsa->vols);
		wsa->vols = NULL;
	}

	if (vols) {
		wsa->vols = strdup(vols);
		if (!wsa->vols) {
			rc = ENOSPC;
			goto quit;
		}
		for(i=0; wsa->vols[i]; i++) {
			/* fold volser characters to upper case */
			wsa->vols[i] = toupper(wsa->vols[i]);
		}
	}

	rc = 0;
	
quit:	
	if (rc) errno = rc;
	return rc;
}
