#include "modmap.h"

int
main(int argc, char **argv)
{
    int             rc      = 0;
    MODMAP          *mm     = NULL;
    FILE            *fp     = NULL;
    size_t          read    = 0;
    unsigned char   *dptr   = NULL;
    MMOD            *mmod   = NULL;
    unsigned char   fn[88]  = "";

    /* allocate a module map handle */
    mm = modmap_new();
    if (!mm) {
        wtof("Unable to allocate module map handle\n");
        rc = 12;
        goto quit;
    }

    while (gets(fn)) {
        strtok(fn,"\n");
        if (strlen(fn) > 72 && isdigit(fn[72])) {
            fn[72]=0;
            strtok(fn,"");
        }
        if (fn[0]=='*' || fn[0]=='#') {
            /* echo comment lines */
            wtof("%s\n", fn);
            continue;
        }
        if (modmap_open(mm, fn)) {
            wtof("Unable to open \"%s\" for input\n", fn);
            continue;
        }

        wtof("Dataset \"%s\" opened\n", mm->fn);

        if (modmap_process(mm)) {
            wtof("Processing error for dataset \"%s\"\n", mm->fn);
            continue;
        }

        /* sort results by address */
        modmap_sort(mm);

        /* dump results via wtof() */
        modmap_dump(mm);

        /* test with new base address */
        modmap_base(mm, 0x00FF0000);

        /* dump results via wtof() */
        modmap_dump(mm);

        /* test zap of memory using module map */
        rc = modmap_zap(mm, 0x00FF0000, 65536);

        wtof("Dataset \"%s\" closed\n", mm->fn);
        modmap_reset(mm);
    }

quit:
    modmap_free(&mm);
    return rc;
}
