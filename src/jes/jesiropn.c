
#include <stdio.h>
#include <stdlib.h>
/* #include <ctype.h> */
#include <string.h>
#include <mvssupa.h>
#include <errno.h>
#include "svc99.h"
#include "clibary.h"
#include "txt99.h"
#include "clibwto.h"
#include "clibvsam.h"

static int __alloc_intrdr(char *ddname);
static int __vsam_open_intrdr(char *ddname, VSFILE **vsfile);
static int __vsam_close_intrdr(VSFILE *vsfile);

int jesiropn(VSFILE **vsfile)
{
    int err = 1;
    char ddname[8];
    
    err = __alloc_intrdr(ddname);
    if (err) goto quit;

    err = __vsam_open_intrdr(ddname, vsfile);
    if (err) goto quit;

quit:
    /* TODO: free INTRDR allocation */
    return err;
}

__asm__("\n&FUNC    SETC '––alloc_intrdr'");
static int __alloc_intrdr(char *ddname)
{
    int         err     = 1;
    unsigned    count   = 0;
    char        *p      = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};

    /* we want the DDNAME returned to us */
    err = __txrddn(&txt99, NULL);
    if (err) goto quit;

    /* allocate SYSOUT dataset */
    err = __txsyso(&txt99, NULL);
    if (err) goto quit;

    /* specify the SYSOUT program name */
    err = __txpgm(&txt99, "INTRDR");
    if (err) goto quit;

    /* unallocate SYSOUT dataset on close */
    err = __txclos(&txt99, NULL);
    if (err) goto quit;

    count = arraycount(&txt99);
    if (!count) goto quit;

    /* Set high order bit to mark end of list */
    count--;
    txt99[count]    = (TXT99*)((unsigned)txt99[count] | 0x80000000);

    /* construct the request block for dynamic allocation */
    rb99.len        = sizeof(RB99);
    rb99.request    = S99VRBAL;
    rb99.flag1      = S99NOCNV;
    rb99.txtptr     = txt99;

    /* SVC 99 */
    err = __svc99(&rb99);
    if (err) goto quit;

    /* return DDNAME */
    memcpy(ddname, txt99[0]->text, 8);

quit:
    if (txt99) FreeTXT99Array(&txt99);

    return err;
}

__asm__("\n&FUNC    SETC '__vsam_open_intrdr'");
static int __vsam_open_intrdr(char *ddname, VSFILE **vsfile)
{

    int          rc     =  0;
    VSFILE      *vs     =  0;
    ACB         *acb    =  0;
    RPL         *rpl    =  0;
    unsigned    *wa     =  0;
    unsigned     pl[16] = {0};
 
    /* allocate VSFILE handle */
    vs = calloc(1, sizeof(VSFILE));
    if (!vs) {
        rc = ENOMEM;
        goto quit;
    }

    /* allocate RPL work area */
    wa = calloc(1, 80);

    /* initialize our VSAM file handle */
    strcpy(vs->eye, VSFILE_EYE);
    strcpyp(vs->ddname, sizeof(vs->ddname), (char*)ddname, ' ');
    vs->type    = 0;
    vs->access  = 0;
    vs->mode    = 0;
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

    /* set ACB properties */
    __asm__("MODCB ACB=(%0),MF=(G,(%1))"
            : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");

    /* set RPL properties */
    __asm__("MODCB RPL=(%0),AREA=(%1),AREALEN=80,RECLEN=80,MF=(G,(%2))"
             : : "r"(&vs->rpl), "r"(wa), "r"(pl) : "1", "14", "15");


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
    if (rc)
    {
        errno = rc;
        if (vs) 
        {
            __vsam_close_intrdr(vs);
            vs = 0;
        }
    }
    if (vsfile) *vsfile = vs;

    return rc;
}

__asm__("\n&FUNC    SETC '__vsam_close_intrdr'");
int __vsam_close_intrdr(VSFILE *vsfile)
{
    return 0;
}

__asm__("DS\t0F\nOPNMODEL OPEN (ACBMODEL),MF=L\n$OPNLEN\tEQU\t*-OPNMODEL");
__asm__("DS\t0F\nACBMODEL ACB\tAM=VSAM,DDNAME=X,MACRF=(ADR,SEQ,OUT)");
__asm__("DS\t0F\nRPLMODEL RPL\tAM=VSAM,ACB=ACBMODEL,OPTCD=(ADR,SEQ,SYN,NUP,MVE)");
__asm__("IFGACB\n$ACBLEN\tEQU\t*-IFGACB");
__asm__("IFGRPL\n$RPLLEN\tEQU\t*-IFGRPL");
