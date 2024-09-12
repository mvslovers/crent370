SSIREQ01 TITLE '- DOCUMENTATION'
SSIREQ01 AMODE 31
SSIREQ01 RMODE 24
         SPLEVEL SET=4
*********************************************************************
* FUNCTION:  THIS PROGRAM PERFORMS THE FOLLOWING FUNCTIONS:         *
*                                                                   *
*        1. REQUESTS A SYSOUT DATA SET FROM JES THROUGH A WRITER    *
*           NAME (SHOWS AN EXAMPLE OF USING ONE OF THE AVAILABLE    *
*           SELECTION CRITERIA TO INFLUENCE WHICH SYSOUT DATA SET   *
*           IS SELECTED).  THIS PROGRAM IS INTENDED TO RUN ON JES3  *
*           ONLY, AS IT SHOWS SELECTION CRITERIA AVAILABLE ONLY TO  *
*           JES3.  (SPECIFICALLY, BIT SSSOHLD IS USED.)             *
*        2. IF ONE IS NOT AVAILABLE, THE OPERATOR CAN WAIT UNTIL    *
*           ONE IS AVAILABLE, OR EXIT THE PROGRAM.                  *
*        3. IF ONE IS AVAILABLE, IT IS DYNAMICALLY ALLOCATED.       *
*        4. EACH RECORD IS READ AND DISPLAYED TO THE OPERATOR.      *
*        5. UPON END-OF-DATA, THE SYSOUT DATA SET IS DEALLOCATED.   *
*           THE SYSOUT CLASS IS CHANGED TO 'A', AND THE             *
*           DESTINATION IS CHANGED TO 'PRT803'.                     *
*           (SHOWS AN EXAMPLE OF USING THE AVAILABLE DYNAMIC        *
*           ALLOCATION TEXT UNIT TO CHANGE THE ATTRIBUTES OF THE    *
*           RECEIVE SYSOUT DATA SET DURING UNALLOCATION.)           *
*        6. THE PROGRAM THEN CYCLES BACK AND ASKS JES FOR THE NEXT  *
*           DATA SET (GOES TO STEP 1).                              *
*                                                                   *
* NAME OF MODULE:  SSIREQ01                                         *
*                                                                   *
* REGISTER USE:                                                   *
*                                                                   *
*              0                   PARM REGISTER                    *
*              1                   PARM REGISTER                    *
*              2                   SSOB                             *
*              3                   SSSO                             *
*              4                   DCB                              *
*              5                   RB                               *
*              6                   MAX RECORD LENGTH                *
*              7                   DUMP CODE                        *
*              8                   ABEND VALUE REGISTER             *
*              9                   IEFSSREQ RETURN CODES            *
*              10                  BASE REGISTER                    *
*              11                  TEXT RECORD STRUCTURE PTR        *
*              12                  UNUSED                           *
*              13                  SAVE AREA CHAIN REGISTER         *
*              14                  PARM REGISTER / RETURN ADDR      *
*              15                  PARM REGISTER / COND CODE        *
*                                                                   *
* ATTRIBUTES:  SUPERVISOR STATE, AMODE(31), RMODE(24)               *
*                                                                   *
*                                                                   *
* NOTE:  THIS IS A SAMPLE.                                          *
*********************************************************************
         TITLE '- EQUATES'
