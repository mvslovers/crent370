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
*
*
*
* Start of functions
*
*
***********************************************************************
*                                                                     *
*  AOPEN - Open a data set                                            *
*                                                                     *
***********************************************************************
*                                                                     *
*  Parameters are:                                                    *
*1 DDNAME - space-padded, 8 character DDNAME to be opened             *
*2 MODE =  0 INPUT  1 OUTPUT  2 UPDAT   3 APPEND      Record mode     *
*  MODE =  4 INOUT  5 OUTIN                                           *
*  MODE = 8/9 Use EXCP for tape, BSAM otherwise (or 32<=JFCPNCP<=65)  *
*  MODE + 10 = Use BLOCK mode (valid 10-15)                           *
*  MODE = 80 = GETLINE, 81 = PUTLINE (other bits ignored)             *
*    N.B.: see comments under Return value
*3 RECFM - 0 = F, 1 = V, 2 = U. Default/preference set by caller;     *
*                               actual value returned from open.      *
*4 LRECL   - Default/preference set by caller; OPEN value returned.   *
*5 BLKSIZE - Default/preference set by caller; OPEN value returned.   *
*                                                                     *
* August 2009 revision - caller will pass preferred RECFM (coded 0-2) *
*    LRECL, and BLKSIZE values. DCB OPEN exit OCDCBEX will use these  *
*    defaults when not specified on JCL or DSCB merge.                *
*                                                                     *
*6 ZBUFF2 - pointer to an area that may be written to (size is LRECL) *
*7 MEMBER - *pointer* to space-padded, 8 character member name.       *
*    A member name beginning with blank or hex zero is ignored.       *
*    If pointer is 0 (NULL), no member is requested                   *
*                                                                     *
*  Return value:                                                      *
*  An internal "handle" that allows the assembler routines to         *
*  keep track of what's what, when READ etc are subsequently          *
*  called.                                                            *
*                                                                     *
*  All passed parameters are subject to overrides based on device     *
*  capabilities and capacities, e.g., blocking may be turned off.     *
*  In particular, the MODE flag will have x'40' ORed in for a         *
*  unit record device.                                                *
*                                                                     *
*                                                                     *
*  Note - more documentation for this and other I/O functions can     *
*  be found halfway through the stdio.c file in PDPCLIB.              *
*                                                                     *
* Here are some of the errors reported:                               *
*                                                                     *
*  OPEN input failed return code is: -37                              *
*  OPEN output failed return code is: -39                             *
*                                                                     *
* FIND input member return codes are:                                 *
* Original, before the return and reason codes had                    *
* negative translations added refer to copyrighted:                   *
* DFSMS Macro Instructions for Data Sets                              *
* RC = 0 Member was found.                                            *
* RC = -1024 Member not found.                                        *
* RC = -1028 RACF allows PDSE EXECUTE, not PDSE READ.                 *
* RC = -1032 PDSE share not available.                                *
* RC = -1036 PDSE is OPENed output to a different member.             *
* RC = -2048 Directory I/O error.                                     *
* RC = -2052 Out of virtual storage.                                  *
* RC = -2056 Invalid DEB or DEB not on TCB or TCBs DEB chain.         *
* RC = -2060 PDSE I/O error flushing system buffers.                  *
* RC = -2064 Invalid FIND, no DCB address.                            *
*                                                                     *
***********************************************************************
         PUSH  USING
@@AOPEN  FUNHEAD SAVE=(WORKAREA,OPENLEN,SUBPOOL)
         LR    R11,R1             KEEP R11 FOR PARAMETERS
         USING PARMSECT,R11       MAKE IT EASIER TO READ
         L     R3,PARM1           R3 POINTS TO DDNAME
* Note that R5 is used as a scratch register
         L     R8,PARM4           R8 POINTS TO LRECL
* PARM5    has BLKSIZE
* PARM6    has ZBUFF2 pointer
         L     R9,PARM7           R9 POINTS TO MEMBER NAME (OF PDS)
         LA    R9,00(,R9)         Strip off high-order bit or byte
         TM    0(R9),255-X'40'    Either blank or zero?
         BNZ   *+6                  No
         SR    R9,R9              Set for no member
         SPACE 1
         L     R4,PARM2           R4 is the MODE.  0=input 1=output
         CH    R4,=H'256'         Call with value?
         BL    *+8                Yes; else pointer
         L     R4,0(,R4)          Load C/370 MODE.  0=input 1=output
         SPACE 1
         AIF   ('&SYS' NE 'S390').NOLOW
         GETMAIN R,LV=ZDCBLEN,SP=SUBPOOL,LOC=BELOW
         AGO   .FINLOW
.NOLOW   GETMAIN R,LV=ZDCBLEN,SP=SUBPOOL
.FINLOW  LR    R10,R1             Addr.of storage obtained to its base
         USING IHADCB,R10         Give assembler DCB area base register
         LR    R0,R10             Load output DCB area address
         LA    R1,ZDCBLEN         Load output length of DCB area
         LA    R15,0              Pad of X'00' and no input length
         MVCL  R0,R14             Clear DCB area to binary zeroes
