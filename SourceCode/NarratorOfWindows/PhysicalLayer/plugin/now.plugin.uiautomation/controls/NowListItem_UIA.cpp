#include "NowListItem_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowStringProcessor_UIA.h"
#include "..\NowCommunication.h"
#include "..\NowService.h"
#include "NowStringProcessor.h"

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

}