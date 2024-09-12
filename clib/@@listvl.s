 TITLE '/home/mike/repos/crent370/clib/@@listvl.c'
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
@@2      EQU   *
         DC    C'__listvl'
         DC    X'0'
         DS    0F
         EJECT
* external function '__listvl' prologue
* frame base=88, local stack=272, call args=16
&FUNC    SETC  '__listvl'
@@LISTVL PDPPRLG CINDEX=0,FRAME=376,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__listvl' code
         L     8,0(11) ==> filter
         L     9,4(11) ==> dolspace
         L     7,8(11) ==> vatlst
         MVC   368(4,13),=F'0'
         LA    2,16(0,0)
         L     2,0(2) ==> cvt
         L     5,40(2) ==> ucblist,cvtilk2
         SLR   6,6 ==> i
         LH    2,0(5) ==> .ucb
         CLM   2,3,=H'-1'
         BE    @@L3
@@L21    EQU   *
         LR    2,6 ==> i
         MH    2,=H'2'
         LH    4,0(2,5) ==> .ucb
         N     4,=XL4'0000FFFF'
         LTR   4,4 ==> ucbdasd
         BE    @@L4
         CLI   18(4),32 ==> .ucbtype
         BNE   @@L4
         CLI   19(4),5 ==> .ucbtype
         BE    @@L4
         IC    2,3(4) ==> .ucbstat
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L4
         LTR   8,8 ==> filter
         BE    @@L10
         IC    2,0(8) ==> filter
         CLM   2,1,=XL1'00'
         BE    @@L10
         LA    2,104(,13)
         ST    2,88(13)
         LR    3,4 ==> ucbdasd
         A     3,=F'28'
         ST    3,92(13)
         MVC   96(4,13),=F'6'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVI   110(13),0 ==> volser
         ST    2,88(13)
         ST    8,92(13) ==> filter
         LA    1,88(,13)
         L     15,=V(@@PATMAT)
         BALR  14,15
         LTR   15,15 ==> fp
         BE    @@L4
@@L10    EQU   *
         MVC   88(4,13),368(13)
         LR    2,4 ==> ucbdasd
         A     2,=F'28'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
         LTR   15,15 ==> fp
         BNE   @@L4
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'40'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15 ==> vol
         LTR   15,15 ==> vol
         BNE   @@L13
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@2)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L3
@@L13    EQU   *
         LA    2,368(,13)
         ST    2,88(13)
         ST    15,92(13) ==> vol
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         ST    3,88(13) ==> vol
         LR    2,4 ==> ucbdasd
         A     2,=F'28'
         ST    2,92(13)
         MVC   96(4,13),=F'6'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         IC    2,3(4) ==> .ucbstat
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L14
         OI    7(3),128 ==> .status
@@L14    EQU   *
         IC    2,3(4) ==> .ucbstat
         N     2,=F'32'
         CLM   2,1,=XL1'00'
         BE    @@L15
         OI    7(3),64 ==> .status
@@L15    EQU   *
         IC    2,3(4) ==> .ucbstat
         N     2,=F'4'
         CLM   2,1,=XL1'00'
         BE    @@L16
         OI    7(3),32 ==> .status
@@L16    EQU   *
         IC    2,34(4) ==> .ucbstab
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BE    @@L17
         OI    7(3),8 ==> .status
@@L17    EQU   *
         IC    2,34(4) ==> .ucbstab
         N     2,=F'8'
         CLM   2,1,=XL1'00'
         BE    @@L18
         OI    7(3),4 ==> .status
@@L18    EQU   *
         IC    2,34(4) ==> .ucbstab
         N     2,=F'4'
         CLM   2,1,=XL1'00'
         BE    @@L19
         OI    7(3),2 ==> .status
@@L19    EQU   *
         ST    4,8(3) ==> ucbdasd,ucbdasd
         MVC   12(2,3),4(4) ==> .cuu,ucbchan
         ST    4,88(13) ==> ucbdasd
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         STH   15,14(3) ==> fp,dasdtype
         LTR   9,9 ==> dolspace
         BE    @@L4
         ST    3,88(13) ==> vol
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
@@L4     EQU   *
         A     6,=F'1' ==> i
         LR    2,6 ==> i
         MH    2,=H'2'
         LH    2,0(2,5) ==> .ucb
         CLM   2,3,=H'-1'
         BNE   @@L21
@@L3     EQU   *
         LTR   7,7 ==> vatlst
         BE    @@L34
         IC    2,0(7) ==> vatlst
         CLM   2,1,=XL1'00'
         BE    @@L34
         ST    7,88(13) ==> vatlst
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         LR    6,15 ==> fp
         SLR   15,15 ==> p
         LA    7,112(,13)
         LR    4,7
         LA    5,256(0,0)
         LR    2,15 ==> p
         LR    3,15 ==> p
         MVCL  4,2 ==> p
         LTR   6,6 ==> fp
         BE    @@L34
         ST    7,88(13)
         MVC   92(4,13),=F'256'
         ST    6,96(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETS)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L38
         LA    2,112(,13) ==> s
         SLR   4,4 ==> c
         LA    3,256(0,0) ==> n
