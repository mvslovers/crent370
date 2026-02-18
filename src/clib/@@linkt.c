/* __linkt() - Link to an external program with estae recovery via try() */
#include "cliblink.h"
#include "clibstae.h"

/* returns 0 otherwise abend code, linked pgm rc returned in prc */
int __linkt(const char *pgm, void *dcb, void *r1, int *prc)
{
    int         rc      = 0;    /* try() return code */

    /* try LINK of pgm, rc==0 success, otherwise abend code in rc */
    rc = try(__link, pgm, dcb, r1, prc);

    return rc;
}

