#define PRINTF_PRIVATE
#include <clibprti.h>

__asm__("\n&FUNC    SETC 'vsnprintf_'");
int vsnprintf_(char* buffer, size_t count, const char* format, va_list va)
{
  return _vsnprintf(_out_buffer, buffer, count, format, va);
}

