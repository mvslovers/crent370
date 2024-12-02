/* RESPRNTF.C */
#define STDIO_C
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "ctype.h"
#include "errno.h"
#include "float.h"
#include "limits.h"
#include "stddef.h"

#define outch(ch) *s++ = (char)ch

static int
examine(char *s, int n, const char **formt, va_list *arg);

#if 0   /* we've removed the double/floating point conversions */
extern void
__dblcvt(double num, char cnvtype, size_t nwidth, int nprecision, char *result);
#endif
int
vsnprintf(char *s, int n, const char *format, va_list arg)
{
    char        *sin        = s;
    int         fin         = 0;
    int         chcount     = 0;
    int         vint;
    double      vdbl;
    unsigned int uvint;
    const char  *vcptr;
    int         len;
    int         i;
    char        numbuf[50];
    char        *nptr;
    int         *viptr;

    while (!fin) {
        if (*format == '\0') {
            /* end of format string */
            fin = 1;
            goto next;
        }

        if (*format == '%') {
            /* format sequence */
            format++;
            if (*format == 'd') {
                /* format signed int */
                vint = va_arg(arg, int);
                if (vint < 0) {
                    uvint = -vint;
                }
                else {
                    uvint = vint;
                }

                nptr = numbuf;
                do {
                    *nptr++ = (char)('0' + uvint % 10);
                    uvint /= 10;
                } while (uvint > 0);

                if (vint < 0) {
                    *nptr++ = '-';
                }

                do {
                    nptr--;
                    if (chcount < n) outch(*nptr);
                    chcount++;
                } while (nptr != numbuf);
            }
#if 0
            else if (strchr("eEgGfF", *format) != NULL && *format != 0)  {
                /* format floating point */
                vdbl = va_arg(arg, double);
                __dblcvt(vdbl, *format, 0, 6, numbuf);   /* 'e','f' etc. */
                len = strlen(numbuf);

                for(i=0; i < len; i++) {
                    if (chcount < n) outch(numbuf[i]);
                    chcount++;
                }
            }
#endif
            else if (*format == 's') {
                /* format string */
                vcptr = va_arg(arg, const char *);

                if (vcptr == NULL) {
                    vcptr = "(null)";
                }

                len = strlen(vcptr);
                for(i=0; i < len; i++) {
                    if (chcount < n) outch(vcptr[i]);
                    chcount++;
                }
            }
            else if (*format == 'c') {
                /* format character */
                vint = va_arg(arg, int);
                if (chcount < n) outch(vint);
                chcount++;
            }
            else if (*format == 'n') {
                /* format number of character output so far */
                viptr = va_arg(arg, int *);
                *viptr = chcount;
            }
            else if (*format == '%') {
                /* format escape character % */
                if (chcount < n) outch('%');
                chcount++;
            }
            else  {
                /* any other format sequence */
                int extraCh;

                extraCh = n-chcount;
                if (extraCh < 0) extraCh = 0;
                extraCh = examine(s, extraCh, &format, &arg);
                if (s!=NULL) {
                    for(i=0; i < extraCh; i++) {
                        if (chcount < n) s++;
                        chcount++;
                    }
                }
                else {
                    chcount += extraCh;
                }
            }
            goto next;
        }

        /* default, output next character */
        if (chcount < n) outch(*format);
        chcount++;

next:
        format++;
    }

    if (chcount < n) outch(0);

    return (chcount);
}

