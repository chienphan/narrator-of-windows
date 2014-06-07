#ifndef _NOW_WINDOW_STORAGE_H_
#define _NOW_WINDOW_STORAGE_H_

#include "NowDefine.h"
#include "INowWindow.h"
#include "INowControl.h"

class DllExport NowStorage
{
private:
	NowMapWindow* m_mapWindow;
	NowMapControl* m_mapControl;
	static NowStorage* m_instance;
	NowStorage(void);

	NOW_RESULT getWindowFromStorage(const string& strWindowName, INowWindow*& pWindow);
	NOW_RESULT getControlFromStogare(const string& strControlName, INowControl*& pControl);
public:
	static NowStorage* getInstance();
	~NowStorage(void);

	NOW_RESULT keepWindow(const char* szWindowName, INowWindow* pWindow);
	NOW_RESULT getWindow(const char* szWindowName, INowWindow*& pWindow);

	NOW_RESULT keepControl(const char* szControlName, INowControl* pControl);
	NOW_RESULT getControl(const char* szControlName, INowControl*& pControl);

	NOW_RESULT emptyStorage();
};

#endif

