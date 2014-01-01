#include "NowButton_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowCommunication.h"

NowButton_UIA::NowButton_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
	//m_strControlType = strControlType;
	//m_strSignature = strSignature;
}

NowButton_UIA::~NowButton_UIA(void)
{
}

//NOW_RESULT NowButton_UIA::getControlType( string& strControlType )
//{
//	int nResult = NOW_FALSE;
//	nResult = NowCommunication::getInstance()->getControlType( m_strSignature , string& strControlType );
//	return nResult;
//}

NOW_RESULT NowButton_UIA::getCaption( wstring& wstrCaption )
{
	int nResult = NOW_FALSE;
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature, NOW_PROP_NAME, wstrCaption);
	return nResult;
}

NOW_RESULT NowButton_UIA::getUIInformation( wstring& wstrHelpText )
{
	int nResult = NOW_FALSE;
	wstring	wstrCaption = L"";
	wstring	wstrToolTip = L"";
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature, NOW_PROP_NAME, wstrCaption);
	if (!NOW_SUCCEED(nResult))
	{
		return nResult;
	}
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature, NOW_PROP_HELP_TEXT, wstrToolTip);
	if (!NOW_SUCCEED(nResult))
	{
		return nResult;
	}
	if (wstrToolTip.length() == 0)
	{
		wstrToolTip = wstrCaption;
	}
	//wstrHelpText = wstrToolTip;
	wstrHelpText =  wstrCaption + L" Button"+ L" . Click to " + wstrToolTip;
	return nResult;
}

NOW_RESULT NowButton_UIA::getParent( INowControl*& ctrParent )
{
	//NowLogger::getInstance()->LogAString("[NowButton_UIA::getParent]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getChildren( list<INowControl*>& lstChildren )
{
	//NowLogger::getInstance()->LogAString("[NowButton_UIA::getChildren]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getState( int& nState )
{
	//NowLogger::getInstance()->LogAString("[NowButton_UIA::getState]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getSignature( string& strSignature )
{
	//NowLogger::getInstance()->LogAString("[NowButton_UIA::getSignature]");
	strSignature = m_strSignature;
	return NOW_OK;
}

NOW_RESULT NowButton_UIA::getNowClass( string& strNowClass )
{
	//NowLogger::getInstance()->LogAString("[NowButton_UIA::getNowClass]");
	strNowClass = string(NOW_CONTROL_BUTTON);
	return NOW_OK;
}

NOW_RESULT NowButton_UIA::getToolTip(wstring& wstrToolTip)
{
	int nResult = NOW_FALSE;
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature, NOW_PROP_HELP_TEXT, wstrToolTip);
	return nResult;
}
