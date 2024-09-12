/* ABORT.C */
#define STDLIB_C
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>

__PDPCLIB_API__ void abort(void)
{
    raise(SIGABRT);
    exit(EXIT_FAILURE);
}
