#include <stdio.h>
#include <time.h>
#include "clibcrt.h"
#include "cliblock.h"

int
main(int argc, char **argv)
{
    int i;
    time_t  now;

    printf("Hello World\n");
#if 1
    for(i=0;i<argc; i++) {
        wtof("argv#%d=\"%s\"\n", i, argv[i]);
    }

    printf("The current time zone offset is: %d\n", __tzget());
    tzset();
    printf("The current time zone offset is: %d\n", __tzget());
    __tzset(-(60*60*6));
    printf("The current time zone offset is: %d\n", __tzget());
#if 0
    now = time(NULL);
    printf("Issuing LOCK %s", ctime(&now));
    printf("rc=%d\n", lock(&now, 0));

    now = time(NULL);
    printf("Issuing TRYLOCK %s", ctime(&now));
    printf("rc=%d\n", trylock(&now, 0));
#endif
    now = time(NULL);
    printf("Issuing TESTLOCK %s", ctime(&now));
    printf("rc=%d\n", testlock(&now, 0));

#if 0
    printf("Sleeping 60 seconds\n");
    sleep(60);
#endif
    now = time(NULL);
    printf("Issuing UNLOCK %s", ctime(&now));
    printf("rc=%d\n", unlock(&now, 0));
#endif
    return 0;
}
