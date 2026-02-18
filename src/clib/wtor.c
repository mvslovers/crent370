/* WTO.C */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct wtormsg {
    union {
        unsigned    reply;
        struct {
            char    reply_len;
            char    reply_addr[3];
        } __attribute__((packed));
    };
    unsigned        *ecb;
    unsigned short  text_len;
    unsigned short  mcs_flags;
    char            text[122];
} WTORMSG;

void
wtor(char *reply, unsigned replymax, const char *text)
{
    unsigned    ecb     = 0;
    unsigned    len     = 0;
    WTORMSG     msg     = {0};

    if (text) {
        len = strlen(text);
        if (len > sizeof(msg.text)) len = sizeof(msg.text);
    }

    if (reply && replymax) {
		if (replymax > 119) replymax = 119;
        msg.reply = (unsigned)reply;
        msg.reply_len = replymax;
        msg.ecb = &ecb;
    }

    if (len) {
        msg.text_len = sizeof(msg.text_len) + sizeof(msg.mcs_flags) + len;
        memcpy(msg.text, text, len);
    }

    __asm__("LR\t1,%0\n\t"
            "SVC\t35" : : "r"(&msg) : "0", "1", "14", "15");

    if (msg.ecb) {
        __asm__("WAIT\t1,ECB=(%0)" : : "r"(msg.ecb) : "0", "1", "14", "15");
    }
}
