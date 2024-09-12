#ifndef EMFILE_H
#define EMFILE_H

/*
 * Emulated File using MVS dataset.
 * 
 * Normally an MVS dataset can be open for
 * read, write or update but not at the same time.
 * This behavior is unique to datasets.
 * 
 * A dataset open for write can not be read.
 * A dataset open for read can not be written.
 * A dataset open for update can not be written
 * to without first being read from the same
 * location. This means the file can not grow
 * while in update mode.
 * 
 * When porting software written for Unix or PC's
 * the expectation is that a 'file' can be accessed
 * in any combination of read, write and update
 * (seek read or seek write) at the same time and
 * that the file can grow simply by positioning
 * to the end of the file and writting new data
 * causing the file to grow in size.
 * 
 * This software emulates the expected unix/pc
 * behavior using MVS datasets as emulated files.
 * 
 * The datasets, from MVS perspective, are fixed
 * block sequential datasets (LRECL=4096,BLKSIZE=4096).
 * The emulated 'file' treats this dataset like a
 * block of fixed size buffers upon which the unix/pc
 * behavior is mapped.
 * 
 * Note that the the first block of the dataset is 
 * reserved for storing a header containing  the eye 
 * catcher "EMFILE MVS" as well as key values used 
 * to emulate the 'file' contained within the 
 * remaining dataset blocks.
 */

#include "stdio.h"
#include "errno.h"
#include "clib64.h"

#ifdef EMFILE	/* defined in errno.h */
# undef EMFILE
#endif

typedef struct emfile	EMFILE;	/* emulated file handle */

/*
 * Runtime configuration for emulated files.
 * 
 * You can call emfile_set_config() anytime you desire to alter 
 * the default values used for allocating new datasets.
 * 
 * Note the vols string can be NULL or one or more volume serial names
 * like "TSO000,TSO002". Up to 5 volume names can be specified in 
 * this version.
 * 
 * If the dataset is allocated on a single volume then the dataset
 * will be initialized one track at a time as the dataset grows
 * to accomodate the data written.  
 * However if the dataset is allocated on multiple volumes then 
 * the entire dataset will be initialized at open time with all 
 * of the extents being allocated at once.
 * This behavior is a requirement of the BDAM access method used
 * to access the dataset blocks.
 */
typedef enum emfile_space { 
	EMFILE_SPACE_TRACK=0, 	/* new datasets SPACE=TRACK				*/
	EMFILE_SPACE_CYL=1		/* new datasets SPACE=CYL				*/
} EMFILE_SPACE;

int emfile_set_config(	/* ... 						(default value)	*/
	EMFILE_SPACE space,	/* EMFILE_SPACE TRACK or CYL		(track)	*/
	unsigned blksize, 	/* block size 						(4096)	*/
	unsigned primary, 	/* primary tracks or cylinders		(15)	*/
	unsigned secondary,	/* secondary tracks or cylinders	(15)	*/
	const char *vols)	/* volume serial name or NULL		(NULL)	*/			asm("@@EMSCFG");

/*
 * emfile_open() mode string values:
 * "r"	Opens a file for reading. The file must exist.
 * "w"	Creates an empty file for writing. 
 *		If a file with the same name already exists, its content 
 * 		is erased and the file is considered as a new empty file.
 * "a"	Appends to a file. Writing operations, append data at the 
 * 		end of the file. The file is created if it does not exist.
 * "r+"	Opens a file to update both reading and writing. 
 * 		The file must exist.
 * "w+"	Creates an empty file for both reading and writing.
 * "a+"	Opens a file for reading and appending.
 */

/* emfile_open() - open an existing or new EMFILE dataset depending on mode strung */
EMFILE *emfile_open(const char *dsn, const char *mode)							asm("@@EMOPEN");

/* emfile_create() - open a new EMFILE dataset for read and write access (update) */
EMFILE *emfile_create(const char *dsn)											asm("@@EMCREA");

/* emfile_close() - close emfile handle */
int emfile_close(EMFILE *emfile)												asm("@@EMCLOS");

/* emfile_flush() - flush write buffer to dataset */
int emfile_flush(EMFILE *emfile)												asm("@@EMFLUS");

/* emfile_sync() - flush write buffer to dataset and update header info */
int emfile_sync(EMFILE *emfile)													asm("@@EMSYNC");

/* emfile_get_error() - retrieve last error and resets last error */
int emfile_get_error(EMFILE *f)													asm("@@EMGERR");

/* emfile_getc() - read 1 character from file, returns EOF on error or EOF */
int emfile_getc(EMFILE *f)														asm("@@EMGETC");

/* emfile_gets() - read string with newline characters - returns NULL on error or EOF */
char *emfile_gets(char *str, int size, EMFILE *f)								asm("@@EMGETS");

/* emfile_putc() - write one character to dataset */
int emfile_putc(int c, EMFILE *emfile)											asm("@@EMPUTC");

/* emfile_puts() - write null byte terminated string to file */
int emfile_puts(const char *str, EMFILE *f)										asm("@@EMPUTS");

/* emfile_printf() - format and print into file */
int emfile_printf(EMFILE *f, const char *format, ...)							asm("@@EMPRTF");

/* emfile_vprintf() - format and print into file */
int emfile_vprintf(EMFILE *f, const char *format, va_list arg)					asm("@@EMVPRT");

/* emfile_seek() - position in the file relative to origin
 * with origin being SEEK_SET(0), SEEK_CUR(1) or SEEK_END(2)
 */
int emfile_seek(EMFILE *f, long int offset, int origin)							asm("@@EMSEEK");

/* emfile_tell(), emfile_tell64() - returns current position in file */
long emfile_tell(EMFILE *f)														asm("@@EMTELL");
__64 emfile_tell64(EMFILE *f)													asm("@@EMTE64");

/* emfile_getpos() returns pos set to current offset in file */	
int emfile_getpos(EMFILE *f, __64 *pos)											asm("@@EMGPOS");

/* emfile_setpos() sets current offset to pos returned by emfile_getpos() */
int emfile_setpos(EMFILE *f, const __64 *pos)									asm("@@EMSPOS");

/* emfile_read() - read size bytes from file - returns number of elements read */
size_t emfile_read(void * buffer, size_t size, size_t nmemb, EMFILE *f)			asm("@@EMREAD");

/* emfile_write() - write emfile, returns number of elements written (nmemb) */
size_t emfile_write(const void *ptr, size_t size, size_t nmemb, EMFILE *emfile)	asm("@@EMWRIT");

/* emfile_truncate() - truncate file to specified length */
int emfile_truncate(EMFILE *f, long int length)									asm("@@EMTRUN");

/* emfile_dump() - write emfile handle values to console (wto) */
void emfile_dump(EMFILE *f)														asm("@@EMDUMP");

#endif
