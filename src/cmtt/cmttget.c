#include <clibmtt.h>

#define INBOUNDS(t,e) ((unsigned)(e) >= (t)->mttentpt && (unsigned)(e) < (t)->mttendpt)

static inline void reverse_mtentry_array(MTENTRY **arr) 
{
    unsigned    count       = array_count(&arr);
    unsigned    n;
    void        *temp;

    for (n = 0; n < count / 2; n++) {
        temp                = arr[n];
        arr[n]              = arr[count - n - 1];
        arr[count - n - 1]  = temp;
    }
}

MTENTRY **cmtt_get_array(CMTT *cmtt)
{
    MTENTRY     **array     = (MTENTRY **)0;
    MTTABLE     *mttable;
    MTENTRY     *mtentry;
    unsigned    size;
    unsigned    offset;

    /* CMTT handle is required */
    if (!cmtt) goto quit;

    /* we *should* have a copy of the master trace table */
    mttable = cmtt->mttable;
    if (!mttable) goto quit;

    /* If we've already created the array we're done */
    array = cmtt->array;
    if (array) goto quit;

    /* create array of MTENTRY pointers */

    /* For performance reasons we want to preallocate the array.
     * 
     * If the actual size needed is more than the calculated size,
     * the array_add() calls below will automatically expand
     * the array as needed (dynamic array).
    */
    size = mttable->mttdarea / 80;
    if (size < 10) size = 10;
    // wtof("%s: estimated size %u", __func__, size);
    array = (MTENTRY**) array_new(size);

    /* start with current point in mttable until end of table */
    for(mtentry = (MTENTRY*) mttable->mttcurpt; 
        INBOUNDS(mttable, mtentry); 
        mtentry = (MTENTRY*)((unsigned)mtentry + mtentry->mtentlen + 10) ) {
        
        array_add(&array, mtentry);
    }

    /* then use the wrap point until we reach the current point */
    for(mtentry = (MTENTRY*) mttable->mttwrppt; 
        INBOUNDS(mttable, mtentry) && mtentry < mttable->mttcurpt; 
        mtentry = (MTENTRY*)((unsigned)mtentry + mtentry->mtentlen + 10) ) {

        array_add(&array, mtentry);
    }

    /* remember our array of MTENTRY pointers */
    cmtt->array = array;

    /* array is in last to first order, we want first to last order */
    size = array_count(&array);
    if (size > 1) {
        /* reverse the order of MTENTRY pointers in our array */
        asm("\n* inline reverse_mtentry_array start");
        reverse_mtentry_array(array);
        asm("\n* inline reverse_mtentry_array end");
        
        /* The first MTENTRY often points to a partial record. 
         * Delete the first MTENTRY pointer from our array. 
        */
        array_del(&array, 1);
    }

quit:
    return array;
}
