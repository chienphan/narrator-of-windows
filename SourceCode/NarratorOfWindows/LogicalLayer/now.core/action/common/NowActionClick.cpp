#include "NowActionClick.h"
#include "NowStorage.h"
#include "NowLogger.h"

NowActionClick::NowActionClick(void)
{
	m_control = NULL;
}


NowActionClick::~NowActionClick(void)
{
}

NOW_RESULT NowActionClick::prepareArguments(vector<string>* argumnents)
{
	NOW_RESULT nResult = NOW_FALSE;
	m_strWindowName = argumnents->at(1);
	m_strControlname = argumnents->at(2);
	nResult = NowStorage::getInstance()->getControl(m_strControlname.c_str(), m_control);
	return nResult;
}

NOW_RESULT NowActionClick::doAction()
{
	wstring wstrValue = L"";
	if (m_control != NULL)
	{
		m_control->getUIProperty(NOW_PROP_HELP_TEXT, wstrValue);
		NowLogger::getInstance()->LogWString(L"[NowActionClick::doAction]" + wstrValue);
	}
	return NOW_OK;
}