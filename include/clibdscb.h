/* CLIBDSCB.H
/*
/* Data Set Control Blocks (MVS)
*/
#ifndef CLIBDSCB_H
#define CLIBDSCB_H

typedef struct extent   EXTENT;
typedef struct dscb1    DSCB1;
typedef struct dscb3    DSCB3;
typedef struct dscb4    DSCB4;
typedef union  dscb     DSCB;
typedef struct locwork  LOCWORK; /* used by __locate() */

struct extent {
   unsigned char  flag;          /* extent flags */
#define EXTCYL    0x81           /* .. extent on cylinder boundaries */
#define EXTCYLS   0x80           /* .. extent sharing cylinder (no longer supported) */
#define EXTLAB    0x40           /* .. first extent describes the user lables and is not counted in NOEPV */
#define EXTIDX    0x04           /* .. index area (ISAM) */
#define EXTOV     0x02           /* .. overflow area (ISAM) */
#define EXTDAT    0x01           /* .. users data block, or a prime area extent (ISAM) */
   unsigned char  seq;           /* extent sequence number */
   unsigned char  lower[4];      /* lower CCHH */
   unsigned char  upper[4];      /* upper CCHH */
};

struct dscb1 {
   char           fmtid;         /* 00 format id 0xF1 */
   char           dssn[6];       /* 01 data set serial number (volser) */
   unsigned char  volsq[2];      /* 07 volume sequence number */
   char           credt[3];      /* 09 creation date */
   char           expdt[3];      /* 0C expiration date */
   unsigned char  noepv;         /* 0F number of extents on volume */
   unsigned char  nobdb;         /* 10 number of bytes used in last directory block */
   unsigned char  flag1;         /* 11 flags */
#define COMPR     0x80           /* .. compressed format data set (STRP is also 1) */
#define CPOIT     0x40           /* .. checkpointed data set */
   char           syscd[13];     /* 12 system code */
   char           refd[3];       /* 1F last reference date */
   unsigned char  smsfg;         /* 22 SMS flag */
#define SMSDS     0x80           /* .. system managed data set */
#define SMSUC     0x40           /* .. uncataloged system managed data set */
#define REBLK     0x20           /* .. can be reblocked */
#define CRSDB     0x10           /* .. created but empty data set */
#define PDSE      0x08           /* .. PDSE or HFS data set (PDSEX also 1 for HFS) */
#define STRP      0x04           /* .. sequential extended format data set */
#define PDSEX     0x02           /* .. HFS data set (PDSE must also be 1) */
#define DSAE      0x01           /* .. extended attributes exist */
   unsigned char  scxtf;         /* 23 secondary space extension flag byte */
#define SCAVB     0x80           /* .. SCXTV is the original block length. on=average block, off=average record */
#define SCMB      0x40           /* .. SCXTV is in megabytes */
#define SCKB      0x20           /* .. SCXTV is in kilobytes */
#define SCUB      0x10           /* .. SCXTV is in bytes */
#define SCCP1     0x08           /* .. SCXTV has been compacted by a factor of 256 */
#define SCCP2     0x04           /* .. SCXTV has been compacted by a factor of 65536 */
   unsigned short scxtv;         /* 24 secondary space extension value */
   unsigned char  dsorg1;        /* 26 first byte of dsorg flags */
#define DSGIS     0x80           /* .. indexed sequential */
#define DSGPS     0x40           /* .. physical sequential */
#define DSGDA     0x20           /* .. direct access */
#define DSGCX     0x10           /* .. BTAM or QTAM line group */
#define DSGPO     0x02           /* .. partitioned */
#define DSGU      0x01           /* .. unmovable */
   unsigned char  dsorg2;        /* 27 second byte of dsorg flags */
#define DSGGS     0x80           /* .. graphics */
#define DSGTX     0x40           /* .. TCAM line group */
#define DSGTQ     0x20           /* .. TCAM message queue */
#define ACBM      0x08           /* .. VSAM data set/space */
#define ORGAM     0x08           /* .. VSAM data set/space */
#define DSGTR     0x04           /* .. TCAM 3705 */
   unsigned char  recfm;         /* 28 record format */
#define RECFF     0x80           /* .. fixed */
#define RECFV     0x40           /* .. variable */
#define RECFU     0xC0           /* .. undefined */
#define RECFT     0x20           /* .. track overflow */
#define RECFB     0x10           /* .. blocked */
#define RECFS     0x08           /* .. fixed length:    standard blocks; no truncated blcoks */
                                 /* .. variable length: spanned records */
#define RECFA     0x04           /* .. ISO/ANSI control characters */
#define RECMC     0x02           /* .. machine control characters */
   unsigned char  optcd;         /* 29 option code */
/* BDAM optcd values (when DSGDA is on) */
#define BDAMWVC   0x80           /* .. write validity check */
#define BDAMTO    0x40           /* .. track overflow */
#define BDAMES    0x20           /* .. extended search */
#define BDAMFB    0x10           /* .. feedback */
#define BDAMAA    0x08           /* .. actual addressing */
#define BDAMDB    0x04           /* .. dynamic buffering */
#define BDAMRE    0x02           /* .. read exclusive */
#define BDAMRBA   0x01           /* .. relative block addressing */
/* ISAM optcd values (when DSGIS in on) */
#define ISAMWVC   0x80           /* .. write validity check */
#define ISAMACT   0x40           /* .. accumulate track index entry */
#define ISAMMI    0x20           /* .. master indices */
#define ISAMIO    0x10           /* .. indepenent overflow area */
#define ISAMCO    0x08           /* .. cylinder overflow area */
#define ISAMD     0x02           /* .. delete option */
#define ISAMR     0x01           /* .. reorganization criteria */
/* BPAM, BSAM, QSAM optcd values (when DSGPO or DSGPS is on) */
#define OPTWVC    0x80           /* .. write validity check */
#define OPTADC    0x40           /* .. allow data check (if on printer) */
#define OPTCS     0x20           /* .. chain scheduling */
#define OPTVSE    0x10           /* .. VSE/MVS interchange feature on tape */
#define OPTEOV    0x08           /* .. treat EOF as EOV (tape) */
#define OPTSD     0x04           /* .. search direct */
#define OPTUT     0x02           /* .. user label totaling */
#define OPTTRC    0x01           /* .. each record contains a table reference character */
/* VSAM optcd values (when ORGAM in on) */
#define OPTIC     0x80           /* .. data set is cataloged in an ICF catalog */
#define OPTBC     0x40           /* .. data set is an ICF catalog */
   unsigned short blksz;         /* 2A block length */
   unsigned short lrecl;         /* 2C logical record length */
   unsigned char  keyl;          /* 2E key length */
   unsigned char  rkp[2];        /* 2F relative key position */
   unsigned char  dsind;         /* 31 data set indicators */
#define IND80     0x80           /* .. last volume containing data in this data set */
#define IND40     0x40           /* .. RACF discrete profile */
#define IND20     0x20           /* .. block length is multiple of 8 bytes */
#define IND10     0x10           /* .. password is required to read or write */
#define IND08     0x08           /* .. reserved */
#define IND04     0x04           /* .. password required to write (IND10 must be on) but not read */
                                 /* .. otheriwse password required to write and read. */
#define IND02     0x02           /* .. data set opened for other than input since last backup */
#define DSCHA     0x02           /* .. "    "     */
#define IND01     0x01           /* .. secure checkpoint data set */
#define CHKOT     0x01           /* .. "    " */
   unsigned char  scal1;         /* 32 secondary space allocation flag */
#define CYL       0xC0           /* .. cylinder  */
#define TRK       0x80           /* .. track */
#define AVR       0x40           /* .. average record */
#define MSGP      0x20           /* .. mass storage vol group (no longer supported) */
#define EXT       0x10           /* .. extension to secondary space exist (see SCEXT) (not CYL, TRK or AVR) */
#define CONTG     0x08           /* .. contigious */
#define MXIG      0x04           /* .. MXIG */
#define ALX       0x02           /* .. ALX */
#define ROUND     0x01           /* .. round */
   unsigned char  scal3[3];      /* 33 secondary allocation quantity */
   unsigned char  lstar[3];      /* 36 last used track and block on track (TTR) */
   unsigned char  trbal[2];      /* 39 space remaining on last track */
   unsigned char  reserved1[2];  /* 3B reserved */
   EXTENT         extent[3];     /* 3D first three extents */
   unsigned char  ptrds[5];      /* 40 pointer (CCHHR) to a format-2 or format-3 DSCB, or zero */
};

