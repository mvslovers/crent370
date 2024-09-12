         COPY  MVSMACS
         COPY  PDPTOP
         CSECT ,
         PRINT GEN
         SPACE 1
**********************************************************************
*                                                                    *
*  GETPFX - get TSO prefix                                           *
*                                                                    *
**********************************************************************
         ENTRY @@GETPFX
@@GETPFX DS    0H
         SAVE  (14,12),,@@GETPFX
         LR    R12,R15
         USING @@GETPFX,R12
*
         LA    R15,0
         LA    R0,0    Not really needed, just looks nice
         USING PSA,R0
         ICM   R2,15,PSATOLD
         BZ    RETURNGP
         USING TCB,R2
         ICM   R3,15,TCBJSCB
         BZ    RETURNGP
         USING IEZJSCB,R3
         ICM   R4,15,JSCBPSCB
         BZ    RETURNGP
         USING PSCB,R4
         ICM   R5,15,PSCBUPT
         BZ    RETURNGP
         USING UPT,R5
         LA    R6,UPTPREFX
         LR    R15,R6
*
RETURNGP DS    0H
         RETURN (14,12),RC=(15)
         LTORG
         SPACE 2
         COPY  CLIBSUPA
*
         SPACE 2
         PRINT NOGEN
         IHAPSA ,            MAP LOW STORAGE
         CVT DSECT=YES
         IKJTCB ,            MAP TASK CONTROL BLOCK
         IKJECT ,            MAP ENV. CONTROL BLOCK
         IKJPTPB ,           PUTLINE PARAMETER BLOCK
         IKJCPPL ,
         IKJPSCB ,
         IEZJSCB ,
         IEZIOB ,
         IEFZB4D0 ,          MAP SVC 99 PARAMETER LIST
         IEFZB4D2 ,          MAP SVC 99 PARAMETERS
         IEFUCBOB ,
MYTIOT   DSECT ,
         IEFTIOT1 ,
         IHAPDS PDSBLDL=YES
         SPACE 1
         IFGACB ,                                               GP14233
         SPACE 1
         IFGRPL ,                                               GP14233
         IEFJESCT ,
         IKJUPT ,
         END
