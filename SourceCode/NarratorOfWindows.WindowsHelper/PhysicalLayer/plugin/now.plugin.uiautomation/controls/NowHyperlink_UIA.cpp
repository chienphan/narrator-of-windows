#include "NowHyperlink_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowStringProcessor_UIA.h"
#include "..\NowCommunication.h"
#include "..\NowService.h"
#include "NowStringProcessor.h"

NowHyperlink_UIA::NowHyperlink_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
}
NowHyperlink_UIA::~NowHyperlink_UIA(void)
{
}

NOW_RESULT NowHyperlink_UIA::getUIInformation(wstring& wrtrHelpText)
{
	int nResult = NOW_FALSE;
	wrtrHelpText = L"";
	wstring wstrCaption = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_NAME , wstrCaption);
	if (NOW_SUCCEED(nResult))
	{
	//	int nState = 0;
	//	nResult = NowCommunication::getInstance()->getUIState(m_strSignature , nState);
	//	char buffer[512];
	//	sprintf_s(buffer, "%d ", nState);
	//	NowLogger::getInstance()->LogAString(string(buffer));
	//	if (NOW_SUCCEED(nResult))
	//	{
	//		wrtrHelpText = wstrCaption + L" is " + NowStringProcessor::Utf8ToStlWString(NowService::getInstance()->ParseState(nState));
	//	}
		wrtrHelpText = wstrCaption;
	}
	
	return nResult;
}
