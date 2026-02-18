/* @@75.C
** Interface to X'75xxxxxx' TCPIP in Hercules
*/
#include "__75.h"
#include "socket.h"

/* __75() - call TCPIP interface via X'75xxxxxx' instruction. */
__asm__("\n&FUNC    SETC '@@75'");
#if 1
int
__75(PL75 *pl)
{
    int         rc;
    unsigned    regs[12];
#if 0
    unsigned    *psa    = 0;                        /* low core == PSA      */
    void        *tcb    = (void*)psa[0x21c/4];      /* TCB      == PSATOLD  */
    char        caller[40]="";

    __caller(caller);
    if (strcmp(caller, "@@75send")==0) {
        wtof("__75() caller=%s, TCB=%08X", caller, tcb);
        wtodumpf(pl, sizeof(PL75), "PL75");
    }
#endif
    __asm__(
    "LR\t14,%2            => save area for regs\n\t"
    "STM\t0,11,0(14)      Save R0-R11 in stack save area\n\t"
    "LR\t11,%1             => PL75\n\t"
    "LM\t0,9,0(11)        Load R0-R9 from parameter list\n"
"*\n\t"
    "LA\t3,0              To Host PC\n\t"
    "SLR\t0,0              Restart = No\n\t"
    "DC\tX'75005000'      TCPIP 0,000(0,R5)\n\t"
    "LTR\t15,15            Check for error\n\t"
    "BNZ\tDYN75ERR\n"
"*\n\t"
    "LA\t3,1              From Host PC\n\t"
    "SLR\t0,0              Restart = No\n\t"
    "DC\tX'75006000'      TCPIP 0,000(0,R6)\n"
"DYN75ERR DS\t0H\n\t"
    "STM\t0,15,0(11)       Save results in parameter list\n\t"
    "LM\t0,11,0(14)       Restore registers\n\t"
    "LR\t%0,15"
    : "=r" (rc) : "r" (pl), "r" (regs) : "0", "1", "14", "15");

    return rc;
}
#else
int
__75(PL75 *pl)
{
    int     rc;

    __asm__(
    "STM\t0,11,20(13)      Save R0-R11 in stack save area\n\t"
    "LR\t11,%1             => PL75\n\t"
    "LM\t0,9,0(11)        Load R0-R9 from parameter list\n"
"*\n\t"
    "LA\t3,0              To Host PC\n\t"
    "SLR\t0,0              Restart = No\n\t"
    "DC\tX'75005000'      TCPIP 0,000(0,R5)\n\t"
    "LTR\t15,15            Check for error\n\t"
    "BNZ\tDYN75ERR\n"
"*\n\t"
    "LA\t3,1              From Host PC\n\t"
    "SLR\t0,0              Restart = No\n\t"
    "DC\tX'75006000'      TCPIP 0,000(0,R6)\n"
"DYN75ERR DS\t0H\n\t"
    "STM\t0,15,0(11)       Save results in parameter list\n\t"
    "LM\t0,11,20(13)      Restore registers from stack\n\t"
    "LR\t%0,15"
    : "=r" (rc) : "r" (pl) : "0", "1", "15");

    return rc;
}
#endif
