/* GETS.C */
#include <stdio.h>
#include <limits.h>
#include <string.h>

char *
gets(char *s)
{
    char            *ret;

    ret = fgets(s, INT_MAX, stdin);
    if (ret) {
        char *p = strchr(s, '\n');
        if (p) *p = 0;
    }
    return ret;
}
