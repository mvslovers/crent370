/* __link() - Link to an external program */
#include "cliblink.h"
#include "ctype.h"

int __link(const char *pgm, void *dcb, void *r1, int *prc)
{
    int         rc      = -1;
    int         i;
    char        program[12];    /* UPPER case pgm name                  */
    unsigned    plist[3];       /* LINK SVC parameter list              */

    /* sanity check, we really need an external program name */
    if (!pgm) goto quit;
    if (!pgm[0]) goto quit;

	// wtof("%s: pgm=\"%s\" dcb=%p", __func__, pgm, dcb);

    /* fold pgm to upper case */
    for(i=0; i < 8 && pgm[i]; i++) {
        program[i] = toupper(pgm[i]);
    }
    /* pad program name with spaces */
    while (i < 8) program[i++] = ' ';
    /* add a 0 byte to program name */
    program[8] = 0;

	// wtof("%s: program=\"%s\"", __func__, program);

    /* build the LINK SVC parameter list */
    plist[0] = (unsigned)program;   /* address of entry point name      */
    plist[1] = (unsigned)dcb;       /* DCB address or NULL              */

    /* finish the LINK SVC parameter list and issue the LINK SVC */
    __asm(
        "OI\t4(%1),X'80'     extended plist for error ret address\n\t"
        "LA\t0,ERRET         => error return address\n\t"
        "ST\t0,8(0,%1)       save in LINK SVC parameter list\n\t"
        "LR\t1,%2            => linked program parameter list\n\t"
        "LR\t15,%1           => LINK SVC parameter list\n\t"
        "SVC\t6              LINK SVC\n\t"
        "B\tDONE             normal return, return to caller\n"
"ERRET\tDS\t0H\n\t"
        "L\t15,=F'-1'        indicate failure\n"
"DONE\tDS\t0H\n\t"
        "LR\t%0,15           save return code"
        :"=r"(rc)
        :"r"(plist), "r"(r1));

quit:
    if (prc) *prc = rc;         /* give return code to caller */

    return rc;  /* -1==failure, otherwise pgm return code */
}
