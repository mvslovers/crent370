#ifndef CLIBAUTH_H
#define CLIBAUTH_H

/* __autask() - make task APF authorized */
extern int __autask(void);

/* __uatask() - reverse of __autask(), reset APF authorization */
extern int __uatask(void);

/* __austep() - make STEPLIB dataset APF authorized */
extern int __austep(void);

/* __uastep() - reverse of __austep(), reset STEPLIB APF authorization */
extern int __uastep(void);

/* __isauth() - returns true if task is APF authorized, false if not */
extern int __isauth(void);

#endif

