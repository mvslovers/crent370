#include "modmap.h"

static int do_cesdr(MODMAP *mm, unsigned char *buf);
static int do_rldr(MODMAP *mm, unsigned char *buf);
static int do_ctl(MODMAP *mm, unsigned char *buf);
static int do_load(MODMAP *mm, unsigned char *buf);

__asm__("\n&FUNC    SETC 'modmap_process'");
int
modmap_process(MODMAP *mm)
{
    int             rc      = 0;
    size_t          read    = 0;
    unsigned char   *dptr   = NULL;
    MMOD            *mmod   = NULL;
    int             loadtext= 0;

    /* read each record from the load module */
    for(;;) {
        /* we use __aread() for record oriented i/o */
        if (__aread(mm->fp->dcb, &dptr, &read) != 0) {
            /* end of file */
            mm->fp->flags |= _FILE_FLAG_EOF;
            break;
        }

        if (loadtext) {
            loadtext = 0;
            /* record *should* be text that follows a control record */
#if 0
            wtodumpf(dptr, read, "%s", "LOADTEXT");
#endif
            do_load(mm, dptr);
            continue;
        }

#if 0
        wtodumpf(dptr, read, "%s", mm->fn);
#endif
        /* process the record we read */
        mmod = (MMOD*)dptr;
        switch(mmod->id) {
        case MMOD_ID_CTL:
            do_ctl(mm, dptr);
            loadtext = 1;
            break;
        case MMOD_ID_RLD:
            do_rldr(mm, dptr);
            break;
        case MMOD_ID_CTLRLD:
            do_ctl(mm, dptr);
            do_rldr(mm, dptr);
            loadtext = 1;
            break;
        case MMOD_ID_CTLEOS:
            do_ctl(mm, dptr);
            loadtext = 1;
            break;
        case MMOD_ID_RLDEOS:
            do_rldr(mm, dptr);
            break;
        case MMOD_ID_CTLRLDEOS:
            do_ctl(mm, dptr);
            do_rldr(mm, dptr);
            loadtext = 1;
            break;
        case MMOD_ID_CTLEOM:
            do_ctl(mm, dptr);
            loadtext = 1;
            break;
        case MMOD_ID_RLDEOM:
            do_rldr(mm, dptr);
            break;
        case MMOD_ID_CTLRLDEOM:
            do_ctl(mm, dptr);
            do_rldr(mm, dptr);
            loadtext = 1;
            break;
        case MMOD_ID_SCAT:
            break;
        case MMOD_ID_CESD:
            do_cesdr(mm, dptr);
            break;
        case MMOD_ID_SYM:
            break;
        case MMOD_ID_IDR:
            break;
        default:
            break;
        }
    }

    return rc;
}

