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
	string m_strSignature;
	static NowPluginManager* m_instance;
	static NowListPlugins m_lstPlugins;

	NowPluginManager(void);

	static NowListPlugins loadPlugins();
public:
	static NowPluginManager* getInstance();
	~NowPluginManager(void);
	
	bool isChangedControl(const string& strSignature);

	NowListPlugins getListPlugins();
};

#endif//_NOW_PLUGIN_MANAGER_H_ 