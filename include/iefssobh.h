#ifndef IEFSSOBH_H
#define IEFSSOBH_H

/*  THE FOLLOWING RETURN CODES WILL BE RETURNED IN REGISTER 15
/*  TO THE ISSUER OF THE IEFSSREQ MACRO -
/*
/*  SSOBRETN CONTAINS FUNCTION-RELATED RETURN CODES
/*    (DEFINED IN EACH FUNCTION EXTENSION)
*/
#define SSRTOK      0           /* SUCCESSFUL COMPLETION - REQUEST WENT     */
/*                                 TO A SUBSYSTEM.                          */
#define SSRTNSUP    4           /* SUBSYSTEM DOES NOT SUPPORT THIS          */
/*                                 FUNCTION                                 */
#define SSRTNTUP    8           /* SUBSYSTEM EXISTS, BUT IS NOT UP          */
#define SSRTNOSS    12          /* SUBSYSTEM DOES NOT EXIST                 */
#define SSRTDIST    16          /* FUNCTION NOT COMPLETED-DISASTROUS        */
/*                                 ERROR                                    */
#define SSRTLERR    20          /* LOGICAL ERROR (BAD SSOB FORMAT,          */
/*                                 INCORRECT LENGTH,...)                    */

typedef struct ssob         SSOB;

struct ssob {
    unsigned char   SSOBID[4];  /* 00 CL4'SSOB' CONTROL BLOCK IDENTIFIER    */
#define SSOBID_EYE  "SSOB"      /* ...                                      */

    unsigned short  SSOBLEN;    /* 04 LENGTH OF SSOB HEADER                 */
    unsigned short  SSOBFUNC;   /* 06 FUNCTION ID                           */
    void           *SSOBSSIB;   /* 08 ADDRESS OF SSIB OR ZERO               */
    int             SSOBRETN;   /* 0C RETURN CODE FROM SUBSYSTEM            */
    void           *SSOBINDV;   /* 10 FUNCTION DEPENDENT AREA POINTER       */
};
#define SSOBHSIZ    sizeof(SSOB)

/* call jes subsystem interface */
extern int iefssreq(SSOB *ssob);

#endif
