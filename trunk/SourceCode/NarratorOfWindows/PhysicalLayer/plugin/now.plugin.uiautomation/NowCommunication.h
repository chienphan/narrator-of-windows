#ifndef _NOW_COMMUNICATION_H_
#define _NOW_COMMUNICATION_H_

#include "NowDefine.h"

class NowCommunication
{
private:
	static NowCommunication* m_instance;
	NowCommunication();
public:
	static NowCommunication* getInstance();
	~NowCommunication();

	NOW_RESULT getElementAtPoint(POINT point, string& strSignatureControl, string& strControlType);
	NOW_RESULT getUIProperty(const string& strSignature, const string& strPropName , wstring& wstrValue); // return wstring
	NOW_RESULT getUIProperty(const string& strSignature, const string& strPropName , string& strValue);	// return string
	NOW_RESULT getStatus(const string& strSignature , int& strState);

	NOW_RESULT getWindowByTitle(const string& strTitleWindow, string& strWindowHandle);
	NOW_RESULT getControlByCondition(const string& strWindowHandle, const string& strPropsData, string& strSignatureControl, string& strControlType);
	NOW_RESULT bringWindowToTop(const string& strSignatureWindow);
	NOW_RESULT clearCache();
	NOW_RESULT setValue(const string& strSignature, const wstring& wstrValue);
};

#endif