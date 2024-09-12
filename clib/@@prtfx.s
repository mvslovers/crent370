 TITLE '/home/mike/repos/crent370/clib/@@prtfx.c'
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
         
&FUNC    SETC '_out_buffer'
* Program text area
         DS    0F
         EJECT
* static function '_out_buffer' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '_out_buffer'
@@0      PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '_out_buffer' code
         L     3,0(11) ==> character
         L     15,8(11) ==> idx
         CL    15,12(11) ==> idx,maxlen
         BNL   @@L1
         L     2,4(11) ==> buffer
         STC   3,0(15,2) ==> character,idx
@@L1     EQU   *
* Function '_out_buffer' epilogue
         PDPEPIL
* Function '_out_buffer' literal pool
         DS    0D
         LTORG
* Function '_out_buffer' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC '_out_null'
         DS    0F
         EJECT
* static function '_out_null' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '_out_null'
@@1      PDPPRLG CINDEX=1,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function '_out_null' code
* Function '_out_null' epilogue
         PDPEPIL
* Function '_out_null' literal pool
         DS    0D
         LTORG
* Function '_out_null' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC '_out_char'
         DS    0F
         EJECT
* static function '_out_char' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '_out_char'
@@2      PDPPRLG CINDEX=2,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function '_out_char' code
         IC    2,3(11) ==> character
         CLM   2,1,=XL1'00' ==> character
         BE    @@L4
         LA    1,88(,13)
         L     15,=V(@@GTOUT)
         BALR  14,15
         N     2,=XL4'000000FF' ==> character
         ST    2,88(13) ==> character
         MVC   92(4,13),0(15)
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L4     EQU   *
* Function '_out_char' epilogue
         PDPEPIL
* Function '_out_char' literal pool
         DS    0D
         LTORG
* Function '_out_char' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
         
&FUNC    SETC '_out_fct'
         DS    0F
         EJECT
* static function '_out_fct' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '_out_fct'
@@3      PDPPRLG CINDEX=3,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function '_out_fct' code
         L     2,4(11) ==> buffer
         SLR   3,3 ==> character
         IC    3,3(11) ==> character
         ST    3,88(13) ==> character
         MVC   92(4,13),4(2) ==> .arg
         L     2,0(2) ==> .fct
         LA    1,88(,13)
         LA    15,0(2)
         BALR  14,15
* Function '_out_fct' epilogue
         PDPEPIL
* Function '_out_fct' literal pool
         DS    0D
         LTORG
* Function '_out_fct' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
         
&FUNC    SETC '_strlen'
         DS    0F
         EJECT
* static function '_strlen' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '_strlen'
@@4      PDPPRLG CINDEX=4,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN4
         LTORG
@@FEN4   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG4    EQU   *
         LR    11,1
         L     10,=A(@@PGT4)
* Function '_strlen' code
         L     3,0(11) ==> str
         LR    15,3 ==> s,str
         IC    2,0(3) ==> str
         CLM   2,1,=XL1'00'
         BE    @@L14
@@L12    EQU   *
         A     15,=F'1' ==> s
         IC    2,0(15) ==> s
         CLM   2,1,=XL1'00'
         BNE   @@L12
@@L14    EQU   *
         SR    15,3 ==> str
* Function '_strlen' epilogue
         PDPEPIL
* Function '_strlen' literal pool
         DS    0D
         LTORG
* Function '_strlen' page table
@@PGT4   DS    0F
         DC    A(@@PG4)
         
&FUNC    SETC '_is_digit'
         DS    0F
         EJECT
* static function '_is_digit' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '_is_digit'
@@5      PDPPRLG CINDEX=5,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN5
         LTORG
@@FEN5   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG5    EQU   *
         LR    11,1
         L     10,=A(@@PGT5)
* Function '_is_digit' code
         SLR   15,15
         IC    3,3(11) ==> ch
         LA    2,16(,3)
         CLM   2,1,=XL1'09'
         BH    @@L16
         LA    15,1(0,0)
@@L16    EQU   *
* Function '_is_digit' epilogue
         PDPEPIL
* Function '_is_digit' literal pool
         DS    0D
         LTORG
* Function '_is_digit' page table
@@PGT5   DS    0F
         DC    A(@@PG5)
         
&FUNC    SETC '_atoi'
         DS    0F
         EJECT
* static function '_atoi' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '_atoi'
@@6      PDPPRLG CINDEX=6,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN6
         LTORG
@@FEN6   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG6    EQU   *
         LR    11,1
         L     10,=A(@@PGT6)
* Function '_atoi' code
         L     5,0(11) ==> str
         SLR   4,4 ==> i
         B     @@L18
@@L21    EQU   *
         LR    2,4 ==> i
         SLL   2,3
         AR    2,4 ==> i
         AR    2,4 ==> i
         L     3,0(5) ==> str
         SLR   4,4
         IC    4,0(3)
         AR    2,4
         LR    4,2 ==> i
         A     4,=F'-240' ==> i
         A     3,=F'1'
         ST    3,0(5) ==> str
@@L18    EQU   *
         L     2,0(5) ==> str
         SLR   3,3
         IC    3,0(2)
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         LTR   15,15 ==> i
         BNE   @@L21
         LR    15,4 ==> i
* Function '_atoi' epilogue
         PDPEPIL
* Function '_atoi' literal pool
         DS    0D
         LTORG
* Function '_atoi' page table
@@PGT6   DS    0F
         DC    A(@@PG6)
         
&FUNC    SETC '_ntoa_format'
         DS    0F
         EJECT
* static function '_ntoa_format' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '_ntoa_format'
@@7      PDPPRLG CINDEX=7,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN7
         LTORG
@@FEN7   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG7    EQU   *
         LR    11,1
         L     10,=A(@@PGT7)
