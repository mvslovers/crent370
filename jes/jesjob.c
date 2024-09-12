/* JESJOB.C - Get JES Job information */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasphct.h"    /* JES Checkpoint Control Table, record 3 in HASPCKPT */
#include "haspjct.h"    /* JES Job Control Table                            */
#include "hasppddb.h"   /* JES PDDB Print Datasets                          */
#include "haspiot.h"    /* JES IOT                                          */
#include "ieftxtft.h"   /* text string types                                */
#include "iefvkeys.h"   /* text key values                                  */
#include "clibjes2.h"   /* JES prototypes */
#include "clibary.h"    /* dynamic array                                    */

static int process_intxt(JES *jes, __JQE *jqe, __JCT *jct, unsigned pddb_mttr, JESJOB *job);
static int process_job(char *buf, char *jobname, char *userid);
static JESDD *process_pddb(__PDDB *pddb, JESJOB *job);
static int process_exec(char *buf, char *stepname, char *procname, char *program);
static int process_dd(char *buf, char *ddname, char *dsname, char *sysout, unsigned *sysin);
static int process_sysout(JESDD **jesdd, const char *ddname, const char *dsname, const char *sysout, const char *stepname, const char *procstep);
static int process_sysin(JESDD **jesdd, const char *ddname, const char *dsname, const char *stepname, const char *procstep);
static int is_dup_dsid(JESDD **jesdd, unsigned dsid);
static time64_t make_time(unsigned int t_hundreths_seconds_since_midnight, unsigned int d_packed_yyyydddf);

static int dsid_comp(const void *, const void *);

