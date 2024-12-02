#ifndef SVC99_H
#define SVC99_H

#include "rb99.h"
#include "txt99.h"

extern TXT99 *__nwtx99(int dal, int count, int size, const char *text);
#define NewTXT99(dal,count,size,text)   __nwtx99((dal),(count),(size),(text))

extern TXT99 *__nwtx9a(int dal, int count, char **array);
#define NewTXT99a(dal,count,array)      __nwtx9a((dal),(count),(array))

extern TXT99 *__nwtx9s(int dal, int count, ...);
#define NewTXT99s(dal,count, ...)       __nwtx9s((dal),(count),## __VA_ARGS__)

extern void __frtx99(TXT99 **txt99);
#define FreeTXT99(txt99)                __frtx99(txt99)

extern void __frtx9a(TXT99 ***txt99array);
#define FreeTXT99Array(txt99array)      __frtx9a(txt99array)


/* __txdsn() - add text unit for DATASET name to array of text units */
extern int  __txdsn(TXT99 ***txt99, const char *dataset);

/* __txdmy() - add text unit for DUMMY to array of text units */
extern int  __txdmy(TXT99 ***txt99, const char *unused);

/* __txddn() - add text unit for DDNAME to array of text units */
extern int  __txddn(TXT99 ***txt99, const char *ddname);

/* __txrddn() - add text unit for RETURN DDNAME to array of text units */
extern int  __txrddn(TXT99 ***txt99, const char *unused);

/* __txdest() - add text unit for DEST to array of text units */
extern int  __txdest(TXT99 ***txt99, const char *dest);

/* __txnew() - add text unit for DISP=NEW to array of text units */
extern int  __txnew(TXT99 ***txt99, const char *unused);

/* __txold() - add text unit for DISP=OLD to array of text units */
extern int  __txold(TXT99 ***txt99, const char *unused);

/* __txmod() - add text unit for DISP=MOD to array of text units */
extern int  __txmod(TXT99 ***txt99, const char *unused);

/* __txshr() - add text unit for DISP=SHR to array of text units */
extern int  __txshr(TXT99 ***txt99, const char *unused);

/* __txsyso() - add text unit for SYSOUT to array of text units */
extern int  __txsyso(TXT99 ***txt99, const char *out_class);

/* __txvols() - add text unit(s) for "VOL1[,VOL2,...] VOLSER(s)
**              to array of text units */
extern int  __txvols(TXT99 ***txt99, const char *vols);

/* __txspac() - add text units for "PRI[,SEC]" SPACE to array of text units */
extern int  __txspac(TXT99 ***txt99, const char *space);

/* __txdir() - add text unit for PDS directory blocks to array of text units */
extern int  __txdir(TXT99 ***txt99, const char *pds_dir);

/* __txblk() - add text unit for BLOCKS to array of text units */
extern int  __txblk(TXT99 ***txt99, const char *blocks);

/* __txtrk() - add text unit for TRACKS to array of text units */
extern int  __txtrk(TXT99 ***txt99, const char *unused);

/* __txcyl() - add text unit for CYLINDERS to array of text units */
extern int  __txcyl(TXT99 ***txt99, const char *unused);

/* __txhold() - add text unit for HOLD to array of text units */
extern int  __txhold(TXT99 ***txt99, const char *unused);

/* __txunit() - add text unit for UNIT to array of text units */
extern int  __txunit(TXT99 ***txt99, const char *unit);

/* __txunct() - add text unit for UNIT count to array of text units */
extern int  __txunct(TXT99 ***txt99, const char *count);

/* __txpara() - add text unit for PARALLEL volume mount to arr of text units */
extern int  __txpara(TXT99 ***txt99, const char *unused);

/* __txlabe() - add text unit for LABEL to array of text units */
extern int  __txlabe(TXT99 ***txt99, const char *label);

/* __txseq() - add text unit for dataset sequence to array of text units */
extern int  __txseq(TXT99 ***txt99, const char *sequence);

/* __txvlct() - add text unit for max volume count to array of text units */
extern int  __txvlct(TXT99 ***txt99, const char *max_vols);

/* __txpriv() - add text unit for PRIVATE volume to array of text units */
extern int  __txpriv(TXT99 ***txt99, const char *unused);

/* __txrlse() - add text unit for RLSE to array of text units */
extern int  __txrlse(TXT99 ***txt99, const char *unused);

/* __txvseq() - add text unit for volume sequence to array of text units */
extern int  __txvseq(TXT99 ***txt99, const char *sequence);

/* __txrnd() - add text unit for ROUND to array of text units */
extern int  __txrnd(TXT99 ***txt99, const char *unused);

/* __txkeep() - add text unit for DISP=,KEEP to array of text units */
extern int  __txkeep(TXT99 ***txt99, const char *unused);

/* __txdel() - add text unit for DISP=,DELETE to array of text units */
extern int  __txdel(TXT99 ***txt99, const char *unused);

