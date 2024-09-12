/* @@FDCLR.C - dynamic deallocation */
#include <stdio.h>

struct rb {
    char    len; /* length of request block, always 20 */
    char    verb; /* dynamic allocation function requested */
    char    flag1;
    char    flag2;
    short   error_reason; /* returned */
    short   info_reason; /* returned */
    void    *tu_list; /* list of pointers to text units */
    int     reserved;
    char    moreflags[4]; /* extraflags */
};

struct tu {
    short   key; /* key defining what this text unit is */
    short   numparms; /* number of parms that follow */
    short   parm1_len;
    char    parm1[98];
    /* parm2_len etc would theoretically follow, but we
    /* can't define them, because the length of 98 is probably
       not correct in the first place */
};

int
__fdclr(char *ddname)
{
    int         err     = 0;
    void        *tu_list[10];
    struct rb   rb;
    struct tu   tu[10];

    memset(&rb, 0x00, sizeof rb);
    rb.len          = 20;
    rb.verb         = 0x02; /* unallocate */
    rb.tu_list      = tu_list;

    tu_list[0]      = &tu[0];
    tu[0].key       = 0x0001; /* ddname */
    tu[0].numparms  = 1;
    tu[0].parm1_len = strlen(ddname);
    strcpy(tu[0].parm1, ddname);

    tu_list[1]      = (void *)0x80000000;

    err = __svc99(&rb);
    return err;
}