JESJOB **jesjob(JES *jes, const char *filter, JESFILT type, int dd)
{
    JESJOB      **array = NULL;
    JESJOB      *job    = NULL;
    JESDD       *jesdd  = NULL;
    HASPCP      *cp     = NULL;
    HASPJS      *js     = NULL;
    __HCT       *hct    = NULL;
    __JCT       *jct    = NULL;
    __PDDB      *pddb   = NULL;
    __PDDB      *pddbend= NULL;
    __JQE       *jqe    = NULL;
    __IOT       *iot    = NULL;
    char        *buf    = NULL;
    char        *jctbuf = NULL;
    char        *iotbuf = NULL;
    char        *jobtype;
    unsigned    mttr;
    int         i;
    int         rc;
    char        filt[12];
    char        jobid[12];
    char        jobname[12];
    char        owner[12];

    if (!jes) goto quit;

    /* if the caller supplied a filter we want to make an UPPERCASE copy */
    if (type != FILTER_NONE && filter) {
        for(i=0; filter[i] && i < sizeof(filt); i++) {
            filt[i] = toupper(filter[i]);
        }
        filt[i] = 0;
    }

    cp = jes->cp;
    hct = &cp->hct;
    /* wtodumpf(hct, sizeof(__HCT), "HCT"); */

    js = jes->js[0];

    buf = calloc(1, hct->_BUFSIZE * 2);
    if (!buf) {
        wtof("Unable to allocate storage for %u byte buffer", hct->_BUFSIZE * 2);
        goto quit;
    }
    jctbuf = buf;
    jct    = (__JCT*)jctbuf;
    iotbuf = jctbuf + hct->_BUFSIZE;
    iot    = (__IOT*)iotbuf;
    pddbend= (__PDDB*)&iotbuf[hct->_BUFSIZE];

    for(jqe=cp->jqe; jqe < cp->jqeend; jqe++) {
        if (jqe->JQETYPE == _FREE) continue;    /* Skip this JQE    */
        if (jqe->JQETYPE == _PURGE) continue;   /* Skip this JQE    */

        /* read this jobs JCT record */
        if (spool_read(js, jqe->JQETRAK, jctbuf, hct->_BUFSIZE)) continue;
        jct = (__JCT*)jctbuf;

        /* wtodumpf(jct, sizeof(__JCT), "JCT mttr=%08X", jqe->JQETRAK); */

        if (jct->JCTJOBFL & JCTBATCH) {
            jobtype = "JOB";    /* Batch job */
        }
        else if (jct->JCTJOBFL & JCTTSUJB) {
            jobtype = "TSU";    /* TSU User */
        }
        else if (jct->JCTJOBFL & JCTSTCJB) {
            jobtype = "STC";    /* System Task */
        }
        else {
            jobtype = "???";    /* No idea we we have here */
        }

        sprintf(jobid, "%s%05u", jobtype, jqe->JQEJOBNO % 10000);
        memcpyp(jobname, sizeof(jobname), jqe->JQEJNAME, sizeof(jqe->JQEJNAME), 0);
        strtok(jobname, " ");

        if (jct->JCTJOBFL & JCTTSUJB) {
            /* TSO User is owner of itself */
            strcpy(owner, jobname);
        }
        else if (jct->JCTJOBFL & JCTSTCJB) {
            /* STC are owned by the system */
            strcpy(owner, "SYSTEM");
        }
        else {
            /* Batch jobs are owned by the job submitter or USERID= from job card.
               note: we don't have the userid from the job card at this point, however
                     we'll see it when we process the INTERNAL TEXT (DSID#5) below
                     and update the job->owner at that time. */
            memcpyp(owner, sizeof(owner), jct->JCTUSEID, sizeof(jct->JCTUSEID), 0);
            if (owner[0] > ' ') strtok(owner, " "); else owner[0] = 0;
        }
        /* wtodumpf(owner, sizeof(owner), "owner"); */

        if (type != FILTER_NONE && filter) {
            /* Filter as needed */
            if (type == FILTER_JOBNAME) {
                if (!__patmat(jobname, filt)) continue;
            }
            else if (type == FILTER_JOBID) {
                if (!__patmat(jobid, filt)) continue;
            }
        }

        job = calloc(1, sizeof(JESJOB));
        if (!job) {
            wtof("Unable to allocate storage for %u byte JESJOB handle", sizeof(JESJOB));
            goto quit;
        }

        /* add this JESJOB to the array of JESJOBs */
        arrayadd(&array, job);
        strcpy(job->eye, JESJOB_EYE);

        /* Fill in the job info from the JQE and JCT records */
        strcpyp(job->jobname, sizeof(job->jobname), jobname, 0);
        strcpyp(job->jobid,   sizeof(job->jobid),   jobid,   0);
        strcpyp(job->owner,   sizeof(job->owner),   owner,   0);

        job->eclass     = jct->JCTCLASS;
        job->priority   = jct->JCTPRIO;
        job->q_type     = jqe->JQETYPE;
        job->q_flag1    = jqe->JQEFLAGS;
        job->q_flag2    = jqe->JQEFLAG2;
        job->iotmttr    = jct->JCTIOT;
        job->spinmttr   = jct->JCTSPIOT;
        job->start_time64 = make_time(jct->JCTXEQON, jct->JCTXDTON);
        job->end_time64   = make_time(jct->JCTXEQOF, jct->JCTXDTOF);
        job->jobkey     = jct->JCTJBKEY;

        if (dd) {
            /* Process the IOT */
            /* wtof("%s process the IOT", __func__); */
            for(mttr = jct->JCTIOT; mttr; mttr=iot->IOTIOTTR) {
                /* read this jobs IOT (and PDDBs) record */
                spool_read(js, mttr, iotbuf, hct->_BUFSIZE);

                for(i=0, pddb = (__PDDB*)&iotbuf[cp->pddb1]; pddb < pddbend; i++, pddb++) {
                    /* wtodumpf(pddb, sizeof(__PDDB), "PDDB#%d", i); */

                    if (pddb->PDBDSKEY == 0) break;
                    if (pddb->PDBMTTR == 0) continue;
                    if (is_dup_dsid(job->jesdd, pddb->PDBDSKEY)) continue;

                    /* populate jesdd from the pddb record */
                    if (!(jesdd=process_pddb(pddb, job))) goto quit;
                }
            }

            /* Process the SPIN IOT */
            /* wtof("%s process the SPIN IOT", __func__); */
            for(mttr = jct->JCTSPIOT; mttr; mttr=iot->IOTIOTTR) {
                /* read this jobs IOT (and PDDBs) record */
                /* wtof("%s spool_read() MTTR=%08X", __func__, mttr); */
                spool_read(js, mttr, iotbuf, hct->_BUFSIZE);
                /* wtodumpf(iotbuf, sizeof(__IOT), "IOT %08X", mttr); */

                for(i=0, pddb = (__PDDB*)&iotbuf[cp->pddb1]; pddb < pddbend; i++, pddb++) {
                    /* wtodumpf(pddb, sizeof(__PDDB), "PDDB#%d", i); */

                    if (pddb->PDBDSKEY == 0) break;
                    if (pddb->PDBMTTR == 0) continue;
                    if (is_dup_dsid(job->jesdd, pddb->PDBDSKEY)) continue;

                    /* populate jesdd from the pddb record */
                    if (!(jesdd=process_pddb(pddb, job))) goto quit;
                }
            }
        }   /* if (dd) */

        /* process the JCL for this job if we want DD info OR if this is a
           batch job (so we can get the USERID= as the job owner). */
        /* wtof("%s process the JCL", __func__); */
        if (dd || (jct->JCTJOBFL & JCTBATCH)) {
            /* Find the DSID #5 PDDB for this job */
            for(rc=0, mttr = jct->JCTIOT; mttr; mttr=iot->IOTIOTTR) {
                /* read this jobs IOT (and PDDBs) record */
                /* wtof("%s spool_read() MTTR=%08X", __func__, mttr); */
                spool_read(js, mttr, iotbuf, hct->_BUFSIZE);
                /* wtodumpf(iotbuf, sizeof(__IOT), "IOT %08X", mttr); */

                for(mttr=0, i=0, pddb = (__PDDB*)&iotbuf[cp->pddb1]; pddb < pddbend; i++, pddb++) {
#if 0
                    wtodumpf(pddb, sizeof(__PDDB), "PDDB#%d", i);
                    wtof("%s PDBDSKEY=%08X", __func__, pddb->PDBDSKEY);
                    wtof("%s PDBMTTR =%08X", __func__, pddb->PDBMTTR);
#endif
                    if (pddb->PDBDSKEY != PDBINTXT) continue;

                    rc = process_intxt(jes, jqe, jct, pddb->PDBMTTR, job);
                    break;
                }
                if (rc) break;
            }
        }

        if (job->jesdd) {
            /* check for missing ddname and remove them from results */
            unsigned count = arraycount(&job->jesdd);
            unsigned n;

            for(n=0; n < count; n++) {
                JESDD *dd = job->jesdd[n];

                if (!dd) continue;
                if (dd->ddname[0]==0 || dd->ddname[0]==' ') {
                    arraydel(&job->jesdd, n+1);
                    free(dd);
                    count--;
                }
            }

            count = arraycount(&job->jesdd);
            if (count > 1) {
                qsort(job->jesdd, count, sizeof(JESDD*), dsid_comp);
            }

        }
#if 0
        {
            unsigned count = arraycount(&job->jesdd);
            unsigned n;

            wtof("%-8.8s %-8.8s %-8.8s CLASS=%c PRTY=%u IOTMTTR=%08X SPINMTTR=%08X",
                job->jobname, job->jobid, job->owner, job->eclass, job->priority, job->iotmttr, job->spinmttr);
            wtof("start=%u %s", job->start_time, ctime(&job->start_time));
            wtof("end=%u %s", job->end_time, ctime(&job->end_time));

            for(n=0; n < count; n++) {
                JESDD *dd = job->jesdd[n];

                if (!dd) continue;
                wtof("dd=%s, step=%s, proc=%s, class=%c, recfm=%02X, mttr=%08X, recs=%u, lrecl=%u, dsid=%u",
                     dd->ddname, dd->stepname, dd->procstep, dd->oclass, dd->recfm, dd->mttr, dd->records, dd->lrecl, dd->dsid);
                wtof("dsname=%-44.44s, flag=%02X", dd->dsname, dd->flag);
            }
        }
#endif
    }

quit:
    if (buf) free(buf);
    return array;
}

