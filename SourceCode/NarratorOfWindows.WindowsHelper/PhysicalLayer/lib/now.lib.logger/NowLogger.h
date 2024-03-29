#ifndef _NOW_LOGGER_H_
#define _NOW_LOGGER_H_

#include "NowDefine.h"

#define DllExport   __declspec( dllexport )

class DllExport NowLogger {
private:
	static NowLogger* m_instance;
	int m_debugMode;
	NowLogger();

public:
	static NowLogger* getInstance();
	~NowLogger();
	void LogWString(const wstring wstrLog);
	void LogAString(const string strLog);
	void LogInt(const int intLog);
};

#endif // _NOW_LOGGER_H_