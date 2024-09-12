#ifndef CLIBPRTF_H
#define CLIBPRTF_H

extern int printf_(const char* format, ...);

extern int sprintf_(char* buffer, const char* format, ...);

extern int snprintf_(char* buffer, size_t count, const char* format, ...)       asm("SNPRTF@");

extern int vsprintf_(char* buffer, const char* format, va_list va)              asm("VSPRTF@");

extern int vsnprintf_(char* buffer, size_t count, const char* format, va_list va) asm("VSNPRTF@");

extern int fctprintf_(void (*out)(char character, void* arg), void* arg, const char* format, ...) asm("FCTPRTF@");


#endif
