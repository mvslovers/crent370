#ifndef CLIBJES2_H
#define CLIBJES2_H

#include <time.h>
#include <time64.h>
#include "clibcp.h"                 /* JES Checkpoint prototypes            */
#include "clibjs.h"                 /* JES Spool prototypes                 */
#include "clibvsam.h"               /* needed for jesir*()                  */
#include <iefssso.h>                /* needed for jesxwrtr()                */

typedef struct jes      JES;        /* JES handle                           */
typedef struct jesjob   JESJOB;     /* JES Job info                         */
typedef struct jesdd    JESDD;      /* JES Job DD info                      */
typedef enum   jesfilt  JESFILT;    /* JES filter type                      */

struct jes {
    unsigned char   eye[8];         /* 00 eye catcher for dumps             */
#define JES_EYE     "**JES**"       /* ... eye catcher                      */
    HASPCP          *cp;            /* 08 JES Checkpoint handle             */
    HASPJS          **js;           /* 0C array of JES Spool handles        */
};

struct jesjob {
    unsigned char   eye[8];         /* 00 eye catcher for dumps             */
#define JESJOB_EYE  "*JESJOB"       /* ... eye catcher                      */
    unsigned char   jobname[9];     /* 08 job name                          */
    unsigned char   jobid[9];       /* 11 job identifier                    */
    unsigned char   owner[9];       /* 1A owner name                        */
    unsigned char   eclass;         /* 23 execution class                   */
    unsigned char   priority;       /* 24 priority                          */
    unsigned char   q_type;         /* 25 see haspjqe.h => JQETYPE          */
    unsigned char   q_flag1;        /* 26 see haspjqe.h => JQEFLAGS         */
    unsigned char   q_flag2;        /* 27 see haspjqe.h => JQEFLAG2         */
    unsigned int    iotmttr;        /* 28 MTTR of IOT                       */
    unsigned int    spinmttr;       /* 2C MTTR of SPIN IOT                  */
    JESDD           **jesdd;        /* 30 array of output dd's              */
    unsigned int    completion;     /* 34 JCTCNVRC: job completion info     */
                                    /*    after execution (high byte 0x77): */
                                    /*      bits 12-23: system ABEND code   */
                                    /*      bits  0-11: max condition code  */
                                    /*    before execution (converter RC):  */
                                    /*      0=OK, 4=JCL ERR, 8=I/O, 36=ABN  */
    time64_t        start_time64;   /* 38 start time                        */
    time64_t        end_time64;     /* 40 end time                          */
    unsigned int    jobkey;         /* 48 job key from JCT                  */
    unsigned char   jtflg;          /* 4C job termination flags (JCTJTFLG)  */
#define JESJOB_JF   0x80            /* ... JOB FAILED                       */
#define JESJOB_CF   0x40            /* ... JOB FAILED DUE TO CC             */
#define JESJOB_ABD  0x20            /* ... ABEND (system or user)           */
    unsigned char   __pad[3];       /* 4D alignment                         */
};                                  /* 50 (80 bytes)                        */

struct jesdd {
    unsigned char   eye[8];         /* 00 eye catcher for dumps             */
#define JESDD_EYE   "*JESDD*"       /* ... eye catcher                      */
    unsigned char   ddname[9];      /* 08 dd name                           */
    unsigned char   stepname[9];    /* 11 step name                         */
    unsigned char   procstep[9];    /* 1A proc step name                    */
    unsigned char   dsname[45];     /* 23 dataset name                      */
    unsigned char   oclass;         /* 50 output class                      */
    unsigned char   recfm;          /* 51 record format (same as DCB RECFM) */
#define RECFM_LA    0xE0            /* ... RECORD LENGTH INDICATOR - ASCII  */
#define RECFM_D     0x20            /* ... ASCII VARIABLE RECORD LENGTH     */
#define RECFM_L     0xC0            /* ... RECORD LENGTH INDICATOR          */
#define RECFM_F     0x80            /* ... FIXED RECORD LENGTH              */
#define RECFM_V     0x40            /* ... VARIABLE RECORD LENGTH           */
#define RECFM_U     0xC0            /* ... UNDEFINED RECORD LENGTH          */
#define RECFM_TO    0x20            /* ... TRACK OVERFLOW                   */
#define RECFM_BR    0x10            /* ... BLOCKED RECORDS                  */
#define RECFM_SB    0x08            /* ... FOR FIXED LENGTH RECORD FORMAT -
                                           STANDARD BLOCKS.
                                           FOR VARIABLE LENGTH RECORD FORMAT -
                                           SPANNED RECORDS                  */
#define RECFM_CC    0x06            /* ... CONTROL CHARACTER INDICATOR      */
#define RECFM_CA    0x04            /* ... ASA CONTROL CHARACTER            */
#define RECFM_CM    0x02            /* ... MACHINE CONTROL CHARACTER        */
#define RECFM_C     0x00            /* ... NO CONTROL CHARACTER             */
#define RECFM_KL    0x01            /* ... KEY LENGTH (KEYLEN) WAS SPECIFIED*/

    unsigned char   flag;           /* 52 flags                             */
#define FLAG_JES2   0x80            /* ... this dd is JES2 generated        */
#define FLAG_SYSOUT 0x40            /* ... this dd is for SYSOUT            */
#define FLAG_SYSIN  0x20            /* ... this dd is for SYSIN             */

