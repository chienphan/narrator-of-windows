#ifndef _NOW_ACTION_SCROLL_INTO_VIEW_H_
#define _NOW_ACTION_SCROLL_INTO_VIEW_H_

#include "NowDefine.h"
#include "inowaction.h"

class NowActionScrollIntoView :
	public INowAction
{
private:
	string m_strWindowName;
	string m_strControlname;
	INowControl* m_control;
	INowWindow* m_window;
public:
	NowActionScrollIntoView(void);
	~NowActionScrollIntoView(void);

	virtual NOW_RESULT prepareArguments( vector<wstring>* argumnents );

	virtual NOW_RESULT doAction();

};

#endif


