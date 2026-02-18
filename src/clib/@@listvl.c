#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include "clibary.h"        /* dynamic array prototypes     */
#include "clibdscb.h"       /* DSCB structs and prototypes  */
#include "cliblist.h"       /* __listc()                    */
#include "clibstr.h"        /* __patmat()                   */
#include "iecvucb.h"		/* UCBDASD						*/
#include "cvt.h"			/* CVT							*/

static int in_vollist(VOLLIST **vollist, const char *vol);
static FILE *open_vatlst(const char *vatlst);
static int get_comment(char *buf, VOLLIST **vollist);
static int get_lspace(VOLLIST *vol);
static unsigned get_dasdtype(UCBDASD *ucbdasd);

/* __listvl() - return list of volumes matching filter or ALL if
** 		filter is NULL.
**		if dolspace is not zero then request volume free space information.
**		if vatlst is specified the comments from the vatlst is returned.
**		Note: if vatlst is a member name then SYS1.PARMLIB(vatlst) will
**		be opened otherwise vatlst should be a dataset(member) name for
**		the vatlst dataset or NULL.
*/
VOLLIST **__listvl(	const char *filter, int dolspace, const char *vatlst) 
{
	VOLLIST	**vollist	= NULL;
	VOLLIST *vol		= NULL;
	CVT 	*cvt		= CVTPTR;
	UCBLIST *ucblist	= cvt->cvtilk2;	/* get ptr to list of UCB's	*/
	UCBDASD	*ucbdasd;
	int		i;
	
	// wtof("%s: start", __func__);
	// wtof("%s: cvt=%p ucblist=%p", __func__, cvt, ucblist);
	// wtodumpf(ucblist, 8192, "%s: ucblist", __func__);
	
	/* scan list of UCB's */
	for(i=0; ucblist->ucb[i] != UCBEOL; i++) {
		/* Get UCB address from list */
		unsigned ucbaddr = ucblist->ucb[i];
		ucbdasd = (UCBDASD*)(ucbaddr);
		if (!ucbdasd) continue;								/* skip NULL UCB address */

		// wtodumpf(ucbdasd, sizeof(UCBDASD), "%s: ucbdasd", __func__);

		/* Make sure this is a DASD UCB */
		if (!(ucbdasd->ucbtype[2] == UCBTYPEDA)) {
			// wtof("%s: NOT DASD continue", __func__);
			continue;	/* NOT DASD */
		}
		if (ucbdasd->ucbtype[3] == UCBTYPE2321) {
			// wtof("%s: IS 2321 continue", __func__);
			continue;	/* skip 2321 data cell */
		}

		/* Make sure this volume is ONLINE */
		if (!(ucbdasd->ucbstat & UCBONLI)) {
			// wtof("%s: NOT ONLINE continue", __func__);
			continue;		/* NOT ONLINE */
		}

		/* filter volser is needed */
		if (filter && *filter) {
			char 	volser[7];
			
			memcpy(volser, ucbdasd->ucbvol, 6);
			volser[6] = 0;
            if (!__patmat(volser, filter)) continue;
		}

		/* Skip if we've already processsed this UCB */
		if (in_vollist(vollist, ucbdasd->ucbvol)) {
			// wtof("%s: in_vollist() continue", __func__);
			continue;	/* skip if in vollist */
		}
		
		/* Build vollist entry */
		vol = (VOLLIST*) calloc(1, sizeof(VOLLIST));
		if (!vol) {
			wtof("%s: out of memory", __func__);
			break;
		}
		
		/* add vol to vollist array */
		array_add(&vollist, vol);
		
		/* populate UCB info for this volume */
		memcpy(vol->volser, ucbdasd->ucbvol, 6);

		/* map UCB flags to vollist flags */
		if (ucbdasd->ucbstat & UCBONLI) 	vol->status |= VOLLIST_STATUS_ONLI;
		if (ucbdasd->ucbstat & UCBRESV) 	vol->status |= VOLLIST_STATUS_RESV;
		if (ucbdasd->ucbstat & UCBPRES) 	vol->status |= VOLLIST_STATUS_PRES;
		if (ucbdasd->ucbstab & UCBSTABPRV)	vol->status |= VOLLIST_STATUS_PRV;
		if (ucbdasd->ucbstab & UCBSTABPUB)	vol->status |= VOLLIST_STATUS_PUB;
		if (ucbdasd->ucbstab & UCBSTABSTR)	vol->status |= VOLLIST_STATUS_STG;

		/* save this UCB address */
		vol->ucbdasd = ucbdasd;
		
		/* get channel and device values */
		vol->cuu = ucbdasd->ucbchan;
		vol->dasdtype = get_dasdtype(ucbdasd);

		if (dolspace) {
			get_lspace(vol);
		}
	}
	
	while (vatlst && *vatlst) {
		FILE *fp = open_vatlst(vatlst);
		char *p  = NULL;
		char buf[256] = {0};
		
		if (!fp) break;

		/* read VATLST records and get comments for our vollist */
		for(p=fgets(buf, sizeof(buf), fp); p; p=fgets(buf, sizeof(buf), fp)) {
			get_comment(buf, vollist);
			memset(buf, 0, sizeof(buf));
		}
		
		fclose(fp);
		break;
	}
	
quit:
	// wtof("%s: exit vollist=%p", __func__, vollist);
	return vollist;
}

