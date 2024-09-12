#ifndef IECVUCB_H
#define IECVUCB_H

typedef struct ucblist	UCBLIST;

/* The UCB list if addressed by CVT->CVTILK2 and contains a list
 * of UCB addresses (array of addresses) as half word values
 * (UCB's are in low core). The end of the UCB list is 0xFFFF .
 */
struct ucblist {
	unsigned short	ucb[0];			/* 00 array of UCB addresses	*/
#define UCBSKIP		0x0000			/* ... skip this UCB			*/
#define UCBEOL		0xFFFF			/* ... end of UCB list			*/
};

/* We're only mapping the UCBDASD at this time */
typedef struct ucbdasd	UCBDASD;

struct ucbdasd {
	unsigned char 	ucbjobid;		/* 00 always 0x00				*/
	unsigned char 	ucbflg5;		/* 01 always 0x00 ?				*/
	unsigned char	ucbid;			/* 02 always 0xFF				*/
	unsigned char 	ucbstat;		/* 03 device status				*/
#define UCBONLI		0x80			/* ... device is ONLINE			*/
#define UCBRESV		0x20			/* ... device is RESERVED		*/
#define UCBPRES		0x04			/* ... device is PERM RESIDENT	*/

	unsigned short 	ucbchan;		/* 04 device channel			*/
	unsigned char	ucbfla;			/* 06							*/
	unsigned char 	ucbflb;			/* 07							*/
	unsigned char 	ucbchanmask;	/* 08							*/
	unsigned char 	ucbcnt;			/* 09							*/
	unsigned char 	ucblci;			/* 0A							*/
	unsigned char 	ucbcpu;			/* 0B							*/
	unsigned char 	ucbwgt;			/* 0C							*/

	unsigned char 	ucbname[3];		/* 0D device name				*/
	unsigned char	ucbtype[4];		/* 10 device type				*/
#define UCBTYPEDA   0x20 			/* ... ucbtype[2] == UCBTYPEDA	*/
#define UCBTYPE2321 0x05			/* ... ucbtype[3] == UCBTYPE2321*/

	unsigned char 	ucbflc;			/* 14							*/
	unsigned char 	ucbext[3];		/* 15 ptr to UCB extension		*/
	unsigned char   ucbspeed[4];	/* 18 ?							*/
	
	unsigned char 	ucbvol[6];		/* 1C volser					*/
	unsigned char 	ucbstab;		/* 22 volume status				*/
#define UCBSTABPRV  0x10			/* ... PRIVATE VOLUME			*/
#define UCBSTABPUB  0x08			/* ... PUBLIC VOLUME			*/
#define UCBSTABSTR  0x04			/* ... STORAGE VOLUME			*/

	unsigned char	ucbdmct;		/* 23							*/
	unsigned char 	ucbsqc;			/* 24							*/
	unsigned char	ucbfl4;			/* 25							*/
	unsigned char	ucbuser;		/* 26							*/
	unsigned char 	ucbresv;		/* 27							*/
	
	void 			*ucbzeus;		/* 28 ptr to 1st ZEUS UCB		*/
	void 			*ucbnzeus;		/* 2C ptr to next in ring		*/
};

#endif


