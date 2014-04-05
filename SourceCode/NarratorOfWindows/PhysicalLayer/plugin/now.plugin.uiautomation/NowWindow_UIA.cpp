#include "NowWindow_UIA.h"


NowWindow_UIA::NowWindow_UIA(const string& strWindowHandle)
{
	m_strWindowHandle = strWindowHandle;
	m_mapControl = new map<string, INowControl*>();
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

NOW_RESULT NowWindow_UIA::getControlFromStorage( const string& strControlName, INowControl* pControl )
{
	if (!strControlName.empty())
	{
		NowMapControl::iterator it = m_mapControl->find(strControlName);
		if (it != m_mapControl->end())
		{
			pControl = it->second;
			return NOW_OK;
		}
	}
	return NOW_FALSE;
}

NOW_RESULT NowWindow_UIA::addControlToStorage( const string& strControlName, INowControl* pControl )
{
	//if pControl == NULL, we also add to storage, when we use it later, 
	//we will check and matching it again
	if (!strControlName.empty())
	{
		NowMapControl::iterator it = m_mapControl->find(strControlName);
		//check window is keep in map or not
		if (it == m_mapControl->end())
		{
			m_mapControl->insert(pair<string, INowControl*>(strControlName, pControl));
			return NOW_OK;
		}
	}
	return NOW_FALSE;
}
