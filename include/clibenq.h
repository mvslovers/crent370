#ifndef CLIBENQ_H
#define CLIBENQ_H

#define ENQ_SCOPE       0x03        /* SCOPE related bits               */
#define ENQ_SYSTEMS     0x02        /* SCOPE=SYSTEMS                    */
#define ENQ_SYSTEM      0x01        /* SCOPE=SYSTEM                     */
#define ENQ_STEP        0x00        /* SCOPE=STEP (default)             */

#define ENQ_SHR         0x04        /* SHARED                           */
#define ENQ_EXC         0x00        /* EXCLUSIVE (default)              */

#define ENQ_RET         0xF0        /* RET related bits                 */
#define ENQ_TEST        0x80        /* RET=TEST                         */
#define ENQ_USE         0x40        /* RET=USE                          */
#define ENQ_CHNG        0x20        /* RET=CHNG                         */
#define ENQ_HAVE        0x00        /* RET=HAVE (default)               */

extern int  __enq(const char *qn, const char *rn, unsigned options);

extern int  __deq(const char *qn, const char *rn, unsigned options);

extern int  __enqdeq(const char *qn, const char *rn, unsigned options, int deq);

#define ENQ(qn,rn,opt)  __enqdeq((qn),(rn),(opt),0)
#define DEQ(qn,rn,opt)  __enqdeq((qn),(rn),(opt),1)

#endif
