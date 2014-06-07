// now.play.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NowExecutor.h"
#include "NowActionManager.h"
#include "NowStringProcessor.h"
#include "NowSetting.h"
#include "NowLogger.h"

int _tmain(int argc, _TCHAR* argv[])
{
	NOW_RESULT nResult = NOW_FALSE;
	string strArg = "";
	string strSpeed = "";
	if (argc == 3)
	{
		strArg = NowStringProcessor::wstringTostring(wstring(argv[1]));
		strSpeed = NowStringProcessor::wstringTostring(wstring(argv[2]));
	}
	else
	{
		return -1;
	}
	if (strArg.empty())
	{
		return -1;
	}

	NowLogger::getInstance()->LogAString("[NOW-PLAY][main]speed=" + strSpeed);
	NowSetting::getInstance()->setSleepTime(strSpeed);

	//Hide the console window
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	NowActionManager::getInstance()->initialize();
	//Read the resource file, ex: lesson001.dat
		//After read file, we will have a list of ACTIONS and DEFINE to "DoWork"
	nResult = NowExecutor::initialize(strArg);
	if(NOW_SUCCEED(nResult))
	{
		//TODO: begin to actions here!!!
		NowExecutor::doActions();
	}
	//ShowWindow(GetConsoleWindow(), SW_NORMAL);
	return 0;
}

