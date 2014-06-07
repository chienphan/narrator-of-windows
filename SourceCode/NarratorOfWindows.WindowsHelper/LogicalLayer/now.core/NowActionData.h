#ifndef _NOW_ACTION_DATA_H_
#define _NOW_ACTION_DATA_H_

#include "NowDefine.h"

class DllExport NowActionData
{
private:
	NowActionData(void);
	static NowActionData* m_instance;

	map<string, string>* m_mapLesson;					//<name, data>
	map<string, string>* m_mapWindow;					//<window_name, window_title>
	map<string, string>* m_mapControl;					//<control_name, window_name>
	map<string, string>* m_mapControlProps;		//<control_name, properties>
	vector<vector<wstring>*>* m_vectActions;				//<action_name><action_prarameters....>

public:
	static NowActionData* getInstance();
	~NowActionData(void);

	NOW_RESULT addLessonData(string name, string data);
	NOW_RESULT addWindowData(string strWindowName, string strWindowTitle);
	NOW_RESULT addControlData(string strWindowName, string strControlName, string strPropsData);
	NOW_RESULT addActionData(vector<wstring>* action);

	NOW_RESULT getWindowTitle(string strWindowName, string& strWindowTitle);
	NOW_RESULT getWindowName(string strControlName, string& strWindowName);
	NOW_RESULT getControlData(string strControlName, string& strPropsData);
	vector<vector<wstring>*>* getActionData();
};

#endif


