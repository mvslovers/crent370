/* @@CALLER.C */

char *
__caller(char   *caller)
{
    unsigned    ep;
    char        *p;

    if (!caller) {
        caller = "";
        goto quit;
    }

    caller[0] = 0;

    __asm__("DS\t0H\n"
"        L      1,4(,13)        => callers stack\n"
"        L      1,4(,1)         => callers stack\n"
"        L      1,4(,1)         => callers stack\n"
"        L      1,16(,1)        => function ep address\n"
"        ST     1,0(,%0)        return ep address"
 : : "r"(&ep));

    p = (char *)ep;
    if (p[0]==0x47 && p[1]==0xF0) {
        p += 4;

        memcpy(caller, p+1, *p);
        caller[*p] = 0;
    }

quit:
    return caller;
}
