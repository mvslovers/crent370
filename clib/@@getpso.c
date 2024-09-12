#include <hasppso.h>

/* returns the address of the Process SYSOUT control block */
__PSO *__getpso(void)
{
    __PSO   *pso    = 0;

    __asm("L\t15,PSATOLD-PSA          OUR TCB ADDRESS\n\t"
          "L\t15,TCBJSCB-TCB(,15)     JSCB ADDRESS\n\t"
          "USING IEZJSCB,15\n\t"
          "L\t15,JSCBACT              ACTIVE JSCB ADDRESS\n\t"
          "L\t15,JSCBSSIB             SSIB ADDRESS\n\t"
          "DROP\t15\n\t"
          "L\t15,SSIBSUSE-SSIB(,15)   SJB ADDRESS\n\t"
          "L\t15,SJBPSOP-SJBDSECT(,15) PSO ADDRESS\n\t"
          "ST\t15,0(,%0)" : : "r"(&pso));

    return pso;
}
    __asm("PRINT NOGEN");
    __asm("IEFJSSOB (SO),CONTIG=NO\n\t"
          "CSECT ,");
    __asm("$TQE");
    __asm("$CMB");
    __asm("$PSO");
    __asm("$SJB");
    __asm("$PDDB");
    __asm("IEZJSCB");
    __asm("IEFJSSIB");
    __asm("IKJTCB");
    __asm("IHAPSA");
