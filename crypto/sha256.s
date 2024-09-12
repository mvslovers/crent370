 TITLE '/home/mike/repos/crent370/crypto/sha256.c'
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
* Program data area
@@2      EQU   *
         DC    X'00'
         DC    X'01'
         DC    X'02'
         DC    X'03'
         DC    X'9C'
         DC    X'09'
         DC    X'86'
         DC    X'7F'
         DC    X'97'
         DC    X'8D'
         DC    X'8E'
         DC    X'0B'
         DC    X'0C'
         DC    X'0D'
         DC    X'0E'
         DC    X'0F'
         DC    X'10'
         DC    X'11'
         DC    X'12'
         DC    X'13'
         DC    X'9D'
         DC    X'85'
         DC    X'08'
         DC    X'87'
         DC    X'18'
         DC    X'19'
         DC    X'92'
         DC    X'8F'
         DC    X'1C'
         DC    X'1D'
         DC    X'1E'
         DC    X'1F'
         DC    X'80'
         DC    X'81'
         DC    X'82'
         DC    X'83'
         DC    X'84'
         DC    X'0A'
         DC    X'17'
         DC    X'1B'
         DC    X'88'
         DC    X'89'
         DC    X'8A'
         DC    X'8B'
         DC    X'8C'
         DC    X'05'
         DC    X'06'
         DC    X'07'
         DC    X'90'
         DC    X'91'
         DC    X'16'
         DC    X'93'
         DC    X'94'
         DC    X'95'
         DC    X'96'
         DC    X'04'
         DC    X'98'
         DC    X'99'
         DC    X'9A'
         DC    X'9B'
         DC    X'14'
         DC    X'15'
         DC    X'9E'
         DC    X'1A'
         DC    X'20'
         DC    X'A0'
         DC    X'A1'
         DC    X'A2'
         DC    X'A3'
         DC    X'A4'
         DC    X'A5'
         DC    X'A6'
         DC    X'A7'
         DC    X'A8'
         DC    X'5B'
         DC    X'2E'
         DC    X'3C'
         DC    X'28'
         DC    X'2B'
         DC    X'5D'
         DC    X'26'
         DC    X'A9'
         DC    X'AA'
         DC    X'AB'
         DC    X'AC'
         DC    X'AD'
         DC    X'AE'
         DC    X'AF'
         DC    X'B0'
         DC    X'B1'
         DC    X'21'
         DC    X'24'
         DC    X'2A'
         DC    X'29'
         DC    X'3B'
         DC    X'5E'
         DC    X'2D'
         DC    X'2F'
         DC    X'B2'
         DC    X'B3'
         DC    X'B4'
         DC    X'B5'
         DC    X'B6'
         DC    X'B7'
         DC    X'B8'
         DC    X'B9'
         DC    X'7C'
         DC    X'2C'
         DC    X'25'
         DC    X'5F'
         DC    X'3E'
         DC    X'3F'
         DC    X'BA'
         DC    X'BB'
         DC    X'BC'
         DC    X'BD'
         DC    X'BE'
         DC    X'BF'
         DC    X'C0'
         DC    X'C1'
         DC    X'C2'
         DC    X'60'
         DC    X'3A'
         DC    X'23'
         DC    X'40'
         DC    X'27'
         DC    X'3D'
         DC    X'22'
         DC    X'C3'
         DC    X'61'
         DC    X'62'
         DC    X'63'
         DC    X'64'
         DC    X'65'
         DC    X'66'
         DC    X'67'
         DC    X'68'
         DC    X'69'
         DC    X'C4'
         DC    X'C5'
         DC    X'C6'
         DC    X'C7'
         DC    X'C8'
         DC    X'C9'
         DC    X'CA'
         DC    X'6A'
         DC    X'6B'
         DC    X'6C'
         DC    X'6D'
         DC    X'6E'
         DC    X'6F'
         DC    X'70'
         DC    X'71'
         DC    X'72'
         DC    X'CB'
         DC    X'CC'
         DC    X'CD'
         DC    X'CE'
         DC    X'CF'
         DC    X'D0'
         DC    X'D1'
         DC    X'7E'
         DC    X'73'
         DC    X'74'
         DC    X'75'
         DC    X'76'
         DC    X'77'
         DC    X'78'
         DC    X'79'
         DC    X'7A'
         DC    X'D2'
         DC    X'D3'
         DC    X'D4'
         DC    X'5B'
         DC    X'D6'
         DC    X'D7'
         DC    X'D8'
         DC    X'D9'
         DC    X'DA'
         DC    X'DB'
         DC    X'DC'
         DC    X'DD'
         DC    X'DE'
         DC    X'DF'
         DC    X'E0'
         DC    X'E1'
         DC    X'E2'
         DC    X'E3'
         DC    X'E4'
         DC    X'5D'
         DC    X'E6'
         DC    X'E7'
         DC    X'7B'
         DC    X'41'
         DC    X'42'
         DC    X'43'
         DC    X'44'
         DC    X'45'
         DC    X'46'
         DC    X'47'
         DC    X'48'
         DC    X'49'
         DC    X'E8'
         DC    X'E9'
         DC    X'EA'
         DC    X'EB'
         DC    X'EC'
         DC    X'ED'
         DC    X'7D'
         DC    X'4A'
         DC    X'4B'
         DC    X'4C'
         DC    X'4D'
         DC    X'4E'
         DC    X'4F'
         DC    X'50'
         DC    X'51'
         DC    X'52'
         DC    X'EE'
         DC    X'EF'
         DC    X'F0'
         DC    X'F1'
         DC    X'F2'
         DC    X'F3'
         DC    X'5C'
         DC    X'9F'
         DC    X'53'
         DC    X'54'
         DC    X'55'
         DC    X'56'
         DC    X'57'
         DC    X'58'
         DC    X'59'
         DC    X'5A'
         DC    X'F4'
         DC    X'F5'
         DC    X'F6'
         DC    X'F7'
         DC    X'F8'
         DC    X'F9'
         DC    X'30'
         DC    X'31'
         DC    X'32'
         DC    X'33'
         DC    X'34'
         DC    X'35'
         DC    X'36'
         DC    X'37'
         DC    X'38'
         DC    X'39'
         DC    X'FA'
         DC    X'FB'
         DC    X'FC'
         DC    X'FD'
         DC    X'FE'
         DC    X'FF'
         DS    0F
