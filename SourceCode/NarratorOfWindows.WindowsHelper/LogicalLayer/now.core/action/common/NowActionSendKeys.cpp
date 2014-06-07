#include "NowActionSendKeys.h"
#include "NowDeviceKeyboard.h"

NowActionSendKeys::NowActionSendKeys(void)
{
}


NowActionSendKeys::~NowActionSendKeys(void)
{
}

NOW_RESULT NowActionSendKeys::prepareArguments( vector<wstring>* argumnents )
{
	NOW_RESULT nResult = NOW_FALSE;
	m_strKeys = argumnents->at(1);
	if (!m_strKeys.empty())
	{
		nResult = NOW_OK;
	}
	return nResult;
}

NOW_RESULT NowActionSendKeys::doAction()
{
	NowDeviceKeyboard::sendKey(m_strKeys);
	return NOW_OK;
}
