/* @@75EXIT.C
** Close any sockets we allocated but haven't closed yet.
*/
#include "__75.h"
#include "socket.h"

extern void
__75exit(void) 
{
    int     i;
 
    printf("in __75exit(), inuse=%08X\n", __75vect->inuse);   
    if (__75vect->inuse) {
        unsigned char *p = (unsigned char*)__75vect->inuse;
        for(i=0; i<sizeof(fd_set); i++) {
            printf("%02X ", p[i]);
        }
        printf("\n");
        for(i=0; i<1024; i++) {
            if (FD_ISSET(i, __75vect->inuse)) {
                printf("closing socket %d\n", i);
                __75clos(i);
            }
            else {
                printf("socket %d is not in use\n", i);
            }
        }
    }
    printf("leaving __75exit()\n");
}
