#include "NowListItem_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowCommunication.h"

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
	int nResult = NOW_FALSE;
	wrtrHelpText = L"";
	wstring wstrCaption = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_NAME , wstrCaption);
	if (!NOW_SUCCEED(nResult))
	{
		return nResult;
	}

	wstring strState = L"";
	nResult = NowCommunication::getInstance()->getUIState(m_strSignature , strState );
	if (!NOW_SUCCEED(nResult))
	{
		return nResult;
	}

	wstring wstrToolTip = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature,NOW_PROP_HELP_TEXT,wstrToolTip);
	if (!NOW_SUCCEED(nResult))
	{
		return nResult;
	}
	wrtrHelpText = wstrCaption + L" is " + strState;

	//wrtrHelpText = wstrToolTip ;
	return nResult;
}