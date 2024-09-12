#include <clibio.h>
#include <clibos.h>
#include <ctype.h>
#include <modmap.h>

static int      super_loadhi(const char *module, void **anchor, void **epa);
static int      relocate_load(FILE *fp, unsigned lowlp, unsigned highlp);
static int      process_rldr(unsigned char *buf, unsigned lowlp, unsigned highlp);
static unsigned fetch(unsigned address, unsigned size);
static int      store(unsigned address, unsigned value, unsigned size);

/* load a module into high memory (CSA) */
__asm__("\n&FUNC    SETC '__loadhi'");
int __loadhi(const char *module, void **lpa, void **epa, unsigned *sz)
{
    void        *highep = 0;    /* relocated entry point address    */
    void        *highlp = 0;    /* relocated load point address     */
    void        *lowep  = 0;    /* low entry point address          */
    void        *lowlp  = 0;    /* low load point address           */
    unsigned    size    = 0;    /* size of module                   */
    unsigned    offep   = 0;    /* offset of entry point            */
    FILE        *fp;            /* file handle                      */
    CDE         *cde;
    void        *dcb;
    char        member[12]   = "        ";
    char        filename[56] = {0};
    int         i;
    char        *p;

    for(i=0; i < 8 && module[i]; i++) {
        member[i] = toupper(module[i]);
    }

    /* we only load from the task STEPLIB, so grab the STEPLIB DCB */
    dcb = __steplb();

    /* load module into low storage (private area) */
    lowep = __load(dcb, member, 0, 0);
    if (!lowep) {
        wtof("%s unable to LOAD \"%s\" into private storage", __func__, member);
        goto quit;
    }

    /* get the CDE for this load module */
    cde = clib_find_cde(member);
    if (!cde) {
        wtof("%s CDE not found for \"%s\"", __func__, member);
        goto quit;
    }

    /* get the load point address */
    size  = cde->xtlst->xtlmsbla & 0x00FFFFFF;
    lowlp = (void*)cde->xtlst->xtlmsbaa;

    /* calculate offset of entry point */
    offep = (unsigned)lowep - (unsigned)lowlp;

    /* allocate CSA memory for module */
    highlp = getmain(size, 241);
    if (!highlp) {
        wtof("%s unable to allocate storage for %u bytes from subpool 241", __func__, size);
        goto quit;
    }

    /* copy the module to the getmain'd storage */
    memcpy(highlp, lowlp, size);

    /* note: After the memcpy, the highlp storage has incorrect adcons
    **       values since the lowlp module was loaded by the system routines.
    **       So we'll have to obtain the relocation info from the
    **       load module dataset (STEPLIB) and correct the adcon values
    **       in the highlp storage.
    */

    /* the load module will be read from the STEPLIB dataset to extract the RLD records */
    strcpy(filename, "DD:STEPLIB(");
    strcat(filename, member);
    strcat(filename, ")");
    fp = fopen(filename, "rb");
    if (!fp) {
        wtof("%s unable to open \"%s\" for reading", __func__, filename);
        goto quit;
    }
#if 0
    wtodumpf(lowlp, size, member);
#endif
    /* relocate the lowlp adcons to the highlp adcons */
    relocate_load(fp, (unsigned)lowlp, (unsigned)highlp);

    /* calculate high entry point address */
    highep = (void*)((unsigned)highlp + offep);

quit:
    /* cleanup resources we used */
    if (fp)     fclose(fp);
    if (lowep)  __delete(module);

    if (highep) {
        /* success */
        if (lpa) *lpa = highlp;
        if (epa) *epa = highep;
        if (sz)  *sz  = size;
        return 0;
    }
    else {
        /* failure */
        if (highlp) freemain(highlp);
        return 4;
    }
}

