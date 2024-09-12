 TITLE '/home/mike/repos/crent370/clib/@@abrpt.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/include
* -iprefix -D__GNUC__=3 -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3
* -D__GXX_ABI_VERSION=102 -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__
* -Asystem=mvs -Acpu=i370 -Amachine=i370 -D__OPTIMIZE__
* -D__STDC_HOSTED__=1 -trigraphs -O1 -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'get_offset'
* Program text area
         DS    0F
         EJECT
* static function 'get_offset' prologue
* frame base=88, local stack=0, call args=24
&FUNC    SETC  'get_offset'
@@0      PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'get_offset' code
         L     2,0(11) ==> sdwa
         L     4,4(11) ==> buf
         L     3,108(2) ==> psw,SDWANXT1
         L     2,76(2) ==> np,SDWAGR13
         MVI   0(4),0 ==> buf
         L     5,=F'8191'
         CLR   2,5 ==> np
         BNH   @@L1
         L     2,4(2) ==> np
         L     15,16(2) ==> ep
         LR    5,3 ==> offset,psw
         SR    5,15 ==> offset,ep
         CLR   15,3 ==> ep,psw
         BH    @@L1
         L     2,0(15) ==> ep
         SRL   2,8
         L     6,=F'4714736'
         CLR   2,6
         BNE   @@L1
         LR    2,15 ==> cp,ep
         CLC   4(1,15),3(15)
         BH    @@L1
         SLR   3,3 ==> len
         IC    3,4(15) ==> len
         LA    6,40(0,0)
         CLR   3,6 ==> len
         BNH   @@L7
         LR    3,6 ==> len
@@L7     EQU   *
         ST    4,88(13) ==> buf
         MVC   92(4,13),=A(@@LC0)
         ST    3,96(13) ==> len
         ST    3,100(13) ==> len
         A     2,=F'5'
         ST    2,104(13)
         ST    5,108(13) ==> offset
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L3     EQU   *
@@L1     EQU   *
* Function 'get_offset' epilogue
         PDPEPIL
* Function 'get_offset' literal pool
         DS    0D
         LTORG
* Function 'get_offset' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'epname %-*.*s offset %08X'
         DC    X'0'
         
&FUNC    SETC 'get_addr'
         DS    0F
         EJECT
* static function 'get_addr' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'get_addr'
@@1      PDPPRLG CINDEX=1,FRAME=128,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'get_addr' code
         L     8,4(11) ==> buf
         ST    8,88(13) ==> buf
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         MVC   120(4,13),=F'0' ==> pos
         LA    5,37(0,0) ==> pos2
         L     6,0(11) ==> np,addr
         LR    4,6 ==> cp,np
         SLR   9,9 ==> i
         L     7,=V(@@ISBUF)
@@L19    EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC2)
         MVC   96(4,13),0(6) ==> np
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,120(13) ==> pos
         AR    2,8 ==> buf
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   15,15 ==> j
@@L18    EQU   *
         SLR   2,2
         IC    2,0(4) ==> cp
         L     3,0(7) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'16'
         CH    2,=H'0'
         BE    @@L15
         IC    2,0(4) ==> cp
         STC   2,0(5,8) ==> pos2
@@L15    EQU   *
         A     15,=F'1' ==> j
         A     4,=F'1' ==> cp
         A     5,=F'1' ==> pos2
         LA    2,3(0,0)
         CR    15,2 ==> j
         BNH   @@L18
         A     9,=F'1' ==> i
         A     6,=F'4' ==> np
         L     2,120(13) ==> pos
         A     2,=F'9'
         ST    2,120(13) ==> pos
         LA    2,3(0,0)
         CR    9,2 ==> i
         BNH   @@L19
@@L20    EQU   *
* Function 'get_addr' epilogue
         PDPEPIL
* Function 'get_addr' literal pool
         DS    0D
         LTORG
