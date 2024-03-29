#include "NowCheckBox_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowStringProcessor_UIA.h"
#include "..\NowCommunication.h"
#include "..\NowService.h"
#include "NowStringProcessor.h"

NowCheckBox_UIA::NowCheckBox_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
}
NowCheckBox_UIA::~NowCheckBox_UIA(void)
{
}

NOW_RESULT NowCheckBox_UIA::getUIInformation(wstring& wrtrHelpText)
{
	int nResult = NOW_FALSE;
	wrtrHelpText = L"";
	wstring wstrCaption = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_NAME , wstrCaption);
	if (NOW_SUCCEED(nResult))
	{
		int nState = 0;
		nResult = NowCommunication::getInstance()->getStatus(m_strSignature , nState);
		if (NOW_SUCCEED(nResult))
		{
			wrtrHelpText = wstrCaption + L" check box is " + NowStringProcessor::Utf8ToStlWString(NowService::getInstance()->ParseState(nState));
		}
	}
	return nResult;
}
