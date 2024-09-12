#define LIB_CLIBLOCK
#define CLIBLOCK_C
#include "cliblock.h"

static CLIBLOCK lib = {
    __lk,
    __lktry,
    __lktest,
    __lkunlk,
    __lkrn,
    __lkrnte,
    __lkuntr,
    __lkrnun,
    __lkrnf,
    __lkrtef,
    __lkuntf,
    __lkrnuf,
};

CLIBLOCK    *cliblock = &lib;
