 TITLE '/home/mike/repos/crent370/racf/raclgout.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'racf_logout'
* Program text area
         DS    0F
         EJECT
* external function 'racf_logout' prologue
* frame base=88, local stack=72, call args=8
&FUNC    SETC  'racf_logout'
RACLGOUT PDPPRLG CINDEX=0,FRAME=168,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'racf_logout' code
         L     7,0(11)
         MVC   96(4,13),=F'0'
         SLR   6,6
         ST    6,160(13)
         L     2,548(6)
         L     5,108(2)
         LR    4,5
         A     4,=F'200'
         L     8,0(4)
         ST    5,88(13)
         ST    6,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LA    3,104(,13)
         LA    2,55(0,0)
         XC    0(0,3),0(3)      clear plist *** executed ***
         EX    2,*-6
         MVI   104(13),56
         
*
* See if we're in supervisor state
*
         TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1
         ST    15,96(13)
         L     2,96(13)
         LTR   2,2
         BNE   @@L2
         LA    6,1(0,0)
@@L2     EQU   *
         LTR   6,6
         BE    @@L3
         
*
* we're in supervisor state, switch to key 0
*
         IPK   ,
         ST    2,160(13)
         SPKA  0(0)
         B     @@L4
@@L3     EQU   *
         
*
* enter supervisor state
*
         MODESET KEY=ZERO,MODE=SUP

@@L4     EQU   *
         MVC   0(4,4),0(7)
         
*
* delete ACEE
*
         RACINIT ENVIR=DELETE,ACEE=(7),MF=(E,104(13))
         ST    15,96(13)
         CL    8,0(7)
         BE    @@L5
         ST    8,0(4)
         B     @@L6
@@L5     EQU   *
         MVC   0(4,4),=F'0'
@@L6     EQU   *
         LTR   6,6
         BE    @@L7
         L     2,160(13)
         
*
* we're in supervisor state, switch back to callers key
*
         SPKA  0(2)
         B     @@L9
@@L7     EQU   *
         
*
* return to problem state
*
         MODESET KEY=NZERO,MODE=PROB

@@L9     EQU   *
         ST    5,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         MVC   0(4,7),=F'0'
         L     15,96(13)
* Function 'racf_logout' epilogue
         PDPEPIL
* Function 'racf_logout' literal pool
         DS    0D
         LTORG
* Function 'racf_logout' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