@@L32    EQU   *
         ST    2,88(13) ==> s
         MVC   92(4,13),368(13)
         LA    1,88(,13)
         L     15,=A(@@7)
         BALR  14,15
         
*** MEMSET ***
         LR    14,2           => target (s) ==> s
         LR    15,3           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,4            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         ST    2,88(13) ==> s
         ST    3,92(13) ==> n
         ST    6,96(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETS)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L32
@@L38    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
@@L34    EQU   *
         L     15,368(13)
* Function '__listvl' epilogue
         PDPEPIL
* Function '__listvl' literal pool
         DS    0D
         LTORG
* Function '__listvl' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s: out of memory'
         DC    X'0'
         DS    0F
         EJECT
* static function 'get_dasdtype' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'get_dasdtype'
@@4      PDPPRLG CINDEX=1,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'get_dasdtype' code
         SLR   15,15 ==> dasdtype
         L     2,0(11) ==> ucbdasd
         SLR   3,3
         IC    3,19(2) ==> .ucbtype
         LA    2,15(0,0)
         CLR   3,2
         BH    @@L40
         MH    3,=H'4'
         L     2,=A(@@L52)
         L     14,0(3,2)
         BR    14
         DS    0F
         DS    0F
         DS    0F
         LTORG
         DS    0F
@@L52    EQU   *
         DC    A(@@L40)
         DC    A(@@L41)
         DC    A(@@L40)
         DC    A(@@L40)
         DC    A(@@L40)
         DC    A(@@L40)
         DC    A(@@L43)
         DC    A(@@L43)
         DC    A(@@L44)
         DC    A(@@L49)
         DC    A(@@L46)
         DC    A(@@L47)
         DC    A(@@L48)
         DC    A(@@L49)
         DC    A(@@L50)
         DC    A(@@L51)
@@L41    EQU   *
         L     15,=F'8977' ==> dasdtype
         B     @@L40
@@L43    EQU   *
         L     15,=F'8965' ==> dasdtype
         B     @@L40
@@L44    EQU   *
         L     15,=F'8980' ==> dasdtype
         B     @@L40
@@L46    EQU   *
         L     15,=F'13120' ==> dasdtype
         B     @@L40
@@L47    EQU   *
         L     15,=F'13136' ==> dasdtype
         B     @@L40
@@L48    EQU   *
         L     15,=F'13173' ==> dasdtype
         B     @@L40
@@L49    EQU   *
         L     15,=F'13104' ==> dasdtype
         B     @@L40
@@L50    EQU   *
         L     15,=F'13184' ==> dasdtype
         B     @@L40
@@L51    EQU   *
         L     15,=F'13200' ==> dasdtype
@@L40    EQU   *
* Function 'get_dasdtype' epilogue
         PDPEPIL
* Function 'get_dasdtype' literal pool
         DS    0D
         LTORG
* Function 'get_dasdtype' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@8      EQU   *
         DC    C'get_lspace'
         DC    X'0'
         DS    0F
         EJECT
