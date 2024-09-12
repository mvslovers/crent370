#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vsclos(VSFILE *vs)
{
    unsigned    pl[2] = {0};

    if (vs) {
        if (vs->flags & VSFILE_FLAG_OPEN) {
            __asm__("MVC\t0($CLSLEN,%1),CLSMODEL\n\t"
                    "CLOSE ((%0)),MF=(E,(%1))"
                : : "r"(&vs->acb), "r"(pl) : "1", "14", "15");

        }
        free(vs);
    }

    return 0;
}
__asm__("DS\t0F\nCLSMODEL CLOSE (*-*),MF=L\n$CLSLEN\tEQU\t*-CLSMODEL");
