#ifndef STDIO_H
#define STDIO_H

#include "clibio.h"

#if 0
#undef  stdin
#define stdin                   (*(stdio->___gtin()))
#undef  stdout
#define stdout                  (*(stdio->___gtout()))
#undef  stderr
#define stderr                  (*(stdio->___gterr()))
#endif // 0

#endif
