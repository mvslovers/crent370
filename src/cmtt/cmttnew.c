#include <cvt.h>
#include <ieebasea.h>   /* Master Scheduler Base, BASE */
#include <ieezb806.h>   /* MTTABLE, MTENTRY */
#include <clibmtt.h>
#include <clibos.h>
#include <clibauth.h>

CMTT *cmtt_new(void)
{
    unsigned        *psa        = (unsigned *)0;
    CVT             *cvt        = (CVT*) psa[0x10/4];
    BASE            *base       = (BASE*) cvt->cvtmser;
    CMTT            *cmtt       = (CMTT*)0;
    int             dyn_auth    = 0;
    int             was_sup     = 0;
    int             rc;
    unsigned char   caller_key;
    MTTABLE         *mttable;
    MTENTRY         *mtentry;
    unsigned        size;
    unsigned        offset;

    // wtof("%s: ENTER", __func__);

    rc = __pswkey(&caller_key);
    // wtof("%s: __pswkey() rc=%d caller_key=%02X", __func__, rc, caller_key);
    if (rc) {
        /* not APF authorized */
        rc = __autask();
        // wtof("%s: __autask() rc=%d", __func__, rc);
        if (rc) goto quit;

        /* remember that we athorized this task */
        dyn_auth = 1;
        
        /* get caller key */
        rc = __pswkey(&caller_key);
        // wtof("%s: __pswkey() rc=%d caller_key=%02X", __func__, rc, caller_key);
    }

    if (__issup()) {
        /* remember we entered in supervisor state */
        was_sup = 1;
    }
    // wtof("%s: __issup() rc=%d", __func__, was_sup);

    /* switch to supervisor state key 0 */
    __super(PSWKEY0, NULL);

    /* get size of master trace table */
    mttable = (MTTABLE*) base->bamttbl;
    size    = mttable->mttsize & 0x00FFFFFF;

    /* Note: We need to do our calloc() calls in problem mode
     * so that the underlying GETMAIN will allocate storage
     * in the correct subpool.
     */

    /* get into KEY 8 */
    __prob(PSWKEY8, NULL);

    /* allocate CMTT handle */
    cmtt = (CMTT*) calloc(1, sizeof(CMTT));
    if (!cmtt) goto quit;
    
    /* initialize CMTT handle */
    strcpy(cmtt->eye, CMTT_EYE);

    /* allocate copy of master trace table */
    cmtt->mttable = (MTTABLE *) calloc(1, size);
    if (!cmtt->mttable) {
        /* no memory, fail request */
        free(cmtt);
        cmtt = (CMTT*)0;
        goto quit;
    }

    /* swicth to supervisor state key 0 and copy trace table */
    __super(PSWKEY0, NULL);

    memcpy(cmtt->mttable, mttable, size);
    // wtodumpf(cmtt->mttable, sizeof(MTTABLE), "cmtt->mttable copy");
    
    /* fixup the pointers in the cmtt->mttable */
    offset = ((unsigned)mttable->mttcurpt - (unsigned)mttable);
    cmtt->mttable->mttcurpt = (MTENTRY*)((unsigned)cmtt->mttable + offset);
    
    offset = (mttable->mttentpt - (unsigned)mttable);
    cmtt->mttable->mttentpt = (unsigned)cmtt->mttable + offset;
    
    offset = (mttable->mttendpt - (unsigned)mttable);
    cmtt->mttable->mttendpt = (unsigned)cmtt->mttable + offset;

    cmtt->mttable->mttsp = 0;

    offset = ((unsigned)mttable->mttwrppt - (unsigned)mttable);
    cmtt->mttable->mttwrppt = (MTENTRY*)((unsigned)cmtt->mttable + offset);

    /* switch to problem mode key 8 */
    __prob(PSWKEY8, NULL);

    /* clear unused areas in our copy of the master trace table */
    mttable = cmtt->mttable;
    mttable->mttpflag   = 0;
    mttable->mttrsvd1   = 0;
    memset(mttable->mttwk808, 0, sizeof(mttable->mttwk808));
    memset(mttable->mttrsvd2, 0, sizeof(mttable->mttrsvd2));

    // wtodumpf(cmtt->mttable, sizeof(MTTABLE), "cmtt->mttable fixed");

    rc = 0;

quit:
    if (was_sup) {
        // wtof("%s:quit calling __super()", __func__);
        __super(caller_key, NULL);
    }
    else {
        // wtof("%s:quit calling __prob()", __func__);
        __prob(caller_key, NULL);
    }
    
    if (dyn_auth) {
        // wtof("%s:quit calling __uatask()", __func__);
        __uatask();
    }

    // wtof("%s: EXIT %p", __func__, cmtt);
    return cmtt;
}
