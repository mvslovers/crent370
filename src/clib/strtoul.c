/* STRTOUL.C */
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

/* this logic is also in vvscanf - if you update this, update
   that one too */

__PDPCLIB_API__ unsigned long int strtoul(
    const char *nptr, char **endptr, int base)
{
    unsigned long x = 0;
    int undecided = 0;

    if (base == 0) {
        undecided = 1;
    }

    while (isspace((unsigned char)*nptr)) {
        nptr++;
    }

    while (1) {
        if (isdigit((unsigned char)*nptr)) {
            if (base == 0) {
                if (*nptr == '0') {
                    base = 8;
                }
                else {
                    base = 10;
                    undecided = 0;
                }
            }
            x = x * base + (*nptr - '0');
            nptr++;
        }
        else if (isalpha((unsigned char)*nptr)) {
            if ((*nptr == 'X') || (*nptr == 'x')) {
                if ((base == 0) || ((base == 8) && undecided)) {
                    base = 16;
                    undecided = 0;
                    nptr++;
                }
                else if (base == 16) {
                    /* hex values are allowed to have an optional 0x */
                    nptr++;
                }
                else {
                    break;
                }
            }
            else if (base <= 10) {
                break;
            }
            else {
                x = x * base + (toupper((unsigned char)*nptr) - 'A') + 10;
                nptr++;
            }
        }
        else {
            break;
        }
    }

    if (endptr != NULL) {
        *endptr = (char *)nptr;
    }
    return (x);
}
