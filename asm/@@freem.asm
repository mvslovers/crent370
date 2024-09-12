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
*  FREEM - FREE MEMORY                                                *
*                                                                     *
***********************************************************************
@@FREEM  FUNHEAD ,
*
         L     R1,0(,R1)
         S     R1,=F'8'
         L     R0,0(,R1)
*
         FREEMAIN RU,LV=(0),A=(1),SP=SUBPOOL
*
         FUNEXIT RC=(15)
         LTORG ,
         END
