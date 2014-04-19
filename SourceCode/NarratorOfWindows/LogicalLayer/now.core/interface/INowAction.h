#ifndef _INOW_ACTION_H_
#define _INOW_ACTION_H_

#include "NowDefine.h"

class INowAction
{
public:
	virtual NOW_RESULT prepareArguments(vector<wstring>* argumnents) = 0;
	virtual NOW_RESULT doAction() = 0;
};

#endif


