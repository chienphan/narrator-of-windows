#include "NowStorage.h"
#include "NowActionData.h"
#include "NowMatching.h"
#include "NowLogger.h"

NowStorage* NowStorage::m_instance = 0;

NowStorage::NowStorage(void)
{
	m_mapWindow = new map<string, INowWindow*>();
	m_mapControl = new map<string, INowControl*>();
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

NOW_RESULT NowStorage::keepWindow( const char* szWindowName, INowWindow* pWindow )
{
	NOW_RESULT nresult = NOW_FALSE;
	if (szWindowName != NULL)
	{
		string strWindowTitle = string(szWindowName);
		NowMapWindow::iterator it = m_mapWindow->find(strWindowTitle);
		//check window is keep in map or not
		if (it == m_mapWindow->end())
		{
			m_mapWindow->insert(pair<string, INowWindow*>(szWindowName, pWindow));
			nresult = NOW_OK;
		}
		else if (it->second == NULL)
		{
			it->second = pWindow;
			nresult = NOW_OK;
		}
	}
	return nresult;
}

NOW_RESULT NowStorage::getWindow( const char* szWindowName, INowWindow*& pWindow )
{
	NOW_RESULT nResult = NOW_FALSE;
	if (szWindowName != NULL)
	{
		string strWindowName = string(szWindowName);
		nResult = getWindowFromStorage(strWindowName, pWindow);

		//window is not match, re-matching window
		if (nResult == NOW_FALSE)
		{
			long nDeadline = GetTickCount() + NOW_WAIT_TIME;
			do
			{
				nResult = NowMatching::getInstance()->matchWindow(strWindowName.c_str());
				Sleep(NOW_DELAY_TIME);
			}
			while(nDeadline > GetTickCount() && !NOW_SUCCEED(nResult));
			//re-get window
			nResult = getWindowFromStorage(strWindowName, pWindow);
		}

		if (pWindow == NULL)
		{
			nResult = NOW_FALSE;
		}
	}
	return nResult;
}

NOW_RESULT NowStorage::emptyStorage()
{
	m_mapWindow->clear();
	m_mapControl->clear();
	return NOW_OK;
}

NOW_RESULT NowStorage::getWindowFromStorage(const string& strWindowName, INowWindow*& pWindow )
{
	NowMapWindow::iterator it = m_mapWindow->find(strWindowName);
	if (it != m_mapWindow->end())
	{
		pWindow = it->second;
		return NOW_OK;
	}

	return NOW_FALSE;
}

NOW_RESULT NowStorage::keepControl(const char* szControlName, INowControl* pControl)
{
	NOW_RESULT nresult = NOW_FALSE;
	if (szControlName != NULL)
	{
		string strControlName = string(szControlName);
		NowMapControl::iterator it = m_mapControl->find(strControlName);
		//check window is keep in map or not
		if (it == m_mapControl->end())
		{
			m_mapControl->insert(pair<string, INowControl*>(strControlName, pControl));
			nresult = NOW_OK;
		}
		else if (it->second == NULL)
		{
			it->second = pControl;
			nresult = NOW_OK;
		}
	}
	return nresult;
}

NOW_RESULT NowStorage::getControl(const char* szControlName, INowControl*& pControl)
{
	NOW_RESULT nResult = NOW_FALSE;
	if (szControlName != NULL)
	{
		string strControlName = string(szControlName);
		nResult = getControlFromStogare(strControlName, pControl);

		//window is not match, re-matching window
		if (nResult == NOW_FALSE)
		{
			long nDeadline = GetTickCount() + NOW_WAIT_TIME;
			do
			{
				nResult = NowMatching::getInstance()->matchControl(strControlName.c_str());
				Sleep(NOW_DELAY_TIME);
			}
			while(nDeadline > GetTickCount() && !NOW_SUCCEED(nResult));

			//re-get window
			nResult = getControlFromStogare(strControlName, pControl);
		}

		if (pControl == NULL)
		{
			nResult = NOW_FALSE;
		}
	}
	return nResult;
	
}

NOW_RESULT NowStorage::getControlFromStogare(const string& strControlName, INowControl*& pControl)
{
	NOW_RESULT nResult = NOW_FALSE;
	NowMapControl::iterator it = m_mapControl->find(strControlName);
	if (it != m_mapControl->end())
	{
		pControl = it->second;
		nResult = NOW_OK;
	}
	return nResult;
}