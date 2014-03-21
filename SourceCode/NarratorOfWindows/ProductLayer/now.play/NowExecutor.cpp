#include "StdAfx.h"
#include "NowExecutor.h"
#include "NowUtility.h"

NOW_RESULT NowExecutor::initialize(const string& dataFileName)
{
	NOW_RESULT nResult = NOW_FALSE;
	int counter = 0;
	vector<vector<string>*>* vectorLessonData = NowUtility::readData(dataFileName);
	
	vector<vector<string>*>::iterator it = vectorLessonData->begin();
	for (; it != vectorLessonData->end(); it++)
	{
		vector<string>* line = *it;
		string actionName = line->at(0);
		if (actionName.compare("lesson_no") == 0)
		{
			//TODO: Get lesson no. here!
			counter++;
		}
		else if (actionName.compare("lesson_name") == 0)
		{
			//TODO: Get lesson name. here!
			counter++;
		}
		else if (actionName.compare("lesson_description") == 0)
		{
			//TODO: Get lesson description. here!
			counter++;
		}
		else if (actionName.compare("window") == 0)
		{
			printf("[window][%s]\n", line->at(1).c_str());
			counter++;
		}
		else if (actionName.compare("control") == 0)
		{
			printf("[control][%s]\n", line->at(1).c_str());
			counter++;
		}
		else 
		{
			printf("[action][%s]\n", line->at(1).c_str());
			counter++;
		}
	}

	if (counter > 5)
	{
		nResult = NOW_OK;
	}

	return nResult;
}
