/* @@PATMAT.C - pattern match */
#include "clibstr.h"

int
__patmat( const char *str, const char *pat )
{
    if ( *pat == 0 ) {
        while( *str == ' ' ) str++;
        if ( *str == 0 ) {
             goto matched;
        }
        goto nomatch;
    }

    if ( *pat == '*' ) {
        while(*(pat+1)=='*') pat++;
        if ( *(pat+1) == 0 ) {
            goto matched;
        }

        while(*(++str)) {
            if (*str == *(pat+1) || (*(pat+1) == '?')) {
                if (__patmat(str + 1, pat + 2)) {
                    goto matched;
                }
            }
        }
        goto nomatch;
    }

    if ( *str == 0 ) {
        goto nomatch;
    }

    if ( (*pat == '?') || (*str == *pat) ) {
        if (__patmat(str + 1, pat + 1)) {
            goto matched;
        }
    }

nomatch:
    return 0;

matched:
    return 1;
}
