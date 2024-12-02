#ifndef IPC_H
#define IPC_H

typedef struct ipc      IPC;        /* Inter Process Communication  */
typedef struct ipcc     IPCC;       /* IPC Channel                  */
typedef struct ipcm     IPCM;       /* IPC Message                  */

/* Create an IPC handle 
 * port     port number to listen on for IPC request, 0 == TCPIP will assign port
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Creates an IPC subtask for sending and receiving messages.
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Note: IPC is intentionally restricted to the local host 127.0.0.1
 * network adapter address for now. This means that only local processes
 * can connect to the IPC port. The local processes coould be those
 * in MVS or those running on the same host that the Hercules emulator
 * is running on. This may be relaxed at some point down the road.
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Examples:
 * // create IPC handle, TCPIP will assign port
 * IPC *myipc = ipc_new(0);
 * 
 * // create IPC handle for port 1234 
 * IPC *myipc = ipc_new(1234);
*/
IPC *ipc_new(unsigned short port)                                           asm("@@ICNW");

/* Free IPC handle 
 * pipc is a pointer to IPC handle.
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Terminates the IPC subtask and releases all resources held by IPC handle.
*/
void ipc_free(IPC **pipc)                                                   asm("@@ICFR");

/* ipc_connect_host_port() - create new channel to host, port */
IPCC *ipc_connect_host_port(IPC *ipc, const char *host, const char *port)   asm("@@ICCHP");
/* ipc_connect_addr_port() - create new chanel to addr, port */
IPCC *ipc_connect_addr_port(IPC *ipc, unsigned addr, unsigned short port)   asm("@@ICCAP");

/* ipc_get_host_port() - get channel by host, port if it exist */
IPCC *ipc_get_host_port(IPC *ipc, const char *host, const char *port)       asm("@@ICGHP");
/* ipc_get_addr_port() - get channel by addr, port if it exist */
IPCC *ipc_get_addr_port(IPC *ipc, unsigned addr, unsigned port)             asm("@@ICGAP");
/* ipc_get_sock() - get channel by socket if it exist */
IPCC *ipc_get_sock(IPC *ipc, int sock)                                      asm("@@ICGSO");
/* ipc_get_id() - get channel by socket if it exist */
IPCC *ipc_get_id(IPC *ipc, int id)                                          asm("@@ICGID");
/* ipc_get_name() - get channel by name if it exist */
IPCC *ipc_get_name(IPC *ipc, const char *name)                              asm("@@ICGNM");

/* ipc_free_channel() - close and free channel */
void ipc_free_channel(IPCC **pipcc)                                         asm("@@ICFCH");

/* ipc_free_message() - free message handle */
void ipc_free_message(IPCM **pipcm)                                         asm("@@ICFMS");



/* Allocate new message for connection */
IPCM *ipc_new_msg(IPCC *ipcc, unsigned size)                            asm("@@ICNWM");

void ipc_free_msg(IPCM *pipcm)                                          asm("@@ICFRM");

/* Send message */
int ipc_send(IPCM *ipcm)                                                asm("@@ICSND");

int ipc_send_recv(IPCM *ipcm)                                           asm("@@ICSNDR");

int ipc_recv(IPCM *ipcm)                                                asm("@@ICRCV");

/* Start function as IPC subtask */
int ipc_start(IPC *ipc, void *func, void *arg1, void *arg2, unsigned stacksize) asm("@@ICST");

#endif
