#ifndef GET3_H
#define GET3_H

/* Use GET3 to convert a 3 byte character array to a value.
** Example: int addr = (int) GET3(esd->address);
*/
#define GET3(s) ( \
    ((unsigned char*)(s))[0] << 16 | \
    ((unsigned char*)(s))[1] <<  8 | \
    ((unsigned char*)(s))[2] )

/* Use SET3 to save a value into a 3 byte character array.
** Example: SET3(address,char_array);
*/
#define SET3(u,s) ( \
    ((unsigned char*)(s))[0] = (unsigned char)(((unsigned)u >> 16) & 0xFF), \
    ((unsigned char*)(s))[1] = (unsigned char)(((unsigned)u >> 8)  & 0XFF), \
    ((unsigned char*)(s))[2] = (unsigned char)((unsigned)u & 0xFF))

#endif
