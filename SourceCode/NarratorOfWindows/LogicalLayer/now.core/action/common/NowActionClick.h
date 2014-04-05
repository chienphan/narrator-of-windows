#ifndef _NOW_CLICK_ACTION_H_
#define _NOW_CLICK_ACTION_H_

#include "NowDefine.h"
#include "inowaction.h"

class NowActionClick : public INowAction
{
private:
	INowControl* m_control;
	INowWindow* m_window;
	string m_strWindowName;
	string m_strControlname;
	string m_clickType;
public:
	NowActionClick(void);
	~NowActionClick(void);

	virtual NOW_RESULT prepareArguments(vector<string>* argumnents);

	virtual NOW_RESULT doAction();

};

#endif


