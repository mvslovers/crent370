/* STRFTIME.C */
#include "time.h"
#include "stdarg.h"
#include "stdio.h"
#include "stddef.h"
#include "mvssupa.h"

/* scalar date routines    --    public domain by Ray Gardner
** These will work over the range 1-01-01 thru 14699-12-31
** The functions written by Ray are isleap, months_to_days,
** years_to_days, ymd_to_scalar, scalar_to_ymd.
** modified slightly by Paul Edwards
*/

extern int      __isleap(unsigned yr);
extern unsigned __mtd(unsigned month);
extern long     __ytd(unsigned yr);
extern long     __ymdts(unsigned yr, unsigned mo, unsigned day);
extern void     __stymd(long scalar,
                        unsigned *pyr, unsigned *pmo, unsigned *pday);

#define isleap(y) __isleap(y)
#define months_to_days(m) __mtd(m)
#define years_to_days(y) __ytd(y)
#define ymd_to_scalar(y,m,d) __ymdts((y),(m),(d))
#define scalar_to_ymd(s,y,m,d) __stymd((s),(y),(m),(d))

/* dow - written by Paul Edwards, 1993-01-31 */
/* Released to the Public Domain */
/* This routine will work over the range 1-01-01 to 32767-12-31.
   It assumes the current calendar system has always been in
   place in that time.  If you pass 0 or negative years, then
   it produces results on the assumption that there is a year
   0.  It should always produce a value in the range of 0..6
   if a valid month and day have been passed, no matter what
   the year is.  However, it has not been tested for negative
   years, because the results are meaningless anyway.  It is
   mainly to stop people playing silly buggers and causing
   the macro to crash on negative years. */

#define dow(y,m,d) \
  ((((((m)+9)%12+1)<<4)%27 + (d) + 1 + \
  ((y)%400+400) + ((y)%400+400)/4 - ((y)%400+400)/100 + \
  (((m)<=2) ? ( \
  (((((y)%4)==0) && (((y)%100)!=0)) || (((y)%400)==0)) \
  ? 5 : 6) : 0)) % 7)

/*
 * strftime.c
 *
 * implements the iso c function strftime()
 *
 * written 1989-09-06 by jim nutt
 * released into the public domain by jim nutt
 *
 * modified 1989-10-21 by Rob Duff
 *
 * modified 1994-08-26 by Paul Edwards
 */

