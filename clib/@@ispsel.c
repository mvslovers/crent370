#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <clib.h>
#include <clibssib.h>
#include <clibary.h>        /* dynamic array prototypes     */
#include <clibispf.h>		/* ISPF prototypes				*/
#include <cliblink.h>		/* __link()						*/
#include <clibtso.h>		/* tsocmd()						*/
#include <ikjcppl.h>		/* CPPL typedef 				*/
#include <ikject.h>			/* ECT typedef					*/

int isp_select(const char *fmt, ...)
{
	int			rc 	= 20;
    va_list     list;
    char 		buf[256];
    int			len;

	va_start(list, fmt);
	len = vsprintf(buf, fmt, list);
	va_end(list);

	rc = isplink("SELECT  ", &len, ISP_LAST(buf));
	return rc;
}
