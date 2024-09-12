 TITLE '/home/mike/repos/crent370/thdmgr/@@cminit.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'cthread_manager_init'
* Program text area
@@LC0    EQU   *
         DC    C'CTHDMGR'
         DC    X'0'
@@LC1    EQU   *
         DC    C'CTHDMGR.%04X.%08X'
         DC    X'0'
         DS    0F
         EJECT
* external function 'cthread_manager_init' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'cthread_manager_init'
@@CMINIT PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_manager_init' code
         L     4,0(11)
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'88'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         ST    15,104(13)
         SLR   3,3
         L     2,548(3)
         L     5,36(2)
         SRL   5,16
         LTR   15,15
         BE    @@L3
         ST    15,88(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,104(13)
         MVC   16(4,2),4(11)
         L     2,104(13)
         MVC   20(4,2),8(11)
         L     2,104(13)
         ST    3,36(2)
         L     2,104(13)
         MVC   24(4,2),12(11)
         L     15,104(13)
         LA    2,5(0,0)
         CLR   4,2
         BH    @@L4
         LR    2,3
         LA    3,3(0,0)
         CLR   4,3
         BNH   @@L5
         LA    2,1(0,0)
         B     @@L5
@@L4     EQU   *
         LA    2,3(0,0)
@@L5     EQU   *
         ST    2,40(15)
         L     2,104(13)
         ST    4,44(2)
         L     2,104(13)
         A     2,=F'60'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC1)
         ST    5,96(13)
         MVC   100(4,13),104(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,104(13)
         MVC   88(4,13),=A(@@2)
         ST    2,92(13)
         MVC   96(4,13),=F'0'
         MVC   100(4,13),=F'32768'
         LA    1,88(,13)
         L     15,=V(@@CTCRTX)
         BALR  14,15
         ST    15,8(2)
         L     2,104(13)
         L     2,8(2)
         LTR   2,2
         BNE   @@L3
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMTERM)
         BALR  14,15
@@L3     EQU   *
         L     15,104(13)
* Function 'cthread_manager_init' epilogue
         PDPEPIL
* Function 'cthread_manager_init' literal pool
         DS    0D
         LTORG
* Function 'cthread_manager_init' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'dispatch_thread'
         DS    0F
         EJECT
* static function 'dispatch_thread' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'dispatch_thread'
@@2      PDPPRLG CINDEX=1,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'dispatch_thread' code
         L     3,0(11)
         LA    5,1(0,0)
         SLR   6,6
         LR    2,5
         LR    4,6
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
@@L9     EQU   *
         ST    3,88(13)
         ST    4,92(13)
         ST    6,96(13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         LA    2,3(0,0)
         CLR   15,2
         BE    @@L10
         LA    2,2(0,0)
         CLR   15,2
         BNE   @@L13
         LA    4,1(0,0)
@@L13    EQU   *
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         LR    2,15
         LTR   4,4
         BE    @@L15
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         LR    5,15
         LTR   15,15
         BE    @@L10
         B     @@L11
@@L15    EQU   *
         ST    3,88(13)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=A(@@7)
         BALR  14,15
         LR    6,15
@@L11    EQU   *
         LTR   5,5
         BNE   @@L9
@@L10    EQU   *
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=A(@@8)
         BALR  14,15
@@L19    EQU   *
         SLR   15,15
* Function 'dispatch_thread' epilogue
         PDPEPIL
* Function 'dispatch_thread' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'dispatch_thread_init'
         DS    0F
         EJECT
* static function 'dispatch_thread_init' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'dispatch_thread_init'
@@3      PDPPRLG CINDEX=2,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'dispatch_thread_init' code
         L     3,0(11)
         SLR   4,4
         ST    4,96(13)
         ST    3,88(13)
         ST    4,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         MVC   36(4,3),=F'1'
         LR    2,3
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         ST    15,96(13)
         L     2,96(13)
         CL    2,40(3)
         BNL   @@L27
@@L25    EQU   *
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWADD)
         BALR  14,15
         A     2,=F'1'
         CL    2,40(3)
         BL    @@L25
@@L27    EQU   *
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,4
* Function 'dispatch_thread_init' epilogue
         PDPEPIL
* Function 'dispatch_thread_init' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread_init' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
         
