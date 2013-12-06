#ifndef _NOW_PLUGIN_UIA_H_
#define _NOW_PLUGIN_UIA_H_

#include "INowPlugin.h"
#include "NowDefine_UIA.h"

class NowPlugin : INowPlugin
{
public:
	NowPlugin(void);
	~NowPlugin(void);

	virtual int printName(int x, int y, std::string& strTemp);

};

#endif //_NOW_PLUGIN_UIA_H_