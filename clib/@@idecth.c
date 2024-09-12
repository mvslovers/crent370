#include <clib.h>

__asm__("\n&FUNC    SETC 'clib_identify_cthread'");
int
clib_identify_cthread(void)
{
    int     rc = 0;

    /* CTHREAD does not already exist, identify it now */
    /* wtof("%s preparing to IDENTIFY CTHREAD", __func__); */

    __asm__("L     1,=V(CTHREAD)    A(thread driver routine)\n\t"
            "LA    0,=CL8'CTHREAD'\n\t"
            "IDENTIFY EPLOC=(0),ENTRY=(1)\n\t"
            "ST    15,0(,%0)\n" : : "r" (&rc): "0", "1", "14", "15");
    __asm__("\n*\n");

    return rc;
}
