#ifndef CLIBWTO_H
#define CLIBWTO_H
#include <stdarg.h>
#include <clibsa.h>

extern void wto(char *buf);

extern void vwtof(const char *text, va_list tList);

extern void wtof(const char *text, ...);

extern void wtodumpf(void *buf, int len, const char *fmt, ...);

extern void wtodump(const char *title, void *varea, int size, int chunk);

extern void wto_traceback(SAVEAREA *sa) asm("@@WTOTB");

/* write to operator with reply */
extern void wtorf(char *reply, unsigned replymax, const char *text, ...);
extern void wtor(char *reply, unsigned replymax, const char *text);

#endif
