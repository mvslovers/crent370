R0       EQU   0
R1       EQU   1
R2       EQU   2
R3       EQU   3
R4       EQU   4
R5       EQU   5
R6       EQU   6
R7       EQU   7
R8       EQU   8
R9       EQU   9
R10      EQU   10
R11      EQU   11
R12      EQU   12
R13      EQU   13
R14      EQU   14
R15      EQU   15
         ENTRY GETTZOFF
GETTZOFF DS    0H
         STM   R0,R12,20(R13)    Save the register we're using
         LA    R12,0(,R15)
         USING GETTZOFF,R12
*
         L     R15,CVTPTR
         L     R15,CVTTZ-CVTMAP(,R15)  GET GMT TIME-ZONE OFFSET
* The CVTTZ value offset is in 1.048576 second increments.
* The maximum offset people have managed to define is 14 hours
* (Kirribati) and when mulplied by 16384, this doesn't exceed a 32-bit
* signed integer, so we're safe.
*
* However, the TZ offset value is actually truncated, e.g. -27465.8
* is stored as -27465, which combined with the 1.048576 granularity
* means that we don't have 1-second accuracy.
* So we round to the nearest minute.
         LR    4,15
         SLL   4,14              o = o * 16384;
         SRDA  4,32
         L     8,=F'15625'
         DR    4,8               o /= 15625
*
         SR    2,2
         SRDA  2,32
         LA    8,60
         DR    2,8               r = o % 60
*
         SR    6,6
         SRDA  6,32
         DR    6,8               o /= 60 convert to minutes
*
         LR    15,7
         LTR   7,7
         BL    GETTZ010
         LA    3,29
         CR    2,3
         BNH   GETTZ010
         A     15,=F'1'          o += 1
         B     GETTZ020
GETTZ010 DS    0H
         LTR   15,15
         BH    GETTZ020
         L     8,=F'-30'
         CR    2,8
         BH    GETTZ020
         BCTR  15,0              o -= 1
GETTZ020 DS    0H
         LR    2,15
         SLL   2,4
         SR    2,15
         SLL   2,2               o = o * 60 convert to seconds
         LR    R15,R2            Time zone offset
         LM    R0,R12,20(R13)    Restore registers we used
         BR    R14
         LTORG
         IHAPSA
         CVT DSECT=YES
         END
