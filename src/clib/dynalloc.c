/* DYNALLOC.C - Dynamic allocation using SVC 99 */
#include <stdlib.h>
#include <string.h>
#include "dynit.h"
#include "svc99.h"
#include "clibary.h"

int
dynalloc(__dyn_t *dyn_parms)
{
    int         rc;
    unsigned    count;
    int         retddn_idx  = -1;
    int         retdsn_idx  = -1;
    TXT99       **txt99     = NULL;
    RB99        rb99;

    if (!dyn_parms) return -1;

    memset(&rb99, 0, sizeof(rb99));

    /* DDNAME or return DDNAME */
    if (dyn_parms->__ddname != NULL &&
        strlen(dyn_parms->__ddname) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALDDNAM, 1,
                     strlen(dyn_parms->__ddname),
                     dyn_parms->__ddname));
        if (rc) goto quit;
    }
    else {
        retddn_idx = arraycount(&txt99);
        rc = arrayadd(&txt99, NewTXT99(DALRTDDN, 1, 8, NULL));
        if (rc) goto quit;
    }

    /* DSNAME or return DSNAME */
    if (dyn_parms->__dsname != NULL &&
        strlen(dyn_parms->__dsname) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALDSNAM, 1,
                     strlen(dyn_parms->__dsname),
                     dyn_parms->__dsname));
        if (rc) goto quit;
    }
    else {
        retdsn_idx = arraycount(&txt99);
        rc = arrayadd(&txt99, NewTXT99(DALRTDSN, 1, 44, NULL));
        if (rc) goto quit;
    }

    /* member name */
    if (dyn_parms->__member != NULL &&
        strlen(dyn_parms->__member) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALMEMBR, 1,
                     strlen(dyn_parms->__member),
                     dyn_parms->__member));
        if (rc) goto quit;
    }

    /* SYSOUT */
    if (dyn_parms->__sysout > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALSYSOU, 1, 1,
                     (const char *)&dyn_parms->__sysout));
        if (rc) goto quit;
    }

    /* SYSOUT program name */
    if (dyn_parms->__sysoutname != NULL &&
        strlen(dyn_parms->__sysoutname) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALSPGNM, 1,
                     strlen(dyn_parms->__sysoutname),
                     dyn_parms->__sysoutname));
        if (rc) goto quit;
    }

    /* status (OLD/NEW/MOD/SHR) */
    if (dyn_parms->__status > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALSTATS, 1, 1,
                     (const char *)&dyn_parms->__status));
        if (rc) goto quit;
    }

    /* normal disposition */
    if (dyn_parms->__normdisp > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALNDISP, 1, 1,
                     (const char *)&dyn_parms->__normdisp));
        if (rc) goto quit;
    }

    /* conditional disposition */
    if (dyn_parms->__conddisp > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALCDISP, 1, 1,
                     (const char *)&dyn_parms->__conddisp));
        if (rc) goto quit;
    }

    /* unit */
    if (dyn_parms->__unit != NULL &&
        strlen(dyn_parms->__unit) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALUNIT, 1,
                     strlen(dyn_parms->__unit),
                     dyn_parms->__unit));
        if (rc) goto quit;
    }

    /* volume serial */
    if (dyn_parms->__volser != NULL &&
        strlen(dyn_parms->__volser) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALVLSER, 1,
                     strlen(dyn_parms->__volser),
                     dyn_parms->__volser));
        if (rc) goto quit;
    }

    /* dataset organization */
    if (dyn_parms->__dsorg > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALDSORG, 1, 2,
                     (const char *)&dyn_parms->__dsorg));
        if (rc) goto quit;
    }

    /* space allocation unit: cylinders or tracks */
    if (dyn_parms->__alcunit == __CYL) {
        rc = arrayadd(&txt99, NewTXT99(DALCYL, 0, 0, NULL));
        if (rc) goto quit;
    }
    else if (dyn_parms->__alcunit == __TRK) {
        rc = arrayadd(&txt99, NewTXT99(DALTRK, 0, 0, NULL));
        if (rc) goto quit;
    }

    /* primary space */
    if (dyn_parms->__primary > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALPRIME, 1, 3,
                     (const char *)&dyn_parms->__primary + 1));
        if (rc) goto quit;
    }

    /* secondary space */
    if (dyn_parms->__secondary > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALSECND, 1, 3,
                     (const char *)&dyn_parms->__secondary + 1));
        if (rc) goto quit;
    }

    /* directory blocks */
    if (dyn_parms->__dirblk > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALDIR, 1, 3,
                     (const char *)&dyn_parms->__dirblk + 1));
        if (rc) goto quit;
    }

    /* average block length */
    if (dyn_parms->__avgblk > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALBLKLN, 1, 3,
                     (const char *)&dyn_parms->__avgblk + 1));
        if (rc) goto quit;
    }

    /* record format */
    if (dyn_parms->__recfm > 0) {
        unsigned char recfm = (unsigned char)dyn_parms->__recfm;
        rc = arrayadd(&txt99,
            NewTXT99(DALRECFM, 1, 1, (const char *)&recfm));
        if (rc) goto quit;
    }

    /* block size */
    if (dyn_parms->__blksize > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALBLKSZ, 1, 2,
                     (const char *)&dyn_parms->__blksize));
        if (rc) goto quit;
    }

    /* logical record length */
    if (dyn_parms->__lrecl > 0) {
        rc = arrayadd(&txt99,
            NewTXT99(DALLRECL, 1, 2,
                     (const char *)&dyn_parms->__lrecl));
        if (rc) goto quit;
    }

    /* volume reference dsname */
    if (dyn_parms->__volrefds != NULL &&
        strlen(dyn_parms->__volrefds) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALVLRDS, 1,
                     strlen(dyn_parms->__volrefds),
                     dyn_parms->__volrefds));
        if (rc) goto quit;
    }

    /* DCB reference dsname */
    if (dyn_parms->__dcbrefds != NULL &&
        strlen(dyn_parms->__dcbrefds) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALDCBDS, 1,
                     strlen(dyn_parms->__dcbrefds),
                     dyn_parms->__dcbrefds));
        if (rc) goto quit;
    }

    /* DCB reference ddname */
    if (dyn_parms->__dcbrefdd != NULL &&
        strlen(dyn_parms->__dcbrefdd) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALDCBDD, 1,
                     strlen(dyn_parms->__dcbrefdd),
                     dyn_parms->__dcbrefdd));
        if (rc) goto quit;
    }

    /* misc flags */
    if (dyn_parms->__misc_flags & __CLOSE) {
        rc = arrayadd(&txt99, NewTXT99(DALCLOSE, 0, 0, NULL));
        if (rc) goto quit;
    }
    if (dyn_parms->__misc_flags & __RELEASE) {
        rc = arrayadd(&txt99, NewTXT99(DALRLSE, 0, 0, NULL));
        if (rc) goto quit;
    }
    if (dyn_parms->__misc_flags & __CONTIG) {
        rc = arrayadd(&txt99, NewTXT99(DALSPFRM, 0, 0, NULL));
        if (rc) goto quit;
    }
    if (dyn_parms->__misc_flags & __ROUND) {
        rc = arrayadd(&txt99, NewTXT99(DALROUND, 0, 0, NULL));
        if (rc) goto quit;
    }
    if (dyn_parms->__misc_flags & __TERM) {
        rc = arrayadd(&txt99, NewTXT99(DALTERM, 0, 0, NULL));
        if (rc) goto quit;
    }
    if (dyn_parms->__misc_flags & __DUMMY_DSN) {
        rc = arrayadd(&txt99, NewTXT99(DALDUMMY, 0, 0, NULL));
        if (rc) goto quit;
    }
    if (dyn_parms->__misc_flags & __HOLDQ) {
        rc = arrayadd(&txt99, NewTXT99(DALSHOLD, 0, 0, NULL));
        if (rc) goto quit;
    }
    if (dyn_parms->__misc_flags & __PERM) {
        rc = arrayadd(&txt99, NewTXT99(DALPERMA, 0, 0, NULL));
        if (rc) goto quit;
    }

    /* password */
    if (dyn_parms->__password != NULL &&
        strlen(dyn_parms->__password) > 0)
    {
        rc = arrayadd(&txt99,
            NewTXT99(DALPASSW, 1,
                     strlen(dyn_parms->__password),
                     dyn_parms->__password));
        if (rc) goto quit;
    }

    /* build request block and call SVC 99 */
    count = arraycount(&txt99);
    if (!count) {
        rc = -1;
        goto quit;
    }

    /* set high order bit to mark end of text unit pointer list */
    count--;
    txt99[count] = (TXT99 *)((unsigned)txt99[count] | 0x80000000);

    rb99.len     = sizeof(RB99);
    rb99.request = S99VRBAL;
    rb99.flag1   = S99NOCNV;
    rb99.txtptr  = txt99;

    rc = __svc99(&rb99);

    dyn_parms->__errcode  = rb99.error;
    dyn_parms->__infocode = rb99.info;

    if (rc == 0 || rc <= 4) {
        /* copy back returned DDNAME */
        if (retddn_idx >= 0) {
            memset(dyn_parms->__retddn, ' ', 8);
            dyn_parms->__retddn[8] = '\0';
            memcpy(dyn_parms->__retddn,
                   txt99[retddn_idx]->text,
                   txt99[retddn_idx]->size);
        }

        /* copy back returned DSNAME */
        if (retdsn_idx >= 0) {
            memset(dyn_parms->__retdsn, ' ', 43);
            dyn_parms->__retdsn[43] = '\0';
            memcpy(dyn_parms->__retdsn,
                   txt99[retdsn_idx]->text,
                   txt99[retdsn_idx]->size);
        }
    }

quit:
    if (txt99) FreeTXT99Array(&txt99);
    return rc;
}
