/*********************************************************************
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Implementation of the Blowfish encryption algorithm.
              Modes of operation (such as CBC) are not included.
              Algorithm specification can be found here:
               * http://www.schneier.com/blowfish.html
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdlib.h>
#include "blowfish.h"

/****************************** MACROS ******************************/
#define F(x,t) t = keystruct->s[0][(x) >> 24]; \
               t += keystruct->s[1][((x) >> 16) & 0xff]; \
               t ^= keystruct->s[2][((x) >> 8) & 0xff]; \
               t += keystruct->s[3][(x) & 0xff];
#define swap(r,l,t) t = l; l = r; r = t;
#define ITERATION(l,r,t,pval) l ^= keystruct->p[pval]; F(l,t); r^= t; swap(r,l,t);

/*********************** FUNCTION DEFINITIONS ***********************/
void blowfish_encrypt(const unsigned char in[], unsigned char out[], const BLOWFISH_KEY *keystruct)
{
   unsigned int l,r,t; //,i;

   l = (in[0] << 24) | (in[1] << 16) | (in[2] << 8) | (in[3]);
   r = (in[4] << 24) | (in[5] << 16) | (in[6] << 8) | (in[7]);

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
   l ^= keystruct->p[15]; F(l,t); r^= t; //Last iteration has no swap()
   r ^= keystruct->p[16];
   l ^= keystruct->p[17];

   out[0] = l >> 24;
   out[1] = l >> 16;
   out[2] = l >> 8;
   out[3] = l;
   out[4] = r >> 24;
   out[5] = r >> 16;
   out[6] = r >> 8;
   out[7] = r;
}
