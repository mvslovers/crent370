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

static char const wday_name[7][3] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static char const mon_name[12][3] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static const int length_of_year[2] = { 365, 366 };

/* Year cycle from MAX_SAFE_YEAR down. */
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
    assert(tm->tm_mday <= days_in_month[IS_LEAP(tm->tm_year), tm->tm_mon]);
    assert(tm->tm_mon  >= 0);
    assert(tm->tm_mon  <= 11);
    assert(tm->tm_wday >= 0);
    assert(tm->tm_wday <= 6);
    assert(tm->tm_yday >= 0);
    assert(tm->tm_yday <= length_of_year[IS_LEAP(tm->tm_year)]);

    return 1;
}

/* The exceptional centuries without leap years cause the cycle to
   shift by 16
*/
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
static int safe_year(const int year)
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

static void copy_tm_to_tm(const struct tm *src, struct tm *dest) {
    if( src == NULL ) {
        memset(dest, 0, sizeof(*dest));
    }
    else {
        memcpy(dest, src, sizeof(*dest));
    }
}

#if 0
/* Simulate localtime_r() to the best of our ability */
struct tm * fake_localtime_r(const time_t *clock, struct tm *result) {
    const struct tm *static_result = localtime(clock);

    if( static_result == NULL ) {
        memset(result, 0, sizeof(*result));
        return NULL;
    }
    else {
        memcpy(result, static_result, sizeof(*result));
        return result;
    }
}

/* Simulate gmtime_r() to the best of our ability */
struct tm * fake_gmtime_r(const time_t *clock, struct tm *result) {
    const struct tm *static_result = gmtime(clock);

    if( static_result == NULL ) {
        memset(result, 0, sizeof(*result));
        return NULL;
    }
    else {
        memcpy(result, static_result, sizeof(*result));
        return result;
    }
}
#endif

static time64_t seconds_between_years(int left_year, int right_year) 
{
    int 		increment = (left_year > right_year) ? 1 : -1;
    time64_t 	seconds;
    int 		cycles;

	__64_init(&seconds);

    if( left_year > 2400 ) {
        cycles = (left_year - 2400) / 400;
        left_year -= cycles * 400;

        /* seconds   += cycles * seconds_in_gregorian_cycle; */
		__64_from_ull(&seconds, seconds_in_gregorian_cycle);
		__64_mul_int(&seconds, cycles, &seconds);
    }
    else if( left_year < 1600 ) {
        cycles = (left_year - 1600) / 400;
        left_year += cycles * 400;

        /* seconds   += cycles * seconds_in_gregorian_cycle; */
		__64_from_ull(&seconds, seconds_in_gregorian_cycle);
		__64_mul_int(&seconds, cycles, &seconds);
    }
    while( left_year != right_year ) {
        /* seconds += length_of_year[IS_LEAP(right_year - 1900)] * 60 * 60 * 24; */
		__64_add_int(&seconds, length_of_year[IS_LEAP(right_year - 1900)] * 60 * 60 * 24, &seconds);

        right_year += increment;
    }

    /* return seconds * increment; */
	return seconds;
}

/* This implementation violates mktime specification, according to which
   tm_yday, tm_wday, and tm_isdst fields should be updated. This function
   leaves input_date unmodified. Given that there were no bug reports, fixing
   it might cause more troubles than just leaving it as it is.
 */
