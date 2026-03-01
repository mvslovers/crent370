/* SHA256F.C
** SHA-256 finalization (padding and final hash output).
** Based on Brad Conte's crypto-algorithms (public domain).
*/
#include <string.h>
#include "sha256.h"

void
sha256_final(SHA256_CTX *ctx, unsigned char hash[])
{
    unsigned int i;
    __64 bits;
    __64 shifted;

    i = ctx->datalen;

    /* pad whatever data is left in the buffer */
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

    /* append to the padding the total message length in bits */
    __64_add_u32(&ctx->bitlen, ctx->datalen * 8, &bits);

    /* store big-endian 64-bit length in data[56..63] */
    __64_rshift(&bits, &shifted, 56);
    ctx->data[56] = (unsigned char)__64_to_u32(&shifted);
    __64_rshift(&bits, &shifted, 48);
    ctx->data[57] = (unsigned char)__64_to_u32(&shifted);
    __64_rshift(&bits, &shifted, 40);
    ctx->data[58] = (unsigned char)__64_to_u32(&shifted);
    __64_rshift(&bits, &shifted, 32);
    ctx->data[59] = (unsigned char)__64_to_u32(&shifted);
    __64_rshift(&bits, &shifted, 24);
    ctx->data[60] = (unsigned char)__64_to_u32(&shifted);
    __64_rshift(&bits, &shifted, 16);
    ctx->data[61] = (unsigned char)__64_to_u32(&shifted);
    __64_rshift(&bits, &shifted, 8);
    ctx->data[62] = (unsigned char)__64_to_u32(&shifted);
    ctx->data[63] = (unsigned char)__64_to_u32(&bits);

    sha256_transform(ctx, ctx->data);

    /* produce the final hash value (big-endian) */
    for (i = 0; i < 4; ++i) {
        hash[i]      = (unsigned char)(ctx->state[0] >> (24 - i * 8));
        hash[i + 4]  = (unsigned char)(ctx->state[1] >> (24 - i * 8));
        hash[i + 8]  = (unsigned char)(ctx->state[2] >> (24 - i * 8));
        hash[i + 12] = (unsigned char)(ctx->state[3] >> (24 - i * 8));
        hash[i + 16] = (unsigned char)(ctx->state[4] >> (24 - i * 8));
        hash[i + 20] = (unsigned char)(ctx->state[5] >> (24 - i * 8));
        hash[i + 24] = (unsigned char)(ctx->state[6] >> (24 - i * 8));
        hash[i + 28] = (unsigned char)(ctx->state[7] >> (24 - i * 8));
    }
}
