/* RACAUTH.C - racf_auth()
** check authorization to resource
** Hex Code Meaning
** 00       The user is authorized by RACF to obtain use of a RACF-protected
**          resource. Register 0 contains one of the following reason codes:
**      Reason  Meaning
**      00      Indicates a normal completion.
**      04      Indicates STATUS=ERASE was specified and the data set is to
**              be erased when scratched.
**              Otherwise, indicates that the warning status of the resource
**              was requested by the RACHECK issuer setting bit X'10' at
**              offset 12 decimal in the RACHECK parameter list and the
**              resource is in warning mode.
**      10      When CLASS=TAPEVOL, indicates the TAPEVOL profile contains
**              a TVTOC.
**      20      When CLASS=TAPEVOL, indicates that the TAPEVOL profile can
**              contain a TVTOC, but currently does not (for a scratch pool
**              volume).
**      24      When CLASS=TAPEVOL, indicates that the TAPEVOL profile does
**              not contain a TVTOC.
** 04       The specified resource is not protected by RACF. Register 0
**          contains the following reason code:
**      Reason  Meaning
**      00      Indicates a normal completion.
** 08       The user is not authorized by RACF to obtain use of the specified
**          RACF-protected resource. Register 0 contains the following
**          reason code:
**      00      Indicates a normal completion. A possible cause would be
**              PROTECTALL is active, no profile is found, and the user ID
**              whose authority was checked does not have the SPECIAL attribute.
**      04      Indicates STATUS=ERASE was specified and the data set is to
**              be erased when scratched.
**      08      Indicates DSTYPE=T or CLASS=‘TAPEVOL’ was specified and the
**              user is not authorized to use the specified volume.
**      0C      Indicates the user is not authorized to use the data set.
**      10      Indicates DSTYPE=T or CLASS=‘TAPEVOL’ was specified and the
**              user is not authorized to specify LABEL=(,BLP).
**      1C      User with EXECUTE authority to the data set profile specified
**              ATTR=READ, and RACF failed the access attempt.
** 0C       The OLDVOL specified was not part of the multivolume data set
**          defined by VOLSER, or it was not part of the same tape volume
**          defined by ENTITY.
** 10       RACINIT issued by third-party RACHECK failed. Register 0 contains
**          the RACINIT return code.
** 64       Indicates that the CHECK subparameter of the RELEASE keyword was
**          specified on the execute form of the RACHECK macro; however, the
**          list form of the macro does not have the proper RELEASE parameter.
**          Macro processing terminates.
*/
#include "racf.h"
#include "cliblock.h"

__asm__("\n&FUNC    SETC 'racf_auth'");
int
racf_auth(ACEE *acee, const char *classname, const char *resource, int attr)
{
    int         rc          = 0;
    unsigned    *psa        = (unsigned *)0;
    unsigned    *ascb       = (unsigned *)psa[0x224/4]; /* A(ASCB)      */
    unsigned    *asxb       = (unsigned *)ascb[0x6C/4]; /* A(ASXB)      */
    ACEE        **asxbsenv  = (ACEE **)  &asxb[0xC8/4]; /* A(ASXBSENV)  */
    ACEE        *oldacee    = *asxbsenv;                /* prev ACEE    */
    int         len;
    RACLASS     cclass;
    char        resname[80];
    RACHECK     plist;

    /* lock the ASXB (ENQ) address */
    lock(asxb,0);

    memset(cclass.name, ' ', sizeof(cclass.name));
    memset(resname, ' ', sizeof(resname));
    memset(&plist, 0, sizeof(plist));

    if (classname) {
        len = strlen(classname);
        if (len > sizeof(cclass.name)) len = sizeof(cclass.name);
        memcpy(cclass.name, classname, len);
    }

    if (resource) {
        len = strlen(resource);
        if (len > sizeof(resname)) len = sizeof(resname);
        memcpy(resname, resource, len);
    }

    switch (attr) {
    case 0:
        /* not specified, default to READ access */
        attr = RACHECK_ATTR_READ;
        break;
    case RACHECK_ATTR_READ:
    case RACHECK_ATTR_UPDATE:
    case RACHECK_ATTR_CONTROL:
    case RACHECK_ATTR_ALTER:
        /* seems okay */
        break;
    default:
        /* invalid, set to highest access allowed */
        attr = RACHECK_ATTR_ALTER;
    }
#if 1
	plist.flag1 |= RACHECK_FLAG1_LOG_NONE;
#endif
    plist.len   = sizeof(plist);

    __asm__("\n"
"*\n"
"* enter supervisor state\n"
"*\n"
"         MODESET KEY=ZERO,MODE=SUP\n"
        : : : "1", "14", "15");

    if (acee) {
        /* set ASXBSENV with the ACEE pointer */
        *asxbsenv = acee;
    }

    __asm__("\n"
"*\n"
"* check access to resource\n"
"*\n"
"         RACHECK ENTITY=((%1)),CLASS=(%2),ATTR=(%3),MF=(E,%4)\n"
"         ST    15,%0"
        : "=m"(rc) : "r"(resname), "r"(&cclass), "r"(attr), "m"(plist)
        : "1", "14", "15" );

    if (acee) {
        /* set ASXBSENV with the prev ACEE pointer */
        *asxbsenv = oldacee;
    }

    __asm__("\n"
"*\n"
"* return to problem state\n"
"*\n"
"         MODESET KEY=NZERO,MODE=PROB\n"
        : : : "1", "14", "15");

    /* unlock the ASXB (ENQ) address */
    unlock(asxb,0);

    return rc;
}
#if 1
    __asm__("\n"
"LISTLOG  RACHECK ENTITY=ENTITY,CLASS='FACILITY',ATTR=READ,LOG=NONE,    X\n\t\tMF=L\n"
"LISTNOG  RACHECK ENTITY=ENTITY,CLASS='FACILITY',ATTR=READ,             X\n\t\tMF=L\n"
"ENTITY   DC   CL40'THIS'\n"
    );
#endif
