/* TMPFILE.C */
#include <stdio.h>

FILE *
tmpfile(void)
{
    char    fn[FILENAME_MAX];

    tmpnam(fn);

    return (fopen(fn, "wb"));
}