&FUNC    SETC 'dispatch_thread_timed_wait'
         DS    0F
         EJECT
* static function 'dispatch_thread_timed_wait' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'dispatch_thread_timed_wait'
@@4      PDPPRLG CINDEX=3,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function 'dispatch_thread_timed_wait' code
         L     3,0(11)
         LA    4,10(0,0)
         L     2,4(11)
         LTR   2,2
         BNE   @@L30
         L     2,8(11)
         LTR   2,2
         BE    @@L31
         LA    4,10(0,0)
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=A(@@9)
         BALR  14,15
         B     @@L30
@@L31    EQU   *
         LA    4,100(0,0)
         L     2,12(11)
         LTR   2,2
         BNE   @@L30
         LA    4,1000(0,0)
@@L30    EQU   *
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         MVC   36(4,3),=F'4'
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    2,3
         A     2,=F'12'
         ST    2,88(13)
         ST    4,92(13)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(@@CTTWAT)
         BALR  14,15
         LR    2,15
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         MVC   36(4,3),=F'1'
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,2
* Function 'dispatch_thread_timed_wait' epilogue
         PDPEPIL
* Function 'dispatch_thread_timed_wait' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread_timed_wait' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
         
&FUNC    SETC 'dispatch_thread_check'
@@LC2    EQU   *
         DC    C'worker %08X, task %08X ended ABEND S%03X'
         DC    X'0'
         DS    0F
         EJECT
* static function 'dispatch_thread_check' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'dispatch_thread_check'
@@5      PDPPRLG CINDEX=4,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN4
         LTORG
@@FEN4   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG4    EQU   *
         LR    11,1
         L     10,=A(@@PGT4)
* Function 'dispatch_thread_check' code
         L     5,0(11)
         SLR   6,6
         ST    5,88(13)
         ST    6,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    2,5
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,6
         CLR   6,15
         BNL   @@L35
@@L43    EQU   *
         L     3,28(5)
         LR    2,4
         MH    2,=H'4'
         L     2,0(2,3)
         ST    2,108(13)
         LR    3,2
         LTR   2,2
         BE    @@L36
         MVC   104(4,13),16(2)
         L     2,104(13)
         LTR   2,2
         BE    @@L36
         L     2,28(3)
         N     2,=F'1'
         LTR   2,2
         BE    @@L40
         LA    6,1(0,0)
@@L40    EQU   *
         L     3,104(13)
         L     2,16(3)
         N     2,=F'1073741824'
         LTR   2,2
         BE    @@L36
         L     2,16(3)
         SRL   2,12
         N     2,=F'4095'
         LTR   2,2
         BE    @@L42
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),108(13)
         ST    3,96(13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L42    EQU   *
         L     2,108(13)
         MVC   24(4,2),=F'5'
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTDEL)
         BALR  14,15
         L     2,108(13)
         MVC   16(4,2),=F'0'
         LA    2,108(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWDEL)
         BALR  14,15
         LA    6,1(0,0)
         B     @@L35
@@L36    EQU   *
         A     4,=F'1'
         CLR   4,15
         BL    @@L43
@@L35    EQU   *
         ST    5,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,6
* Function 'dispatch_thread_check' epilogue
         PDPEPIL
* Function 'dispatch_thread_check' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread_check' page table
@@PGT4   DS    0F
         DC    A(@@PG4)
         
&FUNC    SETC 'dispatch_thread_quiesce'
         DS    0F
         EJECT
* static function 'dispatch_thread_quiesce' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'dispatch_thread_quiesce'
@@6      PDPPRLG CINDEX=5,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN5
         LTORG
@@FEN5   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG5    EQU   *
         LR    11,1
         L     10,=A(@@PGT5)
* Function 'dispatch_thread_quiesce' code
         L     5,0(11)
         LA    6,1(0,0)
         ST    5,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    2,5
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,15
         LR    3,15
         LTR   15,15
         BE    @@L57
@@L54    EQU   *
         LR    2,5
         A     2,=F'28'
         ST    2,88(13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARGET)
         BALR  14,15
         LTR   15,15
         BE    @@L48
         L     2,16(15)
         LTR   2,2
         BE    @@L48
         L     2,16(2)
         N     2,=F'1073741824'
         LTR   2,2
         BNE   @@L48
         L     2,24(15)
         LA    7,2(0,0)
         CLR   2,7
         BNE   @@L48
         ST    15,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWSHU)
         BALR  14,15
