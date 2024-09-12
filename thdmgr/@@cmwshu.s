 TITLE '/home/mike/repos/crent370/thdmgr/@@cmwshu.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'cthread_worker_shutdown'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_worker_shutdown' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'cthread_worker_shutdown'
@@CMWSHU PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_worker_shutdown' code
         L     5,0(11)
         LTR   5,5
         BE    @@L3
         L     3,16(5)
         LTR   3,3
         BE    @@L4
         L     2,16(3)
         N     2,=F'1073741824'
         LTR   2,2
         BNE   @@L19
@@L4     EQU   *
         LR    2,5
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         LTR   3,3
         BE    @@L3
         L     2,8(3)
         LTR   2,2
         BE    @@L3
         SLR   4,4
@@L14    EQU   *
         L     2,16(3)
         N     2,=F'1073741824'
         LTR   2,2
         BNE   @@L19
         LR    2,5
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         STIMER WAIT,BINTVL==F'10'   0.10 seconds
         A     4,=F'1'
         LA    2,49(0,0)
         CR    4,2
         BNH   @@L14
@@L19    EQU   *
         L     2,8(3)
         LTR   2,2
         BE    @@L3
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTDET)
         BALR  14,15
@@L3     EQU   *
         SLR   15,15
* Function 'cthread_worker_shutdown' epilogue
         PDPEPIL
* Function 'cthread_worker_shutdown' literal pool
         DS    0D
         LTORG
* Function 'cthread_worker_shutdown' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
