/* @@IRALLC.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"
#include "txt99.h"

int
__irallc(FILE *fp)
{
    int         err     = 1;
    unsigned    count   = 0;
    char        *recfm  = 0;
    char        *lrecl  = 0;
    char        *space  = 0;
    char        *p      = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};
    char        temp[sizeof(fp->mode)+1];

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
    memcpy(fp->ddname, txt99[0]->text, 8);
    fp->flags |= _FILE_FLAG_DYNAMIC;

quit:
    if (txt99) FreeTXT99Array(&txt99);

    return err;
}
