 TITLE '/home/mike/repos/crent370/jes/josjobfr.c'
         COPY  PDPTOP
         CSECT
* Program text area
         DS    0F
         EJECT
* external function 'jesjobfr' prologue
* frame base=88, local stack=16, call args=8
&FUNC    SETC  'jesjobfr'
JESJOBFR PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'jesjobfr' code
         MVC   96(4,13),=F'0'
         L     2,0(11)
         LTR   2,2
         BNE   @@L4
         B     @@L5
@@L4     EQU   *
         L     2,0(11)
         MVC   96(4,13),0(2)
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,100(13)
         MVC   104(4,13),=F'0'
@@L6     EQU   *
         L     2,104(13)
         CL    2,100(13)
         BL    @@L9
         B     @@L7
@@L9     EQU   *
         L     2,104(13)
         MH    2,=H'4'
         A     2,96(13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(JESJOBF1)
         BALR  14,15
         L     2,104(13)
         A     2,=F'1'
         ST    2,104(13)
         B     @@L6
@@L7     EQU   *
         MVC   88(4,13),0(11)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
         L     2,0(11)
         MVC   0(4,2),=F'0'
@@L5     EQU   *
         SLR   2,2
         LR    15,2
* Function 'jesjobfr' epilogue
         PDPEPIL
* Function 'jesjobfr' literal pool
         DS    0D
         LTORG
* Function 'jesjobfr' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
