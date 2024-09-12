 TITLE '/home/mike/repos/crent370/clib/@@listds.c'
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
* external function '__listds' prologue
* frame base=88, local stack=472, call args=16
&FUNC    SETC  '__listds'
@@LISTDS PDPPRLG CINDEX=0,FRAME=576,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__listds' code
         L     3,0(11) ==> level
         L     4,4(11) ==> option
         SLR   2,2 ==> rc
         LA    8,104(,13)
         LA    9,472(0,0)
         LR    6,2 ==> rc
         LR    7,2 ==> rc
         MVCL  8,6 ==> rc
         ST    3,104(13) ==> level,level
         ST    4,108(13) ==> option,option
         MVC   112(4,13),8(11) ==> .filter,filter
         ST    3,88(13) ==> level
         ST    4,92(13) ==> option
         MVC   96(4,13),=A(@@2)
         LA    2,104(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@LISTC)
         BALR  14,15
         L     15,116(13) ==> .array
* Function '__listds' epilogue
         PDPEPIL
* Function '__listds' literal pool
         DS    0D
         LTORG
* Function '__listds' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         DS    0F
         EJECT
* static function 'parse' prologue
* frame base=88, local stack=336, call args=16
&FUNC    SETC  'parse'
@@2      PDPPRLG CINDEX=1,FRAME=440,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'parse' code
         L     7,0(11) ==> udata,vdata
         LR    6,7 ==> buf,udata
         A     6,=F'68' ==> buf
         LR    9,7 ==> dscb1,udata
         A     9,=F'324' ==> dscb1
         ST    9,416(13) ==> dscb1,dscb
         SLR   8,8 ==> dslist
         LA    4,104(,13)
         LA    5,36(0,0)
         LR    2,8 ==> dslist
         LR    3,8 ==> dslist
         MVCL  4,2 ==> dslist
         ST    6,88(13) ==> buf
         MVC   92(4,13),4(11)
         LA    2,8(,11) ==> arg
         ST    2,96(13) ==> arg
         LA    1,88(,13)
         L     15,=V(VSPRINTF)
         BALR  14,15
         CLI   0(6),241 ==> buf
         L     14,=A(@@L4)
         BER   14
         ST    6,88(13) ==> buf
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    4,15 ==> p
         LTR   15,15 ==> p
         L     14,=A(@@L4)
         BER   14
         SLR   2,2
         IC    2,0(15) ==> p
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L6
         A     4,=F'1' ==> p
         IC    2,0(4) ==> p
         CLM   2,1,=XL1'00'
         BNE   @@L6
         ST    8,88(13) ==> dslist
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    4,15 ==> p
@@L6     EQU   *
         IC    2,16(7) ==> .dsn
         CLM   2,1,=XL1'00'
         BNE   @@L9
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRICMP)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L11
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(STRICMP)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L11
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC3)
         LA    1,88(,13)
         L     15,=V(STRICMP)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L11
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(STRICMP)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L9
@@L11    EQU   *
         MVC   88(4,13),=F'0'
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    4,15 ==> p
         LTR   15,15 ==> p
         L     14,=A(@@L4)
         BER   14
         SLR   2,2
         IC    2,0(15) ==> p
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         L     14,=A(@@L4)
         BNER  14
         L     2,8(7) ==> .filter
         LTR   2,2
         BE    @@L14
         ST    15,88(13) ==> p
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@PATMAT)
         BALR  14,15
         LTR   15,15 ==> p
         L     14,=A(@@L4)
         BER   14
@@L14    EQU   *
         LR    2,7 ==> udata
         A     2,=F'16'
         ST    2,88(13)
         ST    4,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         MVI   61(7),0 ==> .volser
         L     14,=A(@@L4)
         BR    14
@@L9     EQU   *
         IC    2,16(7) ==> .dsn
         CLM   2,1,=XL1'00'
         L     14,=A(@@L4)
         BER   14
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(STRICMP)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L17
         ST    15,88(13) ==> p
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L18
         STC   15,16(7) ==> p,dsn
         L     14,=A(@@L4)
         BR    14
@@L18    EQU   *
         LR    2,7 ==> udata
         A     2,=F'61'
         ST    2,88(13)
         ST    15,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
