#ifndef CLIBECB_H
#define CLIBECB_H

#include <clibary.h>

typedef unsigned int        ECB;

#define ECB_WAITING_BIT     0x80000000
#define ECB_POSTED_BIT      0x40000000
#define ECB_VALUE_MASK      0x3FFFFFFF

/* ecb_wait() - wait for ECB to be posted */
int ecb_wait(ECB *ecb)                                                                  asm("@@ECBWT");

/* ecb_timed_wait() - wait for ecb to be posted, after bintvl expires ecb will be posted with postcode value */
int ecb_timed_wait(ECB *ecb, unsigned bintvl, unsigned postcode)                        asm("@@ECBTW");

/* ecb_waitlist() - wait for any ecb in the ecb list to be posted, last ecb address must have high bit on */
int ecb_waitlist(ECB **ecblist)                                                         asm("@@ECBWL");

/* ecb_waitarray() - wait for any ecb in the ecb array to be posted */
int ecb_waitarray(ECB **ecbarray)                                                       asm("@@ECBWA");

/* ecb_timed_waitlist() wait for any ecb in the ecb list to be posted,
   if timeecb is not null then after bintvl expires the timeecb will be posted with postcode value */
int ecb_timed_waitlist(ECB **ecblist, ECB *timeecb, unsigned bintvl, unsigned postcode) asm("@@ECBTWL");

/* ecb_timed_waitarray() wait for any ecb in the ecb array to be posted,
   if timeecb is not null then after bintvl expires the timeecb will be posted with postcode value */
int ecb_timed_waitarray(ECB **ecblist, ECB *timeecb, unsigned bintvl, unsigned postcode) asm("@@ECBTWA");

int ecb_post(ECB *ecb, unsigned postcode)                                               asm("@@ECBPST");

#endif /* CLIBECB_H */
