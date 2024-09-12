#include <clib.h>

__asm__("\n&FUNC    SETC 'clib_auth_name'");
int
clib_auth_name(const char *name)
{
    int     rc = 0;
    CDE     *cde = clib_find_cde(name);

    if (cde) {
        /* wtodumpf(cde, sizeof(CDE), "%s %s CDE before auth_cde()", __func__, name); */
        rc = clib_auth_cde(cde);
        /* wtodumpf(cde, sizeof(CDE), "%s %s CDE after auth_cde()", __func__, name); */
    }
    else {
        /* wtof("%s %s CDE was not found", __func__, name); */
        rc = 4;
    }

    return rc;
}
