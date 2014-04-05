#ifndef _NOW_WINDOW_UIA_H_
#define _NOW_WINDOW_UIA_H_

#include "NowDefine.h"
#include "INowWindow.h"

class NowWindow_UIA : public INowWindow
{
private:
	string m_strWindowHandle;
	NowMapControl* m_mapControl;
public:
	NowWindow_UIA(const string& strWindowHandle);
	~NowWindow_UIA(void);

	virtual NOW_RESULT getWindowHandle( string& strWindowHandle );

	virtual NOW_RESULT getControlFromStorage( const string& strControlName, INowControl* pControl );

	virtual NOW_RESULT addControlToStorage( const string& strControlName, INowControl* pControl );

};

#endif


