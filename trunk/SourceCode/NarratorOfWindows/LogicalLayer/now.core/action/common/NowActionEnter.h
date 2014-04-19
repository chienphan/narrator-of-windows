#ifndef _NOW_ACTION_TYPE_KEY_H_
#define _NOW_ACTION_TYPE_KEY_H_

#include "NowDefine.h"
#include "inowaction.h"

class NowActionEnter : public INowAction
{
private:
	string m_strWindowName;
	string m_strControlname;
	wstring m_strContent;
	INowControl* m_control;
	INowWindow* m_window;
public:
	NowActionEnter(void);
	~NowActionEnter(void);

	virtual NOW_RESULT prepareArguments(vector<wstring>* argumnents);

	virtual NOW_RESULT doAction();

};

#endif


