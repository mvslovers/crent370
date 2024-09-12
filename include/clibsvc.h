#ifndef CLIBSVC_H
#define CLIBSVC_H

typedef struct svcregs      SVCREGS;

/* area passed to @@SVC from @@CRTSVC */
struct svcregs {
    unsigned        r15;        /* 00 SVC R15            (input/output)     */
    unsigned        r0;         /* 04 SVC R0             (input/output)     */
    unsigned        r1;         /* 08 SVC R1             (input/output)     */
    void            *cvt;       /* 0C CVT address        (input)            */
    void            *tcb;       /* 10 TCB address        (input)            */
    void            *svrb;      /* 14 SVRB address       (input)            */
    void            *epa;       /* 18 SVC entry address  (input)            */
    void            *ascb;      /* 1C ASCB address       (input)            */
    void            *rblink;    /* 20 RBLINK address     (input)            */
    void            *jscb;      /* 24 JSCB address       (input)            */
    unsigned        unused[2];  /* 28 unused                                */
};                              /* 30 (48 bytes)                            */

/* note: these functions execute in supervisor state and key 0, be careful */

/* __svc() SVC startup code, called by @@CRTSVC, calls svcmain(), returns to @@CRTSVC */
void __svc(SVCREGS *svcregs)                                asm("@@SVC");

/* svcmain() SVC main function, called by __svc(), returns to __svc() */
int svcmain(SVCREGS *svcregs    /* input registers  */,
            unsigned *r15       /* output register  */,
            unsigned *r0        /* output register  */,
            unsigned *r1        /* output register  */)     asm("SVCMAIN");

/* If using the default SVCMAIN module from the CRENT370 library then these R1 values identify the request */
#define SVCMAIN_SUP     0       /* request supervisor state     */
#define SVCMAIN_PROB    1       /* request problem state        */
#define SVCMAIN_KEY     2       /* request PSW KEY (R15 value), old value returned in R15 */
#define SVCMAIN_AUTHON  3       /* request JSCBAUTH ON          */
#define SVCMAIN_AUTHOFF 4       /* request JSCBAUTH OFF         */

#endif
