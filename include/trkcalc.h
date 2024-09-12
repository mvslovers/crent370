#ifndef TRKCALC_H
#define TRKCALC_H

typedef enum devtype    DEVTYPE;
enum devtype {
    DEV2311=0x01,
    DEV2301=0x02,
    DEV2303=0x03,
    DEV2302=0x04,
    DEV2321=0x05,
    DEV23051=0x06,  /* 2305-1   */
    DEV23052=0x07,  /* 2305-2   */
    DEV2314=0x08,
    DEV3330=0x09,
    DEV3340=0x0A,
    DEV3350=0x0B,
    DEB3375=0x0C,
    DEV333011=0x0D, /* 3330-11  */
    DEV3380=0x0E,
    DEV3390=0x0F,
};

/* trkcalc() - returns number of blocks that will fit on track */
extern int      trkcalc(DEVTYPE devtype, int keylen, int blksize);

#endif
