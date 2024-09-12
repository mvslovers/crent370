#ifndef CLIB64_H
#define CLIB64_H
#include <stdint.h>

/* This macro defines the word size in bytes of the array that constitues the big-number data structure. */
/* Since our target machine has 32 bit integers maximum, we need to use half that for the array */
#define __64_WORD_SIZE 2	/* 2==16 bit array elements */

/* Size of big-numbers in bytes */
#define __64_ARRAY_SIZE    (8 / __64_WORD_SIZE)	/* we only need 64 bit values for time64 so we use 8 bytes */

#define __64_DTYPE                    uint16_t
#define __64_DTYPE_TMP                uint32_t
#define __64_DTYPE_MSB                ((__64_DTYPE_TMP)(0x8000))
#define __64_SPRINTF_FORMAT_STR       "%.04x"
#define __64_SSCANF_FORMAT_STR        "%4hx"
#define __64_MAX_VAL                  ((__64_DTYPE_TMP)0xFFFF)

/* Data-holding structure: array of __64_DTYPEs */
typedef union {
	uint64_t	u64;					/* used internally for bit operations and assigments */
	uint32_t	u32[2];					/* used internally for initialization */
	__64_DTYPE array[__64_ARRAY_SIZE];	/* used internally for arithmatic operations */
} __64;

/* Tokens returned by __64_cmp() for value comparison */
enum { __64_SMALLER = -1, __64_EQUAL = 0, __64_LARGER = 1 };


/* Initialization functions: */
void __64_init(__64* n) 								asm("@@64INIT");
void __64_from_i32(__64* n, int32_t i32) 				asm("@@64FI32");
void __64_from_u32(__64* n, uint32_t u32) 				asm("@@64FU32");
void __64_from_u64(__64* n, uint64_t u64)				asm("@@64FU64");

int32_t __64_to_i32(__64* n) 							asm("@@64TI32");
uint32_t __64_to_u32(__64* n) 							asm("@@64TU32");
uint64_t __64_to_u64(__64 *n)							asm("@@64TU64");

void __64_from_string(__64* n, char* str)				asm("@@64FSTR");
void __64_to_string(__64* n, char* str, int maxsize)	asm("@@64TSTR");

/* Basic arithmetic operations: */
void __64_add(__64* a, __64* b, __64* c)				asm("@@64ADD"); 	/* c = a + b */
void __64_add_i32(__64* a, int32_t b, __64* c)			asm("@@64AI32");	/* c = a + b */
void __64_add_u32(__64* a, uint32_t b, __64* c)			asm("@@64AU32");	/* c = a + b */
void __64_add_u64(__64* a, uint64_t b, __64* c)			asm("@@64AU64");	/* c = a + b */

void __64_sub(__64* a, __64* b, __64* c)				asm("@@64SUB"); 	/* c = a - b */
void __64_sub_i32(__64* a, int32_t b, __64* c)   		asm("@@64SI32");	/* c = a - b */
void __64_sub_u32(__64* a, uint32_t b, __64* c)   		asm("@@64SU32");	/* c = a - b */
void __64_sub_u64(__64* a, uint64_t b, __64* c)			asm("@@64SU64");	/* c = a - b */

void __64_mul(__64* a, __64* b, __64* c)				asm("@@64MUL"); 	/* c = a * b */
void __64_mul_i32(__64 *a, int32_t b, __64* c)   		asm("@@64MI32");	/* c = a * b */
void __64_mul_u32(__64 *a, uint32_t b, __64* c)   		asm("@@64MU32");	/* c = a * b */
void __64_mul_u64(__64 *a, uint64_t b, __64 *c)			asm("@@64MU64");	/* c = a * b */

void __64_div(__64* a, __64* b, __64* c)				asm("@@64DIV"); 	/* c = a / b */
void __64_div_i32(__64* a, int32_t b, __64* c)			asm("@@64DI32");	/* c = a / b */
void __64_div_u32(__64* a, uint32_t b, __64* c)			asm("@@64DU32");	/* c = a / b */
void __64_div_u64(__64* a, uint64_t b, __64* c)			asm("@@64DU64");	/* c = a / b */

