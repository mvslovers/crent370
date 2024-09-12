 TITLE '/home/mike/repos/crent370/clib/strerror.c'
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
* external function 'strerror' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'strerror'
STRERROR PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strerror' code
         L     3,0(11) ==> error
         SLR   15,15 ==> str
         LA    2,131(0,0)
         CLR   3,2 ==> error
         BH    @@L2
         MH    3,=H'4'
         L     2,=A(@@0)
         L     15,0(3,2) ==> str,errors
@@L2     EQU   *
* Function 'strerror' epilogue
         PDPEPIL
* Function 'strerror' literal pool
         DS    0D
         LTORG
* Function 'strerror' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'No Error'
         DC    X'0'
@@LC1    EQU   *
         DC    C'Operation not permitted'
         DC    X'0'
@@LC2    EQU   *
         DC    C'No such file or directory'
         DC    X'0'
@@LC3    EQU   *
         DC    C'No such process'
         DC    X'0'
@@LC4    EQU   *
         DC    C'Interrupted system call'
         DC    X'0'
@@LC5    EQU   *
         DC    C'I/O error'
         DC    X'0'
@@LC6    EQU   *
         DC    C'No such device or address'
         DC    X'0'
@@LC7    EQU   *
         DC    C'Argument list too long'
         DC    X'0'
@@LC8    EQU   *
         DC    C'Exec format error'
         DC    X'0'
@@LC9    EQU   *
         DC    C'Bad file number'
         DC    X'0'
@@LC10   EQU   *
         DC    C'No child processes'
         DC    X'0'
@@LC11   EQU   *
         DC    C'Try again'
         DC    X'0'
@@LC12   EQU   *
         DC    C'Out of memory'
         DC    X'0'
@@LC13   EQU   *
         DC    C'Permission denied'
         DC    X'0'
@@LC14   EQU   *
         DC    C'Bad address'
         DC    X'0'
@@LC15   EQU   *
         DC    C'Block device required'
         DC    X'0'
@@LC16   EQU   *
         DC    C'Device or resource busy'
         DC    X'0'
@@LC17   EQU   *
         DC    C'File exists'
         DC    X'0'
@@LC18   EQU   *
         DC    C'Cross-device link'
         DC    X'0'
@@LC19   EQU   *
         DC    C'No such device'
         DC    X'0'
@@LC20   EQU   *
         DC    C'Not a directory'
         DC    X'0'
@@LC21   EQU   *
         DC    C'Is a directory'
         DC    X'0'
@@LC22   EQU   *
         DC    C'Invalid argument'
         DC    X'0'
@@LC23   EQU   *
         DC    C'File table overflow'
         DC    X'0'
@@LC24   EQU   *
         DC    C'Too many open files'
         DC    X'0'
@@LC25   EQU   *
         DC    C'Not a typewriter'
         DC    X'0'
@@LC26   EQU   *
         DC    C'Text file busy'
         DC    X'0'
@@LC27   EQU   *
         DC    C'File too large'
         DC    X'0'
@@LC28   EQU   *
         DC    C'No space left on device'
         DC    X'0'
@@LC29   EQU   *
         DC    C'Illegal seek'
         DC    X'0'
@@LC30   EQU   *
         DC    C'Read-only file system'
         DC    X'0'
@@LC31   EQU   *
         DC    C'Too many links'
         DC    X'0'
@@LC32   EQU   *
         DC    C'Broken pipe'
         DC    X'0'
@@LC33   EQU   *
         DC    C'Math argument out of domain of func'
         DC    X'0'
@@LC34   EQU   *
         DC    C'Math result not representable'
         DC    X'0'
@@LC35   EQU   *
         DC    C'Resource temporarily unavailable'
         DC    X'0'
@@LC36   EQU   *
         DC    C'Operation now in progress'
         DC    X'0'
@@LC37   EQU   *
         DC    C'Operation already in progress'
         DC    X'0'
@@LC38   EQU   *
         DC    C'Socket operation on non-socket'
         DC    X'0'
@@LC39   EQU   *
         DC    C'Destination address required'
         DC    X'0'
@@LC40   EQU   *
         DC    C'Message too long'
         DC    X'0'
@@LC41   EQU   *
         DC    C'Protocol wrong type for socket'
         DC    X'0'
@@LC42   EQU   *
         DC    C'Protocol not available'
         DC    X'0'
@@LC43   EQU   *
         DC    C'Protocol not supported'
         DC    X'0'
@@LC44   EQU   *
         DC    C'Socket type not supported'
         DC    X'0'
@@LC45   EQU   *
         DC    C'Operation not supported'
         DC    X'0'
@@LC46   EQU   *
         DC    C'Protocol family not supported'
         DC    X'0'
@@LC47   EQU   *
         DC    C'Address family not supported by protocol family'
         DC    X'0'
@@LC48   EQU   *
         DC    C'Address already in use'
         DC    X'0'
@@LC49   EQU   *
         DC    C'Can''t assign requested address'
         DC    X'0'
