#include <clibmtt.h>

void cmtt_free(CMTT **pcmtt)
{
    CMTT    *cmtt;
    
    if (!pcmtt) goto quit;

    cmtt = *pcmtt;
    if (cmtt) {
        if (cmtt->array)    array_free(&cmtt->array);
        if (cmtt->mttable)  free(cmtt->mttable);
        free(cmtt);
    }
    
    *pcmtt = (CMTT*)0;

quit:
    return;
}
