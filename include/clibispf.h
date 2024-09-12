#ifndef CLIBISPF_H
#define CLIBISPF_H

/* The following function can be found in the ISP.V2R2M0.LLIB dataset */

int ispqry(void)										asm("ISPQRY");
/* ispqry() rc=0 ISPF services exist, rc=20 ISPF services are not available */
#define ispf_available()	(ispqry() == 0 ? 1 : 0)

/* NOTE ISPLINK and ISPEXEC require VL style parameter list
 * and C (GCCMVS / C2ASM370) can not create VL style plist.
*/
int ISPLINK(const char *service_name, ...)				asm("ISPLINK");
int ISPEXEC(unsigned *buflen, const char *buf)			asm("ISPEXEC");

/* C language callers should use ispexec() or isplink() below 
 * rc=0 Success
 * rc=20 ISPF not active
 * 
 * isplink() callers must set the high order bit of the last paramater
 * see ISP_LAST(a) below
*/
int isplink(const char *service_name, ...)				asm("@@ISPLNK");
int ispexec(const char *fmt, ...)						asm("@@ISPEXE");

/* ISP_LAST(a) - set the high order bit for this pointer */
#define ISP_LAST(a) 	((void*)((unsigned)(a) | 0x80000000))

/* isp_select() - formats buf and calls isplink("SELECT  ", buflen, buf) */
int isp_select(const char *fmt, ...)					asm("@@ISPSEL");

/* Call depth:
 *   ispexec()    --> tsocmdf() --> tsocmd() --> __link()
 *   isplink()    --> BALR to V(ISPLINK)
 *   isp_select() --> isplink() --> BALR to V(ISPLINK)
*/

/* Note: All service macro names prefixed with ISP_ to avoid name conflicts */
#define ISP_DEFAULT		"        "	/* default value to be used */

/* Display Services */
#define ISP_ADDPOP		"ADDPOP  "
#define ISP_DISPLAY		"DISPLAY "
#define ISP_REMPOP		"REMPOP  "
#define ISP_SELECT		"SELECT  "
#define ISP_SETMSG		"SETMSG  "
#define ISP_TBDISPL 	"TBDISPL "

/* File Tayloring Services */
#define ISP_FTOPEN		"FTOPEN  "
#define ISP_FTINCL		"FTINCL  "
#define ISP_FTCLOSE 	"FTCLOSE "
#define ISP_FTERASE 	"FTERASE "

/* Library Access Services */
#define ISP_DSINFO		"DSINFO  "
#define ISP_LMCLOSE		"LMCLOSE "
#define ISP_LMCOMP		"LMCOMP  "
#define ISP_LMCOPY		"LMCOPY  "
#define ISP_LMDDISP 	"LMDDISP "
#define ISP_LMDFREE 	"LMDFREE "
#define ISP_LMDINIT 	"LMDINIT "
#define ISP_LMDLIST 	"LMDLIST "
#define ISP_LMERASE 	"LMERASE "
#define ISP_LMFREE  	"LMFREE  "
#define ISP_LMGET   	"LMGET   "
#define ISP_LMINIT  	"LMINIT  "
#define ISP_LMMADD  	"LMMADD  "
#define ISP_LMMDEL  	"LMDDEL  "
#define ISP_LMMDISP 	"LMMDISP "
#define ISP_LMMFIND 	"LMMFIND "
#define ISP_LMMLIST 	"LMMLIST "
#define ISP_LMMOVE  	"LMMOVE  "
#define ISP_LMMREN  	"LMMREN  "
#define ISP_LMMREP  	"LMMREP  "
#define ISP_LMMSTATS 	"LMMSTATS"
#define ISP_LMOPEN  	"LMOPEN  "
#define ISP_LMPRINT 	"LMPRINT "
#define ISP_LMPUT   	"LMPUT   "
#define ISP_LMQUERY 	"LMQUERY "
#define ISP_LMRENAME 	"LMRENAME"
#define ISP_MEMLIST 	"MEMLIST "

/* PDF Component Services */
#define ISP_BRIF		"BRIF    "
#define ISP_BROWSE		"BROWSE  "
#define ISP_EDIF		"EDIF    "
#define ISP_EDIREC		"EDIREC  "
#define ISP_EDIT		"EDIT    "
#define ISP_EDREC		"EDREC   "
#define ISP_VIEW		"VIEW    "
#define ISP_VIIF    	"VIIF    "

/* Table Services */
#define ISP_TBCLOSE 	"TBCLOSE "
#define ISP_TBCREATE 	"TBCREATE"
#define ISP_TBEND		"TBEND   "
#define ISP_TBERASE 	"TBERASE "
#define ISP_TBOPEN		"TBOPEN  "
#define ISP_TBQUERY 	"TBQUERY "
#define ISP_TBSAVE  	"TBSAVE  "
#define ISP_TBSORT  	"TBSORT  "
#define ISP_TBSTATS 	"TBSTATS "
#define ISP_TBADD   	"TBADD   "
#define ISP_TBBOTTOM 	"TBBOTTOM"
#define ISP_TBDELETE 	"TBDELETE"
#define ISP_TBEXIST 	"TBEXIST "
#define ISP_TBGET   	"TBGET   "
#define ISP_TBMOD   	"TBMOD   "
#define ISP_TBPUT   	"TBPUT   "
#define ISP_TBSARG  	"TBSARG  "
#define ISP_TBSCAN  	"TBSCAN  "
#define ISP_TBSKIP  	"TBSKIP  "
#define ISP_TBTOP   	"TBTOP   "
#define ISP_TBVCLEAR 	"TBVCLEAR"

/* Variable Services */
#define ISP_VERASE  	"VERASE  "
#define ISP_VGET    	"VGET    "
#define ISP_VPUT    	"VPUT    "
#define ISP_VCOPY   	"VCOPY   "	/* ISPLINK only */
#define ISP_VDEFINE 	"VDEFINE "	/* ISPLINK only */
#define ISP_VDELETE 	"VDELETE "	/* ISPLINK only */
#define ISP_VMASK   	"VMASK   "	/* ISPLINK only */
#define ISP_VREPLACE 	"VREPLACE"	/* ISPLINK only */
#define ISP_VRESET  	"VRESET  "	/* ISPLINK only */

/* Miscellaneous Services */
#define ISP_CONTROL 	"CONTROL "
#define ISP_FILESTAT 	"FILESTAT"
#define ISP_FILEXFER 	"FILEXFER"
#define ISP_GETMSG  	"GETMSG  "
#define ISP_GRERROR 	"GRERROR "	/* ISPLINK only */
#define ISP_GRINIT  	"GRINIT  "	/* ISPLINK only */
#define ISP_GRTERM  	"GRTERM  "	/* ISPLINK only */
#define ISP_LIBDEF  	"LIBDEF  "
#define ISP_LIST    	"LIST    "
#define ISP_LOG     	"LOG     "
#define ISP_PQUERY  	"PQUERY  "
#define ISP_QBASELIB 	"QBASELIB"
#define ISP_QLIBDEF 	"QLIBDEF "
#define ISP_QTABOPEN 	"QTABOPEN"
#define ISP_QUERYENQ 	"QUERYENQ"
#define ISP_TRANS		"TRANS   "
#define ISP_WSCON   	"WSCON   "
#define ISP_WSDISCON 	"WSDISCON"

#endif
