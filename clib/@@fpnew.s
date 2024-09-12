 TITLE '/home/mike/repos/crent370/clib/@@fpnew.c'
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
* external function '__fpnew' prologue
* frame base=88, local stack=120, call args=16
&FUNC    SETC  '__fpnew'
@@FPNEW  PDPPRLG CINDEX=0,FRAME=224,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fpnew' code
         SLR   6,6 ==> count
         MVC   88(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    7,15 ==> recfm
         MVC   88(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    8,15 ==> lrecl
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         ST    15,220(13) ==> blksize
         MVC   88(4,13),=A(@@LC3)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    9,15 ==> space
         ST    6,216(13) ==> count
         LA    4,104(,13)
         LA    5,20(0,0)
         LR    2,6 ==> count
         LR    3,6 ==> count
         MVCL  4,2 ==> count
         LA    3,128(,13) ==> s
         LA    2,87(0,0) ==> n
         
*** MEMSET ***
         LR    14,3           => target (s) ==> s
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,6            fill character ==> count
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         ST    3,88(13) ==> s
         L     2,0(11) ==> fp
         A     2,=F'106'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LR    4,3 ==> p,s
         IC    2,0(3) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L61
@@L18    EQU   *
         CLI   0(4),77 ==> p
         BNE   @@L7
         LR    2,4 ==> p
         BCTR  2,0
         CLI   0(2),126
         BE    @@L8
         MVI   0(4),126 ==> p
         B     @@L9
@@L66    EQU   *
         ST    4,88(13) ==> p
         LR    2,4 ==> p
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         B     @@L7
@@L8     EQU   *
         ST    4,88(13) ==> p
         LR    2,4 ==> p
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
@@L9     EQU   *
         A     4,=F'1' ==> p
         IC    2,0(4) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L7
@@L15    EQU   *
         CLI   0(4),93 ==> p
         BE    @@L66
         A     4,=F'1' ==> p
         IC    2,0(4) ==> p
         CLM   2,1,=XL1'00'
         BNE   @@L15
@@L7     EQU   *
         CLI   0(4),107 ==> p
         BNE   @@L16
         MVI   0(4),94 ==> p
         B     @@L5
@@L16    EQU   *
         SLR   2,2
         IC    2,0(4) ==> p
         L     3,=V(@@TOUP)
         L     3,0(3) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,0(4) ==> p
@@L5     EQU   *
         A     4,=F'1' ==> p
         IC    2,0(4) ==> p
         CLM   2,1,=XL1'00'
         BNE   @@L18
@@L61    EQU   *
         LA    2,128(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    4,15 ==> p
         LTR   15,15 ==> p
         BE    @@L64
@@L30    EQU   *
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> recfm
         BE    @@L23
         LR    7,4 ==> recfm,p
         A     7,=F'6' ==> recfm
         B     @@L21
@@L23    EQU   *
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> recfm
         BE    @@L25
         LR    8,4 ==> lrecl,p
         A     8,=F'6' ==> lrecl
         B     @@L21
@@L25    EQU   *
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC7)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> recfm
         BE    @@L27
         A     4,=F'8' ==> p
         ST    4,220(13) ==> p,blksize
         B     @@L21
@@L27    EQU   *
         ST    4,88(13) ==> p
         MVC   92(4,13),=A(@@LC8)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> recfm
         BE    @@L21
         LR    9,4 ==> space,p
         A     9,=F'6' ==> space
@@L21    EQU   *
         MVC   88(4,13),=F'0'
         MVC   92(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    4,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L30
@@L64    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@TXRDDN)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LA    2,216(,13)
         ST    2,88(13)
         L     2,0(11) ==> fp
         A     2,=F'61'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@TXDSN)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXNEW)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXCAT)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LA    2,216(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC9)
         LA    1,88(,13)
         L     15,=V(@@TXORG)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LTR   7,7 ==> recfm
         BNE   @@L37
         L     7,=A(@@LC10) ==> recfm
@@L37    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    7,92(13) ==> recfm
         LA    1,88(,13)
         L     15,=V(@@TXRECF)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LTR   8,8 ==> lrecl
         BNE   @@L39
         L     8,=A(@@LC11) ==> lrecl
