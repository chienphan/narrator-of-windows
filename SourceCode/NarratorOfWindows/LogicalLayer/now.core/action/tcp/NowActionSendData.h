#ifndef _NOW_ACTION_SEND_DATA_H_
#define _NOW_ACTION_SEND_DATA_H_

#include "INowAction.h"

class NowActionSendData : public INowAction
{
private:
	wstring m_data;
public:
	NowActionSendData(void);

	~NowActionSendData(void);

	virtual NOW_RESULT prepareArguments( vector<wstring>* argumnents );

	virtual NOW_RESULT doAction();

};

#endif

