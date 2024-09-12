/* @@JSOPEN.C - Open JES Spool Dataset(s) */
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

__asm("\n"
"HASPACE  DCB   DDNAME=HASPACE1,DSORG=DA,MACRF=(RIC),OPTCD=A,           X\n"
"               RECFM=F\n"
"DCBLEN   EQU   *-HASPACE");
__asm("DCBD\tDSORG=DA\n\t"
      "CSECT ,");

static int allocate_spool(HASPJS *fp, const char *dataset);

HASPJS *__jsopen(const char *dataset)
{
    int         rc;
    HASPJS      *js     = NULL;
    DCB         *dcb    = NULL;
    unsigned    openpl  = 0x80000000;
    int         i;
    unsigned    work;
    unsigned    blocks;
    char        devinfo[20] = {0};
    char        buf[4096];

    /* Allocate a Spool File Handle */
    js = calloc(1, sizeof(HASPJS) + sizeof(DCB));
    if (!js) {
        goto quit;
    }

    /* Initialize Checkpoint File Handle */
    strcpy(js->eye, HASPJS_EYE);
    dcb = (DCB*) ((char*)js + sizeof(HASPJS));
    js->dcb = dcb;

    /* copy model DCB into our dcb area */
    __asm("L\t1,=A(HASPACE)        model DCB for HASPACE\n\t"
          "MVC\t0(DCBLEN,%0),0(1)   copy model to our dcb area"
          : :"r"(dcb));

    /* Get DD or DATASET allocated */
    if (toupper(dataset[0])=='D' && toupper(dataset[1])=='D' && dataset[2]==':') {
        /* The dataset is "dd:SOMENAME" */
        int i;
        const char *p = &dataset[3];

        for (i=0; i < 8 && *p; i++) {
            js->ddname[i] = toupper(p[i]);
        }
        while(i < 8) js->ddname[i++]=' ';
        memcpy(dcb->dcbddnam, js->ddname, 8);
    }
    else {
        /* Allocate dataset */
        rc = allocate_spool(js, dataset);
        if (rc) {
            __jsclos(js);
            js = NULL;
            goto quit;
        }
    }

    /* open the checkpoint dataset */
    __asm("OPEN\t((%0)),MF=(E,(%1))" : : "r"(dcb), "r"(&openpl));
    if (!(dcb->dcboflgs & DCBOFOPN)) {
        __jsclos(js);
        js = NULL;
    }
#if 0
    wtof("DCB=%08X, dcbdevt=%02X", dcb, dcb->dcbdevt);
    wtodumpf(dcb, sizeof(DCB), "DCB");
#endif

    /* get spool device info */
    __asm("DEVTYPE (%0),((%1),20),DEVTAB" : :"r"(js->ddname), "r"(devinfo));
#if 0
    wtodumpf(devinfo, sizeof(devinfo), "devinfo");
#endif
    js->trkcyl = *(unsigned short *)&devinfo[10];

quit:
   return js;
}

__asm__("\n&FUNC    SETC 'allocate_spool'");
static int
allocate_spool(HASPJS *fp, const char *dataset)
{
    int         err     = 1;
    unsigned    count   = 0;
    DCB         *dcb    = fp->dcb;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};

    /* we want the DDNAME returned to us */
    err = __txrddn(&txt99, NULL);
    if (err) goto quit;

    /* allocate this dataset */
    err = __txdsn(&txt99, dataset);
    if (err) goto quit;

    /* DISP=SHR */
    err = __txshr(&txt99, NULL);
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
    memcpy(fp->ddname, txt99[0]->text, 8);
    memcpy(dcb->dcbddnam, txt99[0]->text, 8);

quit:
    if (txt99) FreeTXT99Array(&txt99);

    return err;
}
