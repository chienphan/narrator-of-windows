#include "NowSetting.h"

NowSetting* NowSetting::m_instance = NULL;

NowSetting::NowSetting(void)
{
	m_SleepTime = 1;
}


NowSetting::~NowSetting(void)
{
}

NowSetting* NowSetting::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new NowSetting();
	}
	return m_instance;
}

void NowSetting::setSleepTime( int milisecond )
{
	if (milisecond > 0)
	{
		m_SleepTime = milisecond;
	}
}

void NowSetting::setSleepTime( string milisecond )
{
	if (!milisecond.empty())
	{
		m_SleepTime = atoi(milisecond.c_str());
	}
}

int NowSetting::getSleepTime()
{
	return m_SleepTime;
}
