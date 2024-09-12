#ifndef IKJECT_H
#define IKJECT_H

typedef struct ikject	ECT;

struct ikject {
	unsigned char ectrcdf;		/* 00 HIGH ORDER BIT INDICATES CP ABENDED		*/
	unsigned char ectrtcd[3];	/* 01 RETURN CODE FROM LAST CP              
								   (ABEND CODE IF ECTRCDF IS SET)           	*/
	void 		*ectiowa;		/* 04 ADDR OF I/O SERVICE ROUTINES WORK AREA	*/
	unsigned char ectmsgf;		/* 08 HIGH ORDER BIT SET MEANS DELETE SECOND 
									LEVEL MESSAGE								*/
	unsigned char ectsnsg[3];	/* 09 ADDR OF SECOND LEVEL MSG CHAIN            */
	char 		ectpcmd[8];		/* 0C PRIMARY COMMAND NAME                      */
	char		ectscmd[8];		/* 14 SUBCOMMAND NAME                           */
	unsigned char ectsws;		/* 1C 1 BYTE OF SWITCHES                        */
#define ECTNOPD  	0x80		/* ... 0 BIT ON= NO OPERANDS EXIST IN CMD BUFFER*/
/*        EQU   X'40'    RESERVED                                        */
#define ECTATRM		0x20		/* ... CP TERMINATED BY TMP DETACH W/ STAE      */
#define ECTLOGF		0x10		/* ... LOGON/OFF REQUESTED TMP TO LOGOFF USER   */
#define ECTNMAL		0x08		/* ... NO USER MSGS TO RECVED AT LOGON          */
#define ECTNNOT  	0x04		/* ... NO BRDCST NOTICES TO BE RECVED AT LOGON	*/
#define ECTBKGRD 	0x02    	/* ... BACKGROUND MODE                          */
#define ECTATTN  	0x01		/* ... ATTENTION MODE FOR CLIST                	*/

	unsigned char ectddnum[3];	/* 1D COUNTER FOR GENERATING TEMP DDNAMES       */

	void 		*ectuser;		/* 20 WORD RESERVED FOR INSTALLATION  USE       */
	void 		*ectbkpb;		/* 24 ADDR OF BACKGROUND PARAMETER BLOCK        */
	unsigned char ectsws2;		/* 28 EXTENDED FLAG FIELD                       */
#define ECTDEFCS 	0x80		/* ... DEFAULT DELETE CHARACTERS USED           */
#define ECTTABND 	0x40		/* ... TEST SUBTASK ABENDED                     */
	unsigned char reserved1[3];	/* 2C RESERVED                                  */
	void 		*reserved2;		/* 30 RESERVED                                  */
	void		*reserved3;		/* 34 RESERVED                                  */
	void 		*reserved4;		/* 38 RESERVED                                  */
};

#endif
