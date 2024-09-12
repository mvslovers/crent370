 TITLE '/home/mike/repos/crent370/clib/@@cpclos.c'
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
* external function '__cpclos' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  '__cpclos'
@@CPCLOS PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__cpclos' code
         L     3,0(11) ==> cp
         LTR   3,3 ==> cp
         BE    @@L2
         L     15,16(3) ==> dcb,dcb
         MVC   96(4,13),=F'-2147483648'
         IC    2,48(15) ==> .dcboflgs
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BE    @@L3
         LA    2,96(,13)
         CLOSE ((15)),MF=(E,(2)) ==> dcb
@@L3     EQU   *
         ST    3,88(13) ==> cp
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         L     2,236(3) ==> .buf
         LTR   2,2
         BE    @@L4
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L4     EQU   *
         ST    3,88(13) ==> cp
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L2     EQU   *
         SLR   15,15
* Function '__cpclos' epilogue
         PDPEPIL
* Function '__cpclos' literal pool
         DS    0D
         LTORG
* Function '__cpclos' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'deallocate_checkpoint'
         DS    0F
         EJECT
* static function 'deallocate_checkpoint' prologue
* frame base=88, local stack=32, call args=8
&FUNC    SETC  'deallocate_checkpoint'
@@6      PDPPRLG CINDEX=1,FRAME=128,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'deallocate_checkpoint' code
         SLR   15,15 ==> count
         ST    15,120(13) ==> count
         LA    4,96(,13)
         LA    5,20(0,0)
         LR    2,15 ==> count
         LR    3,15 ==> count
         MVCL  4,2 ==> count
         LA    2,120(,13)
         ST    2,88(13)
         L     2,0(11) ==> fp
         A     2,=F'8'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@TXDDN)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L7
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L7
         BCTR  15,0 ==> count
         L     4,120(13)
         LR    3,15 ==> count
         MH    3,=H'4'
         L     2,0(3,4)
         O     2,=F'-2147483648'
         ST    2,0(3,4)
         MVI   96(13),20 ==> .len
         MVI   97(13),2 ==> .request
         MVI   98(13),64 ==> .flag1
         MVC   104(4,13),120(13) ==> .txtptr
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
         LR    3,15 ==> err
@@L7     EQU   *
         L     2,120(13)
         LTR   2,2
         BE    @@L9
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FRTX9A)
         BALR  14,15
@@L9     EQU   *
         LR    15,3 ==> err
* Function 'deallocate_checkpoint' epilogue
         PDPEPIL
* Function 'deallocate_checkpoint' literal pool
         DS    0D
         LTORG
* Function 'deallocate_checkpoint' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
