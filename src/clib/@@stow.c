/* @@STOW.C - STOW (SVC 21) wrapper for PDS directory maintenance */
#include <clibos.h>

/*
 * __stow() - update a partitioned data set directory entry.
 *
 * The DCB must be open for OUTPUT or UPDAT against a DSORG=PO data set.
 * The directory action is selected by 'func':
 *
 *   'A' add      - area = 8-byte name + 3-byte TTR + 1-byte count + user data
 *   'R' replace  - area = same layout as add
 *   'D' delete   - area = 8-byte name
 *   'C' change   - area = 8-byte old name + 8-byte new name (16 bytes);
 *                  repoints the directory entry, preserving the member's
 *                  TTR and user data (ISPF statistics)
 *
 * Returns the STOW return code in register 15 (0 on success, non-zero
 * otherwise - see the STOW documentation), or -1 for an unknown function.
 *
 * The assembler STOW macro encodes the function and SVC linkage, so the
 * register conventions are handled the same way __bldl() wraps BLDL.
 */
int
__stow(void *dcb, void *area, int func)
{
    int rc = -1;

    switch (func) {
    case 'A': case 'a':
        __asm__("STOW\t(%1),(%2),A\n\t"
                "LR\t%0,R15"
                : "=r"(rc) : "r"(dcb), "r"(area) : "0", "1", "14", "15");
        break;
    case 'R': case 'r':
        __asm__("STOW\t(%1),(%2),R\n\t"
                "LR\t%0,R15"
                : "=r"(rc) : "r"(dcb), "r"(area) : "0", "1", "14", "15");
        break;
    case 'D': case 'd':
        __asm__("STOW\t(%1),(%2),D\n\t"
                "LR\t%0,R15"
                : "=r"(rc) : "r"(dcb), "r"(area) : "0", "1", "14", "15");
        break;
    case 'C': case 'c':
        __asm__("STOW\t(%1),(%2),C\n\t"
                "LR\t%0,R15"
                : "=r"(rc) : "r"(dcb), "r"(area) : "0", "1", "14", "15");
        break;
    }

    return rc;
}
