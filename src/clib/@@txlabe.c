/* @@TXLABE.C */
#include "svc99.h"
#include "clibary.h"

static struct {
    const char      label[4];
    unsigned char   type;
} types[] = {
    {"NL",  0x01},
    {"SL",  0x02},
    {"NSL", 0x04},
    {"SUL", 0x0A},
    {"BLP", 0x10},
    {"LTM", 0x21},
    {"AL",  0x40},
    {"AUL", 0x48},
    {"",    0},
};

int
__txlabe(TXT99 ***txt99, const char *label)
{
    int     err     = 1;
    int     len     = label ? strlen(label) : 0;
    int     i;
    TXT99   *tu;

    if (len > 1) {
        for(i=0; types[i].label[0]; i++) {
            if (memcmp(types[i].label, label, len)==0) {
                tu = NewTXT99(DALLABEL,1,1,&types[i].type);
                if (!tu) goto quit;

                err = arrayadd(txt99, tu);
                goto quit;
            }
        }
    }

quit:
    return err;
}
