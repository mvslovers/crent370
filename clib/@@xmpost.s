 TITLE '/home/mike/repos/crent370/clib/@@xmpost.c'
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
@@6      EQU   *
         DC    C'__xmpost'
         DC    X'0'
         DS    0F
         EJECT
* external function '__xmpost' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__xmpost'
@@XMPOST PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__xmpost' code
         L     3,0(11) ==> ascb
         L     2,4(11) ==> ecb
         L     15,8(11) ==> postcode
         LTR   3,3 ==> ascb
         BNE   @@L2
         MVC   88(4,13),=A(@@LC0)
         B     @@L4
@@L2     EQU   *
         LTR   2,2 ==> ecb
         BNE   @@L3
         MVC   88(4,13),=A(@@LC1)
@@L4     EQU   *
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L1
@@L3     EQU   *
         O     2,=F'-2147483648' ==> ecb
         O     15,=F'1073741824' ==> postcode
         N     15,=F'2147483647' ==> postcode
         DS    0H
         STM   14,12,12(13)    save registers
         LR    9,13            only register preserved after XM POST
         LR    10,15           POST COMPLETION CODE ==> postcode
         LR    11,2           ECB ADDRESS ==> ecb
         LA    12,POSTERR      ERROR ROUTINE
         LR    13,3           ASCB ADDRESS ==> ascb
         L     15,CVTPTR       CVT ADDRESS
         L     15,CVT0PT01-CVTMAP(,15)   POST BRANCH-ENTRY
         BALR  14,15
         LR    13,9            restore save area pointer
         LM    14,12,12(13)    restore registers
         B     DONE
POSTERR  DS    0H
         BR    14
DONE     DS    0H
@@L1     EQU   *
* Function '__xmpost' epilogue
         PDPEPIL
* Function '__xmpost' literal pool
         DS    0D
         LTORG
* Function '__xmpost' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s missing ASCB'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%s missing ECB'
         DC    X'0'
         IHAPSA ,
         CVT DSECT=YES,LIST=YES
         END
