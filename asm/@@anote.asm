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
*  ANOTE  - Remember the position in the data set (BSAM/BPAM only)    *
*                                                                     *
***********************************************************************
@@ANOTE  FUNHEAD IO=YES,AM=YES,SAVE=SAVEADCB,US=NO   NOTE position
         L     R3,4(,R1)          R3 points to the return value
         FIXWRITE ,
         GO24  ,                  For old code
         TM    IOMFLAGS,IOFEXCP   EXCP mode?
         BZ    NOTEBSAM           No
         L     R4,DCBBLKCT        Return block count
         B     NOTECOM
         SPACE 1
NOTEBSAM NOTE  (R10)              Note current position
         LR    R4,R1              Save result
NOTECOM  AMUSE ,
         ST    R4,0(,R3)          Return TTR0 to user
         FUNEXIT RC=0
*
         LTORG ,                  In case someone adds literals
*
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
