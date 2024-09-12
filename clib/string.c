#define LIB_STRING
#define STRING_C
#include "string.h"

static STRING   lib = {
    memcpy,
    memmove,
    strcpy,
    strncpy,
    strcat,
    strncat,
    memcmp,
    strcmp,
    strcoll,
    strncmp,
    strxfrm,
    memchr,
    strchr,
    strcspn,
    strpbrk,
    strrchr,
    strspn,
    strstr,
    strtok,
    memset,
    strerror,
    strlen,
    strcpyp,
    memcpyp,
    __patmat,
};

STRING  *string = &lib;
