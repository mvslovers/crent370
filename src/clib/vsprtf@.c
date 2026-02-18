#define PRINTF_PRIVATE
#include <clibprti.h>

__asm__("\n&FUNC    SETC 'vsprintf_'");
int vsprintf_(char* buffer, const char* format, va_list va)
{
  return _vsnprintf(_out_buffer, buffer, (size_t)-1, format, va);
}


