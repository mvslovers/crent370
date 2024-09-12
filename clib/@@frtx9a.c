/* @@FRTX9A.C */
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "svc99.h"
#include "clibary.h"

void
__frtx9a(TXT99 ***txt99)
{
    if (txt99 && *txt99) {
        TXT99       **p     = *txt99;
        unsigned    count   = arraycount(&p);
        unsigned    n;

        for( n=0; n < count; n++ ) {
            FreeTXT99(&p[n]);
        }
        arrayfree(txt99);
    }
}
