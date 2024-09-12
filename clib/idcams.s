 TITLE '/home/mike/repos/crent370/clib/idcams.c'
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
         
&FUNC    SETC 'idcams'
* Program text area
         DS    0F
         EJECT
* external function 'idcams' prologue
* frame base=88, local stack=256, call args=16
&FUNC    SETC  'idcams'
IDCAMS   PDPPRLG CINDEX=0,FRAME=360,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'idcams' code
         LA    3,104(,13)
         ST    3,88(13)
         MVC   92(4,13),=F'256'
         MVC   96(4,13),0(11)
         LA    2,4(,11) ==> args
         ST    2,100(13) ==> args
         LA    1,88(,13)
         L     15,=V(VSNPRINT)
         BALR  14,15
         MVI   359(13),0 ==> cmds
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
* Function 'idcams' epilogue
         PDPEPIL
* Function 'idcams' literal pool
         DS    0D
         LTORG
* Function 'idcams' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         DS    0H
@@7      EQU   *
         DC    X'0000'
         
&FUNC    SETC 'link_idcams'
         DS    0F
         EJECT
* static function 'link_idcams' prologue
* frame base=88, local stack=8128, call args=16
&FUNC    SETC  'link_idcams'
@@6      PDPPRLG CINDEX=1,FRAME=8232,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'link_idcams' code
         L     2,=A(@@LC0)
         MVC   104(10,13),0(2) ==> ddname1
         L     2,=A(@@LC1)
         MVC   120(10,13),0(2) ==> ddname2
         L     4,=V(@@IDCEX) ==> iofunc
         LA    3,136(,13)
         LR    8,3
         L     9,=F'8000'
         SLR   6,6
         LR    7,6
         MVCL  8,6
         L     2,=F'8216'
         ST    3,0(2,13)
         L     2,=F'8220'
         AR    2,13
         MVC   0(4,2),0(11) ==> udata,cmds
         L     3,=F'8032'
         LA    7,104(,13)
         ST    7,104(13,3) ==> sysin
         ST    4,108(3,13) ==> iofunc,sysin
         L     2,=F'8216'
         AR    2,13
         ST    2,112(3,13) ==> sysin
         L     5,=F'8048'
         LA    6,120(,13)
         ST    6,104(13,5) ==> sysprint
         ST    4,108(5,13) ==> iofunc,sysprint
         ST    2,112(5,13) ==> sysprint
         L     4,=F'8064'
         LA    2,2(0,0)
         ST    2,104(13,4) ==> iolist
         LA    2,108(,13)
         AR    2,4
         AR    3,7
         MVC   0(12,2),0(3) ==> iolist,sysin
         AR    6,4
         AR    7,5
         MVC   0(12,6),0(7) ==> iolist,sysprint
         L     2,=F'8224'
         AR    2,13
         MVC   0(4,2),=F'0'
         L     2,=F'8096'
         L     3,=A(@@7)
         ST    3,104(13,2) ==> plist
         ST    3,108(2,13) ==> plist
         ST    3,112(2,13) ==> plist
         L     3,=F'-2147475480'
         AR    3,13
         ST    3,116(2,13) ==> plist
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=F'0'
         L     2,=F'8200'
         AR    2,13
         ST    2,96(13)
         L     2,=F'8224'
         AR    2,13
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@LINKDS)
         BALR  14,15
         LTR   15,15 ==> rc
         BNH   @@L3
         LCR   3,15 ==> rc
         L     2,=F'8224'
         AR    2,13
         ST    3,0(2)
@@L3     EQU   *
         LTR   15,15 ==> rc
         BNL   @@L5
         L     2,=F'8224'
         AR    2,13
         ST    15,0(2) ==> rc
@@L5     EQU   *
         L     2,=F'8224'
         AR    2,13
         L     15,0(2) ==> rc
* Function 'link_idcams' epilogue
         PDPEPIL
* Function 'link_idcams' literal pool
         DS    0D
         LTORG
* Function 'link_idcams' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@LC0    EQU   *
         DC    C'DDSYSIN   '
         DC    X'0'
@@LC1    EQU   *
         DC    C'DDSYSPRINT'
         DC    X'0'
@@LC2    EQU   *
         DC    C'IDCAMS'
         DC    X'0'
         ENTRY @@IDCEX
@@IDCEX  DS    0H
         SAVE  (14,12),,@@IDCEX
         LA    12,0(,15)           base register
         USING @@IDCEX,12          base register
         L     14,0(,1)            A(UDATA)
         L     15,0(,14)           A(NAB in C stack frame)
         ST    13,4(,15)           backward chain (prev)
         ST    15,8(,13)           forward chain (next)
         LR    13,15               our stack frame
         LA    15,88(,15)          minimal stack frame
         ST    15,76(13)           next available byte
* Now call our idcams io exit
         L     15,=A(@@IDCEXC)     A(__idcexc)
         BALR  14,15               call our C function
         L     13,4(,13)           get prev stack frame
         RETURN (14,12),RC=(15)    restore regs and return
         LTORG ,                   our literal pool
         DROP  12                  drop base register
         
&FUNC    SETC '__idcexc'
         DS    0F
         EJECT
* external function '__idcexc' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__idcexc'
@@IDCEXC PDPPRLG CINDEX=2,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function '__idcexc' code
         L     3,0(11) ==> udata
         L     5,8(11) ==> ioinfo
         SLR   4,4 ==> rc
         L     2,4(11) ==> ioflags
         SLR   6,6
         IC    6,0(2) ==> .op
         LR    2,6
         LA    6,4(0,0)
         CR    2,6
         BE    @@L7
         BNH   @@L7
         LA    6,8(0,0)
         CLR   2,6
         BNE   @@L7
         MVC   0(4,5),4(3) ==> .rec,cmds
         L     2,4(3) ==> .cmds
         LTR   2,2
         BE    @@L11
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         B     @@L12
@@L11    EQU   *
         SLR   15,15 ==> rc
@@L12    EQU   *
         ST    15,4(5) ==> rc,reclen
         L     2,4(3) ==> .cmds
         LTR   2,2
         BNE   @@L13
         LA    4,4(0,0) ==> rc
@@L13    EQU   *
         MVC   4(4,3),=F'0' ==> .cmds
@@L7     EQU   *
         LR    15,4 ==> rc
* Function '__idcexc' epilogue
         PDPEPIL
* Function '__idcexc' literal pool
         DS    0D
         LTORG
* Function '__idcexc' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
         END
