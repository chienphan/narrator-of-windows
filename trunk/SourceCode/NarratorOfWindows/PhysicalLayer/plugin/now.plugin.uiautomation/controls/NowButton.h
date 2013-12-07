#ifndef _NOW_BUTTON_H_
#define _NOW_BUTTON_H_

#include "NowDefine.h"
#include "NowControl.h"

//using namespace System::Windows::Automation;

class NowButton : NowControl
{
private:
	//AutomationElement^ m_runtimeElement;
public:
	NowButton();
	~NowButton();

	virtual string getControlType();

};

#endif


