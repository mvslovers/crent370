#ifndef IHADVA_H
#define IHADVA_H

/********************************************************************/
/*                 DEVTYPE PARAMETER AREA                           */
/*     THIS MACRO MAPS THE PARAMETER AREA RETURNED TO THE CALLER BY */
/*     THE DEVTYPE SVC.                                             */
/*     IN AN ASSEMBLER CALL DSECT=NO MAY BE CODED.                  */
/*                                                                  */
/*     IN A PLS INCLUDE, DVABASE MAY BE DECLARED AS DEF(LABEL)      */
/*     TO CAUSE IT TO BE USED IN A STRUCTURE. IF DVABASE IS         */
/*     OMITTED THE STRUCTURE IS DECLARED AS BASED.                  */
/*                                                                  */
/********************************************************************/

typedef struct dvatab	DVATAB;	/* DASD Devices						*/
typedef struct dvarps   DVARPS; /* RPS section						*/
typedef struct dvarea	DVAREA; /* Area if no INFOLIST=, DEVTAB or RPS */

/* Area if no INFOLIST=, DEVTAB or RPS */
struct dvarea {
	union {
		unsigned dvaucbty;		/* 00 UCBTYPE field					*/
		struct {
			unsigned char dvaopt[2]; /* 00 UCB options				*/
			unsigned char dvaclass;	 /* 02 Device class             */
			unsigned char dvaunit;   /* 03 Uint type                */
		};
	};
	unsigned	dvamaxrc;		/* 04 Maximum record size           */
};
#define DVADEVLG sizeof(DVAREA)	/* 08 (8) bytes */

struct dvarps {
	unsigned short dvaovr0;     /* 00 Overhead bytes for record 0    */
	unsigned char dvasect;      /* 02 Number of sectors in full track*/
	unsigned char dvasectd;     /* 03 Number of data sectors         */
};
#define DVARPSLG sizeof(DVARPS) /* 04 (4) bytes */

/***********************************************************************/
/*                  DEVTAB SECTION FOR DASD DEVICES                    */
/***********************************************************************/
struct dvatab {
	union {
		unsigned dvaucbty;		/* 00 UCBTYPE field					 */
		struct {
			unsigned char dvaopt[2]; /* 00 UCB options				 */
			unsigned char dvaclass;	 /* 02 Device class              */
			unsigned char dvaunit;   /* 03 Uint type                 */
		};
	};
	unsigned	dvamaxrc;		/* 04 Maximum record size            */
	/* - - e n d    o f    d v a r e a - - */
	unsigned short dvacyl;		/* 08 Phys no of CYL per volume      */
	unsigned short dvatrk;		/* 0A Number of tracks per cylinder  */
	unsigned short dvatrkln;	/* 0C Number of bytes per track      */
	union {
		unsigned short dvaovhd; /* 0E Block overhead if dva2bov=1    */
		struct {
			unsigned char dvaovnlb; /* 0E Overhead not last block    */
			unsigned char dvaovlb;  /* 0F Overhead last block        */
		};
	};

    unsigned char dvaovnk;      /* 10 Overhead decrement not keyed   */
	unsigned char dvaflags;		/* 11 flags                          */
#define DVABDCYL  0x80          /* ... IF 1, DVACYL IS INVALID       */
#define DVA2BOV   0x08          /* ... IF 1, USE DVAOVHD             */
                                /* ... IF 0, USE DVAOVNLB,DVAOVLB    */
#define DVAFTOL   0x01          /* ... IF 1, APPLY TOLERANCE FACTOR  */
	unsigned short dvatol;      /* 12 Tolerance factor               */
    /*************************************/
    /* APPLY TOLERANCE FACTOR AS FOLLOWS:*/
    /* 1. ADD BLOCKSIZE AND KEYLENGTH    */
    /* 2. MULTIPLY BY DVATOL             */
    /* 3. SHIFT RIGHT DVASHFT BITS       */
    /* 4. ADD APPROPRIATE OVERHEADS      */
    /*************************************/
#define DVASHFT    9            /* shift amount to devide by 512     */
#define DVAENTLG   0x14         /* 14 (20) bytes                     */

/**********************************************************************/
/*              THE FOLLOWING SECTION OF THE TABLE IS PRESENT         */
/*              ONLY FOR RPS DEVICES--TEST UCBTBYT2 FOR UCB2OPT3      */
/**********************************************************************/
	unsigned short dvaovr0;     /* 14 Overhead bytes for record 0    */
	unsigned char dvasect;      /* 16 Number of sectors in full track*/
	unsigned char dvasectd;     /* 17 Number of data sectors         */
};

#endif /* IHADVA_H */
