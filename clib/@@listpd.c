/* @@LISTPD.C - create PDSLIST array */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include "clibary.h"        /* dynamic array prototypes     */
#include "cliblist.h"       /* __listpd()                   */
#include "clibstr.h"        /* __patmat()                   */

PDSLIST **
__listpd(const char *dataset, const char *filter)
{
    int         rc      = 0;
    FILE        *fp     = 0;
    PDSLIST     **array = 0;
    PDSLIST     *pdslist;
    int         len;
    unsigned    pos;
    unsigned    size;
    char        buf[256];
    char        member[12];

    fp = fopen(dataset, "r,record");
    if (!fp) goto quit;

    do {
        len = fread(buf, 1, sizeof(buf), fp);
        if (len <= 0) goto quit;

        len = *(unsigned short *)buf;
        for(pos = 2; pos < len; pos += size) {
            if (memcmp(&buf[pos], "\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF", 8)==0) {
                /* logical end of directory */
                goto quit;
            }
            size = 12;  /* member,ttr,c = 8+3+1 */
            size += ((buf[pos+11] & 0x1F) * 2); /* + size of user data */

            if (filter) {
                memcpy(member, &buf[pos], 8);
                member[8] = 0;
                strtok(member, " ");
                if (!__patmat(member, filter)) continue;
            }

            pdslist = calloc(1, size);
            pdslist = calloc(1, size);
            if (!pdslist) goto quit;

            memcpy(pdslist, &buf[pos], size);
            rc = arrayadd(&array, pdslist);
            if (rc) {
                free(pdslist);
                goto quit;
            }
        }
    } while(!feof(fp));

quit:
    if (fp) fclose(fp);
    return array;
}
