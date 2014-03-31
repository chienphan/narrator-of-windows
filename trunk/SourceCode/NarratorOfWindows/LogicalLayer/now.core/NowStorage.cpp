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

NOW_RESULT NowStorage::keepWindowToStorage( const char* szWindowTitle, INowWindow* pwindow )
{
	if (szWindowTitle != NULL && pwindow != NULL)
	{
		string strWindowTitle = string(szWindowTitle);
		NowMapWindow::iterator it = m_mapWindow->find(strWindowTitle);
		//check window is keep in map or not
		if (it == m_mapWindow->end())
		{
			m_mapWindow->insert(pair<string, INowWindow*>(strWindowTitle, pwindow));
			return NOW_OK;
		}
	}
	return NOW_FALSE;
}

NOW_RESULT NowStorage::getWindowFromStorage( const char* szWindowTitle, INowWindow*& pWindow )
{
	if (szWindowTitle != NULL)
	{
		string strWindowTitle = string(szWindowTitle);
		NowMapWindow::iterator it = m_mapWindow->find(strWindowTitle);
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
