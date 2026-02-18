#include <clibos.h>
#include <clibwto.h>

/* __xmpost() POST ECB with postcode in address space for ascb */
void __xmpost(void *ascb, void *ecb, unsigned postcode)
{
    if (!ascb) {
        wtof("%s missing ASCB", __func__);
        return;
    }
    if (!ecb) {
        wtof("%s missing ECB", __func__);
        return;
    }
    ecb = (void*)((unsigned)ecb | 0x80000000);  /* need hi bit on */
    postcode = (postcode | 0x40000000) & 0x7FFFFFFF;

__asm__( "DS    0H\n"
"         STM   14,12,12(13)    save registers\n"
"         LR    9,13            only register preserved after XM POST\n"
"         LR    10,%2           POST COMPLETION CODE\n"
"         LR    11,%1           ECB ADDRESS\n"
"         LA    12,POSTERR      ERROR ROUTINE\n"
"         LR    13,%0           ASCB ADDRESS\n"
"         L     15,CVTPTR       CVT ADDRESS\n"
"         L     15,CVT0PT01-CVTMAP(,15)   POST BRANCH-ENTRY\n"
"         BALR  14,15\n"
"         LR    13,9            restore save area pointer\n"
"         LM    14,12,12(13)    restore registers\n"
"         B     DONE\n"
"POSTERR  DS    0H\n"
"         BR    14\n"
"DONE     DS    0H" : : "r"(ascb), "r"(ecb), "r"(postcode) );


}

__asm__("IHAPSA ,");
__asm__("CVT DSECT=YES,LIST=YES");
