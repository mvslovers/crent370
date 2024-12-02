/* copied from https://www.metalc.guru/example3.html */

#ifdef __MVS__
#pragma pack(reset)
#endif    
#include 
#include 
#include 
#include 
#include "cvt.h"
#include "psa.h"
#include "metal.h"

#ifndef __MVS_
#include 
#endif

#define timerUnit 1.048576 

const char weekdays[7][11] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

const char weekdaysShort[7][4] = {
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat"
};

const char months[12][10] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const char monthsShort[12][4] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"
};

/*
Julian dates (abbreviated JD) are a continuous count of days and fractions
since noon Universal Time on January 1, 4713 BCE (on the Julian calendar).
The time scale that is the basis for Julian dates is Universal Time,
and that 0h UT corresponds to a Julian date fraction of 0.5.

Astronomical calculations include a year 0, so these dates are accordingly,
i.e. the year 4713 BC becomes astronomical year number -4712, etc.
In this system the year 0 is equivalent to 1 BC.

The Julian Day Number (JDN) is the integer assigned to a whole solar day in
the Julian day count starting from noon Greenwich Mean Time, with Julian day
number 0 assigned to the day starting at noon on January 1, 4713 BC,
For example, the Julian day number for January 1, 2000, was 2,451,545.

The Julian Date (JD) of any instant is the Julian day number for the preceding
noon in Greenwich Mean Time plus the fraction of the day since that instant.
Julian Dates are expressed as a Julian day number with a decimal fraction added.
For example, the Julian Date for 00:30:00.0 UT January 1,2013, is 2,456,293.520833.

The routines used here return integer results, so the JDN is starts at 00:00:00 on
January 1, -4712, which is day 0. Day one is January 2, -4712, January 1, 2013
is 2,456,293, etc.

The changeover from the Julian calendar to the Gregorian calendar occurred in
October of 1582. Specifically, for dates on or before 4 October 1582,
the Julian calendar is used; for dates on or after 15 October 1582,
the Gregorian calendar is used. There is a ten-day gap in calendar dates,
but no discontinuity in Julian dates or days of the week: 4 October 1582 (Julian)
is a Thursday, which begins at JD 2299159.5; and 15 October 1582 (Gregorian) is a
Friday, which begins at JD 2299160.5.

 Jean Meeus, Astronomical Algorithms (Richmod, Virginia: Willmann-Bell, 1991)

 */

extern int isYearLeapYear(int year)
{
    return ((year % 4) == 0) &&
            (!(((year % 100) == 0) && ((year % 400) != 0)));
}

extern int dayOfTheYEAR(int year, int month, int day)
{
    int doy;
    int K;
    int k;

    k = isYearLeapYear(year);

    if (k == 1)
    {
        K = 1;
    }
    else
    {
        K = 2;
    }

    doy = (int) ((275 * month) / 9) - K * (int) ((month + 9) / 12) + day - 30;

    return doy;
}

/*
 From yyyy.ddd to yyyy.mm.dd
 */
extern void dayOfYearToCalendar(int year, int *month, int *day)
{
    int K;
    int k;
    double M;
    double N;
    int D;

    M = 0;
    D = 0;
    N = *day;

    k = isYearLeapYear(year);

    if (k == 1)
    {
        K = 1;
    }
    else
    {
        K = 2;
    }

    if (N < 32)
    {
        M = 1;
    }
    else
    {
        M = (int) (((9 * (K + N)) / 275) + 0.98);
    }

    D = N - (int) (275 * M / 9) + K * (int) ((M + 9) / 12) + 30;

    *month = M;
    *day = D;

}

/*
 GREGORIAN_TO_JD  Determine Julian day number from Gregorian calendar date

 Name	Epoch	
Julian Date	12h Jan 1, 4713 BC
 */
