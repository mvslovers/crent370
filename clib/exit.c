/* EXIT.C */
#define STDLIB_C
#include <stdlib.h>
#include <stddef.h>

void __exit(int status) __attribute__((noreturn));

__PDPCLIB_API__ void exit(int status)
{
    __exit(status);
}

