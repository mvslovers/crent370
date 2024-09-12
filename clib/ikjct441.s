 TITLE '/home/mike/repos/crent370/clib/ikjct441.c'
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
* external function 'ikjct441' prologue
* frame base=88, local stack=56, call args=40
&FUNC    SETC  'ikjct441'
IKJCT441 PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ikjct441' code
         MVC   168(4,13),=F'0'
         L     2,4(11)
         LTR   2,2
         BE    @@L2
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         SLR   15,15
@@L3     EQU   *
         ST    15,172(13)
         MVC   176(4,13),=F'0'
         MVC   180(4,13),=F'-1'
         SLR   3,3 ==> psa
         L     2,16(3) ==> cvt
         L     2,156(2) ==> tvt
         L     4,40(2) ==> ep
         ST    11,128(13) ==> .ecode
         LA    2,168(,13)
         ST    2,156(13) ==> .retcode
         LA    2,4(,11)
         ST    2,132(13) ==> .name
         LA    2,172(,13)
         ST    2,136(13) ==> .namelen
         LA    2,8(,11)
         ST    2,140(13) ==> .value
         LA    2,12(,11)
         ST    2,144(13) ==> .vallen
         LA    2,176(,13)
         ST    2,148(13) ==> .token
         LA    2,180(,13)
         ST    2,152(13) ==> .ect
         ST    3,160(13) ==> psa,next
         ST    11,88(13)
         LA    2,4(,11)
         ST    2,92(13)
         LA    2,172(,13)
         ST    2,96(13)
         LA    2,8(,11)
         ST    2,100(13)
         LA    2,12(,11)
         ST    2,104(13)
         LA    2,176(,13)
         ST    2,108(13)
         LA    2,180(,13)
         ST    2,112(13)
         LA    2,168(,13)
         ST    2,116(13)
         ST    3,120(13) ==> psa
         LA    1,88(,13)
         LA    15,0(4) ==> ep
         BALR  14,15
         L     15,168(13)
* Function 'ikjct441' epilogue
         PDPEPIL
* Function 'ikjct441' literal pool
         DS    0D
         LTORG
* Function 'ikjct441' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
