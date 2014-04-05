#include "NowMatching.h"
#include "INowWindow.h"
#include "NowDefine.h"
#include "NowPluginManager.h"
#include "NowWindowStorage.h"

NowMatching* NowMatching::m_instance = 0;

NowMatching::NowMatching(void)
{
}


NowMatching::~NowMatching(void)
{
}

NowMatching* NowMatching::getInstance()
{
	if (m_instance == 0)
	{
		m_instance = new NowMatching();
	}
	return m_instance;
}

NOW_RESULT NowMatching::matchWindow(const char* szWindowName, const char* szWindowTitle)
{
	INowWindow* pWindow = NULL;

	//Get list of plug-ins 
	NowListPlugins lstPlugins = NowPluginManager::getInstance()->getListPlugins();
	if (lstPlugins == NULL)
	{
		return NOW_FALSE;
	}

	//Check for exist window
	if (NOW_SUCCEED(NowWindowStorage::getInstance()->getWindowFromStorage(szWindowName, pWindow)))
	{
		//Window is ready exist
		if (pWindow != NULL)
		{
			return NOW_OK;
		}
	}

	if (lstPlugins->size() > 0)
	{
		//For each plug-in, try to get control element. If succeed, we will have the control
		for (vector<INowPlugin*>::iterator it = lstPlugins->begin(); it != lstPlugins->end(); ++it)
		{
			//Get control element at mouse point and keep to cache if succeed
			NOW_RESULT nRet = (*it)->matchWindow(szWindowTitle, pWindow);
			if (NOW_SUCCEED(nRet))
			{
				break;
			}
		}

		NowWindowStorage::getInstance()->keepWindowToStorage(szWindowName, pWindow);
		return NOW_OK;
	}

	return NOW_FALSE;
}

NOW_RESULT NowMatching::matchControl( const char* szWindowName, const char* szControlName, map<string, string>* propvalue )
{
	INowWindow* pWindow = NULL;
	NOW_RESULT nResult = NowWindowStorage::getInstance()->getWindowFromStorage(szWindowName, pWindow);
	if (NOW_SUCCEED(nResult))
	{
		//Window is not exist
		if (pWindow == NULL)
		{
			//re-matching window
		}
	}
	return NOW_FALSE;
}


