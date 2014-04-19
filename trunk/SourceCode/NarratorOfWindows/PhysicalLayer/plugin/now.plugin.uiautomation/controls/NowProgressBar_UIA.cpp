#include "NowProgressBar_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowStringProcessor_UIA.h"
#include "..\NowCommunication.h"
#include "..\NowService.h"
#include "NowStringProcessor.h"

NowProgressBar_UIA::NowProgressBar_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
}
NowProgressBar_UIA::~NowProgressBar_UIA(void)
{
}

NOW_RESULT NowProgressBar_UIA::getUIInformation(wstring& wrtrHelpText)
{
	int nResult = NOW_FALSE;
	wrtrHelpText = L"";
	wstring wstrCaption = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_AUTOMATION_ID , wstrCaption);
	if (NOW_SUCCEED(nResult))
	{
		string strValue = "";
		nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_IS_VALUE , strValue);
		if (NOW_SUCCEED(nResult))
		{
			wrtrHelpText = wstrCaption + L" is " + NowStringProcessor::Utf8ToStlWString(strValue) + L"%";
		}
	}
	return nResult;
}
