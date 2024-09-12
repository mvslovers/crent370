 TITLE '/home/mike/repos/crent370/jes/jesjob.c'
         COPY  PDPTOP
         CSECT
* Program text area
@@LC0    EQU   *
         DC    C'Unable to allocate storage for %u byte buffer'
         DC    X'0'
@@LC1    EQU   *
         DC    C'JOB'
         DC    X'0'
@@LC2    EQU   *
         DC    C'TSU'
         DC    X'0'
@@LC3    EQU   *
         DC    C'STC'
         DC    X'0'
@@LC4    EQU   *
         DC    C'???'
         DC    X'0'
@@LC5    EQU   *
         DC    C'%s%05u'
         DC    X'0'
@@LC6    EQU   *
         DC    C' '
         DC    X'0'
@@LC7    EQU   *
         DC    C'SYSTEM'
         DC    X'0'
@@LC8    EQU   *
         DC    C'Unable to allocate storage for %u byte JESJOB ha'
         DC    C'ndle'
         DC    X'0'
@@LC9    EQU   *
         DC    C'*JESJOB'
         DC    X'0'
         DS    0F
         EJECT
* external function 'jesjob' prologue
* frame base=88, local stack=176, call args=24
&FUNC    SETC  'jesjob'
JESJOB   PDPPRLG CINDEX=0,FRAME=288,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'jesjob' code
         MVC   112(4,13),=F'0'
         MVC   116(4,13),=F'0'
         MVC   120(4,13),=F'0'
         MVC   124(4,13),=F'0'
         MVC   128(4,13),=F'0'
         MVC   132(4,13),=F'0'
         MVC   136(4,13),=F'0'
         MVC   140(4,13),=F'0'
         MVC   144(4,13),=F'0'
         MVC   148(4,13),=F'0'
         MVC   152(4,13),=F'0'
         MVC   156(4,13),=F'0'
         MVC   160(4,13),=F'0'
         MVC   164(4,13),=F'0'
         L     2,0(11)
         LTR   2,2
         BNE   @@L4
         L     14,=A(@@L5)
         BR    14
@@L4     EQU   *
         L     2,8(11)
         LTR   2,2
         BE    @@L6
         L     2,4(11)
         LTR   2,2
         BE    @@L6
         MVC   176(4,13),=F'0'
@@L7     EQU   *
         L     2,4(11)
         A     2,176(13)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L8
         L     2,176(13)
         LA    3,11(0,0)
         CLR   2,3
         BNH   @@L10
         B     @@L8
@@L10    EQU   *
         LA    3,72(0,0)
         LA    2,112(,13)
         A     2,176(13)
         AR    3,2
         L     2,4(11)
         A     2,176(13)
         SLR   4,4
         IC    4,0(2)
         LR    2,4
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TOUPPER)
         BALR  14,15
         LR    2,15
         STC   2,0(3)
         L     2,176(13)
         A     2,=F'1'
         ST    2,176(13)
         B     @@L7
@@L8     EQU   *
         LA    3,72(0,0)
         LA    2,112(,13)
         A     2,176(13)
         AR    2,3
         MVI   0(2),0
