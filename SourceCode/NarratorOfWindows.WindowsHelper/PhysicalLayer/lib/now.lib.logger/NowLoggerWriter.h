#ifndef _NOW_LOGGER_WRITER_H_
#define _NOW_LOGGER_WRITER_H_

#include "NowDefine.h"
#include <fstream>
#include <iostream>
#include <codecvt>

class NowLoggerWriter
{
private:
	static NowLoggerWriter* m_instance;
	string m_dir;
	wfstream m_currentFile;
	

	NowLoggerWriter(void);
	string getFileName();
public:
	~NowLoggerWriter(void);
	static NowLoggerWriter* getInstance();
	void writeAString(string strDebug);
	void writeWString(wstring strDebug);
};

#endif//_NOW_LOGGER_WRITER_H_