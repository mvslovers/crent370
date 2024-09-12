/* @@75GHBA.C
** Get host by address
*/
#include "__75.h"
#include "socket.h"
#include "stdlib.h"
#include "string.h"
#include "clibcrt.h"

extern unsigned char *asc2ebc;

/* gethostbyaddr() */
__asm__("\n&FUNC    SETC 'gethostbyaddr'");
struct hostent *
gethostbyaddr(void *addr)
{
    CLIBCRT         *crt    = __crtget();
    struct hostent  *h      = NULL;
    int             len;
    int             i;
    PL75            pl;
    char            name[256];

    if (!crt) goto quit;

    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
    __asm__("XC\t0(256,%0),0(%0)    clear name buffer" : : "r" (name));

    /* crthoste[0]  A(alias) */
    /* crthoste[1]  addr */
    /* crthoste[2]  A(addr) */
    /* crthoste[3]  0 */
    /* crthoste[4]  hostent */
    crt->crthoste[0] = 0;
    crt->crthoste[1] = 0;
    crt->crthoste[2] = (unsigned)&crt->crthoste[1];
    crt->crthoste[3] = 0;
    h = (struct hostent*) &crt->crthoste[4];
    h->h_name        = crt->crthostn;
    h->h_aliases     = (char**)&crt->crthoste[0];
    h->h_addrtype    = AF_INET;
    h->h_length      = 4;
    h->h_addr_list   = (char**)&crt->crthoste[2];
    h = NULL;

    crt->crthostn[0] = 0;

    crt->crthoste[1] = *(unsigned*)addr;
    printf("__75ghba() addr=%08X, *addr=%08X\n",
        addr, *(unsigned*)addr);

    /* get host name for address */
    pl.r6   = (unsigned) name;              /* A(name) */
    pl.r7   = (unsigned) 18;                /* function code gethostbyaddr  */
    pl.r8   = (unsigned) crt->crthoste[1];  /* addr */

    __75(&pl);
    if (!name[0]) goto quit;

    /* success, we found host name for this IP address */
    h   = (struct hostent*) &crt->crthoste[4];
    len = strlen(name);

    if (len>=sizeof(crt->crthostn)) len = sizeof(crt->crthostn)-1;
    for(i=0;i < len; i++) {
        crt->crthostn[i] = name[i];
    }
    crt->crthostn[len] = 0;

quit:
    return h;
}