* Function '_ntoa_format' code
         L     5,8(11) ==> idx
         L     9,12(11) ==> maxlen
         L     6,16(11) ==> buf
         L     4,20(11) ==> len
         L     15,32(11) ==> prec
         L     7,36(11) ==> width
         L     8,40(11) ==> flags
         ST    5,104(13) ==> idx,start_idx
         LR    2,8 ==> flags
         N     2,=F'2'
         LTR   2,2
         BNE   @@L23
         CLR   4,15 ==> len,prec
         BNL   @@L25
         LA    2,31(0,0)
         CLR   4,2 ==> len
         BH    @@L25
@@L28    EQU   *
         L     3,=F'-16'
         STC   3,0(4,6) ==> len
         A     4,=F'1' ==> len
         CLR   4,15 ==> len,prec
         BNL   @@L25
         LA    2,31(0,0)
         CLR   4,2 ==> len
         BNH   @@L28
@@L25    EQU   *
         LR    2,8 ==> flags
         N     2,=F'1'
         LR    3,2
         LTR   2,2
         BE    @@L23
         CLR   4,7 ==> len,width
         BNL   @@L23
         LA    2,31(0,0)
         CLR   4,2 ==> len
         BH    @@L23
@@L33    EQU   *
         L     2,=F'-16'
         STC   2,0(4,6) ==> len
         A     4,=F'1' ==> len
         LTR   3,3
         BE    @@L23
         CLR   4,7 ==> len,width
         BNL   @@L23
         LA    2,31(0,0)
         CLR   4,2 ==> len
         BNH   @@L33
@@L23    EQU   *
         LR    2,8 ==> flags
         N     2,=F'16'
         LTR   2,2
         BE    @@L34
         LR    2,8 ==> flags
         N     2,=F'1024'
         LTR   2,2
         BNE   @@L35
         LTR   4,4 ==> len
         BE    @@L35
         CLR   4,15 ==> len,prec
         BE    @@L36
         CLR   4,7 ==> len,width
         BNE   @@L35
@@L36    EQU   *
         BCTR  4,0 ==> len
         LTR   4,4 ==> len
         BE    @@L35
         L     15,28(11) ==> base
         LA    3,16(0,0)
         CLR   15,3
         BNE   @@L35
         BCTR  4,0 ==> len
@@L35    EQU   *
         L     3,28(11) ==> base
         LA    2,16(0,0)
         CLR   3,2
         BNE   @@L38
         LR    2,8 ==> flags
         N     2,=F'32'
         LTR   2,2
         BNE   @@L38
         LA    15,31(0,0)
         CLR   4,15 ==> len
         BH    @@L38
         L     2,=F'-89'
         STC   2,0(4,6) ==> len
         B     @@L74
@@L38    EQU   *
         L     15,28(11) ==> base
         LA    3,16(0,0)
         CLR   15,3
         BNE   @@L40
         LR    2,8 ==> flags
         N     2,=F'32'
         LTR   2,2
         BE    @@L40
         LA    2,31(0,0)
         CLR   4,2 ==> len
         BH    @@L40
         L     3,=F'-25'
         STC   3,0(4,6) ==> len
         B     @@L74
@@L40    EQU   *
         L     2,28(11) ==> base
         LA    15,2(0,0)
         CLR   2,15
         BNE   @@L39
         LA    3,31(0,0)
         CLR   4,3 ==> len
         BH    @@L39
         L     15,=F'-126'
         STC   15,0(4,6) ==> len
@@L74    EQU   *
         A     4,=F'1' ==> len
@@L39    EQU   *
         LA    2,31(0,0)
         CLR   4,2 ==> len
         BH    @@L34
         L     3,=F'-16'
         STC   3,0(4,6) ==> len
         A     4,=F'1' ==> len
@@L34    EQU   *
         LTR   4,4 ==> len
         BE    @@L44
         CLR   4,7 ==> len,width
         BNE   @@L44
         L     15,24(11) ==> negative
         LTR   15,15
         BNE   @@L45
         LR    2,8 ==> flags
         N     2,=F'12'
         LTR   2,2
         BE    @@L44
@@L45    EQU   *
         BCTR  4,0 ==> len
@@L44    EQU   *
         LA    2,31(0,0)
         CLR   4,2 ==> len
         BH    @@L46
         L     3,24(11) ==> negative
         LTR   3,3
         BE    @@L47
         LA    15,96(0,0)
         STC   15,0(4,6) ==> len
         B     @@L75
@@L47    EQU   *
         LR    2,8 ==> flags
         N     2,=F'4'
         LTR   2,2
         BE    @@L49
         LA    2,78(0,0)
         STC   2,0(4,6) ==> len
         B     @@L75
@@L49    EQU   *
         LR    2,8 ==> flags
         N     2,=F'8'
         LTR   2,2
         BE    @@L46
         LA    3,64(0,0)
         STC   3,0(4,6) ==> len
@@L75    EQU   *
         A     4,=F'1' ==> len
@@L46    EQU   *
         LR    2,8 ==> flags
         N     2,=F'3'
         LTR   2,2
         BNE   @@L52
         LR    3,4 ==> i,len
         CLR   4,7 ==> len,width
         BNL   @@L52
@@L57    EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         ST    5,96(13) ==> idx
         A     5,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         L     15,0(11) ==> out
         LA    1,88(,13)
         LA    15,0(15)
         BALR  14,15
         A     3,=F'1' ==> i
         CLR   3,7 ==> i,width
         BL    @@L57
@@L52    EQU   *
         SLR   3,3 ==> i
         CLR   3,4 ==> i,len
         BNL   @@L72
@@L62    EQU   *
         LR    2,4 ==> len
         SR    2,3 ==> i
         AR    2,6 ==> buf
         BCTR  2,0
         SLR   15,15
         IC    15,0(2)
         ST    15,88(13)
         MVC   92(4,13),4(11) ==> buffer
         ST    5,96(13) ==> idx
         A     5,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         L     2,0(11) ==> out
         LA    1,88(,13)
         LA    15,0(2)
         BALR  14,15
         A     3,=F'1' ==> i
         CLR   3,4 ==> i,len
         BL    @@L62
