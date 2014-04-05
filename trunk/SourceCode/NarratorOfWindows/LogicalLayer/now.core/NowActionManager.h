#ifndef _NOW_ACTION_MANAGER_H_
#define _NOW_ACTION_MANAGER_H_

#include "NowDefine.h"

class DllExport NowActionManager
{
private:
	NowActionManager(void);
	static NowActionManager* m_instance;
	map<string, INowAction*>* m_mapAction;
public:
	static NowActionManager* getInstance();
	~NowActionManager(void);

	void initialize();
	NOW_RESULT getAction(const string& actionName, INowAction*& pAction);
};

#endif


