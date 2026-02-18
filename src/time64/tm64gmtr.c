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
#include "mvssupa.h"
#include "clibcrt.h"

static const int length_of_year[2] = { 365, 366 };

/* Let's assume people are going to be looking for dates in the future.
   Let's provide some cheats so you can skip ahead.
   This has a 4x speed boost when near 2008.
*/

#if 0
__asm__("\n&FUNC    SETC 'check_tm'");
static int check_tm(struct tm *tm)
{
    /* Don't forget leap seconds */
    assert(tm->tm_sec >= 0);
    assert(tm->tm_sec <= 61);
    assert(tm->tm_min >= 0);
    assert(tm->tm_min <= 59);
    assert(tm->tm_hour >= 0);
    assert(tm->tm_hour <= 23);
    assert(tm->tm_mday >= 1);
    assert(tm->tm_mday <= days_in_month(IS_LEAP(tm->tm_year), tm->tm_mon));
    assert(tm->tm_mon  >= 0);
    assert(tm->tm_mon  <= 11);
    assert(tm->tm_wday >= 0);
    assert(tm->tm_wday <= 6);
    assert(tm->tm_yday >= 0);
    assert(tm->tm_yday <= length_of_year[IS_LEAP(tm->tm_year)]);

    return 1;
}
#endif

__asm__("\n&FUNC    SETC 'gmtime64_r'");
struct tm *gmtime64_r (const time64_t *in_time, struct tm *p)
{
    int 		v_tm_sec, v_tm_min, v_tm_hour, v_tm_mon, v_tm_wday;
    time64_t 	v_tm_tday;
    int 		leap;
    time64_t 	m;
    time64_t 	time = *in_time;
    int 		year = 70;
    int 		cycles = 0;
	time64_t	mod;
	time64_t	tmp;
	int			i;

	/* v_tm_sec =  (int)(time % 60); time /= 60; */
	__64_divmod_u32(&time, 60, &time, &mod);
	v_tm_sec = (int) __64_to_i32(&mod);

    /* v_tm_min =  (int)(time % 60); time /= 60; */
	__64_divmod_u32(&time, 60, &time, &mod);
	v_tm_min = (int) __64_to_i32(&mod);

    /* v_tm_hour = (int)(time % 24); time /= 24; */
	__64_divmod_u32(&time, 24, &time, &mod);
	v_tm_hour = (int) __64_to_i32(&mod);

    v_tm_tday = time;

#if 0
	/* #define WRAP(a,b,m)     ((a) = ((a) <  0  ) ? ((b)--, (a) + (m)) : (a)) */
    WRAP (v_tm_sec, v_tm_min, 60);
    WRAP (v_tm_min, v_tm_hour, 60);
    WRAP (v_tm_hour, v_tm_tday, 24);
#endif

    /* v_tm_wday = (int)((v_tm_tday + 4) % 7); */
	tmp = v_tm_tday;
	__64_add_u32(&tmp, 4, &tmp);
	__64_mod_u32(&tmp, 7, &tmp);
	v_tm_wday = (int) __64_to_i32(&tmp);

    if (v_tm_wday < 0)	v_tm_wday += 7;

    m = v_tm_tday;
    /* if (m >= CHEAT_DAYS) { */
	if (__64_cmp_u32(&m, CHEAT_DAYS) != __64_SMALLER) {
        year = CHEAT_YEARS;
        /* m -= CHEAT_DAYS; */
		__64_sub_u32(&m, CHEAT_DAYS, &m);
    }

    /* if (m >= 0) { */
	if (__64_cmp_u32(&m, 0) != __64_SMALLER) {
        /* Gregorian cycles, this is huge optimization for distant times */
	    /* cycles = (int)(m / (Time64_T) days_in_gregorian_cycle); */
		__64_div_u32(&m, days_in_gregorian_cycle, &tmp);
		cycles = (int) __64_to_i32(&tmp);
		
        if( cycles ) {
            /* m -= (cycles * (Time64_T) days_in_gregorian_cycle); */
			__64_from_u32(&tmp, days_in_gregorian_cycle);
			__64_mul_u32(&tmp, cycles, &tmp);
			__64_sub(&m, &tmp, &m);

            /* year += (cycles * years_in_gregorian_cycle); */
			__64_from_u32(&tmp, years_in_gregorian_cycle);
			__64_mul_u32(&tmp, cycles, &tmp);
			year += (int) __64_to_i32(&tmp);
        }

        /* Years */
        leap = IS_LEAP (year);
        /* while (m >= (Time64_T) length_of_year[leap]) { */
		while(__64_cmp_i32(&m, length_of_year[leap]) != __64_SMALLER) {
            /* m -= (Time64_T) length_of_year[leap]; */
			__64_sub_i32(&m, length_of_year[leap], &m);

            year++;
            leap = IS_LEAP (year);
        }

        /* Months */
        v_tm_mon = 0;
        /* while (m >= (Time64_T) days_in_month(leap, v_tm_mon)) { */
		while(__64_cmp_i32(&m, days_in_month(leap, v_tm_mon)) != __64_SMALLER) {
            /* m -= (Time64_T) days_in_month(leap, v_tm_mon); */
			__64_sub_i32(&m, days_in_month(leap, v_tm_mon), &m);

            v_tm_mon++;
        }
    } 
#if 0
	else {
        year--;
        /* Gregorian cycles */
        cycles = (int)((m / (Time64_T) days_in_gregorian_cycle) + 1);
        if( cycles ) {
            m -= (cycles * (Time64_T) days_in_gregorian_cycle);
            year += (cycles * years_in_gregorian_cycle);
        }
        /* Years */
        leap = IS_LEAP (year);
        while (m < (Time64_T) -length_of_year[leap]) {
            m += (Time64_T) length_of_year[leap];
            year--;
            leap = IS_LEAP (year);
        }
        /* Months */
        v_tm_mon = 11;
        while (m < (Time64_T) -days_in_month[leap][v_tm_mon]) {
            m += (Time64_T) days_in_month[leap][v_tm_mon];
            v_tm_mon--;
        }
        m += (Time64_T) days_in_month[leap][v_tm_mon];
    }
#endif
    p->tm_year = year;

    if( p->tm_year != year ) {
#ifdef EOVERFLOW
        errno = EOVERFLOW;
#endif
        return NULL;
    }

    /* At this point m is less than a year so casting to an int is safe */
    /* p->tm_mday = (int) m + 1; */
	i = (int) __64_to_i32(&m);
    p->tm_mday = (int) i + 1;

    /* p->tm_yday = julian_days_by_month[leap][v_tm_mon] + (int)m; */
    p->tm_yday = julian_days_by_month(leap, v_tm_mon) + (int)i;
    p->tm_sec  = v_tm_sec;
    p->tm_min  = v_tm_min;
    p->tm_hour = v_tm_hour;
    p->tm_mon  = v_tm_mon;
    p->tm_wday = v_tm_wday;
#if 0
    assert(check_tm(p));
#endif

    return p;
}

