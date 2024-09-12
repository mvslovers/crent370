 TITLE '/home/mike/repos/crent370/crypto/sha256u.c'
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
* external function 'sha256_update' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'sha256_update'
SHA256U  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'sha256_update' code
         L     3,0(11) ==> ctx
         L     6,4(11) ==> data
         L     5,8(11) ==> len
         SLR   4,4 ==> i
         CLR   4,5 ==> i,len
         BNL   @@L9
@@L7     EQU   *
         L     2,8(3) ==> .datalen
         IC    7,0(4,6) ==> i
         STC   7,44(3,2) ==> .data
         A     2,=F'1'
         ST    2,8(3) ==> .datalen
         LA    7,64(0,0)
         CLR   2,7
         BNE   @@L4
         ST    3,88(13) ==> ctx
         LR    2,3 ==> ctx
         A     2,=F'44'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(SHA256T)
         BALR  14,15
         ST    3,88(13) ==> ctx
         MVC   92(4,13),=F'512'
         ST    3,96(13) ==> ctx
         LA    1,88(,13)
         L     15,=V(@@64AU32)
         BALR  14,15
         MVC   8(4,3),=F'0' ==> .datalen
@@L4     EQU   *
         A     4,=F'1' ==> i
         CLR   4,5 ==> i,len
         BL    @@L7
@@L9     EQU   *
* Function 'sha256_update' epilogue
         PDPEPIL
* Function 'sha256_update' literal pool
         DS    0D
         LTORG
* Function 'sha256_update' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