@@3      EQU   *
         DC    A(@@2)
* Program text area
         DS    0F
         EJECT
* static function 'mem2asc' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'mem2asc'
@@4      PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'mem2asc' code
         L     7,0(11) ==> in
         L     15,4(11) ==> out
         L     6,8(11) ==> len
         SLR   4,4 ==> i
         CLR   4,6 ==> i,len
         BNL   @@L8
         L     5,=A(@@3)
@@L6     EQU   *
         SLR   3,3 ==> c
         IC    3,0(4,7) ==> c,i
         L     2,0(5) ==> ebc2asc
         IC    2,0(3,2) ==> c
         STC   2,0(4,15) ==> i
         A     4,=F'1' ==> i
         CLR   4,6 ==> i,len
         BL    @@L6
@@L8     EQU   *
* Function 'mem2asc' epilogue
         PDPEPIL
* Function 'mem2asc' literal pool
         DS    0D
         LTORG
* Function 'mem2asc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC3    EQU   *
         DC    X'BA'
         DC    X'78'
         DC    X'16'
         DC    X'BF'
         DC    X'8F'
         DC    X'01'
         DC    X'CF'
         DC    X'EA'
         DC    X'41'
         DC    X'41'
         DC    X'40'
         DC    X'DE'
         DC    X'5D'
         DC    X'AE'
         DC    X'22'
         DC    X'23'
         DC    X'B0'
         DC    X'03'
         DC    X'61'
         DC    X'A3'
         DC    X'96'
         DC    X'17'
         DC    X'7A'
         DC    X'9C'
         DC    X'B4'
         DC    X'10'
         DC    X'FF'
         DC    X'61'
         DC    X'F2'
         DC    X'00'
         DC    X'15'
         DC    X'AD'
