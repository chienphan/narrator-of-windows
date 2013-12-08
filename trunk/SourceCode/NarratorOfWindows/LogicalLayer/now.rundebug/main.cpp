#include "NowDefine.h"
#include "INowPlugin.h"
#include "NowPluginManager.h"
#include "NowLogger.h"
#include "NowDevice.h"

int main( void ) 
{ 
	
	NowPluginManager* pluginManager = new NowPluginManager();
	INowPlugin* plugin =  pluginManager->LoadPlugins();

	POINT currentPoint;

	wstring strTemp = L"";

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
					//NowLogger::getInstance()->LogAString("<>null");
					//NowLogger::getInstance()->LogWString(L"Cộng hòa xã hội chũ nghĩa!");
					//NowLogger::getInstance()->LogAString(pControl->getControlType().c_str());
				}
				else
				{
					//wstring wstrTemp = L"Cộng hòa xã hội chũ nghĩa!";
					//NowLogger::getInstance()->LogWString(wstrTemp);
					//NowLogger::getInstance()->LogAString("null");
				}
				//string strTemp = pControl->getControlType();
				//wcout<<strTemp.c_str()<<endl;
				//wcout<<L"================================================="<<endl;
			}
		}
	}

	system("pause");

	delete pluginManager;
	return 0;
}