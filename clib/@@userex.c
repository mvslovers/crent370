/* @@USEREX.C */
#include "stdlib.h"
#include "signal.h"
#include "string.h"
#include "ctype.h"
#include "stddef.h"
#include "mvssupa.h"

void (*__userex[__NATEXIT])(void) = {0};
