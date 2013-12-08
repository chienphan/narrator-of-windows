#include "NowLoggerConfig.h"
#include "NowDevice.h"

NowLoggerConfig* NowLoggerConfig::m_instance = NULL;

NowLoggerConfig::NowLoggerConfig(void)
{
	if (!NOW_SUCCEED(initial()))
	{
		m_mode = NOW_LOGGER_NONE_MODE;
		m_dir = "";
	}
}

NowLoggerConfig::~NowLoggerConfig(void)
{
}

NowLoggerConfig* NowLoggerConfig::getInstance()
{
	if (!m_instance)
	{
		m_instance = new NowLoggerConfig();
	}
	return m_instance;
}

NOW_RESULT NowLoggerConfig::getLoggerMode()
{
	return m_mode;
}

std::string NowLoggerConfig::getLoggerDir()
{
	return m_dir;
}

NOW_RESULT NowLoggerConfig::initial()
{
	NOW_RESULT nRet = NOW_FALSE;
	string currentDir = NowDevice::getCurrentDirectory();
	currentDir.append("\\");
	currentDir.append("logconfig.txt");
	ifstream myfile (currentDir);

	if (myfile.is_open())
	{
		char chrTemp[NOW_MAXLENGTH];
		
		myfile>>chrTemp;
		string strTemp = string(chrTemp);
		
		int n = strTemp.find("mode=");
		if ( n == 0)
		{
			char chrMode[NOW_MAXLENGTH];
			strTemp.copy(chrMode, strTemp.length() - (string("mode=")).length(), (string("mode=")).length());
			chrMode[strTemp.length() - (string("mode=")).length()] = '\0';
			
			
			string strCompare = string(chrMode);
			if (strCompare.compare("file") == 0)
			{
				m_mode = NOW_LOGGER_FILE_MODE;
				
				myfile>>chrTemp;
				strTemp = string(chrTemp);

				if (strTemp.find("logdir=") == 0)
				{
					char chrMode[NOW_MAXLENGTH];
					strTemp.copy(chrMode, strTemp.length() - (string("logdir=")).length(), (string("logdir=")).length());
					chrMode[strTemp.length() - (string("logdir=")).length()] = '\0';

					m_dir = string(chrMode);
					nRet = NOW_OK;
				}
			}

			if ((string(chrMode)).compare("debugview") == 0)
			{
				m_mode = NOW_LOGGER_DEBUGVIEW_MODE;
				nRet = NOW_OK;
			}
		}

		myfile.close();
	}	
	return nRet;
}
