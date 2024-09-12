 TITLE '/home/mike/repos/crent370/clib/@@jsrd4.c'
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
* external function '__jsrd4' prologue
* frame base=88, local stack=56, call args=0
&FUNC    SETC  '__jsrd4'
@@JSRD4  PDPPRLG CINDEX=0,FRAME=144,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__jsrd4' code
         L     15,0(11) ==> js
         L     7,4(11) ==> mttr
         L     8,8(11) ==> buf4k
         L     6,12(11) ==> buflen
         MVC   136(4,13),=F'-1'
         MVC   124(4,13),=F'0'
         MVC   120(4,13),=F'0'
         LA    4,88(,13)
         LA    5,32(0,0)
         SLR   2,2
         LR    3,2
         MVCL  4,2
         L     2,=A(@@LC0)
         MVC   128(8,13),0(2)
         LTR   15,15 ==> js
         BE    @@L3
         L     2,16(15) ==> dcb,dcb
         LTR   2,2 ==> dcb
         BE    @@L3
         STH   6,62(2) ==> buflen,dcbblksi
         L     5,20(15) ==> .trkcyl
         LA    4,120(,13)
         LA    3,124(,13)
         LA    2,128(,13)
         XC    0(8,2),0(2)  Initialize MBBCCHHR to zero
         LR    1,7           Load MTTR value ==> mttr
         STC   1,7(2)       Save R value
         SRL   1,8           Shift TT value
         N     1,=F'65535'     Keep just the TT value
         SR    0,0            Prepare for divide
         DR    0,5           Divide by trks per cyl
         ST    0,0(,4)       Store head number
         ST    1,0(,3)       Store cylinder number
         MVC   3(2,2),2(3)  Copy cylinder number
         MVC   5(2,2),2(4)  Copy head number
         MVC   136(4,13),=F'0'
         L     5,16(15) ==> .dcb
         LA    4,88(,13)
         LA    3,128(,13)
         LA    2,136(,13)
         USING IHADCB,5      ADDRESSING FOR DCB DSECT
         MVC   DCBSYNAD+1(3),=AL3(SYNAD)  SET SYNAD ADDR IN DCB
         DROP  5             DROP ADDRESSING FOR DCB
         LR    10,2            R10 => rc
         READ  (4),DI,(5),(8),(6),,(3),MF=E ==> buf4k,buflen
         CHECK (4)
         B     QUIT
         
SYNAD    SYNADAF ACSMETH=BDAM DECODE ERROR CAUSE
         L     1,128(,1)      Get DECB address
         L     0,0(,1)        Get DECB ECB value
         ST    0,0(,10)       Save ECB value as return code
         SYNADRLS ,           RELEASE WORK AREA
         BR    14             RETURN TO OP SYS
QUIT     DS    0H
@@L3     EQU   *
         L     15,136(13)
* Function '__jsrd4' epilogue
         PDPEPIL
* Function '__jsrd4' literal pool
         DS    0D
         LTORG
* Function '__jsrd4' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    X'0'
         DC    7X'00'
         DCBD  DSORG=DA,DEVD=DA
         CSECT ,
         END
