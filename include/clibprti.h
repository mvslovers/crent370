#ifndef CLIBPRTI_H
#define CLIBPRTI_H
/*
///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2014-2018, PALANDesign Hannover, Germany
//
// \license The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// \brief Tiny printf, sprintf and (v)snprintf implementation, optimized for speed on
//        embedded systems with a very limited resources. These routines are thread
//        safe and reentrant!
//        Use this instead of the bloated standard/newlib printf cause these use
//        malloc for printf (and may not be thread safe).
//
///////////////////////////////////////////////////////////////////////////////
*/

#include <stdarg.h>
#include <stddef.h>
#include "clibprtf.h"       /* CLIB public printf() functions */

/* 'ntoa' conversion buffer size, this must be big enough to hold one converted
// numeric number including padded zeros (dynamically created on stack)
// default: 32 byte
*/
#ifndef PRINTF_NTOA_BUFFER_SIZE
#define PRINTF_NTOA_BUFFER_SIZE    32U
#endif

/* 'ftoa' conversion buffer size, this must be big enough to hold one converted
// float number including padded zeros (dynamically created on stack)
// default: 32 byte
*/
#ifndef PRINTF_FTOA_BUFFER_SIZE
#define PRINTF_FTOA_BUFFER_SIZE    32U
#endif

/* support for the floating point type (%f)
// default: activated
*/
#ifndef PRINTF_DISABLE_SUPPORT_FLOAT
#define PRINTF_SUPPORT_FLOAT
#endif

/* support for the long long types (%llu or %p)
// default: activated
*/
#define PRINTF_DISABLE_SUPPORT_LONG_LONG
#ifndef PRINTF_DISABLE_SUPPORT_LONG_LONG
#define PRINTF_SUPPORT_LONG_LONG
#endif

/* support for the ptrdiff_t type (%t)
// ptrdiff_t is normally defined in <stddef.h> as long or long long type
// default: activated
*/
#define PRINTF_DISABLE_SUPPORT_PTRDIFF_T
#ifndef PRINTF_DISABLE_SUPPORT_PTRDIFF_T
#define PRINTF_SUPPORT_PTRDIFF_T
#endif

/* internal flag definitions */
#define FLAGS_ZEROPAD   (1U <<  0U)
#define FLAGS_LEFT      (1U <<  1U)
#define FLAGS_PLUS      (1U <<  2U)
#define FLAGS_SPACE     (1U <<  3U)
#define FLAGS_HASH      (1U <<  4U)
#define FLAGS_UPPERCASE (1U <<  5U)
#define FLAGS_CHAR      (1U <<  6U)
#define FLAGS_SHORT     (1U <<  7U)
#define FLAGS_LONG      (1U <<  8U)
#define FLAGS_LONG_LONG (1U <<  9U)
#define FLAGS_PRECISION (1U << 10U)
#define FLAGS_ZEROFILL  (1U << 11U)

/* output function type */
typedef void (*out_fct_type)(char character, void* buffer, size_t idx, size_t maxlen);

#ifndef bool
#define bool    int
#define true    1
#define false   0
#endif

/* wrapper (used as buffer) for output function type */
typedef struct {
  void  (*fct)(char character, void* arg);
  void* arg;
} out_fct_wrap_type;

struct printf_private {
    void            (*_out_buffer)(char character, void* buffer, size_t idx, size_t maxlen);
    void            (*_out_null)(char character, void* buffer, size_t idx, size_t maxlen);
    void            (*_out_char)(char character, void* buffer, size_t idx, size_t maxlen);
    void            (*_out_fct)(char character, void* buffer, size_t idx, size_t maxlen);
    unsigned int    (*_strlen)(const char* str);
    bool            (*_is_digit)(char ch);
    unsigned int    (*_atoi)(const char** str);
    size_t          (*_ntoa_format)(out_fct_type out, char* buffer, size_t idx, size_t maxlen,
                                    char* buf, size_t len, bool negative, unsigned int base,
                                    unsigned int prec, unsigned int width, unsigned int flags);
    size_t          (*_ntoa_long)(out_fct_type out, char* buffer, size_t idx, size_t maxlen,
                                  unsigned long value, bool negative, unsigned long base,
                                  unsigned int prec, unsigned int width, unsigned int flags);
    size_t          (*_ntoa_long_long)(out_fct_type out, char* buffer, size_t idx, size_t maxlen,
                                       unsigned long long value, bool negative, unsigned long long base,
                                       unsigned int prec, unsigned int width, unsigned int flags);
    size_t          (*_ftoa)(out_fct_type out, char* buffer, size_t idx, size_t maxlen,
                             double value, unsigned int prec, unsigned int width, unsigned int flags);
    int             (*_vsnprintf)(out_fct_type out, char* buffer, const size_t maxlen, const char* format,
                                  va_list va);
};

#ifdef PRINTF_PRIVATE
extern struct printf_private *__prtfx;
#define _out_buffer     (__prtfx->_out_buffer)
#define _out_null       (__prtfx->_out_null)
#define _out_char       (__prtfx->_out_char)
#define _out_fct        (__prtfx->_out_fct)
#define _strlen         (__prtfx->_strlen)
#define _is_digit(ch)   (__prtfx->_is_digit)
#define _atoi           (__prtfx->_atoi)
#define _ntoa_format    (__prtfx->_ntoa_format)
#define _ntoa_long      (__prtfx->_ntoa_long)
#define _ntoa_long_long (__prtfx->_ntoa_long_long)
#define _ftoa           (__prtfx->_ftoa)
#define _vsnprintf      (__prtfx->_vsnprintf)
#endif /* PRINTF_PRIVATE */

#endif
