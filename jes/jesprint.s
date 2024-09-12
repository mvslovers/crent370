 TITLE '/home/mike/repos/crent370/jes/jesprint.c'
         COPY  PDPTOP
         CSECT
* Program text area
@@LC0    EQU   *
         DC    C'Unable to allocate storage for %u byte buffer'
         DC    X'0'
@@LC1    EQU   *
         DC    C'SYSLOG'
         DC    X'0'
@@LC2    EQU   *
         DC    C'SYSLOG DSID=%u'
         DC    X'0'
         DS    0F
         EJECT
* external function 'jesprint' prologue
* frame base=88, local stack=80, call args=16
&FUNC    SETC  'jesprint'
JESPRINT PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'jesprint' code
         MVC   104(4,13),=F'503'
         MVC   108(4,13),=F'0'
         MVC   112(4,13),=F'0'
         MVC   116(4,13),=F'0'
         MVC   120(4,13),=F'0'
         MVC   124(4,13),=F'0'
         MVC   128(4,13),=F'0'
         MVC   152(4,13),=F'0'
         L     2,0(11)
         LTR   2,2
         BNE   @@L4
         L     14,=A(@@L5)
         BR    14
@@L4     EQU   *
         L     2,4(11)
         LTR   2,2
         BNE   @@L6
         L     14,=A(@@L5)
         BR    14
@@L6     EQU   *
         L     2,8(11)
         LTR   2,2
         BNE   @@L7
         L     14,=A(@@L5)
         BR    14
@@L7     EQU   *
         L     2,0(11)
         MVC   112(4,13),8(2)
         L     2,112(13)
         LTR   2,2
         BNE   @@L8
         L     14,=A(@@L5)
         BR    14
