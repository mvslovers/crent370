 TITLE '/home/mike/repos/crent370/clib/@@dscbdv.c'
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
* external function '__dscbdv' prologue
* frame base=88, local stack=72, call args=16
&FUNC    SETC  '__dscbdv'
@@DSCBDV PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__dscbdv' code
         LA    3,104(,13)
         ST    3,88(13)
         MVC   92(4,13),=F'44'
         MVC   96(4,13),0(11) ==> dsn
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         MVI   148(13),0 ==> dataset
         LA    2,152(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'6'
         MVC   96(4,13),4(11) ==> vol
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         MVI   158(13),0 ==> volser
         MVC   160(4,13),=F'-1056964608' ==> .flags
         ST    3,164(13) ==> .p1
         ST    2,168(13) ==> .p2
         MVC   172(4,13),8(11) ==> .p3,dscb
         LA    2,160(,13)
         LR    1,2
         SVC   27
         LR    2,15 ==> rc
         LR    15,2 ==> rc
* Function '__dscbdv' epilogue
         PDPEPIL
* Function '__dscbdv' literal pool
         DS    0D
         LTORG
* Function '__dscbdv' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         LOCATE    INDAB  READ CATALOG ENTRY FOR DATA SET A.B
*                          INTO VIRTUAL STORAGE AREA NAMED LOCAREA.
*                          LOCAREA MAY ALSO CONTAIN A 3-BYTE
*                          TTR OR A 6-BYTE SERIAL NUMBER
INDAB     CAMLST    NAME,AB,,LOCAREA
AB        DC        CL44'A.B'
LOCAREA   DS        0D
          DS        265C

         END
