#include <clibos.h>

int main(int argc, char **argv)
{
    const char  *name   = "TESTPRTF";
    void        *epa;
    void        *lpa    = 0;
    unsigned    size    = 0;
    char        reply[16] = {0};

    clib_apf_setup(argv[0]);

    super_key_do(PSWKEY8, __loadhi, name, &lpa, &epa, &size);

    wtof("%s %s LPA(%08X), EPA(%08X) SIZE(%u)", __func__, name, lpa, epa, size);
#if 0
    if (lpa) {
        wtodumpf(lpa, size, "%s LPA", __func__);
    }
#endif
    if (epa) {
        wtof("%s calling %s", __func__, name);
        __asm__ __volatile__ ("\n*** CALL MODULE ***\n\t"
            "LR\tR15,%0\n\t"
            "BALR\tR14,R15"
            : : "r"(epa) : "14", "15");
    }

    wtorf(reply, sizeof(reply)-1, "%s continue?", __func__);
    wtof("%s reply was \"%s\"", __func__, reply);

    /* since we're only testing, we need to free the CSA storage */
    if (lpa) super_key_do(PSWKEY8, freemain, lpa);

    return 0;
}