@@L48    EQU   *
         BCTR  3,0
         LTR   3,3
         BNE   @@L54
@@L57    EQU   *
         ST    5,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LTR   4,4
         BNE   @@L55
         LR    6,4
@@L55    EQU   *
         LR    15,6
* Function 'dispatch_thread_quiesce' epilogue
         PDPEPIL
* Function 'dispatch_thread_quiesce' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread_quiesce' page table
@@PGT5   DS    0F
         DC    A(@@PG5)
         
&FUNC    SETC 'dispatch_work'
         DS    0F
         EJECT
* static function 'dispatch_work' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'dispatch_work'
@@10     PDPPRLG CINDEX=6,FRAME=128,BASER=12,ENTRY=NO
         B     @@FEN6
         LTORG
@@FEN6   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG6    EQU   *
         LR    11,1
         L     10,=A(@@PGT6)
* Function 'dispatch_work' code
         L     5,0(11)
         L     4,4(11)
         LTR   4,4
         BE    @@L58
         L     2,16(4)
         LTR   2,2
         BE    @@L58
         L     3,16(2)
         N     3,=F'1073741824'
         LTR   3,3
         BNE   @@L58
         L     2,24(4)
         LA    6,2(0,0)
         CLR   2,6
         BNE   @@L58
         LR    2,5
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    6,15
         L     2,28(4)
         N     2,=F'2'
         LTR   2,2
         BE    @@L64
         LR    6,3
         L     2,28(4)
         N     2,=F'1'
         LTR   2,2
         BE    @@L58
         B     @@L66
@@L64    EQU   *
         LTR   15,15
         BNE   @@L66
         L     2,28(4)
         N     2,=F'1'
         LTR   2,2
         BE    @@L58
@@L66    EQU   *
         MVC   88(4,13),=F'0'
         LA    0,104(,13)
         LA    1,88(,13)
         L     15,=V(TM64TIME)
         BALR  14,15
         MVC   112(8,13),104(13)
         LA    2,112(,13)
         ST    2,88(13)
         LR    2,4
         A     2,=F'40'
         ST    2,92(13)
         LA    2,120(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SUB)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         LR    3,15
         LTR   6,6
         BNE   @@L70
         LTR   15,15
         BE    @@L69
@@L70    EQU   *
         LR    2,5
         A     2,=F'48'
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AU32)
         BALR  14,15
         LR    2,4
         A     2,=F'56'
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AU32)
         BALR  14,15
         MVC   48(8,4),112(13)
         MVC   24(4,4),=F'3'
@@L69    EQU   *
         LTR   6,6
         BE    @@L71
         LR    2,5
         A     2,=F'32'
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         ST    15,20(4)
         LR    2,4
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         B     @@L74
@@L71    EQU   *
         LTR   3,3
         BE    @@L58
         MVC   20(4,4),=F'0'
         LR    2,4
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'1'
@@L74    EQU   *
         LA    1,88(,13)
         L     15,=V(@@CTPOST)
         BALR  14,15
@@L60    EQU   *
@@L58    EQU   *
* Function 'dispatch_work' epilogue
         PDPEPIL
* Function 'dispatch_work' literal pool
         DS    0D
         LTORG
* Function 'dispatch_work' page table
@@PGT6   DS    0F
         DC    A(@@PG6)
         
&FUNC    SETC 'dispatch_thread_work'
         DS    0F
         EJECT
* static function 'dispatch_thread_work' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'dispatch_thread_work'
@@7      PDPPRLG CINDEX=7,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN7
         LTORG
@@FEN7   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG7    EQU   *
         LR    11,1
         L     10,=A(@@PGT7)
* Function 'dispatch_thread_work' code
         L     6,0(11)
         SLR   7,7
         ST    6,88(13)
         ST    7,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    2,6
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    5,15
         CL    15,40(6)
         BNL   @@L76
         ST    6,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWADD)
         BALR  14,15
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    5,15
@@L76    EQU   *
         CL    5,44(6)
         BNH   @@L77
         LR    4,5
         LTR   5,5
         BE    @@L77
