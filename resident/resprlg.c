#include <clibres.h>

/* This code gets copied into the RES structure as the prolog value */
__asm__ __volatile__("CSECT ,\n"
"         ENTRY\tRESPRLG\n"
"RESPRLG  DS\t0H\n"
"         LR\t0,15      save resident address\n"
"         L\t15,8(,15)  load dispatcher address (RES->disp)\n"
"         BR\t15        branch to dispatcher");
