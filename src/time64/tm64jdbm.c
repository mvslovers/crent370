#include <time64.h>
#include <__time64.h>

static const int jdbm[2][12] = {
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
    {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
};

__asm__("\n&FUNC    SETC 'julian_days_by_month'");
int julian_days_by_month(int isleap, int month)
{
	return jdbm[isleap][month];
}