static char *aday[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static char *day[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

static char *amonth[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static char *month[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

static char *__tzname[2] = { "" "" };

static void strfmt(char *str, const char *fmt, ...);

/**
 *
 * size_t strftime(char *str,
 *                 size_t maxs,
 *                 const char *fmt,
 *                 const struct tm *t)
 *
 *      this functions acts much like a sprintf for time/date output.
 *      given a pointer to an output buffer, a format string and a
 *      time, it copies the time to the output buffer formatted in
 *      accordance with the format string.  the parameters are used
 *      as follows:
 *
 *          str is a pointer to the output buffer, there should
 *          be at least maxs characters available at the address
 *          pointed to by str.
 *
 *          maxs is the maximum number of characters to be copied
 *          into the output buffer, included the '\0' terminator
 *
 *          fmt is the format string.  a percent sign (%) is used
 *          to indicate that the following character is a special
 *          format character.  the following are valid format
 *          characters:
 *
 *              %A      full weekday name (Monday)
 *              %a      abbreviated weekday name (Mon)
 *              %B      full month name (January)
 *              %b      abbreviated month name (Jan)
 *              %c      standard date and time representation
 *              %d      day-of-month (01-31)
 *              %H      hour (24 hour clock) (00-23)
 *              %I      hour (12 hour clock) (01-12)
 *              %j      day-of-year (001-366)
 *              %M      minute (00-59)
 *              %m      month (01-12)
 *              %p      local equivalent of AM or PM
 *              %S      second (00-59)
 *              %U      week-of-year, first day sunday (00-53)
 *              %W      week-of-year, first day monday (00-53)
 *              %w      weekday (0-6, sunday is 0)
 *              %X      standard time representation
 *              %x      standard date representation
 *              %Y      year with century
 *              %y      year without century (00-99)
 *              %Z      timezone name
 *              %%      percent sign
 *
 *      the standard date string is equivalent to:
 *
 *          %a %b %d %Y
 *
 *      the standard time string is equivalent to:
 *
 *          %H:%M:%S
 *
 *      the standard date and time string is equivalent to:
 *
 *          %a %b %d %H:%M:%S %Y
 *
 *      strftime returns the number of characters placed in the
 *      buffer, not including the terminating \0, or zero if more
 *      than maxs characters were produced.
 *
**/

__PDPCLIB_API__ size_t strftime(char *s,
                                size_t maxs,
                                const char *f,
                                const struct tm *t)
{
    int w;
    char *p, *q, *r;
    char buf[26];

    p = s;
    q = s + maxs - 1;
    while ((*f != '\0')) {
        if (*f++ == '%') {
            r = buf;
            switch (*f++) {
            case '%' :
                r = "%";
                break;

            case 'a' :
                r = aday[t->tm_wday];
                break;

            case 'A' :
                r = day[t->tm_wday];
                break;

            case 'b' :
                r = amonth[t->tm_mon];
                break;

            case 'B' :
                r = month[t->tm_mon];
                break;

            case 'c' :
                strfmt(r, "%0 %0 %2 %2:%2:%2 %4",
                    aday[t->tm_wday], amonth[t->tm_mon],
                    t->tm_mday,t->tm_hour, t->tm_min,
                    t->tm_sec, t->tm_year+1900);
                break;

            case 'd' :
                strfmt(r,"%2",t->tm_mday);
                break;

            case 'H' :
                strfmt(r,"%2",t->tm_hour);
                break;

            case 'I' :
                strfmt(r,"%2",(t->tm_hour%12)?t->tm_hour%12:12);
                break;

            case 'j' :
                strfmt(r,"%3",t->tm_yday+1);
                break;

            case 'm' :
                strfmt(r,"%2",t->tm_mon+1);
                break;

            case 'M' :
                strfmt(r,"%2",t->tm_min);
                break;

            case 'p' :
                r = (t->tm_hour>11)?"PM":"AM";
                break;

            case 'S' :
                strfmt(r,"%2",t->tm_sec);
                break;

            case 'U' :
                w = t->tm_yday/7;
                if (t->tm_yday%7 > t->tm_wday)
                    w++;
                strfmt(r, "%2", w);
                break;

            case 'W' :
                w = t->tm_yday/7;
                if (t->tm_yday%7 > (t->tm_wday+6)%7)
                    w++;
                strfmt(r, "%2", w);
                break;

            case 'w' :
                strfmt(r,"%1",t->tm_wday);
                break;

            case 'x' :
                strfmt(r, "%3s %3s %2 %4", aday[t->tm_wday],
                    amonth[t->tm_mon], t->tm_mday, t->tm_year+1900);
                break;

            case 'X' :
                strfmt(r, "%2:%2:%2", t->tm_hour, t->tm_min, t->tm_sec);
                break;

            case 'y' :
                strfmt(r,"%2",t->tm_year%100);
                break;

            case 'Y' :
                strfmt(r,"%4",t->tm_year+1900);
                break;

            case 'Z' :
                r = (t->tm_isdst) ? __tzname[1] : __tzname[0];
                break;

            default:
                buf[0] = '%';     /* reconstruct the format */
                buf[1] = f[-1];
                buf[2] = '\0';
                if (buf[1] == 0)
                    f--;        /* back up if at end of string */
            }
            while (*r) {
                if (p == q) {
                    *q = '\0';
                    return 0;
                }
                *p++ = *r++;
            }
        }
        else {
            if (p == q) {
                *q = '\0';
                return 0;
            }
            *p++ = f[-1];
        }
    }
    *p = '\0';
    return (size_t)(p - s);
}

static int pow[5] = { 1, 10, 100, 1000, 10000 };

/**
 * static void strfmt(char *str, char *fmt);
 *
 * simple sprintf for strftime
 *
 * each format descriptor is of the form %n
 * where n goes from zero to four
 *
 * 0    -- string %s
 * 1..4 -- int %?.?d
 *
**/

static void strfmt(char *str, const char *fmt, ...)
{
    int ival, ilen;
    char *sval;
    va_list vp;

    va_start(vp, fmt);
    while (*fmt) {
        if (*fmt++ == '%') {
            ilen = *fmt++ - '0';
            if (ilen == 0) {               /* zero means string arg */
                sval = va_arg(vp, char*);
                while (*sval) *str++ = *sval++;
            }
            else {                         /* always leading zeros */
                ival = va_arg(vp, int);
                while (ilen) {
                    ival %= pow[ilen--];
                    *str++ = (char)('0' + ival / pow[ilen]);
                }
            }
        }
        else  *str++ = fmt[-1];
    }
    *str = '\0';
    va_end(vp);
}