@@L17    EQU   *
         IC    2,61(7) ==> .volser
         CLM   2,1,=XL1'00'
         BE    @@L4
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'80'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    8,15 ==> dslist
         LTR   15,15 ==> dslist
         BNE   @@L20
         STC   15,16(7) ==> dslist,dsn
         STC   15,61(7) ==> dslist,volser
         B     @@L4
@@L20    EQU   *
         ST    15,88(13) ==> dslist
         LR    2,7 ==> udata
         A     2,=F'16'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         MVI   0(2),0 ==> .dsn
         LR    6,8 ==> dslist
         A     6,=F'45'
         ST    6,88(13)
         A     2,=F'45'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         MVI   0(2),0 ==> .volser
         ST    6,88(13)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L21
         LA    2,144(,13)
         ST    2,424(13)
         MVC   428(4,13),=F'268'
         ST    15,432(13) ==> p
         ST    15,436(13) ==> p
         L     4,424(13)
         L     5,4+424(13)
         L     2,432(13)
         L     3,4+432(13)
         MVCL  4,2
         ST    8,88(13) ==> dslist
         LA    3,144(,13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(@@LOCATE)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L21
         ST    6,88(13)
         LA    2,150(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'7'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L21    EQU   *
         ST    8,88(13) ==> dslist
         LR    2,8 ==> dslist
         A     2,=F'45'
         ST    2,92(13)
         MVC   96(4,13),416(13) ==> dscb
         LA    1,88(,13)
         L     15,=V(@@DSCBDV)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L24
         LR    4,15 ==> p,rc
         IC    2,38(9) ==> .dsorg1
         N     2,=F'127'
         LA    5,32(0,0)
         CR    2,5
         BE    @@L28
         BH    @@L32
         LA    3,2(0,0)
         CLR   2,3
         BE    @@L29
         B     @@L25
@@L32    EQU   *
         LA    5,64(0,0)
         CLR   2,5
         BE    @@L27
         LA    3,128(0,0)
         CLR   2,3
         BNE   @@L25
         L     4,=A(@@LC7) ==> p
         B     @@L25
@@L27    EQU   *
         L     4,=A(@@LC8) ==> p
         B     @@L25
@@L28    EQU   *
         L     4,=A(@@LC9) ==> p
         B     @@L25
@@L29    EQU   *
         L     4,=A(@@LC10) ==> p
@@L25    EQU   *
         CLI   39(9),8 ==> .dsorg2
         BNE   @@L33
         L     4,=A(@@LC11) ==> p
@@L33    EQU   *
         LTR   4,4 ==> p
         BE    @@L34
         LR    2,8 ==> dslist
         A     2,=F'52'
         ST    2,88(13)
         ST    4,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
@@L34    EQU   *
         SLR   4,4 ==> p
         IC    2,40(9) ==> .recfm
         N     2,=F'192'
         LA    5,128(0,0)
         CR    2,5
         BE    @@L36
         BH    @@L41
         LA    3,64(0,0)
         CLR   2,3
         BE    @@L37
         B     @@L35
@@L41    EQU   *
         LA    5,192(0,0)
         CLR   2,5
         BE    @@L38
         B     @@L35
@@L36    EQU   *
         L     4,=A(@@LC12) ==> p
         B     @@L35
@@L37    EQU   *
         L     4,=A(@@LC13) ==> p
         B     @@L35
@@L38    EQU   *
         L     4,=A(@@LC14) ==> p
@@L35    EQU   *
         LTR   4,4 ==> p
         BE    @@L42
         LR    2,8 ==> dslist
         A     2,=F'57'
         ST    2,88(13)
         ST    4,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
@@L42    EQU   *
         IC    2,40(9) ==> .recfm
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BE    @@L43
         LR    2,8 ==> dslist
         A     2,=F'57'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC15)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
@@L43    EQU   *
         IC    2,40(9) ==> .recfm
         N     2,=F'8'
         CLM   2,1,=XL1'00'
         BE    @@L44
         LR    2,8 ==> dslist
         A     2,=F'57'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC16)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
@@L44    EQU   *
         IC    2,40(9) ==> .recfm
         N     2,=F'4'
         CLM   2,1,=XL1'00'
         BE    @@L45
         LR    2,8 ==> dslist
         A     2,=F'57'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC17)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
@@L45    EQU   *
         IC    2,40(9) ==> .recfm
         N     2,=F'2'
         CLM   2,1,=XL1'00'
         BE    @@L46
         LR    2,8 ==> dslist
         A     2,=F'57'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC18)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
