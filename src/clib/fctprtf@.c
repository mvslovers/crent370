#define PRINTF_PRIVATE
#include <clibprti.h>

__asm__("\n&FUNC    SETC 'fctprintf_'");
int fctprintf_(void (*out)(char character, void* arg), void* arg, const char* format, ...)
{
  va_list va;
  out_fct_wrap_type out_fct_wrap;
  int ret;

  out_fct_wrap.fct = out;
  out_fct_wrap.arg = arg;

  va_start(va, format);
  ret = _vsnprintf(_out_fct, (char*)&out_fct_wrap, (size_t)-1, format, va);
  va_end(va);

  return ret;
}
