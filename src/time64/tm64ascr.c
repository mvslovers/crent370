#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time64.h>
#include "__time64.h"

static char const wday_name[7][3] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static char const mon_name[12][3] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

__asm__("\n&FUNC    SETC 'valid_tm_wday'");
static int valid_tm_wday( const struct tm* date ) 
{
    if( 0 <= date->tm_wday && date->tm_wday <= 6 )
        return 1;
    else
        return 0;
}

__asm__("\n&FUNC    SETC 'valid_tm_mon'");
static int valid_tm_mon( const struct tm* date ) 
{
    if( 0 <= date->tm_mon && date->tm_mon <= 11 )
        return 1;
    else
        return 0;
}

__asm__("\n&FUNC    SETC 'asctime64_r'");
char *asctime64_r( const struct tm* date, char *result ) 
{
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
	if (result) {
	    snprintf(result, 26, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
    	    wday_name[date->tm_wday],
    	    mon_name[date->tm_mon],
    	    date->tm_mday, date->tm_hour,
    	    date->tm_min, date->tm_sec,
    	    1900 + date->tm_year);
	}

    return result;
}

