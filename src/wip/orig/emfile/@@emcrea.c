#include "emfilei.h"

EMFILE *emfile_create(const char *dsn)
{
	int		rc;
	EMFILE 	*f		= NULL;
	char 	flag	= EMFILE_FLAG_UPDATE;
	char	c;

	wtof("%s: enter dsn=\"%s\"", __func__, dsn);

	if (!dsn) {
		wtof("%s: dsn=NULL", __func__);
		errno = EINVAL;
		goto failed;
	}

	/* allocate a 'file' handle */
	f = calloc(1, sizeof(EMFILE));
	if (!f) {
		wtof("%s: emfile handle no memory", __func__);
		errno = ENOMEM;
		goto quit;
	}
	strcpy(f->eye, EMFILE_EYE);
	f->flags = flag;

	if (toupper(dsn[0])=='D' && toupper(dsn[1])=='D' && dsn[2]==':') {
		/* copy the ddname into our handle */
		// wtof("%s: dsn is dd name", __func__);
		emfile_set_ddn(&dsn[3], f->ddname);
	}
	else {
		/* copy the dataset name into our handle */
		// wtof("%s: dsn is dsn", __func__);
		emfile_set_dsn(dsn, f->dsname);

		/* DISP=NEW */
		rc = emfile_allocate_new(f);
		// wtof("%s: emfile_allocate_new() rc=%d", __func__, rc);
		if (rc) goto failed;
	}

	f->flags |= flag;

	/* perform common setup of emulated 'file' */
	rc = emfile_setup(f);
	// wtof("%s: emfile_setup() rc=%d", __func__, rc);
	if (rc==0) goto quit;

failed:
	if (f) {
		emfile_close(f);
		f = NULL;
	}

quit:
	wtof("%s: exit emfile=0x%08X", __func__, f);
	return f;
}
