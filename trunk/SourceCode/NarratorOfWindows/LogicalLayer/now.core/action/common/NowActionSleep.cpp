#include "NowActionSleep.h"


NowActionSleep::NowActionSleep(void)
{
}


NowActionSleep::~NowActionSleep(void)
{
}

NOW_RESULT NowActionSleep::prepareArguments( vector<string>* argumnents )
{
	NOW_RESULT nResult = NOW_FALSE;
	string strWindowName = argumnents->at(1);
	m_nSleepTime = atoi(strWindowName.c_str());
	if (m_nSleepTime > 0)
	{
		nResult = NOW_OK;
	}
	return nResult;
}

NOW_RESULT NowActionSleep::doAction()
{
	Sleep(m_nSleepTime);
	return NOW_OK;
}
