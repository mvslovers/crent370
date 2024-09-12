/* @@TXTRTC.C */
#include "svc99.h"
#include "clibary.h"

static struct {
    const char      trtch[7];
    unsigned char   type;
} table[] = {
    {"C",       0x13},
    {"COMP",    0x08},
    {"E",       0x23},
    {"ET",      0x2B},
    {"NOCOMP",  0x04},
    {"T",       0x3B},
    {"",        0}
};

int
__txtrtc(TXT99 ***txt99, const char *trtch)
{
    int     err     = 1;
    int     len     = trtch ? strlen(trtch) : 0;
    int     i;
    TXT99   *tu;
    unsigned char   type;

    if (len) {
        type = 0;

        for(i=0; table[i].trtch[0]; i++) {
            if (memcmp(table[i].trtch, trtch, len)==0) {
                tu = NewTXT99(DALTRTCH,1,1,&table[i].type);
                if (!tu) goto quit;

                err = arrayadd(txt99, tu);
                goto quit;
            }
        }
    }

quit:
    return err;
}
