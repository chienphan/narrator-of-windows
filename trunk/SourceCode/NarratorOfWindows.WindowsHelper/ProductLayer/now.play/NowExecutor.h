#ifndef _NOW_EXECUTOR_H_
#define _NOW_EXECUTOR_H_

#include "NowDefine.h"

class NowExecutor{
public:
	static NOW_RESULT initialize(const string& dataFileName);
	static NOW_RESULT doActions();
};

#endif