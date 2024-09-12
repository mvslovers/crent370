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
#include <time64.h>
#include "__time64.h"

__asm__("\n&FUNC    SETC 'mktime64'");
time64_t mktime64(struct tm *input_date) 
{
    struct tm safe_date;
    struct tm date;
    time64_t  time;
    int       year = input_date->tm_year + 1900;
	uint64_t  seconds;

	__64_init(&time);

    if ((year < 1970) || (year > 9999)) {
		/* in keeping with our 32 bit mktime() function:
			disallow anything before 1970
			disallow anything after 9999
		*/
		__64_sub_i32(&time, 1, &time);	/* make time -1 */
		goto quit;
    }

	/* safe "years" can use the 32 bit mktime() function */
    if( MIN_SAFE_YEAR <= year && year <= MAX_SAFE_YEAR ) { 
        __64_from_u32(&time, mktime(input_date));
        goto quit;
    }

    /* Have to make the year safe in date else it won't fit in safe_date */
    date = *input_date;
    date.tm_year = safe_year(year) - 1900;
	safe_date = date;

	/* initialize time using safe date */
    __64_from_u32(&time, (uint32_t) mktime(&safe_date));
	/* add the seconds between the input_date year and safe_date year */
	seconds = seconds_between_years(year, (int)(safe_date.tm_year + 1900));
    __64_add_u64(&time, seconds, &time);

	/* update the struct tm input_date */
    *input_date = *gmtime64(&time);

quit:
    return time;
}

