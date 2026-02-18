#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

#if 0
__asm__("\n"
"R0       EQU   0\n"
"R1       EQU   1\n"
"R2       EQU   2\n"
"R3       EQU   3\n"
"R4       EQU   4\n"
"R5       EQU   5\n"
"R6       EQU   6\n"
"R7       EQU   7\n"
"R8       EQU   8\n"
"R9       EQU   9\n"
"R10      EQU   10\n"
"R11      EQU   11\n"
"R12      EQU   12\n"
"R13      EQU   13\n"
"R14      EQU   14\n"
"R15      EQU   15\n"
);
#endif

int
__vsopen(const char *ddname, VSTYPE t, VSACCESS a, VSMODE m, VSFILE **vsfile)
{
    int         rc      = 0;
    VSFILE      *vs     = 0;
    ACB         *acb    = 0;
    RPL         *rpl    = 0;
    unsigned    pl[16]  = {0};

    /* validate options */
    if (t==VSTYPE_ESDS) {
#if 0
        if (a==VSACCESS_DIR || a==VSACCESS_DYNAM) {
            /* invalid access for ESDS */
            rc = EVSACCESS;
            goto quit;
        }
#endif
    }
    else if (t==VSTYPE_KSDS) {
        if (a==VSACCESS_DIR) {
            if (m==VSMODE_OUT) {
                rc = EVSMODE;
                goto quit;
            }
        }
        else if (a==VSACCESS_DYNAM) {
            if (m==VSMODE_OUT) {
                rc = EVSMODE;
                goto quit;
            }
        }
    }
    else if (t==VSTYPE_RRDS) {
        if (a==VSACCESS_DYNAM) {
            if (m==VSMODE_OUT) {
                rc = EVSMODE;
                goto quit;
            }
        }
    }

    /* allocate VSFILE handle */
    vs = calloc(1, sizeof(VSFILE));
    if (!vs) {
        rc = ENOMEM;
        goto quit;
    }

    /* initialize our VSAM file handle */
    strcpy(vs->eye, VSFILE_EYE);
    strcpyp(vs->ddname, sizeof(vs->ddname), (char*)ddname, ' ');
    vs->type    = t;
    vs->access  = a;
    vs->mode    = m;
    vs->vsself  = vs;   /* pointer to self, used by __vserr */
    acb         = &vs->acb;
    rpl         = &vs->rpl;

    /* get prototype ACB */
    __asm__("MVC\t0($ACBLEN,%0),ACBMODEL    Copy prototype ACB"
        : : "r"(&vs->acb));

    /* put DD name into ACB */
    memcpy(acb->acbddnm, vs->ddname, sizeof(acb->acbddnm));

    /* get prototype RPL */
    __asm__("MVC\t0($RPLLEN,%0),RPLMODEL    Copy prototype RPL"
        : : "r"(&vs->rpl));

    /* put ACB address into RPL */
    __asm__("MODCB RPL=(%0),ACB=((%1)),MF=(G,(%2))"
        : : "r"(&vs->rpl), "r"(&vs->acb), "r"(pl));

    /* TYPE */
    switch(t) {
    case VSTYPE_KSDS:
    case VSTYPE_RRDS:
        __asm__("MODCB ACB=(%0),MACRF=(KEY),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        __asm__("MODCB RPL=(%0),OPTCD=(KEY),MF=(G,(%1))"
                : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        break;
    case VSTYPE_ESDS:
        __asm__("MODCB ACB=(%0),MACRF=(ADR),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        __asm__("MODCB RPL=(%0),OPTCD=(ADR),MF=(G,(%1))"
                : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        break;
    default:
        rc = EVSTYPE;
        goto quit;
    }

    /* ACCESS */
    switch(a) {
    case VSACCESS_DIR:      /* direct access        */
        __asm__("MODCB ACB=(%0),MACRF=(DIR),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        break;
    case VSACCESS_SEQ:      /* sequential access    */
        __asm__("MODCB ACB=(%0),MACRF=(SEQ),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        break;
    case VSACCESS_DYNAM:    /* dynamic access       */
        __asm__("MODCB ACB=(%0),MACRF=(SEQ,DIR),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        break;
    case VSACCESS_ADR:      /* address access       */
        __asm__("MODCB ACB=(%0),MACRF=(ADR),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        break;
    default:
        rc = EVSACCESS;
        goto quit;
    }
    switch(a) {
    case VSACCESS_DIR:      /* direct access        */
        __asm__("MODCB RPL=(%0),OPTCD=(DIR),MF=(G,(%1))"
                : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        break;
    case VSACCESS_SEQ:      /* sequential access    */
    case VSACCESS_DYNAM:    /* dynamic access       */
        __asm__("MODCB RPL=(%0),OPTCD=(SEQ),MF=(G,(%1))"
                : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        break;
    case VSACCESS_ADR:      /* address access       */
        __asm__("MODCB RPL=(%0),OPTCD=(ADR),MF=(G,(%1))"
                : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        break;
    }

    /* MODE */
    switch(m) {
    case VSMODE_IN:         /* input (read only)        */
        __asm__("MODCB ACB=(%0),MACRF=(IN),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        break;
    case VSMODE_OUT:        /* output (write only)      */
    case VSMODE_UPD:        /* update (read and write)  */
        __asm__("MODCB ACB=(%0),MACRF=(OUT),MF=(G,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");
        break;
    default:
        rc = EVSMODE;
        goto quit;
    }
    switch(m) {
    case VSMODE_IN:         /* input (read only)        */
    case VSMODE_OUT:        /* output (write only)      */
        __asm__("MODCB RPL=(%0),OPTCD=(NUP),MF=(G,(%1))"
                : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        break;
    case VSMODE_UPD:        /* update (read and write)  */
        __asm__("MODCB RPL=(%0),OPTCD=(UPD),MF=(G,(%1))"
                : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        break;
    }

    /* open VSAM cluster */
    __asm__("MVC\t0($OPNLEN,%1),OPNMODEL    Copy prototype OPEN\n\t"
            "OPEN  ((%0)),MF=(E,(%1))\n\t"
            "ST    15,%2"
        : : "r"(&vs->acb), "r"(pl), "m"(rc) : "1", "14", "15");
    if (acb->acboflgs & ACBOPEN) {
        vs->flags |= VSFILE_FLAG_OPEN;
    }
    else {
        rc = EVSOPEN;
    }

quit:
    if (rc) {
        errno = rc;
        if (vs) {
            __vsclos(vs);
            vs = 0;
        }
    }
    if (vsfile) *vsfile = vs;

    return rc;
}
__asm__("DS\t0F\nOPNMODEL OPEN (ACBMODEL),MF=L\n$OPNLEN\tEQU\t*-OPNMODEL");
__asm__("DS\t0F\nACBMODEL ACB\tDDNAME=X,EXLST=EXITLIST");
__asm__("DS\t0F\nRPLMODEL RPL\tACB=ACBMODEL");
#if 0
__asm__("EXTRN @@VSXLER,@@VSXERR,@@VSXEOF");
__asm__("DS\t0F\nEXITLIST EXLST LERAD=@@VSXLER,SYNAD=@@VSXERR,EODAD=@@VSXEOF");
#else
__asm__("DS\t0F\nEXITLIST EXLST LERAD=LERAD,SYNAD=SYNAD,EODAD=EODAD");
#endif
__asm__("DS\t0F\n"
"EODAD    PDPPRLG CINDEX=0,FRAME=WORKLEN,BASER=12,ENTRY=NO\n"
"         USING WORK,R13\n"
"*\n"
"         ST    R1,PLIST+0          A(RPL)\n"
"         LA    R3,4                End Of File Code\n"
"         ST    R3,PLIST+4\n"
"*\n"
"         LA    R1,PLIST\n"
"         L     R15,=V(@@VSXEOF)\n"
"         BALR  R14,R15\n"
"*\n"
"         L     R13,4(,R13)         get callers stack\n"
"         LR    R14,R2              get return address\n"
"         LM    R0,R12,20(R13)      restore registers\n"
"         BR    R14                 return to target\n"
"         LTORG ,\n"
);

__asm__("DS\t0F\n"
"LERAD    PDPPRLG CINDEX=0,FRAME=WORKLEN,BASER=12,ENTRY=NO\n"
"         USING WORK,R13\n"
"*\n"
"         ST    R1,PLIST+0          A(RPL)\n"
"         LA    R3,8                Logical Error Code\n"
"         ST    R3,PLIST+4\n"
"*\n"
"         LA    R1,PLIST\n"
"         L     R15,=V(@@VSXERR)    Common error handler\n"
"         BALR  R14,R15\n"
"*\n"
"         L     R13,4(,R13)         get callers stack\n"
"         LR    R14,R2              get return address\n"
"         LM    R0,R12,20(R13)      restore registers\n"
"         BR    R14                 return to target\n"
"         LTORG ,\n"
);

__asm__("DS\t0F\n"
"SYNAD    PDPPRLG CINDEX=0,FRAME=WORKLEN,BASER=12,ENTRY=NO\n"
"         USING WORK,R13\n"
"*\n"
"         ST    R1,PLIST+0          A(RPL)\n"
"         LA    R3,12               Physical Error Code\n"
"         ST    R3,PLIST+4\n"
"*\n"
"         LA    R1,PLIST\n"
"         L     R15,=V(@@VSXERR)    Common error handler\n"
"         BALR  R14,R15\n"
"*\n"
"         L     R13,4(,R13)         get callers stack\n"
"         LR    R14,R2              get return address\n"
"         LM    R0,R12,20(R13)      restore registers\n"
"         BR    R14                 return to target\n"
"         LTORG ,\n"
);

__asm__("\n"
"WORK     DSECT\n"
"SAVEAREA DS    18F                                                  00\n"
"STKSVLWS DS    A                 PL/I Language Work Space N/A       48\n"
"STKSVNAB DS    A                 next available byte      -------+  4C\n"
"PLIST    DS    2F                parameter list\n"
"WORKLEN  EQU   *-WORK\n"
);

__asm__("IFGACB\n$ACBLEN\tEQU\t*-IFGACB");
__asm__("IFGRPL\n$RPLLEN\tEQU\t*-IFGRPL");
__asm__("CSECT ,");
