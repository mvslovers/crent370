#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "time64.h"
#include "__time64.h"

extern long     __ymdts(unsigned yr, unsigned mo, unsigned day);
#define ymd_to_scalar(y,m,d) __ymdts((y),(m),(d))

__asm__("\n&FUNC    SETC 'main'");
int main(int argc, char **argv)
{
	struct tm	date = {0};
	time64_t	result;
	time_t		t;
	struct tm   tmp_date;
	struct tm   *tmp;
	int		i;
	char	*p;
	utime64_t	uresult;
	double	d;

#if 0
	/* set time zone offset from TZ environment variable or CVTTZ if TZ does not exist */
	tzset();
	printf("time zone offset from __tzget() returned %d seconds\n", __tzget());
#endif

#if 0
	printf("ymd_to_scalar(1970,1,1)=%d\n", ymd_to_scalar(1970,1,1));
#endif

#if 0
	{
		__64 seconds;
		__64 days;

		/* static const time64_t seconds_in_gregorian_cycle = days_in_gregorian_cycle * 60LL * 60LL * 24LL; */
		__64_from_int(&days, days_in_gregorian_cycle);
		__64_mul_int(&days, 60 * 60 * 24, &seconds);
		printf("seconds_in_gregorian_cycle=%llu or 0x%016llX\n \n", seconds, seconds);
	}
#endif

	for(i=0; i < 10; i++) {
		uresult = utime64(NULL);
		printf("utime64(NULL) = 0x%016llX (%llu)\n", uresult, uresult);
		__64_divmod_u32(&uresult, 1000000, &uresult, &result);
		printf(" div 1000000  = 0x%016llX (%llu) remainder = %016llX (%llu)\n", 
			uresult, uresult, result, result);
	}
	printf("---------------------------------------------------\n");

	result = utime64(NULL);
	uresult = utime64(NULL);
	d = difftime64(uresult, result);
	printf("difftime64(uresult,result)==%f\n", d);
	printf("---------------------------------------------------\n");

	for(i=0; i < 10; i++) {
		result = utime64(NULL);
		uresult = utime64(NULL);
		__64_sub(&uresult, &result, &result);
		printf("utime64() - utime64() = 0x%016llX (%llu)\n", result, result);
	}
	printf("---------------------------------------------------\n");

	result = time64(NULL);
	printf("time64(NULL) = 0x%016llX (%llu)\n", result, result);
	if (result.u32[0]==0xFFFFFFFF) {
		p = "*** time64 failure ***\n";
	}
	else {
		tmp = gmtime64(&result);
		if (!tmp) {
			p = "*** gmtime64 failure ***\n";
		}
		else {
			p = asctime64(tmp);
			if (!p) p = "*** asctime64 failure ***\n";
		}
		printf("   GMT: %s", p);
		tmp = localtime64(&result);
		if (!tmp) {
			p = "*** gmtime64 failure ***\n";
		}
		else {
			p = asctime64(tmp);
			if (!p) p = "*** asctime64 failure ***\n";
		}
		printf(" local: %s", p);
	}
	printf("---------------------------------------------------\n");

#if 1
	memset(&date, 0, sizeof(date));

	date.tm_mon = 11;
	date.tm_mday = 1;
	date.tm_hour = 12;
	date.tm_min = 34;
	date.tm_sec = 45;

	printf("---------------------------------------------------\n");
	printf("Validate values at: https://www.epochconverter.com/\n");
	printf("Note: all values are for Jan 1 of each year.\n");
	printf("---------------------------------------------------\n");
	for(i=69; i < 1000; i++) {
		date.tm_year = i;
#if 0
		result = timegm64(&date);
		if (result.u32[0]==0xFFFFFFFF) {
			p = "*** timegm64 failure ***\n";
		}
		else {
			tmp = gmtime64(&result);
			if (!tmp) {
				p = "*** gmtime64 failure ***\n";
			}
			else {
				p = asctime64(tmp);
				if (!p) p = "*** asctime64 failure ***\n";
			}
		}
		printf("timegm64: Year:%d 0x%016llX %s", 1900+i, result, p);
#else
		result = mktime64(&date);
		if (result.u32[0]==0xFFFFFFFF) {
			p = "*** mktime64 failure ***\n";
		}
		else {
			tmp = gmtime64(&result);
			if (!tmp) {
				p = "*** gmtime64 failure ***\n";
			}
			else {
				p = asctime64(tmp);
				if (!p) p = "*** asctime64 failure ***\n";
			}
		}
		printf("mktime64: Year:%d 0x%016llX %s", 1900+i, result, p);
#endif

		tmp_date = date;
		t = mktime(&tmp_date);
		if (t==(time_t)-1) {
			p = "*** mktime failure ***\n";
		}
		else {
			tmp = gmtime(&t);
			if (!tmp) {
				p = "*** gmtime failure ***\n";
			}
			else {
				p = asctime(tmp);
				if (!p) p = "*** asctime failure ***\n";
			}
		}

		printf("  mktime: Year:%d         0x%08X %s", 1900+i, t, p);
		printf("---------------------------------------------------\n");
	}

	{
		result = time64(NULL);
		if (result.u32[0]==0xFFFFFFFF) {
			p = "*** timegm64 failure ***\n";
		}
		else {
			tmp = gmtime64(&result);
			if (!tmp) {
				p = "*** gmtime64 failure ***\n";
			}
			else {
				p = asctime64(tmp);
				if (!p) p = "*** asctime64 failure ***\n";
			}
		}
		printf("timegm64: Time NOW  0x%016llX GMT %s", result, p);

		tmp_date = date;
		t = time(NULL);
		if (t==(time_t)-1) {
			p = "*** mktime failure ***\n";
		}
		else {
			tmp = gmtime(&t);
			if (!tmp) {
				p = "*** gmtime failure ***\n";
			}
			else {
				p = asctime(tmp);
				if (!p) p = "*** asctime failure ***\n";
			}
		}

		printf("  mktime: Time NOW          0x%08X GMT %s", t, p);
		printf("---------------------------------------------------\n");
	}

	/*  */
	result.u32[0] = 0x7FFFFFFF;
	result.u32[1] = 0xFFFFFFFF;
	printf("1/2 Max value test 0x%08X%08X\n", result.u32[0], result.u32[1]);

	/* 18446744073709551615 */
	result.u32[0] = 0xFFFFFFFF;
	result.u32[1] = 0xFFFFFFFF;
	printf("Max value test 0x%08X%08X\n", result.u32[0], result.u32[1]);

	__64_init(&result);
	__64_sub_i32(&result, 1, &result);
	printf("result = 0 then result - 1 0x%08X%08X\n", result.u32[0], result.u32[1]);
#endif
	return 0;
}

