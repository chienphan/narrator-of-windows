#include "StdAfx.h"
#include "NowExecutor.h"
#include "NowUtility.h"
#include "INowWindow.h"
#include "NowMatching.h"
#include "NowStorage.h"

NOW_RESULT NowExecutor::initialize(const string& dataFileName)
{
	NOW_RESULT nResult = NOW_OK;
	vector<vector<string>*>* vectorLessonData = NowUtility::readData(dataFileName);
	
	vector<vector<string>*>::iterator it = vectorLessonData->begin();
	for (; it != vectorLessonData->end(); it++)
	{
		vector<string>* line = *it;
		string actionName = line->at(0);
		if (actionName.compare("lesson_no") == 0)
		{
			//TODO: Get lesson no. here!
		}
		else if (actionName.compare("lesson_name") == 0)
		{
			//TODO: Get lesson name. here!
		}
		else if (actionName.compare("lesson_description") == 0)
		{
			//TODO: Get lesson description. here!
		}
		else if (actionName.compare("window") == 0)
		{
			INowWindow* pWindow = NULL;
			vector<string>* vectWindow = NowUtility::split(line->at(1), NOW_CHAR_OR);
			if (vectWindow->size() == 2)
			{
				const char* szWindowName  = vectWindow->at(0).c_str();
				const char* szWindowTitle = vectWindow->at(1).c_str();
				//Matching the window
				nResult = NowMatching::getInstance()->matchWindow(szWindowTitle, pWindow);

				//keep pWindow to store
				nResult = NowStorage::getInstance()->keepWindowToStorage(szWindowName, pWindow);
			}
		}
		else if (actionName.compare("control") == 0)
		{
			printf("[control][%s]\n", line->at(1).c_str());
		}
		else 
		{
			printf("[action][%s]\n", line->at(1).c_str());
		}

		//kill method if false
		if (nResult == NOW_FALSE)
		{
			return nResult;
		}
	}
	
	return NOW_OK;
}
