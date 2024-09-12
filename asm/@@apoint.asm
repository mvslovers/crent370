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
*  APOINT - Restore the position in the data set (BSAM/BPAM only)     *
*           Note that this does not fail; it just bombs on the        *
*           next read or write if incorrect.                          *
*                                                                     *
***********************************************************************
@@APOINT FUNHEAD IO=YES,AM=YES,SAVE=SAVEADCB,US=NO   NOTE position
         L     R3,4(,R1)          R3 points to the TTR value
         L     R3,0(,R3)          Get the TTR
         ST    R3,ZWORK           Save below the line
         FIXWRITE ,
         GO24  ,                  For old code
         TM    IOMFLAGS,IOFEXCP   EXCP mode ?
         BZ    POINBSAM           No
         L     R4,DCBBLKCT        Get current position
         SR    R4,R3              Get new position's increment
         BZ    POINCOM
         BM    POINHEAD
POINBACK MVI   TAPECCW,X'27'      Backspace
         B     POINECOM
POINHEAD MVI   TAPECCW,X'37'      Forward space
POINECOM LA    R0,1
         STH   R0,TAPECCW+6
         LPR   R4,R4
POINELUP EXCP  TAPEIOB
         WAIT  ECB=TAPEECB
         BCT   R4,POINELUP
         ST    R3,DCBBLKCT
         B     POINCOM
         SPACE 1
POINBSAM POINT (R10),ZWORK        Request repositioning
POINCOM  AMUSE ,
         NI    IOPFLAGS,255-IOFLEOF   Valid POINT resets EOF
         XC    KEPTREC(8),KEPTREC      Also clear record data
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
