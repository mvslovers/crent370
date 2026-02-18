/* @@STDERR.C - global variable */
#include <stdio.h>
extern FILE __perm[3];

FILE *__stderr = &__perm[2];
