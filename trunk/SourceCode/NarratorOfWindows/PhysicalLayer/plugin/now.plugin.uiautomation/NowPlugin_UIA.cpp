#include "NowPlugin_UIA.h"
#include "NowDefine_UIA.h"
#using "now.agent.uiautomation.client.dll"

using namespace now::agent::uiautomation::client;
using namespace System;

NowPlugin::NowPlugin(void)
{
}

NowPlugin::~NowPlugin(void)
{
}

int NowPlugin::printName(int x, int y, std::string& strTemp)
{
	NowAutomationElement^ element = gcnew NowAutomationElement();
	String^ strResult = element->GetElementAtPoint(x, y);

	return 1;
}
