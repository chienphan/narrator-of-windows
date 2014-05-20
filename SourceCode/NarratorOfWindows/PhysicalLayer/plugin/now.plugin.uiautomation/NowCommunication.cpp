#include "NowCommunication.h"
#include "NowStringProcessor_UIA.h"
#include "NowLogger.h"
#include "NowUIAActionDefine.h"
#include <stdio.h>
#include <stdlib.h>

#using "now.agent.uiautomation.client.dll"

using namespace now::agent::uiautomation::client::action;
using namespace now::agent::uiautomation::client::argument;
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
		array<String^>^ arrValue = mstrValue->Split(*(NowStringProcessor_UIA::StringToStlWString(gcnew String("|")).c_str()));

		if (arrValue->Length == 2)
		{
			strSignatureControl = NowStringProcessor_UIA::StringToStlString(arrValue[0]);
			strControlType = NowStringProcessor_UIA::StringToStlString(arrValue[1]);
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
	String^ mstrSignature = NowStringProcessor_UIA::StlStringToString(strSignature);
	String^ mstrPropName = NowStringProcessor_UIA::StlStringToString(strPropName);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GETPROPERTY;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignature);
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_PROPERTY_NAME, mstrPropName);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		String^ mstrValue = NowUIAArgumentOut::GetInstance()->GetStringArgument();
		wstrValue = NowStringProcessor_UIA::StringToStlWString(mstrValue);
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult;
}

NOW_RESULT NowCommunication::getUIProperty(const string& strSignature, const string& strPropName , string& strValue)
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor_UIA::StlStringToString(strSignature);
	String^ mstrPropName = NowStringProcessor_UIA::StlStringToString(strPropName);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GETPROPERTY;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignature);
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_PROPERTY_NAME, mstrPropName);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		String^ mstrValue = NowUIAArgumentOut::GetInstance()->GetStringArgument();
		strValue = NowStringProcessor_UIA::StringToStlString(mstrValue);
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult;
}

NOW_RESULT NowCommunication::getStatus(const string& strSignature , int& nState)
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor_UIA::StlStringToString(strSignature);

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
	String^ mstrTitleWindow = NowStringProcessor_UIA::StlStringToString(strTitleWindow);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GET_WINDOW_BY_TITLE;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_WINDOW_TITLE, mstrTitleWindow);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		String^ mstrHandleWindow = NowUIAArgumentOut::GetInstance()->GetStringArgument();
		strWindowHandle = NowStringProcessor_UIA::StringToStlString(mstrHandleWindow);
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult;
}

NOW_RESULT NowCommunication::getControlByCondition( const string& strWindowHandle, const string& strPropsData, string& strSignatureControl, string& strControlType )
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrWindowHandle = NowStringProcessor_UIA::StlStringToString(strWindowHandle);
	String^ mstrPropsData = NowStringProcessor_UIA::StlStringToString(strPropsData);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_GET_CONTROL_BY_CONDITION;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_DATA, mstrPropsData);
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_WINDOW_HANDLE, mstrWindowHandle);
	
	nResult = NowUIAActionManager::GetInstance()->DoAction();

	if (NOW_SUCCEED(nResult))
	{
		String^ mstrValue = NowUIAArgumentOut::GetInstance()->GetStringArgument();
		array<String^>^ arrValue = mstrValue->Split(*(NowStringProcessor_UIA::StringToStlWString(gcnew String("|")).c_str()));

		if (arrValue->Length == 2)
		{
			strSignatureControl = NowStringProcessor_UIA::StringToStlString(arrValue[0]);
			strControlType = NowStringProcessor_UIA::StringToStlString(arrValue[1]);
		}
		else
		{
			nResult = NOW_FALSE;
		}
	}
	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult ;
}

NOW_RESULT NowCommunication::bringWindowToTop( const string& strSignatureWindow )
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignatureWindow = NowStringProcessor_UIA::StlStringToString(strSignatureWindow);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_BRING_WINDOW_TO_TOP;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignatureWindow);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult ;
}

NOW_RESULT NowCommunication::clearCache()
{
	NOW_RESULT nResult = NOW_FALSE;

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_CLEAR_CACHE;

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult ;
}

NOW_RESULT NowCommunication::setValue( const string& strSignature, const wstring& wstrValue )
{
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor_UIA::StlStringToString(strSignature);
	String^ mstrValue = NowStringProcessor_UIA::StlWStringToString(wstrValue);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_SET_VALUE;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignature);
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_VALUE, mstrValue);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	return nResult ;
}

NOW_RESULT NowCommunication::scrollIntoView( const string& strSignature )
{
	NowLogger::getInstance()->LogAString("[NowCommunication::scrollIntoView] IN");
	NOW_RESULT nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor_UIA::StlStringToString(strSignature);

	NowUIAArgumentIn::GetInstance()->ActionName = UIA_ACTION_SCROLL_INTO_VIEW;
	NowUIAArgumentIn::GetInstance()->AddArgument(UIA_PROP_SIGNATURE, mstrSignature);

	nResult = NowUIAActionManager::GetInstance()->DoAction();

	//Clear data
	NowUIAArgumentIn::GetInstance()->ClearArguments();
	NowLogger::getInstance()->LogAString("[NowCommunication::scrollIntoView] OUT");
	return nResult ;
}