__asm__("\n&FUNC    SETC 'dsid_comp'");
static int
dsid_comp(const void *v1, const void *v2)
{
    JESDD   *dd1    = *(JESDD **)v1;
    JESDD   *dd2    = *(JESDD **)v2;

    /* wtof("%s dd1->ddname=%s, dd2->ddname=%s", __func__, dd1->ddname, dd2->ddname); */

    return (int) (dd1->dsid - dd2->dsid);
}

__asm__("\n&FUNC    SETC 'process_pddb'");
static JESDD *
process_pddb(__PDDB *pddb, JESJOB *job)
{
    JESDD *jesdd = calloc(1, sizeof(JESDD));

    if (!jesdd) {
        wtof("Unable to allocate storage for %u byte JESDD handle", sizeof(JESDD));
        goto quit;
    }

    /* add the jesdd to the array of jesdd in the job handle */
    arrayadd(&job->jesdd, jesdd);

    /* initialize the jesdd handle */
    strcpy(jesdd->eye, JESDD_EYE);

    memcpyp(jesdd->ddname, sizeof(jesdd->ddname), pddb->PDBDSID, sizeof(pddb->PDBDSID), 0);
    strtok(jesdd->ddname, " ");

    switch (pddb->PDBDSKEY) {
        case PDBINJCL:  {
            strcpy(jesdd->ddname, "JESJCLIN");
            sprintf(jesdd->dsname, "JES2.%s.SI%04u", job->jobid, pddb->PDBDSKEY);
            jesdd->flag = FLAG_JES2 | FLAG_SYSIN;
            break;
        }
        case PDBOUHJL:  {
            strcpy(jesdd->ddname, "JESMSGLG");
            sprintf(jesdd->dsname, "JES2.%s.SO%04u", job->jobid, pddb->PDBDSKEY);
            jesdd->flag = FLAG_JES2 | FLAG_SYSOUT;
            break;
        }
        case PDBOUJCI:  {
            strcpy(jesdd->ddname, "JESJCL");
            sprintf(jesdd->dsname, "JES2.%s.SO%04u", job->jobid, pddb->PDBDSKEY);
            jesdd->flag = FLAG_JES2 | FLAG_SYSOUT;
            break;
        }
        case PDBOUMSG:  {
            strcpy(jesdd->ddname, "JESYSMSG");
            sprintf(jesdd->dsname, "JES2.%s.SO%04u", job->jobid, pddb->PDBDSKEY);
            jesdd->flag = FLAG_JES2 | FLAG_SYSOUT;
            break;
        }
        case PDBINTXT:  {
            strcpy(jesdd->ddname, "JESINTXT");
            sprintf(jesdd->dsname, "JES2.%s.SI%04u", job->jobid, pddb->PDBDSKEY);
            jesdd->flag = FLAG_JES2 | FLAG_SYSIN;
            break;
        }
        case PDBINJNL:  {
            strcpy(jesdd->ddname, "JESJRNL");
            sprintf(jesdd->dsname, "JES2.%s.SI%04u", job->jobid, pddb->PDBDSKEY);
            jesdd->flag = FLAG_JES2 | FLAG_SYSIN;
            break;
        }
    }
#if 0
    if (jesdd->ddname[0]==0 || jesdd->ddname[0]==' ') {
        sprintf(jesdd->ddname, "JES%05u", pddb->PDBDSKEY);
        sprintf(jesdd->dsname, "JES2.%s.SI%04u", job->jobid, pddb->PDBDSKEY);
    }
#endif
    jesdd->oclass   = pddb->PDBCLASS;
    jesdd->recfm    = pddb->PDBRECFM;
    jesdd->mttr     = pddb->PDBMTTR;
    jesdd->records  = pddb->PDBRECCT;
    jesdd->lrecl    = pddb->PDBLRECL;
    jesdd->dsid     = pddb->PDBDSKEY;

quit:
    return jesdd;
}

