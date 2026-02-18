#define PRINTF_PRIVATE
#include <clibprti.h>

__asm__("\n&FUNC    SETC 'sprintf_'");
int sprintf_(char* buffer, const char* format, ...)
{
    va_list va;
    int     ret;

    va_start(va, format);
    ret = _vsnprintf(_out_buffer, buffer, (size_t)-1, format, va);
    va_end(va);

    return ret;
}