*---------------------------------------------------------------------*
*   GET USER'S DEFAULTS HERE, BECAUSE THEY MAY GET CHANGED
*---------------------------------------------------------------------*
         L     R5,PARM3    HAS RECFM code (0-FB 1-VB 2-U)
         L     R14,0(,R5)         LOAD RECFM VALUE
         STC   R14,FILEMODE       PASS TO OPEN
         L     R14,0(,R8)         GET LRECL VALUE
         ST    R14,LRECL          PASS TO OPEN
         L     R14,PARM5          R14 POINTS TO BLKSIZE
         L     R14,0(,R14)        GET BLOCK SIZE
         ST    R14,BLKSIZE        PASS TO OPEN
         SPACE 1
*---------------------------------------------------------------------*
*   DO THE DEVICE TYPE NOW TO CHECK WHETHER EXCP IS POSSIBLE
*     ALSO BYPASS STUFF IF USER REQUESTED TERMINAL I/O
*---------------------------------------------------------------------*
OPCURSE  STC   R4,WWORK           Save to storage
         STC   R4,WWORK+1         Save to storage
         NI    WWORK+1,7          Retain only open mode bits
         TM    WWORK,IOFTERM      Terminal I/O ?
         BNZ   TERMOPEN           Yes; do completely different
***> Consider forcing terminal mode if DD is a terminal?
         MVC   DWDDNAM,0(R3)      Move below the line
         DEVTYPE DWDDNAM,DWORK    Check device type
         BXH   R15,R15,FAILDCB    DD missing
         ICM   R0,15,DWORK+4      Any device size ?
         BNZ   OPHVMAXS
         MVC   DWORK+6(2),=H'32760'    Set default max
         SPACE 1
OPHVMAXS CLI   WWORK+1,3          Append requested ?
         BNE   OPNOTAP            No
         TM    DWORK+2,UCB3TAPE+UCB3DACC    TAPE or DISK ?
         BM    OPNOTAP            Yes; supported
         NI    WWORK,255-2        Change to plain output
*OR-FAIL BNM   FAILDCB            No, not supported
         SPACE 1
OPNOTAP  CLI   WWORK+1,2          UPDAT request?
         BNE   OPNOTUP            No
         CLI   DWORK+2,UCB3DACC   DASD ?
         BNE   FAILDCB            No, not supported
         SPACE 1
OPNOTUP  CLI   WWORK+1,4          INOUT or OUTIN ?
         BL    OPNOTIO            No
         TM    DWORK+2,UCB3TAPE+UCB3DACC    TAPE or DISK ?
         BNM   FAILDCB            No; not supported
         SPACE 1
OPNOTIO  TM    WWORK,IOFEXCP      EXCP requested ?
         BZ    OPFIXMD2
         CLI   DWORK+2,UCB3TAPE   TAPE/CARTRIDGE device?
         BE    OPFIXMD1           Yes; wonderful ?
OPFIXMD0 NI    WWORK,255-IOFEXCP  Cancel EXCP request
         B     OPFIXMD2
OPFIXMD1 L     R0,BLKSIZE         GET USER'S SIZE
         CH    R0,=H'32760'       NEED EXCP ?
         BNH   OPFIXMD0           NO; USE BSAM
         ST    R0,DWORK+4              Increase max size
         ST    R0,LRECL           ALSO RECORD LENGTH
         MVI   FILEMODE,2         FORCE RECFM=U
         SPACE 1
OPFIXMD2 IC    R4,WWORK           Fix up
OPFIXMOD STC   R4,WWORK           Save to storage
         MVC   IOMFLAGS,WWORK     Save for duration
         SPACE 1
*---------------------------------------------------------------------*
*   Do as much common code for input and output before splitting
*   Set mode flag in Open/Close list
*   Move BSAM, QSAM, or EXCP DCB to work area
*---------------------------------------------------------------------*
         STC   R4,OPENCLOS        Initialize MODE=24 OPEN/CLOSE list
         NI    OPENCLOS,X'07'        For now
*                  OPEN mode: IN OU UP AP IO OI
         TR    OPENCLOS(1),=X'80,8F,84,8E,83,86,0,0'
         CLI   OPENCLOS,0         NOT SUPPORTED ?
         BE    FAILDCB            FAIL REQUEST
         SPACE 1
         TM    WWORK,IOFEXCP      EXCP mode ?
         BZ    OPQRYBSM
         MVC   ZDCBAREA(EXCPDCBL),EXCPDCB  Move DCB/IOB/CCW
         LA    R15,TAPEIOB   FOR EASIER SETTINGS
         USING IOBSTDRD,R15
         MVI   IOBFLAG1,IOBDATCH+IOBCMDCH   COMMAND CHAINING IN USE
         MVI   IOBFLAG2,IOBRRT2
         LA    R1,TAPEECB
         ST    R1,IOBECBPT
         LA    R1,TAPECCW
         ST    R1,IOBSTART   CCW ADDRESS
         ST    R1,IOBRESTR   CCW ADDRESS
         LA    R1,TAPEDCB
         ST    R1,IOBDCBPT   DCB
         LA    R1,TAPEIOB
         STCM  R1,7,DCBIOBAA LINK IOB TO DCB FOR DUMP FORM.ING
         LA    R0,1          SET BLOCK COUNT INCREMENT
         STH   R0,IOBINCAM
         DROP  R15
         B     OPREPCOM
         SPACE 1
