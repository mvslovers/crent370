#include "time.h"
#include "stdarg.h"
#include "stdio.h"
#include "stddef.h"
#include "mvssupa.h"


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

	/* 70 = year 1970			|| 205 = year 2105 */
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

int main(int argc, char **argv)
{
	int			i;
	time_t		t = (time_t)0;
	struct tm	tm = {0};
	long		epoch = ymd_to_scalar(1970, 1, 1);
	
	printf("Unix epoch 1970-01-01 value is %ld\n", epoch);
	
	tm.tm_year = 206;	/* 206 = 2106 */
	tm.tm_mon  = 0;
	tm.tm_mday = 1;
	tm.tm_hour = 1;
	tm.tm_min  = 23;
	tm.tm_sec  = 45;
	for(i=0; (i < 12) && (t != (time_t)-1); tm.tm_mon++, i++) {
		t = mktime(&tm);
		printf("%s", asctime(&tm));
	}
	
	return 0;
}
