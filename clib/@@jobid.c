#include "clibssib.h"

const char *__jobid(void)
{
	const char	*jobid;

    __asm("L\t15,PSATOLD-PSA          OUR TCB ADDRESS\n\t"
          "L\t15,TCBJSCB-TCB(,15)     JSCB ADDRESS\n\t"
          "USING IEZJSCB,15\n\t"
          "L\t15,JSCBACT              ACTIVE JSCB ADDRESS\n\t"
          "L\t15,JSCBSSIB             SSIB ADDRESS\n\t"
          "DROP\t15\n\t"
          "LA\t15,SSIBJBID-SSIB(,15)  JOB ID\n\t"
          "ST\t15,%0" : "=m"(jobid));
	
	return jobid;
}

    __asm("PRINT NOGEN");
    __asm("IEZJSCB");
    __asm("IKJTCB");
    __asm("IHAPSA");
    __asm("IEFJSSIB");
