#include "NowActionScrollIntoView.h"
#include "NowStringProcessor.h"
#include "NowStorage.h"

NowActionScrollIntoView::NowActionScrollIntoView(void)
{
}


NowActionScrollIntoView::~NowActionScrollIntoView(void)
{
}

NOW_RESULT NowActionScrollIntoView::prepareArguments( vector<wstring>* argumnents )
{
	NOW_RESULT nResult = NOW_FALSE;
	m_strWindowName = NowStringProcessor::wstringTostring(argumnents->at(1));
	m_strControlname = NowStringProcessor::wstringTostring(argumnents->at(2));
	//m_strContent = argumnents->at(3);
	nResult = NowStorage::getInstance()->getWindow(m_strWindowName.c_str(), m_window);
	if (NOW_SUCCEED(nResult))
	{
		nResult = NowStorage::getInstance()->getControl(m_strControlname.c_str(), m_control);
	}
	return nResult;
}

NOW_RESULT NowActionScrollIntoView::doAction()
{
	NOW_RESULT nResult = NOW_FALSE;

	if (m_window != NULL)
	{
		m_window->bringToTop();
	}
	Sleep(100);

	if (m_control != NULL)
	{
		nResult = m_control->scrollIntoView();
	}
	return nResult;
}
