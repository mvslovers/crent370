#ifndef CLIBSOCK_H
#define CLIBSOCK_H

typedef struct clibsock CLIBSOCK;

/* the CLIBSOCK structure is used to hold information about open
** sockets created by the DYN75 interface.
**
** the name and peer fields represent sockaddr_in structures.
*/
struct clibsock {
    char    eye[8];                 /* 00 eye catcher "CLIBSOCK"        */
#define CLIBSOCK_EYE    "CLIBSOCK"  /* ...                              */
    int     socket;                 /* 08 socket number                 */
    int     unused;                 /* 0C unused                        */
    char    name[16];               /* 10 sockaddr_in for local side    */
    char    peer[16];               /* 20 sockaddr_in for remote side   */
};                                  /* 30 (48 bytes)                    */

extern int  __soadd(int ss, void *name, void *peer);
extern int  __soupd(int ss, void *name, void *peer);
extern int  __sodel(int ss);

/* __sofind() - returns index of found socket or 0 if not found */
extern int  __sofind(int ss, CLIBSOCK **s);

/* __sosnam() - get socket name (local side of socket) */
extern int  __sosnam(int ss, void *name);

/* __sopnam() - get peer name (remote side of socket) */
extern int  __sopnam(int ss, void *peer);

#endif
