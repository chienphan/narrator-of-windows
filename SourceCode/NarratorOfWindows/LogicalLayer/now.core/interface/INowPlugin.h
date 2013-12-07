#ifndef _INOW_PLUGIN_H_
#define _INOW_PLUGIN_H_

#include "NowDefine.h"

class INowPlugin
{
public:
	
	/*
	* Get Plug-in name
	* @return : name of plug-in
	*/
	virtual string getPluginName() = 0;

	/*
	* Get element at point
	* @param point : position of mouse pointer
	* @param pControl : NowControl element
	* @return : NOW_OK if succeed, NOW_FALSE if not
	*/
	virtual NOW_RESULT getElementAtPoint(POINT point, NowControl*& pControl) = 0;

};

#endif