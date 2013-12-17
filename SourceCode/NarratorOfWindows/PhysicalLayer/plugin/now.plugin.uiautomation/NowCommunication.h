#ifndef _NOW_COMMUNICATION_H_
#define _NOW_COMMUNICATION_H_

#include "NowDefine.h"

class NowCommunication
{
private:
	static NowCommunication* m_instance;
	NowCommunication(void);
public:
	static NowCommunication* getInstance();
	~NowCommunication(void);

	NOW_RESULT getElementAtPoint(POINT point, string& strSignatureControl, string& strControlType);
	NOW_RESULT getHelpText(const string& strSignature, wstring& wstrHelpText);
};

#endif