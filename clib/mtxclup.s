 TITLE '/home/mike/repos/crent370/clib/mtxclup.c'
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
         
&FUNC    SETC 'cleanup_mutex'
* Program text area
         DS    0F
         EJECT
* static function 'cleanup_mutex' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'cleanup_mutex'
@@0      PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cleanup_mutex' code
         L     2,0(11) ==> mutex
         ST    2,88(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(MTXHELD)
         BALR  14,15
         LTR   15,15
         BE    @@L1
         MVC   0(4,2),=F'0' ==> .owner
         MVC   4(4,2),=F'0' ==> .count
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=F'0'
         ST    2,96(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(@@LKRNUF)
         BALR  14,15
@@L1     EQU   *
* Function 'cleanup_mutex' epilogue
         PDPEPIL
* Function 'cleanup_mutex' literal pool
         DS    0D
         LTORG
* Function 'cleanup_mutex' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'MUTEX.%08X'
         DC    X'0'
         DS    0F
         EJECT
* external function 'mtxclup' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'mtxclup'
MTXCLUP  PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'mtxclup' code
         L     15,0(11) ==> mutex
         LTR   15,15 ==> mutex
         BE    @@L3
         MVC   88(4,13),=A(@@0)
         ST    15,92(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
@@L3     EQU   *
* Function 'mtxclup' epilogue
         PDPEPIL
* Function 'mtxclup' literal pool
         DS    0D
         LTORG
* Function 'mtxclup' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
