 TITLE '/home/mike/repos/crent370/jes/jesdelj.c'
         COPY  PDPTOP
         CSECT
* Program text area
         DS    0F
         EJECT
* external function 'jesdelj' prologue
* frame base=88, local stack=152, call args=16
&FUNC    SETC  'jesdelj'
JESDELJ  PDPPRLG CINDEX=0,FRAME=256,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'jesdelj' code
         MVC   104(4,13),=F'-1'
         L     2,0(11)
         LTR   2,2
         BNE   @@L4
         L     2,4(11)
         LTR   2,2
         BNE   @@L4
         B     @@L5
@@L4     EQU   *
         LA    2,112(,13)
         ST    2,88(13)
         LA    2,136(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(INITSSOB)
         BALR  14,15
         MVC   118(2,13),=H'1'
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'120'
         LA    1,88(,13)
         L     15,=A(@@0)
         BALR  14,15
         MVC   136(2,13),=H'120'
         MVI   138(13),64
         IC    2,140(13)
         O     2,=F'-128'
         STC   2,140(13)
         L     2,0(11)
         LTR   2,2
         BE    @@L6
         LA    2,136(,13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),0(11)
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         IC    2,140(13)
         O     2,=F'16'
         STC   2,140(13)
@@L6     EQU   *
         L     2,4(11)
         LTR   2,2
         BE    @@L7
         LA    2,136(,13)
         A     2,=F'16'
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),4(11)
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         IC    2,140(13)
         O     2,=F'8'
         STC   2,140(13)
@@L7     EQU   *
         MVI   141(13),128
         LA    2,112(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(IEFSSREQ)
         BALR  14,15
         MVC   104(4,13),124(13)
@@L5     EQU   *
         L     2,104(13)
         LR    15,2
* Function 'jesdelj' epilogue
         PDPEPIL
* Function 'jesdelj' literal pool
         DS    0D
         LTORG
* Function 'jesdelj' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         DS    0F
         EJECT
* static function 'memset' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'memset'
@@0      PDPPRLG CINDEX=1,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'memset' code
         L     4,0(11)
         L     3,8(11)
         L     2,4(11)
         
*** MEMSET ***
         LR    14,4           => target (s)
         LR    15,3           => length (n)
         SLR   0,0             => source (NULL)
         LR    1,2            fill character
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         L     2,0(11)
         LR    15,2
* Function 'memset' epilogue
         PDPEPIL
* Function 'memset' literal pool
         DS    0D
         LTORG
* Function 'memset' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