void __64_mod(__64* a, __64* b, __64* c)				asm("@@64MOD"); 	/* c = a % b */
void __64_mod_i32(__64* a, int32_t b, __64* c)   		asm("@@64QI32");	/* c = a % b */
void __64_mod_u32(__64* a, uint32_t b, __64* c)   		asm("@@64QU32");	/* c = a % b */
void __64_mod_u64(__64* a, uint64_t b, __64* c)			asm("@@64QU64");	/* c = a % b */

void __64_divmod(__64* a, __64* b, __64* c, __64* d)	asm("@@64DMOD");	/* c = a/b, d = a%b */
void __64_divmod_i32(__64* a, int32_t b, __64* c, __64* d)	asm("@@64VI32");/* c = a/b, d = a%b */
void __64_divmod_u32(__64* a, uint32_t b, __64* c, __64* d)	asm("@@64VU32");/* c = a/b, d = a%b */
void __64_divmod_u64(__64* a, uint64_t b, __64* c, __64* d)	asm("@@64VU64");/* c = a/b, d = a%b */

/* Bitwise operations: */
void __64_and(__64* a, __64* b, __64* c)				asm("@@64AND"); 	/* c = a & b */
void __64_and_i32(__64* a, int32_t b, __64* c)			asm("@@64NI32"); 	/* c = a & b */
void __64_and_u32(__64* a, uint32_t b, __64* c)			asm("@@64NU32"); 	/* c = a & b */
void __64_and_u64(__64* a, uint64_t b, __64* c)			asm("@@64NU64"); 	/* c = a & b */

void __64_or(__64* a, __64* b, __64* c)					asm("@@64OR");  	/* c = a | b */
void __64_or_i32(__64* a, int32_t b, __64* c)			asm("@@64OI32");  	/* c = a | b */
void __64_or_u32(__64* a, uint32_t b, __64* c)			asm("@@64OU32");  	/* c = a | b */
void __64_or_u64(__64* a, uint64_t b, __64* c)			asm("@@64OU64");  	/* c = a | b */

void __64_xor(__64* a, __64* b, __64* c)				asm("@@64XOR"); 	/* c = a ^ b */
void __64_xor_i32(__64* a, int32_t b, __64* c)			asm("@@64XI32"); 	/* c = a ^ b */
void __64_xor_u32(__64* a, uint32_t b, __64* c)			asm("@@64XU32"); 	/* c = a ^ b */
void __64_xor_u64(__64* a, uint64_t b, __64* c)			asm("@@64XU64"); 	/* c = a ^ b */

void __64_lshift(__64* a, __64* b, int nbits)			asm("@@64LSFT"); 	/* b = a << nbits */
void __64_rshift(__64* a, __64* b, int nbits)			asm("@@64RSFT"); 	/* b = a >> nbits */

/* Special operators and comparison */
int  __64_cmp(__64* a, __64* b)				asm("@@64CMP"); /* Compare: returns LARGER, EQUAL or SMALLER */
int  __64_cmp_i32(__64* a, int32_t b)		asm("@@64CI32");/* Compare: returns LARGER, EQUAL or SMALLER */
int  __64_cmp_u32(__64* a, uint32_t b)		asm("@@64CU32");/* Compare: returns LARGER, EQUAL or SMALLER */
int  __64_cmp_u64(__64* a, uint64_t b)		asm("@@64CU64");/* Compare: returns LARGER, EQUAL or SMALLER */

int  __64_is_zero(__64* n)					asm("@@64IS0"); /* For comparison with zero */
void __64_inc(__64* n)						asm("@@64INC"); /* Increment: add one to n */
void __64_dec(__64* n)                      asm("@@64DEC"); /* Decrement: subtract one from n */
void __64_pow(__64* a, __64* b, __64* c)	asm("@@64POW"); /* Calculate a^b -- e.g. 2^10 => 1024 */
void __64_isqrt(__64* a, __64* b)			asm("@@64ISQR");/* Integer square root -- e.g. isqrt(5) => 2*/
void __64_copy(__64* src, __64* dst)		asm("@@64COPY");/* Copy src into dst -- dst := src */
#define __64_assign(dst,src) __64_copy((src),(dst))

/* Functions for shifting number in-place. */
void __64_lshift_one_bit(__64* a)						asm("@@64LSH1");
void __64_rshift_one_bit(__64* a)						asm("@@64RSH1");
void __64_lshift_word(__64* a, int nwords)				asm("@@64LSHW");
void __64_rshift_word(__64* a, int nwords)				asm("@@64RSHW");

#endif /* CLIB64_H */