struct dscb3 {
   unsigned char  key[4];        /* key identifier "\x03\x03\x03\x03" */
   EXTENT         extent4[4];    /* first four extents */
   char           fmtid;         /* format ID 0xF3 */
   EXTENT         extent9[9];    /* nine additional extents */
   unsigned char  ptrds[5];      /* pointer (CCHHR) to next format-3 DSCB or zero */
};

struct dscb4 {
   char           key[44];       /* all hex 0x04 */
   char           fmtid;         /* format id 0xF4 */
   unsigned char  hpchr[5];      /* highest address (CCHHR) of a format-1 DSCB */
   unsigned short dsrec;         /* number of available DSCBs */
   unsigned char  hcchh[4];      /* CCHH of next available alternate track */
   unsigned short noatk;         /* number of remaining alternate tracks */
   unsigned char  vtoci;         /* VTOC indicators */
#define DOSBT     0x80           /* .. VSE bit. Indexed VTOC */
#define DVTOC     0x40           /* .. index was disabled */
#define EFVLD     0x20           /* .. extented free space management flag */
#define DSTKP     0x10           /* .. VSE stacked pack */
#define DOCVT     0x08           /* .. VSE converted VTOC */
#define DIRF      0x04           /* .. DIRF bit. a VTOC changce is incomplete */
#define DICVT     0x02           /* .. DIRF reclaimed */
#define IVTOC     0x01           /* .. volume uses an indexed VTOC */
   unsigned char  noext;         /* number of extents in the VTOC */
   unsigned char  smsfg;         /* SMS indicators */
#define SMSCV     0x40           /* .. SMS in initial status */
#define SMS       0xC0           /* .. SMS volume */
   unsigned char  devac;         /* number of alternate cylinders when volume was formatted */
   unsigned short dscyl;         /* number of logical cylinders */
   unsigned short dstrk;         /* number of tracks in logical cylinder */
   unsigned short devtk;         /* device track length */
   unsigned short devov;         /* keyed record overhead */
   unsigned char  devi;          /* non-last-keyed record overhead */
   unsigned char  devl;          /* last keyed record overhead */
   unsigned char  devk;          /* non-keyed record overhead differential */
   unsigned char  devfg;         /* device flags */
#define DEVAV     0x10           /* .. value in DEVAC is valid */
   unsigned short devtl;         /* device tolerance */
   unsigned char  devdt;         /* number of DSCBs per track */
   unsigned char  devdb;         /* number of PDS directory blocks per track */
   unsigned char  amtim[8];      /* VSAM time stamp */
   unsigned char  amcat[3];      /* VSAM catalog indicator */
   unsigned char  vsind;         /* VSAM indicators */
#define VSREF     0x80           /* .. a VSAM catalog references this volume */
#define VSBAD     0x40           /* .. the VSAM data sets on this volume are unusable (no longer set) */
   unsigned short cra;           /* relative track location of the CRA */
   unsigned char  r2tim[8];      /* VSAM volume/catalog match time stamp */
   char           reserved1[5];  /* reserved */
   unsigned char  f6ptr[5];      /* pointer (CCHHR) to first format-6 DSCB or zero (no longer supported) */
   EXTENT         extent[2];     /* VTOC extents */
   unsigned char  eflvl;         /* Extent free-space management level */
   unsigned char  efptr[5];      /* pointer to extended free-space information (format-7 DSCBs) */
   char           reserved2[9];  /* reserved */
};

