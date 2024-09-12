#ifndef SAFP_H
#define SAFP_H

typedef struct safp     SAFP;   /* SAF ROUTER PARAMETER LIST                */

struct safp {
    int         safprret;       /* 00 RACF OR INSTALLATION EXIT RETURN CODE */
    int         safprrea;       /* 04 RACF OR INSTALLATION EXIT REASON CODE */
    short       safpln;         /* 08 LENGTH OF SAFP PARAMETER LIST IN BYTES*/
    short       unused1;        /* 0A RESERVED                              */
    short       safpreqt;       /* 0C REQUEST NUMBER (VALUES DEFINED BELOW) */
#define SAFPAU      1           /* ... RACHECK  - AUTHORIZATION FUNCTION    */
#define SAFPFAU     2           /* ... FRACHECK - FAST AUTHORIZATION
                                       FUNCTION                             */
#define SAFPLIS     3           /* ... RACLIST  - INCORE LIST BUILDING
                                       FUNCTION                             */
#define SAFPDEF     4           /* ... RACDEF   - DEFINITION FUNCTION       */
#define SAFPVER     5           /* ... RACINIT  - VERIFICATION FUNCTION     */
#define SAFPEXT     6           /* ... ICHEXTRT - EXTRACT FUNCTION          */
    short       unused2;        /* 0E RESERVED                              */
    char        *safpreqr;      /* 10 REQUESTOR NAME ADDRESS (POINTS
                                      TO AN 8-BYTE CHARACTER FIELD)         */
    char        *safpsubs;      /* 14 SUBSYSTEM NAME ADDRESS (POINTS
                                      TO AN 8-BYTE CHARACTER FIELD)         */
    void        *safpwa;        /* 18 SAF WORKAREA ADDRESS                  */
    unsigned    unused3[2];     /* 1C RESERVED                              */
    int         safpracp;       /* 24 OFFSET TO RACF-RELATED PARAMETER LIST
                                      FROM BASE ADDRESS OF SAFP             */
};                              /* 28 (40 bytes)                            */

#endif
