#include <clibos.h>

int __bldl(BLDL *bldl, void *dcb)
{
    int         rc  = 0;

    if (!bldl->ff)  bldl->ff    = 1;
    if (!bldl->ll)  bldl->ll    = sizeof(DE76);

    __asm__("BLDL\t(%1),(%2)\n\t"
            "LR\t%0,R15" : "=r"(rc) : "r"(dcb), "r"(bldl) : "0", "1", "14", "15");

    return rc;
}
