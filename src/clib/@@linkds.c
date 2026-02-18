/* __linkds() - Link to an external program with estae recovery, dump suppressed */
#include "cliblink.h"
#include "clibstae.h"

/* returns 0 otherwise abend code, linked pgm rc returned in prc */
__asm__("\n&FUNC    SETC 'trylink'");
static int trylink(const char *pgm, void *dcb, void *r1, int *prc)
{
    int         rc      = 0;    /* try() return code */

	// wtof("%s: pgm=\"%s\"", __func__, pgm);

    /* create ESTAE for abend report, suppress the dump */
    abendrpt(ESTAE_CREATE, DUMP_SUPPRESS);

    /* LINK of pgm, rc==0 success */
    rc = __link(pgm, dcb, r1, prc);

    /* remove the ESTAE */
    abendrpt(ESTAE_DELETE, DUMP_DEFAULT);

    return rc;
}

/* returns 0 otherwise abend code, linked pgm rc returned in prc */
int __linkds(const char *pgm, void *dcb, void *r1, int *prc)
{
    int         rc      = 0;    /* try() return code */

	// wtof("%s: pgm=\"%s\"", __func__, pgm);

    /* try LINK of pgm, rc==0 success, otherwise abend code in rc */
    rc = try(trylink, pgm, dcb, r1, prc);

    return rc;
}



