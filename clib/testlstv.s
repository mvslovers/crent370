 TITLE '/home/mike/repos/crent370/clib/testlstv.c'
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
         COPY  PDPMAIN
         EJECT
* external function 'main' prologue
* frame base=88, local stack=64, call args=48
&FUNC    SETC  'main'
MAIN     PDPPRLG CINDEX=0,FRAME=200,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'main' code
         MVC   88(4,13),=F'0'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(@@LISTVL)
         BALR  14,15
         ST    15,192(13) ==> count
         LA    2,192(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    8,15 ==> count
         L     2,192(13)
         LTR   2,2
         BE    @@L2
         MVC   88(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
@@L2     EQU   *
         SLR   7,7 ==> n
         CLR   7,8 ==> n,count
         BNL   @@L22
@@L20    EQU   *
         LR    3,7 ==> n
         MH    3,=H'4'
         L     2,192(13)
         L     6,0(3,2) ==> v
         LA    4,136(,13)
         LA    5,16(0,0)
         SLR   2,2
         LR    3,2
         MVCL  4,2
         LA    4,152(,13)
         LA    5,40(0,0)
         SLR   2,2
         LR    3,2
         MVCL  4,2
         LTR   6,6 ==> v
         BE    @@L5
         IC    2,7(6) ==> .status
         N     2,=F'8'
         CLM   2,1,=XL1'00'
         BE    @@L8
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC3)
         B     @@L23
@@L8     EQU   *
         IC    2,7(6) ==> .status
         N     2,=F'4'
         CLM   2,1,=XL1'00'
         BE    @@L10
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         B     @@L23
@@L10    EQU   *
         IC    2,7(6) ==> .status
         N     2,=F'2'
         CLM   2,1,=XL1'00'
         BE    @@L9
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC5)
@@L23    EQU   *
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
@@L9     EQU   *
         IC    2,7(6) ==> .status
         N     2,=F'32'
         CLM   2,1,=XL1'00'
         BE    @@L13
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC6)
         B     @@L24
@@L13    EQU   *
         IC    2,7(6) ==> .status
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L15
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC7)
         B     @@L24
@@L15    EQU   *
         IC    2,7(6) ==> .status
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L14
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC8)
@@L24    EQU   *
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
@@L14    EQU   *
         L     2,36(6) ==> .comment
         LTR   2,2
         BE    @@L18
         LA    2,152(,13)
         ST    2,88(13)
         MVC   92(4,13),36(6) ==> .comment
         MVC   96(4,13),=F'39'
         LA    1,88(,13)
         L     15,=V(STRNCPY)
         BALR  14,15
         MVI   191(13),0 ==> comment
         B     @@L19
@@L18    EQU   *
         LA    2,152(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC9)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
@@L19    EQU   *
         MVC   88(4,13),=A(@@LC10)
         ST    6,92(13) ==> v
         MVC   96(4,13),16(6) ==> .freecyls
         MVC   100(4,13),20(6) ==> .freetrks
         MVC   104(4,13),24(6) ==> .freeexts
         MVC   108(4,13),28(6) ==> .maxfreecyls
         MVC   112(4,13),32(6) ==> .maxfreetrks
         LH    2,12(6) ==> .cuu
         N     2,=XL4'0000FFFF'
         ST    2,116(13)
         LH    2,14(6) ==> .dasdtype
         N     2,=XL4'0000FFFF'
         ST    2,120(13)
         MVC   124(4,13),8(6) ==> .ucbdasd
         LA    2,136(,13)
         ST    2,128(13)
         LA    2,152(,13)
         ST    2,132(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
@@L5     EQU   *
         A     7,=F'1' ==> n
         CLR   7,8 ==> n,count
         BL    @@L20
@@L22    EQU   *
         LA    2,192(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FREEVL)
         BALR  14,15
         SLR   15,15
* Function 'main' epilogue
         PDPEPIL
* Function 'main' literal pool
         DS    0D
         LTORG
* Function 'main' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'VATLST00'
         DC    X'0'
@@LC1    EQU   *
         DC    C'VOLSER  FREE  FREE   FREE   LARGEST CONTIG FREE '
         DC    C'AREA  UNIT  DEVICE   UCB   --STATUS--   ------CO'
         DC    C'MMENTS------'
         DC    X'15'
         DC    X'0'
@@LC2    EQU   *
         DC    C'        CYLS  TRKS  EXTENTS    CYLINDERS  TRACKS'
         DC    C'             TYPE'
         DC    X'15'
         DC    X'0'
@@LC3    EQU   *
         DC    C'PRIV '
         DC    X'0'
@@LC4    EQU   *
         DC    C'PUBL '
         DC    X'0'
@@LC5    EQU   *
         DC    C'STRG '
         DC    X'0'
@@LC6    EQU   *
         DC    C'RSDNT'
         DC    X'0'
@@LC7    EQU   *
         DC    C'RESRV'
         DC    X'0'
@@LC8    EQU   *
         DC    C'ONLIN'
         DC    X'0'
@@LC9    EQU   *
         DC    C'no comment'
         DC    X'0'
@@LC10   EQU   *
         DC    C'%.6s  %4u  %4u   %4u        %4u      %4u      %4'
         DC    C'X    %4X   %4X   %-12s %s'
         DC    X'15'
         DC    X'0'
         END   @@MAIN
