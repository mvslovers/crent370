/* @@CPOPEN.C - Open JES Checkpoint Dataset */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clibwto.h"
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"
#include "osdcb.h"
#include "osjfcb.h"
#include "clibcp.h"     /* JES Checkpoint prototypes and functions          */
#include "haspjqe.h"    /* JES Job Queue Element                            */
#include "haspjoe.h"    /* JES Job Output Element                           */

__asm("\n"
"HASPCKPT DCB   DDNAME=HASPCKPT,DSORG=PS,MACRF=(RCP),                   X\n"
"               RECFM=U,BLKSIZE=4096\n"
"DCBLEN   EQU   *-HASPCKPT");

static int allocate_checkpoint(HASPCP *fp, const char *dataset);

HASPCP *__cpopen(const char *dataset)
{
    int         rc;
    HASPCP      *cp     = NULL;
    DCB         *dcb    = NULL;
    unsigned    openpl  = 0x80000000;
    unsigned    work;
    unsigned    blocks;
    char        buf[4096];

    /* Allocate a Checkpoint File Handle */
    cp = calloc(1, sizeof(HASPCP) + sizeof(DCB));
    if (!cp) {
        goto quit;
    }

    /* Initialize Checkpoint File Handle */
    strcpy(cp->eye, HASPCP_EYE);
    dcb = (DCB*) ((char*)cp + sizeof(HASPCP));
    cp->dcb = dcb;

    /* copy model DCB into our dcb area */
    __asm("L\t1,=A(HASPCKPT)        model DCB for HASPCKPT\n\t"
          "MVC\t0(DCBLEN,%0),0(1)   copy model to our dcb area"
          : :"r"(dcb));

    /* Get DD or DATASET allocated */
    if (toupper(dataset[0])=='D' && toupper(dataset[1])=='D' && dataset[2]==':') {
        /* The dataset is "dd:SOMENAME" */
        int i;
        const char *p = &dataset[3];

        for (i=0; i < 8 && *p; i++) {
            cp->ddname[i] = toupper(p[i]);
        }
        while(i < 8) cp->ddname[i++]=' ';
        memcpy(dcb->dcbddnam, cp->ddname, 8);
    }
    else {
        /* Allocate dataset */
        rc = allocate_checkpoint(cp, dataset);
        if (rc) {
            __cpclos(cp);
            cp = NULL;
            goto quit;
        }
    }

    /* open the checkpoint dataset */
    __asm("OPEN\t((%0)),MF=(E,(%1))" : : "r"(dcb), "r"(&openpl));
    if (!(dcb->dcboflgs & DCBOFOPN)) {
        __cpclos(cp);
        cp = NULL;
    }

    /* skip over SYNC records */
    __cppoin(cp, 0x00000300);   /* TTRz = record 3 */

    /* read first record */
    __cpread(cp, buf);

    /* save in checkpoint handle */
    memcpy(&cp->hct, buf, sizeof(cp->hct));

    /* Compute offset to first PDDB in IOT */
    work = cp->hct._NUMTGV;     /* number of track groups per volume    */
    work += 7; work = work >> 3;/* round to multiple of 8               */
    work *= cp->hct._NUMDA;     /* times number of spool volumes        */
    work += 75;                 /* add offset                           */
    work &= 0xFFFFFFFC;         /* round to full word boundary          */
    cp->pddb1 = work;           /* offset to first PDDB                 */

    /* Compute number of JQE block on checkpoint */
    work = cp->hct._MAXJOBS;    /* Number of JQES                       */
    work++;                     /* plus 1 for eye catcher               */
    work *= JQELNGTH;           /* times length of JQE                  */
    work += 4095;               /* prepare to round 4K                  */
    work >>= 12;                /* divide by 4096                       */
    cp->jqeblks = work;         /* number of JQE blocks on checkpoint   */

    /* Compute number of JOT block in checkpoint */
    work = cp->hct._NUMJOES;    /* number of JOES                       */
    work += 3;                  /* adjust length for JOT prefix         */
    work *= JOESIZE;            /* multiply by length of JOE            */
    work += 4095;               /* prepare to round 4K                  */
    work >>= 12;                /* divide by 4096                       */
    cp->jotblks;                /* number of JOT blocks on checkpoint   */

    /* Allocate buffer for JOT and JQE blocks */
    blocks = cp->jotblks + cp->jqeblks;
    cp->buf = calloc(1, blocks*4096);
    if (!cp->buf) goto quit;
    cp->buflen = blocks*4096;

    /* Read in the checkpoint blocks into our buffer */
    for (work=0; work < blocks; work++) {
        __cpread(cp, &cp->buf[work*4096]);
    }

    /* The first JQE is here */
    cp->jqe = (__JQE*)&cp->buf[28]; /* skip over "JES2 COLDSTART TK4- .ï.Ì...." */
    cp->jqeend = (__JQE*)&cp->buf[cp->jqeblks*4096];

    if (cp->jotblks) {
        cp->jot = (__JOT*)&cp->buf[cp->jqeblks*4096];
        cp->jotend = (__JOT*)&cp->buf[blocks*4096];
    }

quit:
   return cp;
}

__asm__("\n&FUNC    SETC 'allocate_checkpoint'");
static int
allocate_checkpoint(HASPCP *fp, const char *dataset)
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
