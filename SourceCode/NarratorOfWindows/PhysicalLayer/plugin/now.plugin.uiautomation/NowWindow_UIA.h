#ifndef _NOW_WINDOW_UIA_H_
#define _NOW_WINDOW_UIA_H_

#include "NowDefine.h"
#include "INowWindow.h"

class NowWindow_UIA : public INowWindow
{
private:
	string m_strWindowHandle;
	
public:
	NowWindow_UIA(const string& strWindowHandle);
	~NowWindow_UIA(void);

	virtual NOW_RESULT getWindowHandle( string& strWindowHandle );

};

#endif