@@L72    EQU   *
         LR    2,8 ==> flags
         N     2,=F'2'
         LTR   2,2
         BE    @@L63
         LR    2,5 ==> idx
         S     2,104(13) ==> start_idx
         CLR   2,7 ==> width
         BNL   @@L63
@@L67    EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         ST    5,96(13) ==> idx
         A     5,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         L     3,0(11) ==> out
         LA    1,88(,13)
         LA    15,0(3)
         BALR  14,15
         LR    2,5 ==> idx
         S     2,104(13) ==> start_idx
         CLR   2,7 ==> width
         BL    @@L67
@@L63    EQU   *
         LR    15,5 ==> idx
* Function '_ntoa_format' epilogue
         PDPEPIL
* Function '_ntoa_format' literal pool
         DS    0D
         LTORG
* Function '_ntoa_format' page table
@@PGT7   DS    0F
         DC    A(@@PG7)
         
&FUNC    SETC '_ntoa_long'
         DS    0F
         EJECT
* static function '_ntoa_long' prologue
* frame base=88, local stack=40, call args=48
&FUNC    SETC  '_ntoa_long'
@@8      PDPPRLG CINDEX=8,FRAME=176,BASER=12,ENTRY=NO
         B     @@FEN8
         LTORG
@@FEN8   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG8    EQU   *
         LR    11,1
         L     10,=A(@@PGT8)
* Function '_ntoa_long' code
         SLR   6,6 ==> value
         SLR   7,7 ==> value
         L     9,16(11) ==> value
         MVC   168(4,13),=F'0' ==> len
         LTR   9,9 ==> value
         BNE   @@L77
         NC    36(4,11),=F'-17' ==> flags
@@L77    EQU   *
         L     2,36(11) ==> flags
         N     2,=F'1024'
         LTR   2,2
         BE    @@L79
         LTR   9,9 ==> value
         BE    @@L78
@@L79    EQU   *
         MVC   172(4,13),24(11) ==> base
@@L80    EQU   *
         LR    6,9 ==> value
         L     2,24(11) ==> base
         CLR   2,9
         BH    @@L85
         LTR   2,2
         BL    @@L84
         LA    3,1(0,0)
         CLR   2,3
         BE    @@L83
         SRDL  6,32 ==> value
         DR    6,2 ==> value
         B     @@L85
@@L83    EQU   *
         SLR   6,6
         B     @@L85
@@L84    EQU   *
         S     6,172(13)
@@L85    EQU   *
         LA    2,136(,13)
         L     8,168(13) ==> len
         AR    8,2
         L     2,168(13) ==> len
         A     2,=F'1'
         ST    2,168(13) ==> len
         LA    15,240(,6) ==> digit
         CLM   6,1,=XL1'09' ==> digit
         BNH   @@L87
         L     2,36(11) ==> flags
         N     2,=F'32'
         LA    15,183(,6) ==> digit
         LTR   2,2
         BNE   @@L87
         LA    15,119(,6) ==> digit
@@L87    EQU   *
         STC   15,0(8) ==> buf
         LR    4,9 ==> value
         SLR   5,5 ==> value
         L     3,24(11) ==> base
         CLR   3,9
         BH    @@L92
         LTR   3,3
         BL    @@L91
         LA    2,1(0,0)
         CLR   3,2
         BE    @@L90
         SRDL  4,32 ==> value
         DR    4,3 ==> value
         B     @@L92
@@L90    EQU   *
         LR    5,9 ==> value
         B     @@L92
@@L91    EQU   *
         LA    5,1(0,0) ==> value
@@L92    EQU   *
         LR    9,5 ==> value
         LTR   5,5 ==> value
         BE    @@L78
         L     2,168(13) ==> len
         LA    3,31(0,0)
         CLR   2,3
         BNH   @@L80
@@L78    EQU   *
         MVC   88(4,13),0(11) ==> out
         MVC   92(4,13),4(11) ==> buffer
         MVC   96(4,13),8(11) ==> idx
         MVC   100(4,13),12(11) ==> maxlen
         LA    2,136(,13)
         ST    2,104(13)
         MVC   108(4,13),168(13) ==> len
         MVC   112(4,13),20(11) ==> negative
         MVC   116(4,13),24(11) ==> base
         MVC   120(4,13),28(11) ==> prec
         MVC   124(4,13),32(11) ==> width
         MVC   128(4,13),36(11) ==> flags
         LA    1,88(,13)
         L     15,=A(@@7)
         BALR  14,15
* Function '_ntoa_long' epilogue
         PDPEPIL
* Function '_ntoa_long' literal pool
         DS    0D
         LTORG
* Function '_ntoa_long' page table
@@PGT8   DS    0F
         DC    A(@@PG8)
         
&FUNC    SETC '_ntoa_long_long'
         DS    0F
         EJECT
* static function '_ntoa_long_long' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '_ntoa_long_long'
@@9      PDPPRLG CINDEX=9,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN9
         LTORG
@@FEN9   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG9    EQU   *
         LR    11,1
         L     10,=A(@@PGT9)
* Function '_ntoa_long_long' code
         SLR   15,15
* Function '_ntoa_long_long' epilogue
         PDPEPIL
* Function '_ntoa_long_long' literal pool
         DS    0D
         LTORG
* Function '_ntoa_long_long' page table
@@PGT9   DS    0F
         DC    A(@@PG9)
         
&FUNC    SETC '_ftoa'
         DS    0F
@@11     EQU   *
         DC    F'1091567616'
         DC    F'0'
         DC    F'1101004800'
         DC    F'0'
         DC    F'1113849856'
         DC    F'0'
         DC    F'1128169472'
         DC    F'0'
         DC    F'1143410688'
         DC    F'0'
         DC    F'1159227904'
         DC    F'0'
         DC    F'1173627904'
         DC    F'0'
         DC    F'1184405120'
         DC    F'0'
         DC    F'1197432336'
         DC    F'0'
         DC    F'1211865802'
         DC    F'0'
         DS    0F
         EJECT
