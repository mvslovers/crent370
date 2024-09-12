         COPY  MVSMACS
         COPY  PDPTOP
         CSECT ,
         PRINT GEN
         SPACE 1
***********************************************************************
*                                                                     *
*  GETTZ - Get the offset from GMT in 1.048576 seconds                *
*                                                                     *
***********************************************************************
* @@GETTZ FUNHEAD ,                 get timezone offset
*
*         L     R3,CVTPTR
*         USING CVT,R3
*         L     R4,CVTTZ
*
* RETURNGS FUNEXIT RC=(R4)
*         LTORG ,
         ENTRY @@GETTZ
@@GETTZ  L     R15,CVTPTR
         L     R15,CVTTZ-CVTMAP(,R15)  GET GMT TIME-ZONE OFFSET
         BR    R14
         LTORG ,
         PRINT NOGEN
         IHAPSA ,            MAP LOW STORAGE
         CVT DSECT=YES
         END
