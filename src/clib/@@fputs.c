/* @@FPUTS.C - caller should hold lock on file handle */
#include <stdio.h>

int
__fputs(const char *s, FILE *fp)
{
    int             i;

    if (fp->flags & _FILE_FLAG_RECORD) {
        /* not allowed in record mode */
        i = EOF;
        goto quit;
    }

    for(i=0; s[i]; i++) {
        if (__fputc(s[i],fp)==EOF) {
            i = EOF;
            break;
        }
    }

quit:
    return i;
}
