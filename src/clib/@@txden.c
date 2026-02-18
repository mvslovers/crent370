/* @@TXDEN.C */
#include "svc99.h"
#include "clibary.h"

static struct {
    const char      density[5];
    unsigned char   type;
} table[] = {
    {"200",     0x03},
    {"556",     0x43},
    {"800",     0x83},
    {"1600",    0xC3},
    {"6250",    0xD3},
    {"",        0}
};

int
__txden(TXT99 ***txt99, const char *density)
{
    int     err     = 1;
    int     i;
    TXT99   *tu;

    if (density) {
        for(i=0; table[i].density[0]; i++) {
            if (strcmp(table[i].density, density)==0) {
                tu = NewTXT99(DALDEN,1,1,&table[i].type);
                if (!tu) goto quit;

                err = arrayadd(txt99, tu);
                goto quit;
            }
        }
    }

quit:
    return err;
}
