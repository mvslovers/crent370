 TITLE '/home/mike/repos/crent370/crypto/sha256t.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/crypto
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
* Program text area
         DS    0F
@@0      EQU   *
         DC    F'1116352408'
         DC    F'1899447441'
         DC    F'-1245643825'
         DC    F'-373957723'
         DC    F'961987163'
         DC    F'1508970993'
         DC    F'-1841331548'
         DC    F'-1424204075'
         DC    F'-670586216'
         DC    F'310598401'
         DC    F'607225278'
         DC    F'1426881987'
         DC    F'1925078388'
         DC    F'-2132889090'
         DC    F'-1680079193'
         DC    F'-1046744716'
         DC    F'-459576895'
         DC    F'-272742522'
         DC    F'264347078'
         DC    F'604807628'
         DC    F'770255983'
         DC    F'1249150122'
         DC    F'1555081692'
         DC    F'1996064986'
         DC    F'-1740746414'
         DC    F'-1473132947'
         DC    F'-1341970488'
         DC    F'-1084653625'
         DC    F'-958395405'
         DC    F'-710438585'
         DC    F'113926993'
         DC    F'338241895'
         DC    F'666307205'
         DC    F'773529912'
         DC    F'1294757372'
         DC    F'1396182291'
         DC    F'1695183700'
         DC    F'1986661051'
         DC    F'-2117940946'
         DC    F'-1838011259'
         DC    F'-1564481375'
         DC    F'-1474664885'
         DC    F'-1035236496'
         DC    F'-949202525'
         DC    F'-778901479'
         DC    F'-694614492'
         DC    F'-200395387'
         DC    F'275423344'
         DC    F'430227734'
         DC    F'506948616'
         DC    F'659060556'
         DC    F'883997877'
         DC    F'958139571'
         DC    F'1322822218'
         DC    F'1537002063'
         DC    F'1747873779'
         DC    F'1955562222'
         DC    F'2024104815'
         DC    F'-2067236844'
         DC    F'-1933114872'
         DC    F'-1866530822'
         DC    F'-1538233109'
         DC    F'-1090935817'
         DC    F'-965641998'
         DS    0F
         EJECT
* external function 'sha256_transform' prologue
* frame base=88, local stack=272, call args=0
&FUNC    SETC  'sha256_transform'
SHA256T  PDPPRLG CINDEX=0,FRAME=360,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'sha256_transform' code
         L     6,4(11) ==> data
         SLR   15,15 ==> i
         LR    5,15 ==> j,i
@@L6     EQU   *
         LR    4,15 ==> i
         MH    4,=H'4'
         IC    3,0(5,6) ==> j
         SLL   3,24
         SLR   2,2
         IC    2,1(5,6)
         SLL   2,16
         OR    3,2
         SLR   2,2
         IC    2,2(5,6)
         SLL   2,8
         OR    3,2
         SLR   2,2
         IC    2,3(5,6)
         OR    3,2
         ST    3,88(13,4) ==> m
         A     15,=F'1' ==> i
         A     5,=F'4' ==> j
         LA    2,15(0,0)
         CLR   15,2 ==> i
         BNH   @@L6
         LA    3,63(0,0)
         CLR   15,3 ==> i
         BH    @@L20
         L     9,=F'-8'
@@L11    EQU   *
         LR    8,15 ==> i
         MH    8,=H'4'
         LA    2,88(,13)
         LR    6,8
         AR    6,2
         LR    4,6
         AR    4,9
         L     3,0(4) ==> m
         LR    5,3
         SLL   5,15
         LR    2,3
         SRL   2,17
         OR    5,2
         LR    2,3
         SLL   2,13
         SRL   3,19
         OR    2,3
         XR    5,2
         L     2,0(4) ==> m
         SRL   2,10
         XR    5,2
         LR    2,6
         A     2,=F'-28'
         A     5,0(2) ==> m
         LR    7,6
         A     7,=F'-60'
         L     4,0(7) ==> m
         LR    2,4
         SLL   2,25
         LR    3,4
         SRL   3,7
         OR    2,3
         LR    3,4
         SLL   3,14
         SRL   4,18
         OR    3,4
         XR    2,3
         L     3,0(7) ==> m
         SRL   3,3
         XR    2,3
         AR    5,2
         A     6,=F'-64'
         A     5,0(6) ==> m
         ST    5,88(13,8) ==> m
         A     15,=F'1' ==> i
         LA    2,63(0,0)
         CLR   15,2 ==> i
         BNH   @@L11
