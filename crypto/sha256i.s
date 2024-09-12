 TITLE '/home/mike/repos/crent370/crypto/sha256i.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/crypto
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
* Program text area
         DS    0F
         EJECT
* external function 'sha256_init' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'sha256_init'
SHA256I  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'sha256_init' code
         L     2,0(11) ==> ctx
         MVC   8(4,2),=F'0' ==> .datalen
         ST    2,88(13) ==> ctx
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         MVC   12(4,2),=F'1779033703' ==> .state
         MVC   16(4,2),=F'-1150833019' ==> .state
         MVC   20(4,2),=F'1013904242' ==> .state
         MVC   24(4,2),=F'-1521486534' ==> .state
         MVC   28(4,2),=F'1359893119' ==> .state
         MVC   32(4,2),=F'-1694144372' ==> .state
         MVC   36(4,2),=F'528734635' ==> .state
         MVC   40(4,2),=F'1541459225' ==> .state
* Function 'sha256_init' epilogue
         PDPEPIL
* Function 'sha256_init' literal pool
         DS    0D
         LTORG
* Function 'sha256_init' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