extern int GregorianToJDN(int year, int month, int day)
{
    double JD;
    double A;
    double B;
    int y;
    int m;

    y = year;
    m = month;

    A = 0;
    B = 0;

    if (month == 1 || month == 2)
    {
        year -= 1;
        month += 12;
    }

    A = (int) (year / 100);

    if ((y <= 1582) && (m < 10) && (day < 5))
    {
        B = 0;
    }
    else
    {
        B = 2 - A + (int) (A / 4);
    }

    JD = (int) ((365.25 * (year + 4716))) + (int) ((30.6001 *
            (month + 1))) + day + B - 1524.5;

    return (int) (JD + 0.5);
}

extern int dayOfTheWeek(int JD)
{
    int dow;
    dow = (JD + 1) % 7;
    return dow;
}

extern int ISODayOfTheWeek(int JD)
{
    int dow;
    dow = JD % 7;
    return dow;
}

/*
ISO Ordinal date
YYYY-DDD
This system is sometimes incorrectly referred to as "Julian Date".
The astronomical Julian Date is a sequential count of the number
of days since day 0 beginning 1 January 4713 BC Greenwich noon,
Julian proleptic calendar.
 */

extern int ISODayToJulianDN(int year, int day)
{
    return (day - 1) + GregorianToJDN(year, 1, 1);
}

/*
Unix Time
Epoch            Calculation
0h Jan 1, 1970	(JD - 2440587.5) × 86400
The number of seconds elapsed since 00:00 Universal time on January 1,
1970 in the Gregorian calendar (Julian day 2440587.5).
 */
extern int UnixTime(int JD)
{
    int ut;

    ut = (JD - 2440587) * 86400;

    return ut;
}

/*
ANSI Date	Jan 1, 1601 (1)	floor (JD - 2305812.5)
The ANSI Date defines January 1, 1601, as day 1, and is used as the origin
of COBOL integer dates.
This epoch is the beginning of the previous 400-year cycle of leap years
in the Gregorian calendar, which ended with the year 2000.
 */
extern int ANSIDate(int JD)
{
    int ad;

    ad = JD - 2299159;

    return ad;

}

/*
 Lilian date
 Epoch            Calculation
Oct 15, 1582	floor (JD - 2299159.5)

Used by IBM Language Environment (LE) software.
 */

extern int LilianDate(int JD)
{
    int ld;

    ld = JD - 2299159 + 1;

    return ld;
}

/*
 IBM TOD Clock to JDN
 Epoch
 January 1, 1900 = JDN 2415021

z/Architecture Principles of Operation

Time-of-Day Clock
The time-of-day (TOD) clock provides a high-resolution
measure of real time suitable for the indication of
date and time of day. The cycle of the clock is
approximately 143 years. A single TOD clock is
shared by all CPUs in the configuration.

Format
The TOD clock is a 104-bit register. It is a binary
counter with the format shown in the following illustration.

The TOD clock nominally is incremented by adding a
one in bit position 51 every microsecond. In models
having a higher or lower resolution, a different bit
position is incremented at such a frequency that the
rate of advancing the clock is the same as if a one
were added in bit position 51 every microsecond.
The resolution of the TOD clock is such that the
incrementing rate is comparable to the instruction
execution rate of the model.

Communication between systems is facilitated by
establishing a standard time origin that is the calendar
date and time to which a clock value of
zero corresponds. January 1, 1900, 0 a.m. Coordinated
Universal Time (UTC) is recommended
as this origin, and it is said to begin the standard
epoch for the clock.
 */

extern int TODToJDN(unsigned long long int TOD)
{
    long long int seconds;
    long long int days;
    long long int tod;

    tod = TOD / 4096;        // 52 bit accuracy
    seconds = tod / 1000000; // microseconds
    days = seconds / 86400;  // seconds in a day
    days += 2415021;

    return (int) days;

}

extern void JulianDNToGregorian(int JD, int *year, int *month, int *day)
{
    double Z;
    double F;
    double B;
    double C;
    double D;
    double E;
    double A;
    double alpha;

    Z = (int) (JD + .5);
    F = (int) Z - Z;

    if (Z < 2299161)
    {
        A = Z;
    }
    else
    {
        alpha = (int) ((Z - 1867216.25) / 36524.25);
        A = Z + 1 + alpha - (int) (alpha / 4);
    }
    B = A + 1524;
    C = (int) ( (B - 122.1) / 365.25);
    D = (int) ( 365.25 * C );
    E = (int) ( (B - D) / 30.6001 );

    *day = B - D - (int) (30.6001 * E) + F;

    if (E < 14)
    {
        *month = E - 1;
    }
    else
    {
        *month = E - 13;
    }
    if (*month > 2)
    {
        *year = C - 4716;
    }
    else
    {
        *year = C - 4715;
    }

}

