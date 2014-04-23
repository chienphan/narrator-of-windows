#include "NowActionSendData.h"
#include "NowStringProcessor.h"
#include "NowTCPCommunication.h"

NowActionSendData::NowActionSendData(void)
{
}

NowActionSendData::~NowActionSendData(void)
{
}

NOW_RESULT NowActionSendData::prepareArguments( vector<wstring>* argumnents )
{
	m_data = argumnents->at(1);
	if (!m_data.empty())
	{
		return NOW_OK;
	}
	return NOW_FALSE;
}

NOW_RESULT NowActionSendData::doAction()
{
	return NowTCPCommunication::getInstance()->sendData(m_data);
}
