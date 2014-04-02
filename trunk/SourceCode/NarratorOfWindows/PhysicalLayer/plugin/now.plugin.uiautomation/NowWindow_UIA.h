#ifndef _NOW_WINDOW_UIA_H_
#define _NOW_WINDOW_UIA_H_

#include "NowDefine.h"
#include "INowWindow.h"

class NowWindow_UIA : public INowWindow
{
private:
	string m_strWindowHandle;
public:
	NowWindow_UIA(string strWindowHandle);
	~NowWindow_UIA(void);
};

#endif


