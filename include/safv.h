#ifndef SAFV_H
#define SAFV_H

typedef struct safv     SAFV;   /* SAF VECTOR TABLE                         */

struct safv {
    char        safviden[4];    /* 00 IDENTIFYING LITERAL FOR DUMPS 'SAFV'  */
#define SAFVIDC "SAFV"
    char        safvvrsn;       /* 04 TABLE VERSION NUMBER - '00'X          */
    char        unused1[3];     /* 05 RESERVED                              */
    void        *safvexit;      /* 08 ADDRESS OF THE SAF ROUTER EXIT
                                      ROUTINE (ICHRTX00)                    */
    void        *safvsafr;      /* 0C ADDRESS OF THE SAF ROUTER
                                      ROUTINE (ICHSFR00)                    */
    void        *safvracr;      /* 10 ADDRESS OF THE RACF FRONT END
                                      ROUTINE (ICHRFR00), SET BY
                                      RACF INITIALIZATION (ICHSEC00)
                                      IF RACF IS INSTALLED                  */
    void        *safvract;      /* 14 ADDRESS OF THE RACF FRONT END
                                      TABLE (ICHRFR01), SET BY
                                      RACF INITIALIZATION (ICHSEC00)
                                      IF RACF IS INSTALLED                  */
    void        *safvexus;      /* 18 RESERVED FOR INSTALLATION EXIT USE    */
    void        *unused2;       /* 1C RESERVED                              */
};                              /* 20 (32 bytes)                            */

#endif
