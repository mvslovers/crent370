/* STRTOD.C */
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

__PDPCLIB_API__ double strtod(const char *nptr, char **endptr)
{
    double x = 0.0;
    double xs= 1.0;
    double es = 1.0;
    double xf = 0.0;
    double xd = 1.0;

    while( isspace( (unsigned char)*nptr ) ) ++nptr;
    if(*nptr == '-') {
        xs = -1;
        nptr++;
    }
    else if(*nptr == '+') {
        nptr++;
    }


    while (1) {
        if (isdigit((unsigned char)*nptr)) {
            x = x * 10 + (*nptr - '0');
            nptr++;
        }
        else {
            x = x * xs;
            break;
        }
    }

    if (*nptr == '.') {
        nptr++;
        while (1) {
            if (isdigit((unsigned char)*nptr)) {
                xf = xf * 10 + (*nptr - '0');
                xd = xd * 10;
            }
            else {
                x = x + xs * (xf / xd);
                break;
            }
            nptr++;
        }
    }

    if ((*nptr == 'e') || (*nptr == 'E')) {
        nptr++;
        if (*nptr == '-') {
            es = -1;
            nptr++;
        }
        xd = 1;
        xf = 0;
        while (1) {
            if (isdigit((unsigned char)*nptr)) {
                xf = xf * 10 + (*nptr - '0');
                nptr++;
            }
            else {
                while (xf > 0) {
                    xd *= 10;
                    xf--;
                }
                if (es < 0.0) {
                    x = x / xd;
                }
                else {
                    x = x * xd;
                }
                break;
            }
        }
    }

    if (endptr) {
        *endptr = (char *)nptr;
    }

    return (x);
}
