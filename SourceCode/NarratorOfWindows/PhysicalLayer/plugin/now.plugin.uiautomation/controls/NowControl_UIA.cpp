#include "NowControl_UIA.h"
#include "NowLogger.h"
#include "..\NowCommunication.h"
#include "NowStringProcessor.h"

NowControl_UIA::NowControl_UIA(string strSignature, string strControlType) 
{
	m_strSignature = strSignature;
	m_strControlType = strControlType;
}


NowControl_UIA::~NowControl_UIA(void)
{
}

NOW_RESULT NowControl_UIA::getControlType( string& strControlType )
{
	//TODO: Need to check to get what is control type???
	int nResult = NOW_FALSE;
	nResult = NowCommunication::getInstance()->getUIProperty( m_strSignature , NOW_PROP_LOCALIZED_CONTROL_TYPE , strControlType );
	return nResult;
}

NOW_RESULT NowControl_UIA::getCaption( wstring& wstrCaption )
{
	int nResult = NOW_FALSE;
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature, NOW_PROP_NAME, wstrCaption);
	return nResult;
}

NOW_RESULT NowControl_UIA::getUIInformation( wstring& wstrHelpText )
{
	NOW_RESULT nResult = NOW_FALSE;
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature, NOW_PROP_NAME, wstrHelpText);
	//wstring wstrCaption = L"";
	//wstring strStatus = L"";
	//int nState = 0;
	//nResult = NowCommunication::getUIProperty(m_strSignature,NOW_PROP_NAME,wstrCaption);
	//if (NOW_SUCCEED(nResult))
	//{
	//	nResult = NowCommunication::getInstance->getStatus(m_strSignature,nState);
	//	if (NOW_SUCCEED(nResult))
	//	{
	//		wstrHelpText = wstrCaption + L" " + NowStringProcessor::Utf8ToStlWString(NowService::getInstance()->ParseState(nState));
	//	}
	//}
	return nResult;
}

NOW_RESULT NowControl_UIA::getParent( INowControl*& ctrParent )
{
	//NowLogger::getInstance()->LogAString("[NowControl_UIA::getParent]");
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getChildren( list<INowControl*>& lstChildren )
{
	//NowLogger::getInstance()->LogAString("[NowControl_UIA::getChildren]");
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getState( int& nState )
{
	//NowLogger::getInstance()->LogAString("[NowControl_UIA::getState]");
	//NowUIACommunication.GetInstance()
	return NOW_FALSE;
}

NOW_RESULT NowControl_UIA::getSignature( string& strSignature )
{
	//NowLogger::getInstance()->LogAString("[NowControl_UIA::getSignature]");
	strSignature = m_strSignature;
	return NOW_OK;
}

NOW_RESULT NowControl_UIA::getNowClass( string& strNowClass )
{
	//NowLogger::getInstance()->LogAString("[NowControl_UIA::getNowClass]");
	strNowClass = string(NOW_CONTROL);
	return NOW_OK;
}

NOW_RESULT NowControl_UIA::getUIProperty( const string& strPropName, wstring& strValue )
{
	int nResult = NOW_FALSE;
	nResult = NowCommunication::getInstance()->getUIProperty(m_strSignature, strPropName, strValue);
	return nResult;
}

NOW_RESULT NowControl_UIA::getProperty( const string& strPropName, string& strValue )
{
	return NowCommunication::getInstance()->getUIProperty(m_strSignature, strPropName, strValue);
}

NOW_RESULT NowControl_UIA::setValue( const wstring& wstrValue )
{
	return NOW_FALSE;
}