* static function 'get_lspace' prologue
* frame base=88, local stack=40, call args=16
&FUNC    SETC  'get_lspace'
@@5      PDPPRLG CINDEX=2,FRAME=144,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'get_lspace' code
         L     4,0(11) ==> vol
         MVC   136(4,13),=F'0'
         L     3,8(4) ==> ucbdasd,ucbdasd
         LA    2,104(,13)
         LR    0,3 UCB address in R0 ==> ucbdasd
         LR    1,2 LSPACE parameter area in R1
         SVC   78  Issue SVC 78 LSPACE
         ST    15,136(13) Save LSPACE RC
         L     2,136(13)
         LTR   2,2
         BNE   @@L55
         STC   2,114(13) ==> .free_tot_cylz
         STC   2,119(13) ==> .free_tot_trkz
         STC   2,124(13) ==> .free_extentsz
         STC   2,129(13) ==> .max_contig_cylz
         STC   2,134(13) ==> .max_contig_trkz
         LA    2,110(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         ST    15,16(4) ==> .freecyls
         LA    2,115(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         ST    15,20(4) ==> .freetrks
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         ST    15,24(4) ==> .freeexts
         LA    2,125(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         ST    15,28(4) ==> .maxfreecyls
         LA    2,130(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         ST    15,32(4) ==> .maxfreetrks
         B     @@L57
@@L55    EQU   *
         MVC   88(4,13),=A(@@LC1)
         MVC   92(4,13),=A(@@8)
         MVC   96(4,13),136(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L57    EQU   *
         L     15,136(13)
* Function 'get_lspace' epilogue
         PDPEPIL
* Function 'get_lspace' literal pool
         DS    0D
         LTORG
* Function 'get_lspace' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
@@LC1    EQU   *
         DC    C'@@listvl:%s: LSPACE RC=%d'
         DC    X'0'
         DS    0F
         EJECT
* static function 'get_comment' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'get_comment'
@@7      PDPPRLG CINDEX=3,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function 'get_comment' code
         SLR   7,7 ==> rc
         LA    2,4(,11)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    6,15 ==> count
         L     5,0(11) ==> rec,buf
         STC   7,6(5) ==> rc,filler1
         STC   7,79(5) ==> rc,filler2
         LA    2,104(,13)
         ST    2,88(13)
         ST    5,92(13) ==> rec
         MVC   96(4,13),=F'6'
         LA    1,88(,13)
         L     15,=V(STRNCPY)
         BALR  14,15
         STC   7,110(13) ==> rc,volpat
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    4,7 ==> n,rc
         CLR   7,6 ==> rc,count
         BNL   @@L68
@@L66    EQU   *
         LR    3,4 ==> n
         MH    3,=H'4'
         L     2,4(11)
         L     3,0(3,2) ==> v
         LTR   3,3 ==> v
         BE    @@L61
         L     2,36(3) ==> .comment
         LTR   2,2
         BNE   @@L61
         ST    3,88(13) ==> v
         LA    2,104(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@PATMAT)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L61
         LR    2,5 ==> rec
         A     2,=F'39'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRDUP)
         BALR  14,15
         ST    15,36(3) ==> count,comment
@@L61    EQU   *
         A     4,=F'1' ==> n
         CLR   4,6 ==> n,count
         BL    @@L66
@@L68    EQU   *
         LR    15,7 ==> rc
* Function 'get_comment' epilogue
         PDPEPIL
* Function 'get_comment' literal pool
         DS    0D
         LTORG
* Function 'get_comment' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
@@LC2    EQU   *
         DC    C' '
         DC    X'0'
@@9      EQU   *
         DC    C'open_vatlst'
         DC    X'0'
         DS    0F
         EJECT
* static function 'open_vatlst' prologue
* frame base=88, local stack=56, call args=16
&FUNC    SETC  'open_vatlst'
@@6      PDPPRLG CINDEX=4,FRAME=160,BASER=12,ENTRY=NO
         B     @@FEN4
         LTORG
@@FEN4   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG4    EQU   *
         LR    11,1
         L     10,=A(@@PGT4)
* Function 'open_vatlst' code
         L     4,0(11) ==> vatlst
         SLR   3,3 ==> fp
         ST    4,88(13) ==> vatlst
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    2,15 ==> len
         LTR   15,15 ==> len
         BE    @@L71
         LA    5,104(,13)
         ST    5,88(13)
         ST    4,92(13) ==> vatlst
         MVC   96(4,13),=F'56'
         LA    1,88(,13)
         L     15,=V(STRNCPY)
         BALR  14,15
         STC   3,159(13) ==> fp,dsn
         LA    3,8(0,0)
         CR    2,3 ==> len
         BH    @@L73
         ST    4,88(13) ==> vatlst
         MVC   92(4,13),=F'75'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L73
         ST    4,88(13) ==> vatlst
         MVC   92(4,13),=F'77'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L73
         ST    5,88(13)
         MVC   92(4,13),=A(@@LC3)
         ST    4,96(13) ==> vatlst
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L73    EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    3,15 ==> fp
         LTR   15,15 ==> fp
         BNE   @@L71
         MVC   88(4,13),=A(@@LC5)
         MVC   92(4,13),=A(@@9)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L71    EQU   *
         LR    15,3 ==> fp
* Function 'open_vatlst' epilogue
         PDPEPIL
* Function 'open_vatlst' literal pool
         DS    0D
         LTORG
* Function 'open_vatlst' page table
@@PGT4   DS    0F
         DC    A(@@PG4)
@@LC3    EQU   *
         DC    C'SYS1.PARMLIB(%s)'
         DC    X'0'
@@LC4    EQU   *
         DC    C'r'
         DC    X'0'
@@LC5    EQU   *
         DC    C'@@listvl:%s: unable to open "%s"'
         DC    X'0'
         DS    0F
         EJECT
* static function 'in_vollist' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'in_vollist'
@@3      PDPPRLG CINDEX=5,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN5
         LTORG
@@FEN5   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG5    EQU   *
         LR    11,1
         L     10,=A(@@PGT5)
* Function 'in_vollist' code
         L     7,4(11) ==> vol
         SLR   6,6 ==> found
         ST    11,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    5,15 ==> count
         LR    4,6 ==> n,found
         CLR   6,15 ==> found,count
         BNL   @@L79
@@L83    EQU   *
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(11)
         L     2,0(2,3)
         ST    2,88(13)
         ST    7,92(13) ==> vol
         MVC   96(4,13),=F'6'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> count
         BNE   @@L80
         LA    6,1(0,0) ==> found
         B     @@L79
@@L80    EQU   *
         A     4,=F'1' ==> n
         CLR   4,5 ==> n,count
         BL    @@L83
@@L79    EQU   *
         LR    15,6 ==> found
* Function 'in_vollist' epilogue
         PDPEPIL
* Function 'in_vollist' literal pool
         DS    0D
         LTORG
* Function 'in_vollist' page table
@@PGT5   DS    0F
         DC    A(@@PG5)
         END
