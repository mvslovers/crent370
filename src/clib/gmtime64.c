/* gmtime64.c */
#include "time.h"
#include "stdarg.h"
#include "stdio.h"
#include "stddef.h"
#include "mvssupa.h"
#include "clibcrt.h"

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

struct tm *gmtime64(const time_t64 *timer)
{
    CLIBCRT     *crt    = __crtget();
    struct tm   *tms    = (struct tm*)crt->crttms;
    unsigned yr, mo, da;
    unsigned long secs;
    unsigned long days;

    days = *timer / (60L*60*24);
    secs = *timer % (60L*60*24);
    scalar_to_ymd(days + ymd_to_scalar(1970, 1, 1), &yr, &mo, &da);
    tms->tm_year = yr - 1900;
    tms->tm_mon = mo - 1;
    tms->tm_mday = da;
    tms->tm_yday = (int)(ymd_to_scalar(tms->tm_year + 1900, mo, da)
                  - ymd_to_scalar(tms->tm_year + 1900, 1, 1));
    tms->tm_wday = dow(tms->tm_year + 1900, mo, da);
    tms->tm_isdst = -1;
    tms->tm_sec = (int)(secs % 60);
    secs /= 60;
    tms->tm_min = (int)(secs % 60);
    secs /= 60;
    tms->tm_hour = (int)secs;
    return (tms);
}

