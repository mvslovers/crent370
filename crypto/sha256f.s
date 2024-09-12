 TITLE '/home/mike/repos/crent370/crypto/sha256f.c'
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
* external function 'sha256_final' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'sha256_final'
SHA256F  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'sha256_final' code
         L     3,0(11) ==> ctx
         L     15,8(3) ==> i,datalen
         LA    2,55(0,0)
         CLR   15,2 ==> i
         BH    @@L2
         L     5,=F'-128'
         STC   5,44(3,15) ==> .data
         A     15,=F'1' ==> i
         CLR   15,2 ==> i
         BH    @@L7
         LA    4,40(0,0)
@@L6     EQU   *
         LR    2,15 ==> i
         AR    2,3 ==> ctx
         SLR   5,5
         STC   5,4(4,2) ==> .data
         A     15,=F'1' ==> i
         LA    2,55(0,0)
         CLR   15,2 ==> i
         BH    @@L7
         B     @@L6
@@L2     EQU   *
         L     5,=F'-128'
         STC   5,44(3,15) ==> .data
         A     15,=F'1' ==> i
         LA    2,63(0,0)
         CLR   15,2 ==> i
         BH    @@L14
         LA    4,40(0,0)
@@L11    EQU   *
         LR    2,15 ==> i
         AR    2,3 ==> ctx
         SLR   5,5
         STC   5,4(4,2) ==> .data
         A     15,=F'1' ==> i
         LA    2,63(0,0)
         CLR   15,2 ==> i
         BNH   @@L11
@@L14    EQU   *
         ST    3,88(13) ==> ctx
         LR    2,3 ==> ctx
         A     2,=F'44'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(SHA256T)
         BALR  14,15
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'56'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
@@L7     EQU   *
         ST    3,88(13) ==> ctx
         L     2,8(3) ==> .datalen
         SLL   2,3
         ST    2,92(13)
         ST    3,96(13) ==> ctx
         LA    1,88(,13)
         L     15,=V(@@64AU32)
         BALR  14,15
         LR    2,3 ==> ctx
         A     2,=F'100'
         ST    2,88(13)
         ST    3,92(13) ==> ctx
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         ST    3,88(13) ==> ctx
         A     2,=F'-56'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(SHA256T)
         BALR  14,15
         MVC   88(4,13),4(11) ==> hash
         A     2,=F'-32'
         ST    2,92(13)
         MVC   96(4,13),=F'32'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
* Function 'sha256_final' epilogue
         PDPEPIL
* Function 'sha256_final' literal pool
         DS    0D
         LTORG
* Function 'sha256_final' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
