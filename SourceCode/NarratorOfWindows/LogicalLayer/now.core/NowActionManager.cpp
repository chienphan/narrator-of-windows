#include "NowActionManager.h"
#include "INowAction.h"

#include "NowActionClick.h"
#include "NowActionTypeKey.h"

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
	m_mapAction->insert(pair<string, INowAction*>(NOW_ACTION_TYPE_KEY, new NowActionTypeKey()));
}