* Function 'get_addr' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@LC1    EQU   *
         DC    C'........ ........ ........ ........ *...........'
         DC    C'.....*'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%08X'
         DC    X'0'
         
&FUNC    SETC 'get_epname'
         DS    0F
         EJECT
* static function 'get_epname' prologue
* frame base=88, local stack=0, call args=24
&FUNC    SETC  'get_epname'
@@2      PDPPRLG CINDEX=2,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'get_epname' code
         L     15,0(11) ==> addr
         L     3,4(11) ==> buf
         MVI   0(3),0 ==> buf
         L     2,0(15) ==> addr
         SRL   2,8
         L     4,=F'4714736'
         CLR   2,4
         BNE   @@L25
         LR    2,15 ==> cp,addr
         CLC   4(1,15),3(15)
         BH    @@L25
         SLR   15,15 ==> len
         IC    15,4(2) ==> len
         LA    4,40(0,0)
         CLR   15,4 ==> len
         BNH   @@L29
         LR    15,4 ==> len
@@L29    EQU   *
         ST    3,88(13) ==> buf
         MVC   92(4,13),=A(@@LC3)
         ST    15,96(13) ==> len
         ST    15,100(13) ==> len
         A     2,=F'5'
         ST    2,104(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L28    EQU   *
@@L25    EQU   *
* Function 'get_epname' epilogue
         PDPEPIL
* Function 'get_epname' literal pool
         DS    0D
         LTORG
* Function 'get_epname' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
@@LC3    EQU   *
         DC    C'%-*.*s'
         DC    X'0'
         
&FUNC    SETC 'dump_regs'
         DS    0F
         EJECT
* static function 'dump_regs' prologue
* frame base=88, local stack=80, call args=16
&FUNC    SETC  'dump_regs'
@@3      PDPPRLG CINDEX=3,FRAME=184,BASER=12,ENTRY=NO
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function 'dump_regs' code
         SLR   3,3 ==> i
         L     2,0(11) ==> n,sdwa
         A     2,=F'24' ==> n
         LA    4,104(,13)
@@L35    EQU   *
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),0(2) ==> n
         ST    4,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC4)
         ST    3,92(13) ==> i
         MVC   96(4,13),0(2) ==> n
         ST    4,100(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         A     3,=F'1' ==> i
         A     2,=F'4' ==> n
         LA    5,15(0,0)
         CR    3,5 ==> i
         BNH   @@L35
         SLR   15,15
* Function 'dump_regs' epilogue
         PDPEPIL
* Function 'dump_regs' literal pool
         DS    0D
         LTORG
* Function 'dump_regs' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
@@LC4    EQU   *
         DC    C'R%02d:%08X:%s'
         DC    X'0'
         
&FUNC    SETC 'get_sa_prev'
         DS    0F
         EJECT
* static function 'get_sa_prev' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'get_sa_prev'
@@4      PDPPRLG CINDEX=4,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN4
         LTORG
@@FEN4   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG4    EQU   *
         LR    11,1
         L     10,=A(@@PGT4)
* Function 'get_sa_prev' code
         L     15,0(11) ==> n
         L     2,4(15)
         A     2,=F'-8192'
         L     3,=F'16703487'
         CLR   2,3
         BH    @@L39
         L     2,4(11) ==> prev
         MVC   0(4,2),4(15) ==> prev
@@L39    EQU   *
         SLR   15,15
* Function 'get_sa_prev' epilogue
         PDPEPIL
* Function 'get_sa_prev' literal pool
         DS    0D
         LTORG
* Function 'get_sa_prev' page table
@@PGT4   DS    0F
         DC    A(@@PG4)
         
&FUNC    SETC 'get_sa_next'
         DS    0F
         EJECT
* static function 'get_sa_next' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'get_sa_next'
@@5      PDPPRLG CINDEX=5,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN5
         LTORG
@@FEN5   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG5    EQU   *
         LR    11,1
         L     10,=A(@@PGT5)
* Function 'get_sa_next' code
         L     15,0(11) ==> n
         L     2,8(15)
         A     2,=F'-8192'
         L     3,=F'16703487'
         CLR   2,3
         BH    @@L41
         L     2,4(11) ==> next
         MVC   0(4,2),8(15) ==> next
@@L41    EQU   *
         SLR   15,15
* Function 'get_sa_next' epilogue
         PDPEPIL
* Function 'get_sa_next' literal pool
         DS    0D
         LTORG
* Function 'get_sa_next' page table
@@PGT5   DS    0F
         DC    A(@@PG5)
         
&FUNC    SETC 'dump_sa'
         DS    0F
         EJECT
* static function 'dump_sa' prologue
* frame base=88, local stack=88, call args=16
&FUNC    SETC  'dump_sa'
@@6      PDPPRLG CINDEX=6,FRAME=192,BASER=12,ENTRY=NO
         B     @@FEN6
         LTORG
@@FEN6   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG6    EQU   *
         LR    11,1
         L     10,=A(@@PGT6)
* Function 'dump_sa' code
         SLR   3,3 ==> psa
         L     2,540(3) ==> tcb
         L     2,112(2) ==> fsa
         N     2,=F'16777215' ==> fsa
         L     4,8(2) ==> ppa
         L     2,0(11) ==> sdwa
         L     2,76(2) ==> n,SDWAGR13
         ST    3,184(13) ==> psa
         MVC   88(4,13),=A(@@4)
         ST    2,92(13) ==> n
         LA    2,184(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         L     2,184(13)
         LTR   2,2
         BE    @@L58
         LA    5,104(,13)
         LR    3,5
@@L50    EQU   *
         L     2,184(13) ==> n
         MVC   88(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@2)
         MVC   92(4,13),16(2)
         ST    5,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         CLI   104(13),0 ==> buf
         BE    @@L47
         MVC   88(4,13),=A(@@LC6)
         ST    5,92(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L47    EQU   *
         MVC   88(4,13),=A(@@1)
         ST    2,92(13) ==> n
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC7)
         ST    2,92(13) ==> n
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),12(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC8)
         MVC   92(4,13),12(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),16(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC9)
         MVC   92(4,13),16(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),20(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC10)
         MVC   92(4,13),20(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),24(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC11)
         MVC   92(4,13),24(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         CLR   2,4 ==> n,ppa
         BE    @@L49
         MVC   184(4,13),=F'0'
         MVC   88(4,13),=A(@@4)
         ST    2,92(13) ==> n
         LA    2,184(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         L     2,184(13)
         LTR   2,2
         BNE   @@L50
@@L58    EQU   *
         MVC   88(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC12)
         ST    4,92(13) ==> ppa
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         ST    4,188(13) ==> ppa
         LTR   4,4
         BE    @@L49
         LA    4,104(,13)
         LR    3,4
@@L56    EQU   *
         L     2,188(13) ==> n
         MVC   88(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@2)
         MVC   92(4,13),16(2)
         ST    4,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         CLI   104(13),0 ==> buf
         BE    @@L55
         MVC   88(4,13),=A(@@LC6)
         ST    4,92(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L55    EQU   *
         MVC   88(4,13),=A(@@1)
         ST    2,92(13) ==> n
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC7)
         ST    2,92(13) ==> n
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),12(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC8)
         MVC   92(4,13),12(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),16(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC9)
         MVC   92(4,13),16(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),20(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC10)
         MVC   92(4,13),20(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@1)
         MVC   92(4,13),24(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC11)
         MVC   92(4,13),24(2)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   188(4,13),=F'0'
         MVC   88(4,13),=A(@@5)
         ST    2,92(13) ==> n
         LA    2,188(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         L     2,188(13)
         LTR   2,2
         BNE   @@L56
@@L49    EQU   *
         SLR   15,15
* Function 'dump_sa' epilogue
         PDPEPIL
* Function 'dump_sa' literal pool
         DS    0D
         LTORG
* Function 'dump_sa' page table
@@PGT6   DS    0F
         DC    A(@@PG6)
@@LC5    EQU   *
         DC    C'------------------------------------------------'
         DC    X'0'
@@LC6    EQU   *
         DC    C'%s'
         DC    X'0'
@@LC7    EQU   *
         DC    C'DSA:%08X:%s'
         DC    X'0'
@@LC8    EQU   *
         DC    C'R14:%08X:%s'
         DC    X'0'
@@LC9    EQU   *
         DC    C'R15:%08X:%s'
         DC    X'0'
@@LC10   EQU   *
         DC    C'R00:%08X:%s'
         DC    X'0'
@@LC11   EQU   *
         DC    C'R01:%08X:%s'
         DC    X'0'
@@LC12   EQU   *
         DC    C'Traceback interrupted, Forward from PPA %08X'
         DC    X'0'
         
&FUNC    SETC 'suppress_dump'
         DS    0F
         EJECT
* static function 'suppress_dump' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'suppress_dump'
@@7      PDPPRLG CINDEX=7,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN7
         LTORG
@@FEN7   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG7    EQU   *
         LR    11,1
         L     10,=A(@@PGT7)
* Function 'suppress_dump' code
         L     2,0(11) ==> sdwa
         MVC   88(4,13),=A(@@LC13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         NI    4(2),127 ==> .SDWACMPF
         SLR   15,15
* Function 'suppress_dump' epilogue
         PDPEPIL
* Function 'suppress_dump' literal pool
         DS    0D
         LTORG
* Function 'suppress_dump' page table
@@PGT7   DS    0F
         DC    A(@@PG7)
@@LC13   EQU   *
         DC    C'suppress dump requested'
         DC    X'0'
         
&FUNC    SETC 'snap_dump'
         DS    0F
         EJECT
* static function 'snap_dump' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'snap_dump'
@@8      PDPPRLG CINDEX=8,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN8
         LTORG
@@FEN8   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG8    EQU   *
         LR    11,1
         L     10,=A(@@PGT8)
* Function 'snap_dump' code
         L     3,0(11) ==> sdwa
         MVC   88(4,13),=A(@@LC14)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         OPEN  (SNAPDCB,(OUTPUT))         Open SNAP DCB
                  LR 2,15 ==> rc
         LTR   2,2 ==> rc
         BE    @@L62
         MVC   88(4,13),=A(@@LC15)
         ST    2,92(13) ==> rc
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L63
@@L62    EQU   *
         LA    2,SNAPDCB
         SNAP DCB=(2),SDATA=ALL,PDATA=ALL
         CLOSE SNAPDCB                    Close the SNAP DCB
         NI    4(3),127 ==> .SDWACMPF
@@L63    EQU   *
         SLR   15,15
* Function 'snap_dump' epilogue
         PDPEPIL
* Function 'snap_dump' literal pool
         DS    0D
         LTORG
* Function 'snap_dump' page table
@@PGT8   DS    0F
         DC    A(@@PG8)
@@LC14   EQU   *
         DC    C'snap dump requested'
         DC    X'0'
@@LC15   EQU   *
         DC    C'OPEN for SNAP DD failed, rc=%d'
         DC    X'0'
         
SNAPDCB  DCB   DDNAME=SNAP,DSORG=PS,LRECL=125,BLKSIZE=1632,            @
               RECFM=VBA,MACRF=(W)
         
&FUNC    SETC 'system_dump'
         DS    0F
         EJECT
* static function 'system_dump' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'system_dump'
@@9      PDPPRLG CINDEX=9,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN9
         LTORG
@@FEN9   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG9    EQU   *
         LR    11,1
         L     10,=A(@@PGT9)
* Function 'system_dump' code
         MVC   88(4,13),=A(@@LC16)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L65    EQU   *
         SLR   15,15
* Function 'system_dump' epilogue
         PDPEPIL
* Function 'system_dump' literal pool
         DS    0D
         LTORG
* Function 'system_dump' page table
@@PGT9   DS    0F
         DC    A(@@PG9)
@@LC16   EQU   *
         DC    C'system_dump requested'
         DC    X'0'
         
&FUNC    SETC 'recovery'
         DS    0F
         EJECT
* static function 'recovery' prologue
* frame base=88, local stack=128, call args=32
&FUNC    SETC  'recovery'
@@10     PDPPRLG CINDEX=10,FRAME=248,BASER=12,ENTRY=NO
         B     @@FEN10
         LTORG
@@FEN10  EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG10   EQU   *
         LR    11,1
         L     10,=A(@@PGT10)
* Function 'recovery' code
         L     5,0(11) ==> sdwa
         L     3,4(11) ==> udata
         LA    6,1(0,0) ==> dump
         SLR   2,2 ==> psa
         L     4,540(2) ==> tcb
         LTR   3,3 ==> udata
         BE    @@L67
         L     2,4(3) ==> dump,u
         LTR   2,2 ==> dump
         BE    @@L67
         LR    6,2 ==> dump
@@L67    EQU   *
         L     3,4(5) ==> abcode
         LR    2,3 ==> abcode
         N     2,=F'16773120' ==> abcode
         LTR   2,2 ==> abcode
         BE    @@L68
         LR    3,2 ==> abcode
         SRL   3,12 ==> abcode
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC17)
         B     @@L91
@@L68    EQU   *
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC18)
         N     3,=F'4095' ==> abcode
@@L91    EQU   *
         ST    3,96(13) ==> abcode
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LR    3,5 ==> sdwa
         A     3,=F'104'
         LA    2,240(,13)
         MVC   0(8,2),0(3)
         L     3,96(5) ==> epa,SDWAEPA
         CLI   88(5),64 ==> .SDWANAME
         BH    @@L70
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC2)
         ST    3,96(13) ==> epa
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         B     @@L71
@@L90    EQU   *
         SLR   2,2
         STC   2,120(13,3) ==> epname
         B     @@L71
@@L70    EQU   *
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC19)
         LR    2,5 ==> sdwa
         A     2,=F'88'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         SLR   3,3 ==> i
