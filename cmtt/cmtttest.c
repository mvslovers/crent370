#include <clibio.h>
#include <clibmtt.h>

unsigned __stklen   = 1024 * 32;

int main(int argc, char **argv)
{
    CMTT        *cmtt       = (CMTT*)0;
    MTENTRY     **array     = (MTENTRY**)0;
    MTENTRY     *mtentry;
    unsigned    count;
    unsigned    n;

    /* create cmtt handle */
    cmtt = cmtt_new();

    /* get array of MTENTRY pointers */
    array = cmtt_get_array(cmtt);

    /* get number of MTENTRY pointers in array */
    count = array_count(&array);

    for(n=0; n < count; n++) {
        mtentry = array[n];

        /* print MTENTRY data 
         * 
         * length   = mtentry->mtentlen
         * data     = mtentry->mtentdat
        */
        printf("%s\n", mtentry->mtentdat);
    }

    /* release cmtt handle and all data */
    cmtt_free(&cmtt);

    return 0;
}
