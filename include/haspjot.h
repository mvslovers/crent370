#ifndef HASPJOT_H
#define HASPJOT_H

#include "haspjoe.h"

typedef struct __jot    __JOT;  /* JES Job Output Table */

struct __jot {
    unsigned short  JOTFREC;    /* 00 COUNT OF FREE JOES                    */
    unsigned short  JOTFREQ;    /* 02 OFFSET/4 QUEUE OF FREE-JOES           */
    unsigned short  JOTCHRQ;    /* 04 OFFSET/4 QUEUE OF CHAR-JOES           */
    /* JOTRDYWQ DS    0XL74               READY WORK JOE QUEUES             */
    unsigned short  JOTNTWKQ;   /* 06 RESERVED WORK QUEUE                   */
    unsigned short  JOTCLSQ[36];/* 08 OFFSET/4 QUEUE OF CLASS WORK-JOES     */
    unsigned char   _1[28];     /* 50                                       */
    __JOE           JOTJOES[0]; /* 6C START OF JOB OUTPUT ELEMENTS          */
};

#endif // HASPJOT_H
