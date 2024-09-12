 TITLE '/home/mike/repos/crent370/clib/@@enqdeq.c'
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
* Program text area
         DS    0F
         EJECT
* external function '__enqdeq' prologue
* frame base=88, local stack=24, call args=8
&FUNC    SETC  '__enqdeq'
@@ENQDEQ PDPPRLG CINDEX=0,FRAME=120,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__enqdeq' code
         L     6,0(11) ==> qn
         L     7,4(11) ==> rn
         L     8,8(11) ==> options
         LA    4,96(,13)
         LA    5,12(0,0)
         SLR   2,2
         LR    3,2
         MVCL  4,2
         LA    2,1(0,0) ==> err
         LTR   6,6 ==> qn
         BE    @@L4
         LTR   7,7 ==> rn
         BE    @@L4
         ST    7,88(13) ==> rn
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LTR   15,15 ==> len
         BE    @@L4
         MVI   96(13),192 ==> .end
         STC   15,97(13) ==> len,len
         SLR   15,15 ==> len
         IC    2,0(6) ==> qn
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L7
         LA    3,112(,13)
@@L11    EQU   *
         IC    2,0(15,6) ==> len
         STC   2,0(3,15) ==> qname
         A     15,=F'1' ==> len
         LA    2,7(0,0)
         CR    15,2 ==> len
         BH    @@L7
         IC    2,0(15,6) ==> len
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L11
@@L7     EQU   *
         LA    3,7(0,0)
         CR    15,3 ==> len
         BH    @@L33
         LA    2,112(,13)
@@L15    EQU   *
         LA    3,64(0,0)
         STC   3,0(2,15) ==> qname
         A     15,=F'1' ==> len
         LA    3,7(0,0)
         CR    15,3 ==> len
         BNH   @@L15
@@L33    EQU   *
         LA    2,112(,13)
         ST    2,100(13) ==> .qname
         ST    7,104(13) ==> rn,rname
         LR    2,8 ==> options
         N     2,=F'3'
         LA    3,1(0,0)
         CLR   2,3
         BE    @@L18
         LA    3,2(0,0)
         CLR   2,3
         BNE   @@L16
         OI    98(13),72 ==> .opt
         B     @@L16
@@L18    EQU   *
         OI    98(13),64 ==> .opt
@@L16    EQU   *
         L     2,12(11) ==> deq
         LTR   2,2 ==> deq
         BE    @@L21
         MVI   98(13),1 ==> .opt
         DS    0H       Request DEQ
         LA    1,96(13) ==> pl
         SVC   48       DEQ
         B     @@L22
@@L21    EQU   *
         LR    2,8 ==> options
         N     2,=F'4'
         LTR   2,2
         BE    @@L23
         OI    98(13),128 ==> .opt
@@L23    EQU   *
         LR    2,8 ==> options
         N     2,=F'240'
         LA    3,64(0,0)
         CLR   2,3
         BE    @@L26
         BH    @@L30
         LA    3,32(0,0)
         CLR   2,3
         BE    @@L27
         B     @@L28
@@L30    EQU   *
         LA    3,128(0,0)
         CLR   2,3
         BNE   @@L28
         OI    98(13),7 ==> .opt
         B     @@L24
@@L26    EQU   *
         OI    98(13),3 ==> .opt
         B     @@L24
@@L27    EQU   *
         OI    98(13),2 ==> .opt
         B     @@L24
@@L28    EQU   *
         OI    98(13),1 ==> .opt
@@L24    EQU   *
         DS    0H       Request ENQ
         LA    1,96(13) ==> pl
         SVC   56       ENQ
@@L22    EQU   *
         SLR   2,2 ==> err
         IC    2,99(13) ==> err,rc
@@L4     EQU   *
         LR    15,2 ==> err
* Function '__enqdeq' epilogue
         PDPEPIL
* Function '__enqdeq' literal pool
         DS    0D
         LTORG
* Function '__enqdeq' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
