#ifndef CLIBENV_H
#define CLIBENV_H

typedef struct __envvar __ENVVAR;
struct __envvar {
    char    *name;
    char    *value;
    char    buf[2];
};

extern __ENVVAR **__envvar;
extern int      __envsiz;

extern char *   __findenv(const char *name, int *index, int nocase);

extern char *   getenv(const char *name);

extern char *   getenvi(const char *name);

extern int      setenv(const char *name, const char *value, int rewrite);

extern int      setenvi(const char *name, int value, int rewrite);

extern int      putenv(const char *str);

extern int      unsetenv(const char *name);

#endif