* static function '_ftoa' prologue
* frame base=88, local stack=72, call args=16
&FUNC    SETC  '_ftoa'
@@10     PDPPRLG CINDEX=10,FRAME=176,BASER=12,ENTRY=NO
         B     @@FEN10
         LTORG
@@FEN10  EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG10   EQU   *
         LR    11,1
         L     10,=A(@@PGT10)
* Function '_ftoa' code
         SLR   2,2
         SLR   3,3
         ST    2,144(13)
         ST    3,4+144(13)
         ST    2,152(13)
         ST    3,4+152(13)
         ST    2,160(13)
         ST    3,4+160(13)
         LR    8,2 ==> whole
         LR    9,3 ==> whole
         LD    4,16(11) ==> value
         L     4,24(11) ==> prec
         MVC   136(4,13),8(11) ==> start_idx,idx
         SLR   6,6 ==> len
         ST    6,140(13) ==> len,negative
         LTDR  4,4 ==> value
         BNL   @@L97
         MVC   140(4,13),=F'1' ==> negative
         LCDR  4,4 ==> value
@@L97    EQU   *
         L     2,32(11) ==> flags
         N     2,=F'1024'
         LTR   2,2
         BNE   @@L99
         LA    4,6(0,0) ==> prec
@@L99    EQU   *
         LA    3,31(0,0)
         CLR   6,3 ==> len
         BH    @@L101
         LA    5,9(0,0)
         CLR   4,5 ==> prec
         BNH   @@L101
         LA    2,104(,13)
@@L104   EQU   *
         L     15,=F'-16'
         STC   15,0(2,6) ==> buf
         A     6,=F'1' ==> len
         BCTR  4,0 ==> prec
         LA    3,31(0,0)
         CLR   6,3 ==> len
         BH    @@L101
         LA    5,9(0,0)
         CLR   4,5 ==> prec
         BH    @@L104
@@L101   EQU   *
         LDR   0,4 ==> value
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     7,84(,13) ==> whole
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    7,84(,13) ==> whole
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LDR   2,4 ==> tmp,value
         SDR   2,0 ==> tmp
         LR    3,4 ==> prec
         MH    3,=H'8'
         L     2,=A(@@11)
         MD    2,0(3,2) ==> tmp,pow10
         LDR   0,2 ==> tmp
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     5,84(,13) ==> frac
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    5,84(,13) ==> frac
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LTR   5,5 ==> frac
         BNL   @@L105
         AD    0,=D'4.294967296E9'
@@L105   EQU   *
         SDR   2,0 ==> tmp
         CD    2,=D'5.0E-1' ==> diff
         BNH   @@L106
         A     5,=F'1' ==> frac
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    5,84(,13) ==> frac
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LTR   5,5 ==> frac
         BNL   @@L109
         AD    0,=D'4.294967296E9'
@@L109   EQU   *
         LR    3,4 ==> prec
         MH    3,=H'8'
         L     2,=A(@@11)
         CD    0,0(3,2) ==> pow10
         BL    @@L111
         SLR   5,5 ==> frac
         A     7,=F'1' ==> whole
         B     @@L111
@@L106   EQU   *
         CD    2,=D'5.0E-1' ==> diff
         BNE   @@L111
         LTR   5,5 ==> frac
         BE    @@L114
         LR    2,5 ==> frac
         N     2,=F'1'
         LTR   2,2
         BE    @@L111
@@L114   EQU   *
         A     5,=F'1' ==> frac
@@L111   EQU   *
         SLR   15,15 ==> idx
         CD    4,=D'2.147483647E9' ==> value
         BH    @@L96
         LTR   4,4 ==> prec
         BNE   @@L117
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    7,84(,13) ==> whole
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         SDR   4,0 ==> value
         CD    4,=D'5.0E-1' ==> diff
         BH    @@L189
         BNE   @@L123
         LR    2,7 ==> whole
         N     2,=F'1'
         LTR   2,2
         BE    @@L123
@@L189   EQU   *
         A     7,=F'1' ==> whole
         B     @@L123
@@L117   EQU   *
         ST    4,168(13) ==> prec,count
         LA    15,31(0,0)
         CLR   6,15 ==> len
         BH    @@L125
         LA    4,104(,13)
@@L128   EQU   *
         L     2,168(13) ==> count
         BCTR  2,0
         ST    2,168(13) ==> count
         ST    5,144(13) ==> frac
         L     2,144(13)
         L     3,4+144(13)
         SRDL  2,32
         LA    15,10(0,0)
         DR    2,15
         ST    2,144(13)
         ST    3,4+144(13)
         IC    3,147(13)
         LA    2,240(,3)
         STC   2,0(4,6) ==> buf
         A     6,=F'1' ==> len
         ST    5,152(13) ==> frac
         L     2,152(13)
         L     3,4+152(13)
         SRDL  2,32
         DR    2,15
         ST    2,152(13)
         ST    3,4+152(13)
         LR    5,3 ==> frac
         L     15,156(13)
         LTR   15,15
         BE    @@L125
         LA    2,31(0,0)
         CLR   6,2 ==> len
         BNH   @@L128
@@L125   EQU   *
         LA    3,31(0,0)
         CLR   6,3 ==> len
         BH    @@L130
         L     2,168(13) ==> count
         LR    4,2 ==> count
         BCTR  4,0
         ST    4,168(13) ==> count
         LTR   2,2 ==> count
         BE    @@L130
         LA    4,104(,13)
@@L133   EQU   *
         L     5,=F'-16'
         STC   5,0(4,6) ==> buf
         A     6,=F'1' ==> len
         LA    15,31(0,0)
         CLR   6,15 ==> len
         BH    @@L130
         L     2,168(13) ==> count
         LR    3,2 ==> count
         BCTR  3,0
         ST    3,168(13) ==> count
         LTR   2,2 ==> count
         BNE   @@L133
