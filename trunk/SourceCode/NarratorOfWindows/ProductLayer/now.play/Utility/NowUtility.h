#ifndef _NOW_UTILITY_H_
#define _NOW_UTILITY_H_

class NowUtility
{
public:
	static vector<vector<string>*>* readData(const string& strFileName);
	static vector<string>* split(const string& source, char delim);
};

#endif	//_NOW_UTILITY_H_


