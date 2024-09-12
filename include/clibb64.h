#ifndef CLIBB64_H
#define CLIBB64_H

#include <stdint.h>
#include <stdlib.h>

extern const unsigned char __b64tbl[65]				asm("@@B64TBL");

extern unsigned char * 
base64_encode(const unsigned char *src, size_t len, size_t *out_len)	asm("@@B64ENC");

extern unsigned char * 
base64_decode(const unsigned char *src, size_t len, size_t *out_len)	asm("@@B64DEC");

#endif