@@L130   EQU   *
         LA    4,31(0,0)
         CLR   6,4 ==> len
         BH    @@L123
         LA    5,75(0,0)
         STC   5,104(6,13) ==> buf
         A     6,=F'1' ==> len
@@L123   EQU   *
         L     2,32(11) ==> i,flags
         N     2,=F'2048' ==> i
         LTR   2,2 ==> i
         BNE   @@L135
         LR    3,2 ==> i
         CLR   2,6 ==> i,len
         BNL   @@L137
@@L141   EQU   *
         IC    2,104(13,3) ==> buf
         CLM   2,1,=XL1'F0'
         BNE   @@L137
         A     3,=F'1' ==> i
         CLR   3,6 ==> i,len
         BL    @@L141
@@L137   EQU   *
         IC    2,104(13,3) ==> buf
         CLM   2,1,=XL1'4B'
         BNE   @@L142
         SLR   6,6 ==> len
         B     @@L135
@@L142   EQU   *
         SR    6,3 ==> len,i
         LA    2,104(,13)
         ST    2,88(13)
         AR    2,3 ==> i
         ST    2,92(13)
         ST    6,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L135   EQU   *
         LA    15,31(0,0)
         CLR   6,15 ==> len
         BH    @@L145
         LA    4,104(,13)
         L     15,=F'-16'
@@L148   EQU   *
         ST    7,160(13) ==> whole
         L     2,160(13)
         L     3,4+160(13)
         SRDA  2,32
         LA    5,10(0,0)
         DR    2,5
         ST    2,160(13)
         ST    3,4+160(13)
         IC    3,163(13)
         LA    2,0(15,3)
         STC   2,0(4,6) ==> buf
         A     6,=F'1' ==> len
         LR    8,7 ==> whole
         SRDA  8,32 ==> whole
         DR    8,5 ==> whole
         LR    7,9 ==> whole
         LTR   9,9 ==> whole
         BE    @@L145
         LA    5,31(0,0)
         CLR   6,5 ==> len
         BNH   @@L148
@@L145   EQU   *
         L     2,32(11) ==> flags
         N     2,=F'3'
         LA    15,1(0,0)
         CLR   2,15
         BNE   @@L149
         CL    6,28(11) ==> len,width
         BNL   @@L149
         LA    2,31(0,0)
         CLR   6,2 ==> len
         BH    @@L149
         LA    2,104(,13)
@@L154   EQU   *
         L     3,=F'-16'
         STC   3,0(2,6) ==> buf
         A     6,=F'1' ==> len
         CL    6,28(11) ==> len,width
         BNL   @@L149
         LA    4,31(0,0)
         CLR   6,4 ==> len
         BNH   @@L154
@@L149   EQU   *
         CL    6,28(11) ==> len,width
         BNE   @@L155
         L     5,140(13) ==> negative
         LTR   5,5
         BNE   @@L156
         L     2,32(11) ==> flags
         N     2,=F'12'
         LTR   2,2
         BE    @@L155
@@L156   EQU   *
         BCTR  6,0 ==> len
@@L155   EQU   *
         LA    15,31(0,0)
         CLR   6,15 ==> len
         BH    @@L157
         L     2,140(13) ==> negative
         LTR   2,2
         BE    @@L158
         LA    3,96(0,0)
         STC   3,104(6,13) ==> buf
         B     @@L190
@@L158   EQU   *
         L     2,32(11) ==> flags
         N     2,=F'4'
         LTR   2,2
         BE    @@L160
         LA    4,78(0,0)
         STC   4,104(6,13) ==> buf
         B     @@L190
@@L160   EQU   *
         L     2,32(11) ==> flags
         N     2,=F'8'
         LTR   2,2
         BE    @@L157
         LA    5,64(0,0)
         STC   5,104(6,13) ==> buf
@@L190   EQU   *
         A     6,=F'1' ==> len
@@L157   EQU   *
         L     2,32(11) ==> flags
         N     2,=F'3'
         LTR   2,2
         BNE   @@L163
         LR    3,6 ==> i,len
         CL    6,28(11) ==> len,width
         BNL   @@L163
@@L168   EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         MVC   96(4,13),8(11) ==> idx
         L     15,8(11) ==> idx
         A     15,=F'1'
         ST    15,8(11) ==> idx
         MVC   100(4,13),12(11) ==> maxlen
         L     2,0(11) ==> out
         LA    1,88(,13)
         LA    15,0(2)
         BALR  14,15
         A     3,=F'1' ==> i
         CL    3,28(11) ==> i,width
         BL    @@L168
@@L163   EQU   *
         SLR   3,3 ==> i
         CLR   3,6 ==> i,len
         BNL   @@L187
@@L173   EQU   *
         LR    2,6 ==> len
         SR    2,3 ==> i
         SLR   4,4
         IC    4,103(2,13) ==> buf
         ST    4,88(13)
         MVC   92(4,13),4(11) ==> buffer
         MVC   96(4,13),8(11) ==> idx
         L     5,8(11) ==> idx
         A     5,=F'1'
         ST    5,8(11) ==> idx
         MVC   100(4,13),12(11) ==> maxlen
         L     15,0(11) ==> out
         LA    1,88(,13)
         LA    15,0(15)
         BALR  14,15
         A     3,=F'1' ==> i
         CLR   3,6 ==> i,len
         BL    @@L173
@@L187   EQU   *
         L     2,32(11) ==> flags
         N     2,=F'2'
         LTR   2,2
         BE    @@L174
         L     2,8(11) ==> idx
         S     2,136(13) ==> start_idx
         CL    2,28(11) ==> width
         BNL   @@L174
@@L178   EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         MVC   96(4,13),8(11) ==> idx
         L     2,8(11) ==> idx
         A     2,=F'1'
         ST    2,8(11) ==> idx
         MVC   100(4,13),12(11) ==> maxlen
         L     3,0(11) ==> out
         LA    1,88(,13)
         LA    15,0(3)
         BALR  14,15
         L     2,8(11) ==> idx
         S     2,136(13) ==> start_idx
         CL    2,28(11) ==> width
         BL    @@L178
