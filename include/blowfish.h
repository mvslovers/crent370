/*********************************************************************
* Filename:   blowfish.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding Blowfish implementation.
*********************************************************************/

#ifndef BLOWFISH_H
#define BLOWFISH_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>

/****************************** MACROS ******************************/
#define BLOWFISH_BLOCK_SIZE 8           // Blowfish operates on 8 bytes at a time

/**************************** DATA TYPES ****************************/
typedef struct {
	unsigned int	p[18];
	unsigned int	s[4][256];
} BLOWFISH_KEY;

/*********************** FUNCTION DECLARATIONS **********************/
void blowfish_key_setup(const unsigned char user_key[], BLOWFISH_KEY *keystruct, size_t len)			asm("BFISHKEY");
void blowfish_encrypt(const unsigned char in[], unsigned char out[], const BLOWFISH_KEY *keystruct)		asm("BFISHENC");
void blowfish_decrypt(const unsigned char in[], unsigned char out[], const BLOWFISH_KEY *keystruct)		asm("BFISHDEC");

#endif   // BLOWFISH_H
