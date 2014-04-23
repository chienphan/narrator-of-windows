#ifndef _NOW_TCP_COMMUNIATION_H_
#define _NOW_TCP_COMMUNIATION_H_

#include "NowDefine.h"

class DllExport NowTCPCommunication
{
private:
	int m_nPort;
	static NowTCPCommunication* m_instance;
	NowTCPCommunication(void);

public:
	static NowTCPCommunication* getInstance();
	~NowTCPCommunication(void);

	NOW_RESULT sendData(const wstring& content);
	NOW_RESULT sendData(const string& content);
};

#endif