 TITLE '/home/mike/repos/crent370/dyn75/@@75ghbn.c'
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
         
&FUNC    SETC 'gethostbyname'
* Program text area
         DS    0F
         EJECT
* external function 'gethostbyname' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'gethostbyname'
@@75GHBN PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'gethostbyname' code
         L     7,0(11) ==> name
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    5,15 ==> crt
         SLR   6,6 ==> h
         LTR   15,15 ==> crt
         BE    @@L3
         ST    6,64(15) ==> h,crthoste
         ST    6,68(15) ==> h,crthoste
         LR    4,15 ==> crt
         A     4,=F'68'
         ST    4,72(15) ==> .crthoste
         ST    6,76(15) ==> h,crthoste
         LR    6,15 ==> h,crt
         A     6,=F'80' ==> h
         LR    3,15 ==> crt
         A     3,=F'104'
         ST    3,0(6) ==> .h_name
         LR    2,15 ==> crt
         A     2,=F'64'
         ST    2,4(6) ==> .h_aliases
         MVC   8(4,6),=F'2' ==> .h_addrtype
         MVC   12(4,6),=F'4' ==> .h_length
         A     2,=F'8'
         ST    2,16(6) ==> .h_addr_list
         SLR   6,6 ==> h
         STC   6,0(3) ==> h,crthostn
         ST    7,88(13) ==> name
         LA    1,88(,13)
         L     15,=V(@@75GABN)
         BALR  14,15
         ST    15,0(4) ==> crt,crthoste
         LTR   15,15 ==> crt
         BE    @@L3
         LR    6,5 ==> h,crt
         A     6,=F'80' ==> h
         ST    7,88(13) ==> name
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
         LA    2,79(0,0)
         CLR   15,2 ==> len
         BNH   @@L5
         LR    3,2 ==> len
@@L5     EQU   *
         LR    2,5 ==> crt
         A     2,=F'104'
         ST    2,88(13)
         ST    7,92(13) ==> name
         ST    3,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   2,2
         STC   2,104(5,3) ==> .crthostn
@@L3     EQU   *
         LR    15,6 ==> h
* Function 'gethostbyname' epilogue
         PDPEPIL
* Function 'gethostbyname' literal pool
         DS    0D
         LTORG
* Function 'gethostbyname' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
