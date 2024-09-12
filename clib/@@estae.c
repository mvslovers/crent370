/* @@ESTAE.C
** Create, Overlay, or Delete an ESTAE
**
** The recovery routine will call a C recovery routine.
** The C recovery routine should alter the SDWA for any
** retry that is desired.
**
** Up to 10 levels of ESTAE recovery routines can be created.
**
** Note: do not compile this code with any C optimization
**       otherwise the function pointer address in the param array
**       will always be zero!
*/
#include "stdio.h"
#include "clibstae.h"
#include "clibcrt.h"

typedef struct {
    unsigned u[2];
} PARAM;

__asm__("\n&FUNC    SETC 'required'");
static unsigned
required(void *fp)
{
    unsigned    np = (unsigned) fp;

    if (!np) {
        fprintf(stderr,
            "estae() a function pointer is required for "
            "ESTAE CREATE or OVERLAY\n");
    }

    return np;
}

int
__estae(ESTAE_OP op, void *fp, void *udata)
{
    CLIBCRT         *crt    = __crtget();
    int             rc      = -1;
    unsigned        work[4];
    unsigned        np;
    volatile PARAM  *param;
    volatile PARAM  *p;

#if 0
    printf("Enter estae(%d,%08X,%08X)\n", op, fp, udata);
#endif
    if (!crt) goto quit;
    param = (PARAM*)crt->crtestpl;

    if (op==ESTAE_CREATE ??!??! op==ESTAE_OVERLAY) {
        np = required(fp);
        if (!np) goto quit;
    }

    switch(op) {
    case ESTAE_CREATE:
        if (crt->crtestct>=10) goto quit;
        p = &param[crt->crtestct];
        p->u[0] = (unsigned) np;   /* C function pointer */
        p->u[1] = (unsigned) udata;/* user data */
#if 0
        printf("p=%08X, param0=%08X, param1=%08X\n", p, p->u[0], p->u[1]);
        printf("np=%08X, udata=%08X\n", np, udata);
#endif
        __asm__(
        "LA\t2,RECOVERY\n\t"
        "LR\t3,%1               recovery parameter list\n\t"
        "LR\t1,%2               macro parameter list\n\t"
        "XC\t0(16,1),0(1)        clear macro parameter list\n\t"
        "ESTAE (2),CT,PARAM=(3),PURGE=NONE,ASYNCH=YES,TERM=YES,        X\n\t"
        "      MF=(E,(1))\n\t"
        "LR\t%0,15"
        : "=r"(rc): "r"(p), "r"(work) : "0", "1", "2", "3", "14", "15");
        if (rc==0) crt->crtestct++;
        break;
    case ESTAE_OVERLAY:
        if (crt->crtestct>0) crt->crtestct--;
        p = &param[crt->crtestct];
        p->u[0] = (unsigned) np;   /* C function pointer */
        p->u[1] = (unsigned) udata;/* user data */
        __asm__(
        "LA\t2,RECOVERY\n\t"
        "LR\t3,%1               recovery parameter list\n\t"
        "LR\t1,%2               macro parameter list\n\t"
        "XC\t0(16,1),0(1)        clear macro parameter list\n\t"
        "ESTAE (2),OV,PARAM=(3),PURGE=NONE,ASYNCH=YES,TERM=YES,        X\n\t"
        "      MF=(E,(1))\n\t"
        "LR\t%0,15"
        : "=r"(rc): "r"(p), "r"(work) : "0", "1", "2", "3", "14", "15");
        crt->crtestct++;
        break;
    case ESTAE_DELETE:
        if (crt->crtestct>0) crt->crtestct--;
        __asm__(
        "ESTAE 0\n\t"
        "LR\t%0,15"
        : "=r" (rc): : "0", "1", "14", "15");
        break;
    }

quit:
#if 0
    printf("Exit estae(), rc=%d\n", rc);
#endif
    return rc;
}