@@L77    EQU   *
         IC    2,120(13,3) ==> epname
         SLL   2,24
         SRA   2,24
         C     2,=F'64'
         BE    @@L90
         A     3,=F'1' ==> i
         LA    2,7(0,0)
         CR    3,2 ==> i
         BNH   @@L77
@@L71    EQU   *
         MVC   88(4,13),=A(@@0)
         ST    5,92(13) ==> sdwa
         LA    3,160(,13)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC20)
         LA    2,136(,13)
         ST    2,92(13)
         LA    2,120(,13)
         ST    2,96(13)
         ST    3,100(13)
         ST    4,104(13) ==> tcb
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         IC    2,20(5) ==> .SDWAPMKP
         SRL   2,5 ==> ilc
         LR    4,2 ==> ilc
         N     4,=F'6' ==> ilc
         IC    2,106(5) ==> .SDWAINT1
         SRL   2,4 ==> cc
         LR    15,2 ==> cc
         N     15,=F'3' ==> cc
         MVC   88(4,13),=A(@@LC21)
         MVC   92(4,13),240(13)
         MVC   96(4,13),244(13) ==> psw
         IC    2,105(5) ==> .SDWAMWP1
         SRL   2,4
         N     2,=F'15'
         ST    2,100(13)
         IC    2,105(5) ==> .SDWAMWP1
         N     2,=F'1'
         L     3,=A(@@LC22)
         CLM   2,1,=XL1'00'
         BNE   @@L79
         L     3,=A(@@LC23)
