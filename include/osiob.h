#ifndef IOB_H
#define IOB_H

typedef struct iob      IOB;
typedef struct iobprfx  IOBPRFX;

#pragma pack(1)
struct iobprfx {
    /* IOB Prefix area */
    char            iobcflg1;       /* 00 I/O INDICATORS                    */
#define IOBV6CHN    0x80            /* ... I/O CHAINED BIT SET BY IGG019V6  */
#define IOBRSV02    0x40            /* ... RESERVED                         */
#define IOBRSV03    0x20            /* ... RESERVED                         */
#define IOBRSV04    0x10            /* ... RESERVED                         */
#define IOBPTST     0x08            /* ... NOTE OR POINT OPERATION IS IN
                                           PROCESS                          */
#define IOBABAPP    0x04            /* ... ERROR HAS BEEN PROCESSED ONCE
                                           BY ABNORMAL-END APPENDAGE ROUTINE*/
#define IOBRSTCH    0x02            /* ... RESTART CHANNEL                  */
#define IOBPCI      0x01            /* ... SET WHEN A PROGRAM-CONTROLLED
                                           INTERRUPTION (PCI) OCCURS        */

    char            iobrsv05;       /* 01 RESERVED                          */
    char            iobcinop;       /* 02 OFFSET OF THE LAST I/O COMMAND
                                          FOR INPUT OPERATION (NOP CCW)
                                          FROM THE ORIGIN OF THE ICB        */
    char            iobconop;       /* 03 OFFSET OF THE LAST I/O COMMAND
                                          FOR AN OUTPUT OPERATION (NOP CCW)
                                          FROM THE ORIGIN OF THE ICB        */
    unsigned        iobcecb;        /* 04 EVENT CONTROL BLOCK USED BY BSAM
                                          OR QSAM. SHOWS THE STATUS OF THE
                                          I/O OPERATION.                    */
    void            *iobcicb;       /* 08 ADDRESS OF THE FIRST INTERRUPT
                                          CONTROL BLOCK (ICB) ON THE ICB
                                          QUEUE                             */
    void            *iobcnopa;      /* 0C ADDRESS OF THE NOP COMMAND AT THE
                                          END OF THE QUEUE                  */
};

struct iob {
    /* Start of IOB */
#define IOBSTDRD    iobflag1
    char            iobflag1;       /* 00 FLAG BYTE 1                       */
#define IOBDATCH        0x80        /* ... DATA CHAINING USED IN CHANNEL
                                           PROGRAM                          */
#define IOBCMDCH        0x40        /* ... COMMAND CHAINING USED IN CHANNEL
                                           PROGRAM                          */
#define IOBERRTN        0x20        /* ... ERROR ROUTINE IS IN CONTROL      */
#define IOBRPSTN        0x10        /* ... DEVICE IS TO BE REPOSITIONED     */
#define IOBCYCCK        0x08        /* ... CYCLIC REDUNDANCY CHECK (CRC)
                                           NEEDED (TAPE)                    */
#define IOBFCREX        0x08        /* ... FETCH COMMAND RETRY EXIT
                                           DIRECT ACCESS)                   */
#define IOBIOERR        0x04        /* ... EXCEPTIONAL CONDITION.  AFTER
                                           THE ERROR ROUTINE RETURNS AND
                                           THIS BIT IS ON, THE ERROR IS
                                           CONSIDERED PERMANENT.            */
#define IOBUNREL        0x02        /* ... IOB UNRELATED FLAG (I.E.,
                                           NONSEQUENTIAL)                   */
#define IOBRSTRT        0x01        /* ... IF 1, RESTART ADDRESS IN IOB TO
                                           BE USED.
                                           IF 0, START.  (OS/VS1)           */
#define IOBSPSVC        0x01        /* ... FOR SAM/PAM, SET BY SVC IF I/O
                                           APPENDAGE SHOULD NOT PROCESS
                                           INTERRUPT (OS/VS2)               */

    char            iobflag2;       /* 01 FLAG BYTE 2                       */
#define IOBHALT         0x80        /* ... HALT I/O HAS BEEN ISSUED BY SVC
                                           PURGE ROUTINE                    */
#define IOBSENSE        0x40        /* ... SENSE WILL NOT BE PERFORMED UNTIL
                                           THE DEVICE IS FREE               */
#define IOBPURGE        0x20        /* ... IOB HAS BEEN PURGED TO ALLOW I/O
                                           ACTIVITY TO QUIESCE.  (OS/VS1)   */
#define IOBRRT3         0x20        /* ... TYPE 3 RELATED REQUEST (OS/VS2)  */
#define IOBRDHA0        0x10        /* ... HOME ADDRESS (R0) RECORD IS TO
                                           BE READ.  SEEK COMMAND NOT NEEDED.
                                           (OS/VS1)                         */
