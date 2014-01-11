#include "NowTreeItem_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowCommunication.h"

NowTreeItem_UIA::NowTreeItem_UIA(string strSignature, string strControlType)  : NowControl_UIA(strSignature, strControlType)
{
	//m_strControlType = strControlType;
	//m_strSignature = strSignature;
}

NowTreeItem_UIA::~NowTreeItem_UIA(void)
{
}

NOW_RESULT NowTreeItem_UIA::getUIInformation(wstring& wstrHelpText)
{
	int nResult = NOW_FALSE ;
	wstring wstrCaption = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_NAME , wstrCaption);
	if (!NOW_SUCCEED(nResult))
	{
		return nResult ;
	}
	//NowLogger::getInstance()->LogWString(wstrCaption);

	wstring wstrState = L"";
	nResult = NowCommunication::getInstance()->getUIState(m_strSignature , wstrState);
	wstrHelpText = wstrCaption + L" is" + wstrState ; 
	return nResult;
}