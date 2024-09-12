#ifndef IEFVKEYS_H
#define IEFVKEYS_H

#define ETEND       0x00    /* NONE    DICTIONARY END               */
#define PROTECTK    0x1B    /* DD      PROTECT=                     */
#define SUBSYSK     0x1C    /* DD      SUBSYS=                      */
#define CHARSK      0x1D    /* DD      CHARS=                       */
#define MODIFYK     0x1E    /* DD      MODIFY=                      */
#define FLASHK      0x1F    /* DD      FLASH=                       */
#define BURSTK      0x20    /* DD      BURST=                       */
#define DSIDK       0x21    /* DD      DSID=                        */
#define MSVGPK      0x22    /* DD      MSVGP=                       */
#define HOLDK       0x23    /* DD      HOLD=                        */
#define SYSINCTK    0x24    /* DD      INTERNAL KEY- NUMBER SYSIN
                                       RECORDS SPOOLED BY JESS      */
#define DESTK       0x25    /* DD      DEST=                        */
#define FRIDMK      0x26    /* DD      FRID=                        */
#define FREEK       0x27    /* DD      FREE=                        */
#define AMPK        0x28    /* DD      AMP=                         */
#define FUNCMK      0x29    /* DD      FUNC=                        */
#define DIAGNSK     0x2A    /* DD      DIAGNS=                      */
#define DLMK        0x2B    /* DD      DLM=                         */
#define FCBK        0x2C    /* DD      FCB=                         */
#define TERMK       0x2D    /* DD      TERM=                        */
#define THRESHMK    0x2E    /* DD      THRESH=                      */
#define RESERVMK    0x2F    /* DD      RESERVE=                     */
#define PCIMK       0x30    /* DD      PCI=                         */
#define BUFMAXMK    0x31    /* DD      BUFMAX=                      */
#define BUFOUTMK    0x32    /* DD      BUFOUT=                      */
#define BUFINMK     0x33    /* DD      BUFIN=                       */
#define BUFSIZMK    0x34    /* DD      BUFSIZE=                     */
#define DYNAK       0x35    /* DD      DYNAM                        */
#define QNAMEK      0x36    /* DD      QNAME=                       */
#define BUFOFFMK    0x37    /* DD      BUFOFF                       */
#define OUTLIMK     0x38    /* DD      OUTLIM                       */
#define IPLTXIDK    0x39    /* DD      IPLTXID=                     */
#define COPIESK     0x3A    /* DD      COPIES=                      */
#define GDSORGMK    0x3B    /* DD      GDSORG=                      */
#define GNCPMK      0x3C    /* DD      GNCP=                        */
#define UCSK        0x3D    /* DD      UCS=                         */
#define DUMMK       0x3E    /* DD      DUMMY                        */
#define CHKPTK      0x3F    /* DD      CHKPT=                       */
#define DCBK        0x40    /* DD      DCB=                         */
#define UNITK       0x41    /* DD      UNIT=                        */
#define LABELK      0x42    /* DD      LABEL=                       */
#define VOLUMEK     0x43    /* DD      VOLUME=                      */
#define AFFK        0x44    /* DD      AFF=                         */
#define SEPK        0x45    /* DD      SEP=                         */
#define DISPK       0x46    /* DD      DISP=                        */
#define SPACEK      0x47    /* DD      SPACE=                       */
#define SPLITK      0x48    /* DD      SPLIT=                       */
#define DDNAMEK     0x49    /* DD      DDNAME=                      */
#define DSNAMEK     0x4A    /* DD      DSNAME=                      */
#define SYSOUTK     0x4B    /* DD      SYSOUT=                      */
#define SUBALLOK    0x4C    /* DD      SUBALLOC=                    */
#define AFFMK       0x4D    /* DD      AFF=        MINOR            */
#define SEPMK       0x4E    /* DD      SEP=        MINOR            */
#define SERMK       0x4F    /* DD      SER=                         */
#define REFMK       0x50    /* DD      REF=                         */
#define EXPDTMK     0x51    /* DD      EXPDT=                       */
#define RETPDMK     0x52    /* DD      RETPD=                       */
#define BFALNMK     0x53    /* DD      BFALN=                       */
#define BFTEKMK     0x54    /* DD      BFTEK=                       */
#define BLKSIZMK    0x55    /* DD      BLKSIZE=                     */
#define BUFLMK      0x56    /* DD      BUFL=                        */
#define BUFNOMK     0x57    /* DD      BUFNO=                       */
#define BUFRQMK     0x58    /* DD      BUFRQ=                       */
#define CODEMK      0x59    /* DD      CODE=                        */
#define CPRIMK      0x5A    /* DD      CPRI=                        */
#define CYLOFLMK    0x5B    /* DD      CYLOFL=                      */
#define HIARCHMK    0x5C    /* DD      HIARCHY=                     */
#define DENMK       0x5D    /* DD      DEN=                         */
#define DSORGMK     0x5E    /* DD      DSORG=                       */
#define EROPTMK     0x5F    /* DD      EROPT=                       */
#define INTVLMK     0x60    /* DD      INTVL=                       */
#define KEYLENMK    0x61    /* DD      KEYLEN=                      */
#define LIMCTMK     0x62    /* DD      LIMCT=                       */
#define LRECLMK     0x63    /* DD      LRECL=                       */
#define MODEMK      0x64    /* DD      MODE =                       */
#define NCPMK       0x65    /* DD      NCP=                         */
#define NTMMK       0x66    /* DD      NTM=                         */
#define OPTCDMK     0x67    /* DD      OPTCD=                       */
#define PRTSPMK     0x68    /* DD      PRTSP=                       */
#define RECFMMK     0x69    /* DD      RECFM=                       */
#define RKPMK       0x6A    /* DD      RKP=                         */
#define SOWAMK      0x6B    /* DD      SOWA=                        */
#define STACKMK     0x6C    /* DD      STACK=                       */
#define TRTCHMK     0x6D    /* DD      TRTCH=                       */
#define DDK         0x6E    /* DD      DD                           */

