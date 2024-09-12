/*
Copyright (c) 2007-2008  Michael G Schwern
This software originally derived from Paul Sheer's pivotal_gmtime_r.c.
The MIT License:
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/* See http://code.google.com/p/y2038 for this code's origin */
#if defined(__LP64__)
#error This cruft should be LP32 only!
#endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "time64.h"
#include "__time64.h"

static const int length_of_year[2] = { 365, 366 };

__asm__("\n&FUNC    SETC 'timegm64'");
time64_t timegm64(const struct tm *date) 
{
    time64_t 	days;
    time64_t 	seconds;
    int      	year;
    int      	orig_year = (int)date->tm_year;
    int      	cycles  = 0;
	time64_t	tmp;
	__64_DTYPE_TMP u;

	__64_init(&days);
	__64_init(&seconds);

	/* wtof("%s: orig_year=%d", __func__, orig_year); */
#if 1
	/* a small optimization for years > 2370 (470) (400 day gregorian cycle + unix epoch date 70)*/
	while (orig_year > years_in_gregorian_cycle + 70) {
		/* wtof("%s: while (orig_year + 100 > years_in_gregorian_cycle) {",  __func__); */
		/* wtof("%s:     orig_year=%d, days_in_gregorian_cycle=%d", __func__, orig_year, years_in_gregorian_cycle); */
		__64_add_u32(&days, days_in_gregorian_cycle, &days);
		/* wtof("%s:     add %d to days = %lld", __func__, days_in_gregorian_cycle, days); */
		orig_year -= years_in_gregorian_cycle;
		/* wtof("%s: }", __func__); */
	}	
#endif

#if 0
    if( orig_year > 100) {
        cycles = (orig_year - 100) / 400;
        orig_year -= cycles * 400;
#if 0
        days      += (time64_t)cycles * days_in_gregorian_cycle;
#else
		__64_from_u32(&tmp, days_in_gregorian_cycle);
		wtof("%s: if (orig_year > 100), orig_year=%d, days_in_gregorian_cycle=%lld", __func__, orig_year, tmp);
		__64_mul_i32(&tmp, cycles, &tmp);
		wtof("%s: times %d = %lld", __func__, cycles, tmp);
		__64_add(&days, &tmp, &days);
		wtof("%s: add %lld to days = %lld", __func__, tmp, days);
#endif
    }
#endif

#if 0 /* we're not going to support negative years */
    else if( orig_year < -300 ) {
        cycles = (orig_year - 100) / 400;
        orig_year -= cycles * 400;
#if 0
        days      += (time64_t)cycles * days_in_gregorian_cycle;
#else
		__64_add_int(&days, cycles * days_in_gregorian_cycle, &days);
#endif
    }
#endif /* we're not going to support negative years */

    if( orig_year > 70 ) {
        year = 70;
        while( year < orig_year ) {
#if 0
            days += length_of_year[IS_LEAP(year)];
#else
			__64_add_i32(&days, length_of_year[IS_LEAP(year)], &days);
#endif
            year++;
        }
    }
	else {
    	if ( orig_year < 70 ) {
#if 0 /* we're not going to support years less than 1970 (70) */
        	year = 69;
        	do {
#if 0
            	days -= length_of_year[IS_LEAP(year)];
#else
				__64_sub_int(&days, length_of_year[IS_LEAP(year)], &days);
#endif
            	year--;
        	} while( year >= orig_year );
#else /* we're not going to support years less than 1970 (70) */
			__asm__("DS\t0H\t year < 70 - indicate failure");
			__64_sub_i32(&seconds, 1, &seconds);	/* 0 - 1 == -1 */
			return seconds;
#endif /* we're not going to support years less than 1970 (70) */
		}
    }

#if 0
    days += julian_days_by_month[IS_LEAP(orig_year)][date->tm_mon];
    days += date->tm_mday - 1;
#else
	__64_add_i32(&days, julian_days_by_month(IS_LEAP(orig_year), date->tm_mon), &days);
	__64_add_i32(&days, date->tm_mday - 1, &days);
#endif

#if 0
    seconds = days * 60 * 60 * 24;
#else
	__64_mul_i32(&days, 60 * 60 * 24, &seconds);
#endif

#if 0
    seconds += date->tm_hour * 60 * 60;
#else
	__64_add_i32(&seconds, date->tm_hour * 60 * 60, &seconds);
#endif

#if 0
    seconds += date->tm_min * 60;
#else
	__64_add_i32(&seconds, date->tm_min * 60, &seconds);
#endif

#if 0
    seconds += date->tm_sec;
#else
	__64_add_i32(&seconds, date->tm_sec, &seconds);
#endif

quit:
#if 0
	{
		struct tm 	tm = *date;
		time_t	 	t = mktime(&tm);
		printf("%s: t=%u, seconds=%llu\n", __func__, t, seconds);
	}
#endif
	/* wtof("%s: return %lld seconds", __func__, seconds); */
    return seconds;
}

