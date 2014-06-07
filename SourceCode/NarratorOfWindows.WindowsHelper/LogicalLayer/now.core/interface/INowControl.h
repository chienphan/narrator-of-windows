#ifndef _INOW_CONTROL_H_
#define _INOW_CONTROL_H_

#include "NowDefine.h"

class INowControl
{
public:
	/*
	* Get control type of control
	*/
	virtual NOW_RESULT getControlType(string& strControlType) = 0;

	/*
	* Get caption of control
	*/
	virtual NOW_RESULT getCaption(wstring& wstrCaption) = 0;

	/*
	* Get help text (tooltip) of control
	*/
	virtual NOW_RESULT getUIInformation(wstring& wstrHelpText) = 0;

	/*
	* Get parent of control
	*/
	virtual NOW_RESULT getParent(INowControl*& ctrParent) = 0;

	/*
	* Get children of control
	*/
	virtual NOW_RESULT getChildren(list<INowControl*>& lstChildren) = 0;

	/*
	* Get state of control
	*/
	virtual NOW_RESULT getState(int& nState) = 0;

	/*
	* Get signature of control
	*/
	virtual NOW_RESULT getSignature(string& strSignature) = 0;

	/*
	*
	*/
	virtual NOW_RESULT getNowClass(string& strNowClass) = 0;

	/*
	*
	*/
	virtual NOW_RESULT getUIProperty(const string& strPropName, wstring& strValue) = 0;

	virtual NOW_RESULT getProperty(const string& strPropName, string& strValue) = 0;
};

#endif