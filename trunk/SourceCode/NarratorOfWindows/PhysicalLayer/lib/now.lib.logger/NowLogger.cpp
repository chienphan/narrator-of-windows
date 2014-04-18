#include "NowLogger.h"
#include "NowLoggerConfig.h"
#include "NowLoggerWriter.h"

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
		m_instance->m_debugMode = NowLoggerConfig::getInstance()->getLoggerMode();
	}
	return m_instance;
}



void NowLogger::LogWString( const wstring wstrLog )
{
	if (m_debugMode == NOW_LOGGER_DEBUGVIEW_MODE)
	{
		OutputDebugStringW(wstrLog.c_str());
	}
	if (m_debugMode == NOW_LOGGER_FILE_MODE)
	{
		NowLoggerWriter::getInstance()->writeWString(wstrLog);
	}
}

void NowLogger::LogAString( const string strLog )
{
	if (m_debugMode == NOW_LOGGER_DEBUGVIEW_MODE)
	{
		OutputDebugStringA(strLog.c_str());
	}
	if (m_debugMode == NOW_LOGGER_FILE_MODE)
	{
		NowLoggerWriter::getInstance()->writeAString(strLog);
	}
}

void NowLogger::LogInt(const int intLog)
{
	char buffer[512];
	sprintf_s(buffer, "%d ", intLog);
	NowLogger::getInstance()->LogAString(string(buffer));
}
