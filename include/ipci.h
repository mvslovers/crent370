#ifndef IPCI_H
#define IPCI_H

#include "ipc.h"                    /* IPC typedef, prototypes      */
typedef struct ipch     IPCH;       /* IPC Message Header           */

#include <string.h>                 /* various string functions     */
#include <errno.h>                  /* errno                        */
#include <clibwsa.h>                /* __getwsa()                   */
#include <clibwto.h>                /* wto(), wtof(), ...           */
#include <cliblock.h>               /* lock(), unlock(), ...        */
#include <clibthrd.h>               /* Threads                      */
#include <clibwto.h>
#include <socket.h>                 /* TCPIP sockets                */
#include <time64.h>                 /* time64(), ...                */

/* Internal structures for IPC functions use only */

struct ipc {    /* Inter Process Communication */
    char            eye[4];         /* 00 IPC eye catcher           */
#define IPC_EYE     "IPC"           /* ... "IPC"                    */
    unsigned char   flag;           /* 04 processing flags          */
#define IPC_FLAG_ACTIVE     0x80    /* ... IPC subtask is active    */
#define IPC_FLAG_QUIESCE    0x40    /* ... no new connections       */
#define IPC_FLAG_SHUTDOWN   0x20    /* ... IPC subtask is shutdown  */

    unsigned char   state;          /* 05 processing state          */
#define IPC_STATE_IDLE          0   /* ... IDLE state               */
#define IPC_STATE_ACTIVE        1   /* ... IPC subtask active       */
#define IPC_STATE_WAIT          2   /* ... WAITing for socket|ecb   */
#define IPC_STATE_ACCEPT        3   /* ... ACCEPTing new connections*/
#define IPC_STATE_READ          4   /* ... READing messages         */
#define IPC_STATE_SEND          5   /* ... SENDing messages         */

    unsigned short  port;           /* 06 listen port               */
    int             sock;           /* 08 listen socket             */
    unsigned        ecb;            /* 0C event control block       */

    CTHDTASK        *task;          /* 10 IPC thread                */
    IPCC            **ipcc;         /* 14 IPC Channels allocated    */
};                                  /* 18 (24 bytes)                */

struct ipcc {   /* IPC Channel */
    char            eye[4];         /* 00 eye catcher               */
#define IPCC_EYE    "IPCC"          /* ... "IPCC"                   */
    IPC             *ipc;           /* 04 parent or NULL            */
    int             sock;           /* 08 channel socket            */
    unsigned        addr;           /* 0C IPV4 address              */
    unsigned short  port;           /* 10 port number               */
    unsigned char   flag;           /* 12 channel flags             */
#define IPCC_FLAG_QUIESCE   0x80    /* ... no new messages allowed  */
#define IPCC_FLAG_ACCEPT    0x40    /* ... created by accept()      */
#define IPCC_FLAG_CONNECT   0x20    /* ... created by connect()     */
#define IPCC_FLAG_ERROR     0x10    /* ... send or recv error       */

    unsigned char   state;          /* 13 channel state             */
#define IPCC_STATE_IDLE         0   /* ... IDLE channel             */
#define IPCC_STATE_SEND         1   /* ... SENDING                  */
#define IPCC_STATE_RECV         2   /* ... RECEIVING                */
#define IPCC_STATE_PROC         3   /* ... PROCESSING               */
#define IPCC_STATE_CLOSE        4   /* ... CLOSE this channel       */

    /* user assigned channel id */
    unsigned        id;             /* 14 channel id                */

    /* user assigned channel name */
    char            *name;          /* 18 channel name              */

    /* posted when message received */
    unsigned        ecb;            /* 1C event control block       */

    /* incomming message queue */
    IPCM            **inq;          /* 20 input msg queue     FIFO  */

    /* outgoing message queue */
    IPCM            **outq;         /* 24 output msg queue    FIFO  */

    /* last time send or receive */
    time64_t        lastused;       /* 28 last time send or receive */

    unsigned        nextid;         /* 30 next outgoing msg id      */
    IPCM            *in;            /* 34 recv in progress          */
};                                  /* 38 (56 bytes)                */

struct ipch {   /* IPC Message Header   */
    unsigned char   sync;           /* 00 sync character            */
#define IPCH_SYNC            0x0C   /* ... sync character           */

    unsigned char   flag;           /* 01 flags                     */
#define IPCH_FLAG_REQUEST    0x80   /* ... message is a request     */
#define IPCH_FLAG_REPLY      0x40   /* ... this message is a reply  */
#define IPCH_FLAG_UNSOL      0x20   /* ... unsolicited message      */
#define IPCH_FLAG_NOOP       0x10   /* ... no op (keep alive)       */

    unsigned char   maj;            /* 02 message major id          */
#define IPCH_MAJ_IPC          255   /* ... Reserved for IPC use     */

    unsigned char   min;            /* 03 message minor id          */
#define IPCH_MIN_IPC_PING       0   /* ... IPC PING message         */

    unsigned        id;             /* 04 message id                */
    unsigned        len;            /* 08 message buffer length     */
    char            buf[0];         /* 0C data buffer               */
};                                  /* 0C (12 bytes)                */

struct ipcm {   /* IPC Message */
    char            eye[4];         /* 00 eye catcher               */
#define IPCM_EYE    "IPCM"          /* ... "IPCM"                   */
    IPCC            *ipcc;          /* 04 IPC Channel               */
    IPCH            *ipch;          /* 08 IPC msg (header+buffer)   */
    unsigned        pos;            /* 0C position in buffer        */
};                                  /* 10 (16 bytes)                */


#endif
