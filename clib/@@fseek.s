 TITLE '/home/mike/repos/crent370/clib/@@fseek.c'
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
* external function '__fseek' prologue
* frame base=88, local stack=1264, call args=16
&FUNC    SETC  '__fseek'
@@FSEEK  PDPPRLG CINDEX=0,FRAME=1368,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fseek' code
         L     4,0(11) ==> fp
         L     7,4(11) ==> offset
         L     3,8(11) ==> whence
         LH    2,40(4) ==> .flags
         LR    5,2
         N     5,=F'-4'
         STH   5,40(4) ==> .flags
         L     5,24(4) ==> oldpos,filepos
         N     2,=F'4096'
         CH    2,=H'0'
         BE    @@L2
         ST    4,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FFLUSH)
         BALR  14,15
@@L2     EQU   *
         LTR   3,3 ==> whence
         BNE   @@L3
         LR    6,7 ==> newpos,offset
         B     @@L4
@@L3     EQU   *
         LA    2,1(0,0)
         CLR   3,2 ==> whence
         BNE   @@L4
         LR    6,5 ==> newpos,oldpos
         AR    6,7 ==> newpos,offset
@@L4     EQU   *
         LA    2,2(0,0)
         CLR   3,2 ==> whence
         BNE   @@L6
         LA    2,368(,13)
@@L7     EQU   *
         ST    2,88(13)
         MVC   92(4,13),=F'1000'
         MVC   96(4,13),=F'1'
         ST    4,100(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FREAD)
         BALR  14,15
         LA    3,1(0,0)
         CLR   15,3 ==> c
         BNE   @@L10
         B     @@L7
@@L6     EQU   *
         LH    3,40(4) ==> .flags
         LR    2,3
         N     2,=F'8192'
         CH    2,=H'0'
         BE    @@L11
         LR    2,3
         N     2,=F'512'
         CH    2,=H'0'
         BE    @@L12
         CL    6,24(4) ==> newpos,filepos
         BNE   @@L11
         MVC   32(4,4),28(4) ==> .upto,buf
         B     @@L10
@@L12    EQU   *
         L     2,32(4) ==> .upto
         S     2,28(4) ==> .buf
         LR    3,5 ==> start,oldpos
         SR    3,2 ==> start
         L     2,36(4) ==> .endbuf
         S     2,32(4) ==> .upto
         AR    2,5 ==> end,oldpos
         CR    6,3 ==> newpos,start
         BL    @@L11
         CR    6,2 ==> newpos,end
         BNL   @@L11
         LR    2,6 ==> newpos
         SR    2,5 ==> oldpos
         A     2,28(4) ==> .buf
         ST    2,32(4) ==> .upto
         B     @@L10
@@L11    EQU   *
         CR    6,5 ==> newpos,oldpos
         BNL   @@L16
         CLI   52(4),64 ==> .member
         BNH   @@L17
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         LR    2,4 ==> fp
         A     2,=F'43'
         ST    2,96(13)
         A     2,=F'9'
         ST    2,100(13)
         B     @@L37
@@L36    EQU   *
         OC    40(2,4),=H'3' ==> .flags
         B     @@L10
@@L17    EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC1)
         LR    2,4 ==> fp
         A     2,=F'43'
         ST    2,96(13)
@@L37    EQU   *
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         LR    2,4 ==> fp
         A     2,=F'106'
         ST    2,92(13)
         ST    4,96(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@REOPEN)
         BALR  14,15
         LTR   15,15 ==> c
         BE    @@L10
         SLR   5,5 ==> oldpos
@@L16    EQU   *
         LH    2,40(4) ==> .flags
         N     2,=F'512'
         CH    2,=H'0'
         BE    @@L20
         LR    2,5 ==> x,oldpos
         CR    5,6 ==> x,newpos
         BNL   @@L10
         LA    3,368(,13)
@@L25    EQU   *
         ST    3,88(13)
         MVC   92(4,13),=F'1000'
         MVC   96(4,13),=F'1'
         ST    4,100(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FREAD)
         BALR  14,15
         A     2,=F'1' ==> x
         CR    2,6 ==> x,newpos
         BNL   @@L10
         B     @@L25
@@L20    EQU   *
         LR    2,5 ==> x,oldpos
         CR    5,6 ==> x,newpos
         BNL   @@L10
@@L32    EQU   *
         ST    4,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FGETC)
         BALR  14,15
         L     5,=F'-1'
         CR    15,5 ==> c
         BE    @@L36
         A     2,=F'1' ==> x
         CR    2,6 ==> x,newpos
         BL    @@L32
@@L10    EQU   *
         LH    2,40(4) ==> .flags
         N     2,=F'2'
         L     15,=F'-1' ==> c
         CH    2,=H'0'
         BNE   @@L1
         MVC   20(4,4),=F'-1' ==> .ungetch
         SLR   15,15 ==> c
@@L1     EQU   *
* Function '__fseek' epilogue
         PDPEPIL
* Function '__fseek' literal pool
         DS    0D
         LTORG
* Function '__fseek' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'dd:%s(%s)'
         DC    X'0'
@@LC1    EQU   *
         DC    C'dd:%s'
         DC    X'0'
         END