@@L85    EQU   *
         LR    2,6
         A     2,=F'28'
         ST    2,88(13)
         ST    4,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARGET)
         BALR  14,15
         ST    15,96(13)
         LTR   15,15
         BE    @@L80
         L     2,24(15)
         LA    8,2(0,0)
         CLR   2,8
         BNE   @@L80
         ST    15,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWSHU)
         BALR  14,15
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWDEL)
         BALR  14,15
         BCTR  5,0
         CL    5,44(6)
         BNH   @@L77
@@L80    EQU   *
         BCTR  4,0
         LTR   4,4
         BNE   @@L85
@@L77    EQU   *
         L     2,4(11)
         LTR   2,2
         BNE   @@L86
         LR    2,6
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15
         BE    @@L88
@@L86    EQU   *
         LR    2,6
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    5,15
         LTR   15,15
         BE    @@L88
         L     2,56(6)
         A     2,=F'1'
         ST    2,56(6)
         CLR   2,15
         BL    @@L90
         MVC   56(4,6),=F'0'
@@L90    EQU   *
         L     4,56(6)
         CLR   4,5
         BNL   @@L104
@@L95    EQU   *
         ST    6,88(13)
         L     3,28(6)
         LR    2,4
         MH    2,=H'4'
         L     3,0(2,3)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=A(@@10)
         BALR  14,15
         A     4,=F'1'
         CLR   4,5
         BL    @@L95
@@L104   EQU   *
         SLR   4,4
         CL    4,56(6)
         BNL   @@L106
@@L100   EQU   *
         ST    6,88(13)
         L     3,28(6)
         LR    2,4
         MH    2,=H'4'
         L     3,0(2,3)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=A(@@10)
         BALR  14,15
         A     4,=F'1'
         CL    4,56(6)
         BL    @@L100
@@L106   EQU   *
         LR    2,6
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15
         BE    @@L88
         LA    7,1(0,0)
@@L88    EQU   *
         ST    6,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,7
* Function 'dispatch_thread_work' epilogue
         PDPEPIL
* Function 'dispatch_thread_work' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread_work' page table
@@PGT7   DS    0F
         DC    A(@@PG7)
         
&FUNC    SETC 'dispatch_thread_create'
         DS    0F
         EJECT
* static function 'dispatch_thread_create' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'dispatch_thread_create'
@@9      PDPPRLG CINDEX=8,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN8
         LTORG
@@FEN8   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG8    EQU   *
         LR    11,1
         L     10,=A(@@PGT8)
* Function 'dispatch_thread_create' code
         L     3,0(11)
         SLR   4,4
         ST    3,88(13)
         ST    4,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    2,3
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         CL    15,44(3)
         BNL   @@L108
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWADD)
         BALR  14,15
@@L108   EQU   *
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,4
* Function 'dispatch_thread_create' epilogue
         PDPEPIL
* Function 'dispatch_thread_create' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread_create' page table
@@PGT8   DS    0F
         DC    A(@@PG8)
         
&FUNC    SETC 'dispatch_thread_term'
         DS    0F
         EJECT
* static function 'dispatch_thread_term' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'dispatch_thread_term'
@@8      PDPPRLG CINDEX=9,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN9
         LTORG
@@FEN9   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG9    EQU   *
         LR    11,1
         L     10,=A(@@PGT9)
* Function 'dispatch_thread_term' code
         L     4,0(11)
         SLR   5,5
         ST    4,88(13)
         ST    5,92(13)
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         MVC   36(4,4),=F'2'
         LR    2,4
         A     2,=F'28'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    3,15
         LTR   15,15
         BE    @@L117
@@L115   EQU   *
         LR    2,4
         A     2,=F'28'
         ST    2,88(13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARGET)
         BALR  14,15
         ST    15,96(13)
         LTR   15,15
         BE    @@L112
         ST    15,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWSHU)
         BALR  14,15
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CMWDEL)
         BALR  14,15
@@L112   EQU   *
         BCTR  3,0
         LTR   3,3
         BNE   @@L115
@@L117   EQU   *
         MVC   36(4,4),=F'3'
         ST    4,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,5
* Function 'dispatch_thread_term' epilogue
         PDPEPIL
* Function 'dispatch_thread_term' literal pool
         DS    0D
         LTORG
* Function 'dispatch_thread_term' page table
@@PGT9   DS    0F
         DC    A(@@PG9)
         END
