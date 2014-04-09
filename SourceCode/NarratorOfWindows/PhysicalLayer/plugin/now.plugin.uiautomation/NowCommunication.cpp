#include "NowCommunication.h"
#include "NowStringProcessor.h"
#include "NowLogger.h"
#include "NowUIAActionDefine.h"
#include <stdio.h>
#include <stdlib.h>

#using "now.agent.uiautomation.client.dll"

using namespace now::agent::uiautomation::client::action;
using namespace now::agent::uiautomation::client::argument;
using namespace now::agent::uiautomation::client::communication;
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

	//Only get signature of element, runtimeElement need to keep at agent
	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GET_ELEMENT_AT_POINT;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_POINT_X, point.x);
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_POINT_Y, point.y);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		String^ mstrValue = NowUIAArgumentOut::GetInstance()->GetStringArgument();
		array<String^>^ arrValue = mstrValue->Split(*(NowStringProcessor::StringToStlWString(gcnew String("|")).c_str()));

		if (arrValue->Length == 2)
		{
			strSignatureControl = NowStringProcessor::StringToStlString(arrValue[0]);
			strControlType = NowStringProcessor::StringToStlString(arrValue[1]);
		}
		else
		{
			nResult = NOW_FALSE;
		}
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult;
}

NOW_RESULT NowCommunication::getUIProperty(const string& strSignature, const string& strPropName , wstring& wstrValue)
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	String^ mstrPropName = NowStringProcessor::StlStringToString(strPropName);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GETPROPERTY;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignature);
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_PROPERTY_NAME, mstrPropName);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		String^ mstrValue = NowUIAArgumentOut::GetInstance()->GetStringArgument();
		wstrValue = NowStringProcessor::StringToStlWString(mstrValue);
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult;
}

NOW_RESULT NowCommunication::getUIProperty(const string& strSignature, const string& strPropName , string& strValue)
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	String^ mstrPropName = NowStringProcessor::StlStringToString(strPropName);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GETPROPERTY;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignature);
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_PROPERTY_NAME, mstrPropName);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		String^ mstrValue = NowUIAArgumentOut::GetInstance()->GetStringArgument();
		strValue = NowStringProcessor::StringToStlString(mstrValue);
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult;
}

NOW_RESULT NowCommunication::getStatus(const string& strSignature , int& nState)
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GETSTATUS;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignature);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		nState = NowUIAArgumentOut::GetInstance()->GetIntArgument();
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult;
}

NOW_RESULT NowCommunication::getWindowByTitle( const string& strTitleWindow, string& strWindowHandle )
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrTitleWindow = NowStringProcessor::StlStringToString(strTitleWindow);
	//NowUIALogger::GetInstance()->LogInfor("[NowCommunication::getWindowByTitle]" + mstrTitleWindow);
	String^ mstrHandleWindow = "";
	nResult = NowUIACommunication::GetInstance()->GetWindowByTitle(mstrTitleWindow, mstrHandleWindow);
	if (NOW_SUCCEED(nResult))
	{
		//NowUIALogger::GetInstance()->LogInfor("[NowCommunication::getWindowByTitle] >>>>" + mstrHandleWindow);
		strWindowHandle = NowStringProcessor::StringToStlString(mstrHandleWindow);
	}
	return nResult ;	
}

NOW_RESULT NowCommunication::getControlByCondition( const string& strWindowHandle, const string& strPropsData, string& strSignatureControl, string& strControlType )
{
	//NowLogger::getInstance()->LogAString("[NowCommunication::getControlByCondition]");
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrWindowHandle = NowStringProcessor::StlStringToString(strWindowHandle);
	String^ mstrPropsData = NowStringProcessor::StlStringToString(strPropsData);
	String^ mstrSignatureControl = "";
	String^ mstrControlType = "";

	nResult = NowUIACommunication::GetInstance()->GetControlByCondition(mstrWindowHandle, mstrPropsData, mstrSignatureControl, mstrControlType);
	if (NOW_SUCCEED(nResult))
	{
		//NowUIALogger::GetInstance()->LogInfor("[NowCommunication::getControlByCondition]" + mstrSignatureControl + "|" + mstrControlType);
		strSignatureControl = NowStringProcessor::StringToStlString(mstrSignatureControl);
		strControlType = NowStringProcessor::StringToStlString(mstrControlType);
	}
	return nResult ;
}

NOW_RESULT NowCommunication::bringWindowToTop( const string& strSignatureWindow )
{
	//NowUIALogger::GetInstance()->LogInfor("[NowCommunication::bringWindowToTop]");
	String^ mstrSignatureWindow = NowStringProcessor::StlStringToString(strSignatureWindow);
	return NowUIACommunication::GetInstance()->BringWindowToTop(mstrSignatureWindow);
}


