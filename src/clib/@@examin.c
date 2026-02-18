/* @@EXAMIN.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <mvssupa.h>
#include <clib64.h>

#define unused(x) ((void)(x))
#define outch(ch) ((fq == NULL) ? *s++ = (char)ch : putc(ch, fq))
#define inch() ((fp == NULL) ? \
    (ch = (unsigned char)*s++) : (ch = getc(fp)))

static const char DIGITS[] = "0123456789ABCDEF";
static const char digits[] = "0123456789abcdef";

extern void
__dblcvt(double num, char cnvtype, size_t nwidth, int nprecision, char *result);

int
__examin(const char **formt, FILE *fq, char *s, va_list *arg, int chcount)
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
    short       hvalue;
    int         ivalue;
    unsigned    ulvalue;
    double      vdbl;
    char        *svalue;
    char        work[80];
    int         x;
    int         y;
    int         rem;
    const char  *format;
    int         base;
    int         fillCh;
    int         neg;
    int         length;
    size_t      slen;
	/* support for long long (64 bit values ) */
	__64		value64;
	__64		rem64;
	__64		div64;
	__64		base64;

    unused(chcount);
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
		if (*(format+1) == 'l') {
			lng = 2;
			format++;
		}
    }
    else if (*format == 'L') {
        lng = 1;
		if (*(format+1) == 'L') {
			lng = 2;
			format++;
		}
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
        
        if (lng==1) {
            lvalue = va_arg(*arg, long);
        }
		else if (lng==2) {
			lvalue = va_arg(*arg, long);
			value64.u32[0] = (uint32_t)lvalue;
			lvalue = va_arg(*arg, long);
			value64.u32[1] = (uint32_t)lvalue;
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
        if (lng==2) {
			/* 64 bit variables */
			__64_from_i32(&base64, base);
			neg = 0;	/* __64 values are unsigned */
			while (!(__64_is_zero(&value64))) {
				__64_divmod(&value64, &base64, &div64, &rem64);
				rem = __64_to_i32(&rem64);

				if ((specifier == 'X') || (specifier == 'p')) {
					work[x] = DIGITS[rem];	/* uppercase digits */
				}
				else {
					work[x] = digits[rem];	/* lowercase digits */
				}
				x++;
				__64_copy(&div64, &value64);
			}
		}
		else {
			/* 32 bit variables */
			while (ulvalue > 0) {
				rem = (int)(ulvalue % base);
				if ((specifier == 'X') || (specifier == 'p')) {
					work[x] = DIGITS[rem];	/* uppercase digits */
				}
				else {
					work[x] = digits[rem];	/* lowercase digits */
				}
				x++;
				ulvalue = ulvalue / base;
			}
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
        else if (flagSpace) {
            work[x++] = ' ';
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
                outch(fillCh);
                extraCh++;
                y++;
            }
        }

        if (flagHash && (toupper((unsigned char)specifier) == 'X')) {
            outch('0');
            outch('x');
            extraCh += 2;
        }

        x--;
        while (x >= 0) {
            outch(work[x]);
            extraCh++;
            x--;
        }

        if (flagMinus) {
            while (y < width) {
                outch(fillCh);
                extraCh++;
                y++;
            }
        }
    }
    else if (strchr("eEgGfF", specifier) != NULL && specifier != 0) {
        if (precision < 0) {
            precision = 6;
        }

        vdbl = va_arg(*arg, double);
        __dblcvt(vdbl, specifier, width, precision, work);   /* 'e','f' etc. */
        slen = strlen(work);
        if ((flagSpace || flagPlus) && (work[0] != '-')) {
            slen++;
            memmove(work + 1, work, slen);
            if (flagSpace) {
                work[0] = ' ';
            }
            else if (flagPlus) {
                work[0] = '+';
            }
        }

        if (fq == NULL) {
            memcpy(s, work, slen);
            s += slen;
        }
        else {
            fputs(work, fq);
        }
        extraCh += slen;
    }
    else if (specifier == 's') {
        svalue = va_arg(*arg, char *);
        fillCh = ' ';
        if (precision > 0) {
            char *p;

            p = memchr(svalue, '\0', precision);
            if (p != NULL) {
                length = (int)(p - svalue);
            }
            else {
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
                    outch(fillCh);
                }
            }
        }

        for (x = 0; x < length; x++) {
            outch(svalue[x]);
        }

        extraCh += length;
        if (flagMinus) {
            if (length < width) {
                extraCh += (width - length);
                for (x = 0; x < (width - length); x++) {
                    outch(fillCh);
                }
            }
        }
    }
    *formt = format;
    return (extraCh);
}
