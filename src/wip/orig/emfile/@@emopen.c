#include "emfilei.h"

static unsigned char parse_mode(const char *mode);

EMFILE *emfile_open(const char *dsn, const char *mode)
{
	int		rc;
	EMFILE 	*f		= NULL;
	char 	flag	= 0;
	char	c;

	wtof("%s: enter dsn=\"%s\"", __func__, dsn);

	if (!dsn) {
		errno = EINVAL;
		goto failed;
	}
	
	if (!mode) {
		errno = EINVAL;
		goto failed;
	}

	/* decode the mode string into flags */
	flag = parse_mode(mode);
	if (!flag) {
		errno = EINVAL;
		goto failed;
	}

	f = calloc(1, sizeof(EMFILE));
	if (!f) {
		errno = ENOMEM;
		goto quit;
	}
	strcpy(f->eye, EMFILE_EYE);
	f->flags = flag;

	if (toupper(dsn[0])=='D' && toupper(dsn[1])=='D' && dsn[2]==':') {
		/* copy the ddname into our handle */
		emfile_set_ddn(&dsn[3], f->ddname);
	}
	else {
		/* copy the dataset name into our handle */
		emfile_set_dsn(dsn, f->dsname);

		if (flag & EMFILE_FLAG_WRITE) {
			/* DISP=OLD for WRITE or UPDATE */
			rc = emfile_allocate_old(f);
		}
		else if (flag & EMFILE_FLAG_READ) {
			/* DISP=SHR okay for read only */
			rc = emfile_allocate_shr(f);
		}
		
		if (rc && (flag & EMFILE_FLAG_CREATE)) {
			/* DISP=NEW for CREATE */
			rc = emfile_allocate_new(f);
		}

		if (rc) goto failed;
	}

	/* perform common setup of emulated 'file' */
	rc = emfile_setup(f);
	if (rc) goto failed;
	
	if (flag & EMFILE_FLAG_APPEND) {
		/* APPEND (implies WRITE) */
		rc = emfile_seek(f, 0, SEEK_END);
		if (rc) goto failed;
	}
	else if ((flag & EMFILE_FLAG_WRITE) && !(flag & EMFILE_FLAG_READ)) {
		/* WRITE without READ == truncate */
		rc = emfile_truncate(f, 0);
		if (rc) goto failed;
	}
	goto quit;

failed:
	if (f) {
		emfile_close(f);
		f = NULL;
	}

quit:
	wtof("%s: exit emfile=0x%08X", __func__, f);
	return f;
}

static unsigned char parse_mode(const char *mode)
{
	unsigned char	flags	= 0;
	char 			c;
	
	// wtof("%s: enter", __func__);

	if (!mode) goto quit;
	
	c = tolower(*mode);
	if (c == 'r') {
		flags = EMFILE_FLAG_READ;
	}
	else if (c == 'w') {
		flags = EMFILE_FLAG_WRITE | EMFILE_FLAG_CREATE;
	}
	else if (c == 'a') {
		flags = EMFILE_FLAG_WRITE | EMFILE_FLAG_CREATE | EMFILE_FLAG_APPEND;
	}
	
	for(mode++; *mode; mode++) {
		c = tolower(*mode);
		
		if (c == '+') {
			flags |= EMFILE_FLAG_READ | EMFILE_FLAG_WRITE;
		}
		/* we ignore any other character in the mode string */
	}

quit:	
	// wtof("%s: exit flags=0x%02X", __func__, flags);
	return flags;
}
