#ifndef _NOW_PLUGIN_MANAGER_H_
#define _NOW_PLUGIN_MANAGER_H_

#include "NowDefine.h"
#include "INowPlugin.h"
/*
* This class load and manage plug-ins 
*/

class NowPluginManager 
{
public:
	NowPluginManager(void);
	~NowPluginManager(void);
	INowPlugin* LoadPlugins();
};

#endif//_NOW_PLUGIN_MANAGER_H_