OPQRYBSM TM    WWORK,IOFBLOCK     Block mode ?
         BNZ   OPREPBSM
         TM    WWORK,X'01'        In or Out
*DEFUNCT BNZ   OPREPQSM
OPREPBSM MVC   ZDCBAREA(BSAMDCBL),BSAMDCB  Move DCB template to work
         TM    DWORK+2,UCB3DACC+UCB3TAPE    Tape or Disk ?
         BM    OPREPCOM           Either; keep RP,WP
         NC    DCBMACR(2),=AL1(DCBMRRD,DCBMRWRT) Strip Point
         B     OPREPCOM
         SPACE 1
OPREPQSM MVC   ZDCBAREA(QSAMDCBL),QSAMDCB
OPREPCOM MVC   DCBDDNAM,0(R3)
         MVC   DEVINFO(8),DWORK   Check device type
         ICM   R0,15,DEVINFO+4    Any ?
         BZ    FAILDCB            No DD card or ?
         N     R4,=X'000000EF'    Reset block mode
         TM    WWORK,IOFTERM      Terminal I/O?
         BNZ   OPFIXMOD
         TM    WWORK,IOFBLOCK           Blocked I/O?
         BZ    OPREPJFC
         CLI   DEVINFO+2,UCB3UREC Unit record?
         BE    OPFIXMOD           Yes, may not block
         SPACE 1
OPREPJFC LA    R14,JFCB
* EXIT TYPE 07 + 80 (END OF LIST INDICATOR)
         ICM   R14,B'1000',=X'87'
         ST    R14,DCBXLST+4
         LA    R14,OCDCBEX        POINT TO DCB EXIT
* Both S380 and S390 operate in 31-bit mode so need a stub
         AIF   ('&SYS' EQ 'S370').NODP24
         ST    R14,DOPE31         Address of 31-bit exit
         OI    DOPE31,X'80'       Set high bit = AMODE 31
         MVC   DOPE24,DOPEX24     Move in stub code
         LA    R14,DOPE24         Switch to 24-bit stub
.NODP24  ANOP  ,
         ICM   R14,8,=X'05'         REQUEST IT
         ST    R14,DCBXLST        AND SET IT BACK
         LA    R14,DCBXLST
         STCM  R14,B'0111',DCBEXLSA
         MVC   EOFR24(EOFRLEN),ENDFILE   Put EOF code below the line
         LA    R1,EOFR24
         STCM  R1,B'0111',DCBEODA
         RDJFCB ((R10)),MF=(E,OPENCLOS)  Read JOB File Control Blk
*---------------------------------------------------------------------*
*   If the caller did not request EXCP mode, but the user has BLKSIZE
*   greater than 32760 on TAPE, then we set the EXCP bit in R4 and
*   restart the OPEN. Otherwise MVS should fail?
*   The system fails explicit BLKSIZE in excess of 32760, so we cheat.
*   The NCP field is not otherwise honored, so if the value is 32 to
*   64 inclusive, we use that times 1024 as a value (max 65535)
*---------------------------------------------------------------------*
         CLI   DEVINFO+2,UCB3TAPE TAPE DEVICE?
         BNE   OPNOTBIG           NO
         TM    WWORK,IOFEXCP      USER REQUESTED EXCP ?
         BNZ   OPVOLCNT           NOTHING TO DO
         CLI   JFCNCP,32          LESS THAN MIN ?
         BL    OPNOTBIG           YES; IGNORE
         CLI   JFCNCP,65          NOT TOO HIGH ?
         BH    OPNOTBIG           TOO BAD
*---------------------------------------------------------------------*
*   Clear DCB wrk area and force RECFM=U,BLKSIZE>32K
*     and restart the OPEN processing
*---------------------------------------------------------------------*
         LR    R0,R10             Load output DCB area address
         LA    R1,ZDCBLEN         Load output length
         LA    R15,0              Pad of X'00'
         MVCL  R0,R14             Clear DCB area to zeroes
         SR    R0,R0
         ICM   R0,1,JFCNCP        NUMBER OF CHANNEL PROGRAMS
         SLL   R0,10              *1024
         C     R0,=F'65535'       LARGER THAN CCW SUPPORTS?
         BL    *+8                NO
         L     R0,=F'65535'       LOAD MAX SUPPORTED
         ST    R0,BLKSIZE         MAKE NEW VALUES THE DEFAULT
         ST    R0,LRECL           MAKE NEW VALUES THE DEFAULT
         MVI   FILEMODE,2         USE RECFM=U
         LA    R0,IOFEXCP         GET EXCP OPTION
         OR    R4,R0              ADD TO USER'S REQUEST
         B     OPCURSE            AND RESTART THE OPEN
         SPACE 1
