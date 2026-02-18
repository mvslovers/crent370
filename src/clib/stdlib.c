#define LIB_STDLIB
#define STDLIB_C
#include "stdlib.h"

static STDLIB   lib = {
    malloc,
    calloc,
    realloc,
    free,
    abort,
    exit,
    qsort,
    srand,
    rand,
    atof,
    strtod,
    atoi,
    atol,
    strtol,
    strtoul,
    getenv,
    bsearch,
};

STDLIB  *stdlib = &lib;
