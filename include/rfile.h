#ifndef RFILE_H
#define RFILE_H
/* This header defines a record oriented dataset interface. */

/* ROPEN provides a low level structure for sequential access
** of MVS datasets.
*/
typedef struct  rfile   RFILE;

struct rfile {
    char        eye[8];             /* 00 eye catcher                       */
#define RFILE_EYE   "*RFILE*"       /* ...                                  */
    int         dyn;                /* 08 true=ddname was dyn alloced       */
    int         recfm;              /* 0C record format flags               */
#define RFILE_RECFM_F       0       /* ... fixed length records             */
#define RFILE_RECFM_V       1       /* ... variable length records          */
#define RFILE_RECFM_U       2       /* ... undefined length records         */
    int         lrecl;              /* 10 logical record length             */
    int         write;              /* 14 true=open for output              */
    void        *hfile;             /* 18 __a....() handle                  */
    void        *asmbuf;            /* 1C __a....() data buffer             */
    char        ddname[9];          /* 20 ddname string                     */
    char        member[9];          /* 29 member string                     */
};                                  /* 32 (50 bytes)                        */

/* ropen() - open dataset
** fnm: "dd:ddname" or "dataset.name" or "'my.dataset.name'" or
**      "dd:ddname(member)" or "dataset(member)" or "'my.dataset(member)'"
*/
extern int  ropen(const char *fnm, int write, RFILE **fp);

/* rclose() - close handle created by ropen() */
extern int  rclose(RFILE *fp);

/* rread() - read record from dataset
** rc: 0==success, otherwise eof or error.
** read: number of bytes actually read. *read can be NULL*
*/
extern int  rread(RFILE *fp, void *ptr, size_t *read);

/* rwrite() - write record to dataset
** rc: 0==success, otherwise error.
** size: record length or 0 to use lrecl.
*/
extern int  rwrite(RFILE *fp, const void *ptr, size_t size);

#endif
