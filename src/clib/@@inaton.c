#include <socket.h>

/* inet_aton() - converts IPV4 string to in_addr_t struct */
/* returns 0 for success, otherwise invalid parms or IPV4 string */
int inet_aton(const char *cp, in_addr_t *inp)
{
	int			rc	= -1;
	char		*next;
	unsigned	x;
	
	while (cp && inp) {
		x = strtoul(cp, &next, 0);
		if (!next[0]) {
			inp->s_addr = x;
			rc = 0;
			break;
		}
		inp->s_addr = x << 24;
		if (next[0]=='.') {
			x = strtoul(&next[1], &next, 0);
			if (x > 0x00FFFFFF) break;
			if (!next[0]) {
				inp->s_addr |= x;
				rc = 0;
				break;
			}
			else {
				inp->s_addr |= x << 16;
			}
		}
		if (next[0]=='.') {
			x = strtoul(&next[1], &next, 0);
			if (x > 0x0000FFFF) break;
			if (!next[0]) {
				inp->s_addr |= x;
				rc = 0;
				break;
			}
			else {
				inp->s_addr |= x << 8;
			}
		}
		if (next[0]=='.') {
			x = strtoul(&next[1], &next, 0);
			if (x > 0xFF) break;
			inp->s_addr |= x;
		}
		rc = 0;
		break;
	}

	return rc;
}
