#include "clibssib.h"

SSIB *__ssib(void)
{
	SSIB *ssib;
	
    __asm("L\t15,PSATOLD-PSA          OUR TCB ADDRESS\n\t"
          "L\t15,TCBJSCB-TCB(,15)     JSCB ADDRESS\n\t"
          "USING IEZJSCB,15\n\t"
          "L\t15,JSCBACT              ACTIVE JSCB ADDRESS\n\t"
          "L\t15,JSCBSSIB             SSIB ADDRESS\n\t"
          "DROP\t15\n\t"
          "ST\t15,%0" : "=m"(ssib));

    return ssib;
}

    __asm("PRINT NOGEN");
    __asm("IEZJSCB");
    __asm("IKJTCB");
    __asm("IHAPSA");
    __asm("IEFJSSIB");
