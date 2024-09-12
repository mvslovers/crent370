 TITLE '/home/mike/repos/crent370/clib/@@fpstar.c'
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
* external function '__fpstar' prologue
* frame base=88, local stack=120, call args=16
&FUNC    SETC  '__fpstar'
@@FPSTAR PDPPRLG CINDEX=0,FRAME=224,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fpstar' code
         L     9,0(11) ==> fp
         LA    1,88(,13)
         L     15,=V(@@PPAGET)
         BALR  14,15
         ST    15,220(13) ==> ppa
         SLR   15,15 ==> count
         LR    7,15 ==> recfm,count
         LR    6,15 ==> lrecl,count
         LR    8,15 ==> blksize,count
         ST    15,216(13) ==> count
         LA    4,104(,13)
         LA    5,20(0,0)
         LR    2,15 ==> count
         LR    3,15 ==> count
         MVCL  4,2 ==> count
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@TXRDDN)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         L     14,=A(@@L3)
         BNER  14
         L     3,220(13) ==> ppa
         IC    2,32(3) ==> .ppaflag
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L4
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXTERM)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXPERM)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXSHR)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LA    2,216(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(@@TXORG)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         MVC   88(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    7,15 ==> recfm
         LTR   15,15 ==> recfm
         BNE   @@L9
         L     7,=A(@@LC2) ==> recfm
@@L9     EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    7,92(13) ==> recfm
         LA    1,88(,13)
         L     15,=V(@@TXRECF)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         MVC   88(4,13),=A(@@LC3)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    6,15 ==> lrecl
         LTR   15,15 ==> lrecl
         BNE   @@L11
         L     6,=A(@@LC4) ==> lrecl
@@L11    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    6,92(13) ==> lrecl
         LA    1,88(,13)
         L     15,=V(@@TXLREC)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         ST    7,88(13) ==> recfm
         MVC   92(4,13),=F'194'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> ppa
         BE    @@L16
         MVC   88(4,13),=A(@@LC5)
         B     @@L40
@@L4     EQU   *
         MVC   88(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(@@TXSYSO)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LA    2,216(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(@@TXORG)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LR    2,9 ==> fp
         A     2,=F'106'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC7)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L19
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC8)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
@@L19    EQU   *
         LTR   15,15 ==> p
         BE    @@L20
         LA    3,128(,13)
         ST    3,88(13)
         LR    2,15 ==> p
         A     2,=F'6'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    3,88(13)
         MVC   92(4,13),=A(@@LC9)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    7,15 ==> recfm
@@L20    EQU   *
         LTR   7,7 ==> recfm
         BNE   @@L21
         MVC   88(4,13),=A(@@LC10)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    7,15 ==> recfm
@@L21    EQU   *
         LTR   7,7 ==> recfm
         BNE   @@L22
         L     7,=A(@@LC2) ==> recfm
@@L22    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    7,92(13) ==> recfm
         LA    1,88(,13)
         L     15,=V(@@TXRECF)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LR    2,9 ==> fp
         A     2,=F'106'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC11)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L24
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC12)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
@@L24    EQU   *
         LTR   15,15 ==> p
         BE    @@L25
         LA    3,128(,13)
         ST    3,88(13)
         LR    2,15 ==> p
         A     2,=F'6'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    3,88(13)
         MVC   92(4,13),=A(@@LC9)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    6,15 ==> lrecl
@@L25    EQU   *
         LTR   6,6 ==> lrecl
         BNE   @@L26
         MVC   88(4,13),=A(@@LC13)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    6,15 ==> lrecl
@@L26    EQU   *
         LTR   6,6 ==> lrecl
         BNE   @@L27
         L     6,=A(@@LC14) ==> lrecl
@@L27    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    6,92(13) ==> lrecl
         LA    1,88(,13)
         L     15,=V(@@TXLREC)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         ST    7,88(13) ==> recfm
         MVC   92(4,13),=F'194'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> ppa
         BE    @@L16
         LR    2,9 ==> fp
         A     2,=F'106'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC15)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L30
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC16)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
@@L30    EQU   *
         LTR   15,15 ==> p
         BE    @@L31
         LA    3,128(,13)
         ST    3,88(13)
         LR    2,15 ==> p
         A     2,=F'8'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    3,88(13)
         MVC   92(4,13),=A(@@LC9)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    8,15 ==> blksize
@@L31    EQU   *
         LTR   8,8 ==> blksize
         BNE   @@L32
         MVC   88(4,13),=A(@@LC17)
@@L40    EQU   *
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    8,15 ==> blksize
@@L32    EQU   *
         LTR   8,8 ==> blksize
         BE    @@L16
         LA    2,216(,13)
         ST    2,88(13)
         ST    8,92(13) ==> blksize
         LA    1,88(,13)
         L     15,=V(@@TXBKSZ)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
@@L16    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L3
         BCTR  15,0 ==> count
         L     4,216(13)
         LR    3,15 ==> count
         MH    3,=H'4'
         L     2,0(3,4)
         O     2,=F'-2147483648'
         ST    2,0(3,4)
         MVI   104(13),20 ==> .len
         MVI   105(13),1 ==> .request
         MVI   106(13),64 ==> .flag1
         MVC   112(4,13),216(13) ==> .txtptr
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
         LR    4,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LR    2,9 ==> fp
         A     2,=F'43'
         ST    2,88(13)
         L     2,216(13)
         L     2,0(2)
         A     2,=F'6'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LH    3,40(9) ==> .flags
         O     3,=F'-32768'
         STH   3,40(9) ==> .flags
         L     5,220(13) ==> ppa
         IC    2,32(5) ==> .ppaflag
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L3
         O     3,=F'128'
         STH   3,40(9) ==> .flags
@@L3     EQU   *
         L     2,216(13)
         LTR   2,2
         BE    @@L38
         LA    2,216(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FRTX9A)
         BALR  14,15
@@L38    EQU   *
         LR    15,4 ==> err
* Function '__fpstar' epilogue
         PDPEPIL
* Function '__fpstar' literal pool
         DS    0D
         LTORG
* Function '__fpstar' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'PS'
         DC    X'0'
@@LC1    EQU   *
         DC    C'TERMINAL_RECFM'
         DC    X'0'
@@LC2    EQU   *
         DC    C'V'
         DC    X'0'
@@LC3    EQU   *
         DC    C'TERMINAL_LRECL'
         DC    X'0'
@@LC4    EQU   *
         DC    C'4000'
         DC    X'0'
@@LC5    EQU   *
         DC    C'TERMINAL_BLKSIZE'
         DC    X'0'
@@LC6    EQU   *
         DC    C'SYSOUT_CLASS'
         DC    X'0'
@@LC7    EQU   *
         DC    C'recfm='
         DC    X'0'
@@LC8    EQU   *
         DC    C'recfm('
         DC    X'0'
@@LC9    EQU   *
         DC    C' ,)'
         DC    X'0'
@@LC10   EQU   *
         DC    C'SYSOUT_RECFM'
         DC    X'0'
@@LC11   EQU   *
         DC    C'lrecl='
         DC    X'0'
@@LC12   EQU   *
         DC    C'lrecl('
         DC    X'0'
@@LC13   EQU   *
         DC    C'SYSOUT_LRECL'
         DC    X'0'
@@LC14   EQU   *
         DC    C'255'
         DC    X'0'
@@LC15   EQU   *
         DC    C'blksize='
         DC    X'0'
@@LC16   EQU   *
         DC    C'blksize('
         DC    X'0'
@@LC17   EQU   *
         DC    C'SYSOUT_BLKSIZE'
         DC    X'0'
         END
