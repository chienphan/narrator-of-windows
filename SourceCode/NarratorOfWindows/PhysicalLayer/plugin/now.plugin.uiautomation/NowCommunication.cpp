#include "NowCommunication.h"
#include "NowStringProcessor.h"
#include "NowLogger.h"

#using "now.agent.uiautomation.client.dll"

using namespace now::agent::uiautomation::client;
using namespace System::Diagnostics;
using namespace System;

NowCommunication* NowCommunication::m_instance = NULL;

NowCommunication::NowCommunication(void)
{
}

NowCommunication::~NowCommunication(void)
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
	//NowLogger::getInstance()->LogAString("[NowCommunication::getElementAtPoint] BEGIN");
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

	//NowLogger::getInstance()->LogAString(strSignatureControl);
	//NowLogger::getInstance()->LogAString(strControlType);

	//NowLogger::getInstance()->LogAString("[NowCommunication::getElementAtPoint] END");
	return nResult;
}

NOW_RESULT NowCommunication::getHelpText( const string& strSignature, wstring& wstrHelpText )
{
	//NowLogger::getInstance()->LogAString("[NowCommunication::getHelpText] - BEGIN");
	int nResult = NOW_FALSE;
	String^ mstrSignature = NowStringProcessor::StlStringToString(strSignature);
	String^ mstrHelpText = "";

	nResult = NowUIACommunication::GetInstance()->GetHelpTextProperty(mstrSignature, mstrHelpText);
	//NowLogger::getInstance()->LogAString(strSignature);
	if (NOW_SUCCEED(nResult))
	{
		//NowLogger::getInstance()->LogAString("[NowCommunication::getHelpText] OK!");
		wstrHelpText = NowStringProcessor::StringToStlWString(mstrHelpText);
		//NowLogger::getInstance()->LogWString(wstrHelpText);
	}
	//NowLogger::getInstance()->LogAString("[NowCommunication::getHelpText] - END");
	return nResult;
}