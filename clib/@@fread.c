/* @@FREAD.C - caller should hold lock on file handle */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mvssupa.h>

size_t
__fread(void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    unsigned char   *p      = (unsigned char*)ptr;
    size_t          lenread = 0;
    size_t          i       = nmemb;
    size_t          j;
    int             c;
    unsigned char   *dptr;

    if (fp->flags & _FILE_FLAG_EOF) {
        i = 0;
        goto quit;
    }

    if (fp->flags & _FILE_FLAG_RECORD) {
        size *= nmemb;
        i = __aread(fp->dcb, &dptr, &lenread);
        if (i != 0) {
            /* read error or eof */
            fp->flags |= _FILE_FLAG_EOF;
            i = 0;
            goto quit;
        }
        /* success, return data */
        i = nmemb;
        if (size > lenread) size = lenread;
        memcpy(ptr, dptr, size);
        fp->filepos += 1;   /* count records read */
        goto quit;
    }

    /* slower but accurate implementation */
    for(i=0; i < nmemb; i++) {
        for(j=0; j < size; j++) {
            c = __fgetc(fp);
            if (c==EOF) goto quit;
            *p++ = (unsigned char)c;
        }
    }

quit:
    return i;
}