__asm__("\n&FUNC    SETC 'make_time'");
static time64_t
make_time(unsigned int t, unsigned int d)
{
    time64_t    result;
    unsigned    year    = 0;
    unsigned    days    = 0;
    struct tm   tm      = {0};
    char        buf[20];

	__64_init(&result);	/* initialize to 0 */

    if (!t) goto quit;  /* t is hundredths seconds since midnight */
    if (!d) goto quit;  /* d is packed date YYYYDDDF julian day   */

	/* fprintf(stderr, "make_time(%08X, %08X)\n", t, d); */

    tm.tm_sec   = (t/100);  /* convert to seconds */

    /* unpack the year from the YYYYDDDF packed date */
    year        = (d >> 16);
    sprintf(buf, "%X", year);
    year        = atoi(buf);
    tm.tm_year  = year;

    /* unpack the year days from the YYYYDDDF packed date */
    days        = (d & 0xFFFF) >> 4;
    sprintf(buf, "%X", days);
    days        = atoi(buf);
    tm.tm_mday  = days;

	/* we don't know if DST is in effect */
	tm.tm_isdst = -1;

    /* convert to time64_t format date and time */
    result = mktime64(&tm);
	/* fprintf(stderr, "mktime64 result=%llu, 0x%016llX\n", result, result); */

	/* if mktime64() failed, return 0 */
    if (result.u32[0] == 0xFFFFFFFF && result.u32[1] == 0xFFFFFFFF) __64_init(&result);

quit:
	/* fprintf(stderr, "make_time result=%llu, 0x%016llX\n \n", result, result); */
    return result;
}

