#ifndef SOCKET_H
#define SOCKET_H

#ifndef OR
#define OR ??!??!
#endif

#ifndef BOR
#define BOR ??!
#endif

#ifndef FIONBIO
#define FIONBIO  1 /* set/clear non-blocking i/o */
#endif

#ifndef FIONREAD
#define FIONREAD 2 /* get # bytes to read */
#endif

#if 0
struct in_addr {
    union {
        struct { unsigned char s_b1,s_b2,s_b3,s_b4; } S_un_b;
        struct { unsigned short s_w1,s_w2; } S_un_w;
        unsigned long S_addr;
    } S_un_a;
};
#else
struct in_addr {
    unsigned long s_addr;
};
#endif
typedef struct in_addr	in_addr_t;

int inet_aton(const char *cp, in_addr_t *inp)	asm("@@INATON");


struct sockaddr {
    unsigned short    sa_family;    /* address family, AF_xxx */
    char              sa_data[14];  /* 14 bytes of protocol address */
};

struct sockaddr_in {
    short   sin_family;
    unsigned short sin_port;
    struct  in_addr sin_addr;
    char    sin_zero [8];
};

struct hostent {
    char    *h_name;
    char    **h_aliases;
    int     h_addrtype;
    int     h_length;
    char    **h_addr_list;
};

typedef long fd_mask;

#define NBBY       8
#ifndef FD_SETSIZE
#define FD_SETSIZE 1024
#endif
#define NFDBITS (sizeof(fd_mask) * NBBY) /* bits per mask */
#define howmany(x, y) (((x) + ((y) - 1)) / (y))

typedef struct fd_set {
    fd_mask    fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} fd_set;

#define FD_SET(n, p) \
    ((p)->fds_bits[(n)/NFDBITS] |= (1 << ((n) % NFDBITS)))
#define FD_CLR(n, p) \
    ((p)->fds_bits[(n)/NFDBITS] &= ~(1 << ((n) % NFDBITS)))
#define FD_ISSET(n, p) \
    ((p)->fds_bits[(n)/NFDBITS] & (1 << ((n) % NFDBITS)))

#define	FD_ZERO(p) \
    __asm__("XC\t0(0,%1),0(%1)      *** executed ***\n\t" \
    "EX\t%0,*-6            clear memory" \
    : : "r" (sizeof(*(p))), "r" ((p)))

typedef struct timeval
{
    long    tv_sec;
    long    tv_usec;
} timeval;

struct linger {
    int     onoff;
    int     linger;
};

struct clientid {
    int     domain;
    char    name[8];
    char    subtaskname[8];
    char    reserved[20];
};

/* Supported address families. */
#define AF_UNSPEC       0
#define AF_UNIX         1   /* Unix domain sockets          */
#define AF_INET         2   /* Internet IP Protocol         */
#define AF_AX25         3   /* Amateur Radio AX.25          */
#define AF_IPX          4   /* Novell IPX                   */
#define AF_APPLETALK    5   /* Appletalk DDP                */
#define AF_NETROM       6   /* Amateur radio NetROM         */
#define AF_BRIDGE       7   /* Multiprotocol bridge         */
#define AF_AAL5         8   /* Reserved for Werner's ATM    */
#define AF_X25          9   /* Reserved for X.25 project    */
#define AF_INET6        10  /* IP version 6                 */
#define AF_MAX          12  /* For now..                    */

#define SOCK_STREAM     1   /* virtual circuit              */
#define SOCK_DGRAM      2   /* datagram                     */
#define SOCK_RAW        3   /* raw socket                   */
#define SOCK_RDM        4   /* reliably-delivered message   */
#define SOCK_SEQPACKET  5   /* sequenced packet stream      */

