#ifndef CLIBLINK_H
#define CLIBLINK_H

/* link to external program, dcb, r1 and prc can be NULL
   returns -1 on non-ABEND link failure, otherwise pgm return code.
   if prc is not NULL then return code is stored at prc.
   note: not estae protected.
*/
int __link(const char *pgm, void *dcb, void *r1, int *prc);

/* link to external program, dcb, rc and prc can be NULL
   returns 0==success otherwise ABEND code.
   if prc is not NULL then pgm or __link() return code is stored at prc.
   note: uses try() to handle ABEND, no dump on failures.
*/
int __linkt(const char *pgm, void *dcb, void *r1, int *prc);

/* link to external program, dcb, rc and prc can be NULL
   returns 0==success otherwise ABEND code.
   if prc is not NULL then pgm or __link() return code is stored at prc.
   note: uses try() to handle ABEND, traceback stack, no dump on failures.
*/
int __linkds(const char *pgm, void *dcb, void *r1, int *prc);

#endif // CLIBLINK_H
