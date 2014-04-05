#include "NowCommunication.h"
#include "NowStringProcessor.h"
#include "NowLogger.h"
#include <stdio.h>
#include <stdlib.h>

#using "now.agent.uiautomation.client.dll"

using namespace now::agent::uiautomation::client;
using namespace System::Diagnostics;
using namespace System;

NowCommunication* NowCommunication::m_instance = NULL;

NowCommunication::NowCommunication()
{
}

NowCommunication::~NowCommunication()
{
}

NowCommunication* NowCommunication::getInstance()
{
	if (!m_instance)
	{
		m_instance = new NowCommunication();
	}
	return m_instance;
}

NOW_RESULT NowCommunication::getElementAtPoint( POINT point, string& strSignatureControl, string& strControlType )
{
	NOW_RESULT nResult = NOW_FALSE;
	//Converter to System::Windows::Point
	System::Windows::Point newPoint;
	newPoint.X = point.x;
	newPoint.Y = point.y;

	//Only get signature of element, runtimeElement need to keep at agent
	String^ mstrControlType = "";
	String^ mstrSignatureControl = ""; 
	nResult = NowUIACommunication::GetInstance()->GetElementAtPoint(newPoint, mstrSignatureControl, mstrControlType);
	if (NOW_SUCCEED(nResult))
	{
		strSignatureControl = NowStringProcessor::StringToStlString(mstrSignatureControl);
		strControlType = NowStringProcessor::StringToStlString(mstrControlType);
	}
	return nResult;
}

NOW_RESULT NowCommunication::getUIProperty(const string& strSignature, const string& strPropName , wstring& wstrValue)
{
	int nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	String^ mstrPropName = NowStringProcessor::StlStringToString(strPropName);
	String^ mstrValue = "";

	nResult = NowUIACommunication::GetInstance()->GetUIProperty(mstrSignature, mstrPropName, mstrValue);
	if (NOW_SUCCEED(nResult))
	{
		wstrValue = NowStringProcessor::StringToStlWString(mstrValue);
	}
	return nResult;
}

NOW_RESULT NowCommunication::getUIProperty(const string& strSignature, const string& strPropName , string& strValue)
{
	int nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	String^ mstrPropName = NowStringProcessor::StlStringToString(strPropName);
	String^ mstrValue = "";

	nResult = NowUIACommunication::GetInstance()->GetUIProperty(mstrSignature, mstrPropName, mstrValue);
	if (NOW_SUCCEED(nResult))
	{
		strValue = NowStringProcessor::StringToStlString(mstrValue);
	}
	return nResult;
}

NOW_RESULT NowCommunication::getUIState(const string& strSignature , int& nState)
{
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	int nResult = NowUIACommunication::GetInstance()->GetUIState(mstrSignature, nState);	
	return nResult ;		
}

NOW_RESULT NowCommunication::getWindowByTitle( const string& strTitleWindow, string& strWindowHandle )
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrTitleWindow = NowStringProcessor::StlStringToString(strTitleWindow);
	NowUIALogger::GetInstance()->LogInfor("[NowCommunication::getWindowByTitle]" + mstrTitleWindow);
	String^ mstrHandleWindow = "";
	nResult = NowUIACommunication::GetInstance()->GetWindowByTitle(mstrTitleWindow, mstrHandleWindow);
	if (NOW_SUCCEED(nResult))
	{
		NowUIALogger::GetInstance()->LogInfor("[NowCommunication::getWindowByTitle] >>>>" + mstrHandleWindow);
		strWindowHandle = NowStringProcessor::StringToStlString(mstrHandleWindow);
	}
	return nResult ;	
}

NOW_RESULT NowCommunication::getControlByCondition( const string& strWindowHandle, const string& strPropsData, string& strSignatureControl, string& strControlType )
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrWindowHandle = NowStringProcessor::StlStringToString(strWindowHandle);
	String^ mstrPropsData = NowStringProcessor::StlStringToString(strPropsData);
	String^ mstrSignatureControl = "";
	String^ mstrControlType = "";

	nResult = NowUIACommunication::GetInstance()->GetControlByCondition(mstrWindowHandle, mstrPropsData, mstrSignatureControl, mstrControlType);
	if (NOW_SUCCEED(nResult))
	{
		NowUIALogger::GetInstance()->LogInfor("[NowCommunication::getControlByCondition]" + mstrSignatureControl + "|" + mstrControlType);
		strSignatureControl = NowStringProcessor::StringToStlString(mstrSignatureControl);
		strControlType = NowStringProcessor::StringToStlString(mstrControlType);
	}
	return nResult ;
}

NOW_RESULT NowCommunication::bringWindowToTop( const string& strSignatureWindow )
{
	NowUIALogger::GetInstance()->LogInfor("[NowCommunication::bringWindowToTop]");
	String^ mstrSignatureWindow = NowStringProcessor::StlStringToString(strSignatureWindow);
	return NowUIACommunication::GetInstance()->BringWindowToTop(mstrSignatureWindow);
}


