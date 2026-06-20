/* @@RENMEM.C - rename a PDS member via STOW (change) */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "osio.h"
#include "clibio.h"
#include "clibos.h"

/*
 * __renmem() - rename member 'oldmem' to 'newmem' in PDS 'dsn'.
 *
 * Uses STOW change, so the member's TTR and directory user data (ISPF
 * statistics) are preserved and no data is copied - this works for every
 * record format including RECFM=U load modules.
 *
 * Returns:
 *    0  success
 *   >0  STOW return code (register 15), typically:
 *          4  the new name already exists in the directory
 *          8  the old name was not found in the directory
 *         12  permanent I/O error
 *         16  no space left in the directory
 *         20  insufficient virtual storage
 *   -1  invalid parameters or out of memory
 *   -2  the data set could not be allocated (not found or in use)
 *   -3  the data set could not be opened
 */
int
__renmem(const char *dsn, const char *oldmem, const char *newmem)
{
    int   rc        = -1;
    DCB   *dcb      = NULL;
    char  ddname[9] = {0};
    char  area[16];
    int   i;

    if (!dsn || !oldmem || !newmem) goto quit;
    if (*oldmem <= ' ' || *newmem <= ' ') goto quit;

    /* allocate the PDS DISP=SHR so we may update its directory */
    if (__dsalcf(ddname, "DSN=%s;DISP=SHR", dsn)) {
        rc = -2;
        goto quit;
    }

    /* build a BSAM/BPAM DCB for the DD */
    dcb = osbdcb(ddname, NULL);
    if (!dcb) {
        rc = -1;
        goto dealloc;
    }

    /* force partitioned organisation: opening a PDS for OUTPUT with
     * DSORG=PO updates the directory without erasing members, whereas
     * DSORG=PS OUTPUT would reset the data set */
    dcb->dcbdsrg1 = DCBDSGPO;
    dcb->dcbdsrg2 = 0;

    /* open for OUTPUT - STOW requires the data set open for output/update */
    if (osbopen(dcb, 0, "write")) {
        rc = -3;
        goto close;
    }

    /* build the 16-byte STOW change list: old name (8) + new name (8),
     * upper-cased and blank padded */
    memset(area, ' ', sizeof(area));
    for (i = 0; i < 8 && oldmem[i] > ' '; i++) {
        area[i] = toupper((unsigned char)oldmem[i]);
    }
    for (i = 0; i < 8 && newmem[i] > ' '; i++) {
        area[8 + i] = toupper((unsigned char)newmem[i]);
    }

    /* rename the directory entry (STOW change) */
    rc = __stow(dcb, area, 'C');

close:
    osbclose(dcb, NULL, 1, 0);  /* close and free the DCB */
    dcb = NULL;
dealloc:
    __dsfree(ddname);
quit:
    return rc;
}
