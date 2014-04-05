#ifndef _NOW_UTILITY_H_
#define _NOW_UTILITY_H_

#include "NowDefine.h"

class DllExport NowUtility
{
public:
	static vector<vector<string>*>* readData(const string& strFileName);
	static vector<string>* split(const string& source, char delim);
	static void getRectData(vector<string>* data, int& left, int& top, int& widht, int& height);
};

#endif	//_NOW_UTILITY_H_


