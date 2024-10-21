#ifndef IEEZB806_H
#define IEEZB806_H

/********************************************************************/
/*                                                                  */
/* MODULE NAME = IEEZB806                                           */
/*                                                                  */
/* DESCRIPTIVE NAME = MASTER TRACE TABLE MAPPING MACRO              */
/*                                                                  */
/* STATUS = OS/VS2, SYSTEM CONTROL PROGRAM 2                        */
/*                                                                  */
/*   LAST UPDATE = 05/11/78                                         */
/*                                                                  */
/* FUNCTION = MAPS THE MASTER TRACE TABLE                           */
/*                                                                  */
/*   OPERATION = THIS MACRO PROVIDES TWO MAPPINGS                   */
/*                                                                  */
/*                1 MTTABLE - MAPS THE MASTER TRACE TABLE           */
/*                                                                  */
/*                2 MTENTRY - MAPS A MASTER TRACE TABLE ENTRY       */
/*                                                                  */
/* MODULE TYPE = MACRO                                              */
/*                                                                  */
/*   PROCESSOR = PLS2                                               */
/* CHANGE ACTIVITY = G64MP2D                                        */
/*                                                                  */
/********************************************************************/

typedef struct mttable  MTTABLE;
typedef struct mtentry  MTENTRY;

struct mttable {
    char            mttid[4];   /* 00 MASTER TRACE TABLE IDENTIFIER */
#define MTTID       "MTT "      /* ... eye catcher                  */
    MTENTRY         *mttcurpt;  /* 04 ADDRESS OF CURRENT ENTRY      */
    unsigned        mttentpt;   /* 08 ADDRESS OF STORAGE AREA FOR TABLE ENTRIES */
    unsigned        mttendpt;   /* 0C ADDRESS OF FIRST BYTE BEYOND END OF THE TABLE */

    union {
        unsigned    mttsize;    /* 10 SUBPOOL AND LENGTH OF TABLE FOR FREEMAIN */
        struct {
            char    mttsp;      /* 10 SUBPOOL OF TABLE              */
            char    mttlen[3];  /* 11 3B LENGTH  OF TABLE           */
        };
    };
    
    char            mttwrptm[12];/* 14 TIME TABLE WAS INITIALIZED OR
                                /*     LAST WRAPPED, IN FORM               
                                /*     IT/WTHH:MM:SS.S PRODUCED BY         
                                /*     THE USE OF THE CONTIME MACRO */
    MTENTRY         *mttwrppt;  /* 20 ADDRESS OF LAST ENTRY STORED BEFORE TABLE WRAP */
    unsigned        mttpflag;   /* 24 MASTER TRACE FACILITY INTERNAL TRACING FLAGS USED BY IEEMB808 */
    unsigned        mttdarea;   /* 28 DATA AREA LENGTH              */
    unsigned        mttrsvd1;   /* 2C RESERVED WORD                 */
    unsigned        mttwk808[16]; /* 30 MTTWK808 WORK AREA FOR IEEMB808 */
    char            mttrsvd2[16]; /* 70 RESERVED WORDS              */
    char            mttenta[0]; /* 80 storage area for MTENTRY records */
};                              /* 80 (128 bytes)                   */
#define MTTHDRLN    sizeof(MTTABLE);

/**********************************************************************
*                                                                     *
* MT ENTRY MAPS A SINGLE MASTER TRACE TABLE ENTRY                     *
*                                                                     *
*  A DETAILED DESCRIPTION OF FIELDS MTENTFLG AND MTENTTAG             *
*  CAN BE FOUND IN MACRO IEZMTPRM                                     *
*                                                                     *
**********************************************************************/
struct mtentry {
    union {
        char        mtenthdr[10]; /* 00 TABLE ENTRY HEADER          */
        struct {
            char    mtentflg[2];  /* 00 FLGS SET BY CALLER          */
            char    mtenttag[2];  /* 02 IDENTIFIES CALLER           */
            void    *mtentimm;    /* 04 CALLERS IMMEDIATE DATA      */
            short   mtentlen;     /* 08 LENGTH OF CALLERS DATA      */
            char    mtentdat[0];  /* 0A DATA PASSED BY CALLER       */
        };
    };
};

#endif  /* IEEZB806_H */
