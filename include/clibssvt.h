#ifndef CLIBSSVT_H
#define CLIBSSVT_H

typedef struct ssvt     SSVT;       /* subsystem vector table               */

struct ssvt {
    short       ssvtrsv1;           /* 00 RESERVED                          */
    short       ssvtfnum;           /* 02 NUMBER OF FUNCTIONS SUPPORTED BY
                                          THIS SUBSYSTEM                    */
/*
**  256 BYTE FUNCTION MATRIX -
**
**    THE SSOB FUNCTION ID MINUS ONE IS USED AS AN OFFSET INTO
**    THIS MATRIX.
**
**        MATRIX FUNCTION BYTE  =0 : THE FUNCTION SPECIFIED IN THE
**                                   SSOB IS NOT SUPPORTED BY THIS
**                                   SUBSYSTEM.
**        MATRIX FUNCTION BYTE ¬=0 : THE VALUE (FUNCTION BYTE-1)*4
**                                   IS ADDED TO THE ADDRESS OF
**                                   SSVTFRTN TO OBTAIN THE
**                                   ADDRESS OF THE WORD CONTAINING
**                                   THE FUNCTION ROUTINE POINTER FOR
**                                   THIS REQUEST.
*/
    char        ssvtfcod[256];      /* 04 FUNCTION MATRIX                   */
    /* note: funcnum is used with ssvtfcod[] */

    void        *ssvtfrtn[0];       /* 104 SSVTFRTN IS THE FIRST WORD OF A
                                           VARIABLE LENGTH MATRIX CONTAINING
                                           FUNCTION ROUTINE POINTERS FOR
                                           FUNCTIONS SUPPORTED BY THIS
                                           SUBSYSTEM.  THE MATRIX CAN BE A
                                           MAXIMUM OF 256 WORDS LONG.       */
    /* note: index is used with ssvtfrtn[] */
};

/* ssvt_new() allocate a SSVT area with space for funcmax functions, requires supervisor state */
SSVT * ssvt_new(unsigned funcmax)                               asm("@@SVNEW");

/* ssvt_free() deallocates a SSVT area, requires supervisor state */
void ssvt_free(SSVT *ssvt)                                      asm("@@SVFREE");

/* ssvt_set() places func into SSVT area, requires supervisor state */
/* note: index range is 1 - funcmax inclusive */
int ssvt_set(SSVT *ssvt, unsigned index, void *func)            asm("@@SVSET");

/* ssvt_reset() removes func from SSVT area, requires supervisor state */
static __inline int ssvt_reset(SSVT *ssvt, unsigned index)
{
    return ssvt_set(ssvt, index, (void*)0);
}

/* ssvt_funcmap() maps function index to subsystem function number */
/* note: it's possible to have a function (index) that serves multiple function numbers */
/* note: index range is 0 - ssvt->ssvtfnum inclusive (0 disables the funcnum function) */
/* note: funcnum range is 1 - 256 inclusive */
int ssvt_funcmap(SSVT *ssvt, unsigned index, unsigned funcnum)  asm("@@SVFMAP");

#endif
