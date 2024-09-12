#ifndef EMFILEI_H
#define EMFILEI_H

/* This header provides the internal structures and function
 * prototypes for the emulated file using MVS datasets
 * described in the "emfile.h" header.
 */
#include "emfile.h"
#include "time64.h"
#include "string.h"
#include "clib.h"
#include "clib64.h"
#include "osdcb.h"
#include "osio.h"
#include "svc99.h"
#include "clibary.h"
#include "clibdscb.h"
#include "trkcalc.h"
#include "ihadva.h"	
#include "cliblist.h"
#include "cliblock.h"
#include "mvssupa.h"

/* EMFILE exist in errno.h as a define, so we have to undo it here */
#define ERRNO_EMFILE EMFILE
#undef EMFILE

#define MAXDDN		8
#define MAXDSN		44
#define MAXVOL		6

struct emfile {
	char		eye[8];				/* 00 eye catcher				*/
#define EMFILE_EYE	"*EMFILE*"		/* ... eye catcher              */
	__64 		alloc;				/* 08 allocated file bytes		*/
	__64		used;				/* 10 used file bytes			*/
	__64		offset;				/* 18 current position in file  */
	unsigned	block;				/* 20 current block number		*/
	unsigned	blocks;				/* 24 dataset block count		*/
	unsigned	tracks;				/* 28 dataset track count		*/
	unsigned	blkstrk;			/* 2C dataset blocks per track	*/
	unsigned	blksize;			/* 30 block size				*/
	DCB			*bdamdcb;			/* 34 dataset control block		*/
	DECB		*bdamdecb;			/* 38 dataset event control blk	*/
	char 		*buf;				/* 3C IO buffer of blksize bytes*/
	char 		*r0;				/* 40 record 0 (header)			*/
	char 		ddname[8];			/* 44 allocated DD name			*/
	char		z1;					/* 4C zero byte					*/
	char		dsname[44];			/* 4D dataset name 				*/
	char 		z2;					/* 79 zero byte					*/

	unsigned short flags;			/* 7A processing flags			*/
#define EMFILE_FLAG_MULTIV	0x8000	/* ... dataset is multi volume	*/
#define EMFILE_FLAG_GROW	0x4000  /* ... dataset can grow			*/
#define EMFILE_FLAG_FULL	0x2000	/* ... dataset now full			*/
#define EMFILE_FLAG_UPDATE	0x00C0	/* ... read and write			*/
#define EMFILE_FLAG_READ	0x0080	/* ... read						*/
#define EMFILE_FLAG_WRITE	0x0040	/* ... write					*/
#define EMFILE_FLAG_APPEND	0x0020	/* ... append                   */
#define EMFILE_FLAG_CREATE	0x0010	/* ... create if not exist		*/
#define EMFILE_FLAG_DYNAMIC 0x0008	/* ... dynamically allocated	*/
#define EMFILE_FLAG_NEW		0x0004	/* ... this is a new dataset	*/
#define EMFILE_FLAG_EOF		0x0002	/* ... end of file reached		*/
#define EMFILE_FLAG_DIRTY   0x0001	/* ... buf has been modified	*/

	char        **volser;			/* 7C volser array				*/
	int			error;				/* 80 last error				*/
	char 		*growdd;			/* 84 allocated dd name			*/
	char		devtype;			/* 88 device type code			*/
	char		unusedc[3];			/* 89 unused/available			*/
	unsigned	unusedu;			/* 8C unused/available			*/
};									/* 90 (144 bytes)				*/

typedef struct emfile10	EMFILE10;	/* version 1 header record		*/
struct emfile10 {
	char		eye[16];			/* 00 eye catcher, signature	*/
#define EMFILEMVS	"EMFILE MVS"	/* ... "EMFILE MVS"				*/
#define EMFILEVER	"1.0"			/* ... "1.0"					*/
#define EMFILEEYE10 \
		EMFILEMVS " " EMFILEVER		/* ... "EMFILE MVS 1.0"         */
	time64_t	create;				/* 10 create timestamp			*/
	time64_t	modified;			/* 18 modified timestamp		*/
	__64		size;				/* 20 size of file in bytes     */
};									/* 28 (40 bytes)				*/

typedef struct emfilewsa EMFILEWSA;	/* writable static area			*/
struct emfilewsa {
	char 		eye[8];				/* 00 eye catcher				*/
#define EMFILEWSA_EYE	"*EMFWSA*"	/* ... eye catcher string		*/
	unsigned	space;				/* 08 EMFILE_TRACK or EMFILE_CYL*/
	unsigned	blksize;			/* 0C block and lrecl size		*/
	unsigned	primary;			/* 10 primary track/cyl			*/
	unsigned	secondary;			/* 14 secondary track/cyl		*/
	char 		*vols;				/* 18 volume serial number's	*/
};									/* 1C (28 bytes)				*/

/* internal use only */
int emfile_setup(EMFILE *f)												asm("@@EMSETU");
int emfile_init(const char *ddname, unsigned blksize, JFCB *jfcb)		asm("@@EMINIT");
int emfile_full_init(const char *ddname, unsigned blksize, JFCB *jfcb)	asm("@@EMFULL");
int emfile_set_dsn(const char *dsn, char *dest)							asm("@@EMSDSN");
int emfile_set_ddn(const char *ddn, char *dest)							asm("@@EMSDDN");
int emfile_set_volser(EMFILE *f, JFCB *jfcb)							asm("@@EMSVOL");
int emfile_calc_size(EMFILE *p)											asm("@@EMCSIZ");
int emfile_read_block(EMFILE *p, unsigned block, char *buf)				asm("@@EMRBLK");
int emfile_write_block(EMFILE *p, unsigned block, char *buf)			asm("@@EMWBLK");
int emfile_validate(EMFILE *p)											asm("@@EMVALI");
int emfile_read_header(EMFILE *p)										asm("@@EMRHDR");
int emfile_write_header(EMFILE *p)                                      asm("@@EMWHDR");
int emfile_create_header(char *buf, __64 size)                          asm("@@EMCHDR");
int emfile_allocate_new(EMFILE *p)										asm("@@EMANEW");
int emfile_allocate_old(EMFILE *p)										asm("@@EMAOLD");
int emfile_allocate_shr(EMFILE *p)										asm("@@EMASHR");
int emfile_allocate_mod(EMFILE *f, char *ddname)						asm("@@EMAMOD");
int emfile_unallocate(const char *ddname)								asm("@@EMUNAL");
int emfile_offset_block_pos(EMFILE *f, unsigned *b, unsigned *p)		asm("@@EMOBPO");
int emfile_grow(EMFILE *f, unsigned bytes)								asm("@@EMGROW");
int emfile_write_bytes(EMFILE *f, const char *buf, unsigned size)		asm("@@EMWBYT");
/* emfile_read_bytes() - returns bytes read (>=0) or error (<0) */
int emfile_read_bytes(EMFILE *f, char *buf, unsigned size, const char *stopc) asm("@@EMRBYT");
/* emfile_get_wsa() - returns pointer to writeable static area or NULL (out of memory) */
EMFILEWSA *emfile_get_wsa(void)											asm("@@EMGWSA");

#endif
