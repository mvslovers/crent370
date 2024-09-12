 TITLE '/home/mike/repos/crent370/clib/@@vsopen.c'
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
* external function '__vsopen' prologue
* frame base=88, local stack=72, call args=16
&FUNC    SETC  '__vsopen'
@@VSOPEN PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vsopen' code
         L     7,4(11) ==> t
         L     8,8(11) ==> a
         L     9,12(11) ==> m
         SLR   2,2 ==> vs
         ST    2,168(13) ==> vs
         LR    6,2 ==> vs
         LA    4,104(,13)
         LA    5,64(0,0)
         LR    3,2 ==> vs
         MVCL  4,2 ==> vs
         LA    2,1(0,0)
         CLR   7,2 ==> t
         BE    @@L3
         LTR   7,7 ==> t
         BNE   @@L4
         LTR   8,8 ==> a
         BE    @@L55
         LA    2,2(0,0)
         B     @@L56
@@L4     EQU   *
         LA    2,2(0,0)
         CLR   7,2 ==> t
         BNE   @@L3
@@L56    EQU   *
         CLR   8,2 ==> a
         BNE   @@L3
         LA    2,1(0,0)
@@L55    EQU   *
         CLR   9,2 ==> m
         BE    @@L41
@@L3     EQU   *
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'192'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    6,15 ==> vs
         LTR   15,15 ==> vs
         BNE   @@L15
         MVC   168(4,13),=F'12'
         B     @@L7
@@L15    EQU   *
         ST    15,88(13) ==> vs
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LR    2,6 ==> vs
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),0(11) ==> ddname
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         STC   7,21(6) ==> t,type
         STC   8,22(6) ==> a,access
         STC   9,23(6) ==> m,mode
         ST    6,184(6) ==> vs,vsself
         LR    5,6 ==> acb,vs
         A     5,=F'24' ==> acb
         MVC   0($ACBLEN,5),ACBMODEL    Copy prototype ACB ==> acb
         A     2,=F'56'
         ST    2,88(13)
         A     2,=F'-56'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         A     2,=F'96'
         MVC   0($RPLLEN,2),RPLMODEL    Copy prototype RPL
         LR    4,6 ==> vs
         A     4,=F'104'
         LR    3,6 ==> vs
         A     3,=F'24'
         LA    2,104(,13)
         MODCB RPL=(4),ACB=((3)),MF=(G,(2))
         LA    2,1(0,0)
         CLR   7,2 ==> t
         BE    @@L19
         BL    @@L18
         LA    2,2(0,0)
         CLR   7,2 ==> t
         BNE   @@L20
@@L18    EQU   *
         LR    2,6 ==> vs
         A     2,=F'24'
         LA    3,104(,13)
         MODCB ACB=(2),MACRF=(KEY),MF=(G,(3))
         A     2,=F'80'
         MODCB RPL=(2),OPTCD=(KEY),MF=(G,(3))
         B     @@L16
@@L19    EQU   *
         LR    2,6 ==> vs
         A     2,=F'24'
         LA    3,104(,13)
         MODCB ACB=(2),MACRF=(ADR),MF=(G,(3))
         A     2,=F'80'
         MODCB RPL=(2),OPTCD=(ADR),MF=(G,(3))
         B     @@L16
@@L20    EQU   *
         MVC   168(4,13),=F'150'
         B     @@L7
@@L16    EQU   *
         LA    2,1(0,0)
         CLR   8,2 ==> a
         BE    @@L24
         BL    @@L23
         LA    2,2(0,0)
         CLR   8,2 ==> a
         BE    @@L25
         LA    2,3(0,0)
         CLR   8,2 ==> a
         BE    @@L26
         B     @@L27
@@L23    EQU   *
         LR    3,6 ==> vs
         A     3,=F'24'
         LA    2,104(,13)
         MODCB ACB=(3),MACRF=(DIR),MF=(G,(2))
         B     @@L22
@@L24    EQU   *
         LR    3,6 ==> vs
         A     3,=F'24'
         LA    2,104(,13)
         MODCB ACB=(3),MACRF=(SEQ),MF=(G,(2))
         B     @@L22
@@L25    EQU   *
         LR    3,6 ==> vs
         A     3,=F'24'
         LA    2,104(,13)
         MODCB ACB=(3),MACRF=(SEQ,DIR),MF=(G,(2))
         B     @@L22
@@L26    EQU   *
         LR    3,6 ==> vs
         A     3,=F'24'
         LA    2,104(,13)
         MODCB ACB=(3),MACRF=(ADR),MF=(G,(2))
         B     @@L22
@@L27    EQU   *
         MVC   168(4,13),=F'151'
         B     @@L7
@@L22    EQU   *
         LA    2,2(0,0)
         CLR   8,2 ==> a
         BH    @@L36
         LA    2,1(0,0)
         CLR   8,2 ==> a
         BNL   @@L32
         B     @@L30
@@L36    EQU   *
         LA    2,3(0,0)
         CLR   8,2 ==> a
         BE    @@L33
         B     @@L29
@@L30    EQU   *
         LR    3,6 ==> vs
         A     3,=F'104'
         LA    2,104(,13)
         MODCB RPL=(3),OPTCD=(DIR),MF=(G,(2))
         B     @@L29
@@L32    EQU   *
         LR    3,6 ==> vs
         A     3,=F'104'
         LA    2,104(,13)
         MODCB RPL=(3),OPTCD=(SEQ),MF=(G,(2))
         B     @@L29