#ifndef __MVS__
#define __CSE_CURRENT_VERSION __CSE_VERSION_1 
#define __CSE_VERSION_1 1    
int __stckf(unsigned long long *);
__csysenv_t __cinit(struct __csysenv_s *);
#endif

struct dateTime
{
    int  jdn;               // Julian Day Number
    int  Lilian;            // Lilian Date used by LE
    char yyyymmdd[9];       // e.g. 20141104
    char yyyymmdd2[11];     // e.g. 2014/11/04
    char yyyymmdd3[11];     // e.g. 2014-11-04
    int  dayOfWeek;         // 0 - 6
    char weekdayLong[9];    // Full text, e.g. "Monday"
    char weekdayShort[4];   // Abbrev. Text, e.g. "Mon"
    char time24[9];         // 24 hour hh:mm:ss
    char time12[9];         // 12 hour hh:mm:ss
    char ampm[3];           // AM or PM
    char tz[7];             // timezone from UTC: +/-hh:mm
    char monthLong[10];     // Full Text e.g. "January" 
    char monthShort[4];     // Abbrev. Month e.g. "Jan"
    char yyyyddd[9];        // yyyy.ddd
    char longDate[40];      // Tuesday, November 04, 2014 10:54:38AM
    char longDate2[21];     // YYYY-MM-DDTHH:MM:SSZ
    char longDate3[26];     // 2014-11-13T01:14:13+00:00
    
    struct
    {
        // Binary Representation of Fields
        short int tz;           // From (CVTTZ * 1.048576) / 3600
        short int dayOfYear;    // 1 - 366
        short int year;
        short int month;
        short int day;
        short int hour12;
        short int hour24;
        short int minute;
        short int second;
    } bin;
} ;

/* 
Get Current Date Time Value Using Store Clock Fast

The TOD clock is a 104-bit register. 
The TOD clock nominally is incremented by adding a
one in bit position 51 every microsecond. 
 
STORE CLOCK FAST
STCKF Op1D(Op1B)
The current value of bits 0-63 of the TOD clock is
stored in the eight-byte field designated by the second-
operand address, provided the clock is in the
set, stopped, or not-set state.

For STORE CLOCK FAST, when the value of a running clock is stored,
bits to the right of the rightmost bit that is incremented are
stored as zeros.

 Offsets
Dec Hex Type/Value Len Name (Dim) Description 
304 (130) SIGNED   4 CVTTZ - Difference between local time and UTC (Coordinated Universal
                             Time) in binary units of 1.048576 seconds. 
328 (148) ADDRESS  4 CVTEXT2 (0) - ADDRESS OF OS/VS1 - OS/VS2 COMMON EXTENSION 
56  (38)  DBL WORD 8 CVTLDTO (0) LOCAL TIME/DATE OFFSET 
80  (50)  DBL WORD 8 CVTLSO  (0) LEAP SECOND OFFSET IN TOD FORMAT 

UtcTime = StckTimeStamp - CVTLSO
LocalTime = StckTimeStamp + CVTLDTO - CVTLSO 
 */

