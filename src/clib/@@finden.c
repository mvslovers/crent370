/* @@FINDEN.C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "clibenv.h"
#include "clibcrt.h"
#include "cliblock.h"

char *
__findenv(const char *name, int *index, int nocase)
{
    CLIBGRT     *grt    = __grtget();
    int         empty   = -1;
    __ENVVAR    *envvar;
    int         i;

    if (name && grt->grtenv) {
        unsigned count = arraycount(&grt->grtenv);
        for(i=0; i < count; i++) {
            envvar = grt->grtenv[i];
            if (!envvar) {
                if (empty < 0) empty = i;
                continue;
            }
            if (!envvar->name) continue;

            if (nocase) {
                if (stricmp(envvar->name, name)==0) {
                    if (index) *index = i;
                    return envvar->value;
                }
            }
            else {
                if (strcmp(envvar->name, name)==0) {
                    if (index) *index = i;
                    return envvar->value;
                }
            }
        }
    }

    if (index) *index = empty;
    return NULL;
}