#define IOBRRT2         0x10        /* ... TYPE 2 RELATED REQUEST (OS/VS2)  */
#define IOBALTTR        0x08        /* ... NO TEST FOR OUT-OF-EXTENT.
                                           AN ALTERNATE TRACK IS IN USE.    */
#define IOBSKUPD        0x04        /* ... SEEK ADDRESS IS BEING UPDATED.
                                           CYLINDER END OR FILE MASK
                                           VIOLATION HAS OCCURRED.          */
#define IOBSTATO        0x02        /* ... DEVICE END STATUS HAS BEEN OR'ED
                                           WITH CHANNEL END STATUS
                                           (GRAPHICS DEVICE)                */
#define IOBPNCH         0x01        /* ... ERROR RECOVERY IN CONTROL FOR A
                                           2540 CARD PUNCH WITH THREE
                                           BUFFERS  (QSAM)
                                           RESETPL MACRO INSTRUCTION WAS
                                           USED  (BTAM)                     */

    char            iobsens0;       /* 02 FIRST SENSE BYTE                  */
#ifndef SENSE0_CMD_REJECT
#define SENSE0_CMD_REJECT   0x80    /* ... Command reject                   */
#define SENSE0_INT_REQ      0x40    /* ... Intervention required            */
#define SENSE0_BUS_CHECK    0x20    /* ... Bus out check                    */
#define SENSE0_EQU_CHECK    0x10    /* ... Equipment check                  */
#define SENSE0_DATA_CHECK   0x08    /* ... Data check                       */
#define SENSE0_OVERRUN      0x04    /* ... Overrun                          */
#endif

    char            iobsens1;       /* 03 SECOND SENSE BYTE                 */
#ifndef SENSE1_PERM_ERROR
#define SENSE1_PERM_ERROR   0x80    /* ... Permanent Error -
                                           Unrecoverbale error has occured  */
#define SENSE1_INV_TRACK    0x40    /* ... Invalid Track Format -
                                           Write exceedes track capacity    */
#define SENSE1_END_CYL      0x20    /* ... End of Cylinder -
                                           Multitrack opeartion has
                                           encountered cylinder end         */
#define SENSE1_NOT_FOUND    0x08    /* ... No Record Found -
                                           Two index points encoutered
                                           without interveaning read        */
#define SENSE1_FILE_PROTECT 0x04    /* ... File Protected -
                                           File Mask violated               */
#define SENSE1_WRITE_INH    0x02    /* ... Write Inhibited                  */
#define SENSE1_OPER_INCOMP  0x01    /* ... Operation Incomplete             */
#endif

    union {
        void        *iobecbpt;      /* 04 ADDRESS OF ECB TO BE POSTED ON
                                          I/O COMPLETION                    */
        struct {
            char    iobecbcc;       /* 04 COMPLETION CODE FOR AN I/O REQUEST.
                                          THIS CODE WILL APPEAR IN THE FIRST
                                          BYTE OF AN ECB.                   */
            char    iobecbpb[3];    /* 05 ADDRESS OF THE ECB TO BE POSTED
                                          UPON THE COMPLETION OF AN I/O
                                          EVENT.
                                          FOR BSAM/BPAM, ECB IS IN THE DECB.
                                          FOR QSAM, ECB IS IN THE QSAM PREFIX
                                          OF THE IOB.                       */
        };
    };

#define IOBFLAG3    iobfl3          /* 08 I/O SUPERVISOR ERROR ROUTINE FLAG
                                          BYTE (DEVICE DEPENDENT)           */
    char            iobfl3;         /* 08 FLAG 3 - STATUS ERROR COUNTS FOR
                                          MAGNETIC DOCUMENT READER (3890)
                                          OR FLAGS FOR 3800 (OS/VS1)        */
#define IOBCCC      0x80            /* ... CHANNEL CONTROL CHECK ERROR
                                           COUNT (3890)                     */
#define IOBICC      0x40            /* ... INTERFACE CONTROL CHECK ERROR
                                           COUNT (3890)                     */
#define IOBCDC      0x20            /* ... CHANNEL DATA CHECK ERROR (3890)  */
#define IOBACU      0x10            /* ... ATTENTION/CONTROL UNIT ERROR
                                           (3890)                           */
#define IOBCNC      0x08            /* ... CHAIN CHECK ERROR (3890)         */
#define IOBSDR      0x08            /* ... STATISTICS ONLY FLAG (3800)      */
#define IOBMSG      0x04            /* ... MESSAGE FLAG (3890 OR 3800)      */
#define IOBICL      0x02            /* ... INCORRECT LENGTH ERROR (3890)    */
#define IOBJAM      0x02            /* ... SET ON WHEN JES SUBSYSTEM HAS
                                           DETECTED A PAPER JAM SO 3800 ERP
                                           WILL SUPPRESS ITS INTERVENTION
                                           REQUIRED MESSAGE (3800)          */