__asm__("\n&FUNC    SETC 'relocate_load'");
static int
relocate_load(FILE *fp, unsigned lowlp, unsigned highlp)
{
    int             rc      = 0;
    size_t          read    = 0;
    unsigned char   *dptr   = NULL;
    MMOD            *mmod   = NULL;
    int             loadtext= 0;

    /* read each record from the load module */
    for(;;) {
        /* we use __aread() for record oriented i/o */
        if (__aread(fp->dcb, &dptr, &read) != 0) {
            /* end of file */
            fp->flags |= _FILE_FLAG_EOF;
            break;
        }

        if (loadtext) {
            loadtext = 0;
            continue;
        }

        mmod = (MMOD*)dptr;

        /* check for control record that are always followed by a text record */
        if ((mmod->id & MMOD_ID_CTL) == MMOD_ID_CTL) {
            /* next record will be a text record */
            loadtext = 1;
        }

        /* process RLD records we've read */
        if ((mmod->id & MMOD_ID_RLD) == MMOD_ID_RLD) {
            process_rldr(dptr, lowlp, highlp);
        }
    }

    return rc;
}

static __inline unsigned fetch(unsigned address, unsigned size)
{
    unsigned    value   = 0;
    unsigned    n;

    for(n = 0; n < size; n++) {
        value <<= 8;
        value |= (unsigned) (*(unsigned char *)(address+n));
    }

#if 0
    wtof("FETCH(%08X,%u) VALUE(%08X)", address, size, value);
#endif
    return value;
}

static __inline int store(unsigned address, unsigned value, unsigned size)
{
    char    *addr   = (char *)address;
    char    *val    = (char *)(((unsigned)&value + sizeof(unsigned)) - size);

    memcpy(addr, val, size);

    return 0;
}

__asm__("\n&FUNC    SETC 'process_rldr'");
static int
process_rldr(unsigned char *buf, unsigned lowlp, unsigned highlp)
{
    int             rc      = 0;
    unsigned        count   = 0;
    MMRLDR          *rldr;
    MMRLD           *rld;
    MMRLDF          *rldf;
    unsigned        address;
    unsigned        value;
    unsigned        size;
    unsigned        offset;

    /* map the buffer contents */
    rldr            = (MMRLDR*)buf;
    rld             = (MMRLD*)rldr->data;
    rldf            = rld->mmrldf;

#if 0
    wtof("%s lowlp=%08X, highlp=%08X", __func__, lowlp, highlp);
    wtodumpf(rldr, 256, "RLDR");
#endif
    while(count < rldr->rldcnt) {
#if 0
        wtodumpf(rld, sizeof(MMRLD), "RLD");
        wtodumpf(rldf, sizeof(MMRLDF), "RLDF");
#endif
        if (rldf->flag & RLD_FLAG_UNRES) {
            /* don't process unresolved relocation entries */
            goto next;
        }

        /* get the size of the target address */
        offset = GET3(rldf->address);                   /* offset of adcon in storage */
#if 0
        wtof("%s offset=%08X", __func__, offset);
#endif
        size = rldf->flag & RLD_FLAG_LL;
        if (size == RLD_FLAG_LL2) {
            size = 2;
        }
        else if (size == RLD_FLAG_LL3) {
            size = 3;
        }
        else if (size == RLD_FLAG_LL4) {
            size = 4;
        }
        else {
            /* should never happen, but just in case */
            goto next;
        }

        /* get current relocated value from module in memory (lowlp) */
        address = lowlp + offset;                       /* address of adcon in private area (lowlp) */
        /* wtof("%s fetch(%08X,%u)", __func__, address, size); */
        value = fetch(address, size);                   /* fetch the current adcon value */
        /* wtof("%s fetch(%08X,%u) rc=%08X", __func__, address, size, value); */

        /* remove the relocation value from the adcon value (lowlp) */
        value -= lowlp;
#if 0
        wtof("%s RLD VALUE(%08X)", __func__, value);
#endif
        /* adjust the adcon value in the CSA storage (highlp) */
        value += highlp;                                /* new adcon value */
        address = highlp + offset;                      /* address of adcon in CSA */
        /* wtof("%s store(%08X,%08X,%u)", __func__, address, value, size); */
        store(address, value, size);                    /* store adcon with relocated value */

next:
        /* get next RLD entry from record */
        buf = (unsigned char*)rldf;
        if (rldf->flag & RLD_FLAG_SAME) {
            count += sizeof(MMRLDF);
            rldf = (MMRLDF*)(buf + sizeof(MMRLDF));
        }
        else {
            count += sizeof(MMRLD);
            rld = (MMRLD*)(buf + sizeof(MMRLDF));
            rldf = rld->mmrldf;
        }
    }

quit:
    return rc;
}
