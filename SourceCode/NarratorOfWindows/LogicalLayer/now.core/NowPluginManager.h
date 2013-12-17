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

public:
	NowPluginManager(void);
	~NowPluginManager(void);
	
	vector<INowPlugin*>* LoadPlugins();

	bool isChangedControl(const string& strSignature);
};

#endif//_NOW_PLUGIN_MANAGER_H_