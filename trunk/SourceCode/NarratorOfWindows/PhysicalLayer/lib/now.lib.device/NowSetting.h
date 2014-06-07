#ifndef _NOW_SETTING_H_
#define _NOW_SETTING_H_

#include "NowDefine.h"

class DllExport NowSetting
{
private:
	static NowSetting* m_instance;
	int m_SleepTime;
	NowSetting(void);

public:
	static NowSetting* getInstance();
	~NowSetting(void);

	void setSleepTime(int milisecond);
	void setSleepTime(string milisecond);
	int getSleepTime();
};

#endif