@@L8     EQU   *
         L     2,112(13)
         A     2,=F'20'
         ST    2,120(13)
         L     2,120(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,156(13)
         L     2,0(11)
         L     2,12(2)
         MVC   116(4,13),0(2)
         L     2,116(13)
         LTR   2,2
         BNE   @@L9
         B     @@L5
@@L9     EQU   *
         MVC   88(4,13),=F'1'
         MVC   92(4,13),156(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15
         ST    2,124(13)
         L     2,124(13)
         LTR   2,2
         BNE   @@L10
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),156(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L5
@@L10    EQU   *
         L     2,124(13)
         A     2,156(13)
         A     2,=F'-3'
         ST    2,136(13)
         L     2,4(11)
         A     2,=F'48'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,164(13)
         MVC   168(4,13),=F'0'
@@L11    EQU   *
         L     2,168(13)
         CL    2,164(13)
         BL    @@L14
         B     @@L12
@@L14    EQU   *
         L     3,4(11)
         L     2,168(13)
         MH    2,=H'4'
         A     2,48(3)
         MVC   176(4,13),0(2)
         L     2,176(13)
         LTR   2,2
         BNE   @@L15
         B     @@L13
@@L15    EQU   *
         L     2,176(13)
         LH    2,94(2)
         N     2,=XL4'0000FFFF'
         CL    2,8(11)
         BNE   @@L13
         MVC   108(4,13),176(13)
         B     @@L12
@@L13    EQU   *
         L     2,168(13)
         A     2,=F'1'
         ST    2,168(13)
         B     @@L11
@@L12    EQU   *
         MVC   104(4,13),=F'404'
         L     2,108(13)
         LTR   2,2
         BNE   @@L17
         B     @@L5
@@L17    EQU   *
         MVC   104(4,13),=F'0'
         L     2,108(13)
         L     2,84(2)
         LTR   2,2
         BNE   @@L18
         B     @@L5
@@L18    EQU   *
         MVC   140(4,13),124(13)
         L     2,108(13)
         MVC   160(4,13),84(2)
@@L19    EQU   *
         L     2,160(13)
         LTR   2,2
         BNE   @@L22
         B     @@L5
@@L22    EQU   *
         MVC   88(4,13),116(13)
         MVC   92(4,13),160(13)
         MVC   96(4,13),124(13)
         L     2,120(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@JSRD4)
         BALR  14,15
         LR    2,15
         LTR   2,2
         BE    @@L23
         B     @@L5
@@L23    EQU   *
         L     2,4(11)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LR    2,15
         LTR   2,2
         BNE   @@L24
         MVC   88(4,13),124(13)
         L     2,120(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,92(13)
         MVC   96(4,13),=A(@@LC2)
         L     2,108(13)
         LH    2,94(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
@@L24    EQU   *
         L     2,4(11)
         L     3,140(13)
         L     2,72(2)
         CL    2,4(3)
         BE    @@L25
         B     @@L5
@@L25    EQU   *
         L     2,108(13)
         L     3,140(13)
         LH    2,94(2)
         MVC   80(2,13),8(3)
         CLM   2,3,80(13)
         BE    @@L26
         B     @@L5
@@L26    EQU   *
         L     2,124(13)
         A     2,=F'10'
         ST    2,132(13)
         MVC   144(4,13),132(13)
@@L27    EQU   *
         L     2,144(13)
         IC    2,0(2)
         CLM   2,1,=XL1'FF'
         BE    @@L21
         L     2,132(13)
         CL    2,136(13)
         BL    @@L30
         B     @@L21
@@L30    EQU   *
         L     2,144(13)
         IC    2,1(2)
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BE    @@L32
         MVC   176(4,13),144(13)
         L     2,176(13)
         A     2,=F'4'
         ST    2,132(13)
         L     2,176(13)
         IC    2,1(2)
         N     2,=F'8'
         CLM   2,1,=XL1'00'
         BE    @@L33
         L     2,132(13)
         LH    2,0(2)
         N     2,=XL4'0000FFFF'
         ST    2,180(13)
         L     2,132(13)
         A     2,=F'2'
         ST    2,132(13)
         L     2,180(13)
         CL    2,152(13)
         BNH   @@L34
         L     2,128(13)
         LTR   2,2
         BE    @@L35
         MVC   88(4,13),128(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L35    EQU   *
         MVC   152(4,13),180(13)
         MVC   88(4,13),=F'1'
         L     2,152(13)
         A     2,=F'4'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15
         ST    2,128(13)
         L     2,128(13)
         LTR   2,2
         BNE   @@L34
         MVC   88(4,13),=A(@@LC0)
         L     2,152(13)
         A     2,=F'4'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L5
@@L34    EQU   *
         MVC   148(4,13),=F'0'
         L     2,176(13)
         IC    2,1(2)
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L33
         L     2,132(13)
         A     2,=F'1'
         ST    2,132(13)
@@L33    EQU   *
         L     2,128(13)
         LTR   2,2
         BNE   @@L38
         B     @@L21
@@L38    EQU   *
         L     2,128(13)
         A     2,148(13)
         ST    2,88(13)
         MVC   92(4,13),132(13)
         L     2,176(13)
         LH    2,2(2)
         N     2,=XL4'0000FFFF'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,176(13)
         LH    2,2(2)
         N     2,=XL4'0000FFFF'
         A     2,148(13)
         ST    2,148(13)
         L     2,176(13)
         IC    2,1(2)
         N     2,=F'2'
         CLM   2,1,=XL1'00'
         BNE   @@L40
         L     2,148(13)
         CL    2,152(13)
         BH    @@L40
         B     @@L39
@@L40    EQU   *
         MVC   88(4,13),12(11)
         MVC   92(4,13),128(13)
         MVC   96(4,13),148(13)
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         LR    2,15
         ST    2,104(13)
         L     2,104(13)
         LTR   2,2
         BNL   @@L41
         B     @@L5
@@L41    EQU   *
         MVC   148(4,13),=F'0'
@@L39    EQU   *
         L     2,176(13)
         LH    2,2(2)
         N     2,=XL4'0000FFFF'
         A     2,132(13)
         ST    2,132(13)
         B     @@L29
@@L32    EQU   *
         L     2,144(13)
         A     2,=F'3'
         ST    2,132(13)
         L     2,144(13)
         IC    2,1(2)
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L42
         L     2,132(13)
         A     2,=F'1'
         ST    2,132(13)
@@L42    EQU   *
         MVC   88(4,13),12(11)
         MVC   92(4,13),132(13)
         L     2,144(13)
         SLR   3,3
         IC    3,0(2)
         LR    2,3
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         LR    2,15
         ST    2,104(13)
         L     2,104(13)
         LTR   2,2
         BNL   @@L43
         B     @@L5
@@L43    EQU   *
         L     2,144(13)
         SLR   3,3
         IC    3,0(2)
         LR    2,3
         A     2,132(13)
         ST    2,132(13)
@@L29    EQU   *
         MVC   144(4,13),132(13)
         B     @@L27
@@L21    EQU   *
         L     2,140(13)
         MVC   160(4,13),0(2)
         B     @@L19
@@L5     EQU   *
         L     2,128(13)
         LTR   2,2
         BE    @@L44
         MVC   88(4,13),128(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L44    EQU   *
         L     2,124(13)
         LTR   2,2
         BE    @@L45
         MVC   88(4,13),124(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L45    EQU   *
         L     2,104(13)
         LR    15,2
* Function 'jesprint' epilogue
         PDPEPIL
* Function 'jesprint' literal pool
         DS    0D
         LTORG
* Function 'jesprint' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'esc_print'
         DS    0F
         EJECT
* static function 'esc_print' prologue
* frame base=88, local stack=1040, call args=8
&FUNC    SETC  'esc_print'
@@2      PDPPRLG CINDEX=1,FRAME=1136,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'esc_print' code
         MVC   96(4,13),=F'0'
         L     2,8(11)
         LTR   2,2
         BNE   @@L47
         B     @@L48
@@L47    EQU   *
         NOPR  0
@@L49    EQU   *
         L     2,8(11)
         LA    3,1(0,0)
         CLR   2,3
         BNH   @@L50
         L     2,4(11)
         A     2,8(11)
         BCTR  2,0
         IC    2,0(2)
         CLM   2,1,=XL1'40'
         BE    @@L51
         B     @@L50
@@L51    EQU   *
         L     2,8(11)
         BCTR  2,0
         ST    2,8(11)
         B     @@L49
@@L50    EQU   *
         L     2,8(11)
         LA    3,255(0,0)
         CLR   2,3
         BNH   @@L53
         MVC   8(4,11),=F'255'
@@L53    EQU   *
         L     3,4(11)
         L     2,8(11)
         LR    1,3          => our print line
         LR    14,2         => length of line
         BCTR  14,0        decrement for execute
         EX    14,TRLINE     translate unsafe characters
         MVC   88(4,13),4(11)
         MVC   92(4,13),8(11)
         L     2,0(11)
         LA    1,88(,13)
         LA    15,0(2)
         BALR  14,15
         LR    2,15
         ST    2,96(13)
@@L48    EQU   *
         L     2,96(13)
         LR    15,2
* Function 'esc_print' epilogue
         PDPEPIL
* Function 'esc_print' literal pool
         DS    0D
         LTORG
* Function 'esc_print' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
TRLINE   TR    0(*-*,1),PRTXLATE   REMOVE UNPRINTABLES
         
PRTXLATE DC    64C' ',191AL1(*-PRTXLATE),C' '
         END
