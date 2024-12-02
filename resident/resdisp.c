#include <clibres.h>
#include <clibos.h>

int resdisp(unsigned fn, ...)
{
    void            *plist  = (void*)(&fn);
    void            *stack  = (void*)0;
    RESDISP         rd      = {RESDISP_EYE};
    RESDISP         rdx;
    int             rc;
    unsigned        ix;
    unsigned        size;

    /* on entry, R0 *should* have the RES address */
    __asm__ __volatile__("LR\t%0,0           save resident address" : "=r"(rd.res) : : "0");

    /* do we have a RES address? */
    if (!rd.res) return -1;

    /* validate eye catcher */
    __asm__ __volatile__("\n*** VALIDATE EYE CATCHER ***");
    __asm__ __volatile__(
        "L\tR15,=F'-2'      assume invalid\n\t"
        "CLC\t=C'" RES_EYE "',16(%0) compare eye catcher\n\t"
        "BNE\t@@L1          invalid eye catcher"
        : : "r"(rd.res) : "15");

    ix = fn;
    if (ix < 0x100) {
        /* is the function number in range? */
        if (ix >= rd.res->funcs) return -3;

        /* get the RESFUNC address */
        rd.resfunc = &rd.res->func[ix];
    }
    else {
        ix -= 0x100;

        /* is the function number in range? */
        if (ix >= rd.res->afuncs) return -3;

        /* get the RESFUNC address */
        rd.resfunc = &rd.res->afunc[ix];
    }

    /* do we have a RESFUNC address? */
    if (!rd.resfunc) return -4;

    /* do we have a function to call? */
    if (!rd.resfunc->func) return -5;

    /* do we need a new stack frame? */
    if (rd.resfunc->flags & RESSTACK) {
        /* allocate a new stack */
        size = 1024 * rd.resfunc->stack_size_k; /* 0 to 256K, 0 defaults to 8K */
        stack = res_request_getstack(rd.res, size);
        if (stack) {
            __asm__ __volatile__("ST\t%0,76(,R13)     stack nab = new stack" : : "r"(stack));
        }
        else {
            return -6;  /* out of memory */
        }
    }

    /* is caller in supervisor state */
    rd.caller_sup   = res_request_issup();
    rd.disp_sup     = rd.caller_sup;

    /* get callers PSW key */
    if (rd.caller_sup) {
do_spka:
        __asm__ __volatile__("\n*** GET PSW KEY for SUPERVISOR STATE CALLER ***");
        __asm__ __volatile__(
            "XR\tR2,R2      clear for IPK\n\t"
            "IPK\t,         get PSW key\n\t"
            "STC\tR2,%0     save PSW key"
            : "=m"(rd.caller_key) : : "2");
        rd.disp_key     = rd.caller_key;

        /* switch PSW key if needed */
        if ((rd.resfunc->flags & RESKEY0) && (rd.caller_key != PSWKEY0)) {
            __asm__ __volatile__(
            "SPKA\t0        PSW key 0\n\t");
            rd.disp_key = PSWKEY0;
        }
        else if ((rd.resfunc->flags & RESKEYU) && (rd.caller_key != PSWKEY8)) {
            __asm__ __volatile__(
            "LA\tR2,X'80'   PSW key 8\n\t"
            "SPKA\t0(R2)    PSW key 8\n\t" : : : "2");
            rd.disp_key = PSWKEY8;
        }

        if (rd.resfunc->flags & RESPROB) {
            res_request_prob(rd.res);
            rd.disp_sup = 0;
        }
    }
    else {
        /* problem mode/state caller */
        /* switch execution state if needed */
        if (rd.resfunc->flags & RESSUP) {
            res_request_sup(rd.res);
            rd.disp_sup = 1;
            goto do_spka;
        }

        /* problem mode/state caller *and* execute mode/state, get psw key */
        rd.caller_key  = res_request_key(rd.res, PSWKEYNONE);
        rd.disp_key     = rd.caller_key;

        /* switch PSW key if needed */
        if ((rd.resfunc->flags & RESKEY0) && (rd.caller_key != PSWKEY0)) {
            res_request_key(rd.res, PSWKEY0);
            rd.disp_key = PSWKEY0;
        }
        else if ((rd.resfunc->flags & RESKEYU) && (rd.caller_key != PSWKEY8)) {
            res_request_key(rd.res, PSWKEY8);
            rd.disp_key = PSWKEY8;
        }

    }


    /* call requested function */
    rdx = rd;               /* make copy of RESDISP struct */
    fn = (unsigned)&rdx;    /* make first parm address of RESDISP structure copy */
    __asm__ __volatile__("\n*** CALL RESIDENT FUNCTION ***");
    __asm__ __volatile__(
        "L\t15,%1          => function to call \n\t"
        "LR\t1,11          => parameter list\n\t"
        "BALR\t14,15       call function\n\t"
        "LR\t%0,15         save return code"
        : "=r" (rc)
        : "m" (rd.resfunc->func), "m"(plist)
        : "0", "1", "14", "15");

    /* switch execution state if needed */
    if (rd.disp_sup != rd.caller_sup) {
        /* we switched states for the resident function */
        if (rd.caller_sup==0) {
            /* caller was in problem state */
            res_request_prob(rd.res);
        }
        else {
            /* caller was in supervisor state */
            res_request_sup(rd.res);
        }
    }

    /* switch PSW key if needed */
    if (rd.caller_key != rd.disp_key) {
        res_request_key(rd.res, rd.caller_key);
    }

    if (stack) res_request_freestack(rd.res, stack);

    return rc;
}
