/* MALLOC.C */
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

extern void (*__userex[__NATEXIT])(void);

__PDPCLIB_API__ void *malloc(size_t size)
{
#if USE_MEMMGR
    void *ptr;

    if (size > MAX_CHUNK)
    {
#if defined(MULMEM)
        /* If we support multiple memory requests */
        ptr = __getm(size);
#else
        ptr = NULL;
#endif
    }
    else
    {
        ptr = memmgrAllocate(&__memmgr, size, 0);
        if (ptr == NULL)
        {
            void *ptr2;

            /* until MVS/380 is fixed, don't do an additional request,
               unless MULMEM is defined */
#if defined(MULMEM)
            if (1)
#else
            if (__memmgr.start == NULL)
#endif
            {
                ptr2 = __getm(REQ_CHUNK);
            }
            else
            {
                ptr2 = NULL;
            }
            if (ptr2 == NULL)
            {
                return (NULL);
            }
            __lastsup = ptr2;
            memmgrSupply(&__memmgr, ptr2, REQ_CHUNK);
            ptr = memmgrAllocate(&__memmgr, size, 0);
        }
    }
    return (ptr);
#else /* not MEMMGR */
    void *ptr;

#define MAX_CHUNK	(6 * 1024 * 1024)	/* 6M */
    if (size > MAX_CHUNK) {
		ptr = NULL;
	}
	else {
		ptr = (__getm(size));
	}
	
    if (!ptr) {
        wtof("Out of memory, bytes needed=%u", size);
        __wtotb(0);
    }
    return ptr;
#endif /* not MEMMGR */
}
