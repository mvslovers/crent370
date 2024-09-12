         MACRO ,
&NM      FIXWRITE ,
&NM      L     R15,=V(@@ATROUT)
         BALR  R14,R15       TRUNCATE CURRENT WRITE BLOCK
         MEND  ,
         COPY  MVSMACS
         COPY  PDPTOP
         CSECT ,
         PRINT GEN
*        YREGS
         SPACE 1
*-----------------------ASSEMBLY OPTIONS------------------------------*
SUBPOOL  EQU   0                                                      *
*---------------------------------------------------------------------*
         SPACE 1
***********************************************************************
*                                                                     *
*  AREAD - Read from an open data set                                 *
*                                                                     *
***********************************************************************
@@AREAD  FUNHEAD IO=YES,AM=YES,SAVE=SAVEADCB,US=NO   READ / GET
         L     R3,4(,R1)  R3 points to where to store record pointer
         L     R4,8(,R1)  R4 points to where to store record length
         SR    R0,R0
         ST    R0,0(,R3)          Return null in case of EOF
         ST    R0,0(,R4)          Return null in case of EOF
         FIXWRITE ,               For OUTIN request
         L     R6,=F'-1'          Prepare for EOF signal
         TM    IOPFLAGS,IOFKEPT   Saved record ?
         BZ    READQEOF           No; check for EOF
         LM    R8,R9,KEPTREC      Get prior address & length
         ST    R8,0(,R3)          Set address
         ST    R9,0(,R4)            and length
         XC    KEPTREC(8),KEPTREC Reset record info
         NI    IOPFLAGS,IOFKEPT   Reset flag
         SR    R6,R6              No EOF
         B     READEXIT
         SPACE 1
READQEOF TM    IOPFLAGS,IOFLEOF   Prior EOF ?
         BNZ   READEXIT           Yes; don't abend
         TM    IOMFLAGS,IOFTERM   GETLIN request?
         BNZ   TGETREAD           Yes
*   Return here for end-of-block or unlike concatenation
*
REREAD   SLR   R6,R6              Clear default end-of-file indicator
         ICM   R8,B'1111',BUFFCURR  Load address of next record
         BNZ   DEBLOCK            Block in memory, go de-block it
         L     R8,BUFFADDR        Load address of input buffer
         L     R9,BLKSIZE         Load block size to read
         CLI   RECFMIX,4          RECFM=Vxx ?
         BE    READ               No, deblock
         LA    R8,4(,R8)          Room for fake RDW
READ     GO24  ,                  For old code
         TM    IOMFLAGS,IOFEXCP   EXCP mode?
         BZ    READBSAM           No, use BSAM
*---------------------------------------------------------------------*
*   EXCP read
*---------------------------------------------------------------------*
READEXCP STCM  R8,7,TAPECCW+1     Read buffer
         STH   R9,TAPECCW+6         max length
         MVI   TAPECCW,2          READ
         MVI   TAPECCW+4,X'20'    SILI bit
         EXCP  TAPEIOB            Read
         WAIT  ECB=TAPEECB        wait for completion
         TM    TAPEECB,X'7F'      Good ?
         BO    EXRDOK             Yes; calculate input length
         CLI   TAPEECB,X'41'      Tape Mark read ?
         BNE   EXRDBAD            NO
         CLM   R9,3,IOBCSW+5-IOBSTDRD+TAPEIOB  All unread?
         BNE   EXRDBAD            NO
         L     R1,DCBBLKCT
         BCTR  R1,0
         ST    R1,DCBBLKCT        allow for tape mark
         OI    DCBOFLGS,X'04'     Set tape mark found
         L     R0,ZXCPVOLS        Get current volume count
         SH    R0,=H'1'           Just processed one
         ST    R0,ZXCPVOLS
         BNP   READEOD            None left - take End File
         EOV   TAPEDCB            switch volumes
         B     READEXCP           and restart
         SPACE 1
EXRDBAD  ABEND 001,DUMP           bad way to show error?
         SPACE 1
EXRDOK   SR    R0,R0
         ICM   R0,3,IOBCSW+5-IOBSTDRD+TAPEIOB
         SR    R9,R0         LENGTH READ
         BNP   BADBLOCK      NONE ?
         AMUSE ,                  Restore caller's mode
         LTR   R6,R6              See if end of input data set
         BM    READEOD            Is end, go return to caller
         B     POSTREAD           Go to common code
         SPACE 1
