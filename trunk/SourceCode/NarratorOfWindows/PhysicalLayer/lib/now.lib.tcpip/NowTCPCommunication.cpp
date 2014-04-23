#include "NowTCPCommunication.h"
#include "NowStringProcessor.h"
#include "NowStringProcessor_UIA.h"
#include "NowDevice.h"

using namespace System;
using namespace System::Text;
using namespace System::Net;
using namespace System::Net::Sockets;

NowTCPCommunication* NowTCPCommunication::m_instance = NULL;

NowTCPCommunication::NowTCPCommunication(void)
{
	//TODO: initialize here!
	string strFullPath = NowDevice::getInstallDirectory() + "\\config\\tcp.txt";
	vector<wstring>* data = NowDevice::getFileData(strFullPath);
	if (data != NULL)
	{
		if (data->size() > 0)
		{
			vector<wstring>* vectString = NowStringProcessor::split(data->at(0), L'=');
			if (vectString->size() == 2)
			{
				string strPort = NowStringProcessor::wstringTostring(vectString->at(1));
				if (!strPort.empty())
				{
					m_nPort = atoi(strPort.c_str());
				}
			}
		}
	}
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
	IPEndPoint^ ip = nullptr;

	try
	{
		ip = gcnew IPEndPoint(IPAddress::Parse(NOW_LOCAL_HOST), m_nPort);
	}
	catch (System::Exception^ exception)
	{
		return NOW_FALSE;
	}

	Socket^ server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

	try
	{
		server->Connect(ip);
		server->Send(System::Text::Encoding::UTF8->GetBytes(NowStringProcessor_UIA::StlStringToString(content)));
	}
	catch (SocketException^ exception)
	{
		return NOW_FALSE;
	}

	server->Shutdown(SocketShutdown::Both);
	server->Close();
	return NOW_FALSE;
}

NOW_RESULT NowTCPCommunication::sendData( const wstring& content )
{
	IPEndPoint^ ip = nullptr;

	try
	{
		ip = gcnew IPEndPoint(IPAddress::Parse(NOW_LOCAL_HOST), m_nPort);
	}
	catch (System::Exception^ exception)
	{
		return NOW_FALSE;
	}

	Socket^ server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

	try
	{
		server->Connect(ip);
		server->Send(System::Text::Encoding::UTF8->GetBytes(NowStringProcessor_UIA::StlWStringToString(content)));
	}
	catch (SocketException^ exception)
	{
		return NOW_FALSE;
	}

	server->Shutdown(SocketShutdown::Both);
	server->Close();
	return NOW_OK;
}
