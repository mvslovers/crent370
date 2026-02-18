/* TZSET.C */
#include <stdlib.h>
#include <stddef.h>
#include "clibenv.h"
#include "clibcrt.h"

void
tzset(void)
{
    int 	*cvt;
    char	*tz;
    char    *p;
    CLIBCRT *crt;
    int     tzoffset;
	int		rem;
	int		neg;
	int		tmp;

    tz = getenv("tz");
    if (!tz) tz = getenv("TZ");

    if (tz) {
		/* assume TZ is "[-]HH[:MM][:SS]" format */
		p = tz;
		tzoffset = 0;
		neg = 0;
		/* wtof("%s: procesing TZ=\"%s\"", __func__, p); */

		while (*p=='-') {
			neg = 1;
			p++;
			/* wtof("%s: neg=1", __func__); */
		}

		if (isdigit(*p)) {
			/* hours */
			tmp = atoi(p);
			/* wtof("%s: hours=%d", __func__, tmp); */
			tzoffset += tmp * 60 * 60;
			p = strchr(p, ':');

			if (p) {
				/* minutes */
				p++;
				tmp = atoi(p);
				/* wtof("%s: minutes=%d", __func__, tmp); */
				tzoffset += tmp * 60;
				p = strchr(p, ':');
			}

			if (p) {
				/* seconds */
				p++;
				tmp = atoi(p);
				/* wtof("%s: seconds=%d", __func__, tmp); */
				tzoffset += tmp;
			}

			if (neg) tzoffset = 0 - tzoffset;
			/* wtof("%s: tzoffset=%d", __func__, tzoffset); */
			goto done;
		}

		wtof("%s: Invalid time zone format in TZ variable \"%s\"", __func__, tz);
		wtof("%s: Expected format is TZ=[-]HH[:MM][:SS]", __func__);
		wtof("%s: Defaulting to time zone offset calculated from CVTTZ", __func__);
    }

	/* calculate time zone offset from system CVTTZ value */
    cvt = *(int**)16;                      		/* get CVT pointer from PSA */
    tzoffset = (int)(cvt[0x130/4] * 1.0485765); /* convert CVTTZ to seconds from UTC */

	/* attempt to correct for cast/rounding errors */
	/* wtof("%s: tzoffset=%d", __func__, tzoffset); */
    if (tzoffset < 0) {
		rem = (-tzoffset) % 10;
		/* wtof("%s: rem=%d", __func__, rem); */

		if (rem) tzoffset -= (10 - rem); /* correct tzoffset */
		/* wtof("%s: tzoffset=%d", __func__, tzoffset); */
	}
	else if (tzoffset > 0) {
		rem = tzoffset % 10;
		/* wtof("%s: rem=%d", __func__, rem); */

		if (rem) tzoffset += (10 - rem); /* correct tzoffset */
		/* wtof("%s: tzoffset=%d", __func__, tzoffset); */
	}

done:
    __tzset(tzoffset);
}
