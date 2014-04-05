#ifndef _NOW_ACTION_TYPE_KEY_H_
#define _NOW_ACTION_TYPE_KEY_H_

#include "NowDefine.h"
#include "inowaction.h"

class NowActionTypeKey : public INowAction
{
public:
	NowActionTypeKey(void);
	~NowActionTypeKey(void);

	virtual NOW_RESULT prepareArguments(vector<string>* argumnents);

	virtual NOW_RESULT doAction();

};

#endif


