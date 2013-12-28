#include "NowDefine.h"
#include "INowPlugin.h"
#include "NowPluginManager.h"
#include "NowLogger.h"
#include "NowDevice.h"

#include "NowControl_UIA.h"
#include "NowButton_UIA.h"

//NowPluginManager* pluginManager = NULL;
NowListPlugins lstPlugin = NULL;

void runDebug(INowPlugin* plugin, POINT currentPoint, INowControl*& pControl, string& strSignature);

int main( void ) 
{ 
	
	//pluginManager = new NowPluginManager();
	lstPlugin =  NowPluginManager::getInstance()->getListPlugins();

	POINT currentPoint;
	INowControl* pControl = NULL;
	string strSignature = "";

	while (true)
	{
		if (GetCursorPos(&currentPoint))
		{
			if (lstPlugin != NULL && lstPlugin->size() > 0)
			{
				for (vector<INowPlugin*>::iterator it = lstPlugin->begin(); it != lstPlugin->end(); ++it)
				{
					runDebug(*it, currentPoint, pControl, strSignature);
				}
			}
		}

		//TODO: check to place this Sleep method here???
		NowDevice::sleep(50);
	}

	system("pause");

	//delete pluginManager;
	return 0;
}

void runDebug(INowPlugin* plugin, POINT currentPoint, INowControl*& pControl, string& strSignature)
{
	NOW_RESULT nRet = plugin->getElementAtPoint(currentPoint, pControl);
	if (NOW_SUCCEED(nRet))
	{
		if (pControl != NULL)
		{
			pControl->getSignature(strSignature);
			if (NowPluginManager::getInstance()->isChangedControl(strSignature))
			{
				wstring wstrHelpText = L"";
				//GetHelpText
				int nOK = pControl->getHelpText(wstrHelpText);
				if (NOW_SUCCEED(nOK))
				{
					if (!wstrHelpText.empty())
					{
						NowLogger::getInstance()->LogWString(wstrHelpText);
					}
				}

				//GetCaption
				wstring wstrCaption = L"";
				nOK = pControl->getCaption(wstrCaption);
				if (NOW_SUCCEED(nOK))
				{
					NowLogger::getInstance()->LogWString(wstrCaption);
				}

				/*else
				{
					NowLogger::getInstance()->LogAString("FALSE!");
				}*/
				if (!NOW_SUCCEED(nOK)) 
				{
					NowLogger::getInstance()->LogAString("FALSE");
				}
			}
		}
		else
		{
			NowLogger::getInstance()->LogAString("Fail to get control");
		}
	}
} 