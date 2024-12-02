#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_case_cmp'");
int pdf_case_cmp(const char *p1, const char *p2)
{
    int     rc;

    for(rc=0; rc == 0; p1++, p2++) {
        rc = tolower(*p1) - tolower(*p2);
        if (*p1==0) break;
    }

    return rc;
}