*---------------------------------------------------------------------*
*   BSAM read
*---------------------------------------------------------------------*
READBSAM SR    R6,R6              Reset EOF flag
         GO24 ,                   Get low
         READ  DECB,              Read record Data Event Control Block C
               SF,                Read record Sequential Forward       C
               (R10),             Read record DCB address              C
               (R8),              Read record input buffer             C
               (R9),              Read BLKSIZE or 256 for PDS.DirectoryC
               MF=E               Execute a MF=L MACRO
*                                 If EOF, R6 will be set to F'-1'
         CHECK DECB               Wait for READ to complete
         TM    IOPFLAGS,IOFCONCT  Did we hit concatenation?
         BZ    READUSAM           No; restore user's AM
         NI    IOPFLAGS,255-IOFCONCT   Reset for next time
         ICM   R6,8,DCBRECFM
         SRL   R6,24+2            Isolate top two bits
         STC   R6,RECFMIX         Store
         TR    RECFMIX,=X'01010002'    Filemode D, V, F, U
         MVC   LRECL+2(2),DCBLRECL  Also return record length
         MVC   ZRECFM,DCBRECFM    and format
         B     READBSAM           Reissue the READ
         SPACE 1
READUSAM AMUSE ,                  Restore caller's mode
         LTR   R6,R6              See if end of input data set
         BM    READEOD            Is end, go return to caller
         L     R14,DECB+16    DECIOBPT
         USING IOBSTDRD,R14       Give assembler IOB base
         SLR   R1,R1              Clear residual amount work register
         ICM   R1,B'0011',IOBCSW+5  Load residual count
         DROP  R14                Don't need IOB address base anymore
         SR    R9,R1              Provisionally return blocklen
         SPACE 1
POSTREAD TM    IOMFLAGS,IOFBLOCK  Block mode ?
         BNZ   POSTBLOK           Yes; process as such
         TM    ZRECFM,DCBRECU     Also exit for U
         BNO   POSTREED
POSTBLOK ST    R8,0(,R3)          Return address to user
         ST    R9,0(,R4)          Return length to user
         STM   R8,R9,KEPTREC      Remember record info
         XC    BUFFCURR,BUFFCURR  Show READ required next call
         B     READEXIT
POSTREED CLI   RECFMIX,4          See if RECFM=V
         BNE   EXRDNOTV           Is RECFM=U or F, so not RECFM=V
         ICM   R9,3,0(R8)         Get presumed block length
         C     R9,BLKSIZE         Valid?
         BH    BADBLOCK           No
         ICM   R0,3,2(R8)         Garbage in BDW?
         BNZ   BADBLOCK           Yes; fail
         B     EXRDCOM
EXRDNOTV LA    R0,4(,R9)          Fake length
         SH    R8,=H'4'           Space to fake RDW
         STH   R0,0(0,R8)         Fake RDW
         LA    R9,4(,R9)          Up for fake RDW (F/U)
EXRDCOM  LA    R8,4(,R8)          Bump buffer address past BDW
         SH    R9,=H'4'             and adjust length to match
         BNP   BADBLOCK           Oops
         ST    R8,BUFFCURR        Indicate data available
         ST    R8,0(,R3)          Return address to user
         ST    R9,0(,R4)          Return length to user
         STM   R8,R9,KEPTREC      Remember record info
         LA    R7,0(R9,R8)        End address + 1
         ST    R7,BUFFEND         Save end
         SPACE 1
         TM    IOMFLAGS,IOFBLOCK   Block mode?
         BNZ   READEXIT           Yes; exit
         TM    ZRECFM,DCBRECU     Also exit for U
         BO    READEXIT
*NEXT*   B     DEBLOCK            Else deblock
         SPACE 1
*        R8 has address of current record
DEBLOCK  CLI   RECFMIX,4          Is data set RECFM=U
         BL    DEBLOCKF           Is RECFM=Fx, go deblock it