static unsigned get_dasdtype(UCBDASD *ucbdasd)
{
	unsigned	dasdtype = 0;

	switch(ucbdasd->ucbtype[3]) {
		case 0x01: dasdtype = 0x2311; break;
		case 0x06: dasdtype = 0x2305; break; /* 2305-1 */
		case 0x07: dasdtype = 0x2305; break; /* 2305-2 */
		case 0x08: dasdtype = 0x2314; break;
		case 0x09: dasdtype = 0x3330; break;
		case 0x0A: dasdtype = 0x3340; break;
		case 0x0B: dasdtype = 0x3350; break;
		case 0x0C: dasdtype = 0x3375; break;
		case 0x0D: dasdtype = 0x3330; break; /* 3330-1 */
		case 0x0E: dasdtype = 0x3380; break;
		case 0x0F: dasdtype = 0x3390; break;
	}

	return dasdtype;
}

static int get_lspace(VOLLIST *vol)
{
	int			rc			= 0;
	UCBDASD 	*ucbdasd 	= vol->ucbdasd;
	struct parmarea {
		char 	space_eq[6];		/* "SPACE=" */
		char	free_tot_cyl[4];
		char 	free_tot_cylz;
		char 	free_tot_trk[4];
		char 	free_tot_trkz;
		char 	free_extents[4];
		char 	free_extentsz;
		char 	max_contig_cyl[4];
		char 	max_contig_cylz;
		char 	max_contig_trk[4];
		char 	max_contig_trkz;
	} parmarea;
	
	__asm__("LR\t0,%1\tUCB address in R0\n\t"
			"LR\t1,%2\tLSPACE parameter area in R1\n\t"
			"SVC\t78\t Issue SVC 78 LSPACE\n\t"
			"ST\t15,%0\tSave LSPACE RC" 
			: "=m"(rc)
			: "r" (ucbdasd), "r" (&parmarea) );

	// wtof("@@listvl:%s: LSPACE RC=%d", __func__, rc);
	
	if (!rc) {
		parmarea.free_tot_cylz = 0;
		parmarea.free_tot_trkz = 0;
		parmarea.free_extentsz = 0;
		parmarea.max_contig_cylz = 0;
		parmarea.max_contig_trkz = 0;
		
		// wtodumpf(&parmarea, sizeof(parmarea), "@@listvl:%s: parmarea", __func__);
		
		vol->freecyls = atoi(parmarea.free_tot_cyl);
		vol->freetrks = atoi(parmarea.free_tot_trk);
		vol->freeexts = atoi(parmarea.free_extents);
		vol->maxfreecyls = atoi(parmarea.max_contig_cyl);
		vol->maxfreetrks = atoi(parmarea.max_contig_trk);
	}
	else {
		wtof("@@listvl:%s: LSPACE RC=%d", __func__, rc);
	}
	
quit:
	return rc;
}

static int get_comment(char *buf, VOLLIST **vollist) 
{
	int			rc		= 0;
	unsigned	n, count = array_count(&vollist);
	struct record {
		char	volser[6];
		char 	filler1[33];
		char	comment[40];
		char 	filler2;
	} *rec = (struct record*)buf;
	char 		volpat[7];

	rec->filler1[0] = 0;	/* zero terminate volser */
	rec->filler2 = 0;		/* zero terminate comment */

	strncpy(volpat, rec->volser, sizeof(volpat)-1);
	volpat[sizeof(volpat)-1] = 0;
	strtok(volpat, " ");
	
	// wtodumpf(rec, sizeof(struct record), "@@listvl:%s: record", __func__);
	
	for(n=0; n < count; n++) {
		VOLLIST *v = vollist[n];

		if (!v) continue;
		if (!v->comment) {
			if (__patmat(v->volser, volpat)) {
				v->comment = strdup(rec->comment);
			}
		}
	}
	
	return rc;
}


static FILE *open_vatlst(const char *vatlst) 
{
	FILE 	*fp		= NULL;
	int		len		= strlen(vatlst);
	char	dsn[56];
	
	if (!len) goto quit;

	strncpy(dsn, vatlst, sizeof(dsn));
	dsn[sizeof(dsn)-1] = 0;
	
	if (len > 8) goto do_dataset;
	if (strchr(vatlst, '.')) goto do_dataset;
	if (strchr(vatlst, '(')) goto do_dataset;
	
	sprintf(dsn, "SYS1.PARMLIB(%s)", vatlst);

do_dataset:
	fp = fopen(dsn, "r");

	if (!fp) wtof("@@listvl:%s: unable to open \"%s\"", __func__);

quit:
	return fp;
}

/* in_vollist() - returns 1 if vol is in vollist array, otherwise 0 */
static int in_vollist(VOLLIST **vollist, const char *vol)
{
	int			found	 = 0;
	unsigned 	n, count = array_count(&vollist);
	
	for(n=0; n < count; n++) {
		VOLLIST *v = vollist[n];
		if (memcmp(v->volser, vol, 6)==0) {
			found = 1;
			break;
		}
	}
	
	return found;
}

