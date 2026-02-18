/* @@FFLUSH.C - caller should already hold lock on file handle */
#include <stdio.h>
#include <string.h>
#include <mvssupa.h>
#include <osdcb.h>
#include <osdecb.h>

#define begwrite(fp, len)   (lenwrite = (len), dptr = (fp)->asmbuf)
#define finwrite(fp)        (__awrite((fp)->dcb, &dptr, &lenwrite))

static int fixflush(FILE *fp, int fill);
static int varflush(FILE *fp);
static int tso_putline(char *buf, unsigned len);

int
__fflush(FILE *fp)
{
	DCB				*dcb 	= fp->dcb;
    int             err     = 0;
    unsigned char   *dptr;
    size_t          lenwrite;
    int             fill;

    if (fp->flags & _FILE_FLAG_RECORD)   goto quit; /* not using buffer  */
    if (!(fp->flags & _FILE_FLAG_WRITE)) goto quit; /* not in WRITE mode */
    if (fp->upto == fp->buf) goto quit;             /* empty buffer      */

	/* This is new code to support TSO terminals */
	if (dcb->dcbdevt == DCBDVTRM) {
		/* DCB refers to terminal */
		DECB	decb = {0};
		size_t  len;

		/* calculate length of data in buffer */
		len = fp->upto - fp->buf;

		err = tso_putline(fp->buf, len);
		goto reset;
	}


    switch(fp->recfm & _FILE_RECFM_TYPE) {
    case _FILE_RECFM_F: /* RECFM=F..    */
    case _FILE_RECFM_U: /* RECFM=U      */
        if (fp->flags & _FILE_FLAG_BINARY) {
            fill = 0;
        }
        else {
            fill = ' ';
        }
        err = fixflush(fp, fill);
        break;
    case _FILE_RECFM_V: /* RECFM=V..    */
        err = varflush(fp);
        break;
    }

reset:
    /* reset buffer */
    fp->upto = fp->buf;
    fp->filepos = 0;

quit:
    return err;
}

__asm__("\n&FUNC    SETC 'fixflush'");
static int
fixflush(FILE *fp, int fill)
{
    int             err     = 0;
    unsigned char   *dptr;
    size_t          lenwrite;
    size_t          len;

    /* calculate length of data in buffer */
    len = fp->upto - fp->buf;

    /* fill and copy data to internal buffer */
    if ((fp->recfm & _FILE_RECFM_TYPE)==_FILE_RECFM_U) {
        /* RECFM=U, no fill, just copy */
        begwrite(fp, len);
        memcpy(dptr, fp->buf, len);
    }
    else {
        /* RECFM=F, fill and copy */
        begwrite(fp, fp->lrecl);
        memset(dptr, fill, fp->lrecl);
        memcpy(dptr, fp->buf, len);
        len = fp->lrecl;
    }

    /* write buffer to disk */
    err = finwrite(fp);

quit:
    return err;
}

__asm__("\n&FUNC    SETC 'varflush'");
static int
varflush(FILE *fp)
{
    int             err     = 0;
    unsigned char   *dptr;
    size_t          lenwrite;
    size_t          len;
    size_t          rdwlen;

    /* calculate length of data in buffer */
    len = fp->upto - fp->buf;

	rdwlen = len+4;
	begwrite(fp, rdwlen);
	/* copy data to internal buffer */
	memcpy(dptr+4, fp->buf, len);

	/* calculate the RDW */
	dptr[0] = (unsigned char) (rdwlen >> 8);
	dptr[1] = (unsigned char) (rdwlen & 0xFF);
	dptr[2] = 0;
	dptr[3] = 0;

	/* write buffer to disk */
	err = finwrite(fp);

    // wtof("@@fflush:%s: dptr=0x%08X lenwrite=%u err=%d", __func__, dptr, lenwrite, err);
    // wtodumpf(dptr, lenwrite, "dptr");

quit:
    return err;
}

static int
tso_putline(char *buf, unsigned len)
{
	unsigned	r0 = 0;
	unsigned	r1 = 0;

	// wtof("%s: enter", __func__);
	if (!len) goto quit;
	
	// wtodumpf(buf, len, "@@fflush.c:%s: buf", __func__);
	
#define TPUT_WAIT		0x00
#define TPUT_NOWAIT		0x10
#define TPUT_HOLD		0x08
#define TPUT_BREAKIN	0x04
#define TPUT_CONTROL	0x02
#define TPUT_ASIS		0x01
#define TPUT_EDIT		0x00
#define TPUT_FULLSCR	(TPUT_CONTROL|TPUT_ASIS)

	r0 = len & 0xFFFF;
	r1 = (TPUT_WAIT | TPUT_HOLD) << 24 | (unsigned) buf & 0x00FFFFFF;

	__asm__(
		"LR\t0,%0                buffer length\n\t"
		"LR\t1,%1                flags and buffer address\n\t"
		"TPUT\t(1),(0),R" : : "r"(r0), "r"(r1) );

quit:
	// wtof("%s: exit rc=%d", __func__, 0);
	return 0;
}