@@L174   EQU   *
         L     15,8(11) ==> idx
@@L96    EQU   *
* Function '_ftoa' epilogue
         PDPEPIL
* Function '_ftoa' literal pool
         DS    0D
         LTORG
* Function '_ftoa' page table
@@PGT10  DS    0F
         DC    A(@@PG10)
         
&FUNC    SETC '_vsnprintf'
         DS    0F
         EJECT
* static function '_vsnprintf' prologue
* frame base=88, local stack=8, call args=40
&FUNC    SETC  '_vsnprintf'
@@12     PDPPRLG CINDEX=11,FRAME=136,BASER=12,ENTRY=NO
         B     @@FEN11
         LTORG
@@FEN11  EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG11   EQU   *
         LR    11,1
         L     10,=A(@@PGT11)
* Function '_vsnprintf' code
         L     7,0(11) ==> out
         L     9,8(11) ==> maxlen
         L     8,16(11) ==> va
         SLR   6,6 ==> idx
         L     2,4(11) ==> buffer
         LTR   2,2
         BNE   @@L192
         L     7,=A(@@1) ==> out
@@L192   EQU   *
         L     2,12(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         L     14,=A(@@L313)
         BER   14
@@L309   EQU   *
         L     12,0(,10)
         L     2,12(11)
         CLI   0(2),108
         L     14,=A(@@L327)
         BNER  14
         L     2,12(11)
         A     2,=F'1'
         ST    2,12(11)
         SLR   4,4 ==> flags
@@L197   EQU   *
         L     2,12(11)
         SLR   5,5
         IC    5,0(2)
         LR    2,5
         LA    15,96(0,0)
         CR    5,15
         BE    @@L202
         BH    @@L208
         LA    3,64(0,0)
         CLR   5,3
         BE    @@L204
         LA    5,78(0,0)
         CLR   2,5
         BE    @@L203
         B     @@L206
@@L208   EQU   *
         LA    15,123(0,0)
         CLR   5,15
         BE    @@L205
         LA    3,240(0,0)
         CLR   5,3
         BNE   @@L206
         O     4,=F'1' ==> flags
         B     @@L319
@@L202   EQU   *
         O     4,=F'2' ==> flags
         B     @@L319
@@L203   EQU   *
         O     4,=F'4' ==> flags
         B     @@L319
@@L204   EQU   *
         O     4,=F'8' ==> flags
         B     @@L319
@@L205   EQU   *
         O     4,=F'16' ==> flags
@@L319   EQU   *
         L     2,12(11)
         A     2,=F'1'
         ST    2,12(11)
         LA    2,1(0,0) ==> n
         B     @@L199
@@L206   EQU   *
         SLR   2,2 ==> n
@@L199   EQU   *
         LTR   2,2 ==> n
         BNE   @@L197
         MVC   128(4,13),=F'0' ==> width
         L     2,12(11)
         SLR   5,5
         IC    5,0(2)
         ST    5,88(13)
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         LTR   15,15 ==> width
         BE    @@L210
         LA    2,12(,11)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         ST    15,128(13) ==> width
         B     @@L211
@@L210   EQU   *
         L     2,12(11)
         IC    2,0(2)
         SLL   2,24
         SRA   2,24
         C     2,=F'92'
         BNE   @@L211
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         L     15,0(2) ==> w
         LTR   15,15 ==> w
         BNL   @@L213
         O     4,=F'2' ==> flags
         LCR   15,15 ==> w
@@L213   EQU   *
         ST    15,128(13) ==> w,width
         L     2,12(11)
         A     2,=F'1'
         ST    2,12(11)
@@L211   EQU   *
         MVC   132(4,13),=F'0' ==> precision
         L     2,12(11)
         CLI   0(2),75
         BNE   @@L215
         O     4,=F'1024' ==> flags
         A     2,=F'1'
         ST    2,12(11)
         SLR   15,15
         IC    15,0(2)
         ST    15,88(13)
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         LTR   15,15 ==> width
         BE    @@L216
         LA    2,12(,11)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         ST    15,132(13) ==> precision
         B     @@L215
@@L216   EQU   *
         L     2,12(11)
         IC    2,0(2)
         SLL   2,24
         SRA   2,24
         C     2,=F'92'
         BNE   @@L215
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         L     2,0(2) ==> prec
         ST    2,132(13) ==> prec,precision
         LTR   2,2 ==> prec
         BH    @@L220
         MVC   132(4,13),=F'0' ==> precision
@@L220   EQU   *
         L     2,12(11)
         A     2,=F'1'
         ST    2,12(11)
@@L215   EQU   *
         L     2,12(11)
         SLR   3,3
         IC    3,0(2)
         LR    2,3
         LA    5,145(0,0)
         CR    3,5
         BE    @@L227
         BH    @@L230
         LA    15,136(0,0)
         CLR   3,15
         BE    @@L224
         B     @@L221
@@L230   EQU   *
         LA    3,147(0,0)
         CLR   2,3
         BE    @@L222
         LA    5,169(0,0)
         CLR   2,5
         BE    @@L227
         B     @@L221
@@L222   EQU   *
         O     4,=F'256' ==> flags
         L     2,12(11)
         A     2,=F'1'
         ST    2,12(11)
         CLI   0(2),147
         BNE   @@L221
         O     4,=F'512' ==> flags
         B     @@L320
@@L224   EQU   *
         O     4,=F'128' ==> flags
         L     2,12(11)
         A     2,=F'1'
         ST    2,12(11)
         CLI   0(2),136
         BNE   @@L221
         O     4,=F'64' ==> flags
         B     @@L320
@@L227   EQU   *
         O     4,=F'256' ==> flags
         L     2,12(11)
@@L320   EQU   *
         A     2,=F'1'
         ST    2,12(11)
@@L221   EQU   *
         L     2,12(11)
         SLR   15,15
         IC    15,0(2)
         LR    2,15
         A     2,=F'-108'
         LA    3,123(0,0)
         CLR   2,3
         L     14,=A(@@L307)
         BHR   14
         LR    3,2
         MH    3,=H'4'
         L     2,=A(@@L308)
         L     14,0(3,2)
         BR    14
         DS    0F
         DS    0F
         DS    0F
         LTORG
         DS    0F
@@L308   EQU   *
         DC    A(@@L306)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L238)
         DC    A(@@L276)
         DC    A(@@L238)
         DC    A(@@L307)
         DC    A(@@L273)
         DC    A(@@L273)
         DC    A(@@L307)
         DC    A(@@L238)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L238)
         DC    A(@@L305)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L287)
         DC    A(@@L307)
         DC    A(@@L238)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L238)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L273)
         DC    A(@@L273)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L307)
         DC    A(@@L238)
