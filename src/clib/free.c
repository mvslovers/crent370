/* FREE.C */
#define STDLIB_C
#include "stdlib.h"
#include "signal.h"
#include "string.h"
#include "ctype.h"
#include "stddef.h"
#include "mvssupa.h"

#if USE_MEMMGR
#include "__memmgr.h"
/* GCCMVS 3.4.6 requires 49 MB minimum for full optimization */
/* so we give it 60. GCCMVS 3.2.3 only requires 20 MB */
/* Note that you can set MAX_CHUNK to less than REQ_CHUNK */
/* But don't do this until MVS/380 etc have been changed to */
/* allow multiple memory requests. */
#if defined(MULMEM)
#define MAX_CHUNK 60000000
#define REQ_CHUNK 60000000
#else
#define MAX_CHUNK 60000000 /* maximum size we will store in memmgr */
#define REQ_CHUNK 60000000 /* size that we request from OS */
#endif

void *__lastsup = NULL; /* last thing supplied to memmgr */
#endif

__PDPCLIB_API__ void free(void *ptr)
{
#if USE_MEMMGR
    if (ptr != NULL) {
        size_t size;

        size = *((size_t *)ptr - 1);
        if (size > MAX_CHUNK) {
#if defined(MULMEM)
            /* Ignore, unless MULMEM is defined, until MVS/380 is fixed */
            __freem(ptr);
#endif
        }
        else
        {
            memmgrFree(&__memmgr, ptr);
        }
    }
#else /* not using MEMMGR */
#if 0 /* debug free problem */
    char caller[256] = "";
    __caller(caller);
    wtof("free(%08X) called by %s", ptr, caller);
#endif /* debug free problem */
    if (ptr) {
        __freem(ptr);
    }

#endif /* not USE_MEMMGR */
    return;
}
