#include <stdio.h>
#include <string.h>
#include <clib.h>
#include <clibdsab.h>
#include <clibtiot.h>
#include <iezjscb.h>
#include <ieftiot.h>
#include <osjfcb.h>

int main(int argc, char **argv)
{
    int         rc      = 0;
    unsigned    *psa    = 0;                        /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    JSCB        *jscb   = (JSCB*)tcb[0xB4/4];   /* JSCB     == TCBJSCB  */
    void        **va;
    DSAB        *ds;
    int         i;

#if 0
    wtodumpf(jscb, sizeof(JSCB), "JSCB");

    wtodumpf(jscb->JSCDSABQ, 256, "JSCDSABQ");
    va = (void**)jscb->JSCDSABQ;
    
    for(i=0, ds = va[3]; ds && i < 100; ds = ds->dsabfchn, i++) {
        TIOTDD  *tiotdd = ds->dsabtiot;
        JFCB    *jfcb = (JFCB*)((tiotdd->TIOEJFCB[0]<<16 | tiotdd->TIOEJFCB[1]<<8 | tiotdd->TIOEJFCB[2]) + 16);
        
        wtof("---------------------------------------------------------");
        wtodumpf(ds, sizeof(DSAB), "DSAB[%d]", i);
        wtodumpf(tiotdd, sizeof(TIOTDD), "TIOTDD[%d]", i);
        wtodumpf(jfcb, sizeof(JFCB), "JFCB[%d]", i);
    }
#endif

    if (jscb) {
        TIOT    *tiot   = __tiot();
        TIOTDD  *tiotdd = (TIOTDD*)tiot->TIOTDD;
        
        for(i=0; i < 100; i++) {
            if (!tiotdd->TIOELNGH) break;
            wtof("---------------------------------------------------------");
            wtodumpf(tiotdd, tiotdd->TIOELNGH, "TIOTDD[%d]", i);
            tiotdd = (TIOTDD*)((unsigned)tiotdd + tiotdd->TIOELNGH);
        }
    }

    for(i=0, ds = get_dsab(NULL, NULL); ds; ds=next_dsab(ds, NULL, NULL), i++) {
        TIOTDD  *tiotdd = ds->dsabtiot;
        JFCB    *jfcb = (JFCB*)((tiotdd->TIOEJFCB[0]<<16 | tiotdd->TIOEJFCB[1]<<8 | tiotdd->TIOEJFCB[2]) + 16);
        
        wtof("---------------------------------------------------------");
        wtodumpf(ds, sizeof(DSAB), "DSAB[%d]", i);
        wtodumpf(tiotdd, sizeof(TIOTDD), "TIOTDD[%d]", i);
        wtodumpf(jfcb, sizeof(JFCB), "JFCB[%d]", i);
    }

quit:
    return rc;
}

