#include <stdio.h>
#include <string.h>
#include <clib.h>
#include <clibdsab.h>
#include <iezjscb.h>
#include <ieftiot.h>
#include <ikjtcb.h>
#include <osjfcb.h>

DSAB *get_dsab(void *tcbptr, const char *ddname)
{
    unsigned    *psa    = 0;                        /* low core == PSA      */
    TCB         *tcb;
    JSCB        *jscb;
    void        **va;
    DSAB        *dsab;
    char        tempname[8];
    int         i;

    if (!tcbptr) {
        /* Use TCB for this task */
        tcb = (TCB*)((unsigned*)psa[0x21c/4]);
    }
    else {
        tcb = tcbptr;
    }
    jscb = tcb->tcbjscb;
    /* we don't know the format of the JSCB QDB so we're using a 
     * void array to pick out the DSAB forward pointer from JSCDSABQ.
    */
    va   = (void**)jscb->JSCDSABQ;
    dsab = va[3];    /* first DSAB for this JSCB */

    /* no ddname? return first DSAB for this JSCB */
    if (!ddname) goto quit;
    if (ddname[0]==' ' | ddname[0]==0) goto quit;

    /* we're going to match ddname and find the first DSAB that matches */
    for(i=0; ddname[i] && i < sizeof(tempname); i++) {
        tempname[i] = toupper(ddname[i]);
    }
    for( ; i < sizeof(tempname); i++) {
        tempname[i] = ' ';
    }
    
    for( ; dsab ; dsab = dsab->dsabfchn) {
        TIOTDD  *tiotdd = dsab->dsabtiot;

        /* just to make sure we don't go completely off the rails */
        if (memcmp(dsab->dsabid, "DSAB", 4) != 0) {
            /* bad eye catcher, return NULL */
            dsab = NULL;
            break;
        }

        /* match the TIOT DD Name with the tempname (from the ddname parm) */
        if (memcmp(tiotdd->TIOEDDNM, tempname, sizeof(tiotdd->TIOEDDNM))==0) {
            /* we found the ddname, return the DSAB */
            break;
        }
    }

quit:
    return dsab;
}