@@LC50   EQU   *
         DC    C'Network is down'
         DC    X'0'
@@LC51   EQU   *
         DC    C'Network is unreachable'
         DC    X'0'
@@LC52   EQU   *
         DC    C'Network dropped connection on reset'
         DC    X'0'
@@LC53   EQU   *
         DC    C'Software caused connection abort'
         DC    X'0'
@@LC54   EQU   *
         DC    C'Connection reset by peer'
         DC    X'0'
@@LC55   EQU   *
         DC    C'No buffer space available'
         DC    X'0'
@@LC56   EQU   *
         DC    C'Socket is already connected'
         DC    X'0'
@@LC57   EQU   *
         DC    C'Socket is not connected'
         DC    X'0'
@@LC58   EQU   *
         DC    C'Can''t send after socket shutdown'
         DC    X'0'
@@LC59   EQU   *
         DC    C'Too many references: can''t splice'
         DC    X'0'
@@LC60   EQU   *
         DC    C'Operation timed out'
         DC    X'0'
@@LC61   EQU   *
         DC    C'Connection refused'
         DC    X'0'
@@LC62   EQU   *
         DC    C'Too many levels of symbolic links'
         DC    X'0'
@@LC63   EQU   *
         DC    C'File name too long'
         DC    X'0'
@@LC64   EQU   *
         DC    C'Host is down'
         DC    X'0'
@@LC65   EQU   *
         DC    C'No route to host'
         DC    X'0'
@@LC66   EQU   *
         DC    C'Directory not empty'
         DC    X'0'
@@LC67   EQU   *
         DC    C'Too many processes'
         DC    X'0'
@@LC68   EQU   *
         DC    C'Too many users'
         DC    X'0'
@@LC69   EQU   *
         DC    C'Disc quota exceeded'
         DC    X'0'
@@LC70   EQU   *
         DC    C'Stale NFS file handle'
         DC    X'0'
@@LC71   EQU   *
         DC    C'Too many levels of remote in path'
         DC    X'0'
@@LC72   EQU   *
         DC    C'Multihop attempted'
         DC    X'0'
@@LC73   EQU   *
         DC    C'RFS specific error'
         DC    X'0'
@@LC74   EQU   *
         DC    C'Not a data message'
         DC    X'0'
@@LC75   EQU   *
         DC    C'Value too large for defined data type'
         DC    X'0'
@@LC76   EQU   *
         DC    C'Name not unique on network'
         DC    X'0'
@@LC77   EQU   *
         DC    C'File descriptor in bad state'
         DC    X'0'
@@LC78   EQU   *
         DC    C'Remote address changed'
         DC    X'0'
@@LC79   EQU   *
         DC    C'Can not access a needed shared library'
         DC    X'0'
@@LC80   EQU   *
         DC    C'Accessing a corrupted shared library'
         DC    X'0'
@@LC81   EQU   *
         DC    C'.lib section in a.out corrupted'
         DC    X'0'
@@LC82   EQU   *
         DC    C'Attempting to link in too many shared libraries'
         DC    X'0'
@@LC83   EQU   *
         DC    C'Cannot exec a shared library directly'
         DC    X'0'
@@LC84   EQU   *
         DC    C'Illegal byte sequence'
         DC    X'0'
@@LC85   EQU   *
         DC    C'Interrupted system call should be restarted'
         DC    X'0'
@@LC86   EQU   *
         DC    C'Streams pipe error'
         DC    X'0'
@@LC87   EQU   *
         DC    C'Operation not supported on transport endpoint'
         DC    X'0'
@@LC88   EQU   *
         DC    C'Address family not supported by protocol'
         DC    X'0'
@@LC89   EQU   *
         DC    C'Cannot assign requested address'
         DC    X'0'
@@LC90   EQU   *
         DC    C'Network dropped connection because of reset'
         DC    X'0'
@@LC91   EQU   *
         DC    C'Transport endpoint is already connected'
         DC    X'0'
@@LC92   EQU   *
         DC    C'Transport endpoint is not connected'
         DC    X'0'
@@LC93   EQU   *
         DC    C'Cannot send after transport endpoint shutdown'
         DC    X'0'
@@LC94   EQU   *
         DC    C'Too many references: cannot splice'
         DC    X'0'
@@LC95   EQU   *
         DC    C'Connection timed out'
         DC    X'0'
@@LC96   EQU   *
         DC    C'Structure needs cleaning'
         DC    X'0'
@@LC97   EQU   *
         DC    C'Not a named type file'
         DC    X'0'
@@LC98   EQU   *
         DC    C'No semaphores available'
         DC    X'0'
@@LC99   EQU   *
         DC    C'Is a named type file'
         DC    X'0'
@@LC100  EQU   *
         DC    C'Remote I/O error'
         DC    X'0'
@@LC101  EQU   *
         DC    C'Quota exceeded'
         DC    X'0'
@@LC102  EQU   *
         DC    C'No medium found'
         DC    X'0'
@@LC103  EQU   *
         DC    C'Wrong medium type'
         DC    X'0'
