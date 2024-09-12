 TITLE '/home/mike/repos/crent370/jes/jesxdone.c'
         COPY  PDPTOP
         CSECT
* Program text area
         DS    0F
         EJECT
* external function 'jesxdone' prologue
* frame base=88, local stack=32, call args=8
&FUNC    SETC  'jesxdone'
JESXDONE PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'jesxdone' code
         MVC   96(4,13),=F'-1'
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),0(11)
         LA    1,88(,13)
         L     15,=V(INITSSOB)
         BALR  14,15
         MVC   110(2,13),=H'1'
         L     2,0(11)
         MVI   4(2),0
         L     2,0(11)
         MVI   5(2),128
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(IEFSSREQ)
         BALR  14,15
         MVC   96(4,13),116(13)
@@L4     EQU   *
         L     2,96(13)
         LR    15,2
* Function 'jesxdone' epilogue
         PDPEPIL
* Function 'jesxdone' literal pool
         DS    0D
         LTORG
* Function 'jesxdone' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
