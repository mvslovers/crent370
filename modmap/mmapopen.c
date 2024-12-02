#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_open'");
int
modmap_open(MODMAP *mm, const char *fn)
{
    int             rc      = 0;
    int             len;

    if (!mm) {
        rc = -1;
        goto quit;
    }

    /* reset module map handle */
    mmaprset(mm);

    len = strlen(fn);
    if (len >= sizeof(mm->fn)) len = sizeof(mm->fn)-1;
    memcpy(mm->fn, fn, len);
    mm->fn[len] = 0;

    /* open file handle */
    mm->fp = fopen(mm->fn, "rb");
    if (!mm->fp) {
        rc = -1;
        goto quit;
    }

    /* update the dataset name from the file handle */
    if (mm->fp->member[0] > ' ') {
        snprintf(mm->fn, sizeof(mm->fn), "%s(%s)", mm->fp->dataset, mm->fp->member);
    }
    else {
        snprintf(mm->fn, sizeof(mm->fn), "%s", mm->fp->dataset);
    }

quit:
    return rc;
}
