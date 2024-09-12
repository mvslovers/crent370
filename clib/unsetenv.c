/* UNSETENV.C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "clibenv.h"
#include "clibary.h"
#include "cliblock.h"
#include "clibcrt.h"

int
unsetenv(const char *name)
{
    CLIBGRT     *grt    = __grtget();
    __ENVVAR    *envvar;
    int         i;

    lock(&grt->grtenv,0);
    if (name && grt->grtenv) {
        unsigned count = arraycount(&grt->grtenv);
        for(i=0; i < count; i++) {
            envvar = grt->grtenv[i];
            if (!envvar) continue;
            if (!envvar->name) {
                free(envvar);
                grt->grtenv[i] = NULL;
                continue;
            }

            if (strcmp(envvar->name, name)==0) {
                free(envvar);
                grt->grtenv[i] = NULL;
                continue;
            }
        }
    }
    unlock(&grt->grtenv,0);

    return 0;
}
