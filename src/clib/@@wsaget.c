#define CLIB_C
#include <stdio.h>
#include <stdlib.h>
#include "clib.h"
#include "clibary.h"
#include "cliblock.h"

void *
__wsaget(void *key, unsigned len)
{
    CLIBGRT     *grt    = __grtget();
    CLIBWSA     *wsa    = 0;
    unsigned    size    = sizeof(CLIBWSA) + len;
    unsigned    count;

    lock(&grt->grtwsa,0);
    count = arraycount(&grt->grtwsa);
    while(count > 0) {
        count--;
        wsa = grt->grtwsa[count];
        if (!wsa) continue;
        if (wsa->wsakey == key && wsa->wsasize == size) break;
        wsa = 0;
    }

    if (!wsa) {
        wsa = calloc(1, size);
        if (wsa) {
            strcpy(wsa->wsaeye, CLIBWSA_EYE);
            wsa->wsakey     = key;
            wsa->wsasize    = size;
            if ((unsigned)key > 0x00002000 && (unsigned)key < 0xFF000000) {
                /* key *should* be an initializer structure pointer */
                memcpy(wsa->wsastart, key, len);
            }
            if (arrayadd(&grt->grtwsa, wsa)) {
                /* failed, likely out of memory */
                wtof("__wsaget() error adding new writable static area");
                free(wsa);
                wsa = 0;
            }
        }
        else {
            wtof("__wsaget() out of memory for requested size %u bytes", size);
        }
    }
    unlock(&grt->grtwsa,0);

    return (void*)(wsa ? wsa->wsastart : 0);
}
