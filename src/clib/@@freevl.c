#include "clibary.h"
#include "cliblist.h"

void __freevl(VOLLIST ***pppvollist)
{
	VOLLIST 	**vollist;
	unsigned	n, count;
	
	if (!pppvollist) goto quit;

	vollist = *pppvollist;
	if (!vollist) goto quit;
	
	count = array_count(&vollist);
	for(n=count; n > 0; n--) {
		VOLLIST *v = array_del(&vollist, n);
		
		if (!v) continue;
		if (v->comment) {
			free(v->comment);
			v->comment = NULL;
		}
		free(v);
	}
	
	array_free(&vollist);
	*pppvollist = NULL;

quit:
	return;
}
