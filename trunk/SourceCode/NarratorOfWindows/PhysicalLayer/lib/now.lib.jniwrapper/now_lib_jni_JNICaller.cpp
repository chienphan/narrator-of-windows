#include "now_lib_jni_JNICaller.h"
#include "NowDefine.h"
#include "NowLogger.h"
#include "NowPluginManager.h"

#include "INowControl.h"

JNIEXPORT jstring JNICALL Java_now_lib_jni_JNICaller_getControlSignatureUnderMouse( JNIEnv * env, jobject jObject)
{
	POINT currentPoint;
	INowControl* pControl = NULL;
	string strSignature = "";

	//Get list of plug-ins 
	NowListPlugins lstPlugins = NowPluginManager::getInstance()->getListPlugins();

	if (GetCursorPos(&currentPoint))
	{
		if (lstPlugins != NULL && lstPlugins->size() > 0)
		{
			//For each plug-in, try to get control element. If succeed, we will have the control
			for (vector<INowPlugin*>::iterator it = lstPlugins->begin(); it != lstPlugins->end(); ++it)
			{
				//Get control element at mouse point and keep to cache if succeed
				NOW_RESULT nRet = (*it)->getElementAtPoint(currentPoint, pControl);
				if (NOW_SUCCEED(nRet))
				{
					if (pControl != NULL)
					{
						//Get control signature
						pControl->getSignature(strSignature);
						break;
					}
				}
			}
		}
	}
	return env->NewStringUTF(strSignature.c_str());
}

JNIEXPORT jstring JNICALL Java_now_lib_jni_JNICaller_getUIInformation( JNIEnv * env, jobject jObject, jstring signature)
{
	wstring wstrResult = L"";
	string strSignature = string(env->GetStringUTFChars(signature, false));
	INowControl* pControl = NowPluginManager::getInstance()->getControlFromCache(strSignature);
	if (pControl)
	{
		if (NOW_SUCCEED(pControl->getUIInformation(wstrResult)))
		{
			return env->NewString((jchar *)wstrResult.c_str(), wstrResult.length());
		}
	}
	return env->NewStringUTF("");
}

JNIEXPORT jstring JNICALL Java_now_lib_jni_JNICaller_getControlProperty( JNIEnv * env, jobject jObject, jstring signature, jstring propertyName)
{
	wstring wstrResult = L"";
	string strSignature = string(env->GetStringUTFChars(signature, false));
	string strPropName = string(env->GetStringUTFChars(propertyName, false));
	INowControl* pControl = NowPluginManager::getInstance()->getControlFromCache(strSignature);
	if (pControl)
	{
		if (NOW_SUCCEED(pControl->getUIProperty(strPropName, wstrResult)))
		{
			return env->NewString((jchar *)wstrResult.c_str(), wstrResult.length());
		}
	}
	return env->NewStringUTF("");
}
