#include "NowLogger.h"

NowLogger* NowLogger::m_instance = NULL;

NowLogger::NowLogger()
{
}


NowLogger::~NowLogger()
{
}

NowLogger* NowLogger::getInstance()
{
	if (!m_instance)
	{
		m_instance = new NowLogger();
		m_instance->m_debugMode = 1;
	}
	return m_instance;
}



void NowLogger::LogWString( const wstring wstrLog )
{
	if (m_debugMode == 1)
	{
		OutputDebugStringW(wstrLog.c_str());
	}
}

void NowLogger::LogAString( const string strLog )
{
	if (m_debugMode == 1)
	{
		OutputDebugStringA(strLog.c_str());
	}
}
