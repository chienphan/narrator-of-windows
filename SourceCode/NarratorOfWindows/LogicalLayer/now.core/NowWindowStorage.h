#ifndef _NOW_WINDOW_STORAGE_H_
#define _NOW_WINDOW_STORAGE_H_

#include "NowDefine.h"
#include "INowWindow.h"

class DllExport NowWindowStorage
{
private:
	NowMapWindow* m_mapWindow;
	static NowWindowStorage* m_instance;
	NowWindowStorage(void);
public:
	static NowWindowStorage* getInstance();
	~NowWindowStorage(void);

	NOW_RESULT keepWindowToStorage(const char* szWindowName, INowWindow* pwindow);
	NOW_RESULT getWindowFromStorage(const char* szWindowName, INowWindow*& pWindow);

	NOW_RESULT emptyStorage();
};

#endif

