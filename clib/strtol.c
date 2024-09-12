/* STRTOL.C */
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

__PDPCLIB_API__ long int strtol(const char *nptr, char **endptr, int base)
{
    unsigned long y;
    long x;
    int neg = 0;

    while (isspace((unsigned char)*nptr)) {
        nptr++;
    }

    if (*nptr == '-') {
        neg = 1;
        nptr++;
    }
    else if (*nptr == '+') {
        nptr++;
    }

    y = strtoul(nptr, endptr, base);
    if (neg) {
        x = (long)-y;
    }
    else {
        x = (long)y;
    }

    return (x);
}