*********************************************************************
*        GENERAL EQUATES                                            *
*********************************************************************
EQUHOBON EQU   X'80000000'         HIGH ORDER BIT ON
FF       EQU   X'FF'               ALL BITS ON IN A BYTE
*********************************************************************
*        AFTER COMPARE INSTRUCTIONS                                 *
*********************************************************************
GT       EQU   2                   A HIGH
LT       EQU   4                   A LOW
NE       EQU   7                   A NOT EQUAL B
EQ       EQU   8                   A EQUAL B
GE       EQU   11                  A NOT LOW
LE       EQU   13                  A NOT HIGH
*
*********************************************************************
*        AFTER ARITHMETIC INSTRUCTIONS                              *
*********************************************************************
OV       EQU   1                   OVERFLOW
PLUS     EQU   2                   PLUS
MINUS    EQU   4                   MINUS
NZERO    EQU   7                   NOT ZERO
ZERO     EQU   8                   ZERO
ZEROS    EQU   8                   ZERO
NMINUS   EQU   11                  NOT MINUS
NOV      EQU   12                  NOT OVERFLOW
NPLUS    EQU   13                  NOT PLUS
*
*********************************************************************
*        AFTER TEST UNDER MASK INSTRUCTIONS                         *
*********************************************************************
ALLON    EQU   1                   ALL ON
MIXED    EQU   4                   MIXED
NALLOFF  EQU   5                   ALLON+MIXED
ALLOFF   EQU   8                   ALL OFF
NALLON   EQU   12                  ALLOFF+MIXED
*********************************************************************
*        ABEND CODE INDICATIONS                                     *
*********************************************************************
BADR15   EQU   1                   IEFSSREQ R15 NON-ZERO
BADRETN  EQU   2                   SSOBRETN NON-ZERO AND NOT 8
BADS99A  EQU   3                   DYNALLOC ALLOC FAILED
BADOPEN  EQU   4                   OPEN DCB FAILED
BADS99U  EQU   5                   DYNALLOC UNALLC FAILED
BADRLEN  EQU   6                   PSO DATASET TOO LARGE (RECLEN)
*********************************************************************
*        GENERAL PURPOSE REGISTERS                                  *
*********************************************************************
R0       EQU   0                   PARM REGISTER
R1       EQU   1                   PARM REGISTER
R2       EQU   2                   SSOB
R3       EQU   3                   SSSO
R4       EQU   4                   DCB
R5       EQU   5                   RB
R6       EQU   6                   MAX RECORD LENGTH
R7       EQU   7                   DUMP CODE
R8       EQU   8                   ABEND VALUE REGISTER
R9       EQU   9                   RETURN CODES OR REASONS
R10      EQU   10                  BASE REGISTER
R11      EQU   11                  TEXT RECORD STRUCTURE PTR
R12      EQU   12                  UNUSED
R13      EQU   13                  SAVE AREA CHAIN REGISTER
R14      EQU   14                  PARM REGISTER / RETURN ADDR
R15      EQU   15                  PARM REGISTER / COND CODE
         TITLE '- CVT - COMMUNICATIONS VECTOR TABLE'
         CVT DSECT=YES,LIST=NO
         TITLE 'DCBD'
         DCBD  DSORG=PS
         TITLE '- IEFJESCT - JES CONTROL TABLE'
         IEFJESCT TYPE=DSECT
         TITLE '- SSOB'
         IEFSSOBH
SSOBGN   EQU   *                   START OF FUNCTIONAL EXTENSION
         TITLE '- SSSO'
         IEFSSSO SOEXT=YES
         TITLE '- IEFZB4D0 - SVC99 DSECTS'
         IEFZB4D0
         TITLE '- IEFZB4D2 - TU KEYS'
         IEFZB4D2
*********************************************************************
*  HOUSEKEEPING                                                     *
*********************************************************************
SSIREQ01 CSECT
         SAVE  (14,12)             FORM ID
         BALR  R10,0               ESTABLISH BASE REG
         USING *,R10               INFORM ASSEMBLER
         LA    R2,SA               CHAIN SAVEAREAS
         ST    R13,4(R2)           OLD IN NEW
         ST    R2,8(R13)           NEW IN OLD
         LR    R13,R2              RECHAIN THE SAVE AREAS
         TITLE '- PROCESS SYSOUT'
         WTO   'SSI CODE 01 Version 1'  LET OP KNOW WHAT LEVEL
         STORAGE OBTAIN,           GET STORAGE FOR SSOB/SSSO
               LENGTH=SSOBLEN1,
               COND=NO
         LR    R2,R1               SAVE BEGINNING OF STORAGE
         USING SSOBEGIN,R2         INFORM ASSEMBLER
         LA    R3,SSOBGN           PT TO BEGINNING OF SSSO
         USING SSSOBGN,R3          INFORM ASSEMBLER
         TITLE '- SSOB PROCESSING'