union dscb {
   char           work[140];     /* 140 byte work area */
   DSCB1          dscb1;         /* format-1 DSCB */
   DSCB3          dscb3;         /* format-3 DSCB */
   DSCB4          dscb4;         /* format-4 DSCB */
};

struct locwork {
	unsigned char unused1[6];	 /* work area should be 0 */
	char          volser[6];     /* returned to caller */
	unsigned char unused2[256];  /* work area should be 0 */
};

/* The following functions use the OBTAIN service and return the OBTAIN return code.
/* Return Code
/*    0(X'00') Successful completion of OBTAIN routine.
/*    4(X'04') The required volume was not mounted.
/*    8(X'08') The format-1 DSCB was not found in the VTOC of the specified volume.
/*   12(X'0C') A permanent I/O error was encountered, or an invalid format-1 DSCB
/*             was found when processing the specified volume, or an unexpected
/*             error return code was received from CVAF (common VTOC access facility).
/*   16(X'10') Invalid work area pointer.
 */

/* __dscbdv() - get DSCB by dataset name and volume */
extern int __dscbdv(const char dsn[44], const char vol[6], DSCB *dscb);

/* __dscbav() - get DSCB by absolute address and volume */
extern int __dscbav(const char cchhr[5], const char vol[6], DSCB *dscb);

/* __dscbv() - get format 4 DSCB by volume */
extern int __dscbv(const char vol[6], DSCB *dscb);

/* __locate() - locate dataset by name, volser is returned in the workarea */
extern int __locate(const char dsn[44], LOCWORK *workarea);


#endif
