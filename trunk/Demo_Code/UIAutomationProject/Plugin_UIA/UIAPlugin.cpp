#include "UIAPlugin.h"
#include <vector>
#include <string>

using namespace System;
using namespace UIACommonLib;

std::vector<int> UIAPlugin::getAllHandleWindows()
{
	String^ strListTopWindowsHandle = UIAElementManager::GetInstance()->GetAllTopWindows();
	return std::vector<int>();
}
