#include "now_lib_jni_NowJNICaller.h"
#include "NowDefine.h"
#include "NowLogger.h"
#include "NowPluginManager.h"

#include "INowControl.h"

//void runDebug(INowPlugin* plugin, POINT currentPoint, INowControl*& pControl, string& strSignature, wstring& wstrHelpText)
//{
//	NOW_RESULT nRet = plugin->getElementAtPoint(currentPoint, pControl);
//	printf("\nAfter getElementAtPoint");
//	if (NOW_SUCCEED(nRet))
//	{
//		if (pControl != NULL)
//		{
//			pControl->getSignature(strSignature);
//			printf("\nAfter getSignature");
//			if (NowPluginManager::getInstance()->isChangedControl(strSignature))
//			{
//				printf("\nAfter isChangedControl");
//				//wstring wstrHelpText = L"";
//				int nOK = pControl->getHelpText(wstrHelpText);
//				printf("\nAfter getHelpText");
//				if (NOW_SUCCEED(nOK))
//				{
//					if (!wstrHelpText.empty())
//					{
//						NowLogger::getInstance()->LogWString(wstrHelpText);
//					}
//				}
//				else
//				{
//					NowLogger::getInstance()->LogAString("FALSE!");
//				}
//			}
//		}
//		else
//		{
//			NowLogger::getInstance()->LogAString("Fail to get control");
//		}
//	}
//}

JNIEXPORT jstring JNICALL Java_now_lib_jni_NowJNICaller_getHelpText( JNIEnv * env, jobject obj)
{
	//NowLogger::getInstance()->LogAString("\n[JNICALL Java_now_lib_jni_NowJNICaller_getHelpText]");
	//(wstring(L"JNICALL Java_now_lib_jni_NowJNICaller_getHelpText")).c_str()
	//wstring wstr = (wchar_t *)env->GetStringChars(jstr, NULL);
	//wstring wstr = wstring(L"Phan Đức Chiến");
	//jstring jstr = env->NewString((jchar *)wstr.c_str(), wstr.length());
	//return env->NewString((jchar *)wstr.c_str(), wstr.length());

	POINT currentPoint; //GetCursorPos(&currentPoint);
	INowControl* pControl = NULL;
	string strSignature = "";
	wstring wstrHelpText = L"";
	NowListPlugins lstPlugins = NowPluginManager::getInstance()->getListPlugins();
	//printf("\nluginManager::getInstance()");
	if (GetCursorPos(&currentPoint))
	{
		//printf("\nGetCursorPos(&currentPoint)");
		if (lstPlugins != NULL && lstPlugins->size() > 0)
		{
			//printf("\nOK");
			for (vector<INowPlugin*>::iterator it = lstPlugins->begin(); it != lstPlugins->end(); ++it)
			{
				//printf("\nRunDebug");
				NOW_RESULT nRet = (*it)->getElementAtPoint(currentPoint, pControl);
				//printf("\nAfter getElementAtPoint");
				if (NOW_SUCCEED(nRet))
				{
					if (pControl != NULL)
					{
						pControl->getSignature(strSignature);
						//printf("\nAfter getSignature");
						if (NowPluginManager::getInstance()->isChangedControl(strSignature))
						{
							//printf("\nAfter isChangedControl");
							//wstring wstrHelpText = L"";
							int nOK = pControl->getHelpText(wstrHelpText);
							//printf("\nAfter getHelpText");
							if (NOW_SUCCEED(nOK))
							{
								if (!wstrHelpText.empty())
								{
									NowLogger::getInstance()->LogWString(wstrHelpText);
								}
							}
							else
							{
								//NowLogger::getInstance()->LogAString("FALSE!");
							}
						}
					}
					else
					{
						//NowLogger::getInstance()->LogAString("Fail to get control");
					}
				}
			}
		}
	}
	//printf("\n Return!!!!!!!");
	return env->NewString((jchar *)wstrHelpText.c_str(), wstrHelpText.length());
}

