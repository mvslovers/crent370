         MACRO ,
&NM      FIXWRITE ,
&NM      L     R15,=V(@@ATROUT)
         BALR  R14,R15       TRUNCATE CURRENT WRITE BLOCK
         MEND  ,
         COPY  MVSMACS
         COPY  PDPTOP
         CSECT ,
         PRINT GEN
*        YREGS
         SPACE 1
*-----------------------ASSEMBLY OPTIONS------------------------------*
SUBPOOL  EQU   0                                                      *
*---------------------------------------------------------------------*
         SPACE 1
***********************************************************************
*                                                                     *
*  ALINE - See whether any more input is available                    *
*     R15=0 EOF     R15=1 More data available                         *
*                                                                     *
***********************************************************************
@@ALINE  FUNHEAD IO=YES,AM=YES,SAVE=(WORKAREA,WORKLEN,SUBPOOL)
         FIXWRITE ,
         TM    IOMFLAGS,IOFTERM   Terminal Input?
         BNZ   ALINEYES             Always one more?
         LA    R3,KEPTREC
         LA    R4,KEPTREC+4
         STM   R2,R4,DWORK   BUILD PARM LIST
*        LA    R15,@@AREAD
         L     R15,=V(@@AREAD)
         LA    R1,DWORK
         BALR  R14,R15       GET NEXT RECORD
         SR    R15,R15       SET EOF FLAG
         LTR   R6,R6         HIT EOF ?
         BM    ALINEX        YES; RETURN ZERO
         OI    IOPFLAGS,IOFKEPT   SHOW WE'RE KEEPING A RECORD
ALINEYES LA    R15,1         ELSE RETURN ONE
ALINEX   FUNEXIT RC=(R15)
*
         LTORG ,
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
