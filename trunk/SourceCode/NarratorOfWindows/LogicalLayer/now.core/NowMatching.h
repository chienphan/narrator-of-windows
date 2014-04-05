#ifndef _NOW_MATCHING_H_
#define _NOW_MATCHING_H_

#include "NowDefine.h"
#include "INowWindow.h"

class DllExport NowMatching
{
private:
	static NowMatching* m_instance;
	NowMatching(void);
public:
	static NowMatching* getInstance();
	~NowMatching(void);

	NOW_RESULT matchWindow(const char* szWindowName, const char* szWindowTitle);
	NOW_RESULT matchControl(const char* szWindowName, const char* szControlName, map<string, string>* propvalue);
};

#endif


