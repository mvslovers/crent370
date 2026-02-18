#include <clib.h>

static int unauth_setup(const char *name);
static int auth_pgm(const char *name);

__asm__("\n&FUNC    SETC 'clib_apf_setup'");
int
clib_apf_setup(const char *pgm)
{
    int         rc      = 0;
    CLIBCRT     *crt    = __crtget();   /* A(CLIBCRT)               */

    if (!(crt->crtopts & CRTOPTS_AUTH)) {
        /* this task has not been authorized yet */
        rc = unauth_setup(pgm);
    }

    return rc;
}

__asm__("\n&FUNC    SETC 'unauth_setup'");
static int unauth_setup(const char *name)
{
    int         rc      = 0;
    CLIBCRT     *crt    = __crtget();   /* A(CLIBCRT)               */

    /* this task is not currently APF authorized */
    rc = __autask();    /* APF authorize this task via SVC 244  */
    /* wtof("%s __autask() rc=%d", __func__, rc); */
    if (rc==0) {
        if (crt->crtauth & CRTAUTH_ON) {
            /* we want the STEPLIB APF authorized as well */
            rc = __austep();    /* APF authorize the STEPLIB */
            if (rc==0) {
                if (crt->crtauth & CRTAUTH_STEPLIB) {
                    rc = auth_pgm(name);
                }
            }
        }
        else {
            rc = auth_pgm(name);
        }
    }

    return rc;
}

__asm__("\n&FUNC    SETC 'auth_pgm'");
static int auth_pgm(const char *name)
{
    int         rc      = 0;

    rc = clib_auth_name(name);
    /* wtof("%s auth_name(%s) rc=%d", __func__, name, rc); */

    rc = clib_identify_cthread();
    /* wtof("%s identify_cthread() rc=%d", __func__, rc); */

    /* mark CTHREAD as an authorized entry point AC(1) */
    rc = clib_auth_name("CTHREAD");

    return rc;
}

