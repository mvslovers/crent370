/* SETENV.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibenv.h"
#include "cliblock.h"
#include "clibcrt.h"

/*
 * setenv --
 *	Set the value of the environmental variable "name" to be
 *	"value".  If rewrite is set, replace any current value.
 *
 * If caller by putenv() we might have had an original string
 * like "name=value" or "  name   =  value" that was parsed
 * using the '=' character, so we need to remove leading and trailing
 * spaces from the "  name   " and leading spaces from the "  value".
 */
int
setenv(const char *name, const char *value, int rewrite)
{
    CLIBGRT     *grt    = __grtget();
    int         err     = 0;
	size_t      l_name, l_value, length;
	int         index;
	char        *found;
	__ENVVAR    *envvar;

    lock(&grt->grtenv,0);

    while(*name==' ') name++;                   /* skip leading spaces */
	l_name = name ? strlen(name) : 0;
	while(l_name > 0 && name[l_name-1]==' ') l_name--;  /* trim */
	if (l_name == 0 || value == NULL) {
		err = 1;
		goto quit;
	}

    /* see if we have this name in the environment variables            */
    /* note: we want to replace exact match variables if possible       */
    found = __findenv(name, &index, 0);             /* same case        */
    if (!found) found = __findenv(name, &index, 1); /* try caseless     */
    if (found && !rewrite) {
        /* found it, but rewrite not desired */
        goto quit;
    }

    /* allocate a new environment variable */
    while(*value==' ') value++;                 /* remove leading spaces */
	l_value = strlen(value);
	length = l_name + l_value + sizeof(__ENVVAR);
    envvar = calloc(1, length);
    if (!envvar) {
        err = 1;
        goto quit;
    }
    envvar->name    = &envvar->buf[0];
    envvar->value   = &envvar->buf[l_name+1];
    memcpy(envvar->name, name, l_name);
    memcpy(envvar->value, value, l_value);

    if (index >= 0) {
        if (found) {
            /* replace environment variable */
            free(grt->grtenv[index]);
            grt->grtenv[index]=envvar;
        }
        else {
            /* save new environment variable in empty slot */
            grt->grtenv[index] = envvar;
        }
        goto quit;
    }

    /* add new environment variable */
    err = arrayadd(&grt->grtenv, envvar);
    if (err) free(envvar);

quit:
    unlock(&grt->grtenv,0);
    return err;
}
