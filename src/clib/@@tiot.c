#include "clibtiot.h"

TIOT *__tiot(void)
{
	TIOT 	*tiot;

	__asm("L\t15,PSATOLD-PSA		OUR TCB ADDRESS\n\t"
          "L\t15,TCBTIO-TCB(,15)	TIOT ADDRESS\n\t"
          "ST\t15,%0" : "=m"(tiot));

	return tiot;
}
    __asm("PRINT NOGEN");
    __asm("IKJTCB");
    __asm("IHAPSA");
    __asm("PRINT GEN");
    
