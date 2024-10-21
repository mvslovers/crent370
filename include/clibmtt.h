#ifndef CLIBMTT_H
#define CLIBMTT_H

#include <ieezb806.h>   /* MTTABLE, MTENTRY */
#include <clibary.h>    /* dynamic array functions */

/* Master Trace Table data extraction routines */
typedef struct clibmtt  CMTT;       /* Clib Master Trace Table handle */

struct clibmtt {
    char            eye[8];         /* 00 eye catcher for dumps     */
#define CMTT_EYE    "*CMTT*"        /* ... eye catcher              */
    MTTABLE         *mttable;       /* 08 copy of Master Trace Table*/
    MTENTRY         **array;        /* 0C array of MTENTRY records  */
};

/* cmtt_new() - allocate CMTT handle and initialize */
CMTT *cmtt_new(void)                                                    asm("CMTTNEW");

/* cmtt_get_array() - builds and returns array of MTENTRY pointers */
MTENTRY **cmtt_get_array(CMTT *cmtt)                                    asm("CMTTGET");

/* cmtt_free() - release CMTT handle */
void cmtt_free(CMTT **pcmtt)                                            asm("CMTTFREE");

#endif  /* CLIBMTT_H */