@@L238   EQU   *
         L     2,12(11)
         IC    2,0(2)
         CLM   2,1,=XL1'A7'
         BE    @@L240
         CLM   2,1,=XL1'E7'
         BNE   @@L239
@@L240   EQU   *
         LA    5,16(0,0) ==> base
         B     @@L241
@@L239   EQU   *
         L     2,12(11)
         CLI   0(2),150
         BNE   @@L242
         LA    5,8(0,0) ==> base
         B     @@L241
@@L242   EQU   *
         L     2,12(11)
         CLI   0(2),130
         BNE   @@L244
         LA    5,2(0,0) ==> base
         B     @@L241
@@L244   EQU   *
         LA    5,10(0,0) ==> base
         N     4,=F'-17' ==> flags
@@L241   EQU   *
         L     2,12(11)
         CLI   0(2),231
         BNE   @@L246
         O     4,=F'32' ==> flags
@@L246   EQU   *
         L     2,12(11)
         IC    2,0(2)
         CLM   2,1,=XL1'89'
         BE    @@L247
         CLM   2,1,=XL1'84'
         BE    @@L247
         N     4,=F'-13' ==> flags
@@L247   EQU   *
         LR    2,4 ==> flags
         N     2,=F'1024'
         LTR   2,2
         BE    @@L248
         N     4,=F'-2' ==> flags
@@L248   EQU   *
         L     2,12(11)
         IC    2,0(2)
         CLM   2,1,=XL1'89'
         BE    @@L250
         CLM   2,1,=XL1'84'
         BNE   @@L249
@@L250   EQU   *
         LR    2,4 ==> flags
         N     2,=F'512'
         LTR   2,2
         L     14,=A(@@L324)
         BNER  14
         LR    2,4 ==> flags
         N     2,=F'256'
         LTR   2,2
         BE    @@L253
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         L     3,0(2) ==> value
         ST    7,88(13) ==> out
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         ST    9,100(13) ==> maxlen
         LPR   2,3 ==> value
         ST    2,104(13)
         SRL   3,31
         B     @@L322
@@L253   EQU   *
         LR    2,4 ==> flags
         N     2,=F'64'
         LTR   2,2
         BE    @@L256
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         SLR   3,3 ==> value
         IC    3,3(2) ==> value
         B     @@L257
@@L256   EQU   *
         LR    2,4 ==> flags
         N     2,=F'128'
         LTR   2,2
         BE    @@L258
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         LH    3,2(2) ==> value
         B     @@L257
@@L258   EQU   *
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         L     3,0(2) ==> value
@@L257   EQU   *
         ST    7,88(13) ==> out
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         ST    9,100(13) ==> maxlen
         LPR   2,3 ==> value
         ST    2,104(13)
         LR    2,3 ==> value
         SRL   2,31
         ST    2,108(13)
         B     @@L321
@@L249   EQU   *
         LR    3,4 ==> flags
         N     3,=F'512'
         LTR   3,3
         L     14,=A(@@L324)
         BNER  14
         LR    2,4 ==> flags
         N     2,=F'256'
         LTR   2,2
         BE    @@L264
         ST    7,88(13) ==> out
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         ST    9,100(13) ==> maxlen
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         MVC   104(4,13),0(2)
@@L322   EQU   *
         ST    3,108(13)
         B     @@L321
@@L264   EQU   *
         LR    2,4 ==> flags
         N     2,=F'64'
         LTR   2,2
         BE    @@L266
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         SLR   15,15
         IC    15,3(2)
         LR    2,15 ==> value
         B     @@L267
@@L266   EQU   *
         LR    2,4 ==> flags
         N     2,=F'128'
         LTR   2,2
         BE    @@L268
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         LH    2,2(2)
         N     2,=XL4'0000FFFF'
         B     @@L267
@@L268   EQU   *
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         L     2,0(2) ==> value
@@L267   EQU   *
         ST    7,88(13) ==> out
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         ST    9,100(13) ==> maxlen
         ST    2,104(13) ==> value
         MVC   108(4,13),=F'0'
@@L321   EQU   *
         ST    5,112(13) ==> base
         MVC   116(4,13),132(13) ==> precision
         MVC   120(4,13),128(13) ==> width
         L     14,=A(@@L328)
         BR    14
@@L273   EQU   *
         L     2,12(11)
         IC    2,0(2)
         CLM   2,1,=XL1'86'
         BE    @@L275
         CLM   2,1,=XL1'C6'
         BNE   @@L274
@@L275   EQU   *
         O     4,=F'2048' ==> flags
@@L274   EQU   *
         ST    7,88(13) ==> out
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         ST    9,100(13) ==> maxlen
         A     8,=F'8' ==> va
         LR    2,8 ==> va
         A     2,=F'-8'
         MVC   104(8,13),0(2)
         MVC   112(4,13),132(13) ==> precision
         MVC   116(4,13),128(13) ==> width
         ST    4,120(13) ==> flags
         LA    1,88(,13)
         L     15,=A(@@10)
         BALR  14,15
         L     14,=A(@@L326)
         BR    14
