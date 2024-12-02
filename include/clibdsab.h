#ifndef CLIBDSAB_H
#define CLIBDSAB_H

#include <ihadsab.h>

/* get_dsab(tcbptr, ddname) - Get DSAB pointer, NULL if not found.
 * tcbptr is TCB address or NULL to use this task TCB.
 * (ddname==NULL) : returns first DSAB ptr for Job Step
 * (ddname > " ") : returns DSAB ptr that matches ddname.
*/
DSAB *get_dsab(void *tcbptr, const char *ddname)                        asm("@@GTDSAB");

/* next_dsab(dsab,ddname) - Get next DSAB for this DSAB and ddname */
DSAB *next_dsab(DSAB *dsab, void *tcbptr, const char *ddname)           asm("@@NXDSAB");

#endif
