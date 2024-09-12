 TITLE '/home/mike/repos/crent370/clib/@@cpopen.c'
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
         
HASPCKPT DCB   DDNAME=HASPCKPT,DSORG=PS,MACRF=(RCP),                   X
               RECFM=U,BLKSIZE=4096
DCBLEN   EQU   *-HASPCKPT
* Program text area
         DS    0F
         EJECT
* external function '__cpopen' prologue
* frame base=88, local stack=4104, call args=16
&FUNC    SETC  '__cpopen'
@@CPOPEN PDPPRLG CINDEX=0,FRAME=4208,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__cpopen' code
         SLR   8,8 ==> work
         SLR   9,9 ==> work
         L     6,0(11) ==> dataset
         L     2,=F'4200'
         AR    2,13
         MVC   0(4,2),=F'-2147483648'
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'360'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    4,15 ==> cp
         LTR   15,15 ==> cp
         BE    @@L3
         ST    15,88(13) ==> cp
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LR    5,4 ==> dcb,cp
         A     5,=F'256' ==> dcb
         ST    5,16(4) ==> dcb,dcb
         L     1,=A(HASPCKPT)        model DCB for HASPCKPT
         MVC   0(DCBLEN,5),0(1)   copy model to our dcb area ==> dcb
         SLR   2,2
         IC    2,0(6) ==> dataset
         L     3,=V(@@TOUP)
         L     3,0(3) ==> __toup
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'196'
         BNE   @@L4
         SLR   2,2
         IC    2,1(6)
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'196'
         BNE   @@L4
         CLI   2(6),122
         BNE   @@L4
         LR    15,6 ==> p,dataset
         A     15,=F'3' ==> p
         SLR   6,6 ==> i
         IC    2,0(15) ==> p
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L6
         L     7,=V(@@TOUP)
@@L10    EQU   *
         SLR   2,2
         IC    2,0(6,15) ==> i
         L     3,0(7) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,8(4,6) ==> .ddname
         A     6,=F'1' ==> i
         LA    2,7(0,0)
         CR    6,2 ==> i
         BH    @@L6
         IC    2,0(15) ==> p
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L10
@@L6     EQU   *
         LA    7,7(0,0)
         CR    6,7 ==> i
         BH    @@L27
         LA    3,8(0,0)
@@L14    EQU   *
         LR    2,6 ==> i
         AR    2,4 ==> cp
         LA    7,64(0,0)
         STC   7,0(3,2) ==> .ddname
         A     6,=F'1' ==> i
         LA    2,7(0,0)
         CR    6,2 ==> i
         BNH   @@L14
@@L27    EQU   *
         LR    2,5 ==> dcb
         A     2,=F'40'
         ST    2,88(13)
         LR    2,4 ==> cp
         A     2,=F'8'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         B     @@L15
@@L4     EQU   *
         ST    4,88(13) ==> cp
         ST    6,92(13) ==> dataset
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L15
         ST    4,88(13) ==> cp
         LA    1,88(,13)
         L     15,=V(@@CPCLOS)
         BALR  14,15
         SLR   4,4 ==> cp
         B     @@L3
@@L15    EQU   *
         L     2,=F'4200'
         AR    2,13
         OPEN  ((5)),MF=(E,(2)) ==> dcb
         IC    2,48(5) ==> .dcboflgs
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BNE   @@L17
         ST    4,88(13) ==> cp
         LA    1,88(,13)
         L     15,=V(@@CPCLOS)
         BALR  14,15
         SLR   4,4 ==> cp
