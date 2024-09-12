 TITLE '/home/mike/repos/crent370/dyn75/@@75ghba.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/dyn75
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'gethostbyaddr'
* Program text area
         DS    0F
         EJECT
* external function 'gethostbyaddr' prologue
* frame base=88, local stack=320, call args=16
&FUNC    SETC  'gethostbyaddr'
@@75GHBA PDPPRLG CINDEX=0,FRAME=424,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'gethostbyaddr' code
         L     7,0(11) ==> addr
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    5,15 ==> crt
         SLR   6,6 ==> h
         LTR   15,15 ==> crt
         BE    @@L3
         LA    2,104(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         LA    2,168(,13)
         XC    0(256,2),0(2)    clear name buffer
         MVC   64(4,15),=F'0' ==> .crthoste
         MVC   68(4,15),=F'0' ==> .crthoste
         LR    3,15 ==> crt
         A     3,=F'68'
         ST    3,72(15) ==> .crthoste
         MVC   76(4,15),=F'0' ==> .crthoste
         LR    6,15 ==> h,crt
         A     6,=F'80' ==> h
         LR    4,15 ==> crt
         A     4,=F'104'
         ST    4,0(6) ==> .h_name
         LR    2,15 ==> crt
         A     2,=F'64'
         ST    2,4(6) ==> .h_aliases
         MVC   8(4,6),=F'2' ==> .h_addrtype
         MVC   12(4,6),=F'4' ==> .h_length
         A     2,=F'8'
         ST    2,16(6) ==> .h_addr_list
         SLR   6,6 ==> h
         STC   6,0(4) ==> h,crthostn
         MVC   0(4,3),0(7) ==> .crthoste,addr
         MVC   88(4,13),=A(@@LC0)
         ST    7,92(13) ==> addr
         MVC   96(4,13),0(7) ==> addr
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    4,168(,13)
         ST    4,128(13) ==> .r6
         MVC   132(4,13),=F'18' ==> .r7
         MVC   136(4,13),0(3) ==> .r8,crthoste
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         CLI   168(13),0 ==> name
         BE    @@L3
         LR    6,5 ==> h,crt
         A     6,=F'80' ==> h
         ST    4,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LA    2,79(0,0)
         CLR   15,2 ==> len
         BNH   @@L5
         LR    15,2 ==> len
@@L5     EQU   *
         SLR   2,2 ==> i
         CR    2,15 ==> i,len
         BNL   @@L12
@@L10    EQU   *
         IC    3,168(2,13) ==> name
         STC   3,104(5,2) ==> .crthostn
         A     2,=F'1' ==> i
         CR    2,15 ==> i,len
         BL    @@L10
@@L12    EQU   *
         SLR   2,2
         STC   2,104(5,15) ==> .crthostn
@@L3     EQU   *
         LR    15,6 ==> h
* Function 'gethostbyaddr' epilogue
         PDPEPIL
* Function 'gethostbyaddr' literal pool
         DS    0D
         LTORG
* Function 'gethostbyaddr' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'__75ghba() addr=%08X, *addr=%08X'
         DC    X'15'
         DC    X'0'
         END
