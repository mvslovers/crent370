/* GETENV.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "clibenv.h"
#include "cliblock.h"
#include "clibcrt.h"

char *
getenv(const char *name)
{
    CLIBGRT *grt    = __grtget();
    int     index;
	char    *result;

    lock(&grt->grtenv,0);
	result = __findenv(name, &index, 0);    /* same case */
	unlock(&grt->grtenv,0);

	return result;
}