OPVOLCNT SR    R1,R1
         ICM   R1,1,JFCBVLCT      GET VOLUME COUNT FROM DD
         BNZ   *+8                OK
         LA    R1,1               SET FOR ONE
         ST    R1,ZXCPVOLS        SAVE FOR EOV
         SPACE 1
OPNOTBIG CLI   DEVINFO+2,UCB3DACC   Is it a DASD device?
         BNE   OPNODSCB           No; no member name supported
*---------------------------------------------------------------------*
*   For a DASD resident file, get the format 1 DSCB
*---------------------------------------------------------------------*
* CAMLST CAMLST SEARCH,DSNAME,VOLSER,DSCB+44
*
         L     R14,CAMDUM         Get CAMLST flags
         LA    R15,JFCBDSNM       Load address of output data set name
         LA    R0,JFCBVOLS        Load addr. of output data set volser
         LA    R1,DS1FMTID        Load address of where to put DSCB
         STM   R14,R1,CAMLST      Complete CAMLST addresses
         OBTAIN CAMLST            Read the VTOC record
         SPACE 1
* The member name may not be below the line, which may stuff up
* the "FIND" macro, so make sure it is in 24-bit memory.
OPNODSCB LTR   R9,R9              See if an address for the member name
         BZ    NOMEM              No member name, skip copying
         MVC   MEMBER24,0(R9)
         LA    R9,MEMBER24
         SPACE 1
*---------------------------------------------------------------------*
*   Split READ and WRITE paths
*     Note that all references to DCBRECFM, DCBLRECL, and DCBBLKSI
*     have been replaced by ZRECFM, LRECL, and BLKSIZE for EXCP use.
*---------------------------------------------------------------------*
NOMEM    TM    WWORK,1            See if OPEN input or output
         BNZ   WRITING
*---------------------------------------------------------------------*
*
* READING
*   N.B. moved RDJFCB prior to member test to allow uniform OPEN and
*        other code. Makes debugging and maintenance easier
*
*---------------------------------------------------------------------*
         OI    JFCBTSDM,JFCNWRIT  Don't mess with DSCB
         CLI   DEVINFO+2,UCB3DACC   Is it a DASD device?
         BNE   OPENVSEQ           No; no member name supported
*---------------------------------------------------------------------*
* See if DSORG=PO but no member; use member from JFCB if one
*---------------------------------------------------------------------*
         TM    DS1DSORG,DS1DSGPO  See if DSORG=PO
         BZ    OPENVSEQ           Not PDS, don't read PDS directory
         TM    WWORK,X'07'   ANY NON-READ OPTION ?
         BNZ   FAILDCB            NOT ALLOWED FOR PDS
         LTR   R9,R9              See if an address for the member name
         BNZ   OPENMEM            Is member name - BPAM access
         TM    JFCBIND1,JFCPDS    See if a member name in JCL
         BZ    OPENDIR            No; read directory
         MVC   MEMBER24,JFCBELNM  Save the member name
         NI    JFCBIND1,255-JFCPDS    Reset it
         XC    JFCBELNM,JFCBELNM  Delete it in JFCB
         LA    R9,MEMBER24        Force FIND to prevent 013 abend
         B     OPENMEM            Change DCB to BPAM PO
*---------------------------------------------------------------------*
* At this point, we have a PDS but no member name requested.
* Request must be to read the PDS directory
*---------------------------------------------------------------------*
OPENDIR  TM    OPENCLOS,X'0F'     Other than plain OPEN ?
         BNZ   BADOPIN            No, fail (allow UPDAT later?)
         LA    R0,256             Set size for Directory BLock
         STH   R0,DCBBLKSI        Set DCB BLKSIZE to 256
         STH   R0,DCBLRECL        Set DCB LRECL to 256
         ST    R0,LRECL
         ST    R0,BLKSIZE
         MVI   DCBRECFM,DCBRECF   Set DCB RECFM to RECFM=F (notU?)
         B     OPENIN
OPENMEM  MVI   DCBDSRG1,DCBDSGPO  Replace DCB DSORG=PS with PO
         OI    JFCBTSDM,JFCVSL    Force OPEN analysis of JFCB
         B     OPENIN
OPENVSEQ LTR   R9,R9              Member name for sequential?
         BNZ   BADOPIN            Yes, fail
         TM    IOMFLAGS,IOFEXCP   EXCP mode ?
         BNZ   OPENIN             YES
         OI    DCBOFLGS,DCBOFPPC  Allow unlike concatenation
OPENIN   OPEN  MF=(E,OPENCLOS),TYPE=J  Open the data set
         TM    DCBOFLGS,DCBOFOPN  Did OPEN work?
         BZ    BADOPIN            OPEN failed, go return error code -37
         LTR   R9,R9              See if an address for the member name
         BZ    GETBUFF            No member name, skip finding it
*
         FIND  (R10),(R9),D       Point to the requested member
