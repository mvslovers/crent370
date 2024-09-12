#ifndef RACF_H
#define RACF_H

#include "acee.h"                   /* ACCESSOR ENVIRONMENT ELEMENT */
#include "safp.h"                   /* SAF ROUTER PARAMETER LIST    */
#include "safv.h"                   /* SAF VECTOR TABLE             */
#include "racinit.h"                /* RACINIT parameter list       */
#include "racheck.h"                /* RACHECK parameter list       */

/* racf_auth() attribute values */
#define RACF_ATTR_READ      RACHECK_ATTR_READ
#define RACF_ATTR_UPDATE    RACHECK_ATTR_UPDATE
#define RACF_ATTR_CONTROL   RACHECK_ATTR_CONTROL
#define RACF_ATTR_ALTER     RACHECK_ATTR_ALTER

/* racf_set_acee() - set the ASXBSENV value, returns previous value */
extern ACEE *   racsacee(ACEE *newacee);
extern ACEE *   racf_set_acee(ACEE *newacee)                            asm("RACSACEE");

/* racf_get_acee() - get the ASXBSENV value */
extern ACEE *   racgacee(void);
extern ACEE *   racf_get_acee(void)                                     asm("RACGACEE");

/* racf_login() - create a new ACEE for user.
** if pass is NULL then password checking is bypassed for this user.
** if racf_rc is not NULL then the RACF return code is returned.
*/
extern ACEE *   raclogin(const char *user, const char *pass,
                         const char *group, int *racf_rc);
extern ACEE *   racf_login(const char *user, const char *pass,
                           const char *group, int *racf_rc)             asm("RACLOGIN");

/* racf_logout() - release a ACEE */
extern int      raclgout(ACEE **acee);
extern int      racf_logout(ACEE **acee)                                asm("RACLGOUT");

/* racf_auth() - check access to resource in security class
** where attr is one of RACF_ATTR_READ, RACF_ATTR_UPDATE, RACF_ATTR_CONTROL
** or RACF_ATTR_ALTER.  If attr is 0 the RACF_ATTR_READ is assumed.
** if attr is an invalid value the RACF_ATTR_ALTER is assumed.
*/
extern int      racauth(ACEE *acee, const char *classname,
                        const char *resource, int attr);
extern int      racf_auth(ACEE *acee, const char *classname,
                          const char *resource, int attr)               asm("RACAUTH");


#endif
