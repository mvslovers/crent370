 TITLE '/home/mike/repos/crent370/thdmgr/@@cmwdel.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'cthread_worker_del'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_worker_del' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'cthread_worker_del'
@@CMWDEL PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_worker_del' code
         L     6,0(11)
         SLR   7,7
         LTR   6,6
         BE    @@L3
         L     2,0(6)
         LTR   2,2
         BE    @@L3
         L     5,12(2)
         LTR   5,5
         BE    @@L5
         ST    5,88(13)
         ST    7,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    8,15
         LR    2,5
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,7
         CLR   7,15
         BNL   @@L7
@@L12    EQU   *
         L     3,28(5)
         LR    2,4
         MH    2,=H'4'
         L     2,0(2,3)
         LTR   2,2
         BE    @@L8
         CL    2,0(6)
         BNE   @@L8
         LR    2,5
         A     2,=F'28'
         ST    2,88(13)
         LR    2,4
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         B     @@L7
@@L8     EQU   *
         A     4,=F'1'
         CLR   4,15
         BL    @@L12
@@L7     EQU   *
         LTR   8,8
         BNE   @@L5
         ST    5,88(13)
         ST    8,92(13)
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L5     EQU   *
         L     3,0(6)
         L     2,8(3)
         N     2,=F'-2147483648'
         LTR   2,2
         BE    @@L14
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWSHU)
         BALR  14,15
@@L14    EQU   *
         L     2,0(6)
         MVC   96(4,13),16(2)
         L     2,96(13)
         LTR   2,2
         BE    @@L15
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTDEL)
         BALR  14,15
         L     2,0(6)
         MVC   16(4,2),=F'0'
@@L15    EQU   *
         L     2,0(6)
         MVC   100(4,13),20(2)
         L     2,100(13)
         LTR   2,2
         BE    @@L16
         LA    2,100(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMQDEL)
         BALR  14,15
         L     2,0(6)
         MVC   20(4,2),=F'0'
@@L16    EQU   *
         MVC   88(4,13),0(6)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         MVC   0(4,6),=F'0'
@@L3     EQU   *
         LR    15,7
* Function 'cthread_worker_del' epilogue
         PDPEPIL
* Function 'cthread_worker_del' literal pool
         DS    0D
         LTORG
* Function 'cthread_worker_del' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
