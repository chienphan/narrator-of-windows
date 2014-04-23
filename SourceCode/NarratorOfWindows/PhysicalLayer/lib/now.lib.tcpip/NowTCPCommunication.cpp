#include "StdAfx.h"
#include "NowTCPCommunication.h"

NowTCPCommunication* NowTCPCommunication::m_instance = NULL;

NowTCPCommunication::NowTCPCommunication(void)
{
	//TODO: initialize here!
}

NowTCPCommunication::~NowTCPCommunication(void)
{
}

NowTCPCommunication* NowTCPCommunication::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new NowTCPCommunication();
	}
	return m_instance;
}

NOW_RESULT NowTCPCommunication::sendData( const string& content )
{
	return NOW_FALSE;
}

NOW_RESULT NowTCPCommunication::sendData( const wstring& content )
{
	return NOW_FALSE;
}
