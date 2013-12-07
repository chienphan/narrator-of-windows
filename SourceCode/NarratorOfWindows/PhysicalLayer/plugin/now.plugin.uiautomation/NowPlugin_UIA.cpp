#include "NowDefine.h"
#include "NowPlugin_UIA.h"
#include "NowStringProcessor.h"
#include "NowLogger.h"
#include "NowButton.h"
#include "NowControl.h"

#using "now.agent.uiautomation.client.dll"

using namespace now::agent::uiautomation::client;
using namespace System::Diagnostics;
using namespace System;

NowPlugin_UIA* NowPlugin_UIA::m_pInstance = NULL;

NowPlugin_UIA::NowPlugin_UIA()
{
	m_strPluginName = "uiautomation";
	m_strControlSignature = "";
}

NowPlugin_UIA::~NowPlugin_UIA()
{
}

NowPlugin_UIA* NowPlugin_UIA::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new NowPlugin_UIA();
	}
	return m_pInstance;
}

string NowPlugin_UIA::getPluginName()
{
	return m_strPluginName;
}

NOW_RESULT NowPlugin_UIA::getElementAtPoint( POINT point, NowControl*& pControl )
{
	NOW_RESULT nResult = NOW_FALSE;

	System::Windows::Point newPoint;
	newPoint.X = point.x;
	newPoint.Y = point.y;

	AutomationElement^ runtimeElement = NowAutomationService::GetInstance()->GetElementAtPoint(newPoint);
	Sleep(100);
	if (runtimeElement != nullptr)
	{
		if (isChangedControl(runtimeElement))
		{
			wstring wstrHelpText = L"";
			try{
				wstrHelpText = NowStringProcessor::StringToStlWString(runtimeElement->Current.HelpText);
			}
			catch(Exception^ ex)
			{
				//TODO: need to implement
				NowLogger::getInstance()->LogWString(NowStringProcessor::StringToStlWString(String::Format("[Exception][{0}]",ex->Message)));
			}
			NowLogger::getInstance()->LogWString(wstrHelpText);

			pControl = safe_cast<NowControl*>(new NowButton());

			nResult = NOW_OK;
		}
	}

	return nResult;
}

bool NowPlugin_UIA::isChangedControl( AutomationElement^ runtimeElement )
{
	bool blnResult = false;
	string strNewSignature = getSignatureControl(runtimeElement);
	if (m_strControlSignature.compare(strNewSignature) != 0)
	{
		m_strControlSignature = strNewSignature;
		blnResult = true;
	}
	return blnResult;
}

string NowPlugin_UIA::getSignatureControl( AutomationElement^ runtimeElement )
{
	char buffer[NOW_MAXLENGTH];
	itoa(runtimeElement->GetHashCode(), buffer, 10);
	return string(buffer);
}

