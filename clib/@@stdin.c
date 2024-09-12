/* @@STDIN.C - global variable */
#include <stdio.h>
extern FILE __perm[3];

FILE *__stdin = &__perm[0];
