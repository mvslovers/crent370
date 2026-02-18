#include <time64.h>
#include <__time64.h>

/* days in month */
static const int dim[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

__asm__("\n&FUNC    SETC 'days_in_month'");
int days_in_month(int isleap, int month)
{
	return dim[isleap][month];
}

