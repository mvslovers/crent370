#ifndef CLIBTRY_H
#define CLIBTRY_H

#ifndef CLIBSTAE_H
#include <clibstae.h>
#endif

/* call func with ESTAE protection, RC0=success otherwise failed */
/* note: used when we want the failure reason returned in rc
** 	when rc is negative value the ESTAE CREATE failed. 
**  otherwise rc is a 0x00sssuuu formatted value. 
**  sss is system abend code, uuu is user abend code.
*/
extern int ___try(void *func, ...);
#define try(func,...) ___try((func), __VA_ARGS__)

/* call func with ESTAE protection. Returns 0 unless the ESTAE create fails */
/* note: used only when we don't care the failure reason */
extern int __try(void *func, ...);

/* abend report via WTO messages */
extern int __abrpt(ESTAE_OP op, DUMP_OP);
#define abendrpt(eop,dop) __abrpt((eop),(dop))

/* return last ___try() or __try() rc/abend code */
unsigned ___tryrc(void);
#define tryrc() ___tryrc()

/* return last ___try() or __try() rc/abend code */
unsigned __tryrc(void);

#endif
