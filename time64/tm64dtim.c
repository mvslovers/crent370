/* DIFFTIME64.C */
#include <time.h>
#include <time64.h>

double difftime64(time64_t time1, time64_t time0)
{
	time64_t	*t1 = &time1;
	time64_t	*t0 = &time0;
	time64_t	tmp;
	double		result;
	int			neg;

	if (__64_cmp(t1, t0) == __64_SMALLER) {
		/* time1 < time0 */
		neg = 1;
		/* swap pointers to time values */
		t1 = &time0;
		t0 = &time1;
	}
	else {
		neg = 0;
	}

	/* subtract time values to obtain difference, result in tmp */
	__64_sub(t1, t0, &tmp);
	result = ((double)(tmp.u32[1]));

	if (neg) {
		/* make result negative value */
		result = ((double)0.0) - result;
	}

    return result;
}

