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

	NOW_RESULT keepWindowToStorage(const char* szWindowTitle, INowWindow* pwindow);
	NOW_RESULT getWindowFromStorage(const char* szWindowTitle, INowWindow*& pWindow);

	NOW_RESULT emptyStorage();
};

#endif

