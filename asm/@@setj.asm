         COPY  MVSMACS
         COPY  PDPTOP
         CSECT ,
         PRINT GEN
         SPACE 1
***********************************************************************
*                                                                     *
*  SETJ - SAVE REGISTERS INTO ENV                                     *
*                                                                     *
***********************************************************************
         ENTRY @@SETJ
@@SETJ   L     R1,0(,R1)          get the env variable
         LA    R15,0              setjmp needs to return 0
         STM   R0,R14,0(R1)       save registers to be restored
         BR    R14                return to caller
         LTORG ,
         END
