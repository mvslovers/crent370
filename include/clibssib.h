#ifndef CLIBSSIB_H
#define CLIBSSIB_H

#include <iefjssib.h>		/* SSIB struct */

/* __ssib() - returns pointer to job SSID */
SSIB * __ssib(void)										asm("@@SSIB");

/* __jobid() - returns pointer to 8 character SSIBJBID in job SSIB */
const char * __jobid(void)								asm("@@JOBID");


#endif
