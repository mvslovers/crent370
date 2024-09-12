/* MKTIME.C */
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

#define EPOCH	719163	/* Unix EPOCH 1970-01-01 */

__PDPCLIB_API__ time_t mktime(struct tm *timeptr)
{
    time_t tt;

	/* 70 = 1970 Unix EPOCH     || 205 = 2105 (roll over in 2106) */
    if ((timeptr->tm_year < 70) || (timeptr->tm_year > 205))
    {
        tt = (time_t)-1;
    }
    else
    {
        tt = ymd_to_scalar(timeptr->tm_year + 1900,
                           timeptr->tm_mon + 1,
                           timeptr->tm_mday)
             - EPOCH;
        tt = tt * 24 + timeptr->tm_hour;
        tt = tt * 60 + timeptr->tm_min;
        tt = tt * 60 + timeptr->tm_sec;
    }
    *timeptr = *gmtime(&tt);
    return (tt);
}
