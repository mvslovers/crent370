         COPY  MVSMACS
         COPY  PDPTOP
         CSECT ,
         PRINT GEN
         SPACE 1
*-----------------------ASSEMBLY OPTIONS------------------------------*
SUBPOOL  EQU   0                                                      *
*---------------------------------------------------------------------*
         SPACE 1
***********************************************************************
*                                                                     *
*  GETM - GET MEMORY                                                  *
*                                                                     *
***********************************************************************
@@GETM   FUNHEAD ,
*
         LDINT R3,0(,R1)          LOAD REQUESTED STORAGE SIZE
         SLR   R1,R1              PRESET IN CASE OF ERROR
         LTR   R4,R3              CHECK REQUEST
         BNP   GETMEX             QUIT IF INVALID
*
* To reduce fragmentation, round up size to 64 byte multiple
*
         A     R3,=A(8+(64-1))    OVERHEAD PLUS ROUNDING
         N     R3,=X'FFFFFFC0'    MULTIPLE OF 64
*
         AIF   ('&SYS' NE 'S380').NOANY
         GETMAIN RU,LV=(R3),SP=SUBPOOL,LOC=ANY
         AGO   .FINANY
.NOANY   ANOP  ,
         GETMAIN RU,LV=(R3),SP=SUBPOOL
.FINANY  ANOP  ,
*
* WE STORE THE AMOUNT WE REQUESTED FROM MVS INTO THIS ADDRESS
         ST    R3,0(,R1)
* AND JUST BELOW THE VALUE WE RETURN TO THE CALLER, WE SAVE
* THE AMOUNT THEY REQUESTED
         ST    R4,4(,R1)
         A     R1,=F'8'
*
GETMEX   FUNEXIT RC=(R1)
         LTORG ,
         END
