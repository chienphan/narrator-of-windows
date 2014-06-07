#ifndef _NOW_ACTION_SEND_KEY_
#define _NOW_ACTION_SEND_KEY_ 

#include "NowDefine.h"
#include "INowAction.h"
class NowActionSendKeys : public INowAction
{
private:
	wstring m_strKeys;
public:
	NowActionSendKeys(void);
	~NowActionSendKeys(void);

	virtual NOW_RESULT prepareArguments( vector<wstring>* argumnents );

	virtual NOW_RESULT doAction();

};


#endif