#define IOBLOG      0x01            /* ... LOG OUT FLAG (3890 OR 3800)      */

    char            iobcsw[7];      /* 09 LOW-ORDER SEVEN BYTES OF THE LAST
                                          CSW THAT REFLECTS THE STATUS FOR
                                          THIS REQUEST                      */
#define iobcmda     iobcsw          /* 09 COMMAND ADDRESS (3890)            */

#define iobustat    iobcsw[3]       /* 0C CSW UNIT STATUS FLAGS (3800)      */
#define IOBUSB0     0x80            /* ... ATTENTION                        */
#define IOBUSB1     0x40            /* ... STATUS MODIFIER                  */
#define IOBUSB2     0x20            /* ... CONTROL UNIT END                 */
#define IOBUSB3     0x10            /* ... BUSY                             */
#define IOBUSB4     0x08            /* ... CHANNEL END                      */
#define IOBUSB5     0x04            /* ... DEVICE END                       */
#define IOBUSB6     0x02            /* ... UNIT CHECK                       */
#define IOBUSB7     0x01            /* ... UNIT EXCEPTION                   */

#define iobcstat    iobcsw[4]       /* 0D CSW CHANNEL STATUS FLAGS (3800)   */
#define IOBCSB0     0x80            /* ... PROGRAM CONTROL INTERRUPT        */
#define IOBCSB1     0x40            /* ... INCORRECT LENGTH                 */
#define IOBCSB2     0x20            /* ... PROGRAM CHECK                    */
#define IOBCSB3     0x10            /* ... PROTECTION CHECK                 */
#define IOBCSB4     0x08            /* ... CHANNEL DATA CHECK               */
#define IOBCSB5     0x04            /* ... CHANNEL CONTROL CHECK            */
#define IOBCSB6     0x02            /* ... INTERFACE CONTROL CHECK          */
#define IOBCSB7     0x01            /* ... CHAINING CHECK                   */

    union {
        void        *iobstart;      /* 10 ADDRESS OF CHANNEL PROGRAM TO BE
                                          EXECUTED                          */
        struct {
            char    iobsiocc;       /* 10 SIO CODE.  BITS 2 AND 3 CONTAIN
                                          CONDITION CODE RETURNED AFTER
                                          EXECUTION OF SIO INSTRUCTION
                                          FOR THIS I/O EVENT.               */
            char    iobstrtb[3];    /* 11 ADDRESS OF CHANNEL PROGRAM TO BE
                                          EXECUTED                          */
        };
    };

    union {
        void        *iobdcbpt;      /* 14 ADDRESS OF DCB ASSOCIATED WITH
                                          THIS IOB                          */
        struct {
            char    iobflag4;       /* 14 FLAG BYTE                         */
#define IOBGDPOL    0x80            /* ... RE-ENTER SIO APPENDAGE FOR OLTEP
                                           GUARANTEED DEVICE PATH           */
#define IOBCC3WE    0x40            /* ... USER REQUESTS THAT IOS POST A
                                           X'6D' FOR A CONDITION CODE 3 ON
                                           ATTEMPTED I/O OPERATIONS (OS/VS2)*/
#define IOBPMERR    0x20            /* ... VTAM SETS THIS BIT ON TO INDICATE
                                           TO IOS THAT VTAM SHOULD BE POSTED
                                           WITH A PERMANENT I/O ERROR BECAUSE
                                           ALL ALTERNATE PATHS TO THE 3705
                                           HAVE BEEN TRIED (OS/VS1)         */
#define IOBRSV40    0x10            /* ... RESERVED                         */
#define IOBRSV41    0x08            /* ... RESERVED                         */
#define IOBRSV42    0x04            /* ... RESERVED                         */
#define IOBJES3I    0x02            /* ... JES3 INTERVENTION REQUIRED
                                           NOTIFICATION. SETTING THIS BIT
                                           WILL RESULT IN TURNING ON BIT
                                           IOSPGDPX IN THE IOSB.  (OS/VS2)  */
#define IOBRSV44    0x01            /* ... RESERVED                         */

            char    iobdcbpb[3];    /* 15 ADDRESS OF DCB ASSOCIATED WITH
                                          THIS IOB                          */
        };
    };

    union {
        void        *iobrestr;      /* 18 AFTER SVC 16 (PURGE) - QUIESCE -
                                          ADDRESS OF THE NEXT IOB IN THE PURGE
                                          CHAIN.  (LAST IOB IN THE CHAIN,
                                          BYTE 4 IS FF.)
                                          DURING I/O SUPERVISOR WRITE-TO-
                                          OPERATOR ROUTINE CONTROL - CCHH PART
                                          OF THE ADDRESS OF A DEFECTIVE TRACK.
                                          DURING I/O ERROR CORRECTION
                                          (MEANINGFUL ONLY IF BIT 3 IN THE
                                          IOBFLAG1 FIELD IS ON) - ADDRESS OF
                                          THE CHANNEL PROGRAM USED TO CORRECT
                                          AN ERROR CONDITION.
                                          AFTER I/O ERROR CORRECTION - IF A
                                          CHANNEL PROGRAM IS RESTARTED THROUGH
                                          A CCW OTHER THAN THE ONE POINTED TO
                                          BY THE IOBSTART FIELD, ITS ADDRESS
                                          IS HERE.                          */
        struct {
            char    iobrepos;       /* 18 DURING I/O ERROR CORRECTION
                                          (MEANINGFUL ONLY IF BIT 3 IN THE
                                          IOBFLAG1 FIELD IS ON) FOR MAGNETIC
                                          TAPE ONLY - THE CONTROL COMMAND
                                          (BSR, FSR, ERG) REQUIRED TO
                                          REPOSITION OVER A BLOCK.          */
            char    iobrstrb[3];    /* 19 SAME AS IOBRESTR ABOVE            */
        };
    };

    union {
        unsigned short  iobincam;   /* 1C QSAM, BSAM, EXCP ACCESS METHOD --
                                          NORMAL SCHEDULING - VALUE USED TO
                                          INCREMENT BLOCK COUNT FIELD IN DCB
                                          FOR MAGNETIC TAPE.
                                          CHAINED SCHEDULING - ZEROS.
                                          QSAM, BSAM -- OPERATION CODE OF
                                          WRITE CCW WHEN A USASI CONTROL
                                          CHARACTER AND NO DATA IS TO BE
                                          WRITTEN (PRINTER AND CARD PUNCH ONLY)
                                                                            */
        struct {
            char        iobbtamf;   /* 1C FLAG BYTE FOR BTAM                */
#define IOBPRMER    0x80            /* ... SAD OR ENABLE ISSUED BY OPEN
                                           RESULTED IN A PERMANENT I/O ERROR*/
#define IOBINUSE    0x40            /* ... THIS IOB IS CURRENTLY IN USE BY
                                           AN I/O OPERATION                 */
#define IOBRSV14    0x20            /* ... RESERVED                         */
#define IOBRSV15    0x10            /* ... RESERVED                         */
#define IOBRSV16    0x08            /* ... RESERVED                         */
#define IOBRSV17    0x04            /* ... RESERVED                         */
#define IOBRFTMG    0x02            /* ... A REQUEST-FOR-TEST MESSAGE RECEIVED
                                           FROM A REMOTE 3270 DISPLAY STATION
                                                                            */
#define IOBOLTST    0x01            /* ... LINE IS UNDER ON-LINE TEST
                                           OPERATION                        */
            char        unused2E;
        };
    };

    unsigned short      ioberrct;   /* 1E USED BY I/O SUPERVISOR ERROR ROUTINES
                                          TO COUNT TEMPORARY ERRORS DURING
                                          RETRY                             */