time64_t mktime64(const struct tm *input_date) 
{
    struct tm safe_date;
    struct tm date;
    time64_t  time;
    int       year = input_date->tm_year + 1900;

    if( MIN_SAFE_YEAR <= year && year <= MAX_SAFE_YEAR ) {
        copy_tm_to_tm(input_date, &safe_date);
        __64_from_int(&time, (uint32_t) mktime(&safe_date));
        return time;
    }

    /* Have to make the year safe in date else it won't fit in safe_date */
    date = *input_date;
    date.tm_year = safe_year(year) - 1900;
    copy_tm_to_tm(&date, &safe_date);

    __64_from_int(&time, (uint32_t) mktime(&safe_date));
    __64_add(&time, seconds_between_years(year, (int)(safe_date.tm_year + 1900), &time);

    return time;
}

#if 0
/* Because I think mktime() is a crappy name */
Time64_T timelocal64(const struct TM *date) {
    return mktime64(date);
}
#endif

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
	__64_divmod_int(&time, 60, &time, &mod);
	v_tm_sec = (int) __64_to_int(&mod);

    /* v_tm_min =  (int)(time % 60); time /= 60; */
	__64_divmod_int(&time, 60, &time, &mod);
	v_tm_min = (int) __64_to_int(&mod);

    /* v_tm_hour = (int)(time % 24); time /= 24; */
	__64_divmod_int(&time, 24, &time, &mod);
	v_tm_hour = (int) __64_to_int(&mod);

    v_tm_tday = time;

#if 0
	/* #define WRAP(a,b,m)     ((a) = ((a) <  0  ) ? ((b)--, (a) + (m)) : (a)) */
    WRAP (v_tm_sec, v_tm_min, 60);
    WRAP (v_tm_min, v_tm_hour, 60);
    WRAP (v_tm_hour, v_tm_tday, 24);
#endif

    /* v_tm_wday = (int)((v_tm_tday + 4) % 7); */
	tmp = v_tm_tday;
	__64_add_int(&tmp, 4, &tmp);
	__64_mod_int(&tmp, 7, &tmp);
	v_tm_wday = (int) __64_to_int(&tmp);

    if (v_tm_wday < 0)	v_tm_wday += 7;

    m = v_tm_tday;
    /* if (m >= CHEAT_DAYS) { */
	if (__64_cmp_int(&m, CHEAT_DAYS) != __64_SMALLER) {
        year = CHEAT_YEARS;
        /* m -= CHEAT_DAYS; */
		__64_sub_int(&m, CHEAT_DAYS, &m);
    }

    /* if (m >= 0) { */
	if (__64_cmp_int(&m, 0) != __64_SMALLER) {
        /* Gregorian cycles, this is huge optimization for distant times */
	    /* cycles = (int)(m / (Time64_T) days_in_gregorian_cycle); */
		__64_div_int(&m, days_in_gregorian_cycle, &tmp);
		cycles = (int) __64_to_int(&tmp);
		
        if( cycles ) {
            /* m -= (cycles * (Time64_T) days_in_gregorian_cycle); */
			__64_from_int(&tmp, days_in_gregorian_cycle);
			__64_mul_int(&tmp, cycles, &tmp);
			__64_sub(&m, &tmp, &m);

            /* year += (cycles * years_in_gregorian_cycle); */
			__64_from_int(&tmp, years_in_gregorian_cycle);
			__64_mul_int(&tmp, cycles, &tmp);
			year += (int) __64_to_int(&tmp);
        }

        /* Years */
        leap = IS_LEAP (year);
        /* while (m >= (Time64_T) length_of_year[leap]) { */
		while(__64_cmp_int(&m, length_of_year[leap]) != __64_SMALLER) {
            /* m -= (Time64_T) length_of_year[leap]; */
			__64_sub_int(&m, length_of_year[leap], &m);

            year++;
            leap = IS_LEAP (year);
        }

        /* Months */
        v_tm_mon = 0;
        /* while (m >= (Time64_T) days_in_month(leap, v_tm_mon)) { */
		while(__64_cmp_int(&m, days_in_month(leap, v_tm_mon)) != __64_SMALLER) {
            /* m -= (Time64_T) days_in_month(leap, v_tm_mon); */
			__64_sub_int(&m, days_in_month(leap, v_tm_mon), &m);

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
	i = (int) __64_to_int(&m)
    p->tm_mday = (int) i + 1;
    /* p->tm_yday = julian_days_by_month[leap][v_tm_mon] + (int)m; */
    p->tm_yday = julian_days_by_month(leap, v_tm_mon) + (int)i;
    p->tm_sec  = v_tm_sec;
    p->tm_min  = v_tm_min;
    p->tm_hour = v_tm_hour;
    p->tm_mon  = v_tm_mon;
    p->tm_wday = v_tm_wday;
    assert(check_tm(p));

    return p;
}

struct TM *localtime64_r (const Time64_T *time, struct TM *local_tm)
{
    time_t safe_time;
    struct tm safe_date;
    struct TM gm_tm;
    Year orig_year;
    int month_diff;
    assert(local_tm != NULL);
    /* Use the system localtime() if time_t is small enough */
    if( SHOULD_USE_SYSTEM_LOCALTIME(*time) ) {
        safe_time = *time;
        TRACE1("Using system localtime for %lld\n", *time);
        LOCALTIME_R(&safe_time, &safe_date);
        copy_tm_to_TM(&safe_date, local_tm);
        assert(check_tm(local_tm));
        return local_tm;
    }
    if( gmtime64_r(time, &gm_tm) == NULL ) {
        TRACE1("gmtime64_r returned null for %lld\n", *time);
        return NULL;
    }
    orig_year = gm_tm.tm_year;
    if (gm_tm.tm_year > (2037 - 1900) ||
        gm_tm.tm_year < (1970 - 1900)
       )
    {
        TRACE1("Mapping tm_year %lld to safe_year\n", (Year)gm_tm.tm_year);
        gm_tm.tm_year = safe_year((Year)(gm_tm.tm_year + 1900)) - 1900;
    }
    safe_time = timegm64(&gm_tm);
    if( LOCALTIME_R(&safe_time, &safe_date) == NULL ) {
        TRACE1("localtime_r(%d) returned NULL\n", (int)safe_time);
        return NULL;
    }
    copy_tm_to_TM(&safe_date, local_tm);
    local_tm->tm_year = orig_year;
    if( local_tm->tm_year != orig_year ) {
        TRACE2("tm_year overflow: tm_year %lld, orig_year %lld\n",
              (Year)local_tm->tm_year, (Year)orig_year);
#ifdef EOVERFLOW
        errno = EOVERFLOW;
#endif
        return NULL;
    }
    month_diff = local_tm->tm_mon - gm_tm.tm_mon;
    /*  When localtime is Dec 31st previous year and
        gmtime is Jan 1st next year.
    */
    if( month_diff == 11 ) {
        local_tm->tm_year--;
    }
    /*  When localtime is Jan 1st, next year and
        gmtime is Dec 31st, previous year.
    */
    if( month_diff == -11 ) {
        local_tm->tm_year++;
    }
    /* GMT is Jan 1st, xx01 year, but localtime is still Dec 31st
       in a non-leap xx00.  There is one point in the cycle
       we can't account for which the safe xx00 year is a leap
       year.  So we need to correct for Dec 31st comming out as
       the 366th day of the year.
    */
    if( !IS_LEAP(local_tm->tm_year) && local_tm->tm_yday == 365 )
        local_tm->tm_yday--;
    assert(check_tm(local_tm));
    return local_tm;
}
static int valid_tm_wday( const struct TM* date ) {
    if( 0 <= date->tm_wday && date->tm_wday <= 6 )
        return 1;
    else
        return 0;
}
static int valid_tm_mon( const struct TM* date ) {
    if( 0 <= date->tm_mon && date->tm_mon <= 11 )
        return 1;
    else
        return 0;
}
char *asctime64_r( const struct TM* date, char *result ) {
    /* I figure everything else can be displayed, even hour 25, but if
       these are out of range we walk off the name arrays */
    if (!valid_tm_wday(date) || !valid_tm_mon(date)) {
        return NULL;
    }
    /* Docs state this function does not support years beyond 9999. */
    if (1900 + date->tm_year > 9999) {
        return NULL;
    }
    /*
     * The IBM docs for this function state that the result buffer can be
     * assumed to be at least 26 bytes wide. The docs also state that this is
     * only valid for years <= 9999, so we know this format string will not
     * print more than that many characters.
     *
     * http://www-01.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/asctimer.htm
     */
    snprintf(result, 26, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
        wday_name[date->tm_wday],
        mon_name[date->tm_mon],
        date->tm_mday, date->tm_hour,
        date->tm_min, date->tm_sec,
        1900 + date->tm_year);
    return result;
}
char *ctime64_r( const Time64_T* time, char* result ) {
    struct TM date;
    localtime64_r( time, &date );
    return asctime64_r( &date, result );
}
/* Non-thread safe versions of the above */
struct TM *localtime64(const Time64_T *time) {
    return localtime64_r(time, &Static_Return_Date);
}
struct TM *gmtime64(const Time64_T *time) {
    return gmtime64_r(time, &Static_Return_Date);
}
char *asctime64( const struct TM* date ) {
    return asctime64_r( date, Static_Return_String );
}
char *ctime64( const Time64_T* time ) {
    return asctime64(localtime64(time));
}

