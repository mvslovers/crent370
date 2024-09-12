 TITLE '/home/mike/repos/crent370/clib/@@loadhi.c'
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
         
&FUNC    SETC '__loadhi'
* Program text area
@@6      EQU   *
         DC    C'__loadhi'
         DC    X'0'
         DS    0F
         EJECT
* external function '__loadhi' prologue
* frame base=88, local stack=80, call args=16
&FUNC    SETC  '__loadhi'
@@LOADHI PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__loadhi' code
         L     7,0(11) ==> module
         SLR   6,6 ==> highlp
         ST    6,176(13) ==> highlp,highep
         ST    6,180(13) ==> highlp,size
         L     2,=A(@@LC0)
         MVC   104(9,13),0(2) ==> member
         LA    4,113(,13)
         LA    5,3(0,0)
         LR    2,6 ==> highlp
         LR    3,6 ==> highlp
         MVCL  4,2 ==> highlp
         LA    4,120(,13)
         LA    5,56(0,0)
         LR    2,6 ==> highlp
         LR    3,6 ==> highlp
         MVCL  4,2 ==> highlp
         LR    3,6 ==> i,highlp
         IC    2,0(7) ==> module
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L3
         L     2,=V(@@TOUP)
         L     4,0(2) ==> __toup
@@L7     EQU   *
         SLR   2,2
         IC    2,0(3,7) ==> i
         MH    2,=H'2'
         IC    2,1(2,4)
         STC   2,104(13,3) ==> member
         A     3,=F'1' ==> i
         LA    2,7(0,0)
         CR    3,2 ==> i
         BH    @@L3
         IC    2,0(3,7) ==> i
         CLM   2,1,=XL1'00'
         BNE   @@L7
@@L3     EQU   *
         LA    1,88(,13)
         L     15,=V(@@STEPLB)
         BALR  14,15
         ST    15,88(13) ==> dcb
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'0'
         MVC   100(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LOAD)
         BALR  14,15
         LR    5,15 ==> lowep
         LTR   15,15 ==> lowep
         BNE   @@L8
         MVC   88(4,13),=A(@@LC1)
         B     @@L23
@@L8     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FNDCDE)
         BALR  14,15
         LTR   15,15 ==> cde
         BNE   @@L10
         MVC   88(4,13),=A(@@LC2)
@@L23    EQU   *
         MVC   92(4,13),=A(@@6)
         ST    2,96(13)
         B     @@L22
@@L10    EQU   *
         L     2,20(15) ==> .xtlst
         L     3,8(2) ==> .xtlmsbla
         N     3,=F'16777215'
         ST    3,180(13) ==> size
         L     3,12(2) ==> lowlp,xtlmsbaa
         LR    9,5 ==> offep,lowep
         SR    9,3 ==> offep,lowlp
         MVC   88(4,13),180(13) ==> size
         MVC   92(4,13),=F'241'
         LA    1,88(,13)
         L     15,=V(GETMAIN)
         BALR  14,15
         LR    6,15 ==> highlp
         LTR   15,15 ==> highlp
         BNE   @@L11
         MVC   88(4,13),=A(@@LC3)
         MVC   92(4,13),=A(@@6)
         MVC   96(4,13),180(13) ==> size
         B     @@L22