@@LC4    EQU   *
         DC    X'24'
         DC    X'8D'
         DC    X'6A'
         DC    X'61'
         DC    X'D2'
         DC    X'06'
         DC    X'38'
         DC    X'B8'
         DC    X'E5'
         DC    X'C0'
         DC    X'26'
         DC    X'93'
         DC    X'0C'
         DC    X'3E'
         DC    X'60'
         DC    X'39'
         DC    X'A3'
         DC    X'3C'
         DC    X'E4'
         DC    X'59'
         DC    X'64'
         DC    X'FF'
         DC    X'21'
         DC    X'67'
         DC    X'F6'
         DC    X'EC'
         DC    X'ED'
         DC    X'D4'
         DC    X'19'
         DC    X'DB'
         DC    X'06'
         DC    X'C1'
@@LC5    EQU   *
         DC    X'CD'
         DC    X'C7'
         DC    X'6E'
         DC    X'5C'
         DC    X'99'
         DC    X'14'
         DC    X'FB'
         DC    X'92'
         DC    X'81'
         DC    X'A1'
         DC    X'C7'
         DC    X'E2'
         DC    X'84'
         DC    X'D7'
         DC    X'3E'
         DC    X'67'
         DC    X'F1'
         DC    X'80'
         DC    X'9A'
         DC    X'48'
         DC    X'A4'
         DC    X'97'
         DC    X'20'
         DC    X'0E'
         DC    X'04'
         DC    X'6D'
         DC    X'39'
         DC    X'CC'
         DC    X'C7'
         DC    X'11'
         DC    X'2C'
         DC    X'D0'
         DS    0F
         EJECT
