 TITLE '/home/mike/repos/crent370/dyn75/@@75selx.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/dyn75
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'selectex'
* Program text area
         DS    0F
         EJECT
* external function 'selectex' prologue
* frame base=88, local stack=64, call args=8
&FUNC    SETC  'selectex'
@@75SELX PDPPRLG CINDEX=0,FRAME=160,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'selectex' code
         L     4,0(11) ==> maxsock
         L     8,4(11) ==> r
         L     9,8(11) ==> w
         L     7,16(11) ==> t
         SLR   6,6 ==> count
         LR    5,6 ==> wait,count
         LA    2,96(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         SLR   3,3 ==> rc
         LA    2,1(0,0)
         CR    4,2 ==> maxsock
         BNH   @@L3
         L     2,20(11)
         LTR   2,2
         BE    @@L4
         LA    2,20(,11)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    6,15 ==> count
@@L4     EQU   *
         LR    2,4 ==> maxsock
         BCTR  2,0
         SLL   2,16
         O     2,=F'17'
         ST    2,124(13) ==> .r7
         MVC   128(4,13),=F'0' ==> .r8
         ST    4,132(13) ==> maxsock,r9
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LR    3,4 ==> bytes,maxsock
         A     3,=F'31' ==> bytes
         LR    2,3 ==> bytes
         BNL   @@L5
         A     2,=F'31' ==> bytes
@@L5     EQU   *
         SRA   2,5
         LR    3,2 ==> bytes
         MH    3,=H'4' ==> bytes
         LTR   8,8 ==> r
         BE    @@L6
         ST    3,100(13) ==> bytes,r1
         ST    8,116(13) ==> r,r5
         MVC   128(4,13),=F'1' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
@@L6     EQU   *
         LTR   9,9 ==> w
         BE    @@L7
         ST    3,100(13) ==> bytes,r1
         ST    9,116(13) ==> w,r5
         MVC   128(4,13),=F'2' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
@@L7     EQU   *
         L     2,12(11) ==> e
         LTR   2,2
         BE    @@L8
         ST    3,100(13) ==> bytes,r1
         ST    2,116(13) ==> .r5
         MVC   128(4,13),=F'3' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
@@L8     EQU   *
         LTR   7,7 ==> t
         BE    @@L13
         L     5,0(7) ==> wait,tv_sec
         SLL   5,5 ==> wait
         LR    2,5 ==> wait
         SLL   2,1
         AR    5,2 ==> wait
         SRL   5,3 ==> wait
         L     2,4(7) ==> .tv_usec
         LTR   2,2
         BE    @@L13
         LA    3,64(0,0)
         CR    2,3
         BNH   @@L11
         SRA   2,6
         AR    5,2 ==> wait
         B     @@L13
@@L11    EQU   *
         A     5,=F'1' ==> wait
@@L13    EQU   *
         MVC   100(4,13),=F'0' ==> .r1
         MVC   128(4,13),=F'4' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     3,112(13) ==> rc,r4
         L     2,=F'-2'
         CLR   3,2 ==> rc
         BNE   @@L27
         MVC   112(4,13),=F'0' ==> .r4
         LTR   7,7 ==> t
         BE    @@L17
         LTR   5,5 ==> wait
         BE    @@L27
         BCTR  5,0 ==> wait
@@L17    EQU   *
         L     2,20(11)
         LTR   2,2
         BE    @@L19
         LTR   6,6 ==> count
         BE    @@L20
         SLR   3,3 ==> n
         CLR   3,6 ==> n,count
         BNL   @@L19
         LR    4,2
@@L28    EQU   *
         LR    2,3 ==> n
         MH    2,=H'4'
         L     15,0(2,4) ==> ecb
         LTR   15,15 ==> ecb
         BE    @@L23
         L     2,0(15) ==> ecb
         N     2,=F'1073741824'
         LTR   2,2
         BNE   @@L27
@@L23    EQU   *
         A     3,=F'1' ==> n
         CLR   3,6 ==> n,count
         BNL   @@L19
         B     @@L28
@@L20    EQU   *
         SLR   3,3 ==> n
         L     2,20(11)
         L     2,0(2)
         LTR   2,2
         BE    @@L19
         L     4,20(11)
@@L37    EQU   *
         LR    2,3 ==> n
         MH    2,=H'4'
         L     15,0(2,4) ==> ecb
         L     2,=F'-2147483648'
         CLR   15,2 ==> ecb
         BE    @@L19
         L     2,0(15) ==> ecb
         N     2,=F'1073741824'
         LTR   2,2
         BNE   @@L27
         LTR   15,15 ==> ecb
         BL    @@L19
         A     3,=F'1' ==> n
         LR    2,3 ==> n
         MH    2,=H'4'
         L     2,0(2,4)
         LTR   2,2
         BNE   @@L37
@@L19    EQU   *
         STIMER WAIT,BINTVL==F'8'   0.08 seconds
         B     @@L13
@@L27    EQU   *
         L     3,112(13) ==> rc,r4
         L     2,=F'-1'
         CLR   3,2 ==> rc
         BNE   @@L38
         MVC   100(4,13),=F'0' ==> .r1
         L     2,124(13) ==> .r7
         SRL   2,16
         ST    2,128(13) ==> .r8
         MVC   124(4,13),=F'2' ==> .r7
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),112(13) ==> count,r4
@@L38    EQU   *
         LTR   8,8 ==> r
         BE    @@L39
         MVC   100(4,13),=F'0' ==> .r1
         ST    8,120(13) ==> r,r6
         MVC   128(4,13),=F'5' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
@@L39    EQU   *
         LTR   9,9 ==> w
         BE    @@L40
         MVC   100(4,13),=F'0' ==> .r1
         ST    9,120(13) ==> w,r6
         MVC   128(4,13),=F'6' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
@@L40    EQU   *
         L     2,12(11) ==> e
         LTR   2,2
         BE    @@L41
         MVC   100(4,13),=F'0' ==> .r1
         ST    2,120(13) ==> .r6
         MVC   128(4,13),=F'7' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
@@L41    EQU   *
         MVC   128(4,13),=F'8' ==> .r8
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
@@L3     EQU   *
         LR    15,3 ==> rc
* Function 'selectex' epilogue
         PDPEPIL
* Function 'selectex' literal pool
         DS    0D
         LTORG
* Function 'selectex' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
