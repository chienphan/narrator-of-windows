// now.play.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NowExecutor.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//Hide the console window
	//ShowWindow(GetConsoleWindow(), SW_HIDE);

	//Read the resource file, ex: lesson001.dat
		//After read file, we will have a list of ACTIONS and DEFINE to "DoWork"
	if(!NowExecutor::initialize("\\data\\lesson001.dat") == NOW_OK)
	{
		return 1;
	}

	//if DEFINE: we will prepare WINDOWS and CONTROLS
		//in this case: we will have a MAP of windows and controls

	//if ACTIONS: we will call "DoWork" method to actions

	//Sleep(5000);

	//ShowWindow(GetConsoleWindow(), SW_NORMAL);
	system("pause");
	return 0;
}

