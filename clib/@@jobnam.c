#include "clibtiot.h"

const char *__jobname(void)
{
	const TIOT 	*tiot;
	const char	*jobname;

	__asm("L\t15,PSATOLD-PSA		OUR TCB ADDRESS\n\t"
          "L\t15,TCBTIO-TCB(,15)	TIOT ADDRESS\n\t"
          "ST\t15,%0" : "=m"(tiot));

	jobname = (const char*) tiot->TIOCNJOB;
	
	return jobname;
}
    __asm("PRINT NOGEN");
    __asm("IKJTCB");
    __asm("IHAPSA");
    __asm("PRINT GEN");
