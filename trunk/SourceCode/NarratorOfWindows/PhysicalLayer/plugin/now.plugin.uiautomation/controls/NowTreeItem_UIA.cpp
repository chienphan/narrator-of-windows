#include "NowTreeItem_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowCommunication.h"
#include "..\NowStringProcessor.h"
#include "..\NowService.h"

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
	int nResult = NOW_FALSE;
	wstrHelpText = L"";
	wstring wstrCaption = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_NAME , wstrCaption);
	//NowLogger::getInstance()->LogWString(wstrCaption);
	if (NOW_SUCCEED(nResult))
	{
		int nState = 0;
		nResult = NowCommunication::getInstance()->getStatus(m_strSignature , nState);
		if (NOW_SUCCEED(nResult))
		{
			wstrHelpText = wstrCaption + L" is " + NowStringProcessor::Utf8ToStlWString(NowService::getInstance()->ParseState(nState));
		}
		//wstrHelpText = wstrCaption;
	}
	return nResult;
}