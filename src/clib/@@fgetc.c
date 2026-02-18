/* @@FGETC.C - caller should already have lock on file handle */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mvssupa.h>
#include <osdcb.h>
#include <osdecb.h>

static unsigned char *tso_getline(unsigned char *buf, size_t len);

int
__fgetc(FILE *fp)
{
	DCB				*dcb = fp->dcb;
    int             c   = EOF;
    size_t          lenread;
    size_t          read;
    unsigned char   *dptr;

    if (fp->flags & (_FILE_FLAG_EOF |_FILE_FLAG_RECORD)) goto quit;

    if (fp->ungetch != -1) {
        c = (int)fp->ungetch;
        fp->ungetch = -1;
        goto quit;
    }

    if (fp->upto < fp->endbuf) goto dogetc;

	/* This is new code to support TSO terminals */
	if (dcb->dcbdevt == DCBDVTRM) {
		dptr = tso_getline(fp->asmbuf, fp->lrecl-1);
		
		read = strlen(dptr);
		// wtof("%s: dptr=\"%s\"", __func__, dptr);
		/* on "normal" terminals and end user could hit control-d
		 * character to indicate EOF. TSO has no such method
		 * so we'll look for a "magic" sequence to emulate EOF.
		 */
		if (strcmp(dptr, "/*")==0) goto quit;
		if (strcmp(dptr, "//")==0) goto quit;
		if (strcmp(dptr, "<eof>")==0) goto quit;
		if (strcmp(dptr, "<EOF>")==0) goto quit;
		goto success;
	}

	do {
		/* read one record from dataset */
		if (__aread(fp->dcb, &dptr, &lenread) != 0) {
			/* end of file */
			fp->flags |= _FILE_FLAG_EOF;
			goto quit;
		}

		switch (fp->recfm & _FILE_RECFM_TYPE) {
		case _FILE_RECFM_F:
			read = fp->lrecl;
			break;
		case _FILE_RECFM_V:
			read = (dptr[0] << 8) | dptr[1];
			dptr += 4;  /* skip over RDW */
			read -= 4;  /* adjust for size of RDW */
			break;
		case _FILE_RECFM_U:
			read = lenread;
			break;
		default:
			/* should never happen! */
			fp->flags |= _FILE_FLAG_EOF;
			goto quit;
		}
	} while (read < 0);

success:
    /* successful read of dataset */
    if (read > 0) {
        if (!(fp->flags & _FILE_FLAG_BINARY)) {
            /* get rid of any trailing NULs in text mode */
            unsigned char *p = memchr(dptr, '\0', read);

            if (p) {
                read = p - dptr;
            }
        }

        /* copy to buffer */
        memcpy(fp->buf, dptr, read);
    }

    fp->upto   = fp->buf;
    fp->endbuf = fp->buf + read;

    /* dataset records do not have newline record delititers
    ** so we need to add a newline for text streams.
    */
    if (!(fp->flags & _FILE_FLAG_BINARY)) {
        /* add newline to text stream */
        *fp->endbuf++ = '\n';
    }

dogetc:
    /* return character from file handle buffer */
    c = (int)*fp->upto++;

    /* increment our relative file position */
    fp->filepos++;

quit:
    return c;
}

static unsigned char *
tso_getline(unsigned char *buf, size_t len)
{
	unsigned	r0 = 0;
	unsigned	r1 = 0;

	if (!buf) goto quit;
	if (!len) goto quit;

#define TGET_WAIT		0x80
#define TGET_NOWAIT		0x90
#define TGET_ASIS		0x01
#define TGET_EDIT		0x00

	r0 = len;
	r1 = (TGET_WAIT | TGET_EDIT) << 24 | (unsigned)buf & 0x00FFFFFF;

	__asm__(
		"LR\t0,%0                buffer length\n\t"
		"LR\t1,%1                flags and buffer address\n\t"
		"TGET\t(1),(0),R" : : "r"(r0), "r"(r1) );

	buf[len-1] = 0;
	// wtodumpf(buf, len, "%s: buf 1", __func__);
	
	/* since TSO has an unformatted screen area
	 * a user can type anyplace and cause a huge amount of
	 * leading spaces before the text they entered.
	 * so the goal here is to remove that leading space
	 * from the input.
	 */
	for(len=0; (isspace(buf[len])); len++);
	strcpy(buf, &buf[len]);
	
	/* remove trailing spaces */
	len = strlen(buf);
	// wtodumpf(buf, len+1, "%s: buf 2", __func__);
	while( len > 0 ) {
		len--;

		if (!isspace(buf[len])) break;

		buf[len] = 0;
	}

	// wtodumpf(buf, len+1, "%s: buf 3", __func__);

quit:
	return buf;
}
