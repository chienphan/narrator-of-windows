#include "NowLoggerWriter.h"
#include "NowLoggerConfig.h"
#include "NowDevice.h"

NowLoggerWriter* NowLoggerWriter::m_instance = NULL;

NowLoggerWriter::NowLoggerWriter(void)
{
	m_dir = NowLoggerConfig::getInstance()->getLoggerDir();
	string filePath = m_dir.append((string("\\")).c_str());
	filePath = filePath.append(getFileName().c_str());
	m_currentFile.open(filePath, ios::out);
}


NowLoggerWriter::~NowLoggerWriter(void)
{
	if (m_currentFile.is_open())
	{
		m_currentFile.close();
	}
}

std::string NowLoggerWriter::getFileName()
{
	string strFileName = "";

	long processID = NowDevice::getCurrentProcessId();
	char bufffer[NOW_MAXLENGTH] = {0}; 
	sprintf_s(bufffer, "%d", processID);

	strFileName.append(string(bufffer));
	strFileName.append("-");
	strFileName.append(NowDevice::getCurrentDateTime());
	strFileName.append(".txt");

	return strFileName;
}

NowLoggerWriter* NowLoggerWriter::getInstance()
{
	if (!m_instance)
	{
		m_instance = new NowLoggerWriter();
	}
	return m_instance;
}

void NowLoggerWriter::writeAString( string strDebug )
{
	if (m_currentFile.is_open())
	{
		m_currentFile<<strDebug.c_str()<<endl;
	}
}

void NowLoggerWriter::writeWString( wstring strDebug )
{
	if (m_currentFile.is_open())
	{
		m_currentFile.imbue(std::locale(std::locale(),
			new std::codecvt_utf8_utf16<wchar_t, 0x10ffff, std::codecvt_mode(std::consume_header|std::generate_header)>));
		m_currentFile<<strDebug.c_str()<<endl;
	}
}
