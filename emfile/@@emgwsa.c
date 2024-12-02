#include "emfilei.h"

static EMFILEWSA static_config = {
	EMFILEWSA_EYE,			/* 00 eye catcher					*/
	EMFILE_SPACE_TRACK,		/* 08 EMFILE_SPACE_ TRACK or CYL	*/
	4096,					/* 0C block and lrecl size			*/
	15,						/* 10 primary track/cyl				*/
	15,						/* 14 secondary track/cyl			*/
	NULL					/* 18 volume serial number			*/
};							/* 1C (28 bytes)					*/
#define EMFILEWSA_KEY (void*)(&static_config)
#define EMFILEWSA_LEN sizeof(static_config)

EMFILEWSA *emfile_get_wsa(void)
{
	EMFILEWSA	*wsa = (EMFILEWSA*) __wsaget(EMFILEWSA_KEY, EMFILEWSA_LEN);

	return wsa;
}
