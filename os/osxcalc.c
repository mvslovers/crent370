/* OSXCALC.C - given a DCB and block number, calculate MBBCCHHR */
#include "osio.h"

/* our lookup table for the number of tracks per cylinder on a device */
static char trkscyl[16];

/*! \brief Calculates the device address for a given block.
**
**  This function is called to calulate the device track address
**  for any given block number that resides within the dataset
**  as referenced by the dcb parameter.
**
**  The calculated device address is returned in the 8 byte *mbbcchhr*
**  parameter.
**  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**  m  is the 1 byte extent number.
**  bb is the 2 byte bin number (always zero on DASD devices).
**  cc is the 2 byte cylinder number.
**  hh is the 2 byte track number.
**  r  is the 1 byte record number (block) in this track.
**  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
int
osxcalc(DCB *dcb, unsigned blkstrk, unsigned block, char *mbbcchhr)
{
    int         rc      = -1;
    /* get DEBBASIC address from DCB and point to first DEBDASD (extent) */
    DEBBASIC    *basic  = (DEBBASIC*)((unsigned)dcb->dcbdebad & 0x00FFFFFF);
    DEBDASD     *dasd   = (DEBDASD*)((unsigned)basic + sizeof(DEBBASIC));

    /* number of extents for this dataset */
    int         extents = (int) basic->debnmext;

    /* get block size on disk from DCB */
    int         blksize = (int) dcb->dcbblksi;

    /* calculate relative track for this block */
    int         track   = blkstrk ? (block / blkstrk) : 0;

    /* calculate relative record (block) on this relative track */
    int         record  = blkstrk ? (block % blkstrk) : 0;

    /* use the device type to lookup the tracks per cylinder */
    int         devtype = (int) (dcb->dcbdevt & 0x0F);
    int         trkcyl  = (int) trkscyl[devtype];

    int         i;
    int         bb;
    int         cc;
    int         hh;

    if (trkcyl==0) goto quit;   /* unsupported device */

    /* data block record numbers start at 1, so make relative to 1 */
    record++;

#if 0
    wtof("block %u, track %d, record %d", block, track, record);
#endif

    for(i=0; i < extents; i++, dasd++) {
        hh = (int)dasd->debnmtrk;
        if (track < (int)dasd->debnmtrk) {
            /* bin number */
            bb = (int)(dasd->debbinum);
            /* starting cyl */
            cc = (int)(dasd->debstrcc);
            /* starting track + relative track */
            hh = (int)(dasd->debstrhh + track);

            /* adjust cylinder and track values */
            cc += (hh / trkcyl);
            hh = (hh % trkcyl);

            /* return MBBCCHHR values */
            mbbcchhr[0] = (char)i;
            mbbcchhr[1] = (char)(bb >> 8);
            mbbcchhr[2] = (char)(bb & 0XFF);
            mbbcchhr[3] = (char)(cc >> 8);
            mbbcchhr[4] = (char)(cc & 0xFF);
            mbbcchhr[5] = (char)(hh >> 8);
            mbbcchhr[6] = (char)(hh & 0xFF);
            mbbcchhr[7] = (char)record;
#if 0
            wtof("mbbcchhr  %02X %02X%02X %02X%02X %02X%02X %02X",
                mbbcchhr[0], mbbcchhr[1], mbbcchhr[2], mbbcchhr[3],
                mbbcchhr[4], mbbcchhr[5], mbbcchhr[6], mbbcchhr[7]);
#endif
            rc = record;
            goto quit;
        }
        /* track was not in this extent,
        ** reduce track count by number of tracks in this extent
        */
        track -= hh;
    }

quit:
    return rc;
}

/* our lookup table for the number of tracks per cylinder on a device */
static char trkscyl[16] = {
    0,  /* 00 invalid  */
    10, /* 01 2311 DISK STORAGE                         */
    0,  /* 02 2301 PARALLEL DRUM                        */
    0,  /* 03 2303 SERIAL DRUM                          */
    0,  /* 04 2302 DISK STORAGE                         */
    0,  /* 05 2321 DATA CELL STORAGE                    */
    8,  /* 06 2305 DRUM MODEL-1                         */
    8,  /* 07 2305 DRUM MODEL-2                         */
    20, /* 08 2314/2319 DISK STORAGE FACILITY           */
    19, /* 09 3330 DISK STORAGE FACILITY
              3330 MODEL-1, 3330 MODEL-2, 3333 MODEL-1  */
    12, /* 0A 3340/3344 DISK STORAGE FACILITY           */
    30, /* 0B 3350 DISK STORAGE FACILITY
              MODELS A2, B2, AND C2                     */
    12, /* 0C 3375 DISK STORAGE FACILITY                */
    19, /* 0D 3330 MODEL-11 OR 3333 MODEL-11
              DISK STORAGE FACILITY                     */
    15, /* 0E 3380 DISK STORAGE FACILITY                */
    15  /* 0F 3390 DISK STORAGE FACILITY                */
};
