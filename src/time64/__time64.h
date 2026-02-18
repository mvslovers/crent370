#ifndef __TIME64_H
#define __TIME64_H

#define years_in_gregorian_cycle	400
#define days_in_gregorian_cycle     ((365 * 400) + 100 - 4 + 1)
#define seconds_in_gregorian_cycle  12622780800ULL /* 0x00000002F0605980ULL */

/* Some numbers relating to the gregorian cycle */
/* static const time64_t seconds_in_gregorian_cycle = days_in_gregorian_cycle * 60LL * 60LL * 24LL; */

/* Year range we can trust the time funcitons with */
#define MAX_SAFE_YEAR 2037
#define MIN_SAFE_YEAR 1970

/* 28 year Julian calendar cycle */
#define SOLAR_CYCLE_LENGTH 28

/* Let's assume people are going to be looking for dates in the future.
   Let's provide some cheats so you can skip ahead.
   This has a 4x speed boost when near 2008.
*/

/* Number of days since epoch on Jan 1st, 2008 GMT */
#define CHEAT_DAYS  	(1199145600 / 24 / 60 / 60)
#define CHEAT_YEARS 	108
#define IS_LEAP(n)      ((!(((n) + 1900) % 400) || (!(((n) + 1900) % 4) && (((n) + 1900) % 100))) != 0)
#define WRAP(a,b,m)     ((a) = ((a) <  0  ) ? ((b)--, (a) + (m)) : (a))
#define is_exception_century(year)	(((year) % 100 == 0) && !((year) % 400 == 0))

int days_in_month(int isleap, int month)								asm("TM64DIM");
int julian_days_by_month(int isleap, int month)							asm("TM64JDBM");
int safe_year(const int year)											asm("TM64SYR");
uint64_t seconds_between_years(int left_year, int right_year)			asm("TM64SBY");

#endif

