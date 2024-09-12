#ifndef OSDECB_H
#define OSDECB_H

typedef struct decb     DECB;       /* DECB for read/write/check */

#pragma pack(1)
struct decb {
    unsigned    decsdecb;           /* 00 EVENT CONTROL BLOCK               */
    char        dectype1;           /* 04 TYPE OF LENGTH OPERAND            */
#define DECLNS      0x80            /* ... S CODED FOR LENGTH               */
    char        dectype2;           /* 05 TYPE OF OPERATION                 */
#define DECRDSF     0x80            /* ...  READ SF                         */
#define DECRDSB     0x40            /* ...  READ SB                         */
#define DECWRSF     0x20            /* ...  WRITE SF                        */
#define DECWRSD     0x10            /* ...  WRITE SD                        */
/* #define DECRSV08    0x08            ...  RESERVED                        */
#define DECWRSZ     0x04            /* ...  WRITE SZ                        */
/* #define DECRSV09    0x02            ...  RESERVED                        */
#define DECWRSFR    0x01            /* ...  WRITE SFR (BIT 2 IS ALSO ON) OR
                                            READ RBL (BIT 0 IS ALSO ON)     */
    short       declngth;           /* 06 LENGTH OF KEY AND DATA            */
    void        *decdcbad;          /* 08 ADDRESS OF THE DCB TO WHICH THIS
                                          I/O REQUEST IS RELATED            */
    void        *decarea;           /* 0C ADDRESS OF KEY AND DATA, OR FOR
                                          1287 OR 1288 OPTICAL READERS, THE
                                          ADDRESS OF A USER-SPECIFIED
                                          CHANNEL PROGRAM                   */
    void        *deciobpt;          /* 10 ADDRESS OF THE IOB                */
    void        *decnext;           /* 14 ADDRESS OF THE NEXT ADDRESS
                                          FEEDBACK FIELD.  PRESENT ONLY IF
                                          R IS CODED IN THE WRITE MACRO.    */
    void        *decrecpt;          /* 18 ADDRESS OF THE BLOCK REFERENCE
                                          FIELD                             */
    void        *decnaa;            /* 1C ADDRESS OF THE NEXT ADDRESS
                                          FEEDBACK FIELD                    */
};
#pragma pack(reset)

#endif