int getDate(struct dateTime *_dateTime)
{
    int rc;
    unsigned long long int TOD;
    int days;
    int year;
    int month;
    int day;
    int remainder;
    int hour12;
    int hour24;
    int minute;
    int second;

    double tod;
    double diffSeconds;
    double diffLeapSeconds;
    long long int seconds;
    
    int ttz;

    // FFFFCA5B17000000
    
    tod = 0;
    diffSeconds = 0;
    diffLeapSeconds = 0;
    seconds = 0;
    rc = 0;
   
    memset(_dateTime,0,sizeof(struct dateTime));

#ifndef __MVS__  
 // (CE0E7F886BFCA21E)16 = (14847945245391102494)10
 //  date time ˜ Friday, 2014/11/14 20:44:15        
    TOD = 14847945245391102494ull;
    ttz = 0xFFFFCA5B;
    diffSeconds = ttz * 1.048576;
#endif
    
#ifdef __MVS__
    struct psa *_psa;
    struct cvt *_cvt;
    struct cvtxtnt2 *_cvtxtnt2;
    struct __csysenv_s _sysenv;
    __csysenv_t _envtkn;
      
    /* The __cinit() function establishes a Metal C 
     environment based on the characteristics in the input
     csysenv structure.*/

    // Initialize the csysenv structure.
    memset(&_sysenv, 0x0, sizeof(_sysenv));
    _sysenv.__cseversion = __CSE_VERSION_1;

    // Set heap initial and increment sizes. 
    _sysenv.__cseheap31initsize = 65536;
    _sysenv.__cseheap31incrsize = 8192;
    _sysenv.__cseheap64initsize = 20;
    _sysenv.__cseheap64incrsize = 1;

    // Create a Metal C environment. */
    _envtkn = __cinit(&_sysenv);

    // Locate CVT. PSA->CVT
    _psa  = (void *) (intptr_t) 0;          // PSA is at address 0
    _cvt =  _psa->_flccvt;                  // CVT pointer is at offset 16 of PSA
    _cvtxtnt2 = _cvt->cvtext2;              // CVT 2nd extension has TZ offset

    // Calculate Time/Date Offset - Add
    diffSeconds = _cvtxtnt2->cvtldto._cvtldtol; // LOCAL TIME/DATE OFFSET
    diffSeconds *= timerUnit;               // Multiply by clock timer units
 
    // Calculate Leap Seconds     - Subtract
    diffLeapSeconds = _cvtxtnt2->cvtlso;    // Leap Seconds Difference in TOD
    diffLeapSeconds *= timerUnit;           // Multiply by clock timer units
 
    rc = __stckf(&TOD);                     // Use store clock fast to get TOD
#endif
    
    tod     = TOD  / 4096;                  // 51 bit accuracy = microseconds
    seconds = tod / 1000000;                // microseconds to seconds
   
    seconds += diffSeconds;                 // Add in time zone difference
    seconds -= diffLeapSeconds;             // Subtract Leap Seconds
    days     = seconds / 86400;             // seconds in a day
    days    += 2415021;                     // Add in JDN Offset for 1900/01/01
  
    _dateTime->jdn = days;
    remainder = seconds % 86400;

    hour24    = remainder / 3600;
    minute    = (remainder % 3600) / 60;
    second    = remainder % 60;
    
    strcpy(_dateTime->ampm, "AM");
    
    if (hour24 > 12)
    {
        hour12 = hour24 % 12;
        strcpy(_dateTime->ampm, "PM");
    }
    
    _dateTime->bin.hour24 = hour24;
    _dateTime->bin.hour12 = hour12;
    _dateTime->bin.minute = minute;
    _dateTime->bin.second = second;
    _dateTime->bin.tz      = diffSeconds / (double) 3600;

    JulianDNToGregorian(days, &year, &month, &day);
    _dateTime->Lilian =  LilianDate(_dateTime->jdn);

    _dateTime->bin.year = year;
    _dateTime->bin.month = month;
    _dateTime->bin.day = day;
    
    strcpy(_dateTime->monthLong, months[month - 1]);
    strcpy(_dateTime->monthShort, monthsShort[month - 1]);

    sprintf(_dateTime->yyyymmdd, "%4.4i%2.2i%2.2i", year, month, day);
    sprintf(_dateTime->yyyymmdd2, "%4.4i/%2.2i/%2.2i", year, month, day);
    sprintf(_dateTime->yyyymmdd3, "%4.4i-%2.2i-%2.2i", year, month, day);

    sprintf(_dateTime->time24, "%2.2i:%2.2i:%2.2i", hour24,
            minute,second);

    sprintf(_dateTime->tz, "%+2.2i:00", _dateTime->bin.tz);

    sprintf(_dateTime->time12, "%2.2i:%2.2i:%2.2i", hour12, minute,second);

    _dateTime->dayOfWeek = dayOfTheWeek(days);
    strcpy(_dateTime->weekdayLong, weekdays[_dateTime->dayOfWeek]);
    strcpy(_dateTime->weekdayShort, weekdaysShort[_dateTime->dayOfWeek]);

    _dateTime->bin.dayOfYear = dayOfTheYEAR(year, month, day);
    sprintf(_dateTime->yyyyddd, "%4.4i.%3.3i", year, _dateTime->bin.dayOfYear);

    sprintf(_dateTime->longDate, "%s, %s %2.2i, %4.4i %s%s", _dateTime->weekdayLong,
            _dateTime->monthLong, _dateTime->bin.day, year,
            _dateTime->time12, _dateTime->ampm);

    // longDate2 YYYY-MM-DDTHH:MM:SSZ
    sprintf(_dateTime->longDate2, "%4.4i-%2.2i-%2.2iT%2.2i:%2.2i:%2.2i", 
             year, month, day, hour24, minute,second);

    // longDate3 2014-11-13T01:14:13+00:00
    sprintf(_dateTime->longDate3, "%4.4i-%2.2i-%2.2iT%2.2i:%2.2i:%2.2i%6.6s", 
             year, month, day, hour24, minute,
           second, _dateTime->tz);

#ifdef __MVS__
    __cterm((__csysenv_t) _envtkn);
#endif    

    return rc;

}
#ifndef __MVS_
int main()
{
    struct dateTime _dateTime;
    // Test Date: Friday 11/14/2014
    getDate(&_dateTime);
    
    printf("long date: %s\n",_dateTime.longDate);
    printf("long date2: %s\n",_dateTime.longDate2);
    printf("long date3: %s\n",_dateTime.longDate3);
    
    printf("jdn: %i\n",_dateTime. jdn);                   // Julian Day Number
    printf("Lilian: %i\n",_dateTime.Lilian);              // Lilian Date used by LE
    printf("yyyymmdd: %s\n", _dateTime.yyyymmdd);          // e.g. 20141104
    printf("yyyymmdd2: %s\n",_dateTime.yyyymmdd2);        // e.g. 2014/11/04
    printf("yyyymmdd3: %s\n", _dateTime.yyyymmdd3);        // e.g. 2014-11-04
    printf("dayOfWeek: %i\n" , _dateTime.dayOfWeek);       // 0 - 6
    printf("weekdayLong: %s\n", _dateTime.weekdayLong);    // Full text, e.g. "Monday"
    printf("weekdayShort: %s\n", _dateTime.weekdayShort);   // Abbrev. Text, e.g. "Mon"
    printf("time24: %s\n", _dateTime.time24);               // 24 hour hh:mm:ss
    printf("time12: %s\n",_dateTime.time12);               // 12 hour hh:mm:ss
    printf("ampm: %s\n", _dateTime.ampm);                   // AM or PM
    printf("tz: %s\n", _dateTime.tz);                       // timezone from UTC: +/-hh:mm
    printf("monthLong: %s\n",_dateTime.monthLong);         // Full Text e.g. "January" 
    printf("monthShort: %s\n",_dateTime.monthShort);       // Abbrev. Month e.g. "Jan"
    printf("yyyyddd: %s\n",_dateTime.yyyyddd);             // yyyy.ddd
    
    printf("tz: %i  \n",_dateTime.bin.tz);           
    printf("day:%i   \n",_dateTime.bin.dayOfYear);    
    printf("yr: %i  \n",_dateTime.bin.year); 
    printf("month: %i  \n",_dateTime.bin.month); 
    printf("day:  %i \n",_dateTime.bin.day); 
    printf("hour12: %i  \n",_dateTime.bin.hour12); 
    printf("hour24: %i  \n",_dateTime.bin.hour24); 
    printf("min: %i  \n",_dateTime.bin.minute); 
    printf("sec: %i  \n",_dateTime.bin.second); 
   
    return 0;
 }

#endif

