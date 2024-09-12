 TITLE '/home/mike/repos/crent370/dyn75/@@75send.c'
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
         
&FUNC    SETC 'send'
* Program text area
         DS    0F
         EJECT
* external function 'send' prologue
* frame base=88, local stack=64, call args=8
&FUNC    SETC  'send'
@@75SEND PDPPRLG CINDEX=0,FRAME=160,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'send' code
         LA    2,96(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         MVC   100(4,13),8(11) ==> .r1,len
         MVC   116(4,13),4(11) ==> .r5,buf
         MVC   124(4,13),=F'10' ==> .r7
         MVC   128(4,13),0(11) ==> .r8,ss
         LA    3,96(,13)
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     2,112(13) ==> rc,r4
         L     4,=F'-1'
         CLR   2,4 ==> rc
         BNE   @@L3
         MVC   100(4,13),=F'0' ==> .r1
         MVC   124(4,13),=F'2' ==> .r7
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),112(13) ==> rc,r4
@@L3     EQU   *
         LR    15,2 ==> rc
* Function 'send' epilogue
         PDPEPIL
* Function 'send' literal pool
         DS    0D
         LTORG
* Function 'send' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
