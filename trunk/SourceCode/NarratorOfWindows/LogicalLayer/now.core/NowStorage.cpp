#include "NowStorage.h"

NowStorage* NowStorage::m_instance = 0;

NowStorage::NowStorage(void)
{
	m_mapWindow = new map<string, INowWindow*>();
}

NowStorage::~NowStorage(void)
{
}

NowStorage* NowStorage::getInstance()
{
	if (m_instance == 0)
	{
		m_instance = new NowStorage();
	}
	return m_instance;
}

NOW_RESULT NowStorage::keepWindowToStorage( const char* szWindowName, INowWindow* pwindow )
{
	//if pWindow == NULL, we also add to storage, when we use it later, 
	//we will check and matching it again
	if (szWindowName != NULL)
	{
		string strWindowTitle = string(szWindowName);
		NowMapWindow::iterator it = m_mapWindow->find(szWindowName);
		//check window is keep in map or not
		if (it == m_mapWindow->end())
		{
			m_mapWindow->insert(pair<string, INowWindow*>(szWindowName, pwindow));
			return NOW_OK;
		}
	}
	return NOW_FALSE;
}

NOW_RESULT NowStorage::getWindowFromStorage( const char* szWindowName, INowWindow*& pWindow )
{
	if (szWindowName != NULL)
	{
		string strWindowTitle = string(szWindowName);
		NowMapWindow::iterator it = m_mapWindow->find(szWindowName);
		if (it != m_mapWindow->end())
		{
			pWindow = it->second;
			return NOW_OK;
		}
	}
	return NOW_FALSE;
}

NOW_RESULT NowStorage::emptyStorage()
{
	m_mapWindow->clear();
	return NOW_OK;
}
