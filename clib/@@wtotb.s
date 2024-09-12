 TITLE '/home/mike/repos/crent370/clib/@@wtotb.c'
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
         
&FUNC    SETC 'wto_traceback'
* Program text area
         DS    0F
         EJECT
* external function 'wto_traceback' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'wto_traceback'
@@WTOTB  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'wto_traceback' code
         MVC   88(4,13),=A(@@6)
         MVC   92(4,13),0(11) ==> sa
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
* Function 'wto_traceback' epilogue
         PDPEPIL
* Function 'wto_traceback' literal pool
         DS    0D
         LTORG
* Function 'wto_traceback' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'try_traceback'
         DS    0F
         EJECT
* static function 'try_traceback' prologue
* frame base=88, local stack=544, call args=24
&FUNC    SETC  'try_traceback'
@@6      PDPPRLG CINDEX=1,FRAME=656,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'try_traceback' code
         L     5,0(11) ==> sa
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         ST    15,644(13) ==> crt
         LTR   5,5 ==> sa
         BNE   @@L3
         ST     13,624(13)        return save area address
         L     2,624(13) ==> sa
         L     5,4(2) ==> sa,prev
         LR    2,5 ==> sa
         LTR   5,5 ==> sa
         BNE   @@L7
         ST     13,628(13)        return save area address
         L     2,628(13) ==> sa
@@L7     EQU   *
         L     5,4(2) ==> sa,prev
         LR    2,5 ==> sa
         LTR   5,5 ==> sa
         BNE   @@L10
         ST     13,632(13)        return save area address
         L     2,632(13) ==> sa
@@L10    EQU   *
         L     5,4(2) ==> sa,prev
         LR    2,5 ==> sa
         LTR   5,5 ==> sa
         BNE   @@L13
         ST     13,636(13)        return save area address
         L     2,636(13) ==> sa
@@L13    EQU   *
         L     5,4(2) ==> sa,prev
@@L3     EQU   *
         MVC   88(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   648(4,13),=F'0' ==> i
         L     8,4(5) ==> prev,prev
         L     2,644(13) ==> crt
         CL    5,12(2) ==> sa,crtsave
         BE    @@L2
@@L30    EQU   *
         LR    2,5 ==> sa
         LTR   5,5 ==> sa
         BNE   @@L21
         ST     13,640(13)        return save area address
         L     2,640(13) ==> sa
@@L21    EQU   *
         L     9,8(2) ==> next,next
         L     7,16(8) ==> prevep,r15
         LA    4,368(,13) ==> epname
         LR    2,7 ==> ep,prevep
         MVI   0(4),0 ==> epname
         CLI   0(7),71 ==> prevep
         BNE   @@L24
         CLI   1(7),240
         BNE   @@L24
         LR    3,7 ==> p,prevep
         A     3,=F'4' ==> p
         ST    4,88(13) ==> epname
         A     2,=F'5'
         ST    2,92(13)
         SLR   2,2
         IC    2,0(3) ==> p
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   2,2
         IC    2,0(3) ==> p
         SLR   3,3
         STC   3,0(2,4)
         B     @@L26
@@L24    EQU   *
         ST    4,88(13) ==> epname
         MVC   92(4,13),=A(@@LC1)
         ST    2,96(13) ==> ep
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L26    EQU   *
         L     6,16(5) ==> thisep,r15
         LA    4,112(,13) ==> epname
         LR    2,6 ==> ep,thisep
         MVI   0(4),0 ==> epname
         CLI   0(6),71 ==> thisep
         BNE   @@L27
         CLI   1(6),240
         BNE   @@L27
         LR    3,6 ==> p,thisep
         A     3,=F'4' ==> p
         ST    4,88(13) ==> epname
         A     2,=F'5'
         ST    2,92(13)
         SLR   2,2
         IC    2,0(3) ==> p
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   2,2
         IC    2,0(3) ==> p
         SLR   3,3
         STC   3,0(2,4)
         B     @@L29
@@L27    EQU   *
         ST    4,88(13) ==> epname
         MVC   92(4,13),=A(@@LC1)
         ST    2,96(13) ==> ep
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L29    EQU   *
         L     4,76(9) ==> frame,nab
         SR    4,9 ==> frame,next
         L     3,12(5) ==> retto,r14
         N     3,=F'268435455' ==> retto
         LR    5,3 ==> offset,retto
         S     5,16(8) ==> offset,r15
         MVC   88(4,13),=A(@@LC2)
         LA    2,112(,13)
         ST    2,92(13)
         ST    6,96(13) ==> thisep
         ST    4,100(13) ==> frame
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC3)
         ST    3,92(13) ==> retto
         LA    2,368(,13)
         ST    2,96(13)
         ST    7,100(13) ==> prevep
         ST    5,104(13) ==> offset
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         L     2,648(13) ==> i
         A     2,=F'1'
         ST    2,648(13) ==> i
         LR    5,8 ==> sa,prev
         L     8,4(8) ==> prev,prev
         LA    3,255(0,0)
         CR    2,3
         BH    @@L2
         L     2,644(13) ==> crt
         CL    5,12(2) ==> sa,crtsave
         BNE   @@L30
@@L2     EQU   *
* Function 'try_traceback' epilogue
         PDPEPIL
* Function 'try_traceback' literal pool
         DS    0D
         LTORG
* Function 'try_traceback' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@LC0    EQU   *
         DC    C'Save area trace back'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%08X (unknown)'
         DC    X'0'
@@LC2    EQU   *
         DC    C'  "%s" ep=%06X frame=%u bytes'
         DC    X'0'
@@LC3    EQU   *
         DC    C'    returns to=%06X "%s" ep=%06X+%X'
         DC    X'0'
         END
