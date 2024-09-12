 TITLE '/home/mike/repos/crent370/thdmgr/@@cmterm.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'cthread_manager_term'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_manager_term' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'cthread_manager_term'
@@CMTERM PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_manager_term' code
         L     6,0(11)
         SLR   7,7
         LTR   6,6
         BE    @@L3
         L     4,0(6)
         LTR   4,4
         BE    @@L3
         ST    4,88(13)
         ST    7,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    5,15
         L     2,36(4)
         LA    3,1(0,0)
         CLR   2,3
         BNE   @@L5
         MVC   36(4,4),=F'2'
@@L5     EQU   *
         LR    2,4
         A     2,=F'12'
         ST    2,88(13)
         MVC   92(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         LTR   5,5
         BNE   @@L6
         ST    4,88(13)
         ST    5,92(13)
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L6     EQU   *
         STIMER WAIT,BINTVL==F'25'   0.25 seconds
         ST    4,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    5,15
         L     2,32(4)
         LTR   2,2
         BE    @@L7
         LR    2,4
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    3,15
         LTR   15,15
         BE    @@L27
@@L13    EQU   *
         LR    2,4
         A     2,=F'32'
         ST    2,88(13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARGET)
         BALR  14,15
         ST    15,96(13)
         LTR   15,15
         BE    @@L10
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMQDEL)
         BALR  14,15
@@L10    EQU   *
         BCTR  3,0
         LTR   3,3
         BNE   @@L13
@@L27    EQU   *
         LR    2,4
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L7     EQU   *
         MVC   100(4,13),8(4)
         L     2,100(13)
         LTR   2,2
         BE    @@L14
         L     2,36(4)
         LA    3,1(0,0)
         CR    2,3
         BH    @@L15
         MVC   36(4,4),=F'2'
@@L15    EQU   *
         LR    2,4
         A     2,=F'12'
         ST    2,88(13)
         MVC   92(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         LTR   5,5
         BNE   @@L16
         ST    4,88(13)
         ST    5,92(13)
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L16    EQU   *
         SLR   3,3
@@L23    EQU   *
         L     2,100(13)
         L     2,16(2)
         N     2,=F'1073741824'
         LTR   2,2
         BNE   @@L18
         STIMER WAIT,BINTVL==F'25'   0.25 seconds
         L     2,36(4)
         LA    5,1(0,0)
         CR    2,5
         BH    @@L22
         MVC   36(4,4),=F'2'
@@L22    EQU   *
         LR    2,4
         A     2,=F'12'
         ST    2,88(13)
         MVC   92(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         A     3,=F'1'
         LA    2,9(0,0)
         CLR   3,2
         BNH   @@L23
@@L18    EQU   *
         STIMER WAIT,BINTVL==F'25'   0.25 seconds
         ST    4,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    5,15
         LR    2,4
         A     2,=F'12'
         ST    2,88(13)
         MVC   92(4,13),=F'3'
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
         LTR   5,5
         BNE   @@L24
         ST    4,88(13)
         ST    5,92(13)
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L24    EQU   *
         STIMER WAIT,BINTVL==F'25'   0.25 seconds
         ST    4,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    5,15
         LA    2,100(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTDEL)
         BALR  14,15
         MVC   8(4,4),=F'0'
@@L14    EQU   *
         LTR   5,5
         BNE   @@L25
         ST    4,88(13)
         ST    5,92(13)
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L25    EQU   *
         ST    4,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         MVC   0(4,6),=F'0'
@@L3     EQU   *
         LR    15,7
* Function 'cthread_manager_term' epilogue
         PDPEPIL
* Function 'cthread_manager_term' literal pool
         DS    0D
         LTORG
* Function 'cthread_manager_term' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
