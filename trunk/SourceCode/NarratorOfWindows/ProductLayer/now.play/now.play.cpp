// now.play.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NowExecutor.h"
#include "NowActionManager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	NOW_RESULT nResult = NOW_FALSE;
	//Hide the console window
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	NowActionManager::getInstance()->initialize();
	//Read the resource file, ex: lesson001.dat
		//After read file, we will have a list of ACTIONS and DEFINE to "DoWork"
	nResult = NowExecutor::initialize("\\data\\lesson001.dat");
	if(NOW_SUCCEED(nResult))
	{
		//TODO: begin to actions here!!!
		NowExecutor::doActions();
	}

	//if DEFINE: we will prepare WINDOWS and CONTROLS
		//in this case: we will have a MAP of windows and controls

	//if ACTIONS: we will call "DoWork" method to actions

	//Sleep(5000);

	//ShowWindow(GetConsoleWindow(), SW_NORMAL);
	//system("pause");
	return 0;
}

