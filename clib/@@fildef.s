 TITLE '/home/mike/repos/crent370/clib/@@fildef.c'
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
* external function '__fildef' prologue
* frame base=88, local stack=1104, call args=16
&FUNC    SETC  '__fildef'
@@FILDEF PDPPRLG CINDEX=0,FRAME=1208,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fildef' code
         L     4,0(11) ==> fdddname
         L     3,4(11) ==> fnm
         LA    2,144(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'20'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
         MVI   144(13),20 ==> .len
         MVI   145(13),1 ==> .verb
         MVI   146(13),64 ==> .flag1
         LA    2,104(,13)
         ST    2,152(13) ==> .tu_list
         IC    2,0(4) ==> fdddname
         CLM   2,1,=XL1'00'
         BE    @@L2
         LA    2,168(,13)
         ST    2,104(13) ==> tu_list
         MVC   168(2,13),=H'1' ==> .key
         MVC   170(2,13),=H'1' ==> .numparms
         ST    4,88(13) ==> fdddname
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         STH   15,172(13) ==> err,parm1_len
         LA    2,174(,13)
         ST    2,88(13)
         ST    4,92(13) ==> fdddname
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         LA    2,168(,13)
         ST    2,104(13) ==> tu_list
         MVC   168(2,13),=H'85' ==> .key
         MVC   170(2,13),=H'1' ==> .numparms
         MVC   172(2,13),=H'8' ==> .parm1_len
         LA    2,174(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
@@L3     EQU   *
         LA    2,272(,13)
         ST    2,108(13) ==> tu_list
         MVC   272(2,13),=H'2' ==> .key
         MVC   274(2,13),=H'1' ==> .numparms
         ST    3,88(13) ==> fnm
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         STH   15,276(13) ==> err,parm1_len
         LA    2,278(,13)
         ST    2,88(13)
         ST    3,92(13) ==> fnm
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LA    2,376(,13)
         ST    2,112(13) ==> tu_list
         MVC   376(2,13),=H'4' ==> .key
         MVC   378(2,13),=H'1' ==> .numparms
         MVC   380(2,13),=H'1' ==> .parm1_len
         MVI   382(13),8 ==> .parm1
         MVC   116(4,13),=F'0' ==> tu_list
         MVC   120(4,13),=F'0' ==> tu_list
         MVC   124(4,13),=F'-2147483648' ==> tu_list
         LA    2,144(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BE    @@L4
         L     2,8(11) ==> mymode
         LTR   2,2 ==> mymode
         BE    @@L5
         MVI   382(13),4 ==> .parm1
         L     2,12(11) ==> modeType
         LA    3,5(0,0)
         CLR   2,3 ==> modeType
         BE    @@L5
         LA    2,480(,13)
         ST    2,116(13) ==> tu_list
         MVC   480(2,13),=H'73' ==> .key
         MVC   482(2,13),=H'1' ==> .numparms
         MVC   484(2,13),=H'1' ==> .parm1_len
         MVI   486(13),64 ==> .parm1
         LA    2,584(,13)
         ST    2,120(13) ==> tu_list
         MVC   584(2,13),=H'66' ==> .key
         MVC   586(2,13),=H'1' ==> .numparms
         MVC   588(2,13),=H'2' ==> .parm1_len
         MVI   590(13),0 ==> .parm1
         MVI   591(13),255 ==> .parm1
@@L5     EQU   *
         LA    2,144(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
         LR    3,15 ==> err
@@L4     EQU   *
         LTR   3,3 ==> err
         BE    @@L10
         LH    2,148(13) ==> .error_reason
         CH    2,=H'0'
         BE    @@L10
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         LH    2,148(13) ==> .error_reason
         SLL   2,16
         SRA   2,16
         ST    2,0(15) ==> err
@@L10    EQU   *
         IC    2,0(4) ==> fdddname
         CLM   2,1,=XL1'00'
         BNE   @@L11
         LTR   3,3 ==> err
         BNE   @@L11
         LH    2,168(13) ==> .key
         CLM   2,3,=H'85'
         BNE   @@L11
         ST    4,88(13) ==> fdddname
         LA    2,174(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         STC   3,8(4) ==> err
@@L11    EQU   *
         LR    15,3 ==> err
* Function '__fildef' epilogue
         PDPEPIL
* Function '__fildef' literal pool
         DS    0D
         LTORG
* Function '__fildef' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
