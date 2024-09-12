 TITLE '/home/mike/repos/crent370/dyn75/@@75vect.c'
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
* Program data area
         DS    0F
@@0      EQU   *
         DC    F'0'
         DC    F'0'
         DC    A(@@1)
         DC    V(@@75GABN)
         DC    V(@@75GHBN)
         DC    V(@@75SOCK)
         DC    V(@@75BIND)
         DC    V(@@75CONN)
         DC    V(@@75LIST)
         DC    V(@@75ACCE)
         DC    V(@@75SEND)
         DC    V(@@75RECV)
         DC    V(@@75CLOS)
         DC    V(@@75IOCT)
         DC    V(@@75SNAM)
         DC    V(@@75SELE)
         DC    V(@@75SELX)
         DC    V(@@75PNAM)
         DC    V(@@75GHBA)
* X-var __75vect
         ENTRY @@75VECT
         DS    0F
@@75VECT EQU   *
         DC    A(@@0)
         DS    0F
@@1      EQU   *
         DC    128X'00'
         END
