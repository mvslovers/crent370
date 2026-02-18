/* SYSTEM.C */
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "clibcrt.h"

/* The following code was taken from Paul Markham's "EXEC" program,
   and adapted to create a system() function.  The code is all
   public domain */

__PDPCLIB_API__ int system(const char *string)
{
    CLIBGRT     *grt    = __grtget();
    char pgm[9];
    size_t pgm_len;
    size_t cnt;
    char *p;

    p = strchr(string, ' ');
    if (p == NULL) {
        p = strchr(string, '\0');
    }

    pgm_len = p - string;
    /* don't allow a program name greater than 8 */

    if (pgm_len > 8) {
        return (-1);
    }
    memcpy(pgm, string, pgm_len);
    pgm[pgm_len] = '\0';

    /* uppercase the program name */
    for (cnt = 0; cnt < pgm_len; cnt++) {
        pgm[cnt] = toupper((unsigned char)pgm[cnt]);
    }

    /* point to parms */
    if (*p != '\0') {
        p++;
    }

    /* all parms now available */
    /* we use 1 = batch or 2 = tso */
    return (__system(grt->grtflag1 & GRTFLAG1_TSO ? 2 : 1,
                pgm_len, pgm, strlen(p), p));
}
