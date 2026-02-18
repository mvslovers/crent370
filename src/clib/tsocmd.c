#include <clibtso.h>

#include <clib.h>
#include <cliblink.h>		/* __link()						*/
#include <ikjcppl.h>		/* CPPL typedef 				*/
#include <ikject.h>			/* ECT typedef					*/

/* tsocmd() - link to pgm as TSO command processor */
int tsocmd(const char *pgm, const char *buf)
{
	int			rc			= 8;
	int			pgmlen		= 0;
	int			buflen		= 0;
	int			i;
	CLIBPPA		*ppa		= __ppaget();
	ECT 		*ect		= NULL;
	TSOCBUF 	*cbuf 		= NULL;
	CPPL		cppl		= {0};

	if (!pgm) {
		wtof("%s: Missing pgm pointer", __func__);
		goto quit;
	}
	
	if (!ppa) {
		wtof("%s: No PPA", __func__);
		goto quit;
	}
	
	if (!ppa->ppacppl) {
		wtof("%s: No CPPL", __func__);
		goto quit;
	}

	if (pgm && *pgm) {
		pgmlen = strlen(pgm);
	}
	if (buf && *buf) {
		buflen = strlen(buf);
	}
	
	cbuf = calloc(1, pgmlen + buflen + sizeof(TSOCBUF) + 2);
	if (!cbuf) {
		wtof("%s: No memory for CBUF", __func__);
		goto quit;
	}

	memcpy(&cppl, ppa->ppacppl, sizeof(cppl));
	ect = cppl.cpplect;

	/* put pgm name in ect as primary command */
	memset(ect->ectpcmd, ' ', sizeof(ect->ectpcmd));
	if (pgmlen > sizeof(ect->ectpcmd)) pgmlen = sizeof(ect->ectpcmd);
	memcpy(ect->ectpcmd, pgm, pgmlen);

	cbuf->cbuflen = 4;
	cbuf->cmdlen = pgmlen;
	if (!buflen) {
		ect->ectsws |= ECTNOPD;		/* turn on NO OPERANDS switch */
		cbuf->cbuflen += sprintf(cbuf->cmdname, "%s", pgm);
	}
	else {
		ect->ectsws &= ~ECTNOPD;	/* turn off NO OPERANDS switch */
		cbuf->cbuflen += sprintf(cbuf->cmdname, "%s %s", pgm, buf);
		cbuf->cmdlen++;
	}

	cppl.cpplcbuf = cbuf;
		
	// wtodumpf(&cppl, sizeof(cppl), "CPPL");
	// wtodumpf(cbuf, cbuf->cbuflen, "CBUF");

	__link(pgm, NULL, &cppl, &rc);
	
quit:
	if (cbuf) free(cbuf);

	return rc;
}
