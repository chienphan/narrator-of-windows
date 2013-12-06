#include "NowDefine.h"
#include "NowPluginManager.h"

int main( void ) 
{ 

	NowPluginManager* pluginManager = new NowPluginManager();
	INowPlugin* plugin =  pluginManager->LoadPlugins();

	

	POINT currentPoint;

	char buffer[256];
	std::string strTemp = "";

	while (true)
	{
		if (GetCursorPos(&currentPoint))
		{
			sprintf(buffer, "[%d]\t[%d]\n", currentPoint.x, currentPoint.y);
			printf(buffer);
			plugin->printName((int)currentPoint.x, (int)currentPoint.y, strTemp);
		}
		Sleep(100);
	}

	system("pause");

	delete pluginManager;
	return 0;
}