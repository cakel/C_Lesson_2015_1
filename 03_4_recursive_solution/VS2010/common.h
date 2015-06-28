#ifndef _COMMON_H_
#define _COMMON_H_
typedef int			boolean;
#define true		(1)
#define false		(0)
#define TBL_NUM(X)	(sizeof(X) / sizeof(X[0]))

#define ENABLE		(1)
#define DISABLE		(0)
#define NORMAL		(0)
#define OFF			(0)
#define ON			(1)

#define KEY_NORMAL			(0)
#define KEY_USE_PWR_ONLY	(1)
#define KEY_BLOCK_ALL		(2)
#endif