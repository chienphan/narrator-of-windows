#ifndef _NOW_CONTROL_BUILDER_H_
#define _NOW_CONTROL_BUILDER_H_

#include "NowDefine.h"

class NowControlBuilder
{
private:
	NowControlBuilder(void);
	static NowControlBuilder* m_Instance;

public:
	~NowControlBuilder(void);

	static NowControlBuilder* getInstance();

	/*
	* Create wrapper for control
	*/
	INowControl* createControlWrapper(string strSignatureControl, string strControlType);

	/*
	* Create wrapper for window
	*/
	INowWindow* createWindowWrapper(string strWindowHandle);
};

#endif// _NOW_CONTROL_BUILDER_H_