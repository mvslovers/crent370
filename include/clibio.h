#ifndef CLIBIO_H
#define CLIBIO_H

#include <stdarg.h>
#include <stddef.h>

typedef struct _file    FILE;       /* file handle                          */
typedef struct _file    _FILE;      /* file handle                          */

struct _file {
    char            eye[8];         /* 00 eye catcher for dumps             */
#define _FILE_EYE   "F I L E"       /* ...                                  */
    void            *dcb;           /* 08 DCB address                       */
    void            *asmbuf;        /* 0C buffer for assembler routines     */

    unsigned short  lrecl;          /* 10 logical record length             */
    unsigned short  blksize;        /* 12 physical block size               */
    int             ungetch;        /* 14 unget character                   */
    unsigned        filepos;        /* 18 character offset in file          */
    unsigned char   *buf;           /* 1C file buffer (lrecl+8)             */

    unsigned char   *upto;          /* 20 current position in buffer        */
    unsigned char   *endbuf;        /* 24 end of buffer                     */
    unsigned short  flags;          /* 28 processing flags                  */
#define _FILE_FLAG_DYNAMIC  0x8000  /* ... DD dynamically allocated         */
#define _FILE_FLAG_OPEN     0x4000  /* ... dataset is open                  */
#define _FILE_FLAG_READ     0x2000  /* ... open for read                    */
#define _FILE_FLAG_WRITE    0x1000  /* ... open for write                   */
#define _FILE_FLAG_APPEND   0x0800  /* ... open for append                  */
#define _FILE_FLAG_BINARY   0x0400  /* ... file data is binary              */
#define _FILE_FLAG_RECORD   0x0200  /* ... fread/fwrite uses record i/o     */
#define _FILE_FLAG_BSAM     0x0100  /* ... BSAM instead of QSAM access      */
#define _FILE_FLAG_TERM		0x0080	/* ... TERM opened in __fpstar()		*/

#define _FILE_FLAG_ERROR    0x0002  /* ... i/o error                        */
#define _FILE_FLAG_EOF      0x0001  /* ... EOF has occured                  */

    unsigned char   recfm;          /* 2A record format                     */
#define _FILE_RECFM_TYPE    0xC0    /* ... mask for F,V,U                   */
#define _FILE_RECFM_F       0x80    /* ... FIXED RECORD LENGTH              */
#define _FILE_RECFM_V       0x40    /* ... VARIABLE RECORD LENGTH           */
#define _FILE_RECFM_U       0xC0    /* ... UNDEFINED RECORD LENGTH          */

#define _FILE_RECFM_O       0x20    /* ... TRACK OVERFLOW                   */
#define _FILE_RECFM_B       0x10    /* ... BLOCKED RECORDS                  */
#define _FILE_RECFM_S       0x08    /* ... FOR FIXED LENGTH RECORD FORMAT -
                                           STANDARD BLOCKS.
                                           FOR VARIABLE LENGTH RECORD FORMAT -
                                           SPANNED RECORDS                  */
#define _FILE_RECFM_CC      0x06    /* ... mask for carriage control A,M    */
#define _FILE_RECFM_A       0x04    /* ... ASA CONTROL CHARACTER            */
#define _FILE_RECFM_M       0x02    /* ... MACHINE CONTROL CHARACTER        */

#define _FILE_RECFM_L       0x01    /* ... KEY LENGTH (KEYLEN) WAS SPECIFIED
                                           IN DCB MACRO INSTRUCTION         */

    char            ddname[9];      /* 2B DD name                           */
    char            member[9];      /* 34 member name                       */
    char            dataset[45];    /* 3D dataset name                      */
    char            mode[86];       /* 6A open mode string                  */
};                                  /* C0 (192 bytes)                       */

typedef unsigned long fpos_t;

#define NULL            ((void *)0)
#define FILENAME_MAX    260
#define FOPEN_MAX       256
#define _IOFBF          1
#define _IOLBF          2
#define _IONBF          3

/* set it to maximum possible LRECL to simplify processing */
/* also add in room for a RDW and dword align it just to be
   on the safe side */
