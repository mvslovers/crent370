#define PRINTF_PRIVATE
#include <clibprti.h>

__asm__("\n&FUNC    SETC 'printf_'");
int printf_(const char* format, ...)
{
    va_list va;
    int     ret;
    char    buffer[1];

    va_start(va, format);
    ret = _vsnprintf(_out_char, buffer, (size_t)-1, format, va);
    va_end(va);

    return ret;
}
