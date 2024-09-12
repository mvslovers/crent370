/* @@TXEROP.C */
#include "svc99.h"
#include "clibary.h"

static struct {
    const char      option[7];
    unsigned char   type;
} table[] = {
    {"BSAM",    0x10},
    {"TEST",    0x10},
    {"ABEND",   0x20},
    {"SKIP",    0x40},
    {"SKP",     0x40},
    {"ACCEPT",  0x80},
    {"",        0}
};

int
__txerop(TXT99 ***txt99, const char *option)
{
    int     err     = 1;
    int     i;
    TXT99   *tu;

    if (option) {
        for(i=0; table[i].option[0]; i++) {
            if (strcmp(table[i].option, option)==0) {
                tu = NewTXT99(DALEROPT,1,1,&table[i].type);
                if (!tu) goto quit;

                err = arrayadd(txt99, tu);
                goto quit;
            }
        }
    }

quit:
    return err;
}
