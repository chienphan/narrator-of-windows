#include "StdAfx.h"
#include "NowExecutor.h"
#include "NowUtility.h"
#include "INowWindow.h"
#include "INowAction.h"
#include "NowActionData.h"
#include "NowActionManager.h"
#include "NowUtility.h"
#include "NowStringProcessor.h"

NOW_RESULT NowExecutor::initialize(const string& dataFileName)
{
	vector<vector<wstring>*>* vectorLessonData = NowUtility::readData(dataFileName);
	
	if (vectorLessonData == NULL)
	{
		return NOW_FALSE;
	}

	if (vectorLessonData->size() <= 0)
	{
		return NOW_FALSE;
	}

	vector<vector<wstring>*>::iterator it = vectorLessonData->begin();
	for (; it != vectorLessonData->end(); it++)
	{
		vector<wstring>* line = *it;
		string actionName = NowStringProcessor::wstringTostring(line->at(0));
		string data = NowStringProcessor::wstringTostring(line->at(1));
		//<lesson_no>=<content>
		//<lesson_name>=<content>
		//<lesson_description>=<content>
		if (actionName.compare("lesson_no") == 0
			|| actionName.compare("lesson_name") == 0
			|| actionName.compare("lesson_description") == 0)
		{
			//add to action data
			NowActionData::getInstance()->addLessonData(actionName, data);
		}
		//<window>=<window_name>|<window_title>
		else if (actionName.compare("window") == 0)
		{
			vector<wstring>* vectWindow = NowStringProcessor::split(line->at(1), NOW_DELIMITER_PARAM_W);
			if (vectWindow->size() == 2)
			{
				string strWindowName = NowStringProcessor::wstringTostring(vectWindow->at(0));
				string strWindowTitle = NowStringProcessor::wstringTostring(vectWindow->at(1));
				//add to action data
				NowActionData::getInstance()->addWindowData(strWindowName, strWindowTitle);
			}
		}
		//<control>=<window_name>|<control_name>|<property_1>;<value_1>|...
		else if (actionName.compare("control") == 0)
		{
			vector<wstring>* vectControl = NowStringProcessor::split(line->at(1), NOW_DELIMITER_PARAM_W);
			if (vectControl->size() > 2)
			{
				int nCounter = 0;
				string strWindowName  = "";
				string strControlName = "";
				string strProperties = "";

				vector<wstring>::iterator it = vectControl->begin();
				for (; it != vectControl->end(); it++)
				{
					if (nCounter == 0)
					{
						strWindowName = NowStringProcessor::wstringTostring(*it);
					}
					else if (nCounter == 1)
					{
						strControlName = NowStringProcessor::wstringTostring(*it);
					}
					else
					{
						vector<string>* vectArgument = NowStringProcessor::split(NowStringProcessor::wstringTostring(*it), NOW_DELIMITER_PROP_A);
						if (vectArgument->size() == 2)
						{
							strProperties += vectArgument->at(0) + NOW_CHAR_EQUAL + vectArgument->at(1) + NOW_CHAR_OR ; 
						}
					}
					nCounter++;
				}

				if (strProperties.size() > 0)
				{
					strProperties = strProperties.substr(0, strProperties.size() - 1);
				}

				//add to action data
				NowActionData::getInstance()->addControlData(strWindowName, strControlName, strProperties);
			}
		}
		//<action_name>=<action_argument_1>|<action_argument_2>>...
		else 
		{
			vector<wstring>* action = NowStringProcessor::split(line->at(1), NOW_DELIMITER_PARAM_W);
			action->insert(action->begin(), NowStringProcessor::Utf8ToStlWString(actionName));
			NowActionData::getInstance()->addActionData(action);
		}
	}
	
	return NOW_OK;
}

NOW_RESULT NowExecutor::doActions()
{
	NOW_RESULT nResult = NOW_FALSE;
	vector<vector<wstring>*>* lstActionData = NowActionData::getInstance()->getActionData();
	if (lstActionData == NULL)
	{
		return NOW_FALSE;
	}

	if (lstActionData->size() > 0)
	{
		vector<vector<wstring>*>::iterator it = lstActionData->begin();
		INowAction* pAction = NULL;
		for (; it != lstActionData->end(); it++)
		{
			vector<wstring>* actionData = *it;
			nResult = NowActionManager::getInstance()->getAction(NowStringProcessor::wstringTostring(actionData->at(0)), pAction);
			if (NOW_SUCCEED(nResult))
			{
				nResult = pAction->prepareArguments(actionData);
				if (NOW_SUCCEED(nResult))
				{
					nResult = pAction->doAction();
				}
			}
		}
	}
	return nResult;
}
