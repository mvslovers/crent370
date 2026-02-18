#include <stdio.h>
#include <string.h>
#include <clib64.h>
#include <clibwto.h>

__asm__("\n&FUNC    SETC 'test_return_from_ptr'");
static __64 test_return_from_ptr(__64 *value)
{
	return *value;
}

__asm__("\n&FUNC    SETC 'test_return_from_struct'");
static __64 test_return_from_struct(__64 value)
{
	return value;
}

__asm__("\n&FUNC    SETC 'main'");
int main(int argc, char **argv) 
{
	__64	u10;
	__64	u16;
	__64	u100;
	__64	u65535;
	__64	u65536;
	__64	result;
	__64	tmp;
	__64	tmp2;
	int		i;
	char	buf[256];

	__64	Uresult;

	wtof("__64_lshift()");
	__64_from_u64(&result,0xffeeddccbbaa9988ULL);
	wtodumpf(&result, sizeof(__64), "starting result value");
	tmp.u64 = __64_to_u64(&result);
	wtodumpf(&tmp, sizeof(__64), "tmp.u64=__64_to_u64(result)");

	for(i=0; i < 8; i++) {
		__64_lshift(&result, &result, 8);
		wtodumpf(&result, sizeof(__64), "result after shift 8 bits");
	}
	wtof("=========================================================");

	wtof("__64_rshift_one_bit()");
#if 0
	result.u64 = 0x8000000000000000ULL;
#else
	__64_from_u32(&result, 0x80000000);
	__64_lshift_word(&result, 2);
#endif
	Uresult.u64 = result.u64;
	wtodumpf(&Uresult, sizeof(__64), "Uresult value");
	wtodumpf(&result, sizeof(__64), "starting result value");
	for(i=0; i<64; i++) {
		__64_rshift_one_bit(&result);
		Uresult.u64 >>=1;
		wtodumpf(&Uresult, sizeof(__64), "Uresult after right shift 1 bit");
		wtodumpf(&result, sizeof(__64), "result after __64_rshift_one_bit()");
	}

#if 0
	__64_init(&u10);
	u10.array[3] = 10;
	wtodumpf(&u10, sizeof(__64), "u10");
	tmp = test_return_from_ptr(&u10);
	wtodumpf(&tmp, sizeof(__64), "tmp=test_return_from_ptr(&u10)");
	tmp2 = test_return_from_struct(u10);
	wtodumpf(&tmp2, sizeof(__64), "tmp2=test_return_from_struct(u10)");
	wtof("=========================================================");

	wtof("__64_lshift()");
	__64_from_int(&tmp, 0x11);
	__64_from_int(&tmp2, 0x11);
	for(i=0; i < 65; i++) {
		wtodumpf(&tmp, sizeof(__64), "tmp");
		__64_lshift(&tmp, &result, i);
		wtodumpf(&result, sizeof(__64), "result=__64_lshift(tmp,result,%d)", i);
		__64_mul(&tmp, &tmp2, &tmp);
		wtof("---------------------------------------------------------");
	}
	wtof("=========================================================");
	wtof("__64_rshift()");
	__64_from_int(&tmp, 0xCCCCCCCC);
	__64_copy(&tmp, &tmp2);
	__64_lshift_word(&tmp,2);
	__64_add(&tmp, &tmp2, &tmp);
	for(i=0; i < 65; i++) {
		wtodumpf(&tmp, sizeof(__64), "tmp");
		__64_rshift(&tmp, &result, i);
		wtodumpf(&result, sizeof(__64), "result=__64_rshift(tmp,result,%d)", i);
		__64_add(&tmp, &tmp2, &tmp);
		wtof("---------------------------------------------------------");
	}
	wtof("=========================================================");

	__64_init(&u16);
	u16.array[3] = 16;
	wtodumpf(&u16, sizeof(__64), "u16");
	wtof("=========================================================");

	__64_init(&u100);
	u100.array[3] = 100;
	wtodumpf(&u100, sizeof(__64), "u100");
	wtof("=========================================================");

	__64_init(&u65535);
	u65535.array[3] = 65535;
	wtodumpf(&u65535, sizeof(__64), "u65535");
	wtof("=========================================================");

	__64_init(&u65536);
	u65536.array[2] = 1;
	wtodumpf(&u65536, sizeof(__64), "u65536");
	wtof("=========================================================");
#endif
#if 0
	__64_from_int(&result, 255);
	wtodumpf(&result, sizeof(__64), "result=255");
	wtof("=========================================================");

	for(i=0; i < 64; i++) {
		__64_lshift_one_bit(&result);
		wtodumpf(&result, sizeof(__64), "result left shift one bit");
	}
	wtof("=========================================================");

	__64_from_int(&result, 255);
	wtodumpf(&result, sizeof(__64), "result=255");

	for(i=0; i < 4; i++) {
		__64_lshift_word(&result, 1);
		wtodumpf(&result, sizeof(__64), "result left shift word");
	}
	wtof("=========================================================");
#endif
#if 0
	__64_from_int(&tmp, 0xFFFFFFFF);
	wtodumpf(&tmp, sizeof(__64), "tmp=0xFFFFFFFF");
	wtof("=========================================================");

	__64_mul(&tmp, &u65536, &result);
	wtodumpf(&result, sizeof(__64), "result 0xFFFFFFFF * u65536");
	wtof("=========================================================");

	__64_copy(&result, &tmp);
	__64_mul(&tmp, &u65536, &result);
	wtodumpf(&result, sizeof(__64), "result 0xFFFFFFFF0000 * u65536");
	wtof("=========================================================");

	wtof("__64_rshift_one_bit()");
	__64_from_int(&result, 0x80000000);
	__64_lshift_word(&result, 2);
	wtodumpf(&result, sizeof(__64), "starting result value");
	for(i=0; i<64; i++) {
		__64_rshift_one_bit(&result);
		wtodumpf(&result, sizeof(__64), "result after __64_rshift_one_bit()");
	}
#endif
#if 0
	wtof("=========================================================");

	wtof("__div() 0xFFFFFFFF, 0x00000010, result");
	__64_from_int(&tmp, 0xFFFFFFFF);
	wtodumpf(&tmp, sizeof(__64), "tmp=0xFFFFFFFF");
	__64_from_int(&u16, 0x10);
	wtodumpf(&u16, sizeof(__64), "u16=0x00000010");
	__64_div(&tmp, &u16, &result);
	wtodumpf(&result, sizeof(__64), "result");
	wtof("=========================================================");
#endif
#if 0
	wtof("__divmod() 0xFFFFFFFF, 0x00000010, tmp2, result");
	__64_from_int(&tmp, 0xFFFFFFFF);
	wtodumpf(&tmp, sizeof(__64), "tmp=0xFFFFFFFF");
	__64_from_int(&u16, 0x10);
	wtodumpf(&u16, sizeof(__64), "u16=0x00000010");
	__64_divmod(&tmp, &u16, &tmp2, &result);
	wtodumpf(&tmp2, sizeof(__64), "tmp2");
	wtodumpf(&result, sizeof(__64), "result");
	wtof("=========================================================");
#endif

#if 0
	wtof("__64_sub() u65535, u100, result");
	__64_sub(&u65535, &u100, &result);
	wtodumpf(&result, sizeof(__64), "result u65535 - u100");
	wtof("=========================================================");

	wtof("__64_add() u65535, u100, result");
	__64_add(&u65535, &u100, &result);
	wtodumpf(&result, sizeof(__64), "result u65535 + u100");
	wtof("=========================================================");

	wtof("__64_sub() loop 0xFFFFFFFFFFFF0000, u100, result");
	__64_init(&result);
	result.array[0] = 65535;
	result.array[1] = 65535;
	result.array[2] = 65535;
	for(i=0; i < 128; i++) {
		__64_sub(&result, &u65536, &result);
		wtodumpf(&result, sizeof(__64), "result -= u65536");
	}
	wtof("=========================================================");
#endif

#if 0
	__64_from_int(&u10, 10);
	wtodumpf(&u10, sizeof(__64), "u10");

	__64_from_int(&u100, 100);
	wtodumpf(&u100, sizeof(__64), "u100");

	__64_from_int(&u65535, 65535);
	wtodumpf(&u65535, sizeof(__64), "u65535");

	__64_from_int(&u65536, 65536);
	wtodumpf(&u65536, sizeof(__64), "u65536");
#endif
#if 0
	__64_to_string(&u10, buf, sizeof(buf));
	printf("u10 = %s\n", buf);

	__64_to_string(&u100, buf, sizeof(buf));
	printf("u100 = %s\n", buf);

	__64_to_string(&u65535, buf, sizeof(buf));
	printf("u65535 = %s\n", buf);
#endif
	return 0;
}