*********************************************************************
* NOW WORK ON THE SSOB.  THE LIFE-OF-JOB IS USED HERE, SO THE       *
* SSOBSSIB IS ZERO.                                                 *
*********************************************************************
         XC    SSOB(SSOBHSIZ),SSOB CLEAR THE SSOB
         MVC   SSOBID,=CL4'SSOB'   SSOB INITIALS INTO SSOB
         MVC   SSOBFUNC,=AL2(SSOBSOUT) MOVE FUNCTION ID INTO SSOB
         MVC   SSOBLEN,=AL2(SSOBHSIZ) MOVE SIZE INTO SSOB
         ST    R3,SSOBINDV         SAVE THE SSSO ADDRESS
         TITLE '- SSSO PROCESSING'
*********************************************************************
* NOW WORK ON THE SSSO.  SELECT A SELECTION CRITERIA BASED ON       *
* AN EXTERNAL WRITER NAME OF 'ANDREW'.                              *
*********************************************************************
         XC    SSSOBGN(SSSOSIZE),SSSOBGN  CLEAR THE SSSO
         MVC   SSSOLEN,=AL2(SSSOSIZE)     SET THE SIZE OF THE SSSO
         MVI   SSSOVER,SSSOCVER    SET THE VERSION NUMBER
         OI    SSSOFLG1,SSSOSPGM+SSSOHLD   SELECT BY WRITER NAME AND
*                                  THE HOLD QUEUE
         OI    SSSOFLGA,SSSOWTRN   IND. THAT SELECTION IS BY
*                                  WRITER NAME, NOT USERID
         MVC   SSSOPGMN,=CL8'ANDREW'  IND. CORRECT WRITER NAME
*                                     THAT IS USED AS SELECTION
         OI    SSSOFLG2,SSSOPSEE   IND. LONG FORM OF IEFSSSO
*********************************************************************
* NOW GO TAP JES ON THE SHOULDER FOR A DATASET!                     *
*********************************************************************
NEXTDS   DS    0H                  GET NEXT DSNAME FROM JES
         MODESET MODE=SUP          GET INTO SUPERVISOR STATE
         LR    R1,R2               R1=ADDRESS OF SSOB
         O     R1,=A(EQUHOBON)     TURN ON THE HIGH-ORDER BIT
         ST    R1,MYSSOBPT         SAVE POINTER FOR SSREQ
         LA    R1,MYSSOBPT         POINT TO SSOB POINTER
         IEFSSREQ ,                GO TO JES FOR A DATASET
         MODESET MODE=PROB         BACK TO PROBLEM STATE
         LA    R8,BADR15           ASSUME BAD REG 15 RETURN
         LTR   R9,R15              DID THE IEFSSREQ WORK OK?
         BC    NZERO,ABEND         NOT GOOD...TAKE AN ABEND
         LA    R8,BADRETN          ASSUME BAD SSOBRETN
         ICM   R9,B'1111',SSOBRETN CHECK OUT SSOBRETN
         BC    NZERO,TESTIT        NON-ZERO, INVESTIGATE FURTHER
*********************************************************************
* WE HAVE A DATA SET.  NOW DYNAMICALLY ALLOCATE IT, READ AND DISPLAY*
* THE RECORDS USING SEQUENTIAL ACCESS METHOD AS EXAMPLE OF HOW TO   *
* RETRIEVE THE DATA.                                                *
*********************************************************************
         TITLE '- ALLOCATE RETURNED DATASET'