#define IPPROTO_IP      0   /* Dummy protocol for TCP               */
#define IPPROTO_ICMP    1   /* Internet Control Message Protocol    */
#define IPPROTO_IGMP    2   /* Internet Group Management Protocol   */
#define IPPROTO_IPIP    4   /* IPIP tunnels (older KA9Q tunnels use 94) */
#define IPPROTO_TCP     6   /* Transmission Control Protocol        */
#define IPPROTO_EGP     8   /* Exterior Gateway Protocol            */
#define IPPROTO_PUP     12  /* PUP protocol                         */
#define IPPROTO_UDP     17  /* User Datagram Protocol               */
#define IPPROTO_IDP     22  /* XNS IDP protocol                     */
#define IPPROTO_TP      29  /* SO Transport Protocol Class 4        */
#define IPPROTO_DCCP    33  /* Datagram Congestion Control Protocol */
#define IPPROTO_IPV6    41  /* IPv6-in-IPv4 tunnelling              */
#define IPPROTO_RSVP    46  /* RSVP Protocol                        */
#define IPPROTO_GRE     47  /* Cisco GRE tunnels (rfc 1701,1702)    */
#define IPPROTO_ESP     50  /* Encapsulation Security Payload protocol */
#define IPPROTO_AH      51  /* Authentication Header protocol       */
#define IPPROTO_MTP     92  /* Multicast Transport Protocol         */
#define IPPROTO_BEETPH  94  /* IP option pseudo header for BEET     */
#define IPPROTO_ENCAP   98  /* Encapsulation Header                 */
#define IPPROTO_PIM     103 /* Protocol Independent Multicast       */
#define IPPROTO_COMP    108 /* Compression Header Protocol          */
#define IPPROTO_SCTP    132 /* Stream Control Transport Protocol    */
#define IPPROTO_UDPLITE 136 /* UDP-Lite (RFC 3828)                  */
#define IPPROTO_MPLS    137 /* MPLS in IP (RFC 4023)                */
#define IPPROTO_RAW     255 /* Raw IP packets                       */

#define SOMAXCONN 256

#define INADDR_ANY  (unsigned)0x00000000
#define INADDR_NONE (unsigned)0xFFFFFFFF

#define ntohl(x) (x)
#define ntohs(x) (x)
#define htonl(x) (x)
#define htons(x) (x)
#define NTOHL(x) (x)
#define NTOHS(x) (x)
#define HTONL(x) (x)
#define HTONS(x) (x)


typedef struct __75vect     __75VECT;
extern __75VECT *__75vect;  /* global pointer to vector     */

unsigned getaddrbyname(const char *name)                                        asm("@@75GABN");
unsigned __75gabn(const char *name);

struct hostent * gethostbyname(const char *name)                                asm("@@75GHBN");
struct hostent * __75ghbn(const char *name);

int socket(int af, int type, int protocol)                                      asm("@@75SOCK");
int __75sock(int af, int type, int protocol);

int bind(int ss, struct sockaddr_in *add, int length)                           asm("@@75BIND");
int __75bind(int ss, struct sockaddr_in * name, int length);

int connect(int ss, struct sockaddr_in *addr, int length)                       asm("@@75CONN");
int __75conn(int ss, struct sockaddr_in *name, int length);

int listen(int ss, int backlog)                                                 asm("@@75LIST");
int __75list(int ss, int backlog);

int accept(int ss, struct sockaddr_in *addr, int *length)                       asm("@@75ACCE");
int __75acce(int ss, struct sockaddr_in *name, int *length);

int send(int ss, const void *buf, int len, int flags)                           asm("@@75SEND");
int __75send(int ss, const void *buf, int len, int flags);

int recv(int ss, void *buf, int len, int flags)                                 asm("@@75RECV");
int __75recv(int ss, void *buf, int len, int flags);

int closesocket(int ss)                                                         asm("@@75CLOS");
int __75clos(int ss);

int ioctlsocket(int ss, int cmd, void *argp)                                    asm("@@75IOCT");
int __75ioct(int ss, int cmd, void *argp);

int getsockname(int ss, struct sockaddr *addr, int *addrlen)                    asm("@@75SNAM");
int __75snam(int ss, struct sockaddr *addr, int *addrlen);

int select(int msock, fd_set *r, fd_set *w, fd_set *e, timeval * t)             asm("@@75SELE");
int __75sele(int maxsock, fd_set *r, fd_set *w, fd_set *e, timeval * t);

int selectex(int, fd_set *, fd_set *, fd_set *, timeval *, unsigned **)         asm("@@75SELX");
int __75selx(int, fd_set *, fd_set *, fd_set *, timeval *, unsigned **);

