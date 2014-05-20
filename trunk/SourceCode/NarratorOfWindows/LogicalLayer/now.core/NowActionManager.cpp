#include "NowActionManager.h"
#include "INowAction.h"

#include "NowActionClick.h"
#include "NowActionEnter.h"
#include "NowActionSleep.h"
#include "NowActionSendKeys.h"
#include "NowActionSendData.h"
#include "NowActionClearCache.h"
#include "NowActionScrollIntoView.h"

NowActionManager* NowActionManager::m_instance = NULL;

NowActionManager::NowActionManager(void)
{
	m_mapAction = new map<string, INowAction*>();
}

NowActionManager::~NowActionManager(void)
{
}

NowActionManager* NowActionManager::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new NowActionManager();
	}
	return m_instance;
}

NOW_RESULT NowActionManager::getAction( const string& actionName, INowAction*& pAction )
{
	map<string, INowAction*>::iterator it = m_mapAction->find(actionName);
	if (it != m_mapAction->end())
	{
		pAction = it->second;
		return NOW_OK;
	}
	return NOW_FALSE;
}

void NowActionManager::initialize()
{
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_CLICK, new NowActionClick()));
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_ENTER, new NowActionEnter()));
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_SLEEP, new NowActionSleep()));
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_SENDKEYS, new NowActionSendKeys()));
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_SEND_DATA, new NowActionSendData()));
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_CLEAR_CACHE, new NowActionClearCache()));
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_SCROLL_INTO_VIEW, new NowActionScrollIntoView()));
}