#define DYNMPEK     0x7B    /* EXEC    DYNAMNBR.                    */
#define DYNMEEK     0x7C    /* EXEC    DYNAMNBR=                    */
#define PRFMPEK     0x7D    /* EXEC    PERFORM.                     */
#define PRFMEEK     0x7E    /* EXEC    PERFORM=                     */
#define ADRSPPEK    0x7F    /* EXEC    ADDRSPC.                     */
#define ADRSPEEK    0x80    /* EXEC    ADDRSPC=                     */
#define SDPPEK      0x81    /* EXEC    DPRTY.                       */
#define SDPEEK      0x82    /* EXEC    DPRTY=                       */

#define RDEEK       0x84    /* EXEC    RD=                          */
#define RDPEK       0x85    /* EXEC    RD.                          */
#define ROLLPEK     0x86    /* EXE     ROLL.                        */
#define ROLLEEK     0x87    /* EXE     ROLL=                        */
#define REGINPEK    0x88    /* EXE     REGION.                      */
#define REGINEEK    0x89    /* EXEC    REGION=                      */
#define PGMEK       0x8A    /* EXEC    PGM=                         */
#define PROCEK      0x8B    /* EXEC    PROC=                        */
#define ACCTPEK     0x8C    /* EXEC    ACCT.                        */
#define CONDPEK     0x8D    /* EXEC    COND.                        */
#define PARMPEK     0x8E    /* EXEC    PARM.                        */
#define TIMEPEK     0x8F    /* EXEC    TIME.                        */
#define ACCTEEK     0x90    /* EXEC    ACCT=                        */
#define CONDEEK     0x91    /* EXEC    COND=                        */
#define PARMEEK     0x92    /* EXEC    PARM=                        */
#define TIMEEEK     0x93    /* EXEC    TIME=                        */
#define EXECK       0x94    /* EXEC    EXEC                         */

#define GROUPK      0xA3    /* JOB     GROUP=                       */
#define PASWORDK    0xA4    /* JOB     PASSWORD=                    */
#define USERK       0xA5    /* JOB     USER=                        */
#define PRFMJK      0xA6    /* JOB     PERFORM=                     */
#define ADRSPJK     0xA7    /* JOB     ADDRSPC=                     */
#define NOTIFYJK    0xA8    /* JOB     NOTIFY=                      */
#define TIMEJK      0xA9    /* JOB     TIME=                        */
#define RESTARJK    0xAA    /* JOB     RESTART=                     */
#define RDJK        0xAB    /* JOB     RD=                          */
#define ROLLJK      0xAC    /* JOB     ROLL=                        */
#define CLASSJK     0xAD    /* JOB     CLASS=                       */
#define REGINJK     0xAE    /* JOB     REGION=                      */
#define CONDJK      0xAF    /* JOB     COND=                        */
#define PRTYJK      0xB0    /* JOB     PRTY=                        */
#define TYPRUNJK    0xB1    /* JOB     TYPRUN=                      */
#define MSGCLAJK    0xB2    /* JOB     MSGCLASS=                    */
#define MSGLEVJK    0xB3    /* JOB     MSGLEVEL=                    */
#define JOBK        0xB4    /* JOB     JOB                          */

#define INTKEY1     0xF0    /* INTERNAL KEY                         */
#define INTKEY2     0xF1    /* INTERNAL KEY                         */
#define INTKEY3     0xF2    /* INTERNAL KEY                         */
#define INTKEY4     0xF3    /* INTERNAL KEY                         */
#define INTKEY5     0xF4    /* INTERNAL KEY                         */
#define INTKEY6     0xF5    /* INTERNAL KEY RESERVED                */
#define INTKEY7     0xF6    /* INTERNAL KEY RESERVED                */
#define INTKEY8     0xF7    /* INTERNAL KEY RESERVED                */
#define INTKEY9     0xF8    /* INTERNAL KEY RESERVED                */
#define INTKEYA     0xF9    /* INTERNAL KEY RESERVED                */
#define INTKEYB     0xFA    /* INTERNAL KEY RESERVED                */
#define INTKEYC     0xFB    /* INTERNAL KEY RESERVED                */

#define ENDK        0xFE    /* NONE    END KEY                      */
#define ENDIND      0xFF    /* NONE    END OF MODULE INDICATOR      */


#endif
