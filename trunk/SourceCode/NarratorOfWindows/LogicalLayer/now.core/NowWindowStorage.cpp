#include "NowWindowStorage.h"

NowWindowStorage* NowWindowStorage::m_instance = 0;

NowWindowStorage::NowWindowStorage(void)
{
	m_mapWindow = new map<string, INowWindow*>();
}

NowWindowStorage::~NowWindowStorage(void)
{
}

NowWindowStorage* NowWindowStorage::getInstance()
{
	if (m_instance == 0)
	{
		m_instance = new NowWindowStorage();
	}
	return m_instance;
}

NOW_RESULT NowWindowStorage::keepWindowToStorage( const char* szWindowName, INowWindow* pwindow )
{
	//if pWindow == NULL, we also add to storage, when we use it later, 
	//we will check and matching it again
	if (szWindowName != NULL)
	{
		string strWindowTitle = string(szWindowName);
		NowMapWindow::iterator it = m_mapWindow->find(szWindowName);
		//check window is keep in map or not
		if (it == m_mapWindow->end() || it->second == NULL)
		{
			m_mapWindow->insert(pair<string, INowWindow*>(szWindowName, pwindow));
			return NOW_OK;
		}
	}
	return NOW_FALSE;
}

NOW_RESULT NowWindowStorage::getWindowFromStorage( const char* szWindowName, INowWindow*& pWindow )
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

NOW_RESULT NowWindowStorage::emptyStorage()
{
	m_mapWindow->clear();
	return NOW_OK;
}
