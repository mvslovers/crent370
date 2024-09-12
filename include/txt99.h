#ifndef TXT99_H
#define TXT99_H

typedef struct txt99    TXT99;

struct txt99 {
   unsigned short dal;  /* DAIR Type Code                                   */
#define DALDDNAM 0x0001 /*    DDNAME                                        */
#define DALDSNAM 0x0002 /*    DSNAME                                        */
#define DALMEMBR 0x0003 /*    MEMBER NAME                                   */
#define DALSTATS 0x0004 /*    DATA SET STATUS                               */
#define DALNDISP 0x0005 /*    DATA SET NORMAL DISPOSITION                   */
#define DALCDISP 0x0006 /*    DATA SET CONDITIONAL DISP                     */
#define DALTRK   0x0007 /*    TRACK SPACE TYPE                              */
#define DALCYL   0x0008 /*    CYLINDER SPACE TYPE                           */
#define DALBLKLN 0x0009 /*    AVERAGE DATA BLOCK LENGTH                     */
#define DALPRIME 0x000A /*    PRIMARY SPACE QUANTITY                        */
#define DALSECND 0x000B /*    SECONDARY SPACE QUANTITY                      */
#define DALDIR   0x000C /*    DIRECTORY SPACE QUANTITY                      */
#define DALRLSE  0x000D /*    UNUSED SPACE RELEASE                          */
#define DALSPFRM 0x000E /*    CONTIG,MXIG,ALX SPACE FORMAT                  */
#define DALROUND 0x000F /*    WHOLE CYLINDER (ROUND) SPACE                  */
#define DALVLSER 0x0010 /*    VOLUME SERIAL                                 */
#define DALPRIVT 0x0011 /*    PRIVATE VOLUME                                */
#define DALVLSEQ 0x0012 /*    VOL SENCE NUMBER                              */
#define DALVLCNT 0x0013 /*    VOLUME COUNT                                  */
#define DALVLRDS 0x0014 /*    VOLUME REFERENCE TO DSNAME                    */
#define DALUNIT  0x0015 /*    UNIT DESCRIPTION                              */
#define DALUNCNT 0x0016 /*    UNIT COUNT                                    */
#define DALPARAL 0x0017 /*    PARALLEL MOUNT                                */
#define DALSYSOU 0x0018 /*    SYSOUT                                        */
#define DALSPGNM 0x0019 /*    SYSOUT PROGRAM NAME                           */
#define DALSFMNO 0x001A /*    SYSOUT FORM NUMBER                            */
#define DALOUTLM 0x001B /*    OUTPUT LIMIT                                  */
#define DALCLOSE 0x001C /*    UNALLOCATE AT CLOSE                           */
#define DALCOPYS 0x001D /*    SYSOUT COPIES                                 */
#define DALLABEL 0x001E /*    LABEL TYPE                                    */
#define DALDSSEQ 0x001F /*    DATA SET SENCE NUMBER                         */
#define DALPASPR 0x0020 /*    PASSWORD PROTECTION                           */
#define DALINOUT 0x0021 /*    INPUT ONLY OR OUTPUT ONLY                     */
#define DALEXPDT 0x0022 /*    2 DIGIT YEAR EXPIRATION DATE                  */
#define DALRETPD 0x0023 /*    RETENTION PERIOD                              */
#define DALDUMMY 0x0024 /*    DUMMY ALLOCATION                              */
#define DALFCBIM 0x0025 /*    FCB IMAGE-ID                                  */
#define DALFCBAV 0x0026 /*    FCB FORM ALIGNMENT,IMAGE VERIFY               */
#define DALQNAME 0x0027 /*    QNAME ALLOCATION                              */
#define DALTERM  0x0028 /*    TERMINAL ALLOCATION                           */
#define DALUCS   0x0029 /*    UNIVERSAL CHARACTER SET                       */
#define DALUFOLD 0x002A /*    UCS FOLD MODE                                 */
#define DALUVRFY 0x002B /*    UCS VERIFY CHARACTER SET                      */
#define DALDCBDS 0x002C /*    DCB DSNAME REFERENCE                          */
#define DALDCBDD 0x002D /*    DCB DDNAME REFERENCE                          */
#define DALBFALN 0x002E /*    BUFFER ALIGNMENT                              */
#define DALBFTEK 0x002F /*    BUFFERING TECHNIQUE                           */
#define DALBLKSZ 0x0030 /*    BLOCKSIZE                                     */
#define DALBUFIN 0x0031 /*    NUMBER OF INPUT BUFFERS                       */
#define DALBUFL  0x0032 /*    BUFFER LENGTH                                 */
#define DALBUFMX 0x0033 /*    MAXIMUM NUMBER OF BUFFERS                     */
#define DALBUFNO 0x0034 /*    NUMBER OF DCB BUFFERS                         */
#define DALBUFOF 0x0035 /*    BUFFER OFFSET                                 */
#define DALBUFOU 0x0036 /*    NUMBER OF OUTPUT BUFFERS                      */
#define DALBUFRQ 0x0037 /*    NUMBER OF GET MACRO BUFFERS                   */
#define DALBUFSZ 0x0038 /*    LINE BUFFER SIZE                              */
#define DALCODE  0x0039 /*    PAPER TAPE CODE                               */
#define DALCPRI  0x003A /*    SEND/RECEIVE PRIORITY                         */
#define DALDEN   0x003B /*    TAPE DENSITY                                  */
#define DALDSORG 0x003C /*    DATA SET ORGANIZATION                         */
#define DALEROPT 0x003D /*    ERROR OPTIONS                                 */
#define DALGNCP  0x003E /*    NO. OF GAM I/O BEFORE WAIT                    */
#define DALINTVL 0x003F /*    POLLING INTERVAL                              */
#define DALKYLEN 0x0040 /*    DATA SET KEYS LENGTH                          */
#define DALLIMCT 0x0041 /*    SEARCH LIMIT                                  */
#define DALLRECL 0x0042 /*    LOGICAL RECORD  LENGTH                        */
#define DALMODE  0x0043 /*    CARD READER/PUNCH MODE                        */
#define DALNCP   0x0044 /*    NO. READ/WRITE BEFORE CHECK                   */
#define DALOPTCD 0x0045 /*    OPTIONAL SERVICES                             */
#define DALPCIR  0x0046 /*    RECEIVING PCI                                 */
#define DALPCIS  0x0047 /*    SENDING PCI                                   */
#define DALPRTSP 0x0048 /*    PRINTER LINE SPACING                          */
#define DALRECFM 0x0049 /*    RECORD FORMAT                                 */
#define DALRSRVF 0x004A /*    FIRST BUFFER RESERVE                          */
#define DALRSRVS 0x004B /*    SECONDARY BUFFER RESERVE                      */
#define DALSOWA  0x004C /*    TCAM USER WORK AREA SIZE                      */
#define DALSTACK 0x004D /*    STACKER BIN                                   */
#define DALTHRSH 0x004E /*    MESSAGE QUEUE PERCENTAGE                      */
#define DALTRTCH 0x004F /*    TAPE RECORDING TECHNOLOGY @T1C                */
#define DALPASSW 0x0050 /*    PASSWORD                                      */
#define DALIPLTX 0x0051 /*    IPL TEXT ID                                   */
#define DALPERMA 0x0052 /*    PERMANENTLY ALLOCATED ATTRIB                  */
#define DALCNVRT 0x0053 /*    CONVERTIBLE ATTRIBUTE                         */
#define DALDIAGN 0x0054 /*    OPEN/CLOSE/EOV DIAGNOSTIC TRACE               */
#define DALRTDDN 0x0055 /*    RETURN DDNAME                                 */
#define DALRTDSN 0x0056 /*    RETURN DSNAME                                 */
#define DALRTORG 0x0057 /*    RETURN D.S. ORGANIZATION                      */
#define DALSUSER 0x0058 /*    SYSOUT REMOTE USER                            */
#define DALSHOLD 0x0059 /*    SYSOUT HOLD QUEUE                             */
#define DALFUNC  0x005A /*    D.S. TYPE FOR 3525 CARD DEVICE                */
#define DALFRID  0x005B /*    IMAGELIB MEMBER FOR SHARK                     */
#define DALSSREQ 0x005C /*    SUBSYSTEM REST                                */
#define DALRTVOL 0x005D /*    RETURN VOLUME SERIAL                          */
#define DALMSVGP 0x005E /*    MSVGP FOR 3330V                               */
#define DALSSNM  0x005F /*    SUBSYSTEM NAME REST                           */
#define DALSSPRM 0x0060 /*    SUBSYSTEM PARAMETERS                          */
#define DALPROT  0x0061 /*    RACF PROTECT FEATURE                          */
#define DALSSATT 0x0062 /*    SUBSYSTEM ATTRIBUTE                           */
#define DALUSRID 0x0063 /*    SYSOUT USER ID                                */
#define DALBURST 0x0064 /*    BURSTER-TRIMMER-STACKER                       */
#define DALCHARS 0x0065 /*    CHAR ARRANGEMENT TABLE                        */
#define DALCOPYG 0x0066 /*    COPY GROUP VALUES                             */
#define DALFFORM 0x0067 /*    FLASH FORMS OVERLAY                           */
#define DALFCNT  0x0068 /*    FLASH FORMS OVERLAY COUNT                     */
#define DALMMOD  0x0069 /*    COPY MODIFICATION MODULE                      */
#define DALMTRC  0x006A /*    TABLE REFERENCE CHARACTER                     */
#define DALLRECK 0x006B /*    LRECL IN MULT OF 1K FORMAT                    */
#define DALDEFER 0x006C /*    DEFER MOUNT UNTIL OPEN                        */
#define DALEXPDL 0x006D /*    4 DIGIT YEAR EXP. DATE                        */
#define DALBRTKN 0x006E /*    Browse token supplied                         */
#define DALINCHG 0x006F /*    Volume Interchange                            */
/*                                     Attributes                           */
#define DALOVAFF 0x0070 /*    Tell JES to override                          */
/*                            system affinity for INTRDR                    */
#define DALACODE 0x8001 /*    ACCESSIBILITY CODE                            */
#define DALOUTPT 0x8002 /*    OUTPUT REFERENCE                              */
/*  JDT defined Allocation keys                                             */
/*        SJF DD ALLOCATION KEYS                                            */
#define DALCNTL  0x8003 /*    CNTL                                          */
#define DALSTCL  0x8004 /*    STORCLAS                                      */
#define DALMGCL  0x8005 /*    MGMTCLAS                                      */
#define DALDACL  0x8006 /*    DATACLAS                                      */
#define DALRECO  0x800B /*    RECORG                                        */
#define DALKEYO  0x800C /*    KEYOFF                                        */
#define DALREFD  0x800D /*    REFDD                                         */
#define DALSECM  0x800E /*    SECMODEL                                      */
#define DALLIKE  0x800F /*    LIKE                                          */
#define DALAVGR  0x8010 /*    AVGREC                                        */
#define DALDSNT  0x8012 /*    DSNTYPE                                       */
#define DALSPIN  0x8013 /*    SPIN                                          */
#define DALSEGM  0x8014 /*    SEGMENT                                       */
/*                                                                          */
#define DALPATH  0x8017 /*    PATH                                          */
#define DALPOPT  0x8018 /*    PATHOPTS                                      */
#define DALPMDE  0x8019 /*    PATHMODE                                      */
#define DALPNDS  0x801A /*    PATHDISP - Normal Disposition                 */
#define DALPCDS  0x801B /*    PATHDISP - Conditional Disposition            */
#define DALRLS   0x801C /*    RLS - Record Level Sharing                    */
#define DALFDAT  0x801D /*    FILEDATA - file organization                  */
#define DALLGST  0x801F /*    LGSTREAM                                      */
#define DALDCCS  0x8020 /*    CCSID                                         */
/*                                                                          */
#define DALBSLM  0x0822 /*    BLKSZLIM                                      */
/*******************************************************************
/**
/** KEYS FOR CONCATENATION FUNCTION
/**
/******************************************************************/
#define DCCDDNAM 0x0001 /*    DDNAMES                                       */
#define DCCPERMC 0x0004 /*    PERMANENTLY CONCATENATED                      */
/*******************************************************************
/**
/** KEYS FOR DECONCATENATION FUNCTION
/**
/******************************************************************/
#define DDCDDNAM 0x0001 /*    DDNAME                                        */
/*******************************************************************
/**
/** KEYS FOR INFORMATION RETRIEVAL FUNCTION
/**
/******************************************************************/
#define DINDDNAM 0x0001 /*    DDNAME                                        */
#define DINDSNAM 0x0002 /*    DSNAME                                        */
#define DINRTDDN 0x0004 /*    RETURN DDNAME                                 */
#define DINRTDSN 0x0005 /*    RETURN DSNAME                                 */
#define DINRTMEM 0x0006 /*    RETURN MEMBER NAME                            */
#define DINRTSTA 0x0007 /*    RETURN DATA SET STATUS                        */
#define DINRTNDP 0x0008 /*    RETURN NORMAL DISPOSITION                     */
#define DINRTCDP 0x0009 /*    RETURN CONDITIONAL DISP                       */
#define DINRTORG 0x000A /*    RETURN D.S. ORGANIZATION                      */
#define DINRTLIM 0x000B /*    RETURN # TO NOT-IN-USE LIMIT                  */
#define DINRTATT 0x000C /*    RETURN DYN. ALLOC ATTRIBUTES                  */
#define DINRTLST 0x000D /*    RETURN LAST ENTRY INDICATION                  */
#define DINRTTYP 0x000E /*    RETURN S.D. TYPE INDICATION                   */
#define DINRELNO 0x000F /*    RELATIVE REST NUMBER                          */
#define DINRTVOL 0x0010 /*    Return First Volser        @L7A               */
/**  JDT defined Information Retrieval output keys                          */
/**  SJF DD INFORMATION RETRIEVAL KEYS                   @L3A               */
#define DINRCNTL 0xC003 /*    CNTL                       @D1A               */
#define DINRSTCL 0xC004 /*    STORCLAS                                      */
#define DINRMGCL 0xC005 /*    MGMTCLAS                                      */
#define DINRDACL 0xC006 /*    DATACLAS                                      */
#define DINRRECO 0xC00B /*    RECORG                                        */
#define DINRKEYO 0xC00C /*    KEYOFF                                        */
#define DINRREFD 0xC00D /*    REFDD                                         */
#define DINRSECM 0xC00E /*    SECMODEL                                      */
#define DINRLIKE 0xC00F /*    LIKE                                          */
#define DINRAVGR 0xC010 /*    AVGREC                                        */
#define DINRDSNT 0xC012 /*    DSNTYPE                                       */
#define DINRSPIN 0xC013 /*    SPIN                                          */
#define DINRSEGM 0xC014 /*    SEGMENT                                       */
#define DINRPATH 0xC017 /*    PATH                                          */
#define DINRPOPT 0xC018 /*    PATHOPTS                                      */
#define DINRPMDE 0xC019 /*    PATHMODE                                      */
#define DINRPNDS 0xC01A /*    NORMAL PATHDISP                               */
#define DINRCNDS 0xC01B /*    CONDITIONAL PATHDISP                          */
#define DINRFDAT 0xC01D /*    FILEDATA                                      */
/**  JDT defined Information Retrieval input keys                           */
/**        SJF DD INFORMATION RETRIEVAL INPUT KEYS                          */
#define DINPATH  0x8017 /*    PATH                                          */
/*************************************************************
/**
/** KEYS FOR REMOVE IN-USE FUNCTION
/**
/*************************************************************/
#define DRITCBAD 0x0001 /*    TCB ADDRESS                                   */
#define DRICURNT 0x0002 /*    CURRENT TASK OPTION                           */
/*************************************************************
/**
/** KEYS FOR DDNAME ALLOCATION FUNCTION
/**
/*************************************************************/
#define DDNDDNAM 0x0001 /*    DDNAME                                        */
#define DDNRTDUM 0x0002 /*    RETURN DUMMY D.S. INDIC                       */
/*************************************************************
/**
/** KEYS FOR UNALLOCATION FUNCTION
/**
/*************************************************************/
#define DUNDDNAM 0x0001 /*    DDNAME                                        */
#define DUNDSNAM 0x0002 /*    DSNAME                                        */
#define DUNMEMBR 0x0003 /*    MEMBER NAME                                   */
#define DUNOVDSP 0x0005 /*    OVERRIDING DISPOSITION                        */
#define DUNUNALC 0x0007 /*    UNALLOC OPTION                                */
#define DUNREMOV 0x0008 /*    REMOVE OPTION                                 */
#define DUNOVSNH 0x000A /*    OVERRIDING SYSOUT NOHOLD                      */
#define DUNOVCLS 0x0018 /*    OVERRIDING SYSOUT CLASS                       */
#define DUNOVSUS 0x0058 /*    OVERRIDING SYSOUT NODE     @                  */
#define DUNOVSHQ 0x0059 /*    OVERRIDING SYSOUT HOLD QUEUE                  */
#define DUNOVUID 0x0063 /*    Overriding SYSOUT User ID  @                  */
/**  JDT defined Unallocation keys                                          */
/**        SJF DD UNALLOCATION KEYS                                         */
#define DUNSPIN  0x8013 /*    SPIN                                          */
/**                                                                         */
#define DUNPATH  0x8017 /*    PATH                                          */
/**                                                                         */
#define DUNOVPDS 0x801A /*    PATHDISP - Override Disposition               */

   unsigned short count;      /* Number of text segments                    */
   unsigned short size;       /* Size of each text segment                  */
   unsigned char  text[1];    /* Text segment                               */
};

#endif
