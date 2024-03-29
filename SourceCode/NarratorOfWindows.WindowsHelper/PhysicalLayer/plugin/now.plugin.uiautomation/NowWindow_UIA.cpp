#include "NowWindow_UIA.h"
#include "NowActionData.h"
#include "NowMatching.h"
#include "NowCommunication.h"

NowWindow_UIA::NowWindow_UIA(const string& strWindowHandle)
{
	m_strWindowHandle = strWindowHandle;
}


NowWindow_UIA::~NowWindow_UIA(void)
{

}

NOW_RESULT NowWindow_UIA::getWindowHandle( string& strWindowHandle )
{
	if (!m_strWindowHandle.empty())
	{
		strWindowHandle = m_strWindowHandle;
		return NOW_OK;
	}
	return NOW_FALSE;
}

NOW_RESULT NowWindow_UIA::bringToTop()
{
	return NowCommunication::getInstance()->bringWindowToTop(m_strWindowHandle);
}