/* our default RETRY routine, S0C1 ABEND */
__asm__("\n"
"RETRY    DS    0H\n"
#if 0
"         ESTAE 0                    REMOVE THE ESTAE\n"
#endif
"         DC    H'0'                 INVALID OPERATION CODE -> S0C1-1");

/* our RECOVERY routine, percolates the ABEND if we don't have an SDWA */
__asm__("\n"
"RECOVERY DS    0H\n"
"         USING RECOVERY,15\n"
#if 0
"         LR    3,0\n"
"         WTO   'In RECOVERY'\n"
"         LR    0,3\n"
#endif
"         CH    0,=H'12'             Q.SDWA?\n"
"         BNE   HAVESDWA             YES, continue\n"
"         SR    15,15                NO, percolate ABEND\n"
"         BR    14                   RETURN TO RTM=PERCOLATE BY DEFAULT\n"
"         LTORG ,\n"
"         DROP  15");

/* We have an SDWA, calls the C function */
__asm__("\n"
"HAVESDWA DS    0H\n"
"         STM   14,12,12(13)         SAVE REGISTERS\n"
"         LA    12,0(,15)            Establish base register\n"
"         USING RECOVERY,12\n"
"         LR    3,1                  SAVE POINTER TO SDWA\n"
"         USING SDWA,3               MAP SYSTEM DIAGNOSTIC SAVE AREA");
#if 0
__asm__( "WTO   'In assembler RECOVERY'");
#endif
/* Allocate a new stack */
__asm__( "GETMAIN RU,LV=STACKLEN,SP=124\n"
"         ST    13,4(1)              chain prev save area\n"
"         ST    1,8(13)              chain next save area\n"
"         LR    13,1                 => our stack\n"
"         USING STACK,13");
#if 0
__asm__( "WTO   'New stack allocated, calling C function'");
#endif
/* Update next available byte in stack */
__asm__( "LA    1,MAINSTK            stack for called functions\n"
"         ST    1,SAVENAB            next available byte in stack");

__asm__( "L     2,SDWAPARM           get parameter address");

/* Create parameter list and call C function */
__asm__( "ST    3,ARG0               SDWA address\n"
"         ST    2,ARG1               udata address\n"
"         LA    1,PARMLIST           => C function parameter list\n"
"         L     15,0(,2)             => C function to call\n"
"         BALR  14,15                call C function\n"
"         LR    2,15                 => save return code");
#if 0
__asm__( "WTO   'Returned from C function'");
#endif
/* Release stack storage */
__asm__( "LR    1,13                 => storage to release\n"
"         L     13,4(13)             => RTM save area\n"
"         FREEMAIN RU,LV=STACKLEN,A=(1),SP=124");
#if 0
__asm__( "WTO   'Returning to RTM'");
#endif
/* Tell RTM to retry */
__asm__( "LR    15,2                 restore return code\n"
"         DROP 3\n"
"         LM    14,12,12(13)         LOAD REGISTERS\n"
"         BR    14                   RETURN TO RTM");
__asm__( "IHASDWA                    GENERATE SDWA DSECT\n"
"STACK    DSECT\n"
"SAVEAREA DS    18F               00 (0)  callers registers go here\n"
"SAVELWS  DS    A                 48 (72) PL/I Language Work Space N/A\n"
"SAVENAB  DS    A                 4C (76) next available byte -------+\n"
"* our stack variables                                               |\n"
"PARMLIST DS    0F                plist for C recovery function      |\n"
"ARG0     DS    A                 => SDWA                            |\n"
"ARG1     DS    A                 => udata                           |\n"
"* end of our stack variables                                        |\n"
"* start of C function stack area                                    |\n"
"         DS    0D                                                   |\n"
"MAINSTK  DS    8192F              32K bytes <-----------------------+\n"
"MAINLEN  EQU   *-MAINSTK\n"
"STACKLEN EQU   *-STACK");
