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
	* Get element at point and then create cache at agent
	* @param point : position of mouse pointer
	* @param pControl : NowControl element
	* @return : NOW_OK if succeed, NOW_FALSE if not
	*/
	virtual NOW_RESULT getElementAtPoint(POINT point, INowControl*& pControl) = 0;

	/*
	* Clear cache 
	* @return : NOW_OK if succeed, NOW_FALSE if not
	*/
	virtual NOW_RESULT clearCache() = 0;

	/*
	* Match the window
	* @param szTitleWindow : title of window
	* @param pWindow : NowWindow element
	* @return : NOW_OK if succeed, NOW_FALSE if not
	*/
	virtual NOW_RESULT matchWindow(const char* szTitleWindow, INowWindow*& pWindow) = 0;
};

#endif