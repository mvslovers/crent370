#include <clibstae.h>
#include <clibcrt.h>

typedef struct {
    unsigned    r[16];
} REGS;
typedef struct {
    unsigned    u[2];
} PARAM;

__asm__("\n&FUNC    SETC 'failed'");
static int
failed(SDWA *sdwa, void *udata)
{
    PARAM       *param  = (PARAM*)udata;
    REGS        *regs   = (REGS*)param->u[1];
    unsigned    abcode  = (*(unsigned*)&sdwa->SDWACMPF) & 0x00FFFFFF;
    unsigned    retry   = 0;

    if (abcode) {
        /* return abend code in R15 */
        regs->r[15] = abcode;
    }

    /* get the retry address */
    __asm__("L\t%0,=A(RETRY)" : "=r" (retry));

    /* suppress dump */
    sdwa->SDWACMPF = 0;

    /* update the retry registers */
    __asm__("MVC\t0(64,%0),0(%1)" :
        : "r" (&sdwa->SDWASR00), "r" (regs) );

    /* RC=4,RETRY=retry,restore registers */
    SETRP(sdwa,4,retry,1);

    /* 4=retry */
    return 4;
}

__asm__("\n&FUNC    SETC 'call'");
static int
call(void *func, void *plist)
{
	CLIBCRT 	*crt = __crtget();
    int         rc;
    REGS        regs;

    /* populate the retry registers */
    __asm__("STM\t0,14,0(%0)" : : "r" (&regs));
    regs.r[15] = (unsigned) (-1);

	if (crt) crt->crttryrc = 0;

    /* create ESTAE with failed() as the recovery routine */
    rc = estae(ESTAE_CREATE, failed, &regs);
    if (rc) {
        rc *= -1;   /* make negative */
        goto quit;
    }

    __asm__(
    "LR\t15,%1          => function to call \n\t"
    "LR\t1,%2           => parameter list\n\t"
    "BALR\t14,15         call function\n\t"
    "SR\t15,15         function completed without abend\n\t"
    "LR\t%0,15         save return code"
    : "=r" (rc)
    : "r" (func), "r" (plist)
    : "0", "1", "14", "15");

	if (!rc) goto cleanup;

    __asm__("\n"
"RETRY    DS   0H");

    __asm__("LR\t%0,15" : "=r" (rc));

	/* isolate the system and user abend codes */
    rc &= 0xFFFFFF;
    
    /* save abend code in crt */
	if (crt) crt->crttryrc = rc;

cleanup:
    /* remove the estae */
    estae(ESTAE_DELETE, 0, 0);

quit:
    return rc;
}

/* call func with ESTAE protection, RC0=success otherwise failed */
int
___try(void *func, ...)
{
    int         rc;
    void        *r1 = (void*)(&func)+4;

    rc = call(func, r1);

#if 0	/* debug code */
	if (rc != 0) {
		if (rc > 0xFFF) {
			/* ESTAE capyured system abend */
			wtof("%s: ABEND S%03X", __func__, (rc >> 12) & 0xFFF);
		}
		else if (rc > 0) {
			/* ESTAE captured user abend */
			wtof("%s: ABEND U%04d", __func__, rc);
		}
		else if (rc < 0) {
			/* ESTAE CREATE failed in call() function */
			int i = rc *= -1;	/* make rc a positive value */
			wtof("%s: ESTAE CREATE failed, RC=0x%08X (%d)", __func__, i, i);
		}
	}
#endif

    return rc;
}

unsigned ___tryrc(void)
{
	unsigned 	rc = 0xFFFFFFFF;
	CLIBCRT 	*crt = __crtget();
	
	if (crt) rc = crt->crttryrc;
	
	return rc;
}
