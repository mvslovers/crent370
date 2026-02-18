#define LIB_CLIB
#define CLIB_C
#include "clib.h"
#include "mvssupa.h"

int gettzoff(void);

static CLIB lib = {
    __crtget,
    __crtres,
    __crtset,
    __grtget,
    __grtres,
    __grtset,
    __wsaget,
    __jpaget,
    __aopen,
    __aread,
    __awrite,
    __aclose,
    __getclk,
    __gettz,
    __getm,
    __freem,
    __dynal,
    __idcams,
    gettzoff,
    wto,
    vwtof,
    wtof,
    wtodumpf,
    wtodump,
};

CLIB    *clib = &lib;
