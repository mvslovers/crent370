/* CLIBARY.H */
#ifndef CLIBARY_H
#define CLIBARY_H
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct array    ARRAY;

/* internal structure of an array */
struct array {
   char         eye[4];
#define ARRAY_EYE   "ARRY"
   unsigned     size;
   unsigned     count;
};

#define ARRAY_SIZE (sizeof(ARRAY) / sizeof(void *))
#define ARRAY_DEFAULT 20    /* default for new array size */

/* allocate a new array of size elements */
extern void *arraynew(unsigned size)                            asm("@@ARNEW");
extern void *array_new(unsigned size)                           asm("@@ARNEW");

/* Note: all of the following have a "varray" that must be supplied
** as a *** type pointer in those calls.
**
** Example:
** char **myarray = NULL;
** int rc = arrayaddf(&myarray, "Hello World");
*/

/* add item to array */
extern int arrayadd(void * varray, void *vitem)                 asm("@@ARADD");
extern int array_add(void * varray, void *vitem)                asm("@@ARADD");

/* add formatted string to array */
extern int arrayaddf( void * varray, const char *fmt, ... )     asm("@@ARADF");
extern int array_adf( void * varray, const char *fmt, ... )     asm("@@ARADF");
extern int array_addf( void * varray, const char *fmt, ... )    asm("@@ARADF");

/* return number of items in array */
extern unsigned arraycou( void * varray )                       asm("@@ARCOU");
extern unsigned arraycount( void * varray )                     asm("@@ARCOU");
extern unsigned array_cou( void * varray )                      asm("@@ARCOU");
extern unsigned array_count( void * varray )                    asm("@@ARCOU");

/* free array storage, items are not freed (you need to free them first) */
extern int arrayfree( void * varray )                           asm("@@ARFRE");
extern int array_fre( void * varray )                           asm("@@ARFRE");
extern int array_free( void * varray )                          asm("@@ARFRE");

/* return item (index) from array, index range 1 through count */
extern void *arrayget( void * varray, unsigned index )          asm("@@ARGET");
extern void *array_get( void * varray, unsigned index )         asm("@@ARGET");

/* return size of array in items */
extern unsigned arraysize( void * varray )                      asm("@@ARSIZ");
extern unsigned array_siz( void * varray )                      asm("@@ARSIZ");
extern unsigned array_size( void * varray )                     asm("@@ARSIZ");

/* delete item from array */
extern void *arraydel( void * varray, unsigned index )          asm("@@ARDEL");
extern void *array_del( void * varray, unsigned index )         asm("@@ARDEL");

/* call function fn for each array item in varray.
   if function fn returns a non-zero value processing ends with that value
   returned to the caller of the arrayeach() function. */
extern int arrayeach(void * varray,
                     int (*fn)(unsigned index, void *item, void *udata),
                     void *udata)                               asm("@@AREACH");
extern int array_each(void * varray,
                     int (*fn)(unsigned index, void *item, void *udata),
                     void *udata)                               asm("@@AREACH");


#endif
