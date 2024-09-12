 TITLE '/home/mike/repos/crent370/dyn75/@@75.c'
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
         
&FUNC    SETC '@@75'
* Program text area
         DS    0F
         EJECT
* external function '__75' prologue
* frame base=88, local stack=48, call args=0
&FUNC    SETC  '__75'
@@75     PDPPRLG CINDEX=0,FRAME=136,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__75' code
         L     2,0(11) ==> pl
         LA    3,88(,13)
         LR    14,3            => save area for regs
         STM   0,11,0(14)      Save R0-R11 in stack save area
         LR    11,2             => PL75 ==> pl
         LM    0,9,0(11)        Load R0-R9 from parameter list
*
         LA    3,0              To Host PC
         SLR   0,0              Restart = No
         DC    X'75005000'      TCPIP 0,000(0,R5)
         LTR   15,15            Check for error
         BNZ   DYN75ERR
*
         LA    3,1              From Host PC
         SLR   0,0              Restart = No
         DC    X'75006000'      TCPIP 0,000(0,R6)
DYN75ERR DS    0H
         STM   0,15,0(11)       Save results in parameter list
         LM    0,11,0(14)       Restore registers
         LR    2,15 ==> rc
         LR    15,2 ==> rc
* Function '__75' epilogue
         PDPEPIL
* Function '__75' literal pool
         DS    0D
         LTORG
* Function '__75' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
