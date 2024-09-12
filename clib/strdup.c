#include <stdlib.h>
#include <clibstr.h>

char *strdup(const char *s)
{
    char    *str    = NULL;
    int     len;

    if (s) {
        len = strlen(s);

        str = calloc(1, len+1);
        if (str) memcpy(str, s, len);
    }

    return str;
}
