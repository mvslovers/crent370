#ifndef CLIBSTR_H
#define CLIBSTR_H

#ifndef __SIZE_T_DEFINED
#define __SIZE_T_DEFINED
#if (defined(__OS2__) || defined(__32BIT__) || defined(__MVS__) \
    || defined(__CMS__) || defined(__VSE__))
typedef unsigned long size_t;
#elif (defined(__MSDOS__) || defined(__DOS__) || defined(__POWERC) \
    || defined(__WIN32__) || defined(__gnu_linux__))
typedef unsigned int size_t;
#endif
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

void *memcpy(void *s1, const void *s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);
char *strcpy(char *s1, const char *s2);
char *strncpy(char *s1, const char *s2, size_t n);
char *strcat(char *s1, const char *s2);
char *strncat(char *s1, const char *s2, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
int strcmp(const char *s1, const char *s2);
int strcoll(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strxfrm(char *s1, const char *s2, size_t n);
void *memchr(const void *s, int c, size_t n);
char *strchr(const char *s, int c);
size_t strcspn(const char *s1, const char *s2);
char *strpbrk(const char *s1, const char *s2);
char *strrchr(const char *s, int c);
size_t strspn(const char *s1, const char *s2);
char *strstr(const char *s1, const char *s2);
char *strtok(char *s1, const char *s2);
#if 0
void *memset(void *s, int c, size_t n);
#else
static __inline void *memset(void *s, int c, size_t n)
{
    __asm__ __volatile__("\n*** MEMSET ***\n"
"         LR    14,%0           => target (s)\n"
"         LR    15,%1           => length (n)\n"
"         SLR   0,0             => source (NULL)\n"
"         LR    1,%2            fill character\n"
"         SLL   1,24            move fill to high byte\n"
"         MVCL  14,0            Set target to fill character"
    : : "r"(s), "r"(n), "r"(c) : "0", "1", "14", "15");
    return s;
}
#endif
char *strerror(int errnum);
size_t strlen(const char *s);

/* copy source string to target string with pad character fill */
char *strcpyp(char *target, int tlen, void *source, int pad );

/* copy source to target with pad character fill */
void *memcpyp(void *target, int tlen, void *source, int slen, int pad);

/* compare "str" against pattern "pat", returns true if match */
int __patmat( const char *str, const char *pat );

char *strdup(const char *s);

static __inline void *memclr(void *s, size_t n)
{
    __asm__ __volatile__("\n*** MEMCLR ***\n"
"         LR    14,%0           => target (s)\n"
"         LR    15,%1           => length (n)\n"
"         SLR   0,0             => source (NULL)\n"
"         SLR   1,1             zero fill\n"
"         MVCL  14,0            Set target to fill character"
    : : "r"(s), "r"(n) : "0", "1", "14", "15");
    return s;
}

#endif
