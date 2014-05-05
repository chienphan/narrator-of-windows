#ifndef _NOW_ACTION_CLEAR_CACHE_H_
#define _NOW_ACTION_CLEAR_CACHE_H_

#include "NowDefine.h"
#include "INowAction.h"

class NowActionClearCache : public INowAction
{
public:
	NowActionClearCache(void);
	~NowActionClearCache(void);

	virtual NOW_RESULT prepareArguments( vector<wstring>* argumnents );

	virtual NOW_RESULT doAction();

};

#endif


