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

int ispexec(const char *fmt, ...)
{
	int			rc 	= 20;
    va_list     list;
    char 		buf[256];

	va_start(list, fmt);
	vsprintf(buf, fmt, list);
	va_end(list);

	rc = tsocmdf("ISPEXEC", buf);
	return rc;
}
