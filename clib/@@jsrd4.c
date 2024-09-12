/* @@JSRD4.C - Read JES Spool Dataset using unsigned int MTTR value */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clibwto.h"
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"
#include "osdcb.h"
#include "osjfcb.h"
#include "clibjes2.h"   /* JES Spool prototypes and functions               */

#if 0
__asm("READ  HDECB2,DI,HASPACE,,0,0,QCDAD,MF=L");
#endif
int __jsrd4(HASPJS *js, unsigned mttr, void *buf4k, unsigned buflen)
{
    int         rc      = -1;
    DCB         *dcb;
    unsigned char *p     = buf4k;
    unsigned    work     = mttr;
    unsigned    cc       = 0;
    unsigned    hh       = 0;
    unsigned    decb[8]  = {0};
    unsigned char block[8] = "";

    if (!js) goto quit;

    dcb = js->dcb;
    if (!dcb) goto quit;

    dcb->dcbblksi = (unsigned short) buflen;

    __asm("XC\t0(8,%4),0(%4)  Initialize MBBCCHHR to zero\n\t"
          "LR\t1,%0           Load MTTR value\n\t"
          "STC\t1,7(%4)       Save R value\n\t"
          "SRL\t1,8           Shift TT value\n\t"
          "N\t1,=F'65535'     Keep just the TT value\n\t"
          "SR\t0,0            Prepare for divide\n\t"
          "DR\t0,%1           Divide by trks per cyl\n\t"
          "ST\t0,0(,%2)       Store head number\n\t"
          "ST\t1,0(,%3)       Store cylinder number\n\t"
          "MVC\t3(2,%4),2(%3)  Copy cylinder number\n\t"
          "MVC\t5(2,%4),2(%2)  Copy head number"
          : :"r"(mttr), "r"(js->trkcyl), "r"(&hh), "r"(&cc), "r"(block));
#if 0
    wtof("mttr=%08X, trkcyl=%u, cc=%u, hh=%u", mttr, js->trkcyl, cc, hh);
    wtodumpf(block, 8, "mbbcchhr");
#endif

    rc = 0;
    __asm("USING\tIHADCB,%0      ADDRESSING FOR DCB DSECT\n\t"
          "MVC\tDCBSYNAD+1(3),=AL3(SYNAD)  SET SYNAD ADDR IN DCB\n\t"
          "DROP\t%0             DROP ADDRESSING FOR DCB\n\t"
          "LR\t10,%5            R10 => rc\n\t"
          "READ\t(%1),DI,(%0),(%2),(%3),,(%4),MF=E\n\t"
          "CHECK\t(%1)\n\t"
          "B\tQUIT"
          : :"r"(js->dcb), "r"(decb), "r"(buf4k), "r"(buflen), "r"(block), "r"(&rc) : "10");

    __asm("\n"
          "SYNAD    SYNADAF ACSMETH=BDAM DECODE ERROR CAUSE\n"
          "         L     1,128(,1)      Get DECB address\n"
          "         L     0,0(,1)        Get DECB ECB value\n"
          "         ST    0,0(,10)       Save ECB value as return code\n"
          "         SYNADRLS ,           RELEASE WORK AREA\n"
          "         BR    14             RETURN TO OP SYS\n"
          "QUIT     DS    0H" : : :"10");

quit:
#if 0
    wtof("__jsrd4() rc=%08X, (%d)", rc, rc);
#endif
    return rc;
}
__asm("DCBD  DSORG=DA,DEVD=DA\n\t"
      "CSECT\t,");

