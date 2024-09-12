/* @@TXBFTE.C */
#include "svc99.h"
#include "clibary.h"

static struct {
    const char      technique[9];
    unsigned char   type;
} tech[] = {
    {"DYNAMIC",     0x08},
    {"EXCHANGE",    0x10},
    {"RECORD",      0x20},
    {"SIMPLE",      0x40},
    {"AREA",        0x60},
    {"",            0}
};

int
__txbfte(TXT99 ***txt99, const char *technique)
{
    int     err     = 1;
    int     len     = technique ? strlen(technique) : 0;
    int     i;
    TXT99   *tu;

    if (len) {
        for(i=0; tech[i].technique[0]; i++) {
            if (memcmp(tech[i].technique, technique, len)==0) {
                tu = NewTXT99(DALBFTEK,1,1,&tech[i].type);
                if (!tu) goto quit;

                err = arrayadd(txt99, tu);
                goto quit;
            }
        }
    }

quit:
    return err;
}