*
* Must be RECFM=V, VB, VBS, VS, VA, VM, VBA, VBM, VSA, VSM, VBSA, VBSM
*  VBS SDW ( Segment Descriptor Word ):
*  REC+0 length 2 is segment length
*  REC+2 0 is record not segmented
*  REC+2 1 is first segment of record
*  REC+2 2 is last seqment of record
*  REC+2 3 is one of the middle segments of a record
*        R5 has address of current record
DEBLOCKV CLI   0(R8),X'80'   LOGICAL END OF BLOCK ?
         BE    REREAD        YES; DONE WITH THIS BLOCK
         LH    R9,0(,R8)     GET LENGTH FROM RDW
         CH    R9,=H'4'      AT LEAST MINIMUM ?
         BL    BADBLOCK      NO; BAD RECORD OR BAD BLOCK
         C     R9,LRECL      VALID LENGTH ?
         BH    BADBLOCK      NO
         LA    R7,0(R9,R8)   SET ADDRESS OF LAST BYTE +1
         C     R7,BUFFEND    WILL IT FIT INTO BUFFER ?
         BL    DEBVCURR      LOW - LEAVE IT
         BH    BADBLOCK      NO; FAIL
         SR    R7,R7         PRESET FOR BLOCK DONE
DEBVCURR ST    R7,BUFFCURR        for recursion
         TM    3(R8),X'FF'   CLEAN RDW ?
         BNZ   BADBLOCK
         TM    IOPFLAGS,IOFLSDW   WAS PREVIOUS RECORD DONE ?
         BO    DEBVAPND           NO
         LH    R0,0(,R8)          Provisional length if simple
         ST    R0,0(,R4)          Return length
         ST    R0,KEPTREC+4       Remember record info
         CLI   2(R8),1            What is this?
         BL    SETCURR            Simple record
         BH    BADBLOCK           Not=1; have a sequence error
         OI    IOPFLAGS,IOFLSDW   Starting a new segment
         L     R2,VBSADDR         Get start of buffer
         MVC   0(4,R2),=X'00040000'   Preset null record
         B     DEBVMOVE           And move this
DEBVAPND CLI   2(R8),3            IS THIS A MIDDLE SEGMENT ?
         BE    DEBVMOVE           YES, PUT IT OUT
         CLI   2(R8),2            IS THIS THE LAST SEGMENT ?
         BNE   BADBLOCK           No; bad segment sequence
         NI    IOPFLAGS,255-IOFLSDW  INDICATE RECORD COMPLETE
DEBVMOVE L     R2,VBSADDR         Get segment assembly area
         SR    R1,R1              Never trust anyone
         ICM   R1,3,0(R8)         Length of addition
         SH    R1,=H'4'           Data length
         LA    R0,4(,R8)          Skip SDW
         SR    R15,R15
         ICM   R15,3,0(R2)        Get amount used so far
         LA    R14,0(R15,R2)      Address for next segment
         LA    R8,0(R1,R15)       New length
         STH   R8,0(,R2)          Update RDW
         A     R8,VBSADDR         New end address
         C     R8,VBSEND          Will it fit ?
         BH    BADBLOCK
         LR    R15,R1             Move all
         MVCL  R14,R0             Append segment
         TM    IOPFLAGS,IOFLSDW    Did last segment?
         BNZ   REREAD             No; get next one
         L     R8,VBSADDR         Give user the assembled record
         SR    R0,R0
         ICM   R0,3,0(R8)         Provisional length if simple
         ST    R0,0(,R4)          Return length
         ST    R0,KEPTREC+4       Remember record info
         B     SETCURR            Done
         SPACE 2
* If RECFM=FB, bump address by lrecl
*        R8 has address of current record
DEBLOCKF L     R7,LRECL           Load RECFM=F DCB LRECL
         ST    R7,0(,R4)          Return length
         ST    R7,KEPTREC+4       Remember record info
         AR    R7,R8              Find the next record address
* If address=BUFFEND, zero BUFFCURR
SETCURR  CL    R7,BUFFEND         Is it off end of block?
         BL    SETCURS            Is not off, go store it
         SR    R7,R7              Clear the next record address
SETCURS  ST    R7,BUFFCURR        Store the next record address
         ST    R8,0(,R3)          Store record address for caller
         ST    R8,KEPTREC         Remember record info
         B     READEXIT
         SPACE 1