*
         LTR   R15,R15            See if member found
         BZ    GETBUFF            Member found, go get an input buffer
* If FIND return code not zero, process return and reason codes and
* return to caller with a negative return code.
         SLL   R15,8              Shift return code for reason code
         OR    R15,R0             Combine return code and reason code
         LR    R7,R15             Number to generate return and reason
         CLOSE MF=(E,OPENCLOS)    Close, FREEPOOL not needed
         B     FREEDCB
BADOPIN  DS    0H
BADOPOUT DS    0H
FAILDCB  N     R4,=F'1'           Mask other option bits
         LA    R7,37(R4,R4)       Preset OPEN error code
FREEDCB  FREEMAIN R,LV=ZDCBLEN,A=(R10),SP=SUBPOOL  Free DCB area
         LCR   R7,R7              Set return and reason code
         B     RETURNOP           Go return to caller with negative RC
         SPACE 1
*---------------------------------------------------------------------*
*   Process for OUTPUT mode
*---------------------------------------------------------------------*
WRITING  LTR   R9,R9
         BZ    WNOMEM
         CLI   DEVINFO+2,UCB3DACC   DASD ?
         BNE   BADOPOUT           Member name invalid
         TM    DS1DSORG,DS1DSGPO  See if DSORG=PO
         BZ    BADOPOUT           Is not PDS, fail request
         TM    WWORK,X'06'   ANY NON-RITE OPTION ?
         BNZ   FAILDCB            NOT ALLOWED FOR PDS
         MVC   JFCBELNM,0(R9)
         OI    JFCBIND1,JFCPDS
         OI    JFCBTSDM,JFCVSL    Just in case
         B     WNOMEM2            Go to move DCB info
WNOMEM   DS    0H
         TM    JFCBIND1,JFCPDS    See if a member name in JCL
         BO    WNOMEM2            Is member name, go to continue OPEN
* See if DSORG=PO but no member so OPEN output would destroy directory
         TM    DS1DSORG,DS1DSGPO  See if DSORG=PO
         BZ    WNOMEM2            Is not PDS, go OPEN
         WTO   'MVSSUPA - No member name for output PDS',ROUTCDE=11
         WTO   'MVSSUPA - Refuses to write over PDS directory',        C
               ROUTCDE=11
         ABEND 123                Abend without a dump
         SPACE 1
WNOMEM2  OPEN  MF=(E,OPENCLOS),TYPE=J
         TM    DCBOFLGS,DCBOFOPN  Did OPEN work?
         BZ    BADOPOUT           OPEN failed, go return error code -39
         SPACE 1
*---------------------------------------------------------------------*
*   Acquire one BLKSIZE buffer for our I/O; and one LRECL buffer
*   for use by caller for @@AWRITE, and us for @@AREAD.
*---------------------------------------------------------------------*
GETBUFF  L     R5,BLKSIZE         Load the input blocksize
         LA    R6,4(,R5)          Add 4 in case RECFM=U buffer
         GETMAIN R,LV=(R6),SP=SUBPOOL  Get input buffer storage
         ST    R1,ZBUFF1          Save for cleanup
         ST    R6,ZBUFF1+4           ditto
         ST    R1,BUFFADDR        Save the buffer address for READ
         XC    0(4,R1),0(R1)      Clear the RECFM=U Record Desc. Word
         LA    R14,0(R5,R1)       Get end address
         ST    R14,BUFFEND          for real
         SPACE 1
         L     R6,LRECL           Get record length
         LA    R6,4(,R6)          Insurance
         GETMAIN R,LV=(R6),SP=SUBPOOL  Get VBS build record area
         ST    R1,ZBUFF2          Save for cleanup
         ST    R6,ZBUFF2+4           ditto
         LA    R14,4(,R1)
         ST    R14,VBSADDR        Save the VBS read/user write
         L     R5,PARM6           Get caller's BUFFER address
         ST    R14,0(,R5)         and return work address
         AR    R1,R6              Add size GETMAINed to find end
         ST    R1,VBSEND          Save address after VBS rec.build area
         B     DONEOPEN           Go return to caller with DCB info
         SPACE 1
         PUSH  USING