@@L33    EQU   *
         LR    3,6 ==> vs
         A     3,=F'104'
         LA    2,104(,13)
         MODCB RPL=(3),OPTCD=(ADR),MF=(G,(2))
@@L29    EQU   *
         LTR   9,9 ==> m
         BE    @@L38
         LA    2,2(0,0)
         CLR   9,2 ==> m
         BH    @@L41
         B     @@L40
@@L38    EQU   *
         LR    3,6 ==> vs
         A     3,=F'24'
         LA    2,104(,13)
         MODCB ACB=(3),MACRF=(IN),MF=(G,(2))
         B     @@L37
@@L40    EQU   *
         LR    3,6 ==> vs
         A     3,=F'24'
         LA    2,104(,13)
         MODCB ACB=(3),MACRF=(OUT),MF=(G,(2))
         B     @@L37
@@L41    EQU   *
         MVC   168(4,13),=F'152'
         B     @@L7
@@L37    EQU   *
         LA    2,1(0,0)
         CLR   9,2 ==> m
         BNH   @@L45
         LA    2,2(0,0)
         CLR   9,2 ==> m
         BE    @@L46
         B     @@L43
@@L45    EQU   *
         LR    3,6 ==> vs
         A     3,=F'104'
         LA    2,104(,13)
         MODCB RPL=(3),OPTCD=(NUP),MF=(G,(2))
         B     @@L43
@@L46    EQU   *
         LR    3,6 ==> vs
         A     3,=F'104'
         LA    2,104(,13)
         MODCB RPL=(3),OPTCD=(UPD),MF=(G,(2))
@@L43    EQU   *
         LR    2,6 ==> vs
         A     2,=F'24'
         LA    3,104(,13)
         MVC   0($OPNLEN,3),OPNMODEL    Copy prototype OPEN
         OPEN  ((2)),MF=(E,(3))
         ST    15,168(13) ==> rc
         IC    2,48(5) ==> .acboflgs
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BE    @@L49
         OI    17(6),128 ==> .flags
         B     @@L7
@@L49    EQU   *
         MVC   168(4,13),=F'153'
@@L7     EQU   *
         L     2,168(13)
         LTR   2,2
         BE    @@L51
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),168(13) ==> vs
         LTR   6,6 ==> vs
         BE    @@L51
         ST    6,88(13) ==> vs
         LA    1,88(,13)
         L     15,=V(@@VSCLOS)
         BALR  14,15
         SLR   6,6 ==> vs
@@L51    EQU   *
         L     2,16(11) ==> vsfile
         LTR   2,2
         BE    @@L53
         ST    6,0(2) ==> vs
@@L53    EQU   *
         L     15,168(13)
* Function '__vsopen' epilogue
         PDPEPIL
* Function '__vsopen' literal pool
         DS    0D
         LTORG
* Function '__vsopen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'*VSFILE*'
         DC    X'0'
         DS    0F
OPNMODEL OPEN (ACBMODEL),MF=L
$OPNLEN  EQU   *-OPNMODEL
         DS    0F
ACBMODEL ACB   DDNAME=X,EXLST=EXITLIST
         DS    0F
RPLMODEL RPL   ACB=ACBMODEL
         DS    0F
EXITLIST EXLST LERAD=LERAD,SYNAD=SYNAD,EODAD=EODAD
         DS    0F
EODAD    PDPPRLG CINDEX=0,FRAME=WORKLEN,BASER=12,ENTRY=NO
         USING WORK,R13
*
         ST    R1,PLIST+0          A(RPL)
         LA    R3,4                End Of File Code
         ST    R3,PLIST+4
*
         LA    R1,PLIST
         L     R15,=V(@@VSXEOF)
         BALR  R14,R15
*
         L     R13,4(,R13)         get callers stack
         LR    R14,R2              get return address
         LM    R0,R12,20(R13)      restore registers
         BR    R14                 return to target
         LTORG ,

         DS    0F
LERAD    PDPPRLG CINDEX=0,FRAME=WORKLEN,BASER=12,ENTRY=NO
         USING WORK,R13
*
         ST    R1,PLIST+0          A(RPL)
         LA    R3,8                Logical Error Code
         ST    R3,PLIST+4
*
         LA    R1,PLIST
         L     R15,=V(@@VSXERR)    Common error handler
         BALR  R14,R15
*
         L     R13,4(,R13)         get callers stack
         LR    R14,R2              get return address
         LM    R0,R12,20(R13)      restore registers
         BR    R14                 return to target
         LTORG ,

         DS    0F
SYNAD    PDPPRLG CINDEX=0,FRAME=WORKLEN,BASER=12,ENTRY=NO
         USING WORK,R13
*
         ST    R1,PLIST+0          A(RPL)
         LA    R3,12               Physical Error Code
         ST    R3,PLIST+4
*
         LA    R1,PLIST
         L     R15,=V(@@VSXERR)    Common error handler
         BALR  R14,R15
*
         L     R13,4(,R13)         get callers stack
         LR    R14,R2              get return address
         LM    R0,R12,20(R13)      restore registers
         BR    R14                 return to target
         LTORG ,

         
WORK     DSECT
SAVEAREA DS    18F                                                  00
STKSVLWS DS    A                 PL/I Language Work Space N/A       48
STKSVNAB DS    A                 next available byte      -------+  4C
PLIST    DS    2F                parameter list
WORKLEN  EQU   *-WORK

         IFGACB
$ACBLEN  EQU   *-IFGACB
         IFGRPL
$RPLLEN  EQU   *-IFGRPL
         CSECT ,
         END
