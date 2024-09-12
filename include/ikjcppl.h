#ifndef IKJCPPL_H
#define IKJCPPL_H

#include "ikjpscb.h"
#include "ikjupt.h"
/**********************************************************************
*    THE COMMAND PROCESSOR PARAMETER LIST (CPPL) IS A LIST OF         *
*    ADDRESSES PASSED FROM THE TMP TO THE CP VIA REGISTER 1           *
***********************************************************************/
typedef struct tsocbuf {
	short 	cbuflen;			/* 00 buffer length				*/
	short   cmdlen;				/* 02 command length			*/
	char    cmdname[1];			/* 04 command name				*/
} TSOCBUF;

typedef struct ikjcppl {
	TSOCBUF	*cpplcbuf;			/* 00 PTR TO COMMAND BUFFER		*/
	UPT 	*cpplupt;			/* 04 PTR TO UPT				*/
	PSCB 	*cpplpscb;			/* 08 PTR TO PSCB				*/
	void 	*cpplect;			/* 0C PTR TO ECT				*/
} CPPL;

#endif /* IKJCPPL_H */
