 TITLE '/home/mike/repos/crent370/clib/@@fdclr.c'
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
* external function '__fdclr' prologue
* frame base=88, local stack=1104, call args=16
&FUNC    SETC  '__fdclr'
@@FDCLR  PDPPRLG CINDEX=0,FRAME=1208,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fdclr' code
         L     3,0(11) ==> ddname
         LA    4,144(,13)
         ST    4,88(13)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'20'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
         MVI   144(13),20 ==> .len
         MVI   145(13),2 ==> .verb
         LA    2,104(,13)
         ST    2,152(13) ==> .tu_list
         LA    2,168(,13)
         ST    2,104(13) ==> tu_list
         MVC   168(2,13),=H'1' ==> .key
         MVC   170(2,13),=H'1' ==> .numparms
         ST    3,88(13) ==> ddname
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         STH   15,172(13) ==> err,parm1_len
         LA    2,174(,13)
         ST    2,88(13)
         ST    3,92(13) ==> ddname
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         MVC   108(4,13),=F'-2147483648' ==> tu_list
         ST    4,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
* Function '__fdclr' epilogue
         PDPEPIL
* Function '__fdclr' literal pool
         DS    0D
         LTORG
* Function '__fdclr' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
