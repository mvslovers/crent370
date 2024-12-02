#include <clibtmr.h>

int main(int argc, char **argv)
{
    TMR     *tmr;
    TQEID   id;
    TQEID   every;
    int     i;
    ECB     ecb;

    wtof("%s %s Timer Test", __func__, argv[0]);

    tmr = tmr_get();
    wtof("%s TMR=%08X", __func__, tmr);

    /* timer with timer purged after timeout test */
    for(i=50; i < 60; i++) {
        ecb = 0;
        id = tmr_ecb(&ecb, i);
        wtof("%s TQEID(%08X) BINTVL(%u)", __func__, id, i);
        ecb_wait(&ecb);
        wtof("%s TQEID(%08X) ECB(%08X)", __func__, id, ecb);
    }

    /* recurring timer for every interval test */
    ecb = 0;
    every = tmr_ecb_every(&ecb, 5); /* 5 = .05 seconds */
    wtof("%s tmr_ecb_every(%08X, 5) ID(%u)", __func__, &ecb, every);

    for(i=0; i < 100; i++) {
        ecb = 0;
        ecb_wait(&ecb);
        wtof("%s POSTED ECB(%08X)", __func__, ecb);
    }

    /* remove the TQE for the "every" TQE */
    i = tqe_purge(every);
    wtof("%s tqe_purge(%08X) RC(%d)", __func__, every, i);

    return 0;
}
