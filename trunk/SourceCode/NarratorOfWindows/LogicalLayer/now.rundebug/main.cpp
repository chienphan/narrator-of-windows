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
	string strSignature = "";
	while (true)
	{
		if (GetCursorPos(&currentPoint))
		{
			NOW_RESULT nRet = plugin->getElementAtPoint(currentPoint, pControl);
			if (NOW_SUCCEED(nRet))
			{
				if (pControl != NULL)
				{
					pControl->getSignature(strSignature);
					if (pluginManager->isChangedControl(strSignature))
					{
						wstring wstrHelpText = L"";
						int nOK = pControl->getHelpText(wstrHelpText);
						
						if (NOW_SUCCEED(nOK))
						{
							if (!wstrHelpText.empty())
							{
								NowLogger::getInstance()->LogWString(wstrHelpText);
							}
						}
						else
						{
							NowLogger::getInstance()->LogAString("FALSE!");
						}
					}
				}
				else
				{
					NowLogger::getInstance()->LogAString("Fail to get control");
				}
			}
		}

		//TODO: check to place this Sleep method here???
		//NowDevice::sleep(100);
	}

	system("pause");

	delete pluginManager;
	return 0;
}