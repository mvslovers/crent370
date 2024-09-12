 TITLE '/home/mike/repos/crent370/racf/raclogin.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'racf_login'
* Program text area
         DS    0F
         EJECT
* external function 'racf_login' prologue
* frame base=88, local stack=120, call args=8
&FUNC    SETC  'racf_login'
RACLOGIN PDPPRLG CINDEX=0,FRAME=216,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'racf_login' code
         L     4,0(11)
         L     7,4(11)
         L     5,8(11)
         L     9,12(11)
         MVC   96(4,13),=F'0'
         MVC   208(4,13),=F'0'
         SLR   6,6
         L     2,548(6)
         L     8,108(2)
         ST    8,88(13)
         ST    6,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LA    3,152(,13)
         LA    2,55(0,0)
         XC    0(0,3),0(3)      clear plist *** executed ***
         EX    2,*-6
         MVI   152(13),56
         LTR   4,4
         BNE   @@L2
         L     4,=A(@@LC0)
@@L2     EQU   *
         ST    4,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LA    2,8(0,0)
         CR    15,2
         BNH   @@L3
         LR    15,2
@@L3     EQU   *
         STC   15,104(13)
         LTR   15,15
         BNH   @@L4
         LA    2,105(,13)
         MVC   0(8,2),=CL8' '   clear userid to spaces
         LA    3,105(,13)
         LR    2,15
         BCTR  2,0
         MVC   0(0,3),0(4)     copy userid *** executed ***
         EX    2,*-6
         LA    2,105(,13)
         OC    0(8,2),=CL8' '    fold to upper case
@@L4     EQU   *
         LTR   7,7
         BE    @@L5
         ST    7,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LA    2,8(0,0)
         CR    15,2
         BNH   @@L6
         LR    15,2
@@L6     EQU   *
         STC   15,120(13)
         LTR   15,15
         BNH   @@L5
         LA    2,121(,13)
         MVC   0(8,2),=CL8' '   clear password to spaces
         LA    3,121(,13)
         LR    2,15
         BCTR  2,0
         MVC   0(0,3),0(7)     copy password *** executed ***
         EX    2,*-6
         LA    2,121(,13)
         OC    0(8,2),=CL8' '    fold to upper case
@@L5     EQU   *
         LTR   5,5
         BE    @@L8
         ST    5,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         B     @@L9
@@L8     EQU   *
         SLR   15,15
@@L9     EQU   *
         LA    2,8(0,0)
         CR    15,2
         BNH   @@L10
         LR    15,2
@@L10    EQU   *
         STC   15,136(13)
         LTR   15,15
         BNH   @@L11
         LA    2,137(,13)
         MVC   0(8,2),=CL8' '   clear group to spaces
         LA    3,137(,13)
         LR    2,15
         BCTR  2,0
         MVC   0(0,3),0(5)     copy group *** executed ***
         EX    2,*-6
         LA    2,137(,13)
         OC    0(8,2),=CL8' '    fold to upper case
         LA    5,136(,13)
@@L11    EQU   *
         
*
* See if we're in supervisor state
*
         TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1
         ST    15,96(13)
         L     2,96(13)
         LTR   2,2
         BNE   @@L12
         LA    6,1(0,0)
@@L12    EQU   *
         LTR   6,6
         BNE   @@L13
         
*
* enter supervisor state
*
         MODESET KEY=ZERO,MODE=SUP

@@L13    EQU   *
         LTR   7,7
         BE    @@L14
         LA    4,104(,13)
         LA    3,120(,13)
         LA    2,208(,13)
         
*
* create ACEE for this user and password
*
         RACINIT ENVIR=CREATE,                                         X
               ACEE=(2),USERID=(4),PASSWRD=(3),GROUP=(5),MF=(E,152(13))
         ST    15,96(13)
         B     @@L15
@@L14    EQU   *
         LA    3,104(,13)
         LA    2,208(,13)
         
*
* create ACEE for this user (no password)
*
         RACINIT ENVIR=CREATE,PASSCHK=NO,                              X
               ACEE=(2),USERID=(3),GROUP=(5),MF=(E,152(13))
         ST    15,96(13)
@@L15    EQU   *
         LTR   6,6
         BNE   @@L17
         
*
* return to problem state
*
         MODESET KEY=NZERO,MODE=PROB

@@L17    EQU   *
         ST    8,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LTR   9,9
         BE    @@L18
         MVC   0(4,9),96(13)
@@L18    EQU   *
         L     15,208(13)
* Function 'racf_login' epilogue
         PDPEPIL
* Function 'racf_login' literal pool
         DS    0D
         LTORG
* Function 'racf_login' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'*'
         DC    X'0'
         END