static int
examine(char *s, int n, const char **formt, va_list *arg)
{
    int         extraCh     = 0;
    int         flagMinus   = 0;
    int         flagPlus    = 0;
    int         flagSpace   = 0;
    int         flagHash    = 0;
    int         flagZero    = 0;
    int         width       = 0;
    int         precision   = -1;
    int         half        = 0;
    int         lng         = 0;
    int         specifier   = 0;
    int         fin;
    long        lvalue;
    short int   hvalue;
    int         ivalue;
    unsigned long ulvalue;
    double      vdbl;
    char        *svalue;
    char        work[50];
    int         x;
    int         y;
    int         i;
    int         rem;
    const char  *format;
    int         base;
    int         fillCh;
    int         neg;
    int         length;
    size_t      slen;

    format = *formt;

    /* processing flags */
    fin = 0;
    while (!fin) {
        switch (*format) {
            case '-': flagMinus = 1;
                      break;
            case '+': flagPlus = 1;
                      break;
            case ' ': flagSpace = 1;
                      break;
            case '#': flagHash = 1;
                      break;
            case '0': flagZero = 1;
                      break;
            case '*': width = va_arg(*arg, int);
                      if (width < 0)
                      {
                          flagMinus = 1;
                          width = -width;
                      }
                      break;
            default:  fin = 1;
                      break;
        }

        if (!fin) {
            format++;
        }
        else {
            if (flagSpace && flagPlus) {
                flagSpace = 0;
            }
            if (flagMinus) {
                flagZero = 0;
            }
        }
    }

    /* processing width */
    if (isdigit((unsigned char)*format)) {
        while (isdigit((unsigned char)*format)) {
            width = width * 10 + (*format - '0');
            format++;
        }
    }

    /* processing precision */
    if (*format == '.') {
        format++;
        if (*format == '*') {
            precision = va_arg(*arg, int);
            format++;
        }
        else {
            precision = 0;
            while (isdigit((unsigned char)*format)) {
                precision = precision * 10 + (*format - '0');
                format++;
            }
        }
    }

    /* processing h/l/L */
    if (*format == 'h') {
        /* all environments should promote shorts to ints,
           so we should be able to ignore the 'h' specifier.
           It will create problems otherwise. */
        /* half = 1; */
    }
    else if (*format == 'l') {
        lng = 1;
    }
    else if (*format == 'L') {
        lng = 1;
    }
    else {
        format--;
    }
    format++;

    /* processing specifier */
    specifier = *format;

    if (strchr("dxXuiop", specifier) != NULL && specifier != 0) {
        if (precision < 0) {
            precision = 1;
        }

        if (lng) {
            lvalue = va_arg(*arg, long);
        }
        else if (half) {
            /* short is promoted to int, so use int */
            hvalue = va_arg(*arg, int);
            if (specifier == 'u') lvalue = (unsigned short)hvalue;
            else lvalue = hvalue;
        }
        else {
            ivalue = va_arg(*arg, int);
            if (specifier == 'u') lvalue = (unsigned int)ivalue;
            else lvalue = ivalue;
        }

        ulvalue = (unsigned long)lvalue;
        if ((lvalue < 0) && ((specifier == 'd') || (specifier == 'i'))) {
            neg = 1;
            ulvalue = -lvalue;
        }
        else {
            neg = 0;
        }

        if ((specifier == 'X') || (specifier == 'x') || (specifier == 'p')) {
            base = 16;
        }
        else if (specifier == 'o') {
            base = 8;
        }
        else {
            base = 10;
        }

        if (specifier == 'p') {
            precision = 8;
        }

        x = 0;
        while (ulvalue > 0) {
            rem = (int)(ulvalue % base);
            if (rem < 10) {
                work[x] = (char)('0' + rem);
            }
            else {
                if ((specifier == 'X') || (specifier == 'p')) {
                    work[x] = (char)('A' + (rem - 10));
                }
                else {
                    work[x] = (char)('a' + (rem - 10));
                }
            }
            x++;
            ulvalue = ulvalue / base;
        }

        while (x < precision) {
            work[x] = '0';
            x++;
        }

        if (neg) {
            work[x++] = '-';
        }
        else if (flagPlus) {
            work[x++] = '+';
        }

        if (flagZero) {
            fillCh = '0';
        }
        else {
            fillCh = ' ';
        }

        y = x;
        if (!flagMinus) {
            while (y < width) {
                if (extraCh < n) outch(fillCh);
                extraCh++;
                y++;
            }
        }

        if (flagHash && ((unsigned char)specifier == 'X' ||
            (unsigned char)specifier == 'x')) {
            if (extraCh < n) outch('0');
            extraCh++;
            if (extraCh < n) outch('x');
            extraCh++;
        }

        x--;
        while (x >= 0) {
            if (extraCh < n) outch(work[x]);
            extraCh++;
            x--;
        }

        if (flagMinus) {
            while (y < width) {
                if (extraCh < n) outch(fillCh);
                extraCh++;
                y++;
            }
        }
    }
#if 0
    else if (strchr("eEgGfF", specifier) != NULL && specifier != 0) {
        if (precision < 0) {
            precision = 6;
        }

        vdbl = va_arg(*arg, double);
        __dblcvt(vdbl, specifier, width, precision, work);   /* 'e','f' etc. */
        slen = strlen(work);

        for(i=0; i < slen; i++) {
            if (extraCh < n) outch(work[i]);
            extraCh++;
        }
    }
#endif
    else if (specifier == 's') {
        svalue = va_arg(*arg, char *);
        fillCh = ' ';
        if (precision > 0) {
            char *p;

            p = memchr(svalue, '\0', precision);
            if (p != NULL) {
                length = (int)(p - svalue);
            }
            else  {
                length = precision;
            }
        }
        else if (precision < 0) {
            length = strlen(svalue);
        }
        else {
            length = 0;
        }

        if (!flagMinus) {
            if (length < width) {
                extraCh += (width - length);
                for (x = 0; x < (width - length); x++) {
                    if (extraCh < n) outch(fillCh);
                }
            }
        }

        for (x = 0; x < length; x++) {
            if (extraCh < n) outch(svalue[x]);
        }

        extraCh += length;
        if (flagMinus) {
            if (length < width) {
                for (x = 0; x < (width - length); x++) {
                    if (extraCh < n) outch(fillCh);
                        extraCh++;
                }
            }
        }
    }

    *formt = format;
    return (extraCh);
}
