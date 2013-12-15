#include "NowControl_UIA.h"
#include "NowLogger.h"

NowControl_UIA::NowControl_UIA(string strSignature, string strControlType) 
	//: m_strControlType(strControlType), m_strSignature(strSignature)
{
	m_strSignature = strSignature;
	m_strControlType = strControlType;
}


NowControl_UIA::~NowControl_UIA(void)
{
}

NOW_RESULT NowControl_UIA::getControlType( string& strControlType )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getControlType]");
	strControlType = m_strControlType;
	return NOW_OK;
}

NOW_RESULT NowControl_UIA::getCaption( wstring& wstrCaption )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getCaption]");
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getHelpText( wstring& wstrHelpText )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getHelpText]");
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getParent( INowControl*& ctrParent )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getParent]");
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getChildren( list<INowControl*>& lstChildren )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getChildren]");
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getState( int& nState )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getState]");
	//NowUIACommunication.GetInstance()
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getSignature( string& strSignature )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getSignature]");
	strSignature = m_strSignature;
	return NOW_OK;
}

NOW_RESULT NowControl_UIA::getNowClass( string& strNowClass )
{
	NowLogger::getInstance()->LogAString("[NowControl_UIA::getNowClass]");
	strNowClass = string(NOW_CONTROL);
	return NOW_OK;
}