/* process_intxt() read internal text for job and merge with job->jesdd array */
__asm__("\n&FUNC    SETC 'process_intxt'");
static int
process_intxt(JES *jes, __JQE *jqe, __JCT *jct, unsigned pddb_mttr, JESJOB *job)
{
    HASPCP          *cp     = jes->cp;
    HASPJS          *js     = jes->js[0];
    __HCT           *hct    = &cp->hct;
    char            *buf    = NULL;
    __TXTPRE        *pre    = NULL;
    JESDD           **jesdd = job->jesdd;
    unsigned        count   = arraycount(&jesdd);
    unsigned        n;
    unsigned        mttr;
    unsigned char   *p;
    unsigned char   *eob;   /* end of block */
    struct hdr {
        unsigned int    next;
        unsigned int    jobid;
        unsigned short  dsid;
        unsigned char   len1;       /* 1 byte length */
        unsigned char   len2[2];    /* 2 byte length */
        unsigned char   record[0];  /* start of text string records */
    }           *hdr;
    unsigned char   jobname[12] = "";
    unsigned char   userid[12] = "";
    unsigned char   stepname[12] = "";
    unsigned char   procstep[12] = "";
    unsigned char   program[12] = "";
    unsigned char   ddname[12] = "";
    unsigned char   dsname[56] = "";
    unsigned char   sysout[8] = "";
    unsigned        sysin;

    /* wtof("%s enter", __func__); */

    buf = calloc(1, hct->_BUFSIZE);
    if (!buf) goto quit;

    for(mttr=pddb_mttr; mttr; mttr=hdr->next) {
        /* read the internal text record */
        /* wtof("%s spool_read() MTTR=%08X", __func__, mttr); */
        spool_read(js, mttr, buf, hct->_BUFSIZE);
        /* wtodumpf(buf, hct->_BUFSIZE, "text record for mttr=%08X", mttr); */

        hdr = (struct hdr*)buf;
        if (hdr->jobid != jct->JCTJBKEY) break;
        if (hdr->dsid != PDBINTXT) break;

        p = hdr->record;
        eob = buf + hct->_BUFSIZE - 1;

        while( p < eob ) {
            pre = (__TXTPRE*)p;
            if (pre->STRLTH==0) break;

            switch(pre->STRINDCS & 0x0F) {
            case JOBSTR:        /* ... JOB STATEMENT TEXT STRING            */
                /* wtodumpf(pre, pre->STRLTH, "JOB Text String"); */
                process_job(p, jobname, userid);
                if (userid[0]) strcpy(job->owner, userid);
                if (!count) goto quit;  /* no JESDD so we're done */
                break;
            case EXECSTR:       /* ... EXEC STATEMENT TEXT STRING           */
                /* wtodumpf(pre, pre->STRLTH, "EXEC Text String"); */
                process_exec(p, stepname, procstep, program);
                break;
            case DDSTR:         /* ... DD STATEMENT TEXT STRING             */
                /* wtodumpf(pre, pre->STRLTH, "DD Text String"); */
                process_dd(p, ddname, dsname, sysout, &sysin);
                /* wtof("ddname=%s, dsname=%s, sysout=%s, sysin=%u", ddname, dsname, sysout, sysin); */
                if (sysout[0]) {
                    /* DD is for SYSOUT */
                    process_sysout(job->jesdd, ddname, dsname, sysout, stepname, procstep);
                }
                if (sysin) {
                    /* DD is for SYSOUT */
                    process_sysin(job->jesdd, ddname, dsname, stepname, procstep);
                }
                break;
            case PROCSTR:       /* ... PROC STATEMENT TEXT STRING           */
                /* wtodumpf(pre, pre->STRLTH, "PROC Text String"); */
                process_exec(p, procstep, program, program);
                break;
            }

            p += pre->STRLTH + 3;
        }
    }

quit:
    if (buf) free(buf);
    /* wtof("%s exit count=%u", __func__, count); */
    return (int)count;
}

