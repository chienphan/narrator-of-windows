#include "NowTabItem_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowStringProcessor_UIA.h"
#include "..\NowCommunication.h"
#include "..\NowService.h"
#include "NowStringProcessor.h"

NowTabItem_UIA::NowTabItem_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
}

NowTabItem_UIA::~NowTabItem_UIA(void)
{
}

NOW_RESULT NowTabItem_UIA::getUIInformation(wstring& wrtrHelpText)
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
			wrtrHelpText = wstrCaption + L" tab " + NowStringProcessor::Utf8ToStlWString(NowService::getInstance()->ParseState(nState));
		}
		//wrtrHelpText = wstrCaption;
	}
	//wrtrHelpText = wstrCaption;
	return nResult;
}
