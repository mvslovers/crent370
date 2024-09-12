 TITLE '/home/mike/repos/crent370/thdmgr/@@cmqadd.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'cthread_queue_add'
* Program text area
@@LC0    EQU   *
         DC    C'CTHDQUE'
         DC    X'0'
         DS    0F
         EJECT
* external function 'cthread_queue_add' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'cthread_queue_add'
@@CMQADD PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_queue_add' code
         L     4,0(11)
         SLR   5,5
         LTR   4,4
         BE    @@L3
         ST    4,88(13)
         ST    5,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    6,15
         L     2,36(4)
         LA    3,2(0,0)
         CLR   2,3
         BE    @@L5
         L     2,36(4)
         LA    3,3(0,0)
         CLR   2,3
         BE    @@L5
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15
         L     5,=F'-1'
         LTR   15,15
         BE    @@L5
         ST    15,88(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    4,8(3)
         MVC   12(4,3),4(11)
         LR    2,4
         A     2,=F'32'
         ST    2,88(13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         A     2,=F'-20'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         LR    5,15
@@L5     EQU   *
         LTR   6,6
         BNE   @@L3
         ST    4,88(13)
         ST    6,92(13)
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L3     EQU   *
         LR    15,5
* Function 'cthread_queue_add' epilogue
         PDPEPIL
* Function 'cthread_queue_add' literal pool
         DS    0D
         LTORG
* Function 'cthread_queue_add' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
