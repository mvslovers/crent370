#include "emfilei.h"

int emfile_setup(EMFILE *f)
{
	EMFILEWSA 	*wsa 	= emfile_get_wsa();
	int			rc;
	JFCB 		jfcb 	= {0};

	/* common setup for emfile_open() and emfile_create() */
	// wtof("%s: enter", __func__);
	
	f->bdamdecb = calloc(1, sizeof(DECB));
	if (!f->bdamdecb) {
		wtof("%s: bdamdecb no memory", __func__);
		rc = ENOMEM;
		goto failed;
	}
	
    /* allocate a BDAM DCB */
    f->bdamdcb = osddcb(f->ddname);
    if (!f->bdamdcb) {
		wtof("%s: no memory", __func__);
		rc = ENOMEM;
        goto failed;
    }

    /* get the dataset name from the Job File Control Block */
    rc = rdjfcb(f->bdamdcb, &jfcb);
    if (rc) {
		wtof("%s: rdjfcb() failed rc=%d", __func__, rc);
		rc = EACCES;
		goto failed;
	}
	wtodumpf(&jfcb, sizeof(JFCB), "%s: new code JFCB", __func__);

	emfile_set_dsn(jfcb.jfcbdsnm, f->dsname);

	emfile_set_volser(f, &jfcb);

	f->blksize = jfcb.jfcblksi;
	wtof("%s: jfcb.jfcblksi=%u", __func__, jfcb.jfcblksi);

	/* calculate size of dataset */
	rc = emfile_calc_size(f);
	// wtof("%s: emfile_calc_size() rc=%d", __func__, rc);
	if (rc) goto failed;

	wtof("%s: f->blksize=%u", __func__, f->blksize);

    f->buf = calloc(1, f->blksize);
    if (!f->buf) {
		wtof("%s: f->buf no memory", __func__);
		rc = ENOMEM;
		goto failed;
	}

	/* allocate buffer for header record */
	f->r0 = calloc(1, sizeof(EMFILE10));
	if (!f->r0) {
		wtof("%s: f->r0 no memory", __func__);
		rc = ENOMEM;
		goto failed;
	}

	/* check for empty dataset */
	wtof("%s: f->blocks=%u", __func__, f->blocks);

	/* check for empty dataset */
	// wtof("%s: f->blocks=%u", __func__, f->blocks);
	if (f->blocks) goto open;

	/* dataset is empty */
	if (!(f->flags & EMFILE_FLAG_WRITE)) goto failed;

	/* dataset is empty and in WRITE/UPDATE mode */
	f->flags |= EMFILE_FLAG_NEW;	/* a fresh virgin 'file' */

	/* initialize dataset as emulated file */
	if (jfcb.jfcbnvol > 1) {
		/* multi volume dataset, initialize all extents on all volumes */
		f->flags |= EMFILE_FLAG_MULTIV;
		rc = emfile_full_init(f->ddname, f->blksize, &jfcb);
		// wtof("%s: emfile_full_init(\"%s\",%u) rc=%d", 
		// 	__func__, f->ddname, f->blksize, rc);
		if (rc) goto failed;

		/* full init was performed */
		f->flags |= EMFILE_FLAG_FULL;	
	}
	else {
		rc = emfile_init(f->ddname, f->blksize, &jfcb);
		// wtof("%s: emfile_init(\"%s\",%u) rc=%d", 
		// 	__func__, f->ddname, f->blksize, rc);
		if (rc) goto failed;

		/* partial init was performed */
		f->flags |= EMFILE_FLAG_GROW;
	}

	/* calculate space used */
	rc = emfile_calc_size(f);
	// wtof("%s: emfile_calc_size() rc=%d", __func__, rc);
	if (rc) goto failed;

open:
    /* open the BDAM dataset */
    rc = osdopen(f->bdamdcb, 0);
    if (rc) {
		wtof("%s: osdopen() failed rc=%d", __func__, rc);
		rc = EACCES;
        goto failed;
    }

	// wtodumpf(f->bdamdcb, sizeof(DCB), "%s: BDAMDCB", __func__);

validate:
	emfile_dump(f);

	/* read the header */
	rc = emfile_read_header(f);
	if (rc) goto failed;

	/* validate header from block 0 */
	rc = emfile_validate(f);
	// wtof("%s: emfile_validate() rc=%d", __func__, rc);
	if (rc==0) goto quit;	/* success */

failed:
	// wtof("%s: failed", __func__);
	f->error = rc;
	errno = rc;

quit:
	// wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
