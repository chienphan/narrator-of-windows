#ifndef _NOW_STORAGE_H_
#define _NOW_STORAGE_H_

#include "NowDefine.h"
#include "INowWindow.h"

class DllExport NowStorage
{
private:
	NowMapWindow* m_mapWindow;
	static NowStorage* m_instance;
	NowStorage(void);
public:
	static NowStorage* getInstance();
	~NowStorage(void);

	NOW_RESULT keepWindowToStorage(const char* szWindowName, INowWindow* pwindow);
	NOW_RESULT getWindowFromStorage(const char* szWindowName, INowWindow*& pWindow);

	NOW_RESULT emptyStorage();
};

#endif

