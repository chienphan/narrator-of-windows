#include "NowDefine.h"
#include "NowPluginManager.h"

int main( void ) 
{ 

	NowPluginManager* pluginManager = new NowPluginManager();
	pluginManager->LoadPlugins();
	system("pause");

	delete pluginManager;
	return 0;
}