    unsigned char   __1;            /* 53 not used                          */
    unsigned int    mttr;           /* 54 MTTR of first output record       */
    unsigned int    records;        /* 58 record count                      */
    unsigned short  lrecl;          /* 5C logical record length             */
    unsigned short  dsid;           /* 5E dataset id                        */
#define DSID_INJCL  1               /* ... INPUT JCL STATEMENTS             */
#define DSID_OUHJL  2               /* ... HASP JOB LOG         JESMSGLG    */
#define DSID_OUJCI  3               /* ... JCL IMAGES           JESJCL      */
#define DSID_OUMSG  4               /* ... SYSTEM MESSAGES      JESYSMSG    */
#define DSID_INTXT  5               /* ... INTERNAL TEXT                    */
#define DSID_INJNL  6               /* ... JOB JOURNAL                      */
                                    /* ... otherwise SYSOUT dataset         */
};                                  /* 60 (96 bytes)                        */

enum jesfilt {
    FILTER_NONE=0,                  /* No filter                            */
    FILTER_JOBNAME,                 /* Filter by job name                   */
    FILTER_JOBID                    /* Filter by job id                     */
};

/* Open JES datasets */
JES *jesopen(void);

/* Close JES datasets */
int  jesclose(JES **jes);

/* jesjob() - return array of job info, filter by filter type, dd=1 to include dd info */
JESJOB **jesjob(JES *jes, const char *filter, JESFILT type, int dd);

/* jesjobfr() - free JESJOB array */
int jesjobfr(JESJOB ***pppjesjob);

/* jesjobf1() - free 1 JESJOB */
int jesjobf1(JESJOB **ppjesjob);

/* jesprint() - print a job SYSOUT by DSID via callback function pointer */
int jesprint(JES *jes, JESJOB *job, unsigned dsid, int(*prt)(const char *line, unsigned linelen));

/* jesdelj() - delete job output by job name and/or job id */
int jesdelj(const char *jobname, const char *jobid);
#define DELJ_OK     0               /* EVERYTHING IS OK                     */
#define DELJ_EODS   4               /* NO MORE DATA SETS TO SELECT          */
#define DELJ_NJOB   8               /* JOB NOT FOUND                        */
#define DELJ_INVA   12              /* INVALID SEARCH ARGUMENTS             */
#define DELJ_UNAV   16              /* UNABLE TO PROCESS NOW                */
#define DELJ_DUPJ   20              /* DUPLICATE JOBNAMES                   */
#define DELJ_INVJ   24              /* INVALID JOBNAME/JOBID COMBINATION    */
#define DELJ_IDST   28              /* INVALID DESTINATION SPECIFIED        */


/* jescanj() - cancel job by job name and job id */
int jescanj(const char *jobname, const char *jobid, int purge_output);
#define CANJ_OK     0               /* CANCEL/STATUS COMPLETED              */
#define CANJ_NOJB   4               /* JOB NAME NOT FOUND                   */
#define CANJ_BADI   8               /* INVALID JOBNAME/JOB ID COMBINATION   */
#define CANJ_NCAN   12              /* JOB NOT CANCELLED - DUPLICATE        */
/*                                     JOBNAMES AND NO JOB ID GIVEN         */
#define CANJ_SMALL  16              /* STATUS ARRAY TOO SMALL               */
#define CANJ_OUTP   20              /* JOB NOT CANCELLED-JOB ON OUTPUT QUEUE*/
#define CANJ_SYNTX  24              /* JOBID WITH INVALID SYNTAX FOR        */
/*                                     SUBSYSTEM                            */
#define CANJ_ICAN   28              /* INVALID CANCEL REQUEST - CANNOT      */
/*                                     CANCEL AN ACTIVE TSO USER OR STARTED */
/*                                     TASK / TSO USER MAY NOT CANCEL THE   */
/*                                     ABOVE JOBS UNLESS THEY ARE ON AN     */
/*                                     OUTPUT QUEUE.                        */

/* jesreque() - release and queue output by job name and/or job id */
/* if oclass is NULL or "" then output class "C" is used */
int jesreque(const char *jobname, const char *jobid, const char *oclass);
#define REQUE_OK    0               /* EVERYTHING IS OK                     */
#define REQUE_EODS  4               /* NO MORE DATA SETS TO SELECT          */
#define REQUE_NJOB  8               /* JOB NOT FOUND                        */
#define REQUE_INVA  12              /* INVALID SEARCH ARGUMENTS             */
#define REQUE_UNAV  16              /* UNABLE TO PROCESS NOW                */
#define REQUE_DUPJ  20              /* DUPLICATE JOBNAMES                   */
#define REQUE_INVJ  24              /* INVALID JOBNAME/JOBID COMBINATION    */
#define REQUE_IDST  28              /* INVALID DESTINATION SPECIFIED        */

/* jesxwrtr() - request jes select output by writer name */
int jesxwrtr(SSSO *ssso, const char *class_list, const char *dest, const char *form);

/* jesxdone() - tell jes we're done with sysout processing */
int jesxdone(SSSO *ssso);

int jesiropn(VSFILE **vsfile);
int jesirput(VSFILE  *vsfile, char card[80]);
int jesircls(VSFILE  *vsfile);
#endif

