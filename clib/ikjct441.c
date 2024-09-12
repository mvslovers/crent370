/* TSO Clist variable access z/OS (not for MVS 3.8) */
typedef struct ikjct441_plist IKJCT441;

struct ikjct441_plist {
    int         *ecode;
    const char  **name;
    int         *namelen;
    char        **value;
    int         *vallen;
    void        *token;
    void        *ect;
    int         *retcode;
    IKJCT441    *next;
};

/* ECODE values */
#define ECODE_TSVERETR    1
#define ECODE_TSVEUPDT    2
#define ECODE_TSVELOC     3
#define ECODE_TSVERSVD    4
#define ECODE_TSVNOIMP    18

int ikjct441(int ecode, const char *name, char *value, int value_size)
{
    int         rc       = 0;
    int         namelen  = name ? strlen(name) : 0;
    void        *token   = (void*)0;
    void        *ectnull = (void*)0xFFFFFFFF;
    unsigned    *psa     = (unsigned *)0;
    unsigned    *cvt     = (unsigned *)psa[16/4];
    unsigned    *tvt     = (unsigned *)cvt[156/4];
    int         (*ep)(int *, const char**, int *, char **, int *, void *, void *, int *, IKJCT441 *)
                         = (void*)tvt[40/4];
    IKJCT441    plist;

    /* construct the parameter list */
    plist.ecode     = &ecode;
    plist.retcode   = &rc;
    plist.name      = &name;
    plist.namelen   = &namelen;
    plist.value     = &value;
    plist.vallen    = &value_size;
    plist.token     = &token;
    plist.ect       = &ectnull;
    plist.retcode   = &rc;
    plist.next      = (IKJCT441*)0;

    /* call IKJCT441 via function pointer 'ep' */
    ep(plist.ecode, plist.name, plist.namelen, plist.value, plist.vallen, plist.token, plist.ect, plist.retcode, plist.next);

    /* return IKJCT441 retcode value (rc) */
    return rc;
}
