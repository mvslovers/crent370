
int
usleep(unsigned usec)
{
    /* 1 TUNITVL == 26.04166 microseconds   */
    /* 1 microsecond == .000001 seconds     */
    unsigned    t = usec / 26;  /* 26 is close enough for this */

    if (!t) t = 1;  /* sleep at least 26.04166 microsends */

    __asm__("STIMER WAIT,TUINTVL=%0"
            : : "m"(t): "0", "1", "14", "15");

    return 0;
}
