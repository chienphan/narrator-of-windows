#ifndef _NOW_ACTION_SLEEP_H_
#define _NOW_ACTION_SLEEP_H_

#include "inowaction.h"

class NowActionSleep :
	public INowAction
{
private:
	int m_nSleepTime;

public:
	NowActionSleep(void);
	~NowActionSleep(void);

	virtual NOW_RESULT prepareArguments( vector<wstring>* argumnents );

	virtual NOW_RESULT doAction();

};

#endif
