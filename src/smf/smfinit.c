/* smfinit.c
** smf_init() - fill standard 18-byte SMF record header.
** Caller must bzero() the record before calling.
**
** Sets: reclen, rectype, segdesc=0, sysiflags=2,
**       time (1/100s since midnight via localtime),
**       date (packed decimal 0YYDDDF from localtime),
**       sysid (from __smfid()).
*/
#include <string.h>
#include <time.h>
#include "clibsmf.h"

__asm__("\n&FUNC    SETC 'smf_init'");
void
smf_init(void *record, unsigned short reclen, unsigned char rectype)
{
    SMF_HEADER          *hdr = (SMF_HEADER *)record;
    const unsigned char *sid;
    time_t              now;
    struct tm           *tm;
    unsigned long       hundredths;
    int                 yy;
    int                 ddd;

    hdr->reclen    = reclen;
    hdr->segdesc   = 0;
    hdr->sysiflags = 2;       /* subtypes present */
    hdr->rectype   = rectype;

    /* get current time */
    now = time(0);
    tm  = localtime(&now);

    /* Time: 1/100 seconds since midnight */
    hundredths = (unsigned long)(tm->tm_hour * 360000L
                               + tm->tm_min  * 6000L
                               + tm->tm_sec  * 100L);
    hdr->time[0] = (unsigned char)(hundredths >> 24);
    hdr->time[1] = (unsigned char)(hundredths >> 16);
    hdr->time[2] = (unsigned char)(hundredths >> 8);
    hdr->time[3] = (unsigned char)(hundredths);

    /* Date: packed decimal 0YYDDDF */
    yy  = tm->tm_year % 100;          /* 2-digit year   */
    ddd = tm->tm_yday + 1;            /* 1-based day    */

    /* dtepref: 0 for 19xx, 1 for 20xx+ */
    hdr->dtepref = (tm->tm_year >= 100) ? 1 : 0;

    /* encode as packed decimal: 0x0YYDDDC
    ** F nibble = 0xC (positive sign) per IBM convention */
    hdr->date[0] = (unsigned char)(((yy / 10) << 4) | (yy % 10));
    hdr->date[1] = (unsigned char)(((ddd / 100) << 4) | ((ddd / 10) % 10));
    hdr->date[2] = (unsigned char)(((ddd % 10) << 4) | 0x0C);

    /* SysID: from SMCA */
    sid = __smfid();
    if (sid) memcpy(hdr->sysid, sid, 4);
}
