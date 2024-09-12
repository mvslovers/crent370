 TITLE '/home/mike/repos/crent370/thdmgr/@@cmwwat.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'cthread_worker_wait'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_worker_wait' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'cthread_worker_wait'
@@CMWWAT PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_worker_wait' code
         L     3,0(11)
         L     4,4(11)
         L     15,=F'-1'
         LTR   3,3
         BE    @@L3
         LTR   4,4
         BE    @@L4
         MVC   0(4,4),=F'0'
@@L4     EQU   *
         LR    2,3
         A     2,=F'20'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMQDEL)
         BALR  14,15
         MVC   24(4,3),=F'2'
         MVC   88(4,13),=F'0'
         LA    0,96(,13)
         LA    1,88(,13)
         L     15,=V(TM64TIME)
         BALR  14,15
         MVC   40(8,3),96(13)
         L     2,12(3)
         A     2,=F'12'
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         LR    2,3
         A     2,=F'8'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTWAIT)
         BALR  14,15
         LA    2,2(0,0)
         CLR   15,2
         BNE   @@L5
         MVC   24(4,3),=F'4'
         B     @@L6
@@L5     EQU   *
         MVC   24(4,3),=F'1'
@@L6     EQU   *
         LTR   4,4
         BE    @@L3
         L     2,20(3)
         LTR   2,2
         BE    @@L3
         MVC   0(4,4),12(2)
@@L3     EQU   *
* Function 'cthread_worker_wait' epilogue
         PDPEPIL
* Function 'cthread_worker_wait' literal pool
         DS    0D
         LTORG
* Function 'cthread_worker_wait' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
