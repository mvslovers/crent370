#ifndef HASPHCT_H
#define HASPHCT_H

typedef struct __hct    __HCT;

/* JES Checkpoint Master Record */
struct __hct {
    unsigned int    _MASTERL;       /* 00 CHECKPOINT MASTER RCD LEN         */
    unsigned short  _JOBRECN;       /* 04 NUMBER OF 4K JOB Q RECORDS        */
    unsigned short  _JOTRECN;       /* 06 NUMBER OF 4K JOT   RECORDS        */
    unsigned int    _1;             /* 08 RESERVED                          */
    unsigned short  _2;             /* 0C RESERVED                          */
    unsigned char   _WCHECK;        /* 0E CKPT WRITE-CHECK-RCD VALUE        */
    unsigned char   _CKPTFLG;       /* 0F CHECKPOINT DISPOSITION            */
    unsigned char   _CKPUSER[8];    /* 10 CHECKPOINTED USER FIELD           */
    unsigned int    _UNSPUNQ;       /* 18 MTTR OF SPIN IOTS WAITING FOR JOT */
    unsigned int    _NEWSIOT;       /* 1C MTTR OF JES2-NEWS IOT, OR ZERO    */
    unsigned int    _NEWSTTR;       /* 20 MTTR OF JES2-NEWS DS, OR ZERO     */
    unsigned short  _JQFREE;        /* 24 OFFSET/4 OF FIRST FREE JQE        */
    unsigned short  _JQHEADS[47];   /* 26 HEADS OF ACTIVE JOB QUEUE CHAINS  */
#define _JQTYPES    47              /* ... NUMBER OF JOB QUEUES             */
    unsigned int    _DATAKEY;       /* 84 MASTER PERIPHERAL DATA SET KEY    */
    unsigned short  _JOBNO;         /* 88 HASP JOB NUMBER                   */
    unsigned short  _STCNO;         /* 8A STARTED TASK NUMBER               */
    unsigned short  _TSUNO;         /* 8C TIME-SHARING USER NUMBER          */
    unsigned short  _3[6];          /* 8E RESERVED                          */
    unsigned char   _HASPID[4];     /* 9A CL4'JES2' CHECKPOINT RECORD IDENT */
    unsigned char   _CHKPT[6];      /* 9E CHECKPOINT VOLUME SERIAL NUMBER   */
    unsigned char   _CHKPT2[6];     /* A4 SECONDARY CHECKPOINT VOLSER       */
    unsigned char   _SPOOL[6];      /* AA PRIMARY SPOOL VOLUME              */
    unsigned short  _BUFSIZE;       /* B0 Y(1960) HASP BUFFER SIZE          */
    unsigned short  _MAXJOBS;       /* B2 MAXIMUM NUMBER OF JOBS IN SYSTEM  */
    unsigned short  _NUMJOES;       /* B4 NUMBER OF JOB OUTPUT ELEMENTS     */
    unsigned short  _MINJOES;       /* B6 MINIMUM NUMBER OF FREE JOES       */
    unsigned short  _NUMRJE;        /* B8 NUMBER OF REMOTE TERMINALS        */
    unsigned short  _NUMTGV;        /* BA NUMBER OF TRACK GROUPS PER VOLUME */
    unsigned short  _QSENO;         /* BC NUMBER OF MEMBERS IN THIS NODE    */
    unsigned char   _NUMDA;         /* BE NUMBER OF DIRECT ACCESS MODULES   */
    unsigned char   _SPOLMSG;       /* BF MSG SPOOL BUFFERS FOR EACH REMOTE */
    unsigned char   _4;             /* C0 RESERVED                          */
    unsigned char   _5;             /* C1 RESERVED                          */
    unsigned char   _RECINCR;       /* C2 RECORD ALTERNATION PARAMETER      */
    unsigned char   _TCELSIZ;       /* C3 NBR OF BUFFERS IN A TRAKCELL      */
    unsigned short  _6;             /* C4 RESERVED FOR FUTURE USE           */
    unsigned short  _7;             /* C6 RESERVED FOR FUTURE USE           */
    unsigned short  _8;             /* C8 RESERVED FOR FUTURE USE           */
    unsigned short  _9;             /* CA                                   */
};                                  /* CC (204 bytes)                       */

#endif
