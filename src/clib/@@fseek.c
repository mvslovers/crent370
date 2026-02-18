/* @@FSEEK.C - caller should hold lock on file handle */
#include <stdio.h>

int
__fseek(FILE *fp, long int offset, int whence)
{
    long oldpos;
    long newpos;
    char fnm[FILENAME_MAX];
    long int x;
    size_t y;
    char buf[1000];

    /* *any* seek will clear the error and eof indicators */
    fp->flags   &= 0xFFFF - _FILE_FLAG_ERROR;
    fp->flags   &= 0xFFFF - _FILE_FLAG_EOF;

    /* get current offset in this stream */
    oldpos = fp->filepos;
    if (fp->flags & _FILE_FLAG_WRITE) {
        __fflush(fp);
    }

    if (whence == SEEK_SET) {
        newpos = offset;
    }
    else if (whence == SEEK_CUR) {
        newpos = oldpos + offset;
    }

    if (whence == SEEK_END) {
        /* read until end of file or error */
        while (__fread(buf, sizeof(buf), 1, fp) == 1) {
            /* do nothing */
        }
        goto quit;
    }

    /* if we're in read mode */
    if (fp->flags & _FILE_FLAG_READ) {
        if (fp->flags & _FILE_FLAG_RECORD) {
            /* record mode, newpos is desired record number */
            if (newpos == fp->filepos) {
                fp->upto = fp->buf;
                goto quit;
            }
        }
        else {
            /* calculate RBA for start and end of buffer */
            long start = oldpos - (fp->upto - fp->buf);
            long end   = oldpos + (fp->endbuf - fp->upto);

            /* is newpos within the current buffer? */
            if ((newpos >= start) && (newpos < end)) {
                /* yes, reposition and we're done */
                fp->upto = fp->buf + (size_t)(newpos - oldpos);
                goto quit;
            }
        }
    }

    if (newpos < oldpos) {
        /* we need to reopen the file */
        if (fp->member[0] > ' ') {
            sprintf(fnm, "dd:%s(%s)", fp->ddname, fp->member);
        }
        else {
            sprintf(fnm, "dd:%s", fp->ddname);
        }
        if (__reopen(fnm, fp->mode, fp) == NULL) goto quit;
        oldpos = 0;
    }

    if (fp->flags & _FILE_FLAG_RECORD) {
        /* record mode, newpos is desired record number */
        for(x=oldpos; x < newpos; x++) {
            __fread(buf, sizeof(buf), 1, fp);
        }
        goto quit;
    }
    else {
        /* byte stream mode, newpos is desired byte offset in file */
        int c;
        for(x=oldpos; x < newpos; x++) {
            c = __fgetc(fp);
            if (c==EOF) {
                fp->flags |= (_FILE_FLAG_ERROR + _FILE_FLAG_EOF);
                goto quit;
            }
        }
    }

quit:
    if (fp->flags & _FILE_FLAG_ERROR) {
        /* well that's not good, something went wrong */
        return (-1);
    }

    /* success */
    fp->ungetch = -1;   /* discard the unget character  */
    return (0);
}
