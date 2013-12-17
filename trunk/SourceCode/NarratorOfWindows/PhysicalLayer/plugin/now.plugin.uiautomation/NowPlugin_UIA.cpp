#include "NowDefine.h"
#include "NowPlugin_UIA.h"
#include "NowStringProcessor.h"
#include "NowLogger.h"
#include "NowControlBuilder.h"
#include "NowCommunication.h"

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

	nResult = NowCommunication::getInstance()->GetElementAtPoint(point, strSignatureControl, strControlType);
	
	//TODO: check to place this Sleep method here???
	//Sleep(100);

	if (NOW_SUCCEED(nResult))
	{
		//Check for change another control
		// We will check 

		/*if (isChangedControl(strSignatureControl))
		{*/
			//Create control wrapper
			pControl = NowControlBuilder::getInstance()->createControlWrapper(strSignatureControl, strControlType);
		//}
	}

	return nResult;
}

//bool NowPlugin_UIA::isChangedControl(const string& strNewSignature )
//{
	/*bool blnResult = false;

	if (m_strControlSignature.compare(strNewSignature) != 0)
	{
		m_strControlSignature = strNewSignature;
		blnResult = true;
	}
	return blnResult;*/

//	return NowCommunication::getInstance()->isChangedControl(strNewSignature);
//}

NOW_RESULT NowPlugin_UIA::clearCache()
{
	m_strControlSignature = "";
	return NOW_FALSE;
}