@@L46    EQU   *
         SLR   2,2
         IC    2,15(9) ==> .noepv
         STH   2,62(8) ==> .extents
         MVC   64(2,8),44(9) ==> .lrecl
         MVC   66(2,8),42(9) ==> .blksize,blksz
         SLR   2,2
         IC    2,9(9) ==> .credt
         AH    2,=H'1900'
         STH   2,68(8) ==> .cryear
         CLM   2,3,=H'1979'
         BH    @@L47
         AH    2,=H'100'
         STH   2,68(8) ==> .cryear
@@L47    EQU   *
         MVC   70(2,8),10(9) ==> .crjday
         LH    2,68(8) ==> .cryear
         N     2,=XL4'0000FFFF'
         A     2,=F'-1900'
         ST    2,124(13) ==> .tm_year
         LH    2,70(8) ==> .crjday
         N     2,=XL4'0000FFFF'
         ST    2,116(13) ==> .tm_mday
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(MKTIME)
         BALR  14,15
         IC    3,123(13) ==> .tm_mon
         LA    2,1(,3)
         STC   2,72(8) ==> .crmon
         MVC   73(1,8),119(13) ==> .crday,tm_mday
         SLR   2,2
         IC    2,31(9) ==> .refd
         AH    2,=H'1900'
         STH   2,74(8) ==> .rfyear
         CLM   2,3,=H'1979'
         BH    @@L48
         AH    2,=H'100'
         STH   2,74(8) ==> .rfyear
@@L48    EQU   *
         MVC   76(2,8),32(9) ==> .rfjday
         LA    4,104(,13) ==> s
         SLR   3,3 ==> c
         LA    2,36(0,0) ==> n
         
*** MEMSET ***
         LR    14,4           => target (s) ==> s
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,3            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         LH    2,74(8) ==> .rfyear
         N     2,=XL4'0000FFFF'
         A     2,=F'-1900'
         ST    2,124(13) ==> .tm_year
         LH    2,76(8) ==> .rfjday
         N     2,=XL4'0000FFFF'
         ST    2,116(13) ==> .tm_mday
         ST    4,88(13) ==> s
         LA    1,88(,13)
         L     15,=V(MKTIME)
         BALR  14,15
         IC    4,123(13) ==> .tm_mon
         LA    2,1(,4)
         STC   2,78(8) ==> .rfmon
         MVC   79(1,8),119(13) ==> .rfday,tm_mday
@@L24    EQU   *
         LR    2,7 ==> udata
         A     2,=F'12'
         ST    2,88(13)
         ST    8,92(13) ==> dslist
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L4
         ST    8,88(13) ==> dslist
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L4     EQU   *
         SLR   15,15
* Function 'parse' epilogue
         PDPEPIL
* Function 'parse' literal pool
         DS    0D
         LTORG
* Function 'parse' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@LC0    EQU   *
         DC    C' -'
         DC    X'15'
         DC    X'0'
@@LC1    EQU   *
         DC    C'NONVSAM'
         DC    X'0'
@@LC2    EQU   *
         DC    C'PAGESPACE'
         DC    X'0'
@@LC3    EQU   *
         DC    C'CLUSTER'
         DC    X'0'
@@LC4    EQU   *
         DC    C'USERCATALOG'
         DC    X'0'
@@LC5    EQU   *
         DC    C'VOLSER'
         DC    X'0'
@@LC6    EQU   *
         DC    C'******'
         DC    X'0'
@@LC7    EQU   *
         DC    C'IS'
         DC    X'0'
@@LC8    EQU   *
         DC    C'PS'
         DC    X'0'
@@LC9    EQU   *
         DC    C'DA'
         DC    X'0'
@@LC10   EQU   *
         DC    C'PO'
         DC    X'0'
@@LC11   EQU   *
         DC    C'VS'
         DC    X'0'
@@LC12   EQU   *
         DC    C'F'
         DC    X'0'
@@LC13   EQU   *
         DC    C'V'
         DC    X'0'
@@LC14   EQU   *
         DC    C'U'
         DC    X'0'
@@LC15   EQU   *
         DC    C'B'
         DC    X'0'
@@LC16   EQU   *
         DC    C'S'
         DC    X'0'
@@LC17   EQU   *
         DC    C'A'
         DC    X'0'
@@LC18   EQU   *
         DC    C'M'
         DC    X'0'
         END
