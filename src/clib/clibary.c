#define LIB_CLIBARY
#define CLIBARY_C
#include "clibary.h"

#if 1
void *clibary = 0;
#else
/* deprecated */
static CLIBARY lib = {
    arraynew,
    arrayadd,
    arrayaddf,
    arraycount,
    arrayfree,
    arrayget,
    arraysize,
    arraydel,
};

CLIBARY     *clibary = &lib;
#endif
