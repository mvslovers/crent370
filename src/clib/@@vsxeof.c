#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

/* This is the VSAM EOD handler */
int
__vsxeof(RPL *rpl, int code)
{
    VSFILE      *vs     = (VSFILE*)((char*)rpl - offsetof(VSFILE,rpl));

    vs->flags   |= VSFILE_FLAG_EOF;

    return code;
}
