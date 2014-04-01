#include "NowMatching.h"
#include "INowWindow.h"
#include "NowDefine.h"
#include "NowPluginManager.h"

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

NOW_RESULT NowMatching::matchWindow( const char* szWindowTitle, INowWindow*& pWindow )
{
	//Get list of plug-ins 
	NowListPlugins lstPlugins = NowPluginManager::getInstance()->getListPlugins();

	if (lstPlugins != NULL && lstPlugins->size() > 0)
	{
		//For each plug-in, try to get control element. If succeed, we will have the control
		for (vector<INowPlugin*>::iterator it = lstPlugins->begin(); it != lstPlugins->end(); ++it)
		{
			//Get control element at mouse point and keep to cache if succeed
			NOW_RESULT nRet = (*it)->matchWindow(szWindowTitle, pWindow);
			if (NOW_SUCCEED(nRet))
			{
				return NOW_OK;
			}
		}
	}
	return NOW_FALSE;
}


