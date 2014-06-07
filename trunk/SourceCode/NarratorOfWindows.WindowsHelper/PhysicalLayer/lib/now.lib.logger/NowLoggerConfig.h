#ifndef _NOW_LOGGER_CONFIG_H_
#define _NOW_LOGGER_CONFIG_H_

#include "NowDefine.h"

class NowLoggerConfig
{
private:
	static NowLoggerConfig* m_instance;
	NOW_RESULT m_mode;
	string m_dir;

	NowLoggerConfig(void);
	NOW_RESULT initial();
public:
	~NowLoggerConfig(void);
	static NowLoggerConfig* getInstance();
	NOW_RESULT getLoggerMode();
	string getLoggerDir();
};

#endif


