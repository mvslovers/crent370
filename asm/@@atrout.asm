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
*---------------------------------------------------------------------*
*  Physical Write - called by @@ACLOSE, switch from output to input
*    mode, and whenever output buffer is full or needs to be emptied.
*  Works for EXCP and BSAM. Special processing for UPDAT mode
*---------------------------------------------------------------------*
         ENTRY @@ATROUT
@@ATROUT B     *+14-@@ATROUT(,R15)   SKIP LABEL
         DC    AL1(9),CL(9)'@@ATROUT' EXPAND LABEL
         AIF   ('&SYS' NE 'S380').NOTRUBS
         BSM   R14,R0             PRESERVE AMODE
.NOTRUBS STM   R14,R12,12(R13)    SAVE CALLER'S REGISTERS
         LR    R12,R15
         USING @@ATROUT,R12
         LA    R15,ZIOSAVE2-ZDCBAREA(,R10)
         ST    R15,8(,R13)
         ST    R13,4(,R15)
         LR    R13,R15
         USING IHADCB,R10    COMMON I/O AREA SET BY CALLER
         TM    IOPFLAGS,IOFLDATA   PENDING WRITE ?
         BZ    TRUNCOEX      NO; JUST RETURN
         NI    IOPFLAGS,255-IOFLDATA  Reset it
         GO24  ,             GET LOW
         LM    R4,R5,BUFFADDR  START/NEXT ADDRESS
         CLI   RECFMIX,4          RECFM=V?
         BNE   TRUNLEN5
         SR    R5,R5
         ICM   R5,3,0(R4)         USE BDW LENGTH
         CH    R5,=H'8'           EMPTY ?
         BNH   TRUNPOST           YES; IGNORE REQUEST
         B     TRUNTMOD           CHECK OUTPUT TYPE
TRUNLEN5 SR    R5,R4              CONVERT TO LENGTH
         BNP   TRUNCOEX           NOTHING TO DO
TRUNTMOD DS    0H
         TM    IOMFLAGS,IOFEXCP   EXCP mode ?
         BNZ   EXCPWRIT           Yes
         CLI   OPENCLOS,X'84'     Update mode?
         BE    TRUNSHRT             Yes; just rewrite as is
         CLI   RECFMIX,4          RECFM=F ?
         BNL   *+8                No; leave it alone
         STH   R5,DCBBLKSI        Why do I need this?
         WRITE DECB,SF,(R10),(R4),(R5),MF=E  Write block
         B     TRUNCHK
TRUNSHRT WRITE DECB,SF,MF=E       Rewrite block from READ
TRUNCHK  CHECK DECB
         B     TRUNPOST           Clean up
         SPACE 1
EXCPWRIT STH   R5,TAPECCW+6
         STCM  R4,7,TAPECCW+1     WRITE FROM TEXT
         NI    DCBIFLGS,255-DCBIFEC   ENABLE ERP
         OI    DCBIFLGS,X'40'     SUPPRESS DDR
         STCM  R5,12,IOBSENS0-IOBSTDRD+TAPEIOB   CLEAR SENSE
         OI    DCBOFLGS-IHADCB+TAPEDCB,DCBOFLWR  SHOW WRITE
         XC    TAPEECB,TAPEECB
         EXCP  TAPEIOB
         WAIT  ECB=TAPEECB
         TM    TAPEECB,X'7F'      GOOD COMPLETION?
         BO    TRUNPOST
*NEXT*   BNO   EXWRN7F            NO
         SPACE 1
EXWRN7F  TM    IOBUSTAT-IOBSTDRD+TAPEIOB,IOBUSB7  END OF TAPE?
         BNZ   EXWREND       YES; SWITCH TAPES
         CLC   =X'1020',IOBSENS0-IOBSTDRD+TAPEIOB  EXCEEDED AWS/HET ?
         BNE   EXWRB001
EXWREND  L     R15,DCBBLKCT
         SH    R15,=H'1'
         ST    R15,DCBBLKCT       ALLOW FOR EOF 'RECORD'
         EOV   TAPEDCB       TRY TO RECOVER
         B     EXCPWRIT
         SPACE 1
EXWRB001 LA    R9,TAPEIOB    GET IOB FOR QUICK REFERENCE
         ABEND 001,DUMP
         SPACE 1
TRUNPOST XC    BUFFCURR,BUFFCURR  CLEAR
         CLI   RECFMIX,4          RECFM=V
         BL    TRUNCOEX           F - JUST EXIT
         LA    R4,4               BUILD BDW
         L     R3,BUFFADDR        GET BUFFER
         STH   R4,0(,R3)          UPDATE
TRUNCOEX L     R13,4(,R13)
         LM    R14,R12,12(R13)    Reload all
         QBSM  0,R14              Return in caller's mode
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
