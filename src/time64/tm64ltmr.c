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

/*
Programmers who have available to them 64-bit time values as a 'long
long' type can use localtime64_r() and gmtime64_r() which correctly
converts the time even on 32-bit systems. Whether you have 64-bit time
values will depend on the operating system.
localtime64_r() is a 64-bit equivalent of localtime_r().
gmtime64_r() is a 64-bit equivalent of gmtime_r().
*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <time64.h>
#include "__time64.h"

struct tm *localtime64_r (const time64_t *time, struct tm *local_tm)
{
    time_t 		safe_time;
    struct tm 	safe_date;
    struct tm 	gm_tm;
    int 		orig_year;
    int 		month_diff;
	time64_t	tmp;

	if (!time) {
		wtof("%s: NULL time pointer parameter 1", __func__);
        return NULL;
	}

	if (!local_tm) {
		wtof("%s: NULL local_tm pointer parameter 2", __func__);
        return NULL;
	}

	/* logic: create a safe date so that we can use the logacy localtime_r()
	**		  to obtain a local date (adjusted for time zone offset).
	*/
	{
		/* create gm_tm from time value */
    	if( gmtime64_r(time, &gm_tm) == NULL ) { 
			wtof("%s: gmtime64_r failure for time value 0x%016LLX (%llu)", __func__, *time, *time);
    	    return NULL;
    	}

		/* save the original year and map gm_tm.tm_year to a safe year */
    	orig_year = gm_tm.tm_year;
    	if (gm_tm.tm_year > (2037 - 1900) || gm_tm.tm_year < (1970 - 1900)){
        	gm_tm.tm_year = safe_year((int)(gm_tm.tm_year + 1900)) - 1900;
    	}

    	/* safe_time = timegm64(&gm_tm); */
    	tmp = timegm64(&gm_tm);
		safe_time = (time_t) __64_to_u32(&tmp);

		/* create a safe_date using the safe_time value with adjustment for time zone */
    	if( localtime_r(&safe_time, &safe_date) == NULL ) {
			wtof("%s: localtime_r failure for time value 0x%08X (%u)", __func__, safe_time, safe_time);
        	return NULL;
    	}
	
		/* copy the safe_date to our local_tm and replace the year with the original year */
		*local_tm = safe_date;
    	local_tm->tm_year = orig_year;
	}

	/* logic: make adjustments to local_tm for any rollover that happened when the
	**		  local time zone offset was applied by localtime_r().
	*/
	{
	    /*  When localtime is Dec 31st previous year and gmtime is Jan 1st next year. */
    	month_diff = local_tm->tm_mon - gm_tm.tm_mon;
    	if( month_diff == 11 ) {
        	local_tm->tm_year--;
    	}

    	/*  When localtime is Jan 1st, next year and gmtime is Dec 31st, previous year. */
    	if( month_diff == -11 ) {
        	local_tm->tm_year++;
    	}

    	/* GMT is Jan 1st, xx01 year, but localtime is still Dec 31st
       	** in a non-leap xx00.  There is one point in the cycle
       	** we can't account for which the safe xx00 year is a leap
       	** year.  So we need to correct for Dec 31st comming out as
       	** the 366th day of the year.
    	*/
    	if( !IS_LEAP(local_tm->tm_year) && local_tm->tm_yday == 365 )
        	local_tm->tm_yday--;
	}

    return local_tm;
}

