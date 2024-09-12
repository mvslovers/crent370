#define PRINTF_PRIVATE
#include <clibprti.h>

__asm__("\n&FUNC    SETC 'snprintf_'");
int snprintf_(char* buffer, size_t count, const char* format, ...)
{
    va_list va;
    int     ret;

    va_start(va, format);
    ret = _vsnprintf(_out_buffer, buffer, count, format, va);
    va_end(va);

    return ret;
}