@@L39    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    8,92(13) ==> lrecl
         LA    1,88(,13)
         L     15,=V(@@TXLREC)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         ST    7,88(13) ==> recfm
         MVC   92(4,13),=F'194'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> recfm
         BE    @@L41
         L     2,220(13) ==> blksize
         LTR   2,2
         BE    @@L41
         LA    2,216(,13)
         ST    2,88(13)
         MVC   92(4,13),220(13) ==> blksize
         LA    1,88(,13)
         L     15,=V(@@TXBKSZ)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
@@L41    EQU   *
         LTR   9,9 ==> space
         BE    @@L44
         ST    9,88(13) ==> space
         MVC   92(4,13),=A(@@LC12)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> recfm
         BNE   @@L45
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> recfm
         LA    1,88(,13)
         L     15,=V(@@TXCYL)
         BALR  14,15
         B     @@L67
@@L45    EQU   *
         ST    9,88(13) ==> space
         MVC   92(4,13),=A(@@LC13)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> recfm
         BNE   @@L47
         LA    2,216(,13)
         ST    2,88(13)
         ST    15,92(13) ==> recfm
         LA    1,88(,13)
         L     15,=V(@@TXTRK)
         BALR  14,15
@@L67    EQU   *
         A     9,=F'4' ==> space
         B     @@L46
@@L47    EQU   *
         ST    9,88(13) ==> space
         MVC   92(4,13),=F'126'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    3,15 ==> x
         LTR   15,15 ==> x
         BE    @@L49
         MVI   0(15),0 ==> x
@@L49    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    9,92(13) ==> space
         LA    1,88(,13)
         L     15,=V(@@TXBLK)
         BALR  14,15
         LTR   3,3 ==> x
         BE    @@L46
         LR    9,3 ==> space,x
         A     9,=F'1' ==> space
@@L46    EQU   *
         IC    2,0(9) ==> space
         CLM   2,1,=XL1'00'
         BE    @@L52
         SLR   2,2
         IC    2,0(9) ==> space
         L     3,=V(@@ISBUF)
         LR    4,3
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BNE   @@L52
@@L55    EQU   *
         A     9,=F'1' ==> space
         IC    2,0(9) ==> space
         CLM   2,1,=XL1'00'
         BE    @@L52
         SLR   2,2
         IC    2,0(9) ==> space
         L     3,0(4) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L55
@@L52    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         ST    9,92(13) ==> space
         LA    1,88(,13)
         L     15,=V(@@TXSPAC)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
@@L44    EQU   *
         LA    2,216(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    6,15 ==> count
         LTR   15,15 ==> count
         BE    @@L32
         BCTR  6,0 ==> count
         L     4,216(13)
         LR    3,6 ==> count
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
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         L     2,0(11) ==> fp
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
         L     2,0(11) ==> fp
         OC    40(2,2),=H'-32768' ==> .flags
@@L32    EQU   *
         L     2,216(13)
         LTR   2,2
         BE    @@L59
         LA    2,216(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FRTX9A)
         BALR  14,15
@@L59    EQU   *
         LR    15,3 ==> err
* Function '__fpnew' epilogue
         PDPEPIL
* Function '__fpnew' literal pool
         DS    0D
         LTORG
* Function '__fpnew' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'DATASET_RECFM'
         DC    X'0'
@@LC1    EQU   *
         DC    C'DATASET_LRECL'
         DC    X'0'
@@LC2    EQU   *
         DC    C'DATASET_BLKSIZE'
         DC    X'0'
@@LC3    EQU   *
         DC    C'DATASET_SPACE'
         DC    X'0'
@@LC4    EQU   *
         DC    C';'
         DC    X'0'
@@LC5    EQU   *
         DC    C'RECFM='
         DC    X'0'
@@LC6    EQU   *
         DC    C'LRECL='
         DC    X'0'
@@LC7    EQU   *
         DC    C'BLKSIZE='
         DC    X'0'
@@LC8    EQU   *
         DC    C'SPACE='
         DC    X'0'
@@LC9    EQU   *
         DC    C'PS'
         DC    X'0'
@@LC10   EQU   *
         DC    C'V'
         DC    X'0'
@@LC11   EQU   *
         DC    C'255'
         DC    X'0'
@@LC12   EQU   *
         DC    C'CYL='
         DC    X'0'
@@LC13   EQU   *
         DC    C'TRK='
         DC    X'0'
         END
