         COPY  MVSMACS
         COPY  PDPTOP
         CSECT ,
         PRINT GEN
         SPACE 1
***********************************************************************
*                                                                     *
*  LONGJ - RESTORE REGISTERS FROM ENV                                 *
*                                                                     *
***********************************************************************
         ENTRY @@LONGJ
@@LONGJ  L     R1,0(,R1)          get the env variable
         L     R15,60(,R1)        get the return code
         LM    R0,R14,0(R1)       restore registers
         BR    R14                return to caller
         LTORG ,
         END
