/* @@75VECT.C
** TCPIP Vector
*/
#include "__75.h"
#include "socket.h"

#if 0
extern unsigned __75gabn(const char *name);
extern struct hostent * __75ghbn(const char *name);
extern int __75sock(int af, int type, int protocol);
extern int __75bind(int ss, struct sockaddr_in * name, int length);
extern int __75conn(int ss, struct sockaddr_in *name, int length);
extern int __75list(int ss, int backlog);
extern int __75acce(int ss, struct sockaddr_in *name, int *length);
extern int __75send(int ss, const void *buf, int len, int flags);
extern int __75recv(int ss, void *buf, int len, int flags);
extern int __75clos(int ss);
extern int __75ioct(int ss, int cmd, void *argp);
extern int __75snam(int ss, struct sockaddr *addr, int *addrlen);
extern int __75sele(int maxsock, fd_set *r, fd_set *w, fd_set *e, timeval * t);
extern int __75selx(int, fd_set *, fd_set *, fd_set *, timeval *, unsigned **);
extern int __75pnam(int ss, struct sockaddr *addr, int *addrlen);
extern struct hostent * __75ghba(void *addr);
#endif

static fd_set   inuse;
static __75VECT vect = {
    0,              /* 00 inited            (deprecated)    */
    0,              /* 04 error             (deprecated)    */
    &inuse,         /* 08 sockets in use    (deprecated)    */
    __75gabn,       /* 0C getaddrbyname()                   */
    __75ghbn,       /* 10 gethostbyname()                   */
    __75sock,       /* 14 socket()                          */
    __75bind,       /* 18 bind()                            */
    __75conn,       /* 1C connect()                         */
    __75list,       /* 20 listen()                          */
    __75acce,       /* 24 accept()                          */
    __75send,       /* 28 send()                            */
    __75recv,       /* 2C recv()                            */
    __75clos,       /* 30 closesocket()                     */
    __75ioct,       /* 34 ioctlsocket()                     */
    __75snam,       /* 38 getsockname()                     */
    __75sele,       /* 3C select()                          */
    __75selx,       /* 40 selectex()                        */
    __75pnam,       /* 44 getpeername()                     */
    __75ghba,       /* 48 gethostbyaddr()                   */
};

__75VECT *__75vect = &vect;
