 TITLE '/home/mike/repos/crent370/clib/@@ssib.c'
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
* external function '__ssib' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  '__ssib'
@@SSIB   PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__ssib' code
         L     15,PSATOLD-PSA          OUR TCB ADDRESS
         L     15,TCBJSCB-TCB(,15)     JSCB ADDRESS
         USING IEZJSCB,15
         L     15,JSCBACT              ACTIVE JSCB ADDRESS
         L     15,JSCBSSIB             SSIB ADDRESS
         DROP  15
         ST    15,88(13)
         L     15,88(13)
* Function '__ssib' epilogue
         PDPEPIL
* Function '__ssib' literal pool
         DS    0D
         LTORG
* Function '__ssib' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         PRINT NOGEN
         IEZJSCB
         IKJTCB
         IHAPSA
         IEFJSSIB
         END