*********************************************************************
* ALLOCATE THE RETURNED SYSOUT DATASET                              *
*********************************************************************
         LA    R8,BADRLEN          ASSUME SIZE TOO LARGE FOR WTO
         SR    R6,R6               CLEAR REG 6
         ICM   R6,B'0011',SSSOMLRL GET MAX RECORD LENGTH
         CH    R6,=H'150'          IS MAX RCD LENGTH>150??
         BC    GT,ABEND            YES - TIME FOR US TO GO HOME
         STH   R6,RECLEN           SAVE MAX RECORD LENGTH
         LA    R5,MY99RB           PT TO RB
         USING S99RB,R5            ADDRESSABILITY TO THE RB
         XC    S99RB(RBLEN),S99RB  ZERO THE RB
         MVI   S99RBLN,RBLEN       RB LENGTH
         MVI   S99VERB,S99VRBAL    RB VERB CODE=ALLOC
         LA    R1,MY99TPTA         ADDR SVC 99 ALLOC TU PTRS
         ST    R1,S99TXTPP         STORED IN RB
         LA    R1,MY99RBPT         PT TO RB POINTER
         MVC   TXTDSNAM,SSSODSN    MOVE DATASET NAME TO BE ALLOCATED
         DYNALLOC                  ISSUE DYNAMIC ALLOCATION
         LA    R8,BADS99A          ASSUME IT DIDN'T WORK
         LR    R9,R1               COPY FOR DUMP
         LTR   R15,R15             SVC 99 WORK OKAY??
         BC    NZERO,ABEND         NO, TAKE A DUMP
*********************************************************************
* SYSOUT DATASET ALLOCATED OKAY.   MOVE RETURNED DDNAME INTO        *
* THE DCB PRIOR TO OPENING IT.                                      *
*********************************************************************
         LA    R4,INDCB            PT TO THE INPUT DCB
         USING IHADCB,R4           ADDRESSABILITY
         MVC   DCBDDNAM(8),TXTDDA99 MOVE IN RETURNED DDNAME
         MVC   TXTDDU99,TXTDDA99   SAVE FOR UNALLOCATION
         MVC   DCBLRECL,SSSOMLRL   MOVE MAX LENGTH RECORD IN
*                                                                   *
         OPEN  INDCB               OPEN THE DCB
         LA    R8,BADOPEN          ASSUME THE OPEN FAILED
         LR    R9,R4               COPY FOR DUMP
         TM    DCBOFLGS,DCBOFOPN   DID IT WORK?
         BC    ALLOFF,ABEND        NOPE, TAKE A DUMP
         TITLE '- GET THE RECORDS - DISPLAY TO PROGRAM'
GETNEXT  DS    0H                  LOOP FOR READING/DISPLAYING
*********************************************************************
* SWITCH TO 24 BIT MODE FOR GET MACRO                               *
*********************************************************************
         LA    R15,SSITO24         SWITCH TO 24 BIT MODE ...
         BSM   0,R15               ... FOR RESTRICTED MACRO
SSITO24  DS    0H
         GET   INDCB               R1==> RECORD AFTER THE GET
         L     R15,SSITO31A        RETURN TO 31 BIT MODE ...
         BSM   0,R15               ... AND CONTINUE