TGETREAD L     R6,ZIOECT          RESTORE ECT ADDRESS
         L     R7,ZIOUPT          RESTORE UPT ADDRESS
         MVI   ZGETLINE+2,X'80'   EXPECTED FLAG
         GO24
         GETLINE PARM=ZGETLINE,ECT=(R6),UPT=(R7),ECB=ZIOECB,           *
               MF=(E,ZIOPL)
         GO31
         LR    R6,R15             COPY RETURN CODE
         CH    R6,=H'16'          HIT BARRIER ?
         BE    READEOD2           YES; EOF, BUT ALLOW READS
         CH    R6,=H'8'           SERIOUS ?
         BNL   READEXNG           ATTENTION INTERRUPT OR WORSE
         L     R1,ZGETLINE+4      GET INPUT LINE
*---------------------------------------------------------------------*
*   MVS 3.8 undocumented behavior: at end of input in batch execution,
*   returns text of 'END' instead of return code 16. Needs DOC fix
*---------------------------------------------------------------------*
         CLC   =X'00070000C5D5C4',0(R1)  Undocumented EOF?
         BNE   TGETNEOF
         XC    KEPTREC(8),KEPTREC Clear saved record info
         LA    R6,1
         LNR   R6,R6              Signal EOF
         B     TGETFREE           FREE BUFFER AND QUIT
TGETNEOF L     R6,BUFFADDR        GET INPUT BUFFER
         LR    R8,R1              INPUT LINE W/RDW
         LH    R9,0(,R1)          GET LENGTH
         LR    R7,R9               FOR V, IN LEN = OUT LEN
         CLI   RECFMIX,4          RECFM=V ?
         BE    TGETHAVE           YES
         BL    TGETSKPF
         SH    R7,=H'4'           ALLOW FOR RDW
         B     TGETSKPV
TGETSKPF L     R7,LRECL             FULL SIZE IF F
TGETSKPV LA    R8,4(,R8)          SKIP RDW
         SH    R9,=H'4'           LENGTH SANS RDW
TGETHAVE ST    R6,0(,R3)          RETURN ADDRESS
         ST    R7,0(,R4)            AND LENGTH
         STM   R6,R7,KEPTREC      Remember record info
         ICM   R9,8,=C' '           BLANK FILL
         MVCL  R6,R8              PRESERVE IT FOR USER
         SR    R6,R6              NO EOF
TGETFREE LH    R0,0(,R1)          GET LENGTH
         ICM   R0,8,=AL1(1)       SUBPOOL 1
         FREEMAIN R,LV=(0),A=(1)  FREE SYSTEM BUFFER
         B     READEXIT           TAKE NORMAL EXIT
         SPACE 1
READEOD  OI    IOPFLAGS,IOFLEOF   Remember that we hit EOF
READEOD2 XC    KEPTREC(8),KEPTREC Clear saved record info
         LA    R6,1
READEXNG LNR   R6,R6              Signal EOF
READEXIT FUNEXIT RC=(R6) =1-EOF   Return to caller
*
BADBLOCK WTO   'MVSSUPA - @@AREAD - problem processing RECFM=V(bs) file*
               ',ROUTCDE=11       Send to programmer and listing
         ABEND 1234,DUMP          Abend U1234 and allow a dump
*
         LTORG ,                  In case someone adds literals
*
         SPACE 2
         COPY  CLIBSUPA
*
         SPACE 2
         PRINT NOGEN
         IHAPSA ,            MAP LOW STORAGE
         CVT DSECT=YES
         IKJTCB ,            MAP TASK CONTROL BLOCK
         IKJECT ,            MAP ENV. CONTROL BLOCK
         IKJPTPB ,           PUTLINE PARAMETER BLOCK
         IKJCPPL ,
         IKJPSCB ,
         IEZJSCB ,
         IEZIOB ,
         IEFZB4D0 ,          MAP SVC 99 PARAMETER LIST
         IEFZB4D2 ,          MAP SVC 99 PARAMETERS
         IEFUCBOB ,
MYTIOT   DSECT ,
         IEFTIOT1 ,
         IHAPDS PDSBLDL=YES
         SPACE 1
         IFGACB ,                                               GP14233
         SPACE 1
         IFGRPL ,                                               GP14233
         IEFJESCT ,
         IKJUPT ,
         END
