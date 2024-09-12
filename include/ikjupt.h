#ifndef IKJUPT_H
#define IKJUPT_H

/**********************************************************************
*    THE USER PROFILE TABLE (UPT) IS BUILT BY THE LOGON/LOGOFF        *
*    SCHEDULER FROM INFORMATION STORED IN THE UADS AND FROM THE       *
*    LOGON COMMAND.  IT IS IN CORE SHARED BY THE TMP AND THE          *
*    LOGON/LOGOFF SCHEDULER.  CP'S AND SERVICE ROUTINES CAN MODIFY    *
*    THE UPT, BUT THEY CANNOT FREE IT.                                *
**********************************************************************/
typedef struct ikjupt {
	char 		reserved1[2];	/* 00 reserved							*/
	char 		uptuser[10];	/* 02 RESERVED FOR INSTALLATION USE     */
	char 		uptsws;			/* 0C USERS ENVIRONMENT SWITCHES        */
#define UPTRCVR		0x80		/* ... EDIT RECOVER OPTION IS REQUESTED DEFLT */
#define UPTNPRM  	0x40		/* ... NO PROMPTING IS TO BE DONE       */
#define UPTMID   	0x20		/* ... PRINT MESSAGE IDENTIFIERS        */
#define UPTNCOM  	0x10		/* ... NO USER COMMUNICATION ALLOWED VIA SEND COMMAND */
#define UPTPAUS  	0x08		/* ... PAUSE FOR '?' WHEN IN NON-INTERACTIVE MODE */
#define UPTALD   	0x04		/* ... ATTN HAS BEEN SPECIFIED AS LINE DELETE CHAR */
#define UPTMODE  	0x02		/* ... MODE MESSAGES DESIRED            */
#define UPTWTP   	0x01		/* ... WRITE TO PROGRAMMER MESSAGES DESIRED */

	char 		uptcdel;		/* 1D CHAR DELETE CHARACTER             */
	char 		uptldel;		/* 1E LINE DELETE CHARACTER             */
	char 		reserved2;		/* 1F RESERVED                          */
	char 		uptprefx[7];	/* 20 DSNAME PREFIX                     */
	char 		uptprefl;		/* 27 LENGTH OF DSNAME PREFIX           */
} UPT;

#endif /* IKJUPT_H */
