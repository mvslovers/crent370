#include "ipci.h"

/* ipc_connect_host_port() - create new channel to host, port */
IPCC *
ipc_connect_host_port(IPC *ipc, const char *host, const char *port)
{
    IPCC            *ipcc   = NULL;
    unsigned        uaddr   = 0x7F000001;   /* default is 127.0.0.1 */
    unsigned short  uport   = 0;

    if (host) {
        uaddr =	getaddrbyname(host);
        if (!uaddr) {
            wtof("%s: Unable to resolve host name: \"%s\"", __func__, host);
            goto quit;
        }
    }

    if (port) {
        unsigned u = strtoul(port, NULL, 0);
        if (u > 0x0000FFFF) {
            wtof("%s: Invalid port number: %u", __func__, u);
            goto quit;
        }
        uport = (unsigned short)u;
    }

    /* connect to address, port */
    ipcc = ipc_connect_addr_port(ipc, uaddr, uport);

quit:
    return ipcc;
}
