/* @@FPMODE.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int
__fpmode(FILE *fp, const char *mode)
{
    int     err     = 1;
    int     i;
    int     j;

    /* mode="(r|w)[b][+][,][record]" */
    /* no support for READ+WRITE, so error in that case */
    memset(fp->mode, 0, sizeof(fp->mode));
    for(i=0;i < sizeof(fp->mode) && *mode; i++, mode++) {
        fp->mode[i] = tolower(*mode);
        switch (fp->mode[i]) {
        case 'a':
            if (fp->flags & _FILE_FLAG_READ) goto quit;
            fp->flags |= _FILE_FLAG_WRITE;
            fp->flags |= _FILE_FLAG_APPEND;
            break;
        case 'b':
            fp->flags |= _FILE_FLAG_BINARY;
            break;
        case 'r':
            if (fp->flags & _FILE_FLAG_WRITE) goto quit;
            if (fp->flags & _FILE_FLAG_APPEND) goto quit;
            fp->flags |= _FILE_FLAG_READ;
            break;
        case 'w':
            if (fp->flags & _FILE_FLAG_READ) goto quit;
            fp->flags |= _FILE_FLAG_WRITE;
            break;
        case '+':
            goto quit;
        case ',':
            /* copy remaining mode string to file handle mode */
            for(j=i; j < sizeof(fp->mode) && *mode; j++) {
                fp->mode[j] = tolower(*mode++);
            }
            if (strstr(&fp->mode[i],"record")) {
                /* wtof("__fpmode found record"); */
                fp->flags |= _FILE_FLAG_RECORD;
            }
            if (strstr(&fp->mode[i],"bsam")) {
                /* wtof("__fpmode found bsam"); */
                fp->flags |= _FILE_FLAG_BSAM;
            }
            goto check;
        }
    }

check:
    if ((fp->flags & _FILE_FLAG_READ) || (fp->flags & _FILE_FLAG_WRITE)) {
        /* success */
        err = 0;
    }

quit:
    return err;
}