*---------------------------------------------------------------------*
*   Establish ZDCBAREA for either @@AWRITE or @@AREAD processing to
*   a terminal, or SYSTSIN/SYSTERM in batch.
*---------------------------------------------------------------------*
TERMOPEN MVC   IOMFLAGS,WWORK     Save for duration
         NI    IOMFLAGS,IOFTERM+IOFOUT      IGNORE ALL OTHERS
         MVC   ZDCBAREA(TERMDCBL),TERMDCB  Move DCB/IOB/CCW
         MVC   ZIODDNM,0(R3)      DDNAME FOR DEBUGGING, ETC.
         LTR   R9,R9              See if an address for the member name
         BNZ   FAILDCB            Yes; fail
         L     R14,PSATOLD-PSA    GET MY TCB
         USING TCB,R14
         ICM   R15,15,TCBJSCB  LOOK FOR THE JSCB
         BZ    FAILDCB       HUH ?
         USING IEZJSCB,R15
         ICM   R15,15,JSCBPSCB  PSCB PRESENT ?
         BZ    FAILDCB       NO; NOT TSO
         L     R1,TCBFSA     GET FIRST SAVE AREA
         N     R1,=X'00FFFFFF'    IN CASE AM31
         L     R1,24(,R1)         LOAD INVOCATION R1
         USING CPPL,R1       DECLARE IT
         MVC   ZIOECT,CPPLECT
         MVC   ZIOUPT,CPPLUPT
         SPACE 1
         ICM   R6,15,BLKSIZE      Load the input blocksize
         BP    *+12               Use it
         LA    R6,1024            Arbitrary non-zero size
         ST    R6,BLKSIZE         Return it
         ST    R6,LRECL           Return it
         LA    R6,4(,R6)          Add 4 in case RECFM=U buffer
         GETMAIN R,LV=(R6),SP=SUBPOOL  Get input buffer storage
         ST    R1,ZBUFF2          Save for cleanup
         ST    R6,ZBUFF2+4           ditto
         LA    R1,4(,R1)          Allow for RDW if not V
         ST    R1,BUFFADDR        Save the buffer address for READ
         L     R5,PARM6           R5 points to ZBUFF2
         ST    R1,0(,R5)          save the pointer
         XC    0(4,R1),0(R1)      Clear the RECFM=U Record Desc. Word
         MVC   ZRECFM,FILEMODE    Requested format 0-2
         NI    ZRECFM,3           Just in case
         TR    ZRECFM,=X'8040C0C0'    Change to F / V / U
         POP   USING
         SPACE 1
*   Lots of code tests DCBRECFM twice, to distinguish among F, V, and
*     U formats. We set the index byte to 0,4,8 to allow a single test
*     with a three-way branch.
DONEOPEN LR    R7,R10             Return DCB/file handle address
         LA    R0,8
         TM    ZRECFM,DCBRECU     Undefined ?
         BO    SETINDEX           Yes
         BM    GETINDFV           No
         TM    ZRECFM,DCBRECTO    RECFM=D
         BZ    SETINDEX           No; treat as U
         B     SETINDVD
GETINDFV SR    R0,R0              Set for F
         TM    ZRECFM,DCBRECF     Fixed ?
         BNZ   SETINDEX           Yes
SETINDVD LA    R0,4               Preset for V
SETINDEX STC   R0,RECFMIX         Save for the duration
         SRL   R0,2               Convert to caller's code
         L     R5,PARM3           POINT TO RECFM
         ST    R0,0(,R5)          Pass either RECFM F or V to caller
         L     R1,LRECL           Load RECFM F or V max. record length
         ST    R1,0(,R8)          Return record length back to caller
         L     R5,PARM5           POINT TO BLKSIZE
         L     R0,BLKSIZE         Load RECFM U maximum record length
         ST    R0,0(,R5)          Pass new BLKSIZE
         L     R5,PARM2           POINT TO MODE
         MVC   3(1,R5),IOMFLAGS   Pass (updated) file mode back
         CLI   DEVINFO+2,UCB3UREC
         BNE   NOTUNREC           Not unit-record
         OI    3(R5),IOFUREC      flag unit-record
NOTUNREC DS    0H
*
* Finished with R5 now
*
RETURNOP FUNEXIT RC=(R7)          Return to caller
*
* This is not executed directly, but copied into 24-bit storage
ENDFILE  LA    R6,1               Indicate @@AREAD reached end-of-file
         LNR   R6,R6              Make negative
         BR    R14                Return to instruction after the GET
EOFRLEN  EQU   *-ENDFILE
*
         LTORG ,
         SPACE 1
BSAMDCB  DCB   MACRF=(RP,WP),DSORG=PS,DDNAME=BSAMDCB, input and output *
               EXLST=1-1          JFCB and DCB exits added later
BSAMDCBN EQU   *-BSAMDCB
READDUM  READ  NONE,              Read record Data Event Control Block *
               SF,                Read record Sequential Forward       *
               ,       (R10),     Read record DCB address              *
               ,       (R4),      Read record input buffer             *
               ,       (R5),      Read BLKSIZE or 256 for PDS.Directory*
               MF=L               List type MACRO
READLEN  EQU   *-READDUM
BSAMDCBL EQU   *-BSAMDCB
         SPACE 1
EXCPDCB  DCB   DDNAME=EXCPDCB,MACRF=E,DSORG=PS,REPOS=Y,BLKSIZE=0,      *
               DEVD=TA,EXLST=1-1,RECFM=U
         DC    8XL4'0'         CLEAR UNUSED SPACE
         ORG   EXCPDCB+84    LEAVE ROOM FOR DCBLRECL
         DC    F'0'          VOLUME COUNT
PATCCW   CCW   1,2-2,X'40',3-3
         ORG   ,
EXCPDCBL EQU   *-EXCPDCB     PATTERN TO MOVE
         SPACE 1
