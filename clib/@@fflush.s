 TITLE '/home/mike/repos/crent370/clib/@@fflush.c'
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
* external function '__fflush' prologue
* frame base=88, local stack=32, call args=8
&FUNC    SETC  '__fflush'
@@FFLUSH PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fflush' code
         L     6,0(11) ==> fp
         L     4,8(6) ==> dcb,dcb
         SLR   15,15 ==> err
         LH    3,40(6) ==> .flags
         LR    2,3
         N     2,=F'512'
         CH    2,=H'0'
         BNE   @@L3
         LR    2,3
         N     2,=F'4096'
         CH    2,=H'0'
         BE    @@L3
         L     2,32(6) ==> .upto
         CL    2,28(6) ==> .buf
         BE    @@L3
         CLI   17(4),79 ==> .dcbdevt
         BNE   @@L6
         LA    4,96(,13)
         LA    5,32(0,0)
         LR    2,15 ==> err
         LR    3,15 ==> err
         MVCL  4,2 ==> err
         L     2,32(6) ==> len,upto
         S     2,28(6) ==> len,buf
         MVC   88(4,13),28(6) ==> .buf
         ST    2,92(13) ==> len
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         B     @@L7
@@L6     EQU   *
         IC    2,42(6) ==> .recfm
         N     2,=F'192'
         LA    3,128(0,0)
         CR    2,3
         BE    @@L10
         BH    @@L16
         LA    3,64(0,0)
         CLR   2,3
         BE    @@L13
         B     @@L7
@@L16    EQU   *
         LA    3,192(0,0)
         CLR   2,3
         BNE   @@L7
@@L10    EQU   *
         LH    2,40(6) ==> .flags
         N     2,=F'1024'
         BCTR  2,0
         N     2,=XL4'0000FFFF' ==> fill
         SRL   2,15 ==> fill
         SLL   2,6 ==> fill
         ST    6,88(13) ==> fp
         ST    2,92(13) ==> fill
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
         B     @@L7
@@L13    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
@@L7     EQU   *
         MVC   32(4,6),28(6) ==> .upto,buf
         MVC   24(4,6),=F'0' ==> .filepos
@@L3     EQU   *
* Function '__fflush' epilogue
         PDPEPIL
* Function '__fflush' literal pool
         DS    0D
         LTORG
* Function '__fflush' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'fixflush'
         DS    0F
         EJECT
* static function 'fixflush' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'fixflush'
@@3      PDPPRLG CINDEX=1,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'fixflush' code
         L     4,0(11) ==> fp
         L     6,4(11) ==> fill
         L     5,32(4) ==> len,upto
         S     5,28(4) ==> len,buf
         IC    2,42(4) ==> .recfm
         N     2,=F'-64'
         CLM   2,1,=XL1'C0'
         BNE   @@L18
         ST    5,108(13) ==> len
         MVC   104(4,13),12(4) ==> .asmbuf
         MVC   88(4,13),104(13)
         B     @@L22
@@L18    EQU   *
         LH    3,16(4) ==> .lrecl
         N     3,=XL4'0000FFFF'
         ST    3,108(13) ==> n
         MVC   104(4,13),12(4) ==> .asmbuf
         L     2,104(13) ==> s
         
*** MEMSET ***
         LR    14,2           => target (s) ==> s
         LR    15,3           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,6            fill character ==> fill
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         ST    2,88(13) ==> s
@@L22    EQU   *
         MVC   92(4,13),28(4) ==> .buf
         ST    5,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVC   88(4,13),8(4) ==> .dcb
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,108(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@AWRITE)
         BALR  14,15
@@L21    EQU   *
* Function 'fixflush' epilogue
         PDPEPIL
* Function 'fixflush' literal pool
         DS    0D
         LTORG
* Function 'fixflush' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'varflush'
         DS    0F
         EJECT
* static function 'varflush' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'varflush'
@@4      PDPPRLG CINDEX=2,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'varflush' code
         L     5,0(11) ==> fp
         SLR   6,6 ==> err
         L     3,32(5) ==> len,upto
         S     3,28(5) ==> len,buf
         LR    4,3 ==> rdwlen,len
         A     4,=F'4' ==> rdwlen
         ST    4,108(13) ==> rdwlen
         MVC   104(4,13),12(5) ==> .asmbuf
         L     2,104(13)
         A     2,=F'4'
         ST    2,88(13)
         MVC   92(4,13),28(5) ==> .buf
         ST    3,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    3,4 ==> rdwlen
         SRL   3,8
         L     2,104(13)
         STC   3,0(2)
         L     2,104(13)
         STC   4,1(2) ==> rdwlen
         L     2,104(13)
         STC   6,2(2) ==> err
         L     2,104(13)
         STC   6,3(2) ==> err
         MVC   88(4,13),8(5) ==> .dcb
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,108(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@AWRITE)
         BALR  14,15
@@L24    EQU   *
* Function 'varflush' epilogue
         PDPEPIL
* Function 'varflush' literal pool
         DS    0D
         LTORG
* Function 'varflush' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
         DS    0F
         EJECT
* static function 'tso_putline' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'tso_putline'
@@2      PDPPRLG CINDEX=3,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function 'tso_putline' code
         L     3,4(11) ==> len
         LTR   3,3 ==> len
         BE    @@L27
         N     3,=F'65535' ==> r0
         L     2,0(11) ==> r1,buf
         N     2,=F'16777215' ==> r1
         O     2,=F'134217728' ==> r1
         LR    0,3                buffer length ==> r0
         LR    1,2                flags and buffer address ==> r1
         TPUT  (1),(0),R
@@L27    EQU   *
         SLR   15,15
* Function 'tso_putline' epilogue
         PDPEPIL
* Function 'tso_putline' literal pool
         DS    0D
         LTORG
* Function 'tso_putline' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
         END