* static function 'sha256_test' prologue
* frame base=88, local stack=584, call args=16
&FUNC    SETC  'sha256_test'
@@5      PDPPRLG CINDEX=1,FRAME=688,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'sha256_test' code
         L     2,=A(@@LC0)
         MVC   680(4,13),0(2)
         L     2,=A(@@LC1)
         MVC   104(57,13),0(2) ==> text2
         L     2,=A(@@LC2)
         MVC   168(11,13),0(2) ==> text3
         L     2,=A(@@LC3)
         MVC   184(32,13),0(2) ==> hash1
         L     2,=A(@@LC4)
         MVC   216(32,13),0(2) ==> hash2
         L     2,=A(@@LC5)
         MVC   248(32,13),0(2) ==> hash3
         LA    6,1(0,0) ==> pass
         LA    2,680(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    4,15 ==> len1
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    7,15 ==> len2
         LA    2,168(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    5,15 ==> len3
         LA    3,568(,13)
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(SHA256I)
         BALR  14,15
         LA    2,680(,13)
         ST    2,88(13)
         LA    2,312(,13)
         ST    2,92(13)
         ST    4,96(13) ==> len1
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         ST    3,88(13)
         ST    2,92(13)
         ST    4,96(13) ==> len1
         LA    1,88(,13)
         L     15,=V(SHA256U)
         BALR  14,15
         ST    3,88(13)
         LA    3,280(,13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(SHA256F)
         BALR  14,15
         ST    3,88(13)
         MVC   92(4,13),=F'32'
         MVC   96(4,13),=A(@@LC6)
         LA    2,680(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         SLR   4,4 ==> pass
         LA    2,184(,13)
         ST    2,88(13)
         ST    3,92(13)
         MVC   96(4,13),=F'32'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> len1
         BNE   @@L10
         LR    4,6 ==> pass
@@L10    EQU   *
         LR    6,4 ==> pass
         LA    2,568(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(SHA256I)
         BALR  14,15
         LA    4,104(,13)
         ST    4,88(13)
         LA    3,312(,13)
         ST    3,92(13)
         ST    7,96(13) ==> len2
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         ST    2,88(13)
         ST    3,92(13)
         ST    7,96(13) ==> len2
         LA    1,88(,13)
         L     15,=V(SHA256U)
         BALR  14,15
         ST    2,88(13)
         LA    3,280(,13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(SHA256F)
         BALR  14,15
         ST    3,88(13)
         MVC   92(4,13),=F'32'
         MVC   96(4,13),=A(@@LC7)
         ST    4,100(13)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         SLR   4,4 ==> pass
         LTR   6,6 ==> pass
         BE    @@L11
         LA    2,216(,13)
         ST    2,88(13)
         ST    3,92(13)
         MVC   96(4,13),=F'32'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> len1
         BNE   @@L11
         LA    4,1(0,0) ==> pass
@@L11    EQU   *
         LR    6,4 ==> pass
         LA    2,568(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(SHA256I)
         BALR  14,15
         LA    2,168(,13)
         ST    2,88(13)
         LA    2,312(,13)
         ST    2,92(13)
         ST    5,96(13) ==> len3
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         SLR   2,2 ==> idx
         LA    4,568(,13)
         LA    3,312(,13)
@@L16    EQU   *
         ST    4,88(13)
         ST    3,92(13)
         ST    5,96(13) ==> len3
         LA    1,88(,13)
         L     15,=V(SHA256U)
         BALR  14,15
         A     2,=F'1' ==> idx
         L     7,=F'99999'
         CR    2,7 ==> idx
         BNH   @@L16
         LA    2,568(,13)
         ST    2,88(13)
         LA    3,280(,13)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(SHA256F)
         BALR  14,15
         ST    3,88(13)
         MVC   92(4,13),=F'32'
         MVC   96(4,13),=A(@@LC8)
         LA    2,168(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         SLR   4,4 ==> pass
         LTR   6,6 ==> pass
         BE    @@L17
         LA    2,248(,13)
         ST    2,88(13)
         ST    3,92(13)
         MVC   96(4,13),=F'32'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> len1
         BNE   @@L17
         LA    4,1(0,0) ==> pass
@@L17    EQU   *
         LR    15,4 ==> pass
* Function 'sha256_test' epilogue
         PDPEPIL
* Function 'sha256_test' literal pool
         DS    0D
         LTORG
* Function 'sha256_test' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@LC0    EQU   *
         DC    C'abc'
         DC    X'0'
@@LC1    EQU   *
         DC    C'abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmno'
         DC    C'mnopnopq'
         DC    X'0'
@@LC2    EQU   *
         DC    C'aaaaaaaaaa'
         DC    X'0'
@@LC6    EQU   *
         DC    C'text1 "%s" sha256'
         DC    X'0'
@@LC7    EQU   *
         DC    C'text2 "%s" sha256'
         DC    X'0'
@@LC8    EQU   *
         DC    C'text3 "%s" sha256'
         DC    X'0'
         DS    0F
         COPY  PDPMAIN
         EJECT
* external function 'main' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'main'
MAIN     PDPPRLG CINDEX=2,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'main' code
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         L     2,=A(@@LC9)
         LTR   15,15
         BNE   @@L22
         L     2,=A(@@LC10)
@@L22    EQU   *
         MVC   88(4,13),=A(@@LC11)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         SLR   15,15
* Function 'main' epilogue
         PDPEPIL
* Function 'main' literal pool
         DS    0D
         LTORG
* Function 'main' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
@@LC9    EQU   *
         DC    C'SUCCEEDED'
         DC    X'0'
@@LC10   EQU   *
         DC    C'FAILED'
         DC    X'0'
@@LC11   EQU   *
         DC    C'SHA-256 tests: %s'
         DC    X'0'
         END   @@MAIN
