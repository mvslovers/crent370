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
#ifndef TIME64_H
#define TIME64_H
#if defined(__LP64__)
#error Your time_t is already 64-bit.
#else
/* Legacy cruft for LP32 where time_t was 32-bit. */
#include <time.h>	/* legacy time_t and function prototypes */
#include <stdint.h>	/* standard types int32_t, uint32_t, uint64_t, ... */
#include <clib64.h>	/* __64 union typedef and related function prototypes */

/* Notes about time:
 * In general time values have been represented as the number of seconds
 * since midnight January 1 1970 (epoch). In the earlier years a single 
 * 31 bit (int) or 32 bit (unsigned int) value was used.
 * 
 * More modern "time" implementations are now using 63 bit (long long)
 * or 64 bit (unsigned lonh long) values while keeping the same epoch.
 * 
 * To that extent we have the prototypes listed below in this header 
 * file in support of 64 bit values using the __64 type (see clib64.h).
 * 
 * Extensions are also provided for mtime64_t and utime64_t values.
 */

/* clock64_t is unsigned long long 64 bit value with seconds resulution */
typedef uint64_t	clock64_t;	/* unsigned long long variable */

/* mclock64_t is unsigned long long 64 bit value with miliseconds resulution .001 */
typedef uint64_t	mclock64_t; /* unsigned long long variable 1ms = .001 seconds*/

/* uclock64_t is unsigned long long 64 bit value with microseconds resulution .000001 */
typedef uint64_t	uclock64_t; /* unsigned long long variable 1us = .000001 seconds */

/* make time64_t a __64 struct (8 bytes or 64 bits) seconds resulution */
typedef __64 		time64_t;	/* union with unsigned long long as primary u64 variable */ 

/* make utime64_t a __64 struct (8 bytes or 64 bits) micro seconds resolution */
typedef __64 		mtime64_t;	/* can be converted to time64_t by dividing by 1000 */ 

/* make utime64_t a __64 struct (8 bytes or 64 bits) micro seconds resolution */
typedef __64 		utime64_t;	/* can be converted to time64_t by dividing by 1000000 */ 

/* get system time value GMT as uint64_t value */
clock64_t clock64(void)													asm("TM64CLCK"); /* get system clock sec */
mclock64_t mclock64(void)												asm("TM64MCLK"); /* get system clock msec */
uclock64_t uclock64(void)												asm("TM64UCLK"); /* get system clock usec */

/* get system time value GMT as time64_t value */
time64_t time64(time64_t *timer)										asm("TM64TIME"); /* get system time sec */
mtime64_t mtime64(mtime64_t *itimer)									asm("TM64MTIM"); /* get system time msec */
utime64_t utime64(utime64_t *itimer)									asm("TM64UTIM"); /* get system time usec */

/* difference between times */
double difftime64(time64_t time1, time64_t time0)						asm("TM64DTIM");

/* create time value from struct tm */
time64_t timegm64(const struct tm*)										asm("TM64TGM");
time64_t mktime64(struct tm*)											asm("TM64MKT");

/* create struct tm from time value GMT */
struct tm* gmtime64(const time64_t*)									asm("TM64GMT");
struct tm* gmtime64_r(const time64_t*, struct tm*)						asm("TM64GMTR");
struct tm* mgmtime64(const mtime64_t*)									asm("TM64MGMT");
struct tm* ugmtime64(const utime64_t*)									asm("TM64UGMT");

/* create struct tm from time value with adjustment for local time zone */
struct tm* localtime64(const time64_t*)									asm("TM64LTM");
struct tm* localtime64_r(const time64_t*, struct tm*)					asm("TM64LTMR");
struct tm* mlocaltime64(const mtime64_t*)								asm("TM64MLTM");
struct tm* ulocaltime64(const utime64_t*)								asm("TM64ULTM");

/* return pointer to formatted string from struct tm */
char* asctime64(const struct tm*)										asm("TM64ASC");
char* asctime64_r(const struct tm*, char*)								asm("TM64ASCR");

/* return pointer for formatted string from time value pointer */
char* ctime64(const time64_t*)											asm("TM64CTI");
char* ctime64_r(const time64_t*, char*)									asm("TM64CTIR");
char* mctime64(const mtime64_t*)										asm("TM64MCTI");
char* uctime64(const utime64_t*)										asm("TM64UCTI");


#endif
#endif /* TIME64_H */

