#include "emfilei.h"

int main(int argc, char **argv)
{
	int		rc		= 0;
	EMFILE 	*f		= NULL;
	int		i;
	char	*buf	= NULL;
	char	*p;
	int		c;
	long	offset;

	wtof("%s: enter", __func__);

	rc = emfile_set_config(EMFILE_SPACE_CYL, 0, 1, 2, "TSO001,TSO002");
	if (rc) goto quit;

#define TESTFILE	"MDR.CRENT370.EMFILE.TEST"

	f = emfile_open(TESTFILE, "w+") ;
	wtof("%s: emfile_open(\"%s\",\"%s\") f=0x%08X",
		__func__, TESTFILE, "w+", f);

#if 0
	if (!f) {
		f = emfile_create(TESTFILE);
		wtof("%s: emfile_create(\"%s\") f=0x%08X",
			__func__, TESTFILE, f);
	}
#endif

	if (!f) {
		rc = errno;
		goto quit;
	}

	// wtodumpf(f, sizeof(EMFILE), "%s: EMFILE", __func__);
	emfile_dump(f);

	buf = calloc(1, 4096+1);
	if (!buf) {
		rc = 12;
		goto quit;
	}
	
	for(i=0; i < 256; i++) {
		memset(buf, i, 4096);
		rc = emfile_write_bytes(f, buf, 4096);
		wtof("%s: emfile_write_bytes(4096) rc=%d", __func__, rc);
		if (rc) goto quit;
	}

	emfile_dump(f);

	offset = emfile_tell(f);
	wtof("%s: offset=%d", __func__, offset);
	
	for(i=0; i < 256; i++) {
		rc = emfile_printf(f, "This is a test\nThis is also a test\nMe too \"%s\"\n", "arg1");
		if (rc < 0) goto quit;
	}

	emfile_dump(f);

	rc = emfile_seek(f, offset + 100, SEEK_SET);
	wtof("%s: emfile_seek(%d, SEEK_SET) rc=%d", __func__, offset+100, rc);
	if (rc) goto quit;

	offset = emfile_tell(f);
	wtof("%s: offset=%d", __func__, offset);

	rc = emfile_truncate(f, offset);
	wtof("%s: emfile_truncate() rc=%d", __func__, rc);
	emfile_dump(f);
	
	rc = emfile_seek(f, offset - 100, SEEK_SET);
#if 0
	while(p=emfile_gets(buf, 256, f)) {
		if (*p) wtodumpf(p, strlen(p), "%s: emfile_gets(256)", __func__);
	}
#endif

#if 0
	while((c=emfile_getc(f)) != EOF) {
		wtodumpf(&c, sizeof(c), "%s: emfile_getc()", __func__);
	}
#endif

quit:
	wtof("%s: quit", __func__);
	if (buf) free(buf);
	if (f) {
		emfile_dump(f);
		emfile_close(f);
	}

	wtof("%s: exit rc=%d", __func__, rc);
	return rc;
}
