/* VVPRINTF.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <cliblock.h>

#define unused(x) ((void)(x))
#define outch(ch) ((fq == NULL) ? *s++ = (char)ch : __fputc(ch,fq))
#if 0
#define inch() ((fp == NULL) ? \
    (ch = (unsigned char)*s++) : (ch = getc(fp)))
#endif

extern void
__dblcvt(double num, char cnvtype, size_t nwidth, int nprecision, char *result);
extern int
__examin(const char **formt, FILE *fq, char *s, va_list *arg, int chcount);

int
vvprintf(const char *format, va_list arg, FILE *fq, char *s)
{
    int         fin = 0;
    int         vint;
    double      vdbl;
    unsigned    uvint;
    const char  *vcptr;
    int         chcount = 0;
    size_t      len;
    char        numbuf[50];
    char        *nptr;
    int         *viptr;

    if (fq) lock(fq,0); /* lock file handle (required for __fputc() call) */

    while (!fin) {
        if (*format == '\0') {
            fin = 1;
        }
        else if (*format == '%') {
            format++;
            if (*format == 'd') {
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
                    outch(*nptr);
                    chcount++;
                } while (nptr != numbuf);
            }
            else if (strchr("eEgGfF", *format) != NULL && *format != 0) {
                vdbl = va_arg(arg, double);
                __dblcvt(vdbl, *format, 0, 6, numbuf);   /* 'e','f' etc. */
                len = strlen(numbuf);
                if (fq == NULL) {
                    memcpy(s, numbuf, len);
                    s += len;
                }
                else {
                    fputs(numbuf, fq);
                }
                chcount += len;
            }
            else if (*format == 's') {
                vcptr = va_arg(arg, const char *);
                if (vcptr == NULL) {
                    vcptr = "(null)";
                }
                if (fq == NULL) {
                    len = strlen(vcptr);
                    memcpy(s, vcptr, len);
                    s += len;
                    chcount += len;
                }
                else {
                    fputs(vcptr, fq);
                    chcount += strlen(vcptr);
                }
            }
            else if (*format == 'c') {
                vint = va_arg(arg, int);
                outch(vint);
                chcount++;
            }
            else if (*format == 'n') {
                viptr = va_arg(arg, int *);
                *viptr = chcount;
            }
            else if (*format == '%') {
                outch('%');
                chcount++;
            }
            else {
                int extraCh;

                extraCh = __examin(&format, fq, s, &arg, chcount);
                chcount += extraCh;
                if (s != NULL) {
                    s += extraCh;
                }
            }
        }
        else {
            outch(*format);
            chcount++;
        }
        format++;
    }

    if (fq) unlock(fq,0);

    return (chcount);
}
