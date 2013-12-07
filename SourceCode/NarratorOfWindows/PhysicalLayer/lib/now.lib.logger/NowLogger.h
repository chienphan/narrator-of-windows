#ifndef _NOW_LOGGER_H_
#define _NOW_LOGGER_H_

#include "NowDefine.h"

#define DllExport   __declspec( dllexport )

class DllExport NowLogger {
private:
	static NowLogger* m_instance;
	// 0 = don't out put
	// 1 = debug viewer
	int m_debugMode;
	NowLogger();

public:
	static NowLogger* getInstance();
	~NowLogger();
	void LogWString(const wstring wstrLog);
	void LogAString(const string strLog);
};

#endif // _NOW_LOGGER_H_