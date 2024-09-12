/*********************************************************************
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Implementation of the SHA-256 hashing algorithm.
              SHA-256 is one of the three algorithms in the SHA2
              specification. The others, SHA-384 and SHA-512, are not
              offered in this implementation.
              Algorithm specification can be found here:
               * http://csrc.nist.gov/publications/fips/fips180-2/fips180-2withchangenotice.pdf
              This implementation uses little endian byte order.
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdlib.h>
#include "sha256.h"
typedef unsigned char	BYTE;
typedef unsigned int	WORD;

void sha256_final(SHA256_CTX *ctx, BYTE hash[])
{
	WORD i;

	i = ctx->datalen;

	// Pad whatever data is left in the buffer.
	if (ctx->datalen < 56) {
		ctx->data[i++] = 0x80;
		while (i < 56)
			ctx->data[i++] = 0x00;
	}
	else {
		ctx->data[i++] = 0x80;
		while (i < 64)
			ctx->data[i++] = 0x00;
		sha256_transform(ctx, ctx->data);
		memset(ctx->data, 0, 56);
	}

	// Append to the padding the total message's length in bits and transform.
	__64_add_u32(&ctx->bitlen, ctx->datalen * 8, &ctx->bitlen);
#if 0
	ctx->data[63] = ctx->bitlen.u32[1];
	ctx->data[62] = ctx->bitlen.u32[1] >> 8;
	ctx->data[61] = ctx->bitlen.u32[1] >> 16;
	ctx->data[60] = ctx->bitlen.u32[1] >> 24;
	ctx->data[59] = ctx->bitlen.u32[0];
	ctx->data[58] = ctx->bitlen.u32[0] >> 8;
	ctx->data[57] = ctx->bitlen.u32[0] >> 16;
	ctx->data[56] = ctx->bitlen.u32[0] >> 24;
#else
	memcpy(&ctx->data[56], &ctx->bitlen, 8);
#endif

	sha256_transform(ctx, ctx->data);

#if 0
	// Since this implementation uses little endian byte ordering and SHA uses big endian,
	// reverse all the bytes when copying the final state to the output hash.
	for (i = 0; i < 4; ++i) {
		hash[i]      = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4]  = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8]  = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (ctx->state[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (ctx->state[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (ctx->state[7] >> (24 - i * 8)) & 0x000000ff;
	}
#else
	/* we're on MVS, so we have big endian byte order already */
	memcpy(hash, ctx->state, SHA256_BLOCK_SIZE);
#endif

}
