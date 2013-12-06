#ifndef _INOW_PLUGIN_H_
#define _INOW_PLUGIN_H_

#include <string>

class INowPlugin
{
public:
	virtual int printName(int x, int y, std::string& strOut) = 0;
};

#endif