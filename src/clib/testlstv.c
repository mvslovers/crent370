#include "clibary.h"
#include "cliblist.h"
#include "stdio.h"
#include "clibwto.h"

int main(int argc, char **argv)
{
	VOLLIST 	**vollist = __listvl(NULL, 1, "VATLST00");
	unsigned	n, count = array_count(&vollist);
	
	// wtof("%s: vollist=%p count=%u", __func__, vollist, count);

	if (vollist) {
		printf("VOLSER  FREE  FREE   FREE   LARGEST CONTIG FREE AREA  UNIT  DEVICE   UCB   --STATUS--   ------COMMENTS------\n");
		printf("        CYLS  TRKS  EXTENTS    CYLINDERS  TRACKS             TYPE\n");
	}

	for(n=0; n < count; n++) {
		VOLLIST *v = vollist[n];
		char status[16] = {0};
		char comment[40] = {0};
		
		if (!v) continue;
		// wtodumpf(v, sizeof(VOLLIST), "%s: vollist[%u]", __func__, n);
		
		if (v->status & VOLLIST_STATUS_PRV) strcpy(status, "PRIV ");
		else if (v->status & VOLLIST_STATUS_PUB) strcpy(status, "PUBL ");
		else if (v->status & VOLLIST_STATUS_STG) strcpy(status, "STRG ");
		
		if (v->status & VOLLIST_STATUS_PRES) strcat(status, "RSDNT");
		else if (v->status & VOLLIST_STATUS_RESV) strcat(status, "RESRV");
		else if (v->status & VOLLIST_STATUS_ONLI) strcat(status, "ONLIN");
		
		if (v->comment) {
			strncpy(comment, v->comment, sizeof(comment)-1);
			comment[sizeof(comment)-1] = 0;
		}
		else {
			strcpy(comment, "no comment");
		}
		
		printf("%.6s  %4u  %4u   %4u        %4u      %4u      %4X    %4X   %4X   %-12s %s\n",
			v->volser, v->freecyls, v->freetrks, v->freeexts, v->maxfreecyls, v->maxfreetrks, v->cuu, v->dasdtype,
			v->ucbdasd, status, comment);
	}
	
	__freevl(&vollist);

	return 0;
}
