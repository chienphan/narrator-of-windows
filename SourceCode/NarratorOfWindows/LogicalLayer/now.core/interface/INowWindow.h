#ifndef _INOW_WINDOW_H_
#define _INOW_WINDOW_H_

#include "NowDefine.h"

class INowWindow
{
public:
	virtual NOW_RESULT getWindowHandle(string& strWindowHandle) = 0;
	virtual NOW_RESULT getControlFromStorage(const string& strControlName, INowControl* pControl) = 0;
	virtual NOW_RESULT addControlToStorage(const string& strControlName, INowControl* pControl) = 0;
};

#endif