/***********************************************************************
 *                                                                     *
 *                   EXTENSION SECTIONS OF THE IOB                     *
 *                                                                     *
 ***********************************************************************/
    union {
        char        iobexten[8];    /* 20 IOB Extension                     */
        char        iobseek[8];     /* 20 A SEEK ADDRESS (IN THE FORMAT
                                          MBBCCHHR) USED WITH A CHANNEL
                                          PROGRAM                           */
        struct {
            char    iobm;           /* 20 THE NUMBER OF THE DEB EXTENT TO BE
                                          USED FOR THIS REQUEST.  THE FIRST
                                          EXTENT IS NUMBER 0.               */
            union {
              unsigned char iobbb[2];/* 21 BIN NUMBER(DATA CELL)            */
              struct {
                char    iobbb1;     /* 21                                   */
                char    iobbb2;     /* 22                                   */
              };
            };
            union {
              unsigned char iobcc[2];/* 23 CYLINDER NUMBER                  */
              struct {
                char    iobcc1;     /* 23                                   */
                char    iobcc2;     /* 24                                   */
              };
            };
            union {
              unsigned char iobhh[2];/* 25 TRACK NUMBER                     */
              struct {
                char    iobhh1;     /* 25                                   */
                char    iobhh2;     /* 26                                   */
              };
            };
            char        iobr;       /* 27 RECORD NUMBER                     */
        };
    };
};                                  /* 28 (40 bytes)                        */
#pragma pack(reset)

#endif
