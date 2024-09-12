#ifndef IHAASVT_H
#define IHAASVT_H

typedef struct asvt         ASVT;

/********************************************************************/
/*                                                                  */
/*           ADDRESS SPACE VECTOR TABLE                             */
/*                                                                  */
/* OS/VS2 RELEASE 4, 04/22/75, LEVEL=1                              */
/*                                                                  */
/* METHOD OF ACCESS                                                 */
/*     BAL  - DSECT IS PRODUCED UNLESS DSECT=NO IS SPECIFIED.       */
/*            USING ON ASVT GIVES ADDRESSABILITY FOR ALL SYMBOLS.   */
/*     PL/S - DCL ASVTPTR PTR                                       */
/*                                                                  */
/* Example:                                                         */
/*       L     R9,CVTPTR               CVT ADDRESS                  */
/*       L     R9,CVTASVT-CVTMAP(,R9)  ASVT ADDRESS                 */
/*       L     R9,ASVTENTY-ASVT(,R9)   FIRST ASCB POINTER           */
/*       L     R1,0(,R9)               ASCB FOR ASID=0001 (MSTR)    */
/*       L     R1,4(,R9)               ASCB FOR ASID=0002 (JES2)    */
/********************************************************************/
struct asvt {
    unsigned char   reserved[512];  /* 00 RESERVED FOR FUTURE EXPANSION         */
    unsigned char   asvtasvt[4];    /* 200 ACRONYM IN EBCDIC "ASVT"             */
    unsigned        asvtmaxu;       /* 204 MAXIMUM NUMBER OF ADDRESS SPACES     */
    unsigned        asvtrs00;       /* 208 RESERVED                             */
    void            *asvtfrst;      /* 20C ADDRESS OF FIRST AVAILABLE ASVT      */
                                    /*     ENTRY  (MDC300)                      */
#define ASVTAVAI    0x80            /*     BIT ONE IF ASID IS AVAILABLE AND     */
                                    /*     ZERO IF ASID IS ASSIGNED             */
    void            *asvtenty[0];   /* 210 ENTRY FOR EACH POSSIBLE ASID.        */
                                    /*     IF ADDRESS SPACE ASSIGNED, ENTRY     */
                                    /*     CONTAINS ADDRESS OF ASCB. IF NOT     */
                                    /*     ASSIGNED, ENTRY CONTAINS EITHER      */
                                    /*     ADDRESS OF NEXT AVAILABLE ASID OR    */
                                    /*     ZEROS WITH HIGH-ORDER BIT ON IF      */
                                    /*     LAST ENTRY.  (MDC301)                */
#define ASVTAVAL    0x80            /*     BIT ONE IF ASID IS AVAILABLE AND     */
                                    /*     ZERO IF ASID IS ASSIGNED             */
};                                  /* 214 (532 bytes)                          */
#define ASVTLEN  sizeof(ASVT)       /* 214 (532 bytes)                          */
#define ASVTULEN sizeof(ASVT) - 512 /* 14 (20 bytes)                            */

#endif /* IHAASVT_H */