SSITO31A DC    A(SSITO31+EQUHOBON) FOR MODE SWITCHING
*********************************************************************
* RETURN TO 31 BIT MODE AND CONTINUE                                *
*********************************************************************
SSITO31  DS    0H
         EX    R6,MOVEIT           MOVE UP TO 150 BYTES OF REC
         LA    R11,RECLEN          POINT TO RECORD FOR OUTPUT
         WTO   TEXT=(11),ROUTCDE=11 DISPLAY TO JOBLOG
         MVI   RECTEXT,C' '        CLEAR RECORD OUT...
         MVC   RECTEXT+1(L'RECTEXT-1),RECTEXT  ..FOR NEXT ONE
         B     GETNEXT             GO GET NEXT RECORD
         TITLE '- EODAD ROUTINE'
MYEODAD  DS    0H                  END-OF-DATASET
         CLOSE INDCB               CLOSE THE INPUT DCB
         DROP  R4                  IHADCB
*********************************************************************
* UNALLOCATE THE SYSOUT DATASET, CHANGING CLASS + DESTINATION       *
*********************************************************************
         XC    S99RB(RBLEN),S99RB  ZERO THE RB
         MVI   S99RBLN,RBLEN       RB LENGTH
         MVI   S99VERB,S99VRBUN    RB VERB CODE=UNALLOC
         LA    R1,MY99TPTU         ADDR SVC 99 ALLOC TU PTRS
         ST    R1,S99TXTPP         STORED IN RB
         LA    R1,MY99RBPT         PT TO RB POINTER
         DYNALLOC                  ISSUE DYNAMIC UNALLOCATION
         LA    R8,BADS99U          ASSUME IT DIDN'T WORK
         LR    R9,R1               COPY FOR DUMP
         LTR   R15,R15             SVC 99 WORK OKAY??
         BC    NZERO,ABEND         NO, TAKE A DUMP
         B     NEXTDS              GO GET NEXT DATA SET
         TITLE '- BAD RETURN FROM IEFSSREQ'
TESTIT   DS    0H
*********************************************************************
*  R8 HAS THE 'BADRETN' ASSUMPTION VALUE FOR POSSIBLE ABEND.        *
*  R9 HAS A NON-ZERO VALUE FROM SSOBRETN FROM THE IEFSSREQ.         *
*********************************************************************
         CH    R9,NOMORE           END OF DATA SET RETURN?
         BC    NE,ABEND            NOPE - QUIT!
*********************************************************************
*  WE RECEIVED THE END-OF-DATA CONDITION.  ASK WHETHER WE           *
*  SHOULD WAIT ON RETURNED ECB, OR COMPLETE NOW,                    *
*********************************************************************
         XC    MYECB,MYECB         CLEAR THE ECB
         WTOR  'ENTER 'W' OR WAIT, ANYTHING ELSE TO EXIT',
               MYREPLY,
               1,
               MYECB
         WAIT  ECB=MYECB
         OI    MYREPLY,C' '        FORCE REPLY TO UPPER CASE
         CLI   MYREPLY,C'W'        SHOULD WE WAIT?
         BC    NE,EXIT             NO, EXIT
*********************************************************************
* WAIT INDICATED.  SET UP WAIT ON THE RETURNED ECB.                 *
*********************************************************************
         MODESET KEY=ZERO          GET INTO KEY 0
         L     R1,SSSOWTRC         POINT TO RETURNED DATA AREA
         WAIT  ECB=(1)             R1==>RETURNED WAIT-FOR ECB
         MODESET KEY=NZERO         BACK TO ORIGINAL
         B     NEXTDS              WE'RE POSTED - GO GET IT!
         TITLE '- CLOSE OUT ROUTINES'
EXIT     DS    0H                  FINAL CALL, RETURN TO MVS
         MVI   SSSOFLG2,SSSOCTRL   IND. FINAL CALL TO JES
         MODESET MODE=SUP          GET INTO SUPERVISOR STATE
         LA    R1,MYSSOBPT         POINT TO SSOB POINTER
         IEFSSREQ ,                GO TO JES FOR GIVE BACK
         MODESET MODE=PROB         BACK TO PROBLEM STATE....
         STORAGE RELEASE,          FREE SSOB/SSSO
               LENGTH=SSOBLEN1,
               ADDR=(R2)           HERE'S WHERE IT LIVES
         L     R13,4(,R13)         OLD SA PTR
         RETURN (14,12),RC=0       BACK TO MVS
         TITLE '- ABEND ROUTINES'
*********************************************************************
* THIS IS THE ABEND ROUTINE.  R8 CONTAINS THE PROGRAM REASON CODE,  *
* R9 CONTAINS SPECIFIC ERROR/REASON CODE AS RETURNED BY THE         *
* SERVICE ROUTINE.                                                  *
*********************************************************************
ABEND    DS    0H                  ISSUE THE ABEND MACRO
         ABEND (8),DUMP,STEP       TAKE A DUMP IF WANTED
         TITLE '- DATA AREAS'
SA       DS    9D                  SAVE AREAS
MYECB    DS    F                   DOUBLEWORD FOR WTOR
*
MYREPLY  DS    CL1                 REPLY AREA FOR WTORS
RESRV    DS    XL3                 ROUND TO FULL WORD
         TITLE '- DYNALLOC DATA'
*********************************************************************
* THE FOLLOWING CONTROL BLOCKS ARE FOR DYNAMIC ALLOCATION AND       *
* UNALLOCATION.                                                     *
*********************************************************************
* S99 REQUEST BLOCK POINTER                                         *
*********************************************************************
MY99RBPT DC    A(EQUHOBON+MY99RB)  S99 RB PTR
*********************************************************************
* S99 REQUEST BLOCK                                                 *
*********************************************************************
MY99RB   DS    CL(RBLEN)           MY SVC 99 RB
RBLEN    EQU   (S99RBEND-S99RB)    LENGTH OF RB FOR MY99RB
*********************************************************************
* TEXT UNIT POINTERS FOR ALLOCATION                                 *
*********************************************************************
MY99TPTA DC    A(TXTDALDS)         TU FOR DATASET NAME
         DC    A(TXTSSREQ)         NAME OF SUBSYSTEM TU PTR
         DC    A(EQUHOBON+TXTRTDDN) RETURN DD NAME TU
*********************************************************************
* TEXT UNIT POINTERS FOR UNALLOCATION                               *
*********************************************************************
MY99TPTU DC    A(TXTDUNDD)         TU FOR UNALLOC BY DDNAME
         DC    A(TXTDUNNH)         NOHOLD TU
         DC    A(TXTDUNCL)         CHANGE THE CLASS TU
         DC    A(EQUHOBON+TXTDUNDS) CHANGE THE DEST TU
*********************************************************************
* TEXT UNITS FOR ALLOCATION                                         *
*********************************************************************
TXTDALDS DC    AL2(DALDSNAM)       DATASET NAME KEY
         DC    X'0001'             NUMBER
         DC    AL2(44)             DSNAME LENGTH
TXTDSNAM DS    CL44' '             DSNAME FROM IEFSSREQ
TXTCLOSE DC    AL2(DALCLOSE)       UNALLOCATE AT CLOSE KEY
         DC    X'0000'             # FIELD (0000 REQUIRED)
TXTSSREQ DC    AL2(DALSSREQ)       REQUEST OF SUBSYSTEM
         DC    X'0001'             # FIELD (0001 REQUIRED)
         DC    X'0004'             LEN OF SS NAME FOLLOWING
         DC    CL4'JES3'           NAME OF SUBSYSTEM
TXTRTDDN DC    AL2(DALRTDDN)       RETURN DDNAME FIELD
         DC    X'0001'             # FIELD (0001 REQUIRED)
         DC    X'0008'             LEN OF PARM
TXTDDA99 DC    CL8' '              RETURNED DDNAME PARM FIELD
*********************************************************************
* TEXT UNITS FOR UNALLOCATION                                       *
*********************************************************************
TXTDUNDD DC    AL2(DUNDDNAM)       TU FOR DDNAME UNALLOC
         DC    X'0001'             NUMBER
         DC    AL2(8)              DDNAME LENGTH
TXTDDU99 DS    CL8' '              DDNAME FROM DYNALLOC
TXTDUNNH DC    AL2(DUNOVSNH)       TU FOR NOHOLD
         DC    X'0000'             # FIELD (0000 REQUIRED)
TXTDUNCL DC    AL2(DUNOVCLS)       TU FOR CHANGE OF CLASS
         DC    X'0001'             # FIELD (0001 REQUIRED)
         DC    X'0001'             LEN OF SYSOUT CLASS
         DC    CL1'A'              CHANGED SYSOUT CLASS
TXTDUNDS DC    AL2(DUNOVSUS)       TU FOR CHANGE OF REMOTE
         DC    X'0001'             # FIELD (0001 REQUIRED)
         DC    X'0008'             LEN OF CHANGED REMOTE
         DC    CL8'PRT803'         CHANGED REMOTE NAME
MYSSOBPT DS    F                   POINTER TO SSOB FOR IEFSSREQ
NOMORE   DC    AL2(SSSOEODS)       NO MORE DATASETS FROM JES
MOVEIT   MVC   RECTEXT(*-*),0(R1)  OBJ OF AN EXECUTE
RECLEN   DS    H                   LENGTH OF OUTPUT RECORD
RECTEXT  DS    CL150               UP TO 150 BYTES OF SYSOUT
INDCB    DCB   DSORG=PS,MACRF=GL,BUFNO=2,EODAD=MYEODAD,                X
               DDNAME=WILLCHNG
         TITLE '- LITERALS'
         LTORG ,
         END
