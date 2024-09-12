#ifndef IKJPSCB_H
#define IKJPSCB_H

#include "ikjupt.h"
/**********************************************************************
*    THE PROTECTED STEP CONTROL BLOCK IS CONSTRUCTED BY LOGON AND      
*    FILLED IN FROM THE UADS .  A FIXED LENGTH TABLE WITH ATTRIBUTE    
*    AND ACCOUNTING FIELDS, THE PSCB IS USED TO MAINTAIN USER ATTRI-   
*    BUTES AND ACCOUNTING DATA ON A USERID BASIS.  THE ADDRESS OF PSCB 
*    IS PASSED TO THE TMP.  HENCE IT IS AN EXTERNAL INTERFACE          
*                                                                      
*   CHANGE ACTIVITY -                                          @YA20518
*    OY20518 - CHECK FOR PSCBSTOR AND IF SPECIFIED SET PSCBSTORAGE     
*              TO THE VALUE SPECIFIED FOR PSCBSTOR SO THAT PROGRAMS    
*              THAT CALL THIS MACRO DO NOT HAVE TO CHANGE THEIR        
*              CODE.                                           @YA20518
*                                                                      
***********************************************************************/

typedef struct ikjpscb {
	char 		pscbuser[7];	/* 00 USERID PADDED RIGHT WITH BLANKS	*/
	char		pscbusrl;		/* 07 LENGTH OF USERID                  */
	char 		pscbgpgm[8];	/* 08 ESOTERIC GROUP NAME INIT BY LOGON FROM UADS
								**    USED BY DYN ALLOC WHEN UNITNAME NOT SPECIFIED  
								**    BUT IS REQUIRED                   */
	char 		pscbatr1;		/* 10 A 15 BIT STRING OF USER ATTRIBUTES*/
#define PSCBCTRL 	0x80		/* ... OPERATOR COMMAND USER            */
#define PSCBACCT 	0x40		/* ... ACCOUNT  COMMAND USER            */
#define PSCBJCL  	0x20		/* ... SUBMIT   COMMAND USER            */
#define PSCBVMNT 	0x10		/* ... CNTL VOL MOUNT AUTH              */
#define PSCBATTN 	0x08		/* ... LINE DELETE CHAR IS ATTENTION    */
#define PSCBRCVR 	0x04		/* ... EDIT RECOVER/NORECOVER           */
								/* ... BITS 6 - 15 RESERVED FOR IBM USE */
	char 		reserved1;		/* 11  RESERVED                         */
	char 		pscbatr2;		/* 12 A 15 BIT STRING RESERVED FOR INSTALLATION USE  */
    char        pscbatr3;		/* 13 ... */
	unsigned    pscbltim[2];	/* 14 DOUBLEWORD FOR LOGON TIME         */
								/* ... IN STORE CLOCK UNITS             */
	char 		pscbsubh;		/* 1C SUBMIT HOLD CLASS                 */
	char 		pscbsubc;		/* 1D SUBMIT CLASS                      */
	char 		pscbsubm;		/* 1E SUBMIT MSGCLASS                   */
	char 		pscbsout;		/* 1F SYSOUT CLASS                      */
	unsigned    reserved2[2];	/* 20 RESERVED                          */
	char        pscbdest[8];	/* 28 DEST FOR SYSOUT DATA SETS         */
	void 		*pscbrlgb;		/* 30 PTR TO RELOGON BUFFER             */
	UPT 		*pscbupt;		/* 34 PTR TO USER PROFILE TABLE         */
	short 		pscbuptl;		/* 38 LENGTH OF UPT                     */
	char 		pscbchar;		/* 3A USER'S CHARACTER DELETE CHARACTER */
	char 		pscbline;		/* 3B USER'S LINE DELETE CHARACTER      */
	unsigned    pscbrsz;		/* 3C REGION SIZE REQUESTED IN 2K UNITS */
	char        pscbu[8];		/* 40 RESERVED FOR INSTALLATION USE     */
} PSCB;

#endif /* IKJPSCB_H */