typedef struct {
    unsigned char   key;
    unsigned char   count;
    unsigned char   len;
    unsigned char   data[0];
} TEXT;

__asm__("\n&FUNC    SETC 'process_job'");
static int
process_job(char *buf, char *jobname, char *userid)
{
    __JOBSTR    *job    = (__JOBSTR*)buf;
    TEXT        *t;
    unsigned    n;
    unsigned    len;

    buf         = job->STRJKEY;
    jobname[0]  = 0;
    userid[0]   = 0;

    for(t = (TEXT*)buf; t->key != 0 && t->key != ENDK; t = (TEXT*)buf) {
        len = t->len & 0x7F;

        switch (t->key) {
        case USERK:     /* JOB     USER=                        */
            memcpy(userid, t->data, len);
            userid[len] = 0;
            strtok(userid, " ");
            break;
        case JOBK:      /* JOB     JOB                          */
            memcpy(jobname, t->data, len);
            jobname[len] = 0;
            strtok(jobname, " ");
            break;
        }

        /* move buf pointer to next key */
        for(buf+=2, n=0; n < t->count; n++) buf += (1 + (buf[0] & 0x7F));
    }

    /* wtof("process_job(%s,%s)", jobname, userid); */
    return 0;
}

__asm__("\n&FUNC    SETC 'process_exec'");
static int
process_exec(char *buf, char *stepname, char *procname, char *program)
{
    __EXECSTR   *exec   = (__EXECSTR*)buf;
    TEXT        *t;
    unsigned    n;
    unsigned    len;

    buf         = exec->STREKEY;
    stepname[0]  = 0;

    for(t = (TEXT*)buf; t->key != 0 && t->key != ENDK; t = (TEXT*)buf) {
        /* wtodumpf(t, sizeof(TEXT), "%s TEXT", __func__); */

        len = t->len & 0x7F;

        /* wtof("%s t->key=%u", __func__, t->key); */
        switch (t->key) {
        case PGMEK:     /* EXEC    PGM=                         */
            /* wtof("%s PGMEK t->data=%08X, t->len=%08X", __func__, t->data, t->len); */
            memcpy(program, t->data, len);
            program[len] = 0;
            strtok(program, " ");
            break;
        case PROCEK:    /* EXEC    PROC=                        */
            /* wtof("%s PROCEK t->data=%08X, t->len=%08X", __func__, t->data, t->len); */
            program[0] = 0;
            memcpy(procname, t->data, len);
            procname[len] = 0;
            strtok(procname, " ");
            break;
        case EXECK:     /* EXEC    EXEC                         */
            /* wtof("%s EXECK t->data=%08X, t->len=%08X", __func__, t->data, t->len); */
            memcpy(stepname, t->data, len);
            stepname[len] = 0;
            strtok(stepname, " ");
            break;
        }

        /* move buf pointer to next key */
        for(buf+=2, n=0; n < t->count; n++) buf += (1 + (buf[0] & 0x7F));
    }

    /* wtof("process_exec(%s,%s,%s)", stepname, procname, program); */
    return 0;
}

