#include "NowActionSleep.h"
#include "NowStringProcessor.h"

NowActionSleep::NowActionSleep(void)
{
}


NowActionSleep::~NowActionSleep(void)
{
}

NOW_RESULT NowActionSleep::prepareArguments( vector<wstring>* argumnents )
{
	NOW_RESULT nResult = NOW_FALSE;
	wstring strWindowName = argumnents->at(1);
	m_nSleepTime = atoi(NowStringProcessor::wstringTostring(strWindowName).c_str());
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