int getpeername(int ss, struct sockaddr *addr, int *addrlen)                    asm("@@75PNAM");
int __75pnam(int ss, struct sockaddr *addr, int *addrlen);

struct hostent * gethostbyaddr(void *addr)                                      asm("@@75GHBA");
struct hostent * __75ghba(void *addr);


struct __75vect {
    int     inited;         /* 00 API initialized flag (deprecated)     */
    int     error;          /* 04 last error code           */
    fd_set  *inuse;         /* 08 sockets in use       (deprecated)     */
    unsigned (*getaddrbyname)(const char *name);
                            /* 0C get IP address by name    */

    struct hostent * (*gethostbyname)(const char *name);
                            /* 10 get host by name          */
    int     (*socket)(int af, int type, int protocol);
                            /* 14 allocate a socket         */
    int     (*bind)(int ss, struct sockaddr_in *add, int length);
                            /* 18 bind socket to name       */
    int     (*connect)(int ss, struct sockaddr_in *addr, int length);
                            /* 1C connect socket to name    */

    int     (*listen)(int ss, int backlog);
                            /* 20 listen for connection     */
    int     (*accept)(int ss, struct sockaddr_in *addr, int *length);
                            /* 24 accept socket connection  */
    int     (*send)(int ss, const void *buf, int len, int flags);
                            /* 28 send data to socket       */
    int     (*recv)(int ss, void *buf, int len, int flags);
                            /* 2C recv data from socket     */

    int     (*closesocket)(int ss);
                            /* 30 close socket              */
    int     (*ioctlsocket)(int ss, int cmd, void *argp);
                            /* 34 ioctl for socket          */
    int     (*getsockname)(int ss, struct sockaddr *addr, int *addrlen);
                            /* 38 getsockname()             */
    int     (*select)(int msock, fd_set *r, fd_set *w, fd_set *e, timeval * t);
                            /* 3C select()                  */
    int     (*selectex)(int, fd_set *, fd_set *, fd_set *, timeval *, unsigned **);
                            /* 40 selectex()                */
    int     (*getpeername)(int ss, struct sockaddr *addr, int *addrlen);
                            /* 44 getpeername()             */
    struct hostent * (*gethostbyaddr)(void *addr);
                            /* 48 gethostbyaddr()           */
};

extern int __75init(void);  /* initialize API */

#if 0
#ifndef __75_H
/* public calls via __75vect vector */
#define getaddrbyname(name) \
    ((__75vect->getaddrbyname)(name))

#define gethostbyname(name) \
    ((__75vect->gethostbyname)(name))

#define socket(af,type,protocol) \
    ((__75vect->socket)((af),(type),(protocol)))

#define bind(ss,name,length) \
    ((__75vect->bind)((ss),(name),(length)))

#define connect(ss,name,length) \
    ((__75vect->connect)((ss),(name),(length)))

#define listen(ss,backlog) \
    ((__75vect->listen)((ss),(backlog)))

#define accept(ss,name,length) \
    ((__75vect->accept)((ss),(name),(length)))

#define send(ss,buf,len,flags) \
    ((__75vect->send)((ss),(buf),(len),(flags)))

#define recv(ss,buf,len,flags) \
    ((__75vect->recv)((ss),(buf),(len),(flags)))

#define closesocket(ss) \
    ((__75vect->closesocket)((ss)))

#define ioctlsocket(ss,cmd,argp) \
    ((__75vect->ioctlsocket)((ss),(cmd),(argp)))

#define getsockname(ss,addr,addrlen) \
    ((__75vect->getsockname)((ss),(addr),(addrlen)))

#define select(maxsock,r,w,e,t) \
    ((__75vect->select)((maxsock),(r),(w),(e),(t)))

#define selectex(maxsock,r,w,e,t,ecblist) \
    ((__75vect->selectex)((maxsock),(r),(w),(e),(t),(ecblist)))

#define getpeername(ss,addr,addrlen) \
    ((__75vect->getpeername)((ss),(addr),(addrlen)))

#define gethostbyaddr(addr) \
    ((__75vect->gethostbyaddr)(addr))

#endif  /* ifndef __75_H */
#endif  /* ifdef 0 */

#endif  /* ifndef SOCKET_H */
