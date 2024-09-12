#ifndef RB99_H
#define RB99_H

typedef struct rb99     RB99;
typedef struct rbx99    RBX99;

struct rb99 {
   unsigned char     len;        /* Lenght of RB (20)                       */

   unsigned char     request;    /* Request                                 */
#define S99VRBAL     0x01        /*    ALLOCATION                           */
#define S99VRBUN     0x02        /*    UNALLOCATION                         */
#define S99VRBCC     0x03        /*    CONCATENATION                        */
#define S99VRBDC     0x04        /*    DECONCATENATION                      */
#define S99VRBRI     0x05        /*    REMOVE IN-USE                        */
#define S99VRBDN     0x06        /*    DDNAME ALLOCATION                    */
#define S99VRBIN     0x07        /*    INFORMATION RETRIEVAL                */

   unsigned char     flag1;      /* First falg byte                         */
#define S99ONCNV     0x80        /*    ALLOC FUNCTION-DO NOT USE AN EXISTING
                                       ALLOCATION THAT DOES NOT HAVE THE
                                       CONVERTIBLE ATTRIBUTE TO SATISFY A
                                       REQUEST                              */
#define S99NOCNV     0x40        /*    ALLOC FUNCTION-DO NOT USE AN EXISTING
                                       ALLOCATION TO SATISFY THE REQUEST    */
#define S99NOMNT     0x20        /*    ALLOC FUNCTION-DO NOT MOUNT VOLUMES
                                       OR CONSIDER OFFLINE UNITS (THIS FLAG
                                       OVERRIDES S99MOUNT AND S99OFFLN BELOW)*/
#define S99JBSYS     0x10        /*    ALLOC FUNC-JOB RELATED SYSOUT        */
#define S99CNENQ     0x08        /*    ALL FUNCTIONS-ISSUE A CONDITIONAL ENQ
                                       ON TIOT RESOURCE. IF NOT AVAILABLE,
                                       RETURN AN ERROR CODE TO USER.        */
#define S99GDGNT     0x04        /*    ALLOC FUNCTION - IGNORE THE GDG NAME
                                       TABLE AND PERFORM A LOCATE FOR THE
                                       GDG BASE LEVEL.                      */
#define S99MSGL0     0x02        /*    All functions - ignore the MSGLEVEL
                                       parameter in the JCT and use
                                       MSGLEVEL=(,0)                        */
#define S99NOMIG     0x01        /*    ALLOC function - do not recall
                                       migrated data sets                   */

   unsigned char     flag2;      /* Second flag byte                        */
#define S99NOSYM     0x80        /*    Allocate, unallocate, info retrieval
                                       - do not perform symbolic substitution*/
#define S99ACUCB     0x40        /*    Alloc function-use Actual UCB address */

   short             error;      /* DAIR Error Code                         */
   short             info;       /* DAIR Information Code                   */
   void              *txtptr;    /* Text pointers address                   */
   void              *rbx99;     /* Reserved                                */
   unsigned          flag3;      /* Special Flags                           */
};

struct rbx99 {
   unsigned char     eye[6];     /* CONTROL BLOCK ID ='S99RBX'              */
   unsigned char     ver;        /* VERSION NUMBER                          */
#define S99RBXVR     0x01        /*    CURRENT VERSION NUMBER               */

   unsigned char     flag1;      /* PROCESSING OPTIONS                      */
#define S99EIMSG     0x80        /*    ISSUE MSG BEFORE RETURNING TO CALLER */
#define S99ERMSG     0x40        /*    RETURN MSG TO CALLER                 */
#define S99ELSTO     0x20        /*    USER STORAGE SHOULD BE BELOW 16M
                                       BOUNDRY                              */
#define S99EMKEY     0x10        /*    USER SPECIFIED STORAGE KEY FOR MESSAGE
                                       BLOCKS                               */
#define S99EMSUB     0x08        /*    USER SPECIFIED SUBPOOL FOR MESSAGE
                                       BLOCKS                               */
#define S99EWTP      0x04        /*    USE WTO FOR MESSAGE OUTPUT           */

   unsigned char     subpool;    /* SUBPOOL FOR MESSAGE BLOCKS              */
   unsigned char     key;        /* STORAGE KEY FOR MESSAGE BLOCKS          */
   unsigned char     msgsev;     /* SEVERITY LEVEL FOR MESSAGES PROCESSING  */
#define S99XINFO     0x00        /*    INFORMATIONAL MSG SEVERITY           */
#define S99XWARN     0x04        /*    WARNING MESSAGE SEVERITY             */
#define S99XSEVE     0x08        /*    SEVERE MESSAGE SEVERITY              */

   unsigned char     msgblks;    /* NUMBER OF MESSAGE BLOCKS RETURNED       */
   void             *cppl;       /* ADDRESS OF CPPL                         */
   unsigned char     s99ercr;    /* RESERVED                                */
   unsigned char     s99ercm;    /* RESERVED                                */
   unsigned char     s99erco;    /* RETURN CODE DEALING WITH MESSAGE OUTPUT */
   unsigned char     s99ercf;    /* RETURN CODE DEALING WITH STORAGE FOR
                                    MESSAGE BLOCKS                          */
   int               s99ewrc;    /* PUTLINE/WTO RETURN CODE                 */
   void             *s99emsgp;   /* MESSAGE BLOCK POINTER                   */
   unsigned short    s99eerr;    /* ERROR REASON CODE                       */
   unsigned short    s99einfo;   /* INFORMATION REASON CODE                 */
   unsigned long     s99ersn;    /* SMS REASON CODE                         */
};

#endif
