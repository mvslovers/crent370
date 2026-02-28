/* OSCHECK.C - wait for io completion */
#include "osio.h"
#include "clibstae.h"

static void check(DECB *decb);

int
oscheck(DECB *decb)
{
    int rc;

    /* we use try() to catch any abends */
    rc = try(check,decb);

    return rc;
}

static void
check(DECB *decb)
{
    __asm__(
         "LR    1,%0\n"
"         CHECK (1)"
        : : "r"(decb) : "0", "1", "14", "15");

    return;
}
