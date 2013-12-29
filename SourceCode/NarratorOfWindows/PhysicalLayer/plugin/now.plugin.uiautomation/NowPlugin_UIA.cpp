#include "NowDefine.h"
#include "NowPlugin_UIA.h"
#include "NowStringProcessor.h"
#include "NowLogger.h"
#include "NowControlBuilder.h"
#include "NowCommunication.h"
#include "NowPluginManager.h"

NowPlugin_UIA* NowPlugin_UIA::m_pInstance = NULL;

NowPlugin_UIA::NowPlugin_UIA()
{
	m_strControlSignature = "";
}

NowPlugin_UIA::~NowPlugin_UIA()
{
}

NowPlugin_UIA* NowPlugin_UIA::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new NowPlugin_UIA();
	}
	return m_pInstance;
}

string NowPlugin_UIA::getPluginName()
{
	return NOW_PLUGIN_NAME_UIA;
}

NOW_RESULT NowPlugin_UIA::getElementAtPoint( POINT point, INowControl*& pControl )
{
	NOW_RESULT nResult = NOW_FALSE;
	string strControlType = "";
	string strSignatureControl = "";
	
	//Get control at point and return signature and control type of control
	//If control is changed we will keep it to cache for reuse later
	nResult = NowCommunication::getInstance()->getElementAtPoint(point, strSignatureControl, strControlType);
	if (NOW_SUCCEED(nResult) && NowPluginManager::getInstance()->isChangedControl(strSignatureControl))
	{
		//Create new wrapper of control then add it to cache
		pControl = NowControlBuilder::getInstance()->createControlWrapper(strSignatureControl, strControlType);
		nResult = NowPluginManager::getInstance()->keepControlToCache(pControl);
	}
	else
	{
		//This case for get element false or control is not changed
		nResult = NOW_FALSE;
	}

	return nResult;
}

NOW_RESULT NowPlugin_UIA::clearCache()
{
	m_strControlSignature = "";
	return NOW_OK;
}

