#include <clibos.h>
#include <ctype.h>

__asm__("\n&FUNC    SETC '__load'");
void *__load(void *dcb, const char *module, unsigned *size, char *ac)
{
    void        *epa        = 0;
    unsigned    work        = 0;
    BLDL        bldl        = {0};
    int         rc;
    int         i;

    if (!module || *module <= ' ') goto quit;

    /* prepare BLDL area */
    for(i=0; i < sizeof(bldl.de76[0].name); i++) {
        if (*module) {
            bldl.de76[0].name[i] = toupper(*module);
            module++;
        }
        else {
            bldl.de76[0].name[i] = ' ';
        }
    }

    /* find module in dcb */
    rc = __bldl(&bldl, dcb);
#if 0
    wtof("%s __bldl() rc=%d", __func__, rc);
    wtodumpf(&bldl, sizeof(BLDL), "%s BLDL", __func__);
#endif
    if (rc) goto quit;

    /* load module into memory */
__asm__( "LOAD DE=(%2),DCB=(%3),ERRET=LOADFAIL\n\t"
         "LR\t%0,0          Success, save EPA\n\t"
         "LR\t%1,1          Success, save AC and Size\n\t"
         "B\tLOADDONE\n"
"LOADFAIL DS\t0H\n\t"
         "XR\t%0,%0         Failed, no EPA\n\t"
         "XR\t%1,%1         Failed, no AC or Size\n"
"LOADDONE DS\t0H"
        : "=r"(epa), "=r"(work) : "r"(bldl.de76), "r"(dcb) : "0", "1", "14", "15");

    /* did we load okay? */
    if (epa) {
        /* yes, return additional info */
        if (size) *size = (work & 0x00FFFFFF) << 3;  /* convert double words to bytes */
        if (ac)   *ac   = (work >> 24);
    }

quit:
    return epa;
}

#if 0
int main(int argc, char **argv)
{
    const char  *name   = "SVCMAIN";
    void        *epa;
    void        *lpa    = 0;
    unsigned    size    = 0;
    char        ac      = 0;
    void        *dcb    = 0;
    CDE         *cde;

    /* get the steplib DCB */
    dcb = __steplb();
    wtof("%s STEPLIB %08X", __func__, dcb);

    wtof("%s LOAD %s", __func__, name);
    epa = __load(dcb, name, &size, &ac);
    wtof("%s epa        %08X", __func__, epa);
    if (epa) {
        wtof("%s size       %u bytes", __func__, size);
        wtof("%s ac         %02X", __func__, ac);

        cde = clib_find_cde(name);
        wtof("%s CDE %08X", __func__, cde);
        if (cde) {
            wtodumpf(cde, sizeof(CDE), "CDE");
            wtodumpf(cde->xtlst, sizeof(XTLST), "XTLST");
            size = cde->xtlst->xtlmsbla & 0x00FFFFFF;
            lpa  = cde->xtlst->xtlmsbaa & 0x00FFFFFF;
        }

        if (lpa) {
            wtodumpf(lpa, size, "LOAD POINT ADDRESS");
        }
        else {
            wtodumpf(epa, size, "ENTRY POINT ADDRESS");
        }
    }

    return 0;
}
#endif