TERMDCB  PUTLINE MF=L        PATTERN FOR TERMINAL I/O
TERMDCBL EQU   *-TERMDCB     SIZE OF IOPL
         SPACE 1
F65536   DC    F'65536'           Maximum VBS record GETMAIN length
*
* QSAMDCB changes depending on whether we are in LOCATE mode or
* MOVE mode
QSAMDCB  DCB   MACRF=P&OUTM.M,DSORG=PS,DDNAME=QSAMDCB
QSAMDCBL EQU   *-QSAMDCB
*
*
* CAMDUM CAMLST SEARCH,DSNAME,VOLSER,DSCB+44
CAMDUM   CAMLST SEARCH,*-*,*-*,*-*
CAMLEN   EQU   *-CAMDUM           Length of CAMLST Template
         POP   USING
         SPACE 1
*---------------------------------------------------------------------*
*   Expand OPEN options for reference
*---------------------------------------------------------------------*
ADHOC    DSECT ,
OPENREF  OPEN  (BSAMDCB,INPUT),MF=L    QSAM, BSAM, any DEVTYPE
         OPEN  (BSAMDCB,OUTPUT),MF=L   QSAM, BSAM, any DEVTYPE
         OPEN  (BSAMDCB,UPDAT),MF=L    QSAM, BSAM, DASD
         OPEN  (BSAMDCB,EXTEND),MF=L   QSAM, BSAM, DASD, TAPE
         OPEN  (BSAMDCB,INOUT),MF=L          BSAM, DASD, TAPE
         OPEN  (BSAMDCB,OUTINX),MF=L         BSAM, DASD, TAPE
         OPEN  (BSAMDCB,OUTIN),MF=L          BSAM, DASD, TAPE
         SPACE 1
PARMSECT DSECT ,             MAP CALL PARM
PARM1    DS    A             FIRST PARM
PARM2    DS    A              NEXT PARM
PARM3    DS    A              NEXT PARM
PARM4    DS    A              NEXT PARM
PARM5    DS    A              NEXT PARM
PARM6    DS    A              NEXT PARM
PARM7    DS    A              NEXT PARM
PARM8    DS    A              NEXT PARM
         CSECT ,
         SPACE 1
         ORG   CAMDUM+4           Don't need rest
         SPACE 2
***********************************************************************
*                                                                     *
*    OPEN DCB EXIT - if RECFM, LRECL, BLKSIZE preset, no change       *
*                     unless forced by device (e.g., unit record      *
*                     not blocked)                                    *
*                    for PDS directory read, F, 256, 256 are preset.  *
*    a) device is unit record - default U, device size, device size   *
*    b) all others - default to values passed to AOPEN                *
*                                                                     *
*    For FB, if LRECL > BLKSIZE, make LRECL=BLKSIZE                   *
*    For VB, if LRECL+3 > BLKSIZE, set spanned                        *
*                                                                     *
*                                                                     *
*    So, what this means is that if the DCBLRECL etc fields are set   *
*    already by MVS (due to existing file, JCL statement etc),        *
*    then these aren't changed. However, if they're not present,      *
*    then start using the "LRECL" etc previously set up by C caller.  *
*                                                                     *
***********************************************************************
         PUSH  USING
         DROP  ,
         USING OCDCBEX,R15
         USING IHADCB,R1     DECLARE OUR DCB WORK SPACE
OCDCBEX  LR    R11,R1        SAVE DCB ADDRESS AND OPEN FLAGS
         N     R1,=X'00FFFFFF'   NO 0C4 ON DCB ACCESS IF AM31
         TM    IOPFLAGS,IOFDCBEX  Been here before ?
         BZ    OCDCBX1
         OI    IOPFLAGS,IOFCONCT  Set unlike concatenation
         OI    DCBOFLGS,DCBOFPPC  Keep them coming
OCDCBX1  OI    IOPFLAGS,IOFDCBEX  Show exit entered
         SR    R2,R2         FOR POSSIBLE DIVIDE (FB)
         SR    R3,R3
         ICM   R3,3,DCBBLKSI   GET CURRENT BLOCK SIZE
         SR    R4,R4         FOR POSSIBLE LRECL=X
         ICM   R4,3,DCBLRECL GET CURRENT RECORD LENGTH
         NI    FILEMODE,3    MASK FILE MODE
         MVC   ZRECFM,FILEMODE   GET OPTION BITS
         TR    ZRECFM,=X'90,50,C0,C0'  0-FB  1-VB  2-U
         TM    DCBRECFM,DCBRECLA  ANY RECORD FORMAT SPECIFIED?
         BNZ   OCDCBFH       YES
         CLI   DEVINFO+2,UCB3UREC  UNIT RECORD?
         BNE   OCDCBFM       NO; USE OVERRIDE
OCDCBFU  CLI   FILEMODE,0         DID USER REQUEST FB?
         BE    OCDCBFM            YES; USE IT
         OI    DCBRECFM,DCBRECU   SET U FOR READER/PUNCH/PRINTER
         B     OCDCBFH
