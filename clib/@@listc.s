 TITLE '/home/mike/repos/crent370/clib/@@listc.c'
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
* external function '__listc' prologue
* frame base=88, local stack=328, call args=16
&FUNC    SETC  '__listc'
@@LISTC  PDPPRLG CINDEX=0,FRAME=432,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__listc' code
         SLR   2,2 ==> psa
         MVC   424(4,13),548(2) ==> ascb
         L     9,=F'-1' ==> ret
         LR    8,2 ==> fp,psa
         LA    4,104(,13)
         LA    5,12(0,0)
         LR    3,2 ==> fp
         MVCL  4,2 ==> fp
         LA    2,120(,13)
         LR    6,2
         LA    7,45(0,0)
         LR    4,8 ==> fp
         LR    5,8 ==> fp
         MVCL  6,4 ==> fp
         LA    6,168(,13)
         LA    7,256(0,0)
         LR    4,8 ==> fp
         LR    5,8 ==> fp
         MVCL  6,4 ==> fp
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TMPNAM)
         BALR  14,15
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    8,15 ==> fp
         LTR   15,15 ==> fp
         BNE   @@L2
         MVC   88(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         NC    40(2,15),=H'32767' ==> .flags
         LA    2,104(,13)
         ST    2,88(13)
         LR    2,15 ==> fp
         A     2,=F'43'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         LR    2,8 ==> fp
         A     2,=F'61'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    8,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
         L     2,4(11) ==> option
         LTR   2,2
         BNE   @@L4
         MVC   4(4,11),=A(@@LC2) ==> option
@@L4     EQU   *
         MVC   88(4,13),424(13) ==> ascb
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         MVC   88(4,13),=A(@@LC3)
         MVC   92(4,13),0(11) ==> level
         LA    3,104(,13)
         ST    3,96(13)
         MVC   100(4,13),4(11) ==> option
         LA    1,88(,13)
         L     15,=V(IDCAMS)
         BALR  14,15
         MVC   88(4,13),424(13) ==> ascb
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LA    2,168(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         ST    3,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    8,15 ==> fp
         LTR   15,15 ==> fp
         BNE   @@L5
         L     9,=F'-1' ==> ret
         MVC   88(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(REMOVE)
         BALR  14,15
         B     @@L3
@@L5     EQU   *
         LA    4,168(,13) ==> p
@@L6     EQU   *
         SLR   3,3 ==> p
         ST    4,88(13) ==> p
         ST    3,92(13) ==> p
         MVC   96(4,13),=F'256'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
         ST    4,88(13) ==> p
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'255'
         ST    8,100(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FREAD)
         BALR  14,15
         LR    9,15 ==> ret
         LTR   15,15 ==> ret
         BNH   @@L8
         LR    3,4 ==> p
         IC    2,42(8) ==> .recfm
         N     2,=F'-64'
         CLM   2,1,=XL1'40'
         BNE   @@L10
         LH    9,0(4) ==> p
         N     9,=XL4'0000FFFF'
         LA    3,172(,13) ==> p
@@L10    EQU   *
         LA    2,255(0,0)
         CLR   9,2 ==> ret
         BNH   @@L11
         LR    9,2 ==> ret
@@L11    EQU   *
         SLR   2,2
         STC   2,168(9,13) ==> buf
         MVC   88(4,13),12(11) ==> udata
         MVC   92(4,13),=A(@@LC7)
         ST    3,96(13) ==> p
         L     2,8(11) ==> prt
         LA    1,88(,13)
         LA    15,0(2)
         BALR  14,15
@@L8     EQU   *
         LTR   3,3 ==> p
         BNE   @@L6
         OC    40(2,8),=H'-32768' ==> .flags
         ST    8,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
         SLR   9,9 ==> ret
@@L3     EQU   *
         LR    15,9 ==> ret
* Function '__listc' epilogue
         PDPEPIL
* Function '__listc' literal pool
         DS    0D
         LTORG
* Function '__listc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'wb,recfm=vb,lrecl=133,blksize=32760'
         DC    X'0'
@@LC1    EQU   *
         DC    C'Unable to allocate tmpfile'
         DC    X'0'
@@LC2    EQU   *
         DC    X'0'
@@LC3    EQU   *
         DC    C' LISTC LEVEL(''%s'') OUTFILE(%s) %s'
         DC    X'0'
@@LC4    EQU   *
         DC    C'DD:%s'
         DC    X'0'
@@LC5    EQU   *
         DC    C'r,record'
         DC    X'0'
@@LC6    EQU   *
         DC    C'unable to reopen temp file'
         DC    X'0'
@@LC7    EQU   *
         DC    C'%s'
         DC    X'0'
         END
