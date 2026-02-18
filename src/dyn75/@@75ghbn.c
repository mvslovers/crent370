/* @@75GHBN.C
** Get host by name
**
** Note: the interface provided by DYN75 only returns a single IP
** address for any given name.  As such, the hostent we return
** is very limited and does not contain any additional information.
*/
#include "socket.h"
#include "stdlib.h"
#include "string.h"
#include "clibcrt.h"

/* gethostbyname() */
__asm__("\n&FUNC    SETC 'gethostbyname'");
struct hostent *
gethostbyname(const char *name)
{
    CLIBCRT         *crt    = __crtget();
    struct hostent  *h      = NULL;
    int             len;

    if (!crt) goto quit;

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

    crt->crthoste[1] = getaddrbyname(name);
    if (!crt->crthoste[1]) goto quit;

    /* success, we found an IP address for this name */
    h   = (struct hostent*) &crt->crthoste[4];
    len = strlen(name);

    if (len>=sizeof(crt->crthostn)) len = sizeof(crt->crthostn)-1;
    memcpy(crt->crthostn, name, len);
    crt->crthostn[len] = 0;

quit:
    return h;
}
