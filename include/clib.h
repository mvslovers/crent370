#ifndef CLIB_H
#define CLIB_H

#include <clibcrt.h>
#include <clibwto.h>
#include <clibgrt.h>
#include <clibppa.h>
#include <clibos.h>

#define __getcrt()              (__crtget())
#define __rescrt()              (__crtres())
#define __setcrt()              (__crtset())
#define __getgrt()              (__grtget())
#define __resgrt()              (__grtres())
#define __setgrt()              (__grtset())
#define __getwsa(key,len)       (__wsaget((key),(len)))
#define __getjpa()              (__jpaget())

#endif