OCDCBFM  MVC   DCBRECFM,ZRECFM
OCDCBFH  LTR   R4,R4
         BNZ   OCDCBLH       HAVE A RECORD LENGTH
         L     R4,DEVINFO+4       SET DEVICE SIZE FOR UNIT RECORD
         CLI   DEVINFO+2,UCB3UREC   UNIT RECORD?
         BE    OCDCBLH       YES; USE IT
*   REQUIRES CALLER TO SET LRECL=BLKSIZE FOR RECFM=U DEFAULT
         ICM   R4,15,LRECL   SET LRECL=PREFERRED BLOCK SIZE
         BNZ   *+8
         L     R4,DEVINFO+4  ELSE USE DEVICE MAX
         IC    R5,DCBRECFM   GET RECFM
         N     R5,=X'000000C0'  RETAIN ONLY D,F,U,V
         SRL   R5,6          CHANGE TO 0-D 1-V 2-F 3-U
         MH    R5,=H'3'      PREPARE INDEX
         SR    R6,R6
         IC    R6,FILEMODE   GET USER'S VALUE
         AR    R5,R6         DCB VS. DFLT ARRAY
*     DCB RECFM:       --D--- --V--- --F--- --U---
*     FILE MODE:       F V  U F V  U F  V U F  V U
         LA    R6,=AL1(4,0,-4,4,0,-4,0,-4,0,0,-4,0)  LRECL ADJUST
         AR    R6,R5         POINT TO ENTRY
         ICM   R5,8,0(R6)    LOAD IT
         SRA   R5,24         SHIFT WITH SIGN EXTENSION
         AR    R4,R5         NEW LRECL
         SPACE 1
*   NOW CHECK BLOCK SIZE
OCDCBLH  LTR   R3,R3         ANY ?
         BNZ   *+8           YES
         ICM   R3,15,BLKSIZE SET OUR PREFERRED SIZE
         BNZ   *+8           OK
         L     R3,DEVINFO+4  SET NON-ZERO
         C     R3,DEVINFO+4  LEGAL ?
         BNH   *+8
         L     R3,DEVINFO+4  NO; SHORTEN
         TM    DCBRECFM,DCBRECU   U?
         BO    OCDCBBU       YES
         TM    DCBRECFM,DCBRECF   FIXED ?
         BZ    OCDCBBV       NO; CHECK VAR
         DR    R2,R4
         CH    R3,=H'1'      DID IT FIT ?
         BE    OCDCBBF       BARELY
         BH    OCDCBBB       ELSE LEAVE BLOCKED
         LA    R3,1          SET ONE RECORD MINIMUM
OCDCBBF  NI    DCBRECFM,255-DCBRECBR   BLOCKING NOT NEEDED
OCDCBBB  MR    R2,R4         BLOCK SIZE NOW MULTIPLE OF LRECL
         B     OCDCBXX       AND GET OUT
*   VARIABLE
OCDCBBV  LA    R5,4(,R4)     LRECL+4
         CR    R5,R3         WILL IT FIT ?
         BNH   *+8           YES
         OI    DCBRECFM,DCBRECSB  SET SPANNED
         B     OCDCBXX       AND EXIT
*   UNDEFINED
OCDCBBU  LR    R4,R3         FOR NEATNESS, SET LRECL = BLOCK SIZE
*   EXEUNT  (Save DCB options for EXCP compatibility in main code)
OCDCBXX  STH   R3,DCBBLKSI   UPDATE POSSIBLY CHANGED BLOCK SIZE
         STH   R4,DCBLRECL     AND RECORD LENGTH
         ST    R3,BLKSIZE    UPDATE POSSIBLY CHANGED BLOCK SIZE
         ST    R4,LRECL        AND RECORD LENGTH
         MVC   ZRECFM,DCBRECFM    DITTO
         AIF   ('&SYS' EQ 'S370').NOOPSW
         BSM   R0,R14
         AGO   .OPNRET
.NOOPSW  ANOP  ,
         BR    R14           RETURN TO OPEN
.OPNRET  ANOP  ,
         POP   USING
         SPACE 2
*
         AIF   ('&SYS' EQ 'S370').NODOP24
***********************************************************************
*                                                                     *
*    OPEN DCB EXIT - 24 bit stub                                      *
*    This code is not directly executed. It is copied below the line  *
*    It is only needed for AMODE 31 programs (both S380 and S390      *
*    execute in this mode).                                           *
*                                                                     *
***********************************************************************
         PUSH  USING
         DROP  ,
         USING DOPEX24,R15
*
* This next line works because when we are actually executing,
* we are executing inside that DSECT, so the address we want
* follows the code. Also, it has already had the high bit set,
* so it will switch to 31-bit mode.
*
DOPEX24  L     R15,DOPE31-DOPE24(,R15)  Load 31-bit routine address
*
* The following works because while the AMODE is saved in R14, the
* rest of R14 isn't disturbed, so it is all set for a BSM to R14
*
         BSM   R14,R15                  Switch to 31-bit mode
DOPELEN  EQU   *-DOPEX24
         POP   USING
.NODOP24 ANOP  ,
*
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
