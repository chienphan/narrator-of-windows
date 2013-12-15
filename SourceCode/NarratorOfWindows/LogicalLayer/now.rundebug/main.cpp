#include "NowDefine.h"
#include "INowPlugin.h"
#include "NowPluginManager.h"
#include "NowLogger.h"
#include "NowDevice.h"

#include "NowControl_UIA.h"
#include "NowButton_UIA.h"

int main( void ) 
{ 
	
	NowPluginManager* pluginManager = new NowPluginManager();
	INowPlugin* plugin =  pluginManager->LoadPlugins();

	POINT currentPoint;

	INowControl* pControl = NULL;

	while (true)
	{
		if (GetCursorPos(&currentPoint))
		{
			NOW_RESULT nRet = plugin->getElementAtPoint(currentPoint, pControl);
			if (NOW_SUCCEED(nRet))
			{
				if (pControl != NULL)
				{
					wstring wstrHelpText = L"";
					pControl->getHelpText(wstrHelpText);
					NowLogger::getInstance()->LogWString(wstrHelpText);
				}
				else
				{
					NowLogger::getInstance()->LogAString("Fail to get control");
				}
			}
		}
	}

	system("pause");

	delete pluginManager;
	return 0;
}