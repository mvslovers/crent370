 TITLE '/home/mike/repos/crent370/racf/racsacee.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'racf_set_acee'
* Program text area
         DS    0F
         EJECT
* external function 'racf_set_acee' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'racf_set_acee'
RACSACEE PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'racf_set_acee' code
         L     5,0(11)
         SLR   2,2
         ST    2,88(13)
         ST    2,92(13)
         L     2,548(2)
         L     3,108(2)
         A     3,=F'200'
         L     4,0(3)
         
*
* See if we're in supervisor state
*
         TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1
         ST    15,88(13)
         L     2,88(13)
         LTR   2,2
         BNE   @@L2
         
*
* we're in supervisor state, switch to key 0
*
         IPK   ,
         ST    2,92(13)
         SPKA  0(0)
         ST    5,0(3)
         L     2,92(13)
         
*
* we're in supervisor state, switch back to callers key
*
         SPKA  0(2)
         B     @@L3
@@L2     EQU   *
         
*
* enter supervisor state
*
         MODESET KEY=ZERO,MODE=SUP

         ST    5,0(3)
         
*
* return to problem state
*
         MODESET KEY=NZERO,MODE=PROB

@@L3     EQU   *
         LR    15,4
* Function 'racf_set_acee' epilogue
         PDPEPIL
* Function 'racf_set_acee' literal pool
         DS    0D
         LTORG
* Function 'racf_set_acee' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
