/* SHA256I.C
** SHA-256 context initialization.
** Based on Brad Conte's crypto-algorithms (public domain).
*/
#include "sha256.h"

void
sha256_init(SHA256_CTX *ctx)
{
    ctx->datalen = 0;
    __64_init(&ctx->bitlen);
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}
