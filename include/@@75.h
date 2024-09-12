#ifndef __75_H
#define __75_H

/* Parameter list for DYN75 calls */
typedef struct pl75 {
    unsigned    r0;  /*  0 (Initially, but turns to > 0 after call.      00 */
    unsigned    r1;  /** Byte Counter to send                            04 */
    unsigned    r2;  /*  Source/Destination of PC buffer.  32bits.       08 */
    unsigned    r3;  /*  Direction (0 = to Host PC, 1 = from Host PC)    0C */
    unsigned    r4;  /*  Returned Bytes/Code/Socket etc.                 10 */
    unsigned    r5;  /** Source Buffer                                   14 */
    unsigned    r6;  /** Destination Buffer (If required)                18 */
    unsigned    r7;  /** Function Code (+ Socket for 'Connect', 'ioctl' &1C 
                         'select')                                          */
    unsigned    r8;  /** Aux. Data (Socket, or Port for 'Connect'...)    20 */
    unsigned    r9;  /** Aux. Data (Port, or IP Address for 'Connect'...)24 */
    unsigned    r10; /*  <Preserved A(PGT0)>                             28 */
    unsigned    r11; /*  <Preserved A(PL75)>                             2C */
    unsigned    r12; /*  <Preserved base register>                       30 */
    unsigned    r13; /*  <Preserved stack work area>                     34 */
    unsigned    r14; /*  Identifier (returned & passed back for          38
                            conversations.)                                 */
    unsigned    r15; /*  Work Variable / Return Code                     3C */
} PL75;              /*                                                  40 */

/* __75() - call TCPIP interface via X'75xxxxxx' instruction. */
extern int __75(PL75 *pl);

#endif
