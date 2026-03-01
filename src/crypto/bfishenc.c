/* BFISHENC.C
** Blowfish block encryption.
** Based on Brad Conte's crypto-algorithms (public domain).
*/
#include "blowfish.h"

#define F(x,t) t = keystruct->s[0][(x) >> 24]; \
               t += keystruct->s[1][((x) >> 16) & 0xff]; \
               t ^= keystruct->s[2][((x) >> 8) & 0xff]; \
               t += keystruct->s[3][(x) & 0xff];

#define swap(r,l,t) t = l; l = r; r = t;

#define ITERATION(l,r,t,pval) \
    l ^= keystruct->p[pval]; F(l,t); r ^= t; swap(r,l,t);

void
blowfish_encrypt(const unsigned char in[], unsigned char out[],
                 const BLOWFISH_KEY *keystruct)
{
    unsigned int l, r, t;

    l = ((unsigned int)in[0] << 24) | ((unsigned int)in[1] << 16)
      | ((unsigned int)in[2] << 8)  | (unsigned int)in[3];
    r = ((unsigned int)in[4] << 24) | ((unsigned int)in[5] << 16)
      | ((unsigned int)in[6] << 8)  | (unsigned int)in[7];

    ITERATION(l,r,t,0);
    ITERATION(l,r,t,1);
    ITERATION(l,r,t,2);
    ITERATION(l,r,t,3);
    ITERATION(l,r,t,4);
    ITERATION(l,r,t,5);
    ITERATION(l,r,t,6);
    ITERATION(l,r,t,7);
    ITERATION(l,r,t,8);
    ITERATION(l,r,t,9);
    ITERATION(l,r,t,10);
    ITERATION(l,r,t,11);
    ITERATION(l,r,t,12);
    ITERATION(l,r,t,13);
    ITERATION(l,r,t,14);
    l ^= keystruct->p[15]; F(l,t); r ^= t;
    r ^= keystruct->p[16];
    l ^= keystruct->p[17];

    out[0] = (unsigned char)(l >> 24);
    out[1] = (unsigned char)(l >> 16);
    out[2] = (unsigned char)(l >> 8);
    out[3] = (unsigned char)l;
    out[4] = (unsigned char)(r >> 24);
    out[5] = (unsigned char)(r >> 16);
    out[6] = (unsigned char)(r >> 8);
    out[7] = (unsigned char)r;
}
