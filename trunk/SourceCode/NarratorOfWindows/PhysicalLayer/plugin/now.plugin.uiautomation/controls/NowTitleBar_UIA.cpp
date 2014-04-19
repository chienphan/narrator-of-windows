#include "NowTitleBar_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowStringProcessor_UIA.h"
#include "..\NowCommunication.h"
#include "..\NowService.h"
#include "NowStringProcessor.h"

NowTitleBar_UIA::NowTitleBar_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
}
NowTitleBar_UIA::~NowTitleBar_UIA(void)
{
}

NOW_RESULT NowTitleBar_UIA::getUIInformation(wstring& wrtrHelpText)
{
	int nResult = NOW_FALSE;
	wrtrHelpText = L"";
	wstring wstrCaption = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature , NOW_PROP_NAME , wstrCaption);
	if (NOW_SUCCEED(nResult))
	{
		wrtrHelpText = wstrCaption;
	}
	
	return nResult;
}