#define BUFSIZ 32768
#define EOF -1
#define L_tmpnam        FILENAME_MAX
#define TMP_MAX         25
#define SEEK_SET        0
#define SEEK_CUR        1
#define SEEK_END        2

extern FILE **__gtin(void);
extern FILE **__gtout(void);
extern FILE **__gterr(void);

#define stdin           (*(__gtin()))
#define stdout          (*(__gtout()))
#define stderr          (*(__gterr()))

extern int      printf(const char *format, ...);
extern FILE     *fopen(const char *filename, const char *mode);
extern int      fclose(FILE *stream);
extern size_t   fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
extern size_t   fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
extern int      fputc(int c, FILE *stream);
extern int      fputs(const char *s, FILE *stream);
extern int      fprintf(FILE *stream, const char *format, ...);
extern int      vfprintf(FILE *stream, const char *format, va_list arg);
extern int      remove(const char *filename);
extern int      rename(const char *old, const char *newnam);
extern int      sprintf(char *s, const char *format, ...);
extern int      snprintf(char *s, int n, const char *format, ...);
extern int      vsprintf(char *s, const char *format, va_list arg);
extern char     *fgets(char *s, int n, FILE *stream);
extern int      ungetc(int c, FILE *stream);
extern int      fgetc(FILE *stream);
extern int      fseek(FILE *stream, long int offset, int whence);
extern long int ftell(FILE *stream);
extern int      fsetpos(FILE *stream, const fpos_t *pos);
extern int      fgetpos(FILE *stream, fpos_t *pos);
extern void     rewind(FILE *stream);
extern void     clearerr(FILE *stream);
extern void     perror(const char *s);
extern int      setvbuf(FILE *stream, char *buf, int mode, size_t size);
extern int      setbuf(FILE *stream, char *buf);
extern FILE     *freopen(const char *filename, const char *mode, FILE *stream);
extern int      fflush(FILE *stream);
extern char     *tmpnam(char *s);
extern FILE     *tmpfile(void);
extern int      fscanf(FILE *stream, const char *format, ...);
extern int      scanf(const char *format, ...);
extern int      sscanf(const char *s, const char *format, ...);
extern char     *gets(char *s);
extern int      puts(const char *s);
extern int      getchar(void);
extern int      putchar(int c);
extern int      getc(FILE *stream);
extern int      putc(int c, FILE *stream);
extern int      feof(FILE *stream);
extern int      ferror(FILE *stream);
extern int      vsnprintf(char *s, int n, const char *format, va_list arg);

#define getchar()       (getc(stdin))
#define putchar(c)      (putc((c), stdout))
#define getc(stream)    (fgetc((stream)))
#define putc(c, stream) (fputc((c), (stream)))
#define feof(stream)    ((stream)->flags & _FILE_FLAG_EOF)
#define ferror(stream)  ((stream)->flags & _FILE_FLAG_ERROR)

/* return name of function that called the caller of __caller() */
extern char *   __caller(char   *caller);


/* the following are functions that should only be called while
** holding a lock on the file handle.
*/
extern int      __fflush(FILE *fp);
extern int      __fgetc(FILE *fp);
extern char *   __fgets(char *s, int n, FILE *fp);
extern int      __fputc(int c, FILE *fp);
extern int      __fputs(const char *s, FILE *fp);
extern size_t   __fread(void *ptr, size_t size, size_t nmemb, FILE *fp);
extern FILE *   __reopen(const char *fn, const char *mode, FILE *fp);
extern int      __fseek(FILE *fp, long int offset, int whence);
extern size_t   __fwrite(const void *vptr, size_t size, size_t nmemb, FILE *fp);

/* __dsalc() allocate dataset - returns ddname if successful */
extern int __dsalc(char *ddname, const char *opts);

/* __dsalcf() allocate dataset (printf style) - returns ddname if successful */
extern int __dsalcf(char *ddname, const char *opts, ...);

/* __dsfree() deallocate ddname */
extern int __dsfree(const char *ddname);   /* input dd name                    */

#endif
