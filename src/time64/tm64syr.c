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

/* Year cycle from MAX_SAFE_YEAR down. */
__asm__("\n* safe_years_high");
static const int safe_years_high[SOLAR_CYCLE_LENGTH] = {
    2016, 2017, 2018, 2019,
    2020, 2021, 2022, 2023,
    2024, 2025, 2026, 2027,
    2028, 2029, 2030, 2031,
    2032, 2033, 2034, 2035,
    2036, 2037, 2010, 2011,
    2012, 2013, 2014, 2015
};

/* Year cycle from MIN_SAFE_YEAR up */
__asm__("\n* safe_years_low");
static const int safe_years_low[SOLAR_CYCLE_LENGTH] = {
    1996, 1997, 1998, 1971,
    1972, 1973, 1974, 1975,
    1976, 1977, 1978, 1979,
    1980, 1981, 1982, 1983,
    1984, 1985, 1986, 1987,
    1988, 1989, 1990, 1991,
    1992, 1993, 1994, 1995,
};

/* Let's assume people are going to be looking for dates in the future.
   Let's provide some cheats so you can skip ahead.
   This has a 4x speed boost when near 2008.
*/

/* The exceptional centuries without leap years cause the cycle to
   shift by 16
*/
__asm__("\n&FUNC    SETC 'cycle_offset'");
static int cycle_offset(int year)
{
    const int start_year = 2000;
    int year_diff  = year - start_year;
    int exceptions;

    if( year > start_year ) year_diff--;

    exceptions  = year_diff / 100;
    exceptions -= year_diff / 400;

    return exceptions * 16;
}

/* For a given year after 2038, pick the latest possible matching
   year in the 28 year calendar cycle.
   A matching year...
   1) Starts on the same day of the week.
   2) Has the same leap year status.
   This is so the calendars match up.
   Also the previous year must match.  When doing Jan 1st you might
   wind up on Dec 31st the previous year when doing a -UTC time zone.
   Finally, the next year must have the same start day of week.  This
   is for Dec 31st with a +UTC time zone.
   It doesn't need the same leap year status since we only care about
   January 1st.
*/
__asm__("\n&FUNC    SETC 'safe_year'");
int safe_year(const int year)
{
    int safe_year = 0;
    int year_cycle;

    if( year >= MIN_SAFE_YEAR && year <= MAX_SAFE_YEAR ) {
        return (int)year; 
    }

    year_cycle = year + cycle_offset(year);

    /* safe_years_low is off from safe_years_high by 8 years */
    if( year < MIN_SAFE_YEAR )	year_cycle -= 8;

    /* Change non-leap xx00 years to an equivalent */
    if( is_exception_century(year) )	year_cycle += 11;

    /* Also xx01 years, since the previous year will be wrong */
    if( is_exception_century(year - 1) )	year_cycle += 17;

    year_cycle %= SOLAR_CYCLE_LENGTH;
    if( year_cycle < 0 )	year_cycle = SOLAR_CYCLE_LENGTH + year_cycle;

    assert( year_cycle >= 0 );
    assert( year_cycle < SOLAR_CYCLE_LENGTH );

    if( year < MIN_SAFE_YEAR )			safe_year = safe_years_low[year_cycle];
    else if( year > MAX_SAFE_YEAR )		safe_year = safe_years_high[year_cycle];
    else assert(0);

    assert(safe_year <= MAX_SAFE_YEAR && safe_year >= MIN_SAFE_YEAR);

    return safe_year;
}