@@L17    EQU   *
         ST    4,88(13) ==> cp
         MVC   92(4,13),=F'768'
         LA    1,88(,13)
         L     15,=V(@@CPPOIN)
         BALR  14,15
         ST    4,88(13) ==> cp
         LA    3,104(,13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(@@CPREAD)
         BALR  14,15
         LR    2,4 ==> cp
         A     2,=F'20'
         ST    2,88(13)
         ST    3,92(13)
         MVC   96(4,13),=F'204'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LH    3,206(4) ==> ._NUMTGV
         N     3,=XL4'0000FFFF'
         A     3,=F'7' ==> work
         SRL   3,3 ==> work
         SLR   9,9 ==> work
         IC    9,210(4) ==> work,_NUMDA
         MR    8,3 ==> work
         LR    3,9 ==> work
         A     3,=F'75' ==> work
         N     3,=F'-4' ==> work
         ST    3,224(4) ==> work,pddb1
         LH    3,198(4) ==> ._MAXJOBS
         N     3,=XL4'0000FFFF'
         A     3,=F'1' ==> work
         LR    2,3 ==> work
         SLL   2,3
         SR    2,3 ==> work
         LR    3,2 ==> work
         SLL   3,2 ==> work
         A     3,=F'4095' ==> work
         SRL   3,12 ==> work
         STH   3,228(4) ==> work,jqeblks
         LH    5,230(4) ==> .jotblks
         N     5,=XL4'0000FFFF'
         LH    2,228(4) ==> .jqeblks
         N     2,=XL4'0000FFFF'
         AR    5,2 ==> blocks
         MVC   88(4,13),=F'1'
         LR    2,5 ==> blocks
         MH    2,=H'4096'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         ST    15,236(4) ==> rc,buf
         LTR   15,15 ==> rc
         BE    @@L3
         ST    2,232(4) ==> .buflen
         SLR   3,3 ==> work
         CLR   3,5 ==> work,blocks
         BNL   @@L29
@@L23    EQU   *
         ST    4,88(13) ==> cp
         LR    2,3 ==> work
         MH    2,=H'4096'
         A     2,236(4) ==> .buf
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@CPREAD)
         BALR  14,15
         A     3,=F'1' ==> work
         CLR   3,5 ==> work,blocks
         BL    @@L23
@@L29    EQU   *
         L     2,236(4) ==> .buf
         A     2,=F'28'
         ST    2,240(4) ==> .jqe
         LH    2,228(4) ==> .jqeblks
         N     2,=XL4'0000FFFF'
         MH    2,=H'4096'
         LR    3,2
         A     3,236(4) ==> .buf
         ST    3,244(4) ==> .jqeend
         LH    2,230(4) ==> .jotblks
         CH    2,=H'0'
         BE    @@L3
         ST    3,248(4) ==> .jot
         LR    2,5 ==> blocks
         MH    2,=H'4096'
         A     2,236(4) ==> .buf
         ST    2,252(4) ==> .jotend
@@L3     EQU   *
         LR    15,4 ==> cp
* Function '__cpopen' epilogue
         PDPEPIL
* Function '__cpopen' literal pool
         DS    0D
         LTORG
* Function '__cpopen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'HASPCP'
         DC    X'0'
         
&FUNC    SETC 'allocate_checkpoint'
         DS    0F
         EJECT
* static function 'allocate_checkpoint' prologue
* frame base=88, local stack=32, call args=16
&FUNC    SETC  'allocate_checkpoint'
@@6      PDPPRLG CINDEX=1,FRAME=136,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'allocate_checkpoint' code
         L     6,0(11) ==> fp
         SLR   15,15 ==> count
         L     7,16(6) ==> dcb,dcb
         ST    15,128(13) ==> count
         LA    4,104(,13)
         LA    5,20(0,0)
         LR    2,15 ==> count
         LR    3,15 ==> count
         MVCL  4,2 ==> count
         LA    2,128(,13)
         ST    2,88(13)
         ST    15,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@TXRDDN)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LA    2,128(,13)
         ST    2,88(13)
         MVC   92(4,13),4(11) ==> dataset
         LA    1,88(,13)
         L     15,=V(@@TXDSN)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LA    2,128(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXSHR)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LA    2,128(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L32
         BCTR  15,0 ==> count
         L     4,128(13)
         LR    3,15 ==> count
         MH    3,=H'4'
         L     2,0(3,4)
         O     2,=F'-2147483648'
         ST    2,0(3,4)
         MVI   104(13),20 ==> .len
         MVI   105(13),1 ==> .request
         MVI   106(13),64 ==> .flag1
         MVC   112(4,13),128(13) ==> .txtptr
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L32
         LR    2,6 ==> fp
         A     2,=F'8'
         ST    2,88(13)
         L     2,128(13)
         L     2,0(2)
         A     2,=F'6'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    2,7 ==> dcb
         A     2,=F'40'
         ST    2,88(13)
         L     2,128(13)
         L     2,0(2)
         A     2,=F'6'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L32    EQU   *
         L     2,128(13)
         LTR   2,2
         BE    @@L37
         LA    2,128(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FRTX9A)
         BALR  14,15
@@L37    EQU   *
         LR    15,3 ==> err
* Function 'allocate_checkpoint' epilogue
         PDPEPIL
* Function 'allocate_checkpoint' literal pool
         DS    0D
         LTORG
* Function 'allocate_checkpoint' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
