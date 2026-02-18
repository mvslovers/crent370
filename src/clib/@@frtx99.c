/* @@FRTX99.C */
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "svc99.h"

void
__frtx99(TXT99 **txt99)
{
    if (txt99 && *txt99) {
        free(*txt99);
        *txt99 = NULL;
    }
}
