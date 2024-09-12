#ifndef SHA256_H
#define SHA256_H
/*********************************************************************
* Filename:   sha256.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding SHA1 implementation.
*********************************************************************/
#include <stddef.h>
#include <clib64.h>

#define SHA256_BLOCK_SIZE 32            /* SHA256 outputs a 32 byte digest */

typedef struct {
	__64				bitlen;
	unsigned int  		datalen;
	unsigned int		state[8];
	unsigned char 		data[64];
} SHA256_CTX;

void sha256_init(SHA256_CTX *ctx)									asm("SHA256I");
void sha256_update(SHA256_CTX *ctx, const unsigned char data[], size_t len)	asm("SHA256U");
void sha256_final(SHA256_CTX *ctx, unsigned char hash[])						asm("SHA256F");

void sha256_transform(SHA256_CTX *ctx, const unsigned char data[])			asm("SHA256T");

#endif   // SHA256_H
