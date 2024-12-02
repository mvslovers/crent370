/* standard library headers */
#include <stddef.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>

/* custom C library headers / MVS operating system specific */
#include "clib.h"                   /* C library internals          */
#include "clibos.h"                 /* OS specific routines         */
#include "clibwsa.h"                /* writable static area         */
#include "clibgrt.h"                /* global runtime               */
#include "clibcrt.h"                /* C runtime area for each task */
#include "clibppa.h"                /* C runtime program properties */
#include "clibenv.h"                /* C runtime environment vars   */
#include "clibstae.h"               /* C runtime recovery routines  */
#include "clibwto.h"                /* write to operator            */
#include "clibcib.h"                /* console information block    */
#include "clibthrd.h"               /* basic threads                */
#include "clibthdi.h"               /* thread management            */
#include "cliblink.h"               /* link to external program     */
#include "clibary.h"                /* dynamic arrays               */
#include "svc99.h"                  /* dynamic allocation           */
#include "osiob.h"                  /* input/output block           */
#include "clibccw.h"                /* CCW struct                   */
#include "clibecb.h"                /* ECB prototypes               */
#include "clibtmr.h"                /* timer                        */
#include "cvt.h"                    /* MVS CVT                      */
#include "ikjtcb.h"                 /* MVS TCB                      */

int main(int argc, char **argv)
{
    int             rc      = 0;
    CVT             *cvt    = CVTPTR;
    unsigned        *oldnew = cvt->cvttcbp;
    TCB             *tcb    = (TCB*)oldnew[1];
    char            *screen = NULL;
    unsigned        *svcaddr;
    char            *svclist;
    unsigned char   savekey = 0;
    void            *svcint = NULL;

    wtof("CVT is %08X", cvt);
    wtof("oldnew is %08X", oldnew);
    wtof("TCB is %08X", tcb);

    __asm__("L\tR1,=A(SVCINT)\n\t"
            "ST\tR1,%0" : "=m"(svcint) : : "1");
    wtof("SVCINT is %08X", svcint);

    /* make this program APF authorized */
    rc = clib_apf_setup(argv[0]);
    wtof("clib_apf_setup() rc=%d", rc);

    /* get PSW key=0 */
    rc = __super(PSWKEY0, &savekey);
    wtof("__super(PSWKEY0,&savekey) rc=%d, savekey=%02X", rc, savekey);

    /* get storage for SVC screening table */
    screen = getmain(264, 253); /* LSQA, fixed, key=0 */
    wtof("getmain(264,253) screen=%08X", screen);
    svcaddr = (unsigned *)&screen[0];
    svclist = &screen[8];

    /* put address of SVC routine in first word */
    svcaddr[0] = (unsigned)svcint;
    svcaddr[1] = 0xC0000000;    /* indicate type 3/4 SVC */

    /* prep screening table */
    memset(svclist, 0x80, 256);
    svclist[255] = 0x00;        /* set screen for SVC 255 */

    /* put SVC screening table in TCB */
    tcb->tcbsvca2 = screen;     /* install SVC screening table */
    tcb->tcbflgs7 |= TCBSVCS;   /* enable SVC screening */

    wtodumpf(screen, 264, "SCREEN");

    /* invoke screened SVC */
    wtof("before SVC 255");
    __asm__("SVC\t255");
    wtof("after SVC 255");

    /* remove SVC screening table */
    tcb->tcbflgs7 &= ~TCBSVCS;  /* disbale SVC screening */
    tcb->tcbsvca2 = (void*)0;   /* remove SVC screening table */

    /* release screening table */
    wtof("before freemain");
    freemain(screen);
    wtof("after freemain");

    __prob(savekey, &savekey);
    wtof("after __prob(savekey,savekey)");

    return 0;
}

__asm__("\n"
"SVCINT   DS    0H\n"
"         USING SVCINT,R6          SET BASE REGISTER\n"
"*\n"
"         LR    R11,R14            SAVE RETURN ADDRESS\n"
"*\n"
"         WTO   'HELLO FROM SVC SCREEN ROUTINE',ROUTCDE=(1,11)\n"
"*\n"
"         LR    R14,R11            RESTORE RETURN ADDRESS\n"
"         BR    R14                EXIT SVC ROUTINE\n"
);

__asm__("IKJTCB DSECT=YES,LIST=YES");