@@L11    EQU   *
         ST    15,88(13) ==> highlp
         ST    3,92(13) ==> lowlp
         MVC   96(4,13),180(13) ==> size
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LA    4,120(,13)
         ST    4,88(13)
         MVC   92(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    4,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         ST    4,88(13)
         MVC   92(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         ST    4,88(13)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    8,15 ==> fp
         LTR   15,15 ==> fp
         BNE   @@L12
         MVC   88(4,13),=A(@@LC7)
         MVC   92(4,13),=A(@@6)
         ST    4,96(13)
@@L22    EQU   *
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L9
@@L12    EQU   *
         ST    15,88(13) ==> fp
         ST    3,92(13) ==> lowlp
         ST    6,96(13) ==> highlp
         LA    1,88(,13)
         L     15,=A(@@7)
         BALR  14,15
         AR    9,6 ==> offep,highlp
         ST    9,176(13) ==> offep,highep
@@L9     EQU   *
         LTR   8,8 ==> fp
         BE    @@L13
         ST    8,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
@@L13    EQU   *
         LTR   5,5 ==> lowep
         BE    @@L14
         ST    7,88(13) ==> module
         LA    1,88(,13)
         L     15,=V(@@DELETE)
         BALR  14,15
@@L14    EQU   *
         L     2,176(13) ==> highep
         LTR   2,2
         BE    @@L15
         L     3,4(11) ==> lpa
         LTR   3,3
         BE    @@L16
         ST    6,0(3) ==> highlp
@@L16    EQU   *
         L     2,8(11) ==> epa
         LTR   2,2
         BE    @@L17
         MVC   0(4,2),176(13) ==> highep
@@L17    EQU   *
         L     3,12(11) ==> sz
         LTR   3,3
         BE    @@L18
         MVC   0(4,3),180(13) ==> size
@@L18    EQU   *
         SLR   15,15 ==> dcb
         B     @@L1
@@L15    EQU   *
         LTR   6,6 ==> highlp
         BE    @@L20
         ST    6,88(13) ==> highlp
         LA    1,88(,13)
         L     15,=V(FREEMAIN)
         BALR  14,15
@@L20    EQU   *
         LA    15,4(0,0) ==> dcb
@@L1     EQU   *
* Function '__loadhi' epilogue
         PDPEPIL
* Function '__loadhi' literal pool
         DS    0D
         LTORG
* Function '__loadhi' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'        '
         DC    X'0'
         DC    3X'00'
@@LC1    EQU   *
         DC    C'%s unable to LOAD "%s" into private storage'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s CDE not found for "%s"'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%s unable to allocate storage for %u bytes from '
         DC    C'subpool 241'
         DC    X'0'
@@LC4    EQU   *
         DC    C'DD:STEPLIB('
         DC    X'0'
@@LC5    EQU   *
         DC    C')'
         DC    X'0'
@@LC6    EQU   *
         DC    C'rb'
         DC    X'0'
@@LC7    EQU   *
         DC    C'%s unable to open "%s" for reading'
         DC    X'0'
         
&FUNC    SETC 'relocate_load'
         DS    0F
         EJECT
* static function 'relocate_load' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'relocate_load'
@@7      PDPPRLG CINDEX=1,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'relocate_load' code
         L     3,0(11) ==> fp
         L     7,4(11) ==> lowlp
         L     6,8(11) ==> highlp
         SLR   5,5 ==> rc
         ST    5,108(13) ==> rc
         ST    5,104(13) ==> rc
         LR    4,5 ==> loadtext,rc
@@L25    EQU   *
         MVC   88(4,13),8(3) ==> .dcb
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,108(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@AREAD)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L32
         LTR   4,4 ==> loadtext
         BE    @@L29
         LR    4,15 ==> loadtext,rc
         B     @@L25
@@L29    EQU   *
         L     15,104(13) ==> mmod
         IC    2,0(15) ==> .id
         N     2,=F'1'
         CLM   2,1,=XL1'00'
         BE    @@L30
         LA    4,1(0,0) ==> loadtext
@@L30    EQU   *
         IC    2,0(15) ==> .id
         N     2,=F'2'
         CLM   2,1,=XL1'00'
         BE    @@L25
         MVC   88(4,13),104(13)
         ST    7,92(13) ==> lowlp
         ST    6,96(13) ==> highlp
         LA    1,88(,13)
         L     15,=A(@@8)
         BALR  14,15
         B     @@L25
@@L32    EQU   *
         OC    40(2,3),=H'1' ==> .flags
         LR    15,5 ==> rc
* Function 'relocate_load' epilogue
         PDPEPIL
* Function 'relocate_load' literal pool
         DS    0D
         LTORG
* Function 'relocate_load' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'process_rldr'
         DS    0F
         EJECT
* static function 'process_rldr' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'process_rldr'
@@8      PDPPRLG CINDEX=2,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'process_rldr' code
         SLR   8,8 ==> count
         L     9,0(11) ==> rldr,buf
         LR    4,9 ==> rldf,rldr
         A     4,=F'20' ==> rldf
         LH    2,6(9) ==> .rldcnt
         N     2,=XL4'0000FFFF'
         CLR   8,2 ==> count
         BNL   @@L57
@@L54    EQU   *
         IC    2,0(4) ==> .flag
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BNE   @@L38
         SLR   2,2
         IC    2,1(4)
         SLL   2,16
         SLR   3,3
         IC    3,2(4)
         SLL   3,8
         OR    2,3
         SLR   3,3
         IC    3,3(4)
         OR    2,3
         ST    2,108(13) ==> offset
         IC    5,0(4) ==> .flag
         N     5,=F'12' ==> size
         LA    2,4(0,0)
         CLR   5,2 ==> size
         BNE   @@L39
         LA    5,2(0,0) ==> size
         B     @@L40
@@L39    EQU   *
         LA    3,8(0,0)
         CLR   5,3 ==> size
         BNE   @@L41
         LA    5,3(0,0) ==> size
         B     @@L40
@@L41    EQU   *
         LA    2,12(0,0)
         CLR   5,2 ==> size
         BNE   @@L38
         LA    5,4(0,0) ==> size
@@L40    EQU   *
         L     7,4(11) ==> address,lowlp
         A     7,108(13) ==> address,offset
         LR    6,5 ==> size
         SLR   3,3 ==> value
         LR    15,3 ==> n,value
         CLR   3,5 ==> value,size
         BNL   @@L59
@@L49    EQU   *
         SLL   3,8 ==> value
         SLR   2,2
         IC    2,0(15,7) ==> n
         OR    3,2 ==> value
         A     15,=F'1' ==> n
         CLR   15,6 ==> n,size
         BL    @@L49
@@L59    EQU   *
         LR    2,3 ==> value
         S     2,4(11) ==> value,lowlp
         A     2,8(11) ==> value,highlp
         L     3,8(11) ==> address,highlp
         A     3,108(13) ==> address,offset
         ST    2,104(13) ==> value
         LR    2,13 ==> val
         SR    2,5 ==> val,size
         A     2,=F'108' ==> val
         ST    3,88(13) ==> address
         ST    2,92(13) ==> val
         ST    5,96(13) ==> size
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L38    EQU   *
         IC    2,0(4) ==> .flag
         N     2,=F'1'
         CLM   2,1,=XL1'00'
         BE    @@L52
         A     8,=F'4' ==> count
         A     4,=F'4' ==> rldf
         B     @@L34
@@L52    EQU   *
         A     8,=F'8' ==> count
         A     4,=F'8' ==> rldf
@@L34    EQU   *
         LH    2,6(9) ==> .rldcnt
         N     2,=XL4'0000FFFF'
         CLR   8,2 ==> count
         BL    @@L54
@@L57    EQU   *
@@L55    EQU   *
         SLR   15,15
* Function 'process_rldr' epilogue
         PDPEPIL
* Function 'process_rldr' literal pool
         DS    0D
         LTORG
* Function 'process_rldr' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
         END
