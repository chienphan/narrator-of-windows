#include "NowMatching.h"
#include "INowWindow.h"
#include "NowDefine.h"
#include "NowPluginManager.h"
#include "NowStorage.h"
#include "NowActionData.h"

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

NOW_RESULT NowMatching::matchWindow(const char* szWindowName)
{
	INowWindow* pWindow = NULL;

	//Get list of plug-ins 
	NowListPlugins lstPlugins = NowPluginManager::getInstance()->getListPlugins();
	if (lstPlugins == NULL)
	{
		return NOW_FALSE;
	}

	if (lstPlugins->size() > 0)
	{
		//For each plug-in, try to get control element. If succeed, we will have the control
		for (vector<INowPlugin*>::iterator it = lstPlugins->begin(); it != lstPlugins->end(); ++it)
		{
			string strWindowTitle = "";
			NowActionData::getInstance()->getWindowTitle(string(szWindowName), strWindowTitle);
			//Get control element at mouse point and keep to cache if succeed
			NOW_RESULT nRet = (*it)->matchWindow(strWindowTitle.c_str(), pWindow);
			if (NOW_SUCCEED(nRet))
			{
				break;
			}
		}

		NowStorage::getInstance()->keepWindow(szWindowName, pWindow);
		return NOW_OK;
	}

	return NOW_FALSE;
}

NOW_RESULT NowMatching::matchControl( const char* szControlName)
{
	NOW_RESULT nResult = NOW_FALSE;
	INowControl* pControl = NULL;
	
	//Get list of plug-ins 
	NowListPlugins lstPlugins = NowPluginManager::getInstance()->getListPlugins();
	if (lstPlugins == NULL)
	{
		return NOW_FALSE;
	}

	if (lstPlugins->size() > 0)
	{
		string strWindowHandle = "";
		string strPropsData = "";
		nResult = getWindowHandle(szControlName, strWindowHandle);
		
		if (NOW_SUCCEED(nResult))
		{
			nResult = NowActionData::getInstance()->getControlData(string(szControlName), strPropsData);
			if (NOW_SUCCEED(nResult))
			{
				//For each plug-in, try to get control element. If succeed, we will have the control
				for (vector<INowPlugin*>::iterator it = lstPlugins->begin(); it != lstPlugins->end(); ++it)
				{
					nResult = (*it)->matchControl(strWindowHandle.c_str(), strPropsData.c_str(), pControl);
					if (NOW_SUCCEED(nResult))
					{
						break;
					}
				}

				NowStorage::getInstance()->keepControl(szControlName, pControl);
				nResult = NOW_OK;
			}
		}
	}

	return nResult;
}

NOW_RESULT NowMatching::getWindowHandle(const char* szControlName, string& strWindowHandle)
{
	NOW_RESULT nResult = NOW_FALSE;
	string strWindowName = "";
	nResult = NowActionData::getInstance()->getWindowName(string(szControlName), strWindowName);
	if (NOW_SUCCEED(nResult))
	{
		INowWindow* pWindow = NULL;
		nResult = NowStorage::getInstance()->getWindow(strWindowName.c_str(), pWindow);
		if (NOW_SUCCEED(nResult))
		{
			pWindow->getWindowHandle(strWindowHandle);
		}
	}
	return nResult;
}