#include "NowListItem_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowStringProcessor.h"
#include "..\NowCommunication.h"
#include "..\NowService.h"

NowListItem_UIA::NowListItem_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
	//m_strControlType = strControlType;
	//m_strSignature = strSignature;
}

NowListItem_UIA::~NowListItem_UIA(void)
{
}

NOW_RESULT NowListItem_UIA::getUIInformation(wstring& wrtrHelpText)
{
	return NowCommunication::getInstance()->getUIProperty(m_strSignature, NOW_PROP_NAME,wrtrHelpText);
	//int nResult = NOW_FALSE;
	//wrtrHelpText = L"";
	//wstring wstrCaption = L"";
	//nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_NAME , wstrCaption);
	//
	//if (NOW_SUCCEED(nResult))
	//{
	//	/*int nState = 0;
	//	nResult = NowCommunication::getInstance()->getUIState(m_strSignature , nState);
	//	if (NOW_SUCCEED(nResult))
	//	{
	//		string strState = NowService::getInstance()->ParseState(nState);
	//		if (strState != "")
	//		{
	//			wrtrHelpText = wstrCaption + L" is " + NowStringProcessor::Utf8ToStlWString(strState);
	//		}
	//		else
	//		{
	//			wrtrHelpText = wstrCaption;
	//		}
	//		NowLogger::getInstance()->LogAString(NowService::getInstance()->ParseState(nState));
	//	}*/
	//	wrtrHelpText = wstrCaption;
	//}
	//return nResult;
}