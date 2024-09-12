/* @@STDOUT.C - global variable */
#include <stdio.h>
extern FILE __perm[3];

FILE *__stdout = &__perm[1];
