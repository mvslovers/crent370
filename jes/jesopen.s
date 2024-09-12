 TITLE '/home/mike/repos/crent370/jes/jesopen.c'
         COPY  PDPTOP
         CSECT
* Program text area
         DS    0F
         EJECT
* external function 'jesopen' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'jesopen'
JESOPEN  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'jesopen' code
         MVC   96(4,13),=F'0'
         MVC   88(4,13),=A(@@2)
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         L     2,96(13)
         LR    15,2
* Function 'jesopen' epilogue
         PDPEPIL
* Function 'jesopen' literal pool
         DS    0D
         LTORG
* Function 'jesopen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'try_jesopen'
@@LC0    EQU   *
         DC    C'Unable to allocate storage for JES handle'
         DC    X'0'
@@LC1    EQU   *
         DC    C'DD:HASPCKPT'
         DC    X'0'
@@LC2    EQU   *
         DC    C'Unable to open checkpoint dataset DD:HASPCKPT'
         DC    X'0'
@@LC3    EQU   *
         DC    C'DD:HASPACE1'
         DC    X'0'
@@LC4    EQU   *
         DC    C'Unable to open spool dataset DD:HASPACE1'
         DC    X'0'
         DS    0F
         EJECT
* static function 'try_jesopen' prologue
* frame base=88, local stack=16, call args=8
&FUNC    SETC  'try_jesopen'
@@2      PDPPRLG CINDEX=1,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'try_jesopen' code
         MVC   96(4,13),=F'0'
         MVC   100(4,13),=F'0'
         MVC   104(4,13),=F'0'
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15
         ST    2,96(13)
         L     2,96(13)
         LTR   2,2
         BNE   @@L5
         MVC   88(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L6
@@L5     EQU   *
         MVC   88(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(@@CPOPEN)
         BALR  14,15
         LR    2,15
         ST    2,100(13)
         L     2,100(13)
         LTR   2,2
         BNE   @@L7
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(JESCLOSE)
         BALR  14,15
         B     @@L6
@@L7     EQU   *
         L     2,96(13)
         MVC   8(4,2),100(13)
         MVC   88(4,13),=A(@@LC3)
         LA    1,88(,13)
         L     15,=V(@@JSOPEN)
         BALR  14,15
         LR    2,15
         ST    2,104(13)
         L     2,104(13)
         LTR   2,2
         BNE   @@L8
         MVC   88(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(JESCLOSE)
         BALR  14,15
         B     @@L6
@@L8     EQU   *
         L     2,96(13)
         A     2,=F'12'
         ST    2,88(13)
         MVC   92(4,13),104(13)
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
@@L6     EQU   *
         L     2,0(11)
         MVC   0(4,2),96(13)
* Function 'try_jesopen' epilogue
         PDPEPIL
* Function 'try_jesopen' literal pool
         DS    0D
         LTORG
* Function 'try_jesopen' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
