/* @@TXRECF.C */
#include "svc99.h"
#include "clibary.h"

static struct {
    const unsigned char recfm;
    const unsigned char type;
} table[] = {
    {'M',   0x02},
    {'R',   0x02},
    {'A',   0x04},
    {'G',   0x04},
    {'S',   0x08},
    {'B',   0x10},
    {'D',   0x20},
    {'T',   0x20},
    {'V',   0x40},
    {'F',   0x80},
    {'U',   0xC0},
    {0,     0}
};

int
__txrecf(TXT99 ***txt99, const char *recfm)
{
    int             err     = 1;
    int             i;
    int             j;
    TXT99           *tu;
    unsigned char   type;
    unsigned char   c;

    if (recfm) {
        type = 0;

        for(i=0; recfm[i]; i++) {
            c = (recfm[i] | ' ');   /* quick fold to upper */
            for(j=0; table[j].recfm; j++) {
                if (c==table[j].recfm) {
                    type |= table[j].type;
                    break;
                }
            }
        }

        if (!type) goto quit;

        tu = NewTXT99(DALRECFM,1,1,&type);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
