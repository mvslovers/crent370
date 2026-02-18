/* GMTIME.C */
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

struct tm *gmtime(const time_t *timer)
{
    CLIBCRT     *crt    = __crtget();
    struct tm   *tms    = (struct tm*)crt->crttms;

	return gmtime_r(timer, tms);
}