__asm__("\n&FUNC    SETC 'process_dd'");
static int
process_dd(char *buf, char *ddname, char *dsname, char *sysout, unsigned *sysin)
{
    __DDSTR     *dd     = (__DDSTR*)buf;
    TEXT        *t;
    unsigned    n;

	// wtof("%s: enter buf=%p", __func__, buf);

    buf         = dd->STRDKEY;
    dsname[0]   = 0;
    sysout[0]   = 0;
    *sysin      = 0;

    for(t = (TEXT*)buf; t->key != 0 && t->key != ENDK; t = (TEXT*)buf) {
#if 0
        char *p = buf;
        for(p+=2, n=0; n < t->count; n++) p += (1 + p[0]);
        wtodumpf(buf, n, "%s: t->key=%d", __func__, t->key);
#endif
        switch (t->key) {
        case DDK:       /* DD      DD                           */
            memcpy(ddname, t->data, t->len);
            ddname[t->len] = 0;
            strtok(ddname, " ");
            // wtodumpf(ddname, t->len, "DDK");
            break;
        case DSNAMEK:   /* DD C    DSNAME=                      */
            if (t->len & 0x80) {
                buf++;
                t = (TEXT*)buf;
            }
            memcpy(dsname, t->data, t->len);
            dsname[t->len] = 0;
            strtok(dsname, " ");
            break;
        case SYSOUTK:   /* DD      SYSOUT=                      */
            memcpy(sysout, t->data, t->len);
            sysout[t->len] = 0;
            strtok(sysout, " ");
            break;
        case SYSINCTK:  /* DD      SYSIN number of records      */
#if 1
            *sysin = 1;
#else
             memcpy(sysin, t->data, t->len);
#endif
            break;
		case SPACEK: 	/* SPACE 4702 03E3D9D2 83 01F1 01F1 01F1 :...TRKc.1.1.1...: */
			// wtodumpf(buf, 16, "SPACEK");
			buf += 3 + t->len;
			continue;
		case 0x83:	/* SPACE lvlvlv */
			// wtodumpf(buf, 16, "0x83");
			buf += 7;
			continue;
        }

        /* move buf pointer to next key */
        for(buf+=2, n=0; n < t->count; n++) buf += (1 + buf[0]);
    }

    // wtof("process_dd(%s,%s,%s)", ddname, dsname, sysout);
	// wtof("%s: exit", __func__);
    return 0;
}

__asm__("\n&FUNC    SETC 'process_sysout'");
static int
process_sysout(JESDD **jesdd, const char *ddname, const char *dsname, const char *sysout, const char *stepname, const char *procstep)
{
    unsigned        count   = arraycount(&jesdd);
    unsigned        n;
    const char      *p;
    unsigned short  dsid;

    p = strrchr(dsname, '.');
    if (!p) goto quit;

    if (p[1] != 'S') goto quit;
    if (p[2] != 'O') goto quit;

    dsid = (unsigned short) atoi(&p[3]);
    if (!dsid) goto quit;
#if 1
    if (ddname[0]==0 || ddname[0]==' ') {
        wtodumpf(ddname, 8, "process_sysout() null ddname for dsid=%d", dsid);
    }
#endif
    for(n=0; n < count; n++) {
        JESDD *dd = jesdd[n];

        if (!dd) continue;
        if (dd->dsid == dsid) {
            strcpy(dd->ddname, ddname);
            strcpy(dd->stepname, stepname);
            strcpy(dd->procstep, procstep);
            strcpy(dd->dsname, dsname);
            if (!dd->oclass) dd->oclass = sysout[0];
            dd->flag = FLAG_SYSOUT;
            break;
        }
    }

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'process_sysin'");
static int
process_sysin(JESDD **jesdd, const char *ddname, const char *dsname, const char *stepname, const char *procstep)
{
    unsigned        count   = arraycount(&jesdd);
    unsigned        n;
    const char      *p;
    unsigned short  dsid;

    p = strrchr(dsname, '.');
    if (!p) goto quit;

    if (p[1] != 'S') goto quit;
    if (p[2] != 'I') goto quit;

    dsid = (unsigned short) atoi(&p[3]);
    if (!dsid) goto quit;

#if 1
    if (ddname[0]==0 || ddname[0]==' ') {
        wtodumpf(ddname, 8, "process_sysin() null ddname for dsid=%d", dsid);
    }
#endif
    for(n=0; n < count; n++) {
        JESDD *dd = jesdd[n];

        if (!dd) continue;
        if (dd->dsid == dsid) {
            strcpy(dd->ddname, ddname);
            strcpy(dd->stepname, stepname);
            strcpy(dd->procstep, procstep);
            strcpy(dd->dsname, dsname);
            dd->flag = FLAG_SYSIN;
            break;
        }
    }

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'is_dup_dsid'");
static int
is_dup_dsid(JESDD **jesdd, unsigned dsid)
{
    unsigned count = arraycount(&jesdd);
    unsigned n;

    for(n=0; n < count; n++) {
        JESDD *dd = jesdd[n];

        if (!dd) continue;
        if (dd->dsid == dsid) return 1;
    }

    return 0;
}
