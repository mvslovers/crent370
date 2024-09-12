         TITLE 'Find SSCT by subsystem name'
         ENTRY @@SSCTBN
@@SSCTBN DS    0H
         SAVE  (14,12),,@@SSCTBN
         LA    12,0(,15)               => our base
         USING @@SSCTBN,12
         L     1,0(,1)                 => CL4'subsystem name'
         L     15,FLCCVT-PSA(,0)       => CVT
         L     15,CVTJESCT-CVT(,15)    => JESCT
         L     15,JESSSCT-JESCT(,15)   => SSCT
         USING SSCT,15
AGAIN    DS    0H
         CLC   SSCTSNAM,0(1)           Is this the subsystem?
         BE    RETURN                  Yes, return now
         ICM   15,B'1111',SSCTSCTA     Next subsystem
         BNZ   AGAIN
RETURN   DS    0H
         RETURN (14,12),RC=(15)
         PRINT NOGEN
         IHAPSA
         CVT DSECT=YES
         IEFJESCT
         IEFJSCVT
         END