__asm__("\n&FUNC    SETC 'do_cesdr'");
static int
do_cesdr(MODMAP *mm, unsigned char *buf)
{
    int             rc      = 0;
    MMCESDR         *cesdr  = (MMCESDR*)buf;
    unsigned        count   = 0;
    unsigned        esdid;
    int             i;
    MMESD           *esd;
    MMSD            *mmsd;
    MMLR            *mmlr;

#if 0
    wtof("Processing CESD, %u ESD entries\n", cesdr->count / sizeof(MMESD));
#endif
    esdid = (unsigned) cesdr->esdid;

    for(i=0; count < cesdr->count; i++, esdid++, count+=sizeof(MMESD)) {
        esd = &cesdr->esd[i];
#if 0
        wtof("ESDID=%04X, Type=%02X, Address=%06X, Flag=%02X, ID=%06X "
            "\"%8.8s\"\n",
            esdid, esd->type, GET3(esd->address), esd->flag, GET3(esd->id),
            esd->symbol);
#endif
        switch(esd->type & 0x7F) {
        case ESD_TYPE_SD:       /* ... Section Definition           */
        case ESD_TYPE_PC:       /* ... Private Code                 */
        case ESD_TYPE_QSD:      /* ... Quad Aligned SD              */
        case ESD_TYPE_QPC:      /* ... Quad Aligned PC              */
            mmsd = modmap_find_sd(mm, esdid);
            if (!mmsd) {
                mmsd = calloc(1, sizeof(MMSD));
                if (!mmsd) {
                    wtof("Out of memory\n");
                    rc = -1;
                    goto quit;
                }
                mmsd->esdid = esdid;
                mmsd->type  = esd->type & 0x7F;
                array_add(&mm->mmsd, mmsd);
            }
            if (mmsd->name[0] <= ' ') {
                memcpy(mmsd->name, esd->symbol, sizeof(mmsd->name));
                mmsd->address   = GET3(esd->address);
                mmsd->size      = GET3(esd->id);
            }
            if (strcmp(mmsd->name, "        ")==0) {
                memcpy(mmsd->name, "$PRIVATE", sizeof(mmsd->name));
            }
            break;
        case ESD_TYPE_LR:       /* ... Label Reference              */
        case ESD_TYPE_PR:       /* ... Pseudo Register              */
            /* wtodumpf(esd, sizeof(*esd), "%s LR/PR", __func__); */
            mmsd = modmap_find_sd(mm, (GET3(esd->id) & 0xFFFF));
            if (!mmsd) {
                mmsd = calloc(1, sizeof(MMSD));
                if (!mmsd) {
                    wtof("Out of memory\n");
                    rc = -1;
                    goto quit;
                }
                mmsd->esdid = (GET3(esd->id) & 0xFFFF);
                mmsd->type  = esd->type & 0x7F;
                array_add(&mm->mmsd, mmsd);
            }
            if ((esd->type & 0x7F) == ESD_TYPE_PR) {
                /* pseudo register */
                if (!mmsd->name[0]) {
                    /* unnamed section, so give it a name */
                    strcpy(mmsd->name, "$PSEUDO$");
                }
            }
            mmlr = calloc(1, sizeof(MMLR));
            if (!mmlr) {
                wtof("Out of memory\n");
                rc = -1;
                goto quit;
            }
            memcpy(mmlr->name, esd->symbol, sizeof(mmlr->name));
            mmlr->esdid     = esdid;
            mmlr->address   = GET3(esd->address);
            array_add(&mmsd->mmlr, mmlr);
            break;
        case ESD_TYPE_ER:       /* ... External Reference           */
        case ESD_TYPE_WX:       /* ... Weak External Reference      */
            mmlr = calloc(1, sizeof(MMLR));
            if (!mmlr) {
                wtof("Out of memory\n");
                rc = -1;
                goto quit;
            }
            memcpy(mmlr->name, esd->symbol, sizeof(mmlr->name));
            mmlr->esdid     = esdid;
            mmlr->address   = GET3(esd->address);
            mmlr->type      = esd->type & 0x7F;
            array_add(&mmsd->mmlr, mmlr);
            break;

        case ESD_TYPE_CM:       /* ... Common                       */
        case ESD_TYPE_NULL:     /* ... NULL                         */
        case ESD_TYPE_QCM:      /* ... Quad Aligned CM              */
        case ESD_TYPE_DPC:      /* ... Deleted PC                   */
#if 0
        wtof("ESDID=%04X, Type=%02X, Address=%06X, Flag=%02X, ID=%06X "
            "\"%8.8s\"\n",
            esdid, esd->type, GET3(esd->address), esd->flag, GET3(esd->id),
            esd->symbol);
#endif
            break;
        }
    }

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'do_rldr'");
static int
do_rldr(MODMAP *mm, unsigned char *buf)
{
    int             rc      = 0;
    unsigned        count   = 0;
    MMRLDR          *rldr;
    MMRLD           *rld;
    MMRLDF          *rldf;
    MMSD            *mmsd;
    MMLR            *mmlr;
    MMRL            *mmrl;
    unsigned        size;
    unsigned        offset;
    unsigned char   *p;

    /* map the buffer contents */
    rldr            = (MMRLDR*)buf;
    rld             = (MMRLD*)rldr->data;
    rldf            = rld->mmrldf;

#if 0
    wtof("Processing RLDR, %u RLD entries, %u bytes\n",
        rldr->count, rldr->bytes);
#endif

    while(count < rldr->rldcnt) {
#if 0
        /* we're not interested in RLD's for the same ESD */
        if (rld->posid == rld->relid) goto next;
#endif
        /* get the size of the target address */
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
            size = 0;
        }

        /* this RLD will be an external (rld->posid != rld->relid)
        **     or an internal reference (rld->posid == rld->relid)
        */
        mmsd = modmap_find_sd(mm, rld->posid);
        if (mmsd) {
            /* add relocation record to this section */
            mmrl = calloc(1, sizeof(MMRL));
            if (mmrl) {
                /* relocation ESDID */
                mmrl->esdid = rld->relid;
                mmrl->address = GET3(rldf->address);
                mmrl->size  = size;
                mmrl->unres = rldf->flag & RLD_FLAG_UNRES;
                mmrl->type  = rldf->flag & RLD_FLAG_TYPE;
                mmrl->neg   = rldf->flag & RLD_FLAG_NEG;
                if (mmsd->text /*&& rld->posid == rld->relid*/) {
                    offset = mmrl->address - mmsd->address;
#if 0
                    wtof("%s mmrl->address(%08X), mmsd->address(%08X), offset(%08X)",
                         __func__, mmrl->address, mmsd->address, offset);
#endif
                    p = mmsd->text + offset;
                    switch (size) {
                    case 2: mmrl->value = *(unsigned short*)p; break;
                    case 3: mmrl->value = GET3(p); break;
                    case 4: mmrl->value = *(unsigned *)p; break;
                    }
                }
#if 0
                wtodumpf(mmsd, sizeof(MMSD), "%s MMSD", __func__);
                wtodumpf(mmrl, sizeof(MMRL), "%s MMRL", __func__);
#endif
                array_add(&mmsd->mmrl, mmrl);
            }
        }
#if 0
        wtof("address=%06X, type=%02X, relid=%u, posid=%u",
            GET3(rldf->address), rldf->flag, rld->relid, rld->posid);
#endif
next:
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

__asm__("\n&FUNC    SETC 'do_ctl'");
static int
do_ctl(MODMAP *mm, unsigned char *buf)
{
    int             rc      = 0;
    unsigned        count   = 0;
    MMCTL           *ctl;
    MMCTLD          *ctld;
    MMSD            *mmsd;
    MMLD            *mmld;

    /* reset the load information */
    modmap_reset_ld(mm);

    /* map the buffer contents */
    ctl             = (MMCTL*)buf;
    ctld            = (MMCTLD*)(ctl->data + ctl->rldcnt);

#if 0
    wtodumpf(ctld, ctl->ctlcnt, "CTLD");
#endif

    while(count < ctl->ctlcnt) {
        /* wtof("%s ESDID(%u) SIZE(%u)", __func__, ctld->esdid, ctld->count); */
        mmsd = modmap_find_sd(mm, ctld->esdid);
        if (mmsd) {
            if (mmsd->text) free(mmsd->text);
            mmsd->text = calloc(1, ctld->count);
        }
        /* remember the esdid and size for the do_load() and do_rld() processing */
        mmld = calloc(1, sizeof(MMLD));
        if (mmld) {
            array_add(&mm->mmld, mmld);
            mmld->esdid = ctld->esdid;
            mmld->size  = ctld->count;
        }
        ctld++;
        count += sizeof(MMCTLD);
    }

    return 0;
}


__asm__("\n&FUNC    SETC 'do_load'");
static int
do_load(MODMAP *mm, unsigned char *buf)
{
    int             rc      = 0;
    unsigned        count   = 0;
    MMSD            *mmsd;
    MMLD            *mmld;
    unsigned        n;

    count = array_count(&mm->mmld);
    for(n=0; n < count; n++) {
        mmld = mm->mmld[n];
        if (!mmld) continue;

        mmsd = modmap_find_sd(mm, mmld->esdid);
        if (mmsd && mmsd->text) {
            memcpy(mmsd->text, buf, mmld->size);
            /* wtodumpf(mmsd->text, mmld->size, "%s ESDID(%u)", __func__, mmsd->esdid); */
        }
        buf += mmld->size;
    }

    return 0;
}