@@LC104  EQU   *
         DC    C'Operation Canceled'
         DC    X'0'
@@LC105  EQU   *
         DC    C'Required key not available'
         DC    X'0'
@@LC106  EQU   *
         DC    C'Key has expired'
         DC    X'0'
@@LC107  EQU   *
         DC    C'Key has been revoked'
         DC    X'0'
@@LC108  EQU   *
         DC    C'Key was rejected by service'
         DC    X'0'
@@LC109  EQU   *
         DC    C'Owner died'
         DC    X'0'
@@LC110  EQU   *
         DC    C'State not recoverable'
         DC    X'0'
* Program data area
         DS    0F
@@0      EQU   *
         DC    A(@@LC0)
         DC    A(@@LC1)
         DC    A(@@LC2)
         DC    A(@@LC3)
         DC    A(@@LC4)
         DC    A(@@LC5)
         DC    A(@@LC6)
         DC    A(@@LC7)
         DC    A(@@LC8)
         DC    A(@@LC9)
         DC    A(@@LC10)
         DC    A(@@LC11)
         DC    A(@@LC12)
         DC    A(@@LC13)
         DC    A(@@LC14)
         DC    A(@@LC15)
         DC    A(@@LC16)
         DC    A(@@LC17)
         DC    A(@@LC18)
         DC    A(@@LC19)
         DC    A(@@LC20)
         DC    A(@@LC21)
         DC    A(@@LC22)
         DC    A(@@LC23)
         DC    A(@@LC24)
         DC    A(@@LC25)
         DC    A(@@LC26)
         DC    A(@@LC27)
         DC    A(@@LC28)
         DC    A(@@LC29)
         DC    A(@@LC30)
         DC    A(@@LC31)
         DC    A(@@LC32)
         DC    A(@@LC33)
         DC    A(@@LC34)
         DC    A(@@LC35)
         DC    A(@@LC36)
         DC    A(@@LC37)
         DC    A(@@LC38)
         DC    A(@@LC39)
         DC    A(@@LC40)
         DC    A(@@LC41)
         DC    A(@@LC42)
         DC    A(@@LC43)
         DC    A(@@LC44)
         DC    A(@@LC45)
         DC    A(@@LC46)
         DC    A(@@LC47)
         DC    A(@@LC48)
         DC    A(@@LC49)
         DC    A(@@LC50)
         DC    A(@@LC51)
         DC    A(@@LC52)
         DC    A(@@LC53)
         DC    A(@@LC54)
         DC    A(@@LC55)
         DC    A(@@LC56)
         DC    A(@@LC57)
         DC    A(@@LC58)
         DC    A(@@LC59)
         DC    A(@@LC60)
         DC    A(@@LC61)
         DC    A(@@LC62)
         DC    A(@@LC63)
         DC    A(@@LC64)
         DC    A(@@LC65)
         DC    A(@@LC66)
         DC    A(@@LC67)
         DC    A(@@LC68)
         DC    A(@@LC69)
         DC    A(@@LC70)
         DC    A(@@LC71)
         DC    A(@@LC72)
         DC    A(@@LC73)
         DC    A(@@LC74)
         DC    A(@@LC75)
         DC    A(@@LC76)
         DC    A(@@LC77)
         DC    A(@@LC78)
         DC    A(@@LC79)
         DC    A(@@LC80)
         DC    A(@@LC81)
         DC    A(@@LC82)
         DC    A(@@LC83)
         DC    A(@@LC84)
         DC    A(@@LC85)
         DC    A(@@LC86)
         DC    A(@@LC68)
         DC    A(@@LC38)
         DC    A(@@LC39)
         DC    A(@@LC40)
         DC    A(@@LC41)
         DC    A(@@LC42)
         DC    A(@@LC43)
         DC    A(@@LC44)
         DC    A(@@LC87)
         DC    A(@@LC46)
         DC    A(@@LC88)
         DC    A(@@LC48)
         DC    A(@@LC89)
         DC    A(@@LC50)
         DC    A(@@LC51)
         DC    A(@@LC90)
         DC    A(@@LC53)
         DC    A(@@LC54)
         DC    A(@@LC55)
         DC    A(@@LC91)
         DC    A(@@LC92)
         DC    A(@@LC93)
         DC    A(@@LC94)
         DC    A(@@LC95)
         DC    A(@@LC61)
         DC    A(@@LC64)
         DC    A(@@LC65)
         DC    A(@@LC37)
         DC    A(@@LC36)
         DC    A(@@LC70)
         DC    A(@@LC96)
         DC    A(@@LC97)
         DC    A(@@LC98)
         DC    A(@@LC99)
         DC    A(@@LC100)
         DC    A(@@LC101)
         DC    A(@@LC102)
         DC    A(@@LC103)
         DC    A(@@LC104)
         DC    A(@@LC105)
         DC    A(@@LC106)
         DC    A(@@LC107)
         DC    A(@@LC108)
         DC    A(@@LC109)
         DC    A(@@LC110)
         END
