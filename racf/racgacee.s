 TITLE '/home/mike/repos/crent370/racf/racgacee.c'
         COPY  PDPTOP
         CSECT
         
&FUNC    SETC 'racf_get_acee'
* Program text area
         DS    0F
         EJECT
* external function 'racf_get_acee' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'racf_get_acee'
RACGACEE PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'racf_get_acee' code
         SLR   2,2
         L     2,548(2)
         L     2,108(2)
         A     2,=F'200'
         L     15,0(2)
* Function 'racf_get_acee' epilogue
         PDPEPIL
* Function 'racf_get_acee' literal pool
         DS    0D
         LTORG
* Function 'racf_get_acee' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
