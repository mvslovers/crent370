#ifndef IEFSSSO_H
#define IEFSSSO_H

#include <iefssobh.h>               /* SSOB Header                          */

#define SSOBSOUT    1               /* SYSOUT FUNCTION ID (SSOBFUNC)        */
/*
/*  PROCESS SYSOUT DATA SETS RETURN CODES (SSOBRETN)
*/
#define SSSORTOK    0               /* EVERYTHING IS OK                     */
#define SSSOEODS    4               /* NO MORE DATA SETS TO SELECT          */
#define SSSONJOB    8               /* JOB NOT FOUND                        */
#define SSSOINVA    12              /* INVALID SEARCH ARGUMENTS             */
#define SSSOUNAV    16              /* UNABLE TO PROCESS NOW                */
#define SSSODUPJ    20              /* DUPLICATE JOBNAMES                   */
#define SSSOINVJ    24              /* INVALID JOBNAME/JOBID COMBINATION    */
#define SSSOIDST    28              /* INVALID DESTINATION SPECIFIED        */

typedef struct ssso         SSSO;
typedef struct sssowtrc     WTRC;

struct ssso {
    unsigned short  SSSOLEN;    /* 00 SYSOUT EXTENSION LENGTH               */
    unsigned char   SSSOUFLG;   /* 02 USER SELECTION OPTIONS CLASS          */
/*                                    ROUTING AND DISPOSITION FLAGS         */
#define SSSOSETC    0x80        /* ... USE SSSOCLAS AS DISPOSITION          */
#define SSSODELC    0x40        /* ... DELETE SELECTED DATA SET             */
#define SSSOROUT    0x20        /* ... REROUTE SELECTED DATA SET TO         */
/*                                     DESTINATION IN SSSODEST              */
#define SSSOHOLD    0x10        /* ... HOLD ALL SELECTED DATA SETS          */
#define SSSORLSE    0x08        /* ... RELEASE ALL SELECTED DATA SETS       */

    unsigned char   SSSORESV;   /* 03 RESERVED                              */
    unsigned char   SSSOFLG1;   /* 04 DATA SET SELECTION CONTROL FLAGS      */
#define SSSOHLD     0x80        /* ... SELECTION SHOULD INCLUDE HELD        */
/*                                     SYSOUT DATA SETS                     */
#define SSSOSCLS    0x40        /* ... USE CLASS                            */
#define SSSODST     0x20        /* ... USE REMOTE DESTINATION               */
#define SSSOSJBN    0x10        /* ... USE JOB NAME                         */
#define SSSOSJBI    0x08        /* ... USE JOB ID                           */
#define SSSOSPGM    0x04        /* ... USE USER WRITER PROGRAM NAME         */
#define SSSOSFRM    0x02        /* ... USE FORM NUMBER                      */

    unsigned char   SSSOFLG2;   /* 05 CURRENT DATA SET DISPOSITION FLAGS    */
#define SSSOCTRL    0x80        /* ... 1 - PROCESSING COMPLETED             */
/*                                     0 - RETURN DATA SET NAME             */
#define SSSOCHKP    0x40        /* ... USE SSSORBA TO CHECKPOINT RBA        */
/*                                     OF CURRENT DATA SET IN CLASS         */

    unsigned short  SSSOCOPY;   /* 06 NUMBER OF COPIES                      */
    unsigned char   SSSOJOBN[8];/* 08 JOB NAME                              */
    unsigned char   SSSOJOBI[8];/* 10 JOB ID                                */
    unsigned char   SSSOCLAS;   /* 18 NAME OF DESTINATION CLASS SPECIFIED   */
/*                                    VIA THE NEWCLASS PARAMETER            */
    unsigned char   SSSORSV5[3];/* 19 RESERVED                              */
    unsigned char   SSSODEST[8];/* 1C REMOTE DESTINATION SPECIFIED          */
/*                                    VIA THE DEST PARAMETER                */
    unsigned char   SSSOPGMN[8];/* 24 USER WRITER NAME                      */
    unsigned char   SSSORBA[8]; /* 2C RBA OF SYSOUT DATA SET                */
    unsigned char   SSSODSN[44];/* 34 SYSOUT DATA SET NAME                  */
    unsigned char   SSSOFORM[4];/* 60 FORM NUMBER                           */
/*
/*  SSSOCLSL WILL CONTAIN 1-8 CLASSES WHEN USED FOR REROUTING OR DELETE
/*  FUNCTIONS AND WILL CONTAIN ONLY ONE CLASS WHEN USED FOR PRINTING.
*/
    unsigned char   SSSOCLSL[8];/* 64 CLASS SELECTION LIST FOR              */
/*                                    DATA SET SELECTION                    */
    WTRC           *SSSOWTRC;   /* 6C A POINTER TO A COMMUNICATION          */
/*                                    AREA FOR THE USER WRITTEN             */
/*                                    WRITER                                */
    unsigned char   SSSODSID[8];/* 70 DATA SET ID TO PLACE SYSOUT           */
/*                                    ON EXTERNAL DEVICES                   */
};
#define SSSOSIZE    sizeof(SSSO)
#define SSOBLEN1    (SSOBHSIZ+SSSOSIZE)

struct sssowtrc {
    unsigned int    wtrcecb;    /* 00 Wait-for-work ECB                     */
    unsigned char   wtrctime[4];/* 04 Start time of the job creating the
                                      SYSOUT data set returned. The format
                                      is from the TIME macro with BIN
                                      specified.                            */
    unsigned char   wtrcdate[4];/* 08 Start date of the job creating the
                                      SYSOUT data set returned, in packed
                                      decimal form where F is the sign:
                                      0cyydddF.                             */
    unsigned char   wtrcuse[8]; /* 0C The installation dependent value from
                                      JMRUSEID. Length of 8 bytes.          */
};                              /* 14 (20 bytes)                            */

#endif
