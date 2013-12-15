#include "NowButton_UIA.h"
#include "NowControl_UIA.h"
#include "NowLogger.h"

NowButton_UIA::NowButton_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
	//m_strControlType = strControlType;
	//m_strSignature = strSignature
}


NowButton_UIA::~NowButton_UIA(void)
{
}

NOW_RESULT NowButton_UIA::getControlType( string& strControlType )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getControlType]");
	strControlType = m_strControlType;
	return NOW_OK;
}

NOW_RESULT NowButton_UIA::getCaption( wstring& wstrCaption )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getCaption]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getHelpText( wstring& wstrHelpText )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getHelpText]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getParent( INowControl*& ctrParent )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getParent]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getChildren( list<INowControl*>& lstChildren )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getChildren]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getState( int& nState )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getState]");
	return NOW_FALSE;
}

NOW_RESULT NowButton_UIA::getSignature( string& strSignature )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getSignature]");
	strSignature = m_strSignature;
	return NOW_OK;
}

NOW_RESULT NowButton_UIA::getNowClass( string& strNowClass )
{
	NowLogger::getInstance()->LogAString("[NowButton_UIA::getNowClass]");
	strNowClass = string(NOW_CONTROL_BUTTON);
	return NOW_OK;
}
