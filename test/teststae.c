#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "clibstae.h"

__asm__("\n&FUNC    SETC 'die'");
static int
die(void)
{
    int rc  = 0;

    return (rc = 1 / rc);
}

__asm__("\n&FUNC    SETC 'main'");
int
main(int argc, char**argv)
{
    int         rc;

    printf("In main()\n");
#if 0
    printf("Calling abendrpt(%d)\n", ESTAE_CREATE);
    rc = abendrpt(ESTAE_CREATE, DUMP_SUPPRESS);
    printf("After abendrpt(), rc=%d\n", rc);
#endif

#if 1
    printf("Calling die()\n");
    rc = die();
    printf("After die(), rc=%d\n", rc);
#endif

#if 0
    printf("Calling abendrpt(%d)\n", ESTAE_DELETE);
    rc = abendrpt(ESTAE_DELETE, DUMP_DEFAULT);
    printf("After abendrpt(), rc=%d\n", rc);
#endif // 0
    return rc;
}
