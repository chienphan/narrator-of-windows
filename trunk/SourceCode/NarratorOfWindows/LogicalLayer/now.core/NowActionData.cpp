#include "NowActionData.h"

NowActionData* NowActionData::m_instance = NULL;

NowActionData::NowActionData(void)
{
	m_mapLesson = new map<string, string>();
	m_mapWindow = new map<string, string>();
	m_mapControl = new map<string, string>();
	m_mapControlProps = new map<string, string>();
	m_vectActions = new vector<vector<string>*>();
}


NowActionData::~NowActionData(void)
{
}

NowActionData* NowActionData::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new NowActionData();
	}
	return m_instance;
}

NOW_RESULT NowActionData::addLessonData(string name, string data)
{
	map<string, string>::iterator it = m_mapLesson->find(name);
	if (it == m_mapLesson->end())
	{
		m_mapLesson->insert(pair<string, string>(name, data));
	}
	return NOW_OK;
}

NOW_RESULT NowActionData::addWindowData( string strWindowName,  string strWindowTitle )
{
	map<string, string>::iterator it = m_mapWindow->find(strWindowName);
	if (it == m_mapWindow->end())
	{
		m_mapWindow->insert(pair<string, string>(strWindowName, strWindowTitle));
	}
	return NOW_OK;
}

NOW_RESULT NowActionData::addControlData(string strWindowName, string strControlName, string strPropsData)
{
	map<string, string>::iterator it = m_mapControl->find(strControlName);
	if (it == m_mapControl->end())
	{
		m_mapControl->insert(pair<string, string>(strControlName, strWindowName));
	}
	map<string, string>::iterator itProp = m_mapControlProps->find(strControlName);
	if (itProp == m_mapControlProps->end())
	{
		m_mapControlProps->insert(pair<string, string>(strControlName, strPropsData));
	}

	return NOW_OK;
}

NOW_RESULT NowActionData::getWindowTitle( string strWindowName, string& strWindowTitle )
{
	map<string, string>::iterator it = m_mapWindow->find(strWindowName);
	if (it != m_mapWindow->end())
	{
		strWindowTitle = it->second;
		return NOW_OK;
	}
	return NOW_FALSE;
}

NOW_RESULT NowActionData::getWindowName( string strControlName, string& strWindowName )
{
	map<string, string>::iterator it = m_mapControl->find(strControlName);
	if (it != m_mapControl->end())
	{
		strWindowName = it->second;
		return NOW_OK;
	}
	return NOW_FALSE;
}

NOW_RESULT NowActionData::addActionData( vector<string>* action )
{
	m_vectActions->push_back(action);
	return NOW_OK;
}

vector<vector<string>*>* NowActionData::getActionData()
{
	return m_vectActions;
}

NOW_RESULT NowActionData::getControlData( string strControlName, string& strPropsData )
{
	map<string, string>::iterator it = m_mapControlProps->find(strControlName);
	if (it != m_mapControlProps->end())
	{
		strPropsData = it->second;
		return NOW_OK;
	}
	return NOW_FALSE;
}
