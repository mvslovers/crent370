/* @@TXORG.C */
#include "svc99.h"
#include "clibary.h"

static struct {
    const char      dsorg[6];
    unsigned short  type;
} table[] = {
    {"CQ",      0x0800},
    {"CX",      0x1000},
    {"DA",      0x2000},
    {"DAU",     0x2100},
    {"GS",      0x0080},
    {"MQ",      0x0400},
    {"PO",      0x0200},
    {"POU",     0x0300},
    {"PS",      0x4000},
    {"PSU",     0x4100},
    {"TCAM",    0x0004},
    {"3705",    0x0004},
    {"TQ",      0x0020},
    {"TX",      0x0040},
    {"VSAM",    0x0008},
    {"",        0}
};

int
__txorg(TXT99 ***txt99, const char *dsorg)
{
    int     err     = 1;
    int     i;
    TXT99   *tu;

    if (dsorg) {
        for(i=0; table[i].dsorg[0]; i++) {
            if (strcmp(table[i].dsorg, dsorg)==0) {
                tu = NewTXT99(DALDSORG,1,2,(char *)&table[i].type);
                if (!tu) goto quit;

                err = arrayadd(txt99, tu);
                goto quit;
            }
        }
    }

quit:
    return err;
}