@@L6     EQU   *
         L     2,0(11)
         MVC   124(4,13),8(2)
         L     2,124(13)
         A     2,=F'20'
         ST    2,132(13)
         L     2,0(11)
         L     2,12(2)
         MVC   128(4,13),0(2)
         MVC   88(4,13),=F'1'
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         MVC   268(4,13),=F'2'
         L     4,264(13)
         L     5,4+264(13)
         MR    4,2
         ST    4,264(13)
         ST    5,4+264(13)
         MVC   92(4,13),268(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15
         ST    2,156(13)
         L     2,156(13)
         LTR   2,2
         BNE   @@L12
         MVC   88(4,13),=A(@@LC0)
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         MVC   276(4,13),=F'2'
         L     4,272(13)
         L     5,4+272(13)
         MR    4,2
         ST    4,272(13)
         ST    5,4+272(13)
         MVC   92(4,13),276(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         L     14,=A(@@L5)
         BR    14
@@L12    EQU   *
         MVC   160(4,13),156(13)
         MVC   136(4,13),160(13)
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         A     2,160(13)
         ST    2,164(13)
         MVC   152(4,13),164(13)
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         A     2,164(13)
         ST    2,144(13)
         L     2,124(13)
         MVC   148(4,13),240(2)
@@L13    EQU   *
         L     12,0(,10)
         L     3,124(13)
         L     2,148(13)
         CL    2,244(3)
         BL    @@L16
         L     14,=A(@@L5)
         BR    14
@@L16    EQU   *
         L     2,148(13)
         IC    2,1(2)
         CLM   2,1,=XL1'FF'
         BNE   @@L17
         L     14,=A(@@L15)
         BR    14
@@L17    EQU   *
         L     2,148(13)
         IC    2,1(2)
         CLM   2,1,=XL1'00'
         BNE   @@L18
         L     14,=A(@@L15)
         BR    14
@@L18    EQU   *
         MVC   88(4,13),128(13)
         L     2,148(13)
         MVC   92(4,13),8(2)
         MVC   96(4,13),160(13)
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@JSRD4)
         BALR  14,15
         LR    2,15
         LTR   2,2
         BE    @@L19
         L     14,=A(@@L15)
         BR    14
@@L19    EQU   *
         MVC   136(4,13),160(13)
         L     2,136(13)
         IC    2,58(2)
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L20
         MVC   168(4,13),=A(@@LC1)
         B     @@L21
@@L20    EQU   *
         L     2,136(13)
         IC    2,58(2)
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L22
         MVC   168(4,13),=A(@@LC2)
         B     @@L21
@@L22    EQU   *
         L     2,136(13)
         IC    2,58(2)
         N     2,=F'32'
         CLM   2,1,=XL1'00'
         BE    @@L24
         MVC   168(4,13),=A(@@LC3)
         B     @@L21
@@L24    EQU   *
         MVC   168(4,13),=A(@@LC4)
@@L21    EQU   *
         LA    2,200(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC5)
         MVC   96(4,13),168(13)
         L     2,148(13)
         LH    2,2(2)
         N     2,=XL4'0000FFFF'
         ST    2,280(13)
         L     2,280(13)
         L     3,4+280(13)
         SRDL  2,32
         ST    2,280(13)
         ST    3,4+280(13)
         L     4,280(13)
         L     5,4+280(13)
         L     2,=F'10000'
         DR    4,2
         ST    4,280(13)
         ST    5,4+280(13)
         L     2,280(13)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LA    2,216(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'12'
         L     2,148(13)
         A     2,=F'20'
         ST    2,96(13)
         MVC   100(4,13),=F'8'
         MVC   104(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(MEMCPYP)
         BALR  14,15
         LA    2,216(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         L     2,136(13)
         IC    2,58(2)
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L26
         LA    2,232(,13)
         ST    2,88(13)
         LA    2,216(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         B     @@L27
@@L26    EQU   *
         L     2,136(13)
         IC    2,58(2)
         N     2,=F'32'
         CLM   2,1,=XL1'00'
         BE    @@L28
         LA    2,232(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC7)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         B     @@L27
@@L28    EQU   *
         LA    2,232(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'12'
         L     2,136(13)
         A     2,=F'440'
         ST    2,96(13)
         MVC   100(4,13),=F'8'
         MVC   104(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(MEMCPYP)
         BALR  14,15
         IC    2,232(13)
         CLM   2,1,=XL1'40'
         BNH   @@L30
         LA    2,232(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         B     @@L27
@@L30    EQU   *
         MVI   232(13),0
@@L27    EQU   *
         L     2,8(11)
         LTR   2,2
         BE    @@L32
         L     2,4(11)
         LTR   2,2
         BE    @@L32
         L     2,8(11)
         LA    3,1(0,0)
         CLR   2,3
         BNE   @@L33
         LA    2,216(,13)
         ST    2,88(13)
         LA    2,184(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@PATMAT)
         BALR  14,15
         LR    2,15
         LTR   2,2
         BNE   @@L32
         L     14,=A(@@L15)
         BR    14
@@L33    EQU   *
         L     2,8(11)
         LA    4,2(0,0)
         CLR   2,4
         BNE   @@L32
         LA    2,200(,13)
         ST    2,88(13)
         LA    2,184(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@PATMAT)
         BALR  14,15
         LR    2,15
         LTR   2,2
         BNE   @@L32
         L     14,=A(@@L15)
         BR    14
@@L32    EQU   *
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'80'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15
         ST    2,116(13)
         L     2,116(13)
         LTR   2,2
         BNE   @@L38
         MVC   88(4,13),=A(@@LC8)
         MVC   92(4,13),=F'80'
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         L     14,=A(@@L5)
         BR    14
@@L38    EQU   *
         LA    2,112(,13)
         ST    2,88(13)
         MVC   92(4,13),116(13)
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         MVC   88(4,13),116(13)
         MVC   92(4,13),=A(@@LC9)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,116(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'9'
         LA    2,216(,13)
         ST    2,96(13)
         MVC   100(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         L     2,116(13)
         A     2,=F'17'
         ST    2,88(13)
         MVC   92(4,13),=F'9'
         LA    2,200(,13)
         ST    2,96(13)
         MVC   100(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         L     2,116(13)
         A     2,=F'26'
         ST    2,88(13)
         MVC   92(4,13),=F'9'
         LA    2,232(,13)
         ST    2,96(13)
         MVC   100(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         L     3,116(13)
         L     2,136(13)
         MVC   35(1,3),451(2)
         L     3,116(13)
         L     2,136(13)
         MVC   36(1,3),99(2)
         L     3,116(13)
         L     2,148(13)
         MVC   37(1,3),1(2)
         L     3,116(13)
         L     2,148(13)
         MVC   38(1,3),4(2)
         L     3,116(13)
         L     2,148(13)
         MVC   39(1,3),5(2)
         L     3,116(13)
         L     2,136(13)
         MVC   40(4,3),16(2)
         L     3,116(13)
         L     2,136(13)
         MVC   44(4,3),12(2)
         L     3,116(13)
         L     2,136(13)
         MVC   88(4,13),184(2)
         L     2,136(13)
         MVC   92(4,13),188(2)
         LR    2,3
         A     2,=F'56'
         LR    0,2
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         L     3,116(13)
         L     2,136(13)
         MVC   88(4,13),192(2)
         L     2,136(13)
         MVC   92(4,13),196(2)
         LR    2,3
         A     2,=F'64'
         LR    0,2
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         L     3,116(13)
         L     2,136(13)
         MVC   72(4,3),8(2)
         L     2,12(11)
         LTR   2,2
         BE    @@L39
         L     2,136(13)
         MVC   172(4,13),16(2)
@@L40    EQU   *
         L     2,172(13)
         LTR   2,2
         BNE   @@L43
         B     @@L41
@@L43    EQU   *
         MVC   88(4,13),128(13)
         MVC   92(4,13),172(13)
         MVC   96(4,13),164(13)
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@JSRD4)
         BALR  14,15
         MVC   176(4,13),=F'0'
         L     2,124(13)
         L     5,164(13)
         A     5,224(2)
         LR    2,5
         ST    2,140(13)
@@L44    EQU   *
         L     2,140(13)
         CL    2,144(13)
         BL    @@L47
         B     @@L42
@@L47    EQU   *
         L     2,140(13)
         LH    2,8(2)
         CH    2,=H'0'
         BNE   @@L48
         B     @@L42
@@L48    EQU   *
         L     2,140(13)
         L     2,4(2)
         LTR   2,2
         BNE   @@L49
         B     @@L46
@@L49    EQU   *
         L     2,116(13)
         MVC   88(4,13),48(2)
         L     2,140(13)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
         LR    2,15
         LTR   2,2
         BE    @@L50
         B     @@L46
@@L50    EQU   *
         MVC   88(4,13),140(13)
         MVC   92(4,13),116(13)
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         LR    2,15
         ST    2,120(13)
         L     2,120(13)
         LTR   2,2
         BNE   @@L46
         L     14,=A(@@L5)
         BR    14
@@L46    EQU   *
         L     2,176(13)
         A     2,=F'1'
         ST    2,176(13)
         L     2,140(13)
         A     2,=F'104'
         ST    2,140(13)
         B     @@L44
@@L42    EQU   *
         L     2,152(13)
         MVC   172(4,13),16(2)
         B     @@L40
@@L41    EQU   *
         L     2,136(13)
         MVC   172(4,13),12(2)
@@L52    EQU   *
         L     2,172(13)
         LTR   2,2
         BNE   @@L55
         B     @@L39
@@L55    EQU   *
         MVC   88(4,13),128(13)
         MVC   92(4,13),172(13)
         MVC   96(4,13),164(13)
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@JSRD4)
         BALR  14,15
         MVC   176(4,13),=F'0'
         L     2,124(13)
         L     3,164(13)
         A     3,224(2)
         LR    2,3
         ST    2,140(13)
@@L56    EQU   *
         L     2,140(13)
         CL    2,144(13)
         BL    @@L59
         B     @@L54
@@L59    EQU   *
         L     2,140(13)
         LH    2,8(2)
         CH    2,=H'0'
         BNE   @@L60
         B     @@L54
@@L60    EQU   *
         L     2,140(13)
         L     2,4(2)
         LTR   2,2
         BNE   @@L61
         B     @@L58
@@L61    EQU   *
         L     2,116(13)
         MVC   88(4,13),48(2)
         L     2,140(13)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
         LR    2,15
         LTR   2,2
         BE    @@L62
         B     @@L58
@@L62    EQU   *
         MVC   88(4,13),140(13)
         MVC   92(4,13),116(13)
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         LR    2,15
         ST    2,120(13)
         L     2,120(13)
         LTR   2,2
         BNE   @@L58
         L     14,=A(@@L5)
         BR    14
@@L58    EQU   *
         L     2,176(13)
         A     2,=F'1'
         ST    2,176(13)
         L     2,140(13)
         A     2,=F'104'
         ST    2,140(13)
         B     @@L56
@@L54    EQU   *
         L     2,152(13)
         MVC   172(4,13),16(2)
         B     @@L52
@@L39    EQU   *
         L     2,12(11)
         LTR   2,2
         BNE   @@L65
         L     2,136(13)
         IC    2,58(2)
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BNE   @@L65
         B     @@L64
@@L65    EQU   *
         MVC   180(4,13),=F'0'
         L     2,136(13)
         MVC   172(4,13),16(2)
@@L66    EQU   *
         L     2,172(13)
         LTR   2,2
         BNE   @@L69
         B     @@L64
@@L69    EQU   *
         MVC   88(4,13),128(13)
         MVC   92(4,13),172(13)
         MVC   96(4,13),164(13)
         L     2,132(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@JSRD4)
         BALR  14,15
         MVC   172(4,13),=F'0'
         MVC   176(4,13),=F'0'
         L     2,124(13)
         L     4,164(13)
         A     4,224(2)
         LR    2,4
         ST    2,140(13)
@@L70    EQU   *
         L     2,140(13)
         CL    2,144(13)
         BL    @@L73
         B     @@L71
@@L73    EQU   *
         L     2,140(13)
         LH    2,8(2)
         CLM   2,3,=H'5'
         BE    @@L74
         B     @@L72
@@L74    EQU   *
         MVC   88(4,13),0(11)
         MVC   92(4,13),148(13)
         MVC   96(4,13),136(13)
         L     2,140(13)
         MVC   100(4,13),4(2)
         MVC   104(4,13),116(13)
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         LR    2,15
         ST    2,180(13)
         B     @@L71
@@L72    EQU   *
         L     2,176(13)
         A     2,=F'1'
         ST    2,176(13)
         L     2,140(13)
         A     2,=F'104'
         ST    2,140(13)
         B     @@L70
@@L71    EQU   *
         L     2,180(13)
         LTR   2,2
         BE    @@L68
         B     @@L64
@@L68    EQU   *
         L     2,152(13)
         MVC   172(4,13),16(2)
         B     @@L66
@@L64    EQU   *
         L     2,116(13)
         L     2,48(2)
         LTR   2,2
         L     14,=A(@@L15)
         BER   14
         L     2,116(13)
         A     2,=F'48'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,248(13)
         MVC   252(4,13),=F'0'
@@L77    EQU   *
         L     2,252(13)
         CL    2,248(13)
         BL    @@L80
         B     @@L78
@@L80    EQU   *
         L     3,116(13)
         L     2,252(13)
         MH    2,=H'4'
         A     2,48(3)
         MVC   256(4,13),0(2)
         L     2,256(13)
         LTR   2,2
         BNE   @@L81
         B     @@L79
@@L81    EQU   *
         L     2,256(13)
         IC    2,8(2)
         CLM   2,1,=XL1'00'
         BE    @@L83
         L     2,256(13)
         IC    2,8(2)
         CLM   2,1,=XL1'40'
         BE    @@L83
         B     @@L79
@@L83    EQU   *
         L     2,116(13)
         A     2,=F'48'
         ST    2,88(13)
         L     2,252(13)
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         MVC   88(4,13),256(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         L     2,248(13)
         BCTR  2,0
         ST    2,248(13)
@@L79    EQU   *
         L     2,252(13)
         A     2,=F'1'
         ST    2,252(13)
         B     @@L77
@@L78    EQU   *
         L     2,116(13)
         A     2,=F'48'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,248(13)
         L     2,248(13)
         LA    5,1(0,0)
         CLR   2,5
         BNH   @@L15
         L     2,116(13)
         MVC   88(4,13),48(2)
         MVC   92(4,13),248(13)
         MVC   96(4,13),=F'4'
         MVC   100(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(QSORT)
         BALR  14,15
@@L15    EQU   *
         L     2,148(13)
         A     2,=F'28'
         ST    2,148(13)
         B     @@L13
@@L5     EQU   *
         L     2,156(13)
         LTR   2,2
         BE    @@L85
         MVC   88(4,13),156(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L85    EQU   *
         L     2,112(13)
         LR    15,2
* Function 'jesjob' epilogue
         PDPEPIL
* Function 'jesjob' literal pool
         DS    0D
         LTORG
* Function 'jesjob' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'dsid_comp'
         DS    0F
         EJECT
* static function 'dsid_comp' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'dsid_comp'
@@6      PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'dsid_comp' code
         L     2,0(11)
         MVC   88(4,13),0(2)
         L     2,4(11)
         MVC   92(4,13),0(2)
         L     2,88(13)
         LH    2,94(2)
         N     2,=XL4'0000FFFF'
         L     3,92(13)
         LH    3,94(3)
         N     3,=XL4'0000FFFF'
         SR    2,3
         LR    15,2
* Function 'dsid_comp' epilogue
         PDPEPIL
* Function 'dsid_comp' literal pool
         DS    0D
         LTORG
* Function 'dsid_comp' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'process_pddb'
@@LC10   EQU   *
         DC    C'Unable to allocate storage for %u byte JESDD han'
         DC    C'dle'
         DC    X'0'
@@LC11   EQU   *
         DC    C'*JESDD*'
         DC    X'0'
@@LC12   EQU   *
         DC    C'JESJCLIN'
         DC    X'0'
@@LC13   EQU   *
         DC    C'JES2.%s.SI%04u'
         DC    X'0'
@@LC14   EQU   *
         DC    C'JESMSGLG'
         DC    X'0'
@@LC15   EQU   *
         DC    C'JES2.%s.SO%04u'
         DC    X'0'
@@LC16   EQU   *
         DC    C'JESJCL'
         DC    X'0'
@@LC17   EQU   *
         DC    C'JESYSMSG'
         DC    X'0'
@@LC18   EQU   *
         DC    C'JESINTXT'
         DC    X'0'
@@LC19   EQU   *
         DC    C'JESJRNL'
         DC    X'0'
         DS    0F
         EJECT
* static function 'process_pddb' prologue
* frame base=88, local stack=8, call args=24
&FUNC    SETC  'process_pddb'
@@4      PDPPRLG CINDEX=2,FRAME=120,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'process_pddb' code
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'96'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15
         ST    2,112(13)
         L     2,112(13)
         LTR   2,2
         BNE   @@L88
         MVC   88(4,13),=A(@@LC10)
         MVC   92(4,13),=F'96'
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L89
@@L88    EQU   *
         L     2,4(11)
         A     2,=F'48'
         ST    2,88(13)
         MVC   92(4,13),112(13)
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         MVC   88(4,13),112(13)
         MVC   92(4,13),=A(@@LC11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'9'
         L     2,0(11)
         A     2,=F'36'
         ST    2,96(13)
         MVC   100(4,13),=F'8'
         MVC   104(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(MEMCPYP)
         BALR  14,15
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         L     2,0(11)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,116(13)
         L     3,116(13)
         LA    2,6(0,0)
         CLR   3,2
         BH    @@L90
         L     2,=A(@@L97)
         L     3,116(13)
         MH    3,=H'4'
         L     2,0(3,2)
         BR    2
         DS    0F
         DS    0F
         DS    0F
         LTORG
         DS    0F
@@L97    EQU   *
         DC    A(@@L90)
         DC    A(@@L91)
         DC    A(@@L92)
         DC    A(@@L93)
         DC    A(@@L94)
         DC    A(@@L95)
         DC    A(@@L96)
@@L91    EQU   *
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC12)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,112(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC13)
         L     2,4(11)
         A     2,=F'17'
         ST    2,96(13)
         L     2,0(11)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,112(13)
         MVI   82(2),160
         B     @@L90
@@L92    EQU   *
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC14)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,112(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC15)
         L     2,4(11)
         A     2,=F'17'
         ST    2,96(13)
         L     2,0(11)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,112(13)
         MVI   82(2),192
         B     @@L90
@@L93    EQU   *
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC16)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,112(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC15)
         L     2,4(11)
         A     2,=F'17'
         ST    2,96(13)
         L     2,0(11)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,112(13)
         MVI   82(2),192
         B     @@L90
@@L94    EQU   *
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC17)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,112(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC15)
         L     2,4(11)
         A     2,=F'17'
         ST    2,96(13)
         L     2,0(11)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,112(13)
         MVI   82(2),192
         B     @@L90
@@L95    EQU   *
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC18)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,112(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC13)
         L     2,4(11)
         A     2,=F'17'
         ST    2,96(13)
         L     2,0(11)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,112(13)
         MVI   82(2),160
         B     @@L90
@@L96    EQU   *
         L     2,112(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC19)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,112(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC13)
         L     2,4(11)
         A     2,=F'17'
         ST    2,96(13)
         L     2,0(11)
         LH    2,8(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         L     2,112(13)
         MVI   82(2),160
@@L90    EQU   *
         L     3,112(13)
         L     2,0(11)
         MVC   80(1,3),10(2)
         L     3,112(13)
         L     2,0(11)
         MVC   81(1,3),1(2)
         L     3,112(13)
         L     2,0(11)
         MVC   84(4,3),4(2)
         L     3,112(13)
         L     2,0(11)
         MVC   88(4,3),20(2)
         L     3,112(13)
         L     2,0(11)
         MVC   92(2,3),2(2)
         L     3,112(13)
         L     2,0(11)
         MVC   94(2,3),8(2)
@@L89    EQU   *
         L     2,112(13)
         LR    15,2
* Function 'process_pddb' epilogue
         PDPEPIL
* Function 'process_pddb' literal pool
         DS    0D
         LTORG
* Function 'process_pddb' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
         
&FUNC    SETC 'make_time'
@@LC20   EQU   *
         DC    C'%X'
         DC    X'0'
         DS    0F
         EJECT
* static function 'make_time' prologue
* frame base=88, local stack=112, call args=16
&FUNC    SETC  'make_time'
@@2      PDPPRLG CINDEX=3,FRAME=216,BASER=12,ENTRY=NO
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function 'make_time' code
         ST    0,184(13)
         MVC   112(4,13),=F'0'
         MVC   116(4,13),=F'0'
         LA    2,120(,13)
         ST    2,192(13)
         MVC   196(4,13),=F'36'
         MVC   200(4,13),=F'0'
         MVC   204(4,13),=F'0'
         L     2,192(13)
         L     3,4+192(13)
         L     4,200(13)
         L     5,4+200(13)
         MVCL  2,4
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         L     2,0(11)
         LTR   2,2
         BNE   @@L100
         B     @@L101
@@L100   EQU   *
         L     2,4(11)
         LTR   2,2
         BNE   @@L102
         B     @@L101
@@L102   EQU   *
         L     2,0(11)
         ST    2,208(13)
         L     2,208(13)
         L     3,4+208(13)
         SRDL  2,32
         ST    2,208(13)
         ST    3,4+208(13)
         L     4,208(13)
         L     5,4+208(13)
         LA    2,100(0,0)
         DR    4,2
         ST    4,208(13)
         ST    5,4+208(13)
         L     2,212(13)
         ST    2,120(13)
         L     2,4(11)
         SRL   2,16
         ST    2,112(13)
         LA    2,160(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC20)
         MVC   96(4,13),112(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LA    2,160(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         ST    15,112(13)
         MVC   140(4,13),112(13)
         L     2,4(11)
         N     2,=F'65535'
         SRL   2,4
         ST    2,116(13)
         LA    2,160(,13)
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC20)
         MVC   96(4,13),116(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LA    2,160(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         ST    15,116(13)
         MVC   132(4,13),116(13)
         MVC   152(4,13),=F'-1'
         LA    2,120(,13)
         ST    2,88(13)
         LA    0,104(,13)
         LA    1,88(,13)
         L     15,=V(TM64MKT)
         BALR  14,15
         L     2,104(13)
         L     3,=F'-1'
         CLR   2,3
         BNE   @@L101
         L     2,108(13)
         L     4,=F'-1'
         CLR   2,4
         BNE   @@L101
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
@@L101   EQU   *
         L     5,184(13)
         MVC   0(8,5),104(13)
         L     15,184(13)
* Function 'make_time' epilogue
         PDPEPIL
* Function 'make_time' literal pool
         DS    0D
         LTORG
* Function 'make_time' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
         
&FUNC    SETC 'process_intxt'
@@LC21   EQU   *
         DC    X'0'
         DC    11X'00'
@@LC22   EQU   *
         DC    X'0'
         DC    7X'00'
         DS    0F
         EJECT
* static function 'process_intxt' prologue
* frame base=88, local stack=336, call args=24
&FUNC    SETC  'process_intxt'
@@5      PDPPRLG CINDEX=4,FRAME=448,BASER=12,ENTRY=NO
         B     @@FEN4
         LTORG
@@FEN4   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG4    EQU   *
         LR    11,1
         L     10,=A(@@PGT4)
* Function 'process_intxt' code
         L     2,0(11)
         MVC   112(4,13),8(2)
         L     2,0(11)
         L     2,12(2)
         MVC   116(4,13),0(2)
         L     2,112(13)
         A     2,=F'20'
         ST    2,120(13)
         MVC   124(4,13),=F'0'
         MVC   128(4,13),=F'0'
         L     2,16(11)
         MVC   132(4,13),48(2)
         LA    2,132(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,136(13)
         L     2,=A(@@LC21)
         MVC   160(1,13),0(2)
         LA    2,161(,13)
         ST    2,328(13)
         MVC   332(4,13),=F'11'
         MVC   336(4,13),=F'0'
         MVC   340(4,13),=F'0'
         L     2,328(13)
         L     3,4+328(13)
         L     4,336(13)
         L     5,4+336(13)
         MVCL  2,4
         L     2,=A(@@LC21)
         MVC   176(1,13),0(2)
         LA    2,177(,13)
         ST    2,344(13)
         MVC   348(4,13),=F'11'
         MVC   352(4,13),=F'0'
         MVC   356(4,13),=F'0'
         L     2,344(13)
         L     3,4+344(13)
         L     4,352(13)
         L     5,4+352(13)
         MVCL  2,4
         L     2,=A(@@LC21)
         MVC   192(1,13),0(2)
         LA    2,193(,13)
         ST    2,360(13)
         MVC   364(4,13),=F'11'
         MVC   368(4,13),=F'0'
         MVC   372(4,13),=F'0'
         L     2,360(13)
         L     3,4+360(13)
         L     4,368(13)
         L     5,4+368(13)
         MVCL  2,4
         L     2,=A(@@LC21)
         MVC   208(1,13),0(2)
         LA    2,209(,13)
         ST    2,376(13)
         MVC   380(4,13),=F'11'
         MVC   384(4,13),=F'0'
         MVC   388(4,13),=F'0'
         L     2,376(13)
         L     3,4+376(13)
         L     4,384(13)
         L     5,4+384(13)
         MVCL  2,4
         L     2,=A(@@LC21)
         MVC   224(1,13),0(2)
         LA    2,225(,13)
         ST    2,392(13)
         MVC   396(4,13),=F'11'
         MVC   400(4,13),=F'0'
         MVC   404(4,13),=F'0'
         L     2,392(13)
         L     3,4+392(13)
         L     4,400(13)
         L     5,4+400(13)
         MVCL  2,4
         L     2,=A(@@LC21)
         MVC   240(1,13),0(2)
         LA    2,241(,13)
         ST    2,408(13)
         MVC   412(4,13),=F'11'
         MVC   416(4,13),=F'0'
         MVC   420(4,13),=F'0'
         L     2,408(13)
         L     3,4+408(13)
         L     4,416(13)
         L     5,4+416(13)
         MVCL  2,4
         L     2,=A(@@LC21)
         MVC   256(1,13),0(2)
         LA    2,257(,13)
         ST    2,424(13)
         MVC   428(4,13),=F'55'
         MVC   432(4,13),=F'0'
         MVC   436(4,13),=F'0'
         L     2,424(13)
         L     3,4+424(13)
         L     4,432(13)
         L     5,4+432(13)
         MVCL  2,4
         L     2,=A(@@LC22)
         MVC   312(8,13),0(2)
         MVC   88(4,13),=F'1'
         L     2,120(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15
         ST    2,124(13)
         L     2,124(13)
         LTR   2,2
         BNE   @@L105
         B     @@L106
@@L105   EQU   *
         MVC   144(4,13),12(11)
@@L107   EQU   *
         L     2,144(13)
         LTR   2,2
         BNE   @@L110
         B     @@L106
@@L110   EQU   *
         MVC   88(4,13),116(13)
         MVC   92(4,13),144(13)
         MVC   96(4,13),124(13)
         L     2,120(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@JSRD4)
         BALR  14,15
         MVC   156(4,13),124(13)
         L     2,156(13)
         L     3,8(11)
         L     2,4(2)
         CL    2,8(3)
         BE    @@L111
         B     @@L106
@@L111   EQU   *
         L     2,156(13)
         LH    2,8(2)
         CLM   2,3,=H'5'
         BE    @@L112
         B     @@L106
@@L112   EQU   *
         L     2,156(13)
         A     2,=F'13'
         ST    2,148(13)
         L     2,120(13)
         LH    2,176(2)
         N     2,=XL4'0000FFFF'
         A     2,124(13)
         BCTR  2,0
         ST    2,152(13)
@@L113   EQU   *
         L     2,148(13)
         CL    2,152(13)
         BL    @@L115
         B     @@L109
@@L115   EQU   *
         MVC   128(4,13),148(13)
         L     2,128(13)
         LH    2,0(2)
         CH    2,=H'0'
         BNE   @@L116
         B     @@L109
@@L116   EQU   *
         L     2,128(13)
         IC    2,2(2)
         N     2,=F'15'
         LR    5,2
         N     5,=XL4'000000FF'
         ST    5,440(13)
         L     3,440(13)
         LA    2,2(0,0)
         CR    3,2
         BE    @@L121
         L     5,440(13)
         LA    4,2(0,0)
         CR    5,4
         BH    @@L128
         L     3,440(13)
         LA    2,1(0,0)
         CLR   3,2
         BE    @@L118
         B     @@L117
@@L128   EQU   *
         L     5,440(13)
         LA    4,4(0,0)
         CLR   5,4
         BE    @@L122
         L     3,440(13)
         LA    2,8(0,0)
         CLR   3,2
         BE    @@L125
         B     @@L117
@@L118   EQU   *
         MVC   88(4,13),148(13)
         LA    2,160(,13)
         ST    2,92(13)
         LA    2,176(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=A(@@7)
         BALR  14,15
         IC    2,176(13)
         CLM   2,1,=XL1'00'
         BE    @@L119
         L     2,16(11)
         A     2,=F'26'
         ST    2,88(13)
         LA    2,176(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
@@L119   EQU   *
         L     2,136(13)
         LTR   2,2
         BNE   @@L117
         B     @@L106
@@L121   EQU   *
         MVC   88(4,13),148(13)
         LA    2,192(,13)
         ST    2,92(13)
         LA    2,208(,13)
         ST    2,96(13)
         LA    2,224(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=A(@@8)
         BALR  14,15
         B     @@L117
@@L122   EQU   *
         MVC   88(4,13),148(13)
         LA    2,240(,13)
         ST    2,92(13)
         LA    2,256(,13)
         ST    2,96(13)
         LA    2,312(,13)
         ST    2,100(13)
         LA    2,320(,13)
         ST    2,104(13)
         LA    1,88(,13)
         L     15,=A(@@9)
         BALR  14,15
         IC    2,312(13)
         CLM   2,1,=XL1'00'
         BE    @@L123
         L     2,16(11)
         MVC   88(4,13),48(2)
         LA    2,240(,13)
         ST    2,92(13)
         LA    2,256(,13)
         ST    2,96(13)
         LA    2,312(,13)
         ST    2,100(13)
         LA    2,192(,13)
         ST    2,104(13)
         LA    2,208(,13)
         ST    2,108(13)
         LA    1,88(,13)
         L     15,=A(@@10)
         BALR  14,15
@@L123   EQU   *
         L     2,320(13)
         LTR   2,2
         BE    @@L117
         L     2,16(11)
         MVC   88(4,13),48(2)
         LA    2,240(,13)
         ST    2,92(13)
         LA    2,256(,13)
         ST    2,96(13)
         LA    2,192(,13)
         ST    2,100(13)
         LA    2,208(,13)
         ST    2,104(13)
         LA    1,88(,13)
         L     15,=A(@@11)
         BALR  14,15
         B     @@L117
@@L125   EQU   *
         MVC   88(4,13),148(13)
         LA    2,208(,13)
         ST    2,92(13)
         LA    2,224(,13)
         ST    2,96(13)
         LA    2,224(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=A(@@8)
         BALR  14,15
@@L117   EQU   *
         L     2,128(13)
         LH    2,0(2)
         N     2,=XL4'0000FFFF'
         A     2,148(13)
         A     2,=F'3'
         ST    2,148(13)
         B     @@L113
@@L109   EQU   *
         L     2,156(13)
         MVC   144(4,13),0(2)
         B     @@L107
@@L106   EQU   *
         L     2,124(13)
         LTR   2,2
         BE    @@L129
         MVC   88(4,13),124(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L129   EQU   *
         L     2,136(13)
         LR    15,2
* Function 'process_intxt' epilogue
         PDPEPIL
* Function 'process_intxt' literal pool
         DS    0D
         LTORG
* Function 'process_intxt' page table
@@PGT4   DS    0F
         DC    A(@@PG4)
         
&FUNC    SETC 'process_job'
         DS    0F
         EJECT
* static function 'process_job' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'process_job'
@@7      PDPPRLG CINDEX=5,FRAME=128,BASER=12,ENTRY=NO
         B     @@FEN5
         LTORG
@@FEN5   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG5    EQU   *
         LR    11,1
         L     10,=A(@@PGT5)
* Function 'process_job' code
         MVC   104(4,13),0(11)
         L     2,104(13)
         A     2,=F'6'
         ST    2,0(11)
         L     2,4(11)
         MVI   0(2),0
         L     2,8(11)
         MVI   0(2),0
         MVC   108(4,13),0(11)
@@L131   EQU   *
         L     2,108(13)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L132
         L     2,108(13)
         IC    2,0(2)
         CLM   2,1,=XL1'FE'
         BNE   @@L134
         B     @@L132
@@L134   EQU   *
         L     2,108(13)
         IC    2,2(2)
         N     2,=F'127'
         N     2,=XL4'000000FF'
         ST    2,116(13)
         L     2,108(13)
         SLR   3,3
         IC    3,0(2)
         ST    3,120(13)
         L     3,120(13)
         LA    2,165(0,0)
         CLR   3,2
         BE    @@L137
         L     3,120(13)
         LA    2,180(0,0)
         CLR   3,2
         BE    @@L138
         B     @@L136
@@L137   EQU   *
         MVC   88(4,13),8(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         MVC   96(4,13),116(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,8(11)
         A     2,116(13)
         MVI   0(2),0
         MVC   88(4,13),8(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         B     @@L136
@@L138   EQU   *
         MVC   88(4,13),4(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         MVC   96(4,13),116(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,4(11)
         A     2,116(13)
         MVI   0(2),0
         MVC   88(4,13),4(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
@@L136   EQU   *
         L     2,0(11)
         A     2,=F'2'
         ST    2,0(11)
         MVC   112(4,13),=F'0'
@@L141   EQU   *
         L     2,108(13)
         SLR   3,3
         IC    3,1(2)
         L     2,112(13)
         CLR   2,3
         BL    @@L144
         B     @@L133
@@L144   EQU   *
         L     2,0(11)
         IC    2,0(2)
         N     2,=F'127'
         N     2,=XL4'000000FF'
         A     2,0(11)
         A     2,=F'1'
         ST    2,0(11)
         L     2,112(13)
         A     2,=F'1'
         ST    2,112(13)
         B     @@L141
@@L133   EQU   *
         MVC   108(4,13),0(11)
         B     @@L131
@@L132   EQU   *
         SLR   2,2
         LR    15,2
* Function 'process_job' epilogue
         PDPEPIL
* Function 'process_job' literal pool
         DS    0D
         LTORG
* Function 'process_job' page table
@@PGT5   DS    0F
         DC    A(@@PG5)
         
&FUNC    SETC 'process_exec'
         DS    0F
         EJECT
* static function 'process_exec' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'process_exec'
@@8      PDPPRLG CINDEX=6,FRAME=128,BASER=12,ENTRY=NO
         B     @@FEN6
         LTORG
@@FEN6   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG6    EQU   *
         LR    11,1
         L     10,=A(@@PGT6)
* Function 'process_exec' code
         MVC   104(4,13),0(11)
         L     2,104(13)
         A     2,=F'4'
         ST    2,0(11)
         L     2,4(11)
         MVI   0(2),0
         MVC   108(4,13),0(11)
@@L146   EQU   *
         L     2,108(13)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L147
         L     2,108(13)
         IC    2,0(2)
         CLM   2,1,=XL1'FE'
         BNE   @@L149
         B     @@L147
@@L149   EQU   *
         L     2,108(13)
         IC    2,2(2)
         N     2,=F'127'
         N     2,=XL4'000000FF'
         ST    2,116(13)
         L     2,108(13)
         SLR   3,3
         IC    3,0(2)
         ST    3,120(13)
         L     3,120(13)
         LA    2,139(0,0)
         CR    3,2
         BE    @@L153
         L     3,120(13)
         LA    2,139(0,0)
         CR    3,2
         BH    @@L157
         L     3,120(13)
         LA    2,138(0,0)
         CLR   3,2
         BE    @@L152
         B     @@L151
@@L157   EQU   *
         L     3,120(13)
         LA    2,148(0,0)
         CLR   3,2
         BE    @@L154
         B     @@L151
@@L152   EQU   *
         MVC   88(4,13),12(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         MVC   96(4,13),116(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,12(11)
         A     2,116(13)
         MVI   0(2),0
         MVC   88(4,13),12(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         B     @@L151
@@L153   EQU   *
         L     2,12(11)
         MVI   0(2),0
         MVC   88(4,13),8(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         MVC   96(4,13),116(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,8(11)
         A     2,116(13)
         MVI   0(2),0
         MVC   88(4,13),8(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         B     @@L151
@@L154   EQU   *
         MVC   88(4,13),4(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         MVC   96(4,13),116(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,4(11)
         A     2,116(13)
         MVI   0(2),0
         MVC   88(4,13),4(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
@@L151   EQU   *
         L     2,0(11)
         A     2,=F'2'
         ST    2,0(11)
         MVC   112(4,13),=F'0'
@@L158   EQU   *
         L     2,108(13)
         SLR   3,3
         IC    3,1(2)
         L     2,112(13)
         CLR   2,3
         BL    @@L161
         B     @@L148
@@L161   EQU   *
         L     2,0(11)
         IC    2,0(2)
         N     2,=F'127'
         N     2,=XL4'000000FF'
         A     2,0(11)
         A     2,=F'1'
         ST    2,0(11)
         L     2,112(13)
         A     2,=F'1'
         ST    2,112(13)
         B     @@L158
@@L148   EQU   *
         MVC   108(4,13),0(11)
         B     @@L146
@@L147   EQU   *
         SLR   2,2
         LR    15,2
* Function 'process_exec' epilogue
         PDPEPIL
* Function 'process_exec' literal pool
         DS    0D
         LTORG
* Function 'process_exec' page table
@@PGT6   DS    0F
         DC    A(@@PG6)
         
&FUNC    SETC 'process_dd'
         DS    0F
         EJECT
* static function 'process_dd' prologue
* frame base=88, local stack=16, call args=16
&FUNC    SETC  'process_dd'
@@9      PDPPRLG CINDEX=7,FRAME=120,BASER=12,ENTRY=NO
         B     @@FEN7
         LTORG
@@FEN7   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG7    EQU   *
         LR    11,1
         L     10,=A(@@PGT7)
* Function 'process_dd' code
         MVC   104(4,13),0(11)
         L     2,104(13)
         A     2,=F'4'
         ST    2,0(11)
         L     2,8(11)
         MVI   0(2),0
         L     2,12(11)
         MVI   0(2),0
         L     2,16(11)
         MVC   0(4,2),=F'0'
         MVC   108(4,13),0(11)
@@L163   EQU   *
         L     2,108(13)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L164
         L     2,108(13)
         IC    2,0(2)
         CLM   2,1,=XL1'FE'
         BNE   @@L166
         B     @@L164
@@L166   EQU   *
         L     2,108(13)
         SLR   3,3
         IC    3,0(2)
         ST    3,116(13)
         L     3,116(13)
         LA    2,74(0,0)
         CR    3,2
         BE    @@L170
         L     3,116(13)
         LA    2,74(0,0)
         CR    3,2
         BH    @@L178
         L     3,116(13)
         LA    2,36(0,0)
         CLR   3,2
         BE    @@L173
         L     3,116(13)
         LA    2,71(0,0)
         CLR   3,2
         BE    @@L174
         B     @@L168
@@L178   EQU   *
         L     3,116(13)
         LA    2,110(0,0)
         CR    3,2
         BE    @@L169
         L     3,116(13)
         LA    2,110(0,0)
         CR    3,2
         BH    @@L179
         L     3,116(13)
         LA    2,75(0,0)
         CLR   3,2
         BE    @@L172
         B     @@L168
@@L179   EQU   *
         L     3,116(13)
         LA    2,131(0,0)
         CLR   3,2
         BE    @@L175
         B     @@L168
@@L169   EQU   *
         MVC   88(4,13),4(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         L     2,108(13)
         SLR   3,3
         IC    3,2(2)
         LR    2,3
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,108(13)
         SLR   3,3
         IC    3,2(2)
         LR    2,3
         A     2,4(11)
         MVI   0(2),0
         MVC   88(4,13),4(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         B     @@L168
@@L170   EQU   *
         L     2,108(13)
         IC    2,2(2)
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L171
         L     2,0(11)
         A     2,=F'1'
         ST    2,0(11)
         MVC   108(4,13),0(11)
@@L171   EQU   *
         MVC   88(4,13),8(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         L     2,108(13)
         SLR   3,3
         IC    3,2(2)
         LR    2,3
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,108(13)
         SLR   3,3
         IC    3,2(2)
         LR    2,3
         A     2,8(11)
         MVI   0(2),0
         MVC   88(4,13),8(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         B     @@L168
@@L172   EQU   *
         MVC   88(4,13),12(11)
         L     2,108(13)
         A     2,=F'3'
         ST    2,92(13)
         L     2,108(13)
         SLR   3,3
         IC    3,2(2)
         LR    2,3
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,108(13)
         SLR   3,3
         IC    3,2(2)
         LR    2,3
         A     2,12(11)
         MVI   0(2),0
         MVC   88(4,13),12(11)
         MVC   92(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         B     @@L168
@@L173   EQU   *
         L     2,16(11)
         MVC   0(4,2),=F'1'
         B     @@L168
@@L174   EQU   *
         L     2,108(13)
         SLR   3,3
         IC    3,2(2)
         LR    2,3
         A     2,0(11)
         A     2,=F'3'
         ST    2,0(11)
         B     @@L165
@@L175   EQU   *
         L     2,0(11)
         A     2,=F'7'
         ST    2,0(11)
         B     @@L165
@@L168   EQU   *
         L     2,0(11)
         A     2,=F'2'
         ST    2,0(11)
         MVC   112(4,13),=F'0'
@@L180   EQU   *
         L     2,108(13)
         SLR   3,3
         IC    3,1(2)
         L     2,112(13)
         CLR   2,3
         BL    @@L183
         B     @@L165
@@L183   EQU   *
         L     2,0(11)
         SLR   3,3
         IC    3,0(2)
         LR    2,3
         A     2,0(11)
         A     2,=F'1'
         ST    2,0(11)
         L     2,112(13)
         A     2,=F'1'
         ST    2,112(13)
         B     @@L180
@@L165   EQU   *
         MVC   108(4,13),0(11)
         B     @@L163
@@L164   EQU   *
         SLR   2,2
         LR    15,2
* Function 'process_dd' epilogue
         PDPEPIL
* Function 'process_dd' literal pool
         DS    0D
         LTORG
* Function 'process_dd' page table
@@PGT7   DS    0F
         DC    A(@@PG7)
         
&FUNC    SETC 'process_sysout'
@@LC23   EQU   *
         DC    C'process_sysout() null ddname for dsid=%d'
         DC    X'0'
         DS    0F
         EJECT
* static function 'process_sysout' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'process_sysout'
@@10     PDPPRLG CINDEX=8,FRAME=128,BASER=12,ENTRY=NO
         B     @@FEN8
         LTORG
@@FEN8   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG8    EQU   *
         LR    11,1
         L     10,=A(@@PGT8)
* Function 'process_sysout' code
         ST    11,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,104(13)
         MVC   88(4,13),8(11)
         MVC   92(4,13),=F'75'
         LA    1,88(,13)
         L     15,=V(STRRCHR)
         BALR  14,15
         ST    15,112(13)
         L     2,112(13)
         LTR   2,2
         BNE   @@L185
         B     @@L186
@@L185   EQU   *
         LA    2,1(0,0)
         A     2,112(13)
         IC    2,0(2)
         CLM   2,1,=XL1'E2'
         BE    @@L187
         B     @@L186
@@L187   EQU   *
         LA    2,2(0,0)
         A     2,112(13)
         IC    2,0(2)
         CLM   2,1,=XL1'D6'
         BE    @@L188
         B     @@L186
@@L188   EQU   *
         L     2,112(13)
         A     2,=F'3'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         LR    2,15
         STH   2,116(13)
         LH    2,116(13)
         CH    2,=H'0'
         BNE   @@L189
         B     @@L186
@@L189   EQU   *
         L     2,4(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L191
         L     2,4(11)
         IC    2,0(2)
         CLM   2,1,=XL1'40'
         BE    @@L191
         B     @@L190
@@L191   EQU   *
         MVC   88(4,13),4(11)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC23)
         LH    2,116(13)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
@@L190   EQU   *
         MVC   108(4,13),=F'0'
@@L192   EQU   *
         L     2,108(13)
         CL    2,104(13)
         BL    @@L195
         B     @@L186
@@L195   EQU   *
         L     2,108(13)
         MH    2,=H'4'
         A     2,0(11)
         MVC   120(4,13),0(2)
         L     2,120(13)
         LTR   2,2
         BNE   @@L196
         B     @@L194
@@L196   EQU   *
         L     2,120(13)
         LH    2,94(2)
         MVC   80(2,13),116(13)
         CLM   2,3,80(13)
         BNE   @@L194
         L     2,120(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),4(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         A     2,=F'17'
         ST    2,88(13)
         MVC   92(4,13),16(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         A     2,=F'26'
         ST    2,88(13)
         MVC   92(4,13),20(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),8(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         IC    2,80(2)
         CLM   2,1,=XL1'00'
         BNE   @@L198
         L     3,120(13)
         L     2,12(11)
         MVC   80(1,3),0(2)
@@L198   EQU   *
         L     2,120(13)
         MVI   82(2),64
         B     @@L186
@@L194   EQU   *
         L     2,108(13)
         A     2,=F'1'
         ST    2,108(13)
         B     @@L192
@@L186   EQU   *
         SLR   2,2
         LR    15,2
* Function 'process_sysout' epilogue
         PDPEPIL
* Function 'process_sysout' literal pool
         DS    0D
         LTORG
* Function 'process_sysout' page table
@@PGT8   DS    0F
         DC    A(@@PG8)
         
&FUNC    SETC 'process_sysin'
@@LC24   EQU   *
         DC    C'process_sysin() null ddname for dsid=%d'
         DC    X'0'
         DS    0F
         EJECT
* static function 'process_sysin' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'process_sysin'
@@11     PDPPRLG CINDEX=9,FRAME=128,BASER=12,ENTRY=NO
         B     @@FEN9
         LTORG
@@FEN9   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG9    EQU   *
         LR    11,1
         L     10,=A(@@PGT9)
* Function 'process_sysin' code
         ST    11,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,104(13)
         MVC   88(4,13),8(11)
         MVC   92(4,13),=F'75'
         LA    1,88(,13)
         L     15,=V(STRRCHR)
         BALR  14,15
         ST    15,112(13)
         L     2,112(13)
         LTR   2,2
         BNE   @@L200
         B     @@L201
@@L200   EQU   *
         LA    2,1(0,0)
         A     2,112(13)
         IC    2,0(2)
         CLM   2,1,=XL1'E2'
         BE    @@L202
         B     @@L201
@@L202   EQU   *
         LA    2,2(0,0)
         A     2,112(13)
         IC    2,0(2)
         CLM   2,1,=XL1'C9'
         BE    @@L203
         B     @@L201
@@L203   EQU   *
         L     2,112(13)
         A     2,=F'3'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         LR    2,15
         STH   2,116(13)
         LH    2,116(13)
         CH    2,=H'0'
         BNE   @@L204
         B     @@L201
@@L204   EQU   *
         L     2,4(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L206
         L     2,4(11)
         IC    2,0(2)
         CLM   2,1,=XL1'40'
         BE    @@L206
         B     @@L205
@@L206   EQU   *
         MVC   88(4,13),4(11)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC24)
         LH    2,116(13)
         N     2,=XL4'0000FFFF'
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
@@L205   EQU   *
         MVC   108(4,13),=F'0'
@@L207   EQU   *
         L     2,108(13)
         CL    2,104(13)
         BL    @@L210
         B     @@L201
@@L210   EQU   *
         L     2,108(13)
         MH    2,=H'4'
         A     2,0(11)
         MVC   120(4,13),0(2)
         L     2,120(13)
         LTR   2,2
         BNE   @@L211
         B     @@L209
@@L211   EQU   *
         L     2,120(13)
         LH    2,94(2)
         MVC   80(2,13),116(13)
         CLM   2,3,80(13)
         BNE   @@L209
         L     2,120(13)
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),4(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         A     2,=F'17'
         ST    2,88(13)
         MVC   92(4,13),12(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         A     2,=F'26'
         ST    2,88(13)
         MVC   92(4,13),16(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),8(11)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         L     2,120(13)
         MVI   82(2),32
         B     @@L201
@@L209   EQU   *
         L     2,108(13)
         A     2,=F'1'
         ST    2,108(13)
         B     @@L207
@@L201   EQU   *
         SLR   2,2
         LR    15,2
* Function 'process_sysin' epilogue
         PDPEPIL
* Function 'process_sysin' literal pool
         DS    0D
         LTORG
* Function 'process_sysin' page table
@@PGT9   DS    0F
         DC    A(@@PG9)
         
&FUNC    SETC 'is_dup_dsid'
         DS    0F
         EJECT
* static function 'is_dup_dsid' prologue
* frame base=88, local stack=16, call args=8
&FUNC    SETC  'is_dup_dsid'
@@3      PDPPRLG CINDEX=10,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN10
         LTORG
@@FEN10  EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG10   EQU   *
         LR    11,1
         L     10,=A(@@PGT10)
* Function 'is_dup_dsid' code
         ST    11,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15
         ST    2,96(13)
         MVC   100(4,13),=F'0'
@@L214   EQU   *
         L     2,100(13)
         CL    2,96(13)
         BL    @@L217
         B     @@L215
@@L217   EQU   *
         L     2,100(13)
         MH    2,=H'4'
         A     2,0(11)
         MVC   104(4,13),0(2)
         L     2,104(13)
         LTR   2,2
         BNE   @@L218
         B     @@L216
@@L218   EQU   *
         L     2,104(13)
         LH    2,94(2)
         N     2,=XL4'0000FFFF'
         CL    2,4(11)
         BNE   @@L216
         MVC   108(4,13),=F'1'
         B     @@L213
@@L216   EQU   *
         L     2,100(13)
         A     2,=F'1'
         ST    2,100(13)
         B     @@L214
@@L215   EQU   *
         MVC   108(4,13),=F'0'
@@L213   EQU   *
         L     15,108(13)
* Function 'is_dup_dsid' epilogue
         PDPEPIL
* Function 'is_dup_dsid' literal pool
         DS    0D
         LTORG
* Function 'is_dup_dsid' page table
@@PGT10  DS    0F
         DC    A(@@PG10)
         END
