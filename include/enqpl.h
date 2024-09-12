#ifndef ENQPL_H
#define ENQPL_H

typedef struct enqpl    ENQPL;

struct enqpl {    /* SVC 56 (ENQ) and SVC 48 (DEQ) parameter list  */
    unsigned char   end;            /* 00 list end byte 0xC0                */
#define ENQ_END_LAST        0x80    /* ... last parameter list              */
#define ENQ_END_OLD         0x40    /* ... no new options                   */
    unsigned char   len;            /* 01 length of resource name           */
    unsigned char   opt;            /* 02 option byte                       */
#define ENQ_OPT_SHARED      0x80    /* ... shared request                   */
#define ENQ_OPT_STEP        0x00    /* ... scope=STEP                       */
#define ENQ_OPT_SYSTEM      0x40    /* ... scope=SYSTEM                     */
#define ENQ_OPT_SYSTEMS     0x48    /* ... scope=SYSTEMS (SYSTEM+SYSTEMS)   */
#define ENQ_OPT_TEST        0x07    /* ... RET=TEST                         */
#define ENQ_OPT_USE         0x03    /* ... RET=USE                          */
#define ENQ_OPT_CHNG        0x02    /* ... RET=CHNG                         */
#define ENQ_OPT_HAVE        0x01    /* ... RET=HAVE                         */
    unsigned char   rc;             /* 03 return code                       */
    void            *qname;         /* 04 queue name address                */
    void            *rname;         /* 08 resource name address             */
};

#endif