/* __txcat() - add text unit for DISP=,CATALOG to array of text units */
extern int  __txcat(TXT99 ***txt99, const char *unused);

/* __txucat() - add text unit for DISP=,UNCATALOG to array of text units */
extern int  __txucat(TXT99 ***txt99, const char *unused);

/* __txbfal() - add text unit for "FULL|DOUBLE" buffer alignment
                to array of text units */
extern int  __txbfal(TXT99 ***txt99, const char *align);

/* __txbfte() - add text unit for buffer technique to array of text units */
extern int  __txbfte(TXT99 ***txt99, const char *technique);

/* __txbksz() - add text unit for BLKSIZE to array of text units */
extern int  __txbksz(TXT99 ***txt99, const char *blksize);

/* __txbufl() - add text unit for buffer length */
extern int  __txbufl(TXT99 ***txt99, const char *length);

/* __txbufn() - add text unit for BUFNO to array of text units */
extern int  __txbufn(TXT99 ***txt99, const char *bufno);

/* __txbufo() - add text unit for buffer offset to array of text units */
extern int  __txbufo(TXT99 ***txt99, const char *offset);

/* __txden() - add text unit for tape density to array of text units */
/*              density="200|556|800|1600|6250" */
extern int  __txden(TXT99 ***txt99, const char *density);

/* __txorg() - add text unit for DSORG to array of text units */
extern int  __txorg(TXT99 ***txt99, const char *dsorg);

/* __txerop() - add text unit for error option to array of text units */
extern int  __txerop(TXT99 ***txt99, const char *option);

/* __txkeyl() - add text unit for key length to array of text units */
extern int  __txkeyl(TXT99 ***txt99, const char *length);

/* __txlmct() - add text unit for limit count to array of text units */
extern int  __txlmct(TXT99 ***txt99, const char *limit);

/* __txlrec() - add text unit for LRECL to array of text units */
/*              lrecl="nnn[K]|X" */
extern int  __txlrec(TXT99 ***txt99, const char *lrecl);

/* __txncp() - add text unit for NCP to array of text units */
extern int  __txncp(TXT99 ***txt99, const char *count);

/* __txrecf() - add text unit for RECFM to array of text units */
extern int  __txrecf(TXT99 ***txt99, const char *recfm);

/* __txtrtc() - add text unit for TRTCH to array of text units */
extern int  __txtrtc(TXT99 ***txt99, const char *trtch);

/* __txinpu() - add text unit for INPUT ONLY to array of text units */
extern int  __txinpu(TXT99 ***txt99, const char *unused);

/* __txoutp() - add text unit for OUTPUT ONLY to array of text units */
extern int  __txoutp(TXT99 ***txt99, const char *unused);

/* __txexpd() - add text unit for YYDDD expiration date to array of text units*/
extern int  __txexpd(TXT99 ***txt99, const char *yyddd);

/* __txretp() - add text unit for retension period to array of text units */
extern int  __txretp(TXT99 ***txt99, const char *days);

/* __txfcb() - add text unit for FCB to array of text units */
/*              fcb="ALIGN|VERIFY|name" */
extern int  __txfcb(TXT99 ***txt99, const char *fcb);

/* __txcopy() - add text unit for COPIES to array of text units */
extern int  __txcopy(TXT99 ***txt99, const char *copies);

/* __txprot() - add text unit for dataset protection to array of text units */
extern int  __txprot(TXT99 ***txt99, const char *unused);

/* __txform() - add text unit for FORM to array of text units */
extern int  __txform(TXT99 ***txt99, const char *form);

/* __txucs() - add text unit for UCS name to array of text units */
/*              name="FOLD|VERIFY|name" */
extern int  __txucs(TXT99 ***txt99, const char *name);

/* __txpgm() - add text unit for PGM (writer) to array of text units */
extern int  __txpgm(TXT99 ***txt99, const char *pgm);

/* __txterm() - add text unit for terminal to array of text units */
extern int  __txterm(TXT99 ***txt99, const char *unused);

/* __txperm() - add text unit for permanent to array of text units */
extern int  __txperm(TXT99 ***txt99, const char *unused);

/* __txunal() - unallocate */
extern int	__txunal(TXT99 ***txt99, const char *unused);


/* __txadel() - abnormal disp delete */
extern int __txadel(TXT99 ***txt99, const char *unused);

/* __txakee() - abnormal disp keep */
extern int __txakee(TXT99 ***txt99, const char *unused);

/* __txacat() - abnormal disp catalog */
extern int __txacat(TXT99 ***txt99, const char *unused);

/* __txauca() - abnormal disp uncatalog */
extern int __txauca(TXT99 ***txt99, const char *unused);

/* __txclos() - unallocate on close */
extern int  __txclos(TXT99 ***txt99, const char *unused);

#endif