@@L79    EQU   *
         ST    3,104(13)
         ST    4,108(13) ==> ilc
         ST    15,112(13) ==> cc
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LA    3,244(,13)
         L     2,0(3) ==> psw
         N     2,=F'16777215'
         ST    2,0(3) ==> psw
         CLR   2,4 ==> ilc
         BNH   @@L80
         SR    2,4 ==> ilc
         ST    2,0(3) ==> psw
@@L80    EQU   *
         MVC   88(4,13),=A(@@1)
         LA    3,244(,13)
         MVC   92(4,13),0(3) ==> psw
         LA    2,160(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         MVC   88(4,13),=A(@@LC24)
         MVC   92(4,13),0(3) ==> psw
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         ST    5,88(13) ==> sdwa
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
         ST    5,88(13) ==> sdwa
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         LA    2,1(0,0)
         CR    6,2 ==> dump
         BE    @@L81
         BH    @@L88
         LTR   6,6 ==> dump
         BE    @@L82
         B     @@L81
@@L88    EQU   *
         LA    2,2(0,0)
         CLR   6,2 ==> dump
         BE    @@L84
         LA    2,3(0,0)
         CLR   6,2 ==> dump
         BE    @@L85
         B     @@L81
@@L82    EQU   *
         ST    5,88(13) ==> sdwa
         LA    1,88(,13)
         L     15,=A(@@7)
         BALR  14,15
         B     @@L81
@@L84    EQU   *
         ST    5,88(13) ==> sdwa
         LA    1,88(,13)
         L     15,=A(@@8)
         BALR  14,15
         B     @@L81
@@L85    EQU   *
         ST    5,88(13) ==> sdwa
         LA    1,88(,13)
         L     15,=A(@@9)
         BALR  14,15
@@L81    EQU   *
         MVI   252(5),0 ==> .SDWARCDE
         MVC   240(4,5),=F'0' ==> .SDWARTYA
         SLR   15,15
* Function 'recovery' epilogue
         PDPEPIL
* Function 'recovery' literal pool
         DS    0D
         LTORG
* Function 'recovery' page table
@@PGT10  DS    0F
         DC    A(@@PG10)
@@LC17   EQU   *
         DC    C'S%03X'
         DC    X'0'
@@LC18   EQU   *
         DC    C'U%04D'
         DC    X'0'
@@LC19   EQU   *
         DC    C'%-8.8s'
         DC    X'0'
@@LC20   EQU   *
         DC    C'ABEND %s detected for module %s %s TCB=%08X'
         DC    X'0'
@@LC21   EQU   *
         DC    C'PSW:%08X %08X KEY(%u) MODE(%s) ILC(%u) CC(%u)'
         DC    X'0'
@@LC22   EQU   *
         DC    C'PROB'
         DC    X'0'
@@LC23   EQU   *
         DC    C'SUP'
         DC    X'0'
@@LC24   EQU   *
         DC    C'>>>:%08X:%s'
         DC    X'0'
         DS    0F
         EJECT
* external function '__abrpt' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__abrpt'
@@ABRPT  PDPPRLG CINDEX=11,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN11
         LTORG
@@FEN11  EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG11   EQU   *
         LR    11,1
         L     10,=A(@@PGT11)
* Function '__abrpt' code
         L     2,0(11) ==> estae_op
         L     15,=F'-1' ==> rc
         LA    3,2(0,0)
         CLR   2,3 ==> estae_op
         BH    @@L93
         ST    2,88(13) ==> estae_op
         MVC   92(4,13),=A(@@10)
         MVC   96(4,13),4(11) ==> dump_op
         LA    1,88(,13)
         L     15,=V(@@ESTAE)
         BALR  14,15
@@L93    EQU   *
* Function '__abrpt' epilogue
         PDPEPIL
* Function '__abrpt' literal pool
         DS    0D
         LTORG
* Function '__abrpt' page table
@@PGT11  DS    0F
         DC    A(@@PG11)
         END
