#ifndef _NOW_MATCHING_H_
#define _NOW_MATCHING_H_

#include "NowDefine.h"
#include "INowWindow.h"

class DllExport NowMatching
{
private:
	static NowMatching* m_instance;
	NowMatching(void);

	NOW_RESULT getWindowHandle(const char* szControlName, string& strWindowHandle);

public:
	static NowMatching* getInstance();
	~NowMatching(void);

	NOW_RESULT matchWindow(const char* szWindowName);
	NOW_RESULT matchControl(const char* szControlName);
};

#endif


