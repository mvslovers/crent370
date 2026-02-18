/* @@LISTC.C */
#include <stdio.h>
#include <ctype.h>
#include <mvssupa.h>
#include "cliblist.h"
#include "cliblock.h"

int
__listc(const char *level, const char *option,
        int (*prt)(void *udata, const char *fmt, ...),
        void *udata)
{
    unsigned    *psa    	= (unsigned *)0;
    void        *ascb   	= (void *)psa[0x224/4];
    int     	ret         = -1;
    FILE    	*fp         = 0;
    char    	*p          = 0;
    char    	ddname[12]  = {0};
    char    	dataset[45] = {0};
    char    	buf[256]    = {0};

    /* allocate a temp dataset */
    tmpnam(dataset);
    fp = fopen(dataset, "wb,recfm=vb,lrecl=133,blksize=32760");
    if (!fp) {
        wtof("Unable to allocate tmpfile");
        goto quit;
    }

    /* turn off the dynamic allocation flag */
    fp->flags &= 0xFFFF - _FILE_FLAG_DYNAMIC;

    /* save the DD and dataset names */
    strcpy(ddname, fp->ddname);
    strcpy(dataset, fp->dataset);

    /* close the temp file, the dd for the temp dataset remains allocated */
    fclose(fp);
    fp = 0;

    /* envoke IDCAMS LISTC LEVEL with output sent to the temp dataset */
    if (!option) option = "";

    lock(ascb,LOCK_EXC);
    ret = idcams(" LISTC LEVEL('%s') OUTFILE(%s) %s", level, ddname, option);
    unlock(ascb,LOCK_EXC);

    /* reopen the temp dataset by the saved DD name */
    sprintf(buf, "DD:%s", ddname);
    fp = fopen(buf, "r,record");
    if (!fp) {
        ret = -1;
        wtof("unable to reopen temp file");
        remove(dataset);
        goto quit;
    }
#if 0
    wtof("fp->flags %04X", fp->flags);
    wtof("fp->mode  %s", fp->mode);
#endif

    /* read record from the temp dataset and call the callers prt function */
    do {
#if 0
        p = fgets(buf, sizeof(buf), fp);
        if (p) {
            prt(udata, "%s", p);
        }
#else
        /* we're using fread() for the temp file which we opened with
        ** mode="r,record" to bypass the "stream" oriented access for
        ** reading data.  the theory is this *should* be a little
        ** faster, however we have to deal with any RDW in this case.
        */
        p = 0;
        memset(buf, 0, sizeof(buf));
        ret = fread(buf, 1, sizeof(buf)-1, fp);
        if (ret > 0) {
            /* wtodumpf(buf, ret, "%s", __func__); */
            p = buf;
            if ((fp->recfm & _FILE_RECFM_TYPE)==_FILE_RECFM_V) {
                /* RECFM=V has RDW when open in record mode
                ** so we need to get the real length and skip the RDW
                */
                ret = *(unsigned short*)p;
                p += 4;
            }
            /* do sanity check and truncate if needed */
            if (ret >= sizeof(buf)) ret = sizeof(buf)-1;
            buf[ret] = 0;

            /* give record (string) to supplied callback function */
            prt(udata, "%s", p);
        }
#endif
    } while(p);

    /* restore the DYNAMIC flag in the temp dataset file handle */
    fp->flags |= _FILE_FLAG_DYNAMIC;

    /* now close the temp dataset and deallocate the DD, deletes the dataset */
    fclose(fp);
    ret = 0;

quit:
    return (ret);
}
