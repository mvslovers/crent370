#ifndef CLIBCCW_H
#define CLIBCCW_H

typedef struct ccw0         CCW0;   /* CCW with 24 bit address  */
typedef struct ccw1         CCW1;   /* CCW with 31 bit address  */
typedef union ccw           CCW;    /* generic CCW container    */

struct ccw0 {
    unsigned int    cmd : 8;        /* 00 command code          */
    unsigned int    addr : 24;      /* 01 address               */
    unsigned char   flags;          /* 04 flags see below       */
    unsigned char   reserved;       /* 05 reserved              */
    unsigned short  count;          /* 06 bytes transfered      */
} __attribute__ ((packed));         /* 08                       */

struct ccw1 {
    unsigned char   cmd;            /* 00 command code          */
    unsigned char   flags;          /* 01 flags see below       */
    unsigned short  count;          /* 02 bytes transfered      */
    unsigned int    addr;           /* 04 address               */
} __attribute__ ((packed));         /* 08                       */

union ccw {
    CCW0            ccw0;           /* 00 type 0 ccw            */
    CCW1            ccw1;           /* 00 type 1 ccw            */
} __attribute__ ((packed));         /* 08 CCW                   */

/* standard command codes */
#define CCW_CMD_WRITE           0x01    /* mmmm mm01            */
#define CCW_CMD_READ            0x02    /* mmmm mm10            */
#define CCW_CMD_CONTROL         0x03    /* mmmm mm11            */
#define CCW_CMD_CONTROL_NOOP    0x03    /* 0000 0011            */
#define CCW_CMD_SENSE           0x04    /* mmmm 0100            */
#define CCW_CMD_SENSE_BASIC     0x04    /* 0000 0100            */
#define CCW_CMD_SENSE_ID        0xE4    /* 1110 0100            */
#define CCW_CMD_TIC             0x08    /* xxxx 1000            */

/* DASD specific command codes */
#define CCW_CMD_STLCK           0x14
#define CCW_CMD_SUSPEND_RECONN  0x5B
#define CCW_CMD_RDC             0x64
#define CCW_CMD_RELEASE         0x94
#define CCW_CMD_SET_PGID        0xAF
#define CCW_CMD_DCTL            0xF3
#define CCW_CMD_SENSE_PGID      0x34

#define SENSE_MAX_COUNT         0x20

/* standard flags */
#define CCW_FLAG_CD             0x80    /* chain data           */
#define CCW_FLAG_CC             0x40    /* chain command        */
#define CCW_FLAG_SLI            0x20    /* suppress length      */
#define CCW_FLAG_SKIP           0x10    /* suppress data xfer   */
#define CCW_FLAG_PCI            0x08    /* pgm controlled int   */
#define CCW_FLAG_IDA            0x04    /* addr -> IDAW         */
#define CCW_FLAG_SUSPEND        0x02    /* suspend execution    */

#endif
