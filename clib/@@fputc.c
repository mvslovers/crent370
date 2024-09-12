/* @@FPUTC.C - caller should hold lock on file handle */
#include <stdio.h>

int
__fputc(int c, FILE *fp)
{
    int     rc      = c;

    if (!(fp->flags & _FILE_FLAG_WRITE)) goto quit; /* not in WRITE mode */
    if (fp->flags & _FILE_FLAG_RECORD) goto quit;   /* in record mode    */

    /* is this a text file? */
    if (!(fp->flags & _FILE_FLAG_BINARY)) {
        /* yes, is this character a newline? */
        if (c == '\n') {
            /* yes, flush buffer to disk */
            fp->filepos++;
            if (__fflush(fp)) rc = EOF;
            goto quit;
        }
    }

    /* if buffer is full flush buffer to disk */
    if (fp->upto == fp->endbuf) {
        if (__fflush(fp)) {
            rc = EOF;
            goto quit;
        }
    }

    /* otherwise we copy the character to the buffer */
    *fp->upto++ = (unsigned char)c;
    fp->filepos++;

quit:
    return rc;
}
