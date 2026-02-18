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

static const int length_of_year[2] = { 365, 366 };

__asm__("\n&FUNC    SETC 'seconds_between_years'");
uint64_t seconds_between_years(int left_year, int right_year) 
{
    int 		increment = (left_year > right_year) ? 1 : -1;
    time64_t 	seconds;
    int 		cycles;

	__64_init(&seconds);
	/* wtof("%s: left_year=%d, right_year=%d, seconds=%lld", __func__, left_year, right_year, seconds); */

    if( left_year > 2400 ) {
        cycles = (left_year - 2400) / 400;
        left_year -= cycles * 400;

        /* seconds   += cycles * seconds_in_gregorian_cycle; */
		__64_from_u64(&seconds, seconds_in_gregorian_cycle);
		/* wtof("%s: left_year > 2400, cycles=%d, left_year=%d, seconds=%lld", __func__, cycles, left_year, seconds); */
		__64_mul_i32(&seconds, cycles, &seconds);
		/* wtof("%s: seconds multiply by cycles =%lld", __func__, seconds); */
    }
    else if( left_year < 1600 ) {
        cycles = (left_year - 1600) / 400;
        left_year += cycles * 400;

        /* seconds   += cycles * seconds_in_gregorian_cycle; */
		__64_from_u64(&seconds, seconds_in_gregorian_cycle);
		/* wtof("%s: left_year < 1600, cycles=%d, left_year=%d, seconds=%lld", __func__, cycles, left_year, seconds); */
		__64_mul_i32(&seconds, cycles, &seconds);
		/* wtof("%s: seconds multiply by cycles =%lld", __func__, seconds); */
    }

	/* wtof("%s: while(left_year != right_year) { # left_year=%d, right_year=%d", __func__, left_year, right_year); */
    while( left_year != right_year ) {
        /* seconds += length_of_year[IS_LEAP(right_year - 1900)] * 60 * 60 * 24; */
		__64_add_i32(&seconds, length_of_year[IS_LEAP(right_year - 1900)] * 60 * 60 * 24, &seconds);

        right_year += increment;
    }
	/* wtof("%s: }", __func__); */

    /* return seconds * increment; */
	/* wtof("%s: return %llu", __func__, seconds.u64); */

	return seconds.u64;
}

