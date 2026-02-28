/* OSXWRITE.C - write one block to dataset by block number */
#include "osio.h"

int
osxwrite(DCB *dcb, unsigned blkstrk, unsigned block, void *buf, char *sense)
{
    unsigned    ccws[6] = {0};      /* clear to zeros                   */
    IOB         iob     = {0};      /* cleared to zeros                 */
    unsigned    ecb     = 0;        /* event control block              */
    int         rc;

    /* build CCW for seek */
    ccws[0] = 0x31000000 | (unsigned)&iob.iobcc;
    ccws[1] = 0x40000005;

    /* build CCW for transfer-in-channel */
    ccws[2] = 0x08000000 | (unsigned)&ccws[0];
    ccws[3] = 0x40000000;

    /* build CCW for write */
    ccws[4] = 0x05000000 | (unsigned)buf;
    ccws[5] = (unsigned) dcb->dcbblksi;

    /* create mbbcchhr for this block as our seek address */
    rc = osxcalc(dcb, blkstrk, block, iob.iobseek);
    if (rc < 0) {
        /* that's not good! */
        iob.iobsens1 = SENSE1_NOT_FOUND;    /* simulate not found       */
        goto quit;
    }

    /* set IOB flags for this request */
    iob.iobflag1    = IOBCMDCH |    /* command chaining in CCW          */
                      IOBUNREL |    /* unrelated i/o, non-sequential    */
                      IOBRSTRT;     /* restart address in iob           */

    /* add ECB address to IOB */
    iob.iobecbpt = &ecb;

    /* add CCW address to IOB */
    iob.iobstart = &ccws;

    /* add DCB address to IOB */
    iob.iobdcbpt = dcb;

    /* give IOB to EXCP processor SVC 0 */
    __asm__("EXCP (%0)" : : "r"(&iob.iobflag1) : "1", "14", "15");

    /* wait for I/O completion */
    __asm__("WAIT 1,ECB=(%0)" : : "r"(&ecb) : "1", "14", "15");

    /* put completion code in rc */
    rc = (int) (ecb >> 24);
    if (rc==0x7F) {
        /* normal completion, make rc zero */
        rc = 0;
    }

quit:
    if (sense) {
        sense[0] = iob.iobsens0;
        sense[1] = iob.iobsens1;
    }
    return rc;
}