@@L20    EQU   *
         L     3,0(11) ==> ctx
         L     6,12(3) ==> a,state
         L     8,16(3) ==> b,state
         L     9,20(3) ==> c,state
         MVC   344(4,13),24(3) ==> d,state
         L     7,28(3) ==> e,state
         MVC   348(4,13),32(3) ==> f,state
         MVC   352(4,13),36(3) ==> g,state
         MVC   356(4,13),40(3) ==> h,state
         SLR   15,15 ==> i
@@L16    EQU   *
         LR    3,7 ==> e
         SLL   3,26
         LR    2,7 ==> e
         SRL   2,6
         OR    3,2
         LR    2,7 ==> e
         SLL   2,21
         LR    4,7 ==> e
         SRL   4,11
         OR    2,4
         XR    3,2
         LR    2,7 ==> e
         SLL   2,7
         LR    4,7 ==> e
         SRL   4,25
         OR    2,4
         XR    3,2
         L     5,356(13) ==> h
         AR    5,3
         L     3,348(13) ==> f
         NR    3,7 ==> e
         LR    2,7 ==> e
         X     2,=F'-1'
         N     2,352(13) ==> g
         XR    3,2
         AR    5,3
         LR    2,15 ==> i
         MH    2,=H'4'
         L     3,=A(@@0)
         A     5,0(2,3) ==> k
         A     5,88(13,2) ==> t1,m
         LR    4,6 ==> a
         SLL   4,30
         LR    2,6 ==> a
         SRL   2,2
         OR    4,2
         LR    2,6 ==> a
         SLL   2,19
         LR    3,6 ==> a
         SRL   3,13
         OR    2,3
         XR    4,2
         LR    2,6 ==> a
         SLL   2,10
         LR    3,6 ==> a
         SRL   3,22
         OR    2,3
         XR    4,2
         LR    2,9 ==> c
         XR    2,8 ==> b
         NR    2,6 ==> a
         LR    3,8 ==> b
         NR    3,9 ==> c
         XR    2,3
         AR    4,2 ==> t2
         MVC   356(4,13),352(13) ==> h,g
         MVC   352(4,13),348(13) ==> g,f
         ST    7,348(13) ==> e,f
         L     7,344(13) ==> e,d
         AR    7,5 ==> e,t1
         ST    9,344(13) ==> c,d
         LR    9,8 ==> c,b
         LR    8,6 ==> b,a
         LR    6,5 ==> a,t1
         AR    6,4 ==> a,t2
         A     15,=F'1' ==> i
         LA    2,63(0,0)
         CLR   15,2 ==> i
         BNH   @@L16
         LR    2,6 ==> a
         L     3,0(11) ==> ctx
         A     2,12(3) ==> .state
         ST    2,12(3) ==> .state
         LR    2,8 ==> b
         A     2,16(3) ==> .state
         ST    2,16(3) ==> .state
         LR    2,9 ==> c
         A     2,20(3) ==> .state
         ST    2,20(3) ==> .state
         L     2,344(13) ==> d
         A     2,24(3) ==> .state
         ST    2,24(3) ==> .state
         LR    2,7 ==> e
         A     2,28(3) ==> .state
         ST    2,28(3) ==> .state
         L     2,348(13) ==> f
         A     2,32(3) ==> .state
         ST    2,32(3) ==> .state
         L     2,352(13) ==> g
         A     2,36(3) ==> .state
         ST    2,36(3) ==> .state
         L     2,356(13) ==> h
         A     2,40(3) ==> .state
         ST    2,40(3) ==> .state
* Function 'sha256_transform' epilogue
         PDPEPIL
* Function 'sha256_transform' literal pool
         DS    0D
         LTORG
* Function 'sha256_transform' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
