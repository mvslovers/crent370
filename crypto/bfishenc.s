 TITLE '/home/mike/repos/crent370/crypto/bfishenc.c'
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
         EJECT
* external function 'blowfish_encrypt' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'blowfish_encrypt'
BFISHENC PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'blowfish_encrypt' code
         L     3,0(11) ==> in
         L     5,4(11) ==> out
         L     4,8(11) ==> keystruct
         IC    15,0(3) ==> in
         SLL   15,24 ==> l
         SLR   2,2
         IC    2,1(3)
         SLL   2,16
         OR    15,2 ==> l
         SLR   2,2
         IC    2,2(3)
         SLL   2,8
         OR    15,2 ==> l
         SLR   2,2
         IC    2,3(3)
         OR    15,2 ==> l
         IC    6,4(3)
         SLL   6,24 ==> r
         SLR   2,2
         IC    2,5(3)
         SLL   2,16
         OR    6,2 ==> r
         SLR   2,2
         IC    2,6(3)
         SLL   2,8
         OR    6,2 ==> r
         SLR   2,2
         IC    2,7(3)
         OR    6,2 ==> r
         X     15,0(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,4(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,8(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,12(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,16(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,20(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,24(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,28(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,32(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,36(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,40(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,44(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,48(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,52(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,56(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         LR    3,15 ==> t,l
         LR    15,6 ==> l,r
         LR    6,3 ==> r,t
         X     15,60(4) ==> l,p
         LR    3,15 ==> l
         SRL   3,24
         MH    3,=H'4'
         LR    2,15 ==> l
         SRL   2,14
         N     2,=F'1020'
         L     3,72(4,3) ==> t,s
         A     3,1096(4,2) ==> t,s
         LR    2,15 ==> l
         SRL   2,6
         N     2,=F'1020'
         X     3,2120(4,2) ==> t,s
         LR    2,15 ==> l
         N     2,=F'255'
         MH    2,=H'4'
         A     3,3144(4,2) ==> t,s
         XR    6,3 ==> r,t
         X     6,64(4) ==> r,p
         X     15,68(4) ==> l,p
         LR    2,15 ==> l
         SRL   2,24
         STC   2,0(5) ==> out
         LR    2,15 ==> l
         SRL   2,16
         STC   2,1(5)
         LR    2,15 ==> l
         SRL   2,8
         STC   2,2(5)
         STC   15,3(5) ==> l
         LR    2,6 ==> r
         SRL   2,24
         STC   2,4(5)
         LR    2,6 ==> r
         SRL   2,16
         STC   2,5(5)
         LR    2,6 ==> r
         SRL   2,8
         STC   2,6(5)
         STC   6,7(5) ==> r
* Function 'blowfish_encrypt' epilogue
         PDPEPIL
* Function 'blowfish_encrypt' literal pool
         DS    0D
         LTORG
* Function 'blowfish_encrypt' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
