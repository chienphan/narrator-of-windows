#ifndef _NOW_PLUGIN_MANAGER_H_
#define _NOW_PLUGIN_MANAGER_H_

#include "NowDefine.h"
#include "INowPlugin.h"
/*
* This class load and manage plug-ins 
*/
#define DllExport   __declspec( dllexport )

class DllExport NowPluginManager 
{
private:
	static NowPluginManager* m_instance;
	static NowListPlugins m_lstPlugins;
	static NowListPlugins loadPlugins();

	string m_strSignature;
	INowControl* m_control;
	NowPluginManager(void);

public:
	static NowPluginManager* getInstance();
	~NowPluginManager(void);
	
	bool isChangedControl(const string& strSignature);
	NowListPlugins getListPlugins();
	NOW_RESULT keepControlToCache(INowControl* pControl);
	INowControl* getControlFromCache(const string& signature);
};

#endif//_NOW_PLUGIN_MANAGER_H_ 