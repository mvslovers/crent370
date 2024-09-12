/* RACLOGIN.C - racf_login()
** returns ACEE if successful.
**
** If racf_rc points to an int it receives the RACF return code:
** Hex Dec  Meaning
** 00    0  RACINIT has completed successfully.
** 04    4  The user profile is not defined to RACF.
** 08    8  The password is not authorized.
** 0C   12  The password has expired.
** 10   16  The new password is not valid.
** 14   20  The user is not defined to the group.
** 18   24  RACINIT was failed by the installation exit routine.
** 1C   28  The user's access has been revoked.
** 20   32  RACF is not active.
** 24   36  The user's access to the specified group has been revoked.
** 28   40  OIDCARD parameter is required but not supplied.
** 2C   44  OIDCARD parameter is not valid for specified user.
** 30   38  The user is not authorized to use the terminal.
**          Register 0 contains one of the following reason codes:
**          Reason  Meaning
**          00      Indicates a normal completion.
**          04      Indicates the user is not authorized to access the system
**                  on this day, or at this time of day.
**          08      Indicates the terminal cannot be used on this day, or at
**                  this time of day.
**          34      The user is not authorized to use the application.
**          64      Indicates that the CHECK subparameter of the RELEASE
**                  keyword was specified on the execute form of the RACINIT
**                  macro; however, the list form of the macro does not have
**                  the proper RELEASE parameter. Macro processing terminates.
*/
#include "racf.h"
#include "cliblock.h"

__asm__("\n&FUNC    SETC 'racf_login'");
ACEE *
racf_login(const char *user, const char *pass, const char *group, int *racf_rc)
{
    volatile int    rc          = 0;
    volatile ACEE   *acee       = 0;
    int             sup         = 0;
    unsigned        *psa        = (unsigned *)0;
    unsigned        *ascb       = (unsigned *)psa[0x224/4]; /* A(ASCB)      */
    unsigned        *asxb       = (unsigned *)ascb[0x6C/4]; /* A(ASXB)      */
    int             len;
    char            userid[9];
    char            password[9];
    char            groupid[9];
    RACINIT         plist;

    /* lock the ASXB (ENQ) address */
    lock(asxb,0);

    __asm__("XC\t0(0,%0),0(%0)      clear plist *** executed ***\n\t"
            "EX\t%1,*-6" : : "r"(&plist), "r"(sizeof(plist)-1));
    plist.len   = sizeof(plist);

    /* provide default for user */
    if (!user) user = "*";

    len = strlen(user);
    if (len > 8) len = 8;
    userid[0] = (char)len;
    if (len > 0) {
        __asm__("MVC\t0(8,%0),=CL8' '   clear userid to spaces"
            : : "r"(&userid[1]));
        __asm__("MVC\t0(0,%0),0(%1)     copy userid *** executed ***\n\t"
                "EX\t%2,*-6" : : "r"(&userid[1]), "r"(user), "r"(len-1));
        __asm__("OC\t0(8,%0),=CL8' '    fold to upper case"
            : : "r"(&userid[1]));
    }

    if (pass) {
        len = strlen(pass);
        if (len > 8) len = 8;
        password[0] = (char)len;
        if (len > 0) {
            __asm__("MVC\t0(8,%0),=CL8' '   clear password to spaces"
                : : "r"(&password[1]));
            __asm__("MVC\t0(0,%0),0(%1)     copy password *** executed ***\n\t"
                    "EX\t%2,*-6" : : "r"(&password[1]), "r"(pass), "r"(len-1));
            __asm__("OC\t0(8,%0),=CL8' '    fold to upper case"
                : : "r"(&password[1]));
        }
    }

    len = group ? strlen(group) : 0;
    if (len > 8) len = 8;
    groupid[0] = (char)len;
    if (len > 0) {
        __asm__("MVC\t0(8,%0),=CL8' '   clear group to spaces"
            : : "r"(&groupid[1]));
        __asm__("MVC\t0(0,%0),0(%1)     copy group *** executed ***\n\t"
                "EX\t%2,*-6" : : "r"(&groupid[1]), "r"(group), "r"(len-1));
        __asm__("OC\t0(8,%0),=CL8' '    fold to upper case"
            : : "r"(&groupid[1]));
        group = groupid;
    }

    __asm__("\n"
"*\n"
"* See if we're in supervisor state\n"
"*\n"
"         TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1\n\tST\t15,%0" : "=m"(rc)
        : : "1", "14", "15");
    if (rc==0) {
        /* we're in supervisor state */
        sup = 1;
    }

    if (!sup) {
        /* switch to supervisor state */
        __asm__("\n"
"*\n"
"* enter supervisor state\n"
"*\n"
"         MODESET KEY=ZERO,MODE=SUP\n"
        : : : "1", "14", "15");
    }

    if (pass) {
        __asm__("\n"
"*\n"
"* create ACEE for this user and password\n"
"*\n"
"         RACINIT ENVIR=CREATE,                                         X\n"
"               ACEE=(%1),USERID=(%2),PASSWRD=(%3),GROUP=(%4),MF=(E,%5)\n"
"         ST\t15,%0" : "=m"(rc)
            : "r"(&acee), "r"(userid), "r"(password), "r"(group), "m"(plist)
            : "1", "14", "15");
    }
    else {
        __asm__("\n"
"*\n"
"* create ACEE for this user (no password)\n"
"*\n"
"         RACINIT ENVIR=CREATE,PASSCHK=NO,                              X\n"
"               ACEE=(%1),USERID=(%2),GROUP=(%3),MF=(E,%4)\n"
"         ST\t15,%0" : "=m"(rc)
            : "r"(&acee), "r"(userid), "r"(group), "m"(plist)
            : "1", "14", "15");
    }

    if (!sup) {
        /* switch back to problem state */
        __asm__("\n"
"*\n"
"* return to problem state\n"
"*\n"
"         MODESET KEY=NZERO,MODE=PROB\n"
        : : : "1", "14", "15");
    }

quit:
    /* unlock the ASXB (ENQ) address */
    unlock(asxb,0);
    if (racf_rc) *racf_rc = rc;
    return (ACEE*)acee;
}
#if 0
        __asm__("\n"
"LIST     RACINIT ENVIR=CREATE,ACEE=ACEE,                               X\n"
"               USERID=USER,PASSWRD=PASS,MF=L\n"
"ACEE     DS    F\n"
"USER     DS    CL9\n"
"PASS     DS    CL9\n");
#endif
