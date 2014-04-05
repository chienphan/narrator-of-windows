#include "StdAfx.h"
#include "NowExecutor.h"
#include "NowUtility.h"
#include "INowWindow.h"
#include "INowAction.h"
#include "NowActionData.h"
#include "NowActionManager.h"

NOW_RESULT NowExecutor::initialize(const string& dataFileName)
{
	vector<vector<string>*>* vectorLessonData = NowUtility::readData(dataFileName);
	
	if (vectorLessonData == NULL)
	{
		return NOW_FALSE;
	}

	if (vectorLessonData->size() <= 0)
	{
		return NOW_FALSE;
	}

	vector<vector<string>*>::iterator it = vectorLessonData->begin();
	for (; it != vectorLessonData->end(); it++)
	{
		vector<string>* line = *it;
		string actionName = line->at(0);

		//<lesson_no>=<content>
		//<lesson_name>=<content>
		//<lesson_description>=<content>
		if (actionName.compare("lesson_no") == 0
			|| actionName.compare("lesson_name") == 0
			|| actionName.compare("lesson_description") == 0)
		{
			//add to action data
			NowActionData::getInstance()->addLessonData(actionName, line->at(1));
		}
		//<window>=<window_name>|<window_title>
		else if (actionName.compare("window") == 0)
		{
			vector<string>* vectWindow = NowUtility::split(line->at(1), NOW_CHAR_OR);
			if (vectWindow->size() == 2)
			{
				string strWindowName  = vectWindow->at(0);
				string strWindowTitle = vectWindow->at(1);
				//add to action data
				NowActionData::getInstance()->addWindowData(strWindowName, strWindowTitle);
			}
		}
		//<control>=<window_name>|<control_name>|<property_1>;<value_1>|...
		else if (actionName.compare("control") == 0)
		{
			vector<string>* vectControl = NowUtility::split(line->at(1), NOW_CHAR_OR);
			if (vectControl->size() > 2)
			{
				int nCounter = 0;
				string strWindowName  = "";
				string strControlName = "";
				string strProperties = "";

				vector<string>::iterator it = vectControl->begin();
				for (; it != vectControl->end(); it++)
				{
					if (nCounter == 0)
					{
						strWindowName = *it;
					}
					else if (nCounter == 1)
					{
						strControlName = *it;
					}
					else
					{
						vector<string>* vectArgument = NowUtility::split(*it, NOW_CHAR_COLON);
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
			vector<string>* action = NowUtility::split(line->at(1), NOW_CHAR_OR);
			action->insert(action->begin(), actionName);
			NowActionData::getInstance()->addActionData(action);
		}
	}
	
	return NOW_OK;
}

NOW_RESULT NowExecutor::doActions()
{
	NOW_RESULT nResult = NOW_FALSE;
	vector<vector<string>*>* lstActionData = NowActionData::getInstance()->getActionData();
	if (lstActionData == NULL)
	{
		return NOW_FALSE;
	}

	if (lstActionData->size() > 0)
	{
		vector<vector<string>*>::iterator it = lstActionData->begin();
		INowAction* pAction = NULL;
		for (; it != lstActionData->end(); it++)
		{
			vector<string>* actionData = *it;
			nResult = NowActionManager::getInstance()->getAction(actionData->at(0), pAction);
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
}
