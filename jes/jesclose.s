 TITLE '/home/mike/repos/crent370/jes/jesclose.c'
         COPY  PDPTOP
         CSECT
* Program text area
         DS    0F
         EJECT
* external function 'jesclose' prologue
* frame base=88, local stack=16, call args=8
&FUNC    SETC  'jesclose'
JESCLOSE PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'jesclose' code
         MVC   96(4,13),=F'0'
         L     2,0(11)
         LTR   2,2
         BNE   @@L4
         B     @@L5
@@L4     EQU   *
         L     2,0(11)
         MVC   96(4,13),0(2)
         L     2,96(13)
         LTR   2,2
         BE    @@L5
         L     2,96(13)
         L     2,12(2)
         LTR   2,2
         BE    @@L7
         L     2,96(13)
         A     2,=F'12'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,100(13)
         MVC   104(4,13),=F'0'
@@L8     EQU   *
         L     2,104(13)
         CL    2,100(13)
         BL    @@L11
         B     @@L9
@@L11    EQU   *
         L     3,96(13)
         L     2,104(13)
         MH    2,=H'4'
         A     2,12(3)
         L     2,0(2)
         LTR   2,2
         BNE   @@L12
         B     @@L10
@@L12    EQU   *
         L     3,96(13)
         L     2,104(13)
         MH    2,=H'4'
         A     2,12(3)
         MVC   88(4,13),0(2)
         LA    1,88(,13)
         L     15,=V(@@JSCLOS)
         BALR  14,15
         L     3,96(13)
         L     2,104(13)
         MH    2,=H'4'
         A     2,12(3)
         MVC   0(4,2),=F'0'
@@L10    EQU   *
         L     2,104(13)
         A     2,=F'1'
         ST    2,104(13)
         B     @@L8
@@L9     EQU   *
         L     2,96(13)
         A     2,=F'12'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L7     EQU   *
         L     2,96(13)
         L     2,8(2)
         LTR   2,2
         BE    @@L13
         L     2,96(13)
         MVC   88(4,13),8(2)
         LA    1,88(,13)
         L     15,=V(@@CPCLOS)
         BALR  14,15
         L     2,96(13)
         MVC   8(4,2),=F'0'
@@L13    EQU   *
         MVC   88(4,13),96(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         L     2,0(11)
         MVC   0(4,2),=F'0'
@@L5     EQU   *
         SLR   2,2
         LR    15,2
* Function 'jesclose' epilogue
         PDPEPIL
* Function 'jesclose' literal pool
         DS    0D
         LTORG
* Function 'jesclose' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
