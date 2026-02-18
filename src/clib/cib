#ifndef CIB_H
#define CIB_H
 
typedef struct com      COM;
typedef struct cib      CIB;
 
struct com {
    unsigned        *comecbpt;  /* PTR TO ECB FOR STOP OR MODIFY COMMAND    */
    CIB             *comcibpt;  /* PTR TO COMMAND INPUT BUFFER (CIB)        */
};
 
#pragma pack(1)
struct cib {
    CIB             *cibnext;   /* ADDRESS OF NEXT CIB IN QUEUE (0 FOR LAST)*/
    unsigned char   cibverb;    /* COMMAND VERB CODE                        */
#define CIBSTART    0x04        /* COMMAND CODE FOR START                   */
#define CIBMODFY    0x44        /* COMMAND CODE FOR MODIFY                  */
#define CIBSTOP     0x40        /* COMMAND CODE FOR STOP                    */
#define CIBMOUNT    0x0C        /* COMMAND CODE FOR MOUNT                   */
    unsigned char   ciblen;     /* LENGTH IN DOUBLEWORDS OF CIB INCLUDING   */
                                /* ... CIBDATA                              */
    unsigned char   unused1[4]; /* RESERVED FOR CSCB COMPATIBILITY          */
    unsigned short  cibasid;    /* ADDRESS SPACE ID (OS/VS2)                */
    unsigned char   cibconid;   /* IDENTIFIER OF CONSOLE ISSUING COMMAND    */
    unsigned char   unused2;    /* RESERVED                                 */
    unsigned short  cibdatln;   /* LENGTH IN BYTES OF DATA IN CIBDATA       */
    unsigned char   cibdata[8]; /* DATA FROM COMMAND OPERAND                */
    /*        (LENGTH OF CIBDATA IS A MULTIPLE OF EIGHT BYTES               */
    /*        DEPENDING ON THE VALUE CONTAINED IN CIBLEN)                   */
    /*              START -  FOURTH POSITIONAL PARAMETER (PARMVALUE)        */
    /*              MODIFY - RESIDUAL OPERAND IMAGE FOLLOWING COMMA         */
    /*                       TERMINATING FIRST POSITIONAL PARAMETER         */
    /*              STOP -   NONE (CIB GENERATED ONLY TO GIVE CONSOLE ID)   */
};
#pragma pack(reset)
 
extern COM *cominit(void);
 
extern int cibset(unsigned count);
 
extern CIB *cibget(void);
 
extern int cibdel(CIB *cib);
 
#endif
