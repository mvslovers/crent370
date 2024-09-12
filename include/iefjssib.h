#ifndef IEFJSSIB_H
#define IEFJSSIB_H

typedef struct ssib         SSIB;

/*
*  SUBSYSTEM IDENTIFICATION BLOCK (SSIB)
*
*        -IDENTIFIES THE SUBSYSTEM TO WHICH A REQUEST FOR SERVICES
*         IS BEING MADE
*
*        -CONTAINS COMMON CONTROL INFORMATION PASSED BETWEEN THE
*         REQUESTOR AND THE SUBSYSTEM
*/

/*
         L     R2,PSATOLD-PSA          OUR TCB ADDRESS                  00281000
         L     R2,TCBJSCB-TCB(,R2)     JSCB ADDRESS                     00282000
         USING IEZJSCB,R2                                               00283000
         L     R2,JSCBACT              ACTIVE JSCB ADDRESS              00284000
         L     R2,JSCBSSIB             SSIB ADDRESS                     00285000
*/

struct ssib {
    /* SSIBEGIN EQU   *                                                             */
    unsigned char   SSIBID[4];      /* 00 CL4'SSIB' CONTROL BLOCK IDENTIFIER        */
    unsigned short  SSIBLEN;        /* 04 AL2(SSIBSIZE)      SSIB LENGTH            */
    unsigned char   SSIBFLG1;       /* 06 FLAGS                                     */
#define SSIBPJES    0x80            /* ... THIS SSIB IS USED TO START THE JOB ENTRY
                                           SUBSYSTEM                                */
    unsigned char   SSIBSSID;       /* 07 SUBSYSTEM IDENTIFIER. SET IN IEFJSCVT BY
                                          SUBSYSTEM FIRST TIME IT IS INVOKED AFTER
                                          IPL. SET IN SSIB BY SUBSYSTEM INTERFACE   */
#define SSIBUNKN    0x00            /* ... UNKNOWN SUBSYSTEM ID                     */
#define SSIBJES2    0x02            /* ... JES2 SUBSYSTEM ID                        */
#define SSIBJES3    0x03            /* ... JES3 SUBSYSTEM ID                        */

    unsigned char   SSIBSSNM[4];    /* 08 SUBSYSTEM NAME                            */
    unsigned char   SSIBJBID[8];    /* 0C JOB IDENTIFIER                            */
    unsigned char   SSIBDEST[8];    /* 14 DEFAULT USERID FOR SYSOUT DESTINATION     */
    unsigned        SSIBRSV1;       /* 1C RESERVED                                  */
    unsigned        SSIBSUSE;       /* 20 RESERVED FOR SUBSYSTEM USAGE              */
};
#define SSIBSIZE    sizeof(SSIB)    /* 24 *-SSIBEGIN         SSIB LENGTH            */

#endif
