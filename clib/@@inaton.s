 TITLE '/home/mike/repos/crent370/clib/@@inaton.c'
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
* external function 'inet_aton' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'inet_aton'
@@INATON PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'inet_aton' code
         L     2,0(11) ==> cp
         L     3,4(11) ==> inp
         L     4,=F'-1' ==> rc
         LTR   2,2 ==> cp
         BE    @@L3
         LTR   3,3 ==> inp
         BE    @@L3
         ST    2,88(13) ==> cp
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(STRTOUL)
         BALR  14,15
         L     2,104(13)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L19
         LR    2,15 ==> x
         SLL   2,24
         ST    2,0(3) ==> .s_addr
         L     2,104(13)
         CLI   0(2),75
         BNE   @@L7
         A     2,=F'1'
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(STRTOUL)
         BALR  14,15
         L     2,=F'16777215'
         CLR   15,2 ==> x
         BH    @@L3
         L     2,104(13)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L20
         LR    2,15 ==> x
         SLL   2,16
         O     2,0(3) ==> .s_addr
         ST    2,0(3) ==> .s_addr
@@L7     EQU   *
         L     2,104(13)
         CLI   0(2),75
         BNE   @@L11
         A     2,=F'1'
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(STRTOUL)
         BALR  14,15
         L     2,=F'65535'
         CLR   15,2 ==> x
         BH    @@L3
         L     2,104(13)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L20
         LR    2,15 ==> x
         SLL   2,8
         O     2,0(3) ==> .s_addr
         ST    2,0(3) ==> .s_addr
@@L11    EQU   *
         L     2,104(13)
         CLI   0(2),75
         BNE   @@L15
         A     2,=F'1'
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(STRTOUL)
         BALR  14,15
         LA    2,255(0,0)
         CLR   15,2 ==> x
         BH    @@L3
@@L20    EQU   *
         O     15,0(3) ==> x,s_addr
@@L19    EQU   *
         ST    15,0(3) ==> x,s_addr
@@L15    EQU   *
         SLR   4,4 ==> rc
@@L3     EQU   *
         LR    15,4 ==> rc
* Function 'inet_aton' epilogue
         PDPEPIL
* Function 'inet_aton' literal pool
         DS    0D
         LTORG
* Function 'inet_aton' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
