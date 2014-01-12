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
		//NowLogger::getInstance()->LogAString(" NOW_SUCCEED(nResult)");
		wstrValue = NowStringProcessor::StringToStlWString(mstrValue);
	}
	//NowLogger::getInstance()->LogWString(wstrValue);
	/*char buffer[512];
	sprintf_s(buffer, "%d ", nResult);
	NowLogger::getInstance()->LogAString(string(buffer));*/
	//NowLogger::getInstance()->LogWString(wstrValue);
	return nResult;
}

NOW_RESULT NowCommunication::getUIProperty(const string& strSignature, const string& strPropName , string& wstrValue)
{
	int nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	String^ mstrPropName = NowStringProcessor::StlStringToString(strPropName);
	String^ mstrValue = "";

	nResult = NowUIACommunication::GetInstance()->GetUIProperty(mstrSignature, mstrPropName, mstrValue);
	if (NOW_SUCCEED(nResult))
	{
		wstrValue = NowStringProcessor::StringToStlString(mstrValue);
	}
	return nResult;
}

NOW_RESULT NowCommunication::getUIState(const string& strSignature , string& strState)
{
	int nResult = NOW_FALSE;
	int nState = 0 ;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	String^ mstrStateName = "";
	int compareState = 0 ;

	/*char buffer[512];
	sprintf_s(buffer, "%d ", nState & NOW_STATE_SELECTED);
	NowLogger::getInstance()->LogAString(string(buffer));*/

	//get Selected State
	mstrStateName = NowStringProcessor::StlStringToString(NOW_PROP_IS_SELECTED);
	nResult = NowUIACommunication::GetInstance()->GetUIState(mstrSignature , mstrStateName , nState);
	if (!NOW_SUCCEED(nResult))
	{
		strState = strState + "";
	}
	else
	{

		compareState = nState & NOW_STATE_SELECTED;
		if (compareState == NOW_STATE_SELECTED )
		{
			strState = strState + " selected";
		}
		else if (compareState != NOW_STATE_SELECTED )
		{
			strState = strState + " not selected";
		}

	}

	//get Expanded state 
	nState = 0 ;
	mstrStateName = "";
	mstrStateName = NowStringProcessor::StlStringToString(NOW_PROP_IS_EXPANDED);
	nResult = NowUIACommunication::GetInstance()->GetUIState(mstrSignature , mstrStateName , nState);
	if (!NOW_SUCCEED(nResult))
	{
		strState = strState + "";
	}
	else
	{
		compareState = nState & NOW_STATE_EXPANDED ; 
		if (compareState == NOW_STATE_EXPANDED)
		{
			strState = strState + " Expanded";
		}
	}

	//get Collapsed state
	nState = 0 ;
	mstrStateName = "";
	mstrStateName = NowStringProcessor::StlStringToString(NOW_PROP_IS_COLLAPSED);
	nResult = NowUIACommunication::GetInstance()->GetUIState(mstrSignature , mstrStateName , nState);
	if (!NOW_SUCCEED(nResult))
	{
		strState = strState + "";
	}
	else
	{
		compareState = nState & NOW_STATE_COLLAPSED ; 
		if (compareState == NOW_STATE_COLLAPSED)
		{
			strState = strState + " Collapsed";
		}
	}

	//get Leaf Node state
	nState = 0 ;
	mstrStateName = "";
	mstrStateName = NowStringProcessor::StlStringToString(NOW_PROP_IS_LEAF_NODE);
	nResult = NowUIACommunication::GetInstance()->GetUIState(mstrSignature , mstrStateName , nState);
	if (!NOW_SUCCEED(nResult))
	{
		strState = strState + "";
	}
	else
	{
		compareState = nState & NOW_STATE_LEAF_NODE ; 
		if (compareState == NOW_STATE_LEAF_NODE)
		{
			strState = strState + " Leaf Node";
		}
	}
	return NOW_OK;		
}