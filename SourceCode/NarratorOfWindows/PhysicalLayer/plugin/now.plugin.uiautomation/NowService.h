#ifndef _NOW_SERVICE_H_
#define _NOW_SERVICE_H_

#include "NowDefine.h"

class NowService
{
private:
	static NowService* m_instance;

	NowService(void);

public:
	static NowService* getInstance();

	string ParseState(int nState);

	~NowService(void);
};

#endif


