/* @@FWRITE.C - caller should hold lock on file handle */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mvssupa.h>

#define begwrite(fp, len)   (lenwrite = (len), dptr = (fp)->asmbuf)
#define finwrite(fp)        (__awrite((fp)->dcb, &dptr, &lenwrite))

size_t
__fwrite(const void *vptr, size_t size, size_t nmemb, FILE *fp)
{
    unsigned char   *ptr    = (unsigned char *)vptr;
    size_t          i       = 0;
    size_t          j;
    unsigned char   *dptr;
    size_t          lenwrite;

    if (fp->flags & _FILE_FLAG_RECORD) {
        /* use record oriented i/o */
        size *= nmemb;
        begwrite(fp, size);
        memcpy(dptr, ptr, size);
        if (finwrite(fp)) goto quit;
        fp->filepos += 1;       /* count record written */
        i = 1;
        goto quit;
    }

    /* slower but accurate implementation */
    for(i=0; i < nmemb; i++) {
        for(j=0; j < size; j++) {
            if (__fputc(*ptr++, fp)==EOF) {
                goto quit;
            }
        }
    }

quit:
    return i;
}