@@L276   EQU   *
         LA    3,1(0,0) ==> l
         LR    2,4 ==> flags
         N     2,=F'2'
         LTR   2,2
         BNE   @@L277
         LR    2,3 ==> l
         LA    3,2(0,0) ==> l
         CL    2,128(13) ==> l,width
         BNL   @@L277
@@L281   EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         A     6,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
         LR    2,3 ==> l
         A     3,=F'1' ==> l
         CL    2,128(13) ==> l,width
         BL    @@L281
@@L277   EQU   *
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         SLR   5,5
         IC    5,3(2)
         ST    5,88(13)
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         A     6,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
         LR    2,4 ==> flags
         N     2,=F'2'
         LTR   2,2
         L     14,=A(@@L324)
         BER   14
         LR    2,3 ==> l
         A     3,=F'1' ==> l
         CL    2,128(13) ==> l,width
         L     14,=A(@@L324)
         BNLR  14
@@L286   EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         A     6,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
         LR    2,3 ==> l
         A     3,=F'1' ==> l
         CL    2,128(13) ==> l,width
         BL    @@L286
         L     14,=A(@@L324)
         BR    14
@@L287   EQU   *
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         L     3,0(2) ==> p
         ST    3,88(13) ==> p
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         LR    5,15 ==> l
         LR    2,4 ==> flags
         N     2,=F'1024'
         LTR   2,2
         BE    @@L288
         L     2,132(13) ==> precision
         CLR   2,15 ==> precision,l
         BNH   @@L289
         LR    2,15 ==> precision,l
@@L289   EQU   *
         LR    5,2 ==> l,precision
@@L288   EQU   *
         LR    2,4 ==> flags
         N     2,=F'2'
         LTR   2,2
         BNE   @@L290
         LR    2,5 ==> l
         A     5,=F'1' ==> l
         CL    2,128(13) ==> l,width
         BNL   @@L290
@@L294   EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         A     6,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
         LR    2,5 ==> l
         A     5,=F'1' ==> l
         CL    2,128(13) ==> l,width
         BL    @@L294
@@L290   EQU   *
         IC    2,0(3) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L296
         LR    2,4 ==> flags
         N     2,=F'1024'
         LTR   2,2
         BE    @@L299
         L     15,132(13) ==> precision
         BCTR  15,0
         ST    15,132(13) ==> precision
         L     2,=F'-1'
         CLR   15,2
         BE    @@L296
@@L299   EQU   *
         SLR   2,2
         IC    2,0(3) ==> p
         ST    2,88(13)
         A     3,=F'1' ==> p
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         A     6,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
         IC    2,0(3) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L296
         LR    2,4 ==> flags
         N     2,=F'1024'
         LTR   2,2
         BE    @@L299
         L     15,132(13) ==> precision
         BCTR  15,0
         ST    15,132(13) ==> precision
         L     2,=F'-1'
         CLR   15,2
         BNE   @@L299
@@L296   EQU   *
         LR    2,4 ==> flags
         N     2,=F'2'
         LTR   2,2
         BE    @@L324
         LR    2,5 ==> l
         A     5,=F'1' ==> l
         CL    2,128(13) ==> l,width
         BNL   @@L324
@@L304   EQU   *
         MVC   88(4,13),=F'64'
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         A     6,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
         LR    2,5 ==> l
         A     5,=F'1' ==> l
         CL    2,128(13) ==> l,width
         BL    @@L304
         B     @@L324
@@L305   EQU   *
         ST    7,88(13) ==> out
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         ST    9,100(13) ==> maxlen
         A     8,=F'4' ==> va
         LR    2,8 ==> va
         A     2,=F'-4'
         MVC   104(4,13),0(2)
         MVC   108(4,13),=F'0'
         MVC   112(4,13),=F'16'
         MVC   116(4,13),132(13) ==> precision
         MVC   120(4,13),=F'8'
         O     4,=F'33' ==> flags
@@L328   EQU   *
         ST    4,124(13) ==> flags
         LA    1,88(,13)
         L     15,=A(@@8)
         BALR  14,15
@@L326   EQU   *
         LR    6,15 ==> idx
         B     @@L324
@@L306   EQU   *
         MVC   88(4,13),=F'108'
         B     @@L323
@@L307   EQU   *
         L     2,12(11)
@@L327   EQU   *
         SLR   3,3
         IC    3,0(2)
         ST    3,88(13)
@@L323   EQU   *
         MVC   92(4,13),4(11) ==> buffer
         ST    6,96(13) ==> idx
         A     6,=F'1' ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
@@L324   EQU   *
         L     2,12(11)
         A     2,=F'1'
         ST    2,12(11)
         L     2,12(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BNE   @@L309
@@L313   EQU   *
         MVC   88(4,13),=F'0'
         MVC   92(4,13),4(11) ==> buffer
         LR    2,9 ==> idx,maxlen
         BCTR  2,0 ==> idx
         CLR   6,9 ==> idx,maxlen
         BNL   @@L311
         LR    2,6 ==> idx
@@L311   EQU   *
         ST    2,96(13) ==> idx
         ST    9,100(13) ==> maxlen
         LA    1,88(,13)
         LA    15,0(7) ==> out
         BALR  14,15
         LR    15,6 ==> idx
* Function '_vsnprintf' epilogue
         PDPEPIL
* Function '_vsnprintf' literal pool
         DS    0D
         LTORG
* Function '_vsnprintf' page table
@@PGT11  DS    0F
         DC    A(@@PG11)
* Program data area
         DS    0F
@@13     EQU   *
         DC    A(@@0)
         DC    A(@@1)
         DC    A(@@2)
         DC    A(@@3)
         DC    A(@@4)
         DC    A(@@5)
         DC    A(@@6)
         DC    A(@@7)
         DC    A(@@8)
         DC    A(@@9)
         DC    A(@@10)
         DC    A(@@12)
* X-var __prtfx
         ENTRY @@PRTFX
         DS    0F
@@PRTFX  EQU   *
         DC    A(@@13)
         END
