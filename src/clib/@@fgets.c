/* @@FGETS.C */
#include <stdio.h>
#include <mvssupa.h>

char *
__fgets(char *s, int n, FILE *fp)
{
    int             cnt;
    int             c;

    if (fp->flags & (_FILE_FLAG_EOF | _FILE_FLAG_RECORD)) {
        s = (char *)0;
        goto quit;
    }

    for(n--, cnt = 0; cnt < n; ) {
        c = __fgetc(fp);
        if (c == EOF) break;
        s[cnt++] = c;
        if (c == '\n') break;
    }

    if ((cnt == 0) && (c == EOF)) {
        /* end of file */
        s = (char*)0;
        goto quit;
    }

    s[cnt] = '\0';

quit:
    return s;
}
