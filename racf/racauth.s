 TITLE '/home/mike/repos/crent370/racf/racauth.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'racf_auth'
* Program text area
         DS    0F
         EJECT
* external function 'racf_auth' prologue
* frame base=88, local stack=160, call args=16
&FUNC    SETC  'racf_auth'
RACAUTH  PDPPRLG CINDEX=0,FRAME=264,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'racf_auth' code
         L     9,0(11)
         L     7,4(11)
         L     8,8(11)
         L     4,12(11)
         SLR   3,3
         ST    3,256(13)
         L     2,548(3)
         L     5,108(2)
         LR    6,5
         A     6,=F'200'
         MVC   260(4,13),0(6)
         ST    5,88(13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LA    2,105(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'64'
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'64'
         MVC   96(4,13),=F'80'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
         LA    2,200(,13)
         ST    2,88(13)
         ST    3,92(13)
         MVC   96(4,13),=F'56'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
         LTR   7,7
         BE    @@L2
         ST    7,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LA    2,8(0,0)
         CLR   15,2
         BNH   @@L3
         LR    15,2
@@L3     EQU   *
         LA    2,105(,13)
         ST    2,88(13)
         ST    7,92(13)
         ST    15,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L2     EQU   *
         LTR   8,8
         BE    @@L4
         ST    8,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LA    2,80(0,0)
         CLR   15,2
         BNH   @@L5
         LR    15,2
@@L5     EQU   *
         LA    2,120(,13)
         ST    2,88(13)
         ST    8,92(13)
         ST    15,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L4     EQU   *
         LA    2,4(0,0)
         CR    4,2
         BE    @@L6
         BH    @@L14
         LA    2,2(0,0)
         LTR   4,4
         BNE   @@L17
         B     @@L7
@@L14    EQU   *
         LA    2,8(0,0)
         CLR   4,2
         BE    @@L6
         LA    2,128(0,0)
@@L17    EQU   *
         CLR   4,2
         BE    @@L6
         B     @@L12
@@L7     EQU   *
         LA    4,2(0,0)
         B     @@L6
@@L12    EQU   *
         LA    4,128(0,0)
@@L6     EQU   *
         OI    204(13),16
         MVI   200(13),56
         
*
* enter supervisor state
*
         MODESET KEY=ZERO,MODE=SUP

         LTR   9,9
         BE    @@L15
         ST    9,0(6)
@@L15    EQU   *
         LA    3,120(,13)
         LA    2,104(,13)
         
*
* check access to resource
*
         RACHECK ENTITY=((3)),CLASS=(2),ATTR=(4),MF=(E,200(13))
         ST    15,256(13)
         LTR   9,9
         BE    @@L16
         MVC   0(4,6),260(13)
@@L16    EQU   *
         
*
* return to problem state
*
         MODESET KEY=NZERO,MODE=PROB

         ST    5,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         L     15,256(13)
* Function 'racf_auth' epilogue
         PDPEPIL
* Function 'racf_auth' literal pool
         DS    0D
         LTORG
* Function 'racf_auth' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
LISTLOG  RACHECK ENTITY=ENTITY,CLASS='FACILITY',ATTR=READ,LOG=NONE,    X
               MF=L
LISTNOG  RACHECK ENTITY=ENTITY,CLASS='FACILITY',ATTR=READ,             X
               MF=L
ENTITY   DC   CL40'THIS'

